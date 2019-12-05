/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:35:06 by bpole             #+#    #+#             */
/*   Updated: 2019/09/26 17:01:32 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*first;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!tmp)
		return (NULL);
	first = tmp;
	while (lst->next)
	{
		lst = lst->next;
		first->next = f(lst);
		if (!first->next)
		{
			ft_lstdel(&tmp, ft_bzero);
			return (NULL);
		}
		first = first->next;
	}
	return (tmp);
}
