/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:46:30 by jlinguet          #+#    #+#             */
/*   Updated: 2023/11/16 14:24:28 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_del;
	t_list	**first;

	first = lst;
	while ((*lst)->next)
	{
		to_del = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(to_del, del);
	}
	ft_lstdelone(ft_lstlast(*first), del);
	*first = NULL;
}
