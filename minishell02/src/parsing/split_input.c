/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:42:11 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/02 22:09:36 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ensure_capacity(t_split_ctx *ctx)
{
	char	**new_args;
	size_t	new_capacity;
	size_t	i;

	if (ctx->count < ctx->capacity)
		return (1);
	new_capacity = ctx->capacity * 2;
	new_args = malloc(sizeof(char *) * (new_capacity + 1));
	if (!new_args)
		return (0);
	i = 0;
	while (i < ctx->count)
	{
		new_args[i] = ctx->tokens[i];
		i++;
	}
	free(ctx->tokens);
	ctx->tokens = new_args;
	ctx->capacity = new_capacity;
	return (1);
}

static int	join_to_last(t_split_ctx *ctx, char *input, int start, size_t len)
{
	char	*joined;
	char	*sub;

	sub = ft_substr(input, start, len);
	joined = ft_strjoin(ctx->tokens[ctx->count - 1], sub);
	free(ctx->tokens[ctx->count - 1]);
	free(sub);
	ctx->tokens[ctx->count - 1] = joined;
	if (!joined)
		return (0);
	return (1);
}

static int	add_token(t_split_ctx *ctx, char *input, int start, int end)
{
	size_t	len;

	ctx->end = end;
	ctx->start = ctx->end + 1;
	if (!ensure_capacity(ctx))
		return (0);
	len = end - start + 1;
	if (start > 0 && (!ft_isspace(input[start - 1])
			&& !ft_isspecialchar(input[start - 1])))
		return (join_to_last(ctx, input, start, len));
	ctx->tokens[ctx->count] = ft_substr(input, start, len);
	if (!ctx->tokens[ctx->count])
		return (0);
	ctx->count++;
	return (1);
}

static int	fill_tokens(t_split_ctx *ctx, char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			ctx->end = get_quote_closing_idx(ctx, input, &i);
			if (ctx->end == -1 || !add_token(ctx, input, ctx->start, ctx->end))
				return (0);
		}
		if (ft_isspace(input[i]) && !ft_isspace(input[i + 1]))
			ctx->start = i + 1;
		if (is_generic_word(input[i], input[i + 1]))
		{
			if (!add_token(ctx, input, ctx->start, i))
				return (0);
		}
		if (ft_isspecialchar(input[i]) && input[i] != input[i + 1])
		{
			if (!add_token(ctx, input, ctx->start, i))
				return (0);
		}
	}
	return (1);
}

char	**split_input(char *input)
{
	t_split_ctx	ctx;

	if (!input)
		return (NULL);
	ctx.capacity = 8;
	ctx.quote_error = 0;
	ctx.start = 0;
	ctx.end = 0;
	ctx.tokens = malloc(sizeof(char *) * (ctx.capacity + 1));
	if (!ctx.tokens)
		return (NULL);
	ctx.count = 0;
	if (!fill_tokens(&ctx, input))
	{
		if (ctx.quote_error)
			printf("minishell: unexpected EOF while looking for "
				"matching `%c'\n", ctx.quote_error);
		ctx.tokens[ctx.count] = NULL;
		free_env(ctx.tokens);
		return (NULL);
	}
	ctx.tokens[ctx.count] = NULL;
	return (ctx.tokens);
}
