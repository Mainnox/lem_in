/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:37:18 by akremer           #+#    #+#             */
/*   Updated: 2019/07/01 17:06:11 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		compte_mot(char *str)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i] != ' ' || str[i] != '\n' || str[i] != '\t')
			word++;
		while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
			i++;
	}
	return (word);
}

static int		ft_s(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
		i++;
	return (i);
}

static int		ft_strcpyy(char *tab, char *str, int i)
{
	int j;

	j = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
	{
		tab[j] = str[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (i);
}

static int		ft_skipc(int i, char *str)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	return (i);
}

char			**ft_split_whitespace(char *str)
{
	char		**tab;
	int			j;
	int			i;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * compte_mot(str) + 1)))
		return (NULL);
	while (str[i])
	{
		i = ft_skipc(i, str);
		if (str[i])
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) * ft_s(&str[i]) + 1)))
				return (NULL);
			i = ft_strcpyy(tab[j], str, i);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
