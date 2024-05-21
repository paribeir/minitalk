/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:20:12 by paribeir          #+#    #+#             */
/*   Updated: 2023/11/22 11:20:58 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Check if node (lst) exists and, if yes, free it.
Check if "content" exists and, if yes, delete it.*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		if (lst->content != NULL)
			del(lst->content);
		free(lst);
	}
}
