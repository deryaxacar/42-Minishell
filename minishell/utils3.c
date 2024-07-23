/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk < beonturk@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:46:36 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/24 00:39:35 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_utils2(t_shell **shell, char *back, t_list *lex,
			char *before)
{
	if (!lex->content)
	{
		free(back);
		free(before);
		malloc_error(4, shell);
	}
}

void	free_utils3(t_shell **shell, char *before, char *new_value,
			t_list *lex)
{
	if (!new_value)
	{
		free(before);
		malloc_error(4, shell);
	}
	free(lex->content);
	lex->content = ft_strjoin(before, new_value);
	free(new_value);
}

void	free_utils4(t_shell **shell, char *before, char *new_value,
			t_list *lex)
{
	if (!lex->content)
	{
		free(before);
		free(new_value);
		malloc_error(4, shell);
	}
}

void	export_utils(t_shell **shell, char **key, char **value,
			char *text)
{
	if (ft_strchr(text, '=') != 0)
	{
		*key = ft_substr(text, 0, ft_strchrindex(text, '='));
		if (!(*key))
			malloc_error(5, shell);
		*value = ft_substr(text, ft_strchrindex(text, '=') + 1, (ft_strlen(text)
					- 1));
		if (!(*value))
		{
			free(key);
			malloc_error(5, shell);
		}
	}
	else
	{
		*key = ft_substr(text, 0, ft_strlen(text));
		if (!(*key))
			malloc_error(5, shell);
		*value = NULL;
	}
}
