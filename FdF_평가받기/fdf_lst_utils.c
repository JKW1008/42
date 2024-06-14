/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:01:36 by kjung             #+#    #+#             */
/*   Updated: 2024/06/08 19:44:18 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_list	*ft_fdf_lstlast(t_point_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_fdf_back(t_point_list **lst, t_point_list *ne)
{
	if (!*lst)
		*lst = ne;
	else
		ft_fdf_lstlast(*lst)->next = ne;
}
