/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:30 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:43:31 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	is_valid_other(char *a, char *b)
{
	if ((a[0] == '<' && !a[1]) && !b)
		return (0);
	else if ((a[0] == '>' && !a[1]) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && !a[1])) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && a[1] == '<')) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '>' && a[1] == '>')) && (!ft_strcmp(a, b)))
		return (0);
	else if (((a[0] == '<' && a[1] != '<')) && (b[0] == '<' || b[0] == '>'
			|| b[0] == '|'))
		return (0);
	else if ((a[0] == '>' && a[1] != '>') && (b[0] == '<' || b[0] == '>'
			|| b[0] == '|'))
		return (0);
	else if (((a[0] == '<' && a[1] == '<')) && (b[0] == '>' || b[0] == '|'))
		return (0);
	else if ((a[0] == '>' && a[1] == '>') && (b[0] == '<' || b[0] == '>'
			|| b[0] == '|'))
		return (0);
	else if ((a[0] == '|' && !a[1] && b[0] == '|' && !b[1]))
		return (0);
	return (1);
}

int	cmd_check(t_list *lex_list, char *a, char *b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lex_list;
	while (tmp)
	{
		a = tmp->content;
		if (tmp->next)
			b = tmp->next->content;
		if (i == 0 && !b && ((a[0] == '<') || (a[0] == '>')))
			return (print_error());
		if ((a[0] == '|' && !a[1]) && i == 0)
			return (print_error());
		else if ((a[0] == '>' && !a[1]) && !b)
			return (print_error());
		else if (!is_valid_other(a, b))
			return (print_error());
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	quote_len1(char *data)
{
	int	j;
	int	i;
	int	a;

	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == '\"' || data[i] == '\'')
		{
			j++;
			a = data[i++];
			while (data[i] && data[i] != a)
			{
				i++;
			}
			if (!data[i])
				break ;
			j++;
		}
		i++;
	}
	return (j);
}

int	quote_check(char *data)
{
	int	x;

	x = 0;
	x = quote_len1(data);
	if (x % 2 != 0)
	{
		printf("minishell: quote error\n");
		return (0);
	}
	return (1);
}
