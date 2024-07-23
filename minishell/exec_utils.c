/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:44:13 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:14 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse	*get_next_cmd(t_parse **parse)
{
	t_parse	*tmp;

	tmp = *parse;
	while (tmp->infile > STDERR || tmp->outfile > STDERR
		|| tmp->type == HEREDOC)
	{
		tmp = tmp->next;
	}
	return (tmp->next);
}

int	single_or_multi_command(t_shell *m_shell)
{
	t_parse	*parse;
	int		i;

	i = 0;
	parse = m_shell->parse;
	while (parse)
	{
		if (parse->type == 2)
			i++;
		parse = parse->next;
	}
	return (i);
}
