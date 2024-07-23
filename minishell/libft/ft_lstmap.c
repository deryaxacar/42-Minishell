/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beonturk <beonturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:11 by beonturk          #+#    #+#             */
/*   Updated: 2024/04/22 12:32:11 by beonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ad;
	t_list	*ap;

	ad = NULL;
	while (lst)
	{
		ap = ft_lstnew(f(lst->content));
		if (!ap)
		{
			ft_lstclear(&ad, del);
			return (NULL);
		}
		ft_lstadd_back(&ad, ap);
		lst = lst->next;
	}
	return (ad);
}
