/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:54:40 by kjung             #+#    #+#             */
/*   Updated: 2025/01/18 17:58:37 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

//	ms_builtin_cd.c
int		check_cd_args(char **cd, char **tmp, char *home);
int		construct_cd_path(char **cd, char **tmp, char *home);
int		check_cd_arg(char **tmp, char **cd, char *home, char **envp);
void	cd_cmd(t_cmd *node, t_data **data);

//	ms_builtin_echo.c
char	*join_char(char *result, char c);
char	*expand_env_var(char *arg, int *i, t_data **data, char *result);
char	*expand_env(char *arg, t_data **data);
int		process_echo_options(char **divided, int *i);
int		do_echo(t_cmd *node);

//	ms_builtin_env.c
int		is_env_name(char *str);
int		validate_env_name(char *cd, char **env, char *eq);
int		check_eqaul(char *env);
void	printenv(char **envp, int flag);

//	ms_builtin_exit.c
int		check_digit(char *str);
void	do_exit(t_cmd *node);

//	ms_builtin_export.c
int		update_existing_env(char **envp, char *env, char *cd_j, char *eq);
char	**create_new_envp(char **old_envp, char *cd_j, char *eq, int cnt);
void	process_env_variable(t_data **data, char *cd_j);
void	export(t_cmd *node, t_data **data);

//	ms_builtin_pwd.c
int		print_dir(void);

//	ms_builtin_unset.c
int		env_cnt(char **envp, char *name);
void	remove_env(char **envp, int i);
void	unset_arg(t_data **data, char *arg);
void	do_unset(t_cmd *node, t_data **data);

#endif