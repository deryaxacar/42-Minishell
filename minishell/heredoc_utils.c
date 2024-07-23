/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:44:47 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:48 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <sys/ioctl.h>
#include <unistd.h>

void	killer(int sig)
{
	(void)sig;
	g_check_heredoc = -3;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
}

void	set_heredoc(int sig)
{
	(void)sig;
	g_check_heredoc = -10;
}
