/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:10 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:43:11 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	change_old(char *str, t_shell *m_shell)
{
	t_list	*tmp;
	t_env	*env;

	tmp = m_shell->env;
	while (tmp)
	{
		env = tmp->content;
		if (!ft_strcmp(env->key, "OLDPWD"))
		{
			if (env->value)
				free(env->value);
			env->value = str;
		}
		tmp = tmp->next;
	}
}

void	change_pwd(t_parse *data, t_shell *m_shell)
{
	t_list	*tmp;
	t_env	*env;

	tmp = m_shell->env;
	while (tmp)
	{
		env = tmp->content;
		if (!ft_strcmp(env->key, "PWD") && data->text
			&& !ft_strcmp(data->text[0], "~"))
		{
			if (env->value)
				free(env->value);
			env->value = get_home(m_shell);
		}
		else if (!ft_strcmp(env->key, "PWD"))
		{
			if (env->value)
				free(env->value);
			env->value = getcwd(NULL, 0);
		}
		tmp = tmp->next;
	}
}

void	exec_cd1(char *str, t_parse *data, t_shell *m_shell)
{
	change_old(str, m_shell);
	chdir(get_home(m_shell));
	change_pwd(data, m_shell);
	m_shell->exec_status = 0;
}

void	exec_cd(t_parse *data, t_shell *m_shell)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (data->text && data->text[0])
	{
		if (chdir(data->text[0]) == 0)
		{
			change_old(str, m_shell);
			change_pwd(data, m_shell);
			m_shell->exec_status = 0;
		}
		else
		{
			if (str)
				free(str);
			m_shell->exec_status = 1;
			perror("cd");
		}
	}
	else
		exec_cd1(str, data, m_shell);
}

void	exec_pwd(t_parse *data, t_shell *m_shell)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		write(data->outfile, cwd, ft_strlen(cwd));
		write(1, "\n", 1);
		m_shell->exec_status = 0;
	}
	else
	{
		perror("getcwd");
		m_shell->exec_status = 1;
	}
	free(cwd);
}
