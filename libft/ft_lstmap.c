/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:50:46 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/22 15:11:07 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*1. Check if parameters are valid
2. Loop
3. Create a new element with ft_lstnew
4. Check if malloc was successful
5. If new_list is NULL (head), add new element
5. Else, add new element to the end of new_list
6. Move to the next element and continue looping
7. Return new_list*/ 

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_list;
	t_list	*new_element;

	current = lst;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (current != NULL)
	{
		new_element = ft_lstnew(f(current->content));
		if (new_element == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (new_list == NULL)
			new_list = new_element;
		else
			ft_lstadd_back(&new_list, new_element);
		current = current->next;
	}
	return (new_list);
}
