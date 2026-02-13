/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siellage <siellage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:16:17 by siellage          #+#    #+#             */
/*   Updated: 2026/02/13 17:16:20 by siellage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_str_free(char *res, char *val)
{
	char	*tmp;

	tmp = res;
	res = ft_strjoin(res, val);
	free(val);
	free(tmp);
	return (res);
}

char	*join_char_free(char *res, char c)
{
	char	*tmp;

	tmp = res;
	res = ft_strjoin_char(res, c);
	free(tmp);
	return (res);
}

char	*handle_dollar(const char *str, size_t *i, char *res, t_expand_ctx *ctx)
{
	size_t	vl;
	char	*vn;
	char	*val;

	vn = extract_var_name(str + *i, &vl);
	if (vn && vn[0])
	{
		val = get_var_value(vn, ctx->envp, ctx->exit_status);
		res = join_str_free(res, val);
	}
	else if (!vn || !vn[0])
		res = join_char_free(res, '$');
	free(vn);
	*i += vl;
	return (res);
}
