/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:24:13 by kjung             #+#    #+#             */
/*   Updated: 2024/06/17 18:04:08 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_lst	*ft_ps_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_ps_back(t_lst **lst, t_lst *ne)
{
	if (!*lst)
		*lst = ne;
	else
		ft_ps_lstlast(*lst)->next = ne;
}
