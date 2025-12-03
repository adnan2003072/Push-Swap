/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:01:42 by abouzkra          #+#    #+#             */
/*   Updated: 2025/12/03 09:54:42 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libpush_swap.h"

static size_t	strs_count(char const *s, char c);
static char		**empty_arr(void);
static int		extract_words(char const *s, char c, char **res);

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (empty_arr());
	res = (char **)malloc(sizeof(char *) * (strs_count(s, c) + 1));
	if (!res)
		return (NULL);
	if (extract_words(s, c, res))
	{
		free_split(res);
		return (NULL);
	}
	return (res);
}

static size_t	strs_count(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static int	extract_words(char const *s, char c, char **res)
{
	size_t	len;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		*res = ft_substr(s, 0, len);
		if (!*res)
			return (1);
		s += len;
		res++;
	}
	*res = NULL;
	return (0);
}

static char	**empty_arr(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *));
	if (!res)
		return (NULL);
	*res = NULL;
	return (res);
}
