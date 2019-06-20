/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:15:11 by akremer           #+#    #+#             */
/*   Updated: 2019/03/27 13:38:56 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		compte_mot(char *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
			word++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (word);
}

static int		ft_s(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

static int		ft_strcpyy(char *tab, char *str, int i, char c)
{
	int j;

	j = 0;
	while (str[i] && (str[i] != c))
	{
		tab[j] = str[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (i);
}

static int		ft_skipc(int i, char c, char *str)
{
	while (str[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**tab;
	int			j;
	int			i;
	char		*str;

	str = (char*)s;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * compte_mot(str, c) + 1)))
		return (NULL);
	while (str[i])
	{
		i = ft_skipc(i, c, str);
		if (str[i])
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) * ft_s(&str[i], c) + 1)))
				return (NULL);
			i = ft_strcpyy(tab[j], str, i, c);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
