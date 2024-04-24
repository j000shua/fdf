/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:43:54 by jlinguet          #+#    #+#             */
/*   Updated: 2023/11/16 14:25:34 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	t_list	*new;

	new = NULL;
	size = ft_lstsize(lst);
	while (size)
	{
		ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(new)->content)
			del(ft_lstlast(new)->content);
		lst = lst->next;
		size--;
	}
	return (new);
}
