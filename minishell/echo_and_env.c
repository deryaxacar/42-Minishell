/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:58 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:43:59 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	run_echo(t_parse *data, int *i)
{
	int	x;
	int	j;

	x = *i;
	while (data->text[x])
	{
		j = 0;
		while (data->text[x][j])
			write(data->outfile, &data->text[x][j++], 1);
		if (data->text[x][j] == '\0' && data->text[x + 1] != NULL)
			write(data->outfile, " ", 1);
		x++;
		*i += 1;
	}
}

static int	all_n_chars(const char *str)
{
	while (*str != '\0')
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

void	exec_echo(t_parse *data, t_shell *m_shell)
{
	int	i;

	i = 0;
	if (!data->text || !data->text[0])
		write(data->outfile, "\n", 1);
	else
	{
		if (data->text[0] && data->text[0][0] == '-' && data->text[0][1] == 'n'
			&& all_n_chars(data->text[0] + 2))
		{
			while (data->text[i] && data->text[i][0] == '-' && \
			data->text[i][1] == 'n' && all_n_chars(data->text[i] + 2))
				i++;
			if (data->text[i])
				run_echo(data, &i);
		}
		else
		{
			run_echo(data, &i);
			if (!data->text[i])
				write(data->outfile, "\n", 1);
		}
	}
	m_shell->exec_status = 0;
}

void	print_list(void *data, t_shell *m_shell)
{
	t_parse	*str;
	t_env	*new;
	int		i;

	i = 0;
	str = m_shell->parse;
	new = (t_env *)data;
	if (!new->value)
		return ;
	while (new->key[i])
		write(str->outfile, &new->key[i++], 1);
	write(str->outfile, "=", 1);
	i = 0;
	while (new->value && new->value[i])
		write(str->outfile, &new->value[i++], 1);
	write(str->outfile, "\n", 1);
}

void	exec_env(t_shell *m_shell)
{
	ft_newlstiter(m_shell->env, print_list, m_shell);
	m_shell->exec_status = 0;
}
