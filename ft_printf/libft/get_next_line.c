/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:06:15 by bpole             #+#    #+#             */
/*   Updated: 2019/11/19 21:14:51 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_lst_add(t_lst **root, t_lst *new)
{
	if (root && new)
	{
		new->next = *root;
		*root = new;
	}
}

static t_lst		*ft_lst_new(char *res, int fd)
{
	t_lst			*lst;

	if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	lst->res = res;
	lst->fd = fd;
	lst->next = NULL;
	return (lst);
}

static t_lst		*ft_lst_init(char **line, t_lst **root, int fd)
{
	t_lst			*lst;

	if (fd < 0 || line == NULL || !*root || BUFF_SIZE < 1)
		return (NULL);
	lst = *root;
	while (lst)
	{
		if (lst->fd == fd)
		{
			if (!lst->res)
				lst->res = ft_strnew(0);
			return (lst);
		}
		lst = lst->next;
	}
	lst = ft_lst_new(ft_strnew(0), fd);
	if (!lst)
		return (NULL);
	ft_lst_add(root, lst);
	if (!lst->res)
		lst->res = ft_strnew(0);
	return (lst);
}

static int			ft_pars(char **line, int fd, char **res, int bites)
{
	char			*tmp;
	int				i;

	i = 0;
	while ((*res)[i] != '\0' && (*res)[i] != '\n')
		i++;
	if ((*res)[i] == '\0')
	{
		if (bites > 0)
			return (get_next_line(fd, line));
		*line = *res;
		*res = NULL;
		return (1);
	}
	*line = ft_strsub(*res, 0, i);
	if (!*line)
		return (-1);
	tmp = *res;
	*res = ft_strdup(*res + i + 1);
	if (!*res)
		return (-1);
	free(tmp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_lst	*root;
	t_lst			*lst;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				bites;

	bites = 0;
	if (!root)
		root = ft_lst_new(ft_strnew(0), fd);
	lst = ft_lst_init(line, &root, fd);
	if (!lst)
		return (-1);
	if (ft_strchr(lst->res, '\n') == NULL)
	{
		if ((bites = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[bites] = '\0';
		tmp = lst->res;
		lst->res = ft_strjoin(lst->res, buf);
		if (!lst->res)
			return (-1);
		free(tmp);
	}
	return (lst->res[0] ? ft_pars(line, fd, &lst->res, bites) : 0);
}
