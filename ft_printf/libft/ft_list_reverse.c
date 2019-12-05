/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:04:33 by bpole             #+#    #+#             */
/*   Updated: 2019/09/26 17:25:49 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*privios;
	t_list	*next;
	t_list	*current;

	privios = NULL;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		current->next = privios;
		privios = current;
		current = next;
	}
	*begin_list = privios;
}
