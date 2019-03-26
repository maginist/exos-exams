/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:36:39 by maginist          #+#    #+#             */
/*   Updated: 2019/03/25 13:44:59 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*first;
	int		tmp;

	tmp = 0;
	first = lst;
	while (lst)
	{
		if (((*cmp)(lst->data, (lst->next)->data)) == 0)
		{
			tmp = lst->data;
			lst->data = (lst->next)->data;
			(lst->next)->data = tmp;
			tmp = 0;
			lst = first;
		}
		else
			lst = lst->next;
	}
	return (first);
}
