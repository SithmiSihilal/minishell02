/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:59:21 by glugo-mu          #+#    #+#             */
/*   Updated: 2026/02/13 17:01:02 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <signal.h>

# define ECHO 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7
# define HERADOC -2
# define SSTDERR 2

typedef struct s_split_ctx
{
	char	**tokens;
	size_t	count;
	size_t	capacity;
	char	quote_error;

	int		start;
	int		end;
}	t_split_ctx;

typedef struct s_expand_ctx
{
	char	**envp;
	int		exit_status;
}	t_expand_ctx;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_token_iter
{
	char			**parts;
	size_t			index;
	t_token_type	prev;
}	t_token_iter;

typedef struct s_redir
{
	t_token_type	type;
	char			*target;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	size_t			argc;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipe_ctx
{
	t_cmd	*cmd;
	char	**envp;
	int		**pipes;
	int		cmd_i;
	int		n_cmds;
}	t_pipe_ctx;

typedef struct s_filelist
{
	char				*metachar;
	char				*filename;
	int					fd;
	struct s_filelist	*next;
}	t_filelist;

typedef struct s_lexlist
{
	char				type;
	char				*content;
	struct s_lexlist	*next;
}	t_lexlist;

typedef struct s_title
{
	char	*head;
	char	*full_title;
}	t_title;

typedef struct s_env
{
	char			*env_name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_cmdlist
{
	int					infile;
	int					outfile;
	int					pid;
	char				*heradoc_values;
	char				*cmd;
	char				**path;
	t_filelist			*files;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_core
{
	int			exit_status;

	int			**pipes;
	int			n_pipes;
	int			main_pid;
	int			exec_output;
	int			old_exec_output;
	int			heradoc_fd;
	int			is_read_arg;
	char		*cmd;
	char		**metachars;
	char		**my_env;
	t_env		*env_table;
	t_lexlist	*lex_table;
	t_cmdlist	*cmd_table;
	t_title		title;
	t_cmd		*cmds;
	int			saved_stdout;
	int			saved_stdin;
}	t_core;

extern int	g_last_signal;

void			close_pipes(int **pipes, int n_pipes);
void			free_cmdlist_adapter(t_cmdlist *cmdlist);
int				isbuiltin(char *cmd);
void			runbuiltin(t_core *core, t_cmdlist *node, int bltn);
void			runecho(t_cmdlist *cmdnode);
void			runenv(t_core *core, t_cmdlist *cmdnode);
int				updateenv(t_core *core, char *envname, char *newarg);
void			runpwd(t_cmdlist *cmdnode);
void			runcd(t_core *core, t_cmdlist *cmdnode);
void			cdsinglearg(t_core *core);
void			cddoublearg(t_core *core, t_cmdlist *cmd_node);
int				changedir(t_core *core, char *path);
int				updatepwdfromexport(t_core *core, char *name, char *cnt);
void			rununset(t_core *core, t_cmdlist *cmdnode);
void			deleteenv(t_core *core, char *name);
void			createdup(t_core *core, t_cmdlist *lst, int *fd, int idx);
int				getarraylen(char **array);
void			print_error(char *ptr1, char *ptr2, char *ptr3);
void			changetitle(void);
void			ownstrjoin(char **dst, char *src);
void			straddchar(char **dst, char c);
int				str_compare(char *s1, char *s2);
int				compare_metachars(char *str);
int				isallnumeric(char *text);
void			runexit(t_core *core, t_cmdlist *cmdnode);
int				runexport(t_core *core, t_cmdlist *cmdnode);
void			singleexportarg(t_core *core, t_cmdlist *cmdnode);
void			doubleexportarg(t_core *core, char *envcmd);
int				changeenv(t_core *core, char *envname, char *arg, int isequal);
int				getenvlen(t_core *core);
void			free_list_env(t_env *env);
char			**getenvcpy(t_core *core);
void			freeenvcpy(char **envlist);
void			fillenvs(t_core *core, char **env);
t_env			*addnewenv(t_env **envtable, char *env);
void			sync_my_env(t_core *core);
char			*getenvname(char *content);
int				getenvnamecount(char *envarg);
char			*validenv(char *env);
char			*envnamecontrol(char *env);
int				envargcontrol(t_core *core, char *env, int print);
void			runexecve(t_cmdlist *cmdnode, int *fd, int fdindex);
void			execcommand(t_cmdlist *cmdnode, int *fd, int fdindex);
char			*getcmd(char *cmd);
int				*createpipe(void);
void			clearpipe(int *fd);
void			switchpipe(int **fd);
void			runmultiplecommand(t_cmdlist *cmdlist);
void			runsinglecommand(t_cmdlist *cmdlist, int *fd);
void			executer(void);
void			runprocess(t_cmdlist *cmdlist, int *fd, int fdindex);
void			waitall(void);
void			free_core(t_core *core);

char			*join_str_free(char *res, char *val);
char			*join_char_free(char *res, char c);
char			*handle_dollar(const char *str, size_t *i, char *res, t_expand_ctx *ctx);
int				is_builtin(char *cmd);
int				exec_builtin(char **args);
int				ft_strcmp(const char *s1, const char *s2);
void			print_env(char **my_env);
void			free_resources(char *input, char **parts, char *original);
char			**copy_env(char **envp);
void			free_env(char **env);
char			**init_env(void);
void			init_global_env(t_core *core, char **envp);
int				ft_isspace(char c);
int				ft_isspecialchar(char c);
int				get_quote_closing_idx(t_split_ctx *ctx, char *input,
					int *start_idx);
int				is_generic_word(char current, char next);
char			**split_input(char *input);
int				validate_input(const char *input);
t_token			*tokenize(char **parts, char **error);
void			token_clear(t_token **tokens);
int				token_add_new(t_token **tokens, char *value, t_token_type type);
int				token_is_redirect(t_token_type type);
int				token_set_error(char **error, const char *token);
void			expand_tokens(t_token *tokens, char **envp, int exit_status);
char			*get_var_value(char *var_name, char **envp, int exit_status);
char			*extract_var_name(const char *str, size_t *len);
void			process_word_token(t_token *token, char **envp, int exit_status);
t_cmd			*commands_from_tokens(t_token *tokens, char **error);
void			cmd_clear(t_cmd **cmds);
char			*find_in_path(const char *cmd, char **envp);
int				execute_external(t_core *core, t_cmd *cmd, char **envp);
int				execute_pipeline(t_core *core, t_cmd *first, char **envp);
int				execute_builtin_simple(t_core *core, t_cmd *cmd);
int				apply_redirections(t_redir *redirs, char **envp, int es);
void			setup_signals(void);
void			setup_child_signals(void);
void			handle_sigint(int sig);

#endif
