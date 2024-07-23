/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:44:58 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:59 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int	ignore_quote(char const *cmd, int i)
{
	if (cmd[i] == '\"')
	{
		i++;
		while (cmd[i] != '\"')
			i++;
	}
	else if (cmd[i] == '\'')
	{
		i++;
		while (cmd[i] != '\'')
			i++;
	}
	return (i);
}

static int	len_for_separate(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || !*cmd)
		return (0);
	if (cmd[i] == '<' && cmd[i + 1] == '<')
		return (2);
	if (cmd[i] == '>' && cmd[i + 1] == '>')
		return (2);
	if (cmd[i] == '<' || cmd[i] == '>' || cmd[i] == '|')
		return (1);
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<'
		&& cmd[i] != '|')
	{
		if (cmd[i] == '\"' || cmd[i] == '\'')
		{
			i = ignore_quote(cmd, i) + 1;
		}
		else
			i++;
	}
	return (i);
}

void	lexer(char *cmd, t_list **lex_list, t_shell **shell)
{
	int		len;
	char	*content;
	char	*trimmed_content;

	if (!cmd || !*cmd)
		return ;
	cmd = ft_strtrim(cmd, " ");
	if (!cmd)
		malloc_error(4, shell);
	len = len_for_separate(cmd);
	content = ft_substr(cmd, 0, len);
	if (!content)
		malloc_error(4, shell);
	trimmed_content = ft_strtrim(content, " ");
	if (!trimmed_content)
		malloc_error(4, shell);
	free(content);
	ft_lstadd_back(lex_list, ft_lstnew(trimmed_content));
	lexer(cmd + len, lex_list, shell);
	free(cmd);
}
