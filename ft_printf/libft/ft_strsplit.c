/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:57:58 by bpole             #+#    #+#             */
/*   Updated: 2019/09/13 18:29:20 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *str, char c)
{
	size_t	tr;
	size_t	res;

	tr = 0;
	res = 0;
	while (*str)
	{
		if (*str != c && tr == 0)
			res++;
		tr = (*str++ != c ? 1 : 0);
	}
	return (res);
}

static void		ft_free_words(char **arr, size_t i)
{
	while (i--)
		ft_strdel(&arr[i]);
	free(arr);
}

static size_t	ft_word_len(char const *str, char c)
{
	size_t	res;

	res = 0;
	while (*str && *str != c)
	{
		str++;
		res++;
	}
	return (res);
}

static char		**ft_full_arr(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	tr;
	size_t	len_word;
	char	*word;

	i = 0;
	tr = 0;
	while (*s)
	{
		if (*s != c && tr == 0)
		{
			len_word = ft_word_len(s, c);
			word = ft_strncpy(ft_strnew(len_word), s, len_word);
			if (!word)
			{
				ft_free_words(arr, i);
				return (NULL);
			}
			arr[i++] = word;
		}
		tr = (*s++ != c ? 1 : 0);
	}
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_word_count(s, c);
	if (i + 1 == 0)
		return (NULL);
	arr = (char**)malloc(sizeof(char*) * (i + 1));
	if (!arr)
		return (NULL);
	arr[i] = NULL;
	if (!ft_full_arr(arr, s, c))
		return (NULL);
	return (arr);
}
