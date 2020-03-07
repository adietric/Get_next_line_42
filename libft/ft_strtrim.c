/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:52:54 by adietric          #+#    #+#             */
/*   Updated: 2018/11/19 11:31:55 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		debu(char const *s)
{
	int			i;

	i = 0;
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	return (i);
}

static int		fini(char const *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	i--;
	if (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		while (i != 0 && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
			i--;
		i++;
		return (i);
	}
	return (-15);
}

static char		*copy(char const *s, char *cpy, int deb, int fin)
{
	int			i;

	i = 0;
	while (deb < fin)
	{
		cpy[i] = s[deb];
		i++;
		deb++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char			*ft_strtrim(char const *s)
{
	char		*cpy;
	int			deb;
	int			fin;

	if (!s)
		return (NULL);
	deb = debu(s);
	fin = fini(s);
	if (fin == -15)
		return (ft_strdup(&s[deb]));
	if (deb > fin)
	{
		cpy = ft_strnew(1);
		return (cpy);
	}
	if (!(cpy = ft_strnew((size_t)fin - (size_t)deb)))
		return (NULL);
	return (copy(s, cpy, deb, fin));
}
