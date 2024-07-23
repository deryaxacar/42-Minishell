/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk < beonturk@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:45:57 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/24 02:15:19 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*search_command(char *cmd, char **value)
{
	char	*data;
	int		i;
	char	*tmp;
	char	*substring;

	tmp = *value;
	i = 0;
	(void)cmd;
	while (*tmp && *tmp != ':')
	{
		i++;
		tmp++;
	}
	if (!i)
		return (NULL);
	substring = ft_substr(*value, 0, i);
	data = ft_strjoin(substring, "/");
	free(substring);
	substring = ft_strjoin(data, cmd);
	free(data);
	if (*tmp)
		*value = *value + i + 1;
	return (substring);
}

char	*get_path(t_shell *m_shell)
{
	t_env	*env;
	t_list	*tmp;
	char	*value;

	value = NULL;
	tmp = m_shell->env;
	while (tmp)
	{
		env = tmp->content;
		if (ft_strcmp(env->key, "PATH") == 0)
		{
			value = env->value;
			return (value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	**get_args(t_parse *parse)
{
	char	**exec;
	int		i;
	int		j;

	j = 0;
	if (parse->text)
		while (parse->text[j])
			j++;
	exec = malloc(sizeof(char *) * (j + 2));
	if (!exec)
		return (NULL);
	i = 0;
	exec[0] = ft_strdup(parse->cmd);
	j = 1;
	if (parse->text)
	{
		while (parse->text[i])
		{
			exec[j] = ft_strdup(parse->text[i++]);
			j++;
		}
	}
	exec[j] = NULL;
	return (exec);
}

void	search_path(t_parse *data, int i, t_shell *m_shell)
{
	char	*value;
	char	*str;
	int		x;

	x = -1;
	str = NULL;
	value = get_path(m_shell);
	while (x != 0 && value && ++i < 10)
	{
		if (str)
			free(str);
		str = search_command(data->cmd, &value);
		if (str)
			x = access(str, F_OK);
		if (str && x == 0)
		{
			if (data->cmd)
				free(data->cmd);
			data->cmd = ft_strdup(str);
		}
	}
	if (str)
		free(str);
}

void	run_execve(t_parse *parse, char **env, int *fd, t_shell *m_shell)
{
	char	**full_cmd;

	search_path(parse, -1, m_shell);
	parse->pid = fork();
	full_cmd = NULL;
	if (!parse->pid)
	{
		full_cmd = get_args(parse);
		create_dup(m_shell, parse);
		if (!full_cmd || !parse->cmd || (execve(parse->cmd, full_cmd, env)
				== -1))
		{
			if (parse->cmd && ft_strcmp(parse->cmd, "<<"))
				printf("minishell: %s: command not found\n", parse->cmd);
			execve_child_free(full_cmd, m_shell);
			exit(127);
		}
	}
	if (fd && parse->pid)
		clear_pipe(fd);
	waitpid(parse->pid, &m_shell->exec_status, 0);
	m_shell->exec_status = WEXITSTATUS(m_shell->exec_status);
}
