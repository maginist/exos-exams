/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:44:06 by maginist          #+#    #+#             */
/*   Updated: 2019/03/25 11:52:54 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list				*sort_list(t_list *lst, int (*cmp)(int, int));

#endif
