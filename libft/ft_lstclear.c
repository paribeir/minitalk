/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:35 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/22 11:19:43 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Check if lst is empty or if the pointer to the list is null 
(checks if list doesnt exist).
Initialize current to head.
Loop: Store next node and delete current node until we reach the last node.
Finally, set the pointer to the list to NULL*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
