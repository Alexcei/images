/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:41:12 by bpole             #+#    #+#             */
/*   Updated: 2019/09/17 11:44:32 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(res->content = (void*)malloc(content_size)))
		{
			free(res);
			return (NULL);
		}
		ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
