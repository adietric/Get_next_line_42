/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:40:17 by adietric          #+#    #+#             */
/*   Updated: 2018/11/21 10:17:08 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*rempli_tab(char const *s, char *tabtab, char c, int i)
{
	int			l;
	int			m;

	m = 0;
	l = 0;
	while (l < i)
	{
		while (s[m] == c)
			m++;
		while (s[m] != c)
			m++;
		l++;
	}
	while (s[m] == c)
		m++;
	l = 0;
	while (s[m] != c && s[m] != '\0')
	{
		tabtab[l] = s[m];
		m++;
		l++;
	}
	tabtab[l] = '\0';
	return (tabtab);
}

static int		taille_tab(char const *s, char c, int i)
{
	int			len;
	int			l;
	int			m;

	l = 0;
	m = 0;
	while (l <= i)
	{
		len = 0;
		while (s[m] == c)
			m++;
		while (s[m] != c && s[m] != '\0')
		{
			len++;
			m++;
		}
		l++;
	}
	if (s[0] == '\0')
		return (1);
	return (len);
}

static int		nb_tab_in_tab(char const *s, char c)
{
	int			i;
	int			l;
	int			j;

	i = 0;
	l = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			j++;
		}
		l++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	if (s[i - 1] != c && s[0] != '\0')
		l++;
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			l;
	int			len;
	char		**tabtab;

	if (!s)
		return (NULL);
	i = 0;
	l = nb_tab_in_tab(s, c);
	if (!(tabtab = (char**)malloc(sizeof(char*) * l)))
		return (NULL);
	while (i < (l - 1))
	{
		len = taille_tab(s, c, i);
		if (!(tabtab[i] = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		tabtab[i] = rempli_tab(s, tabtab[i], c, i);
		i++;
	}
	tabtab[i] = NULL;
	return (tabtab);
}
