/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:01:52 by adietric          #+#    #+#             */
/*   Updated: 2018/11/18 15:24:08 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*alendroi(char *str, int t)
{
	int			i;
	int			c;
	char		*final;

	if (!(final = (char*)malloc(sizeof(char) * t + 1)))
		return (NULL);
	i = 0;
	c = 0;
	while (str[i])
		i++;
	i--;
	while (i != -1)
	{
		final[c] = str[i];
		i--;
		c++;
	}
	final[c] = '\0';
	return (final);
}

static char		*rempli(int n, char *str, int t)
{
	int			i;
	int			nb;

	if (n == -2147483648)
		return (alendroi("8463847412-", t));
	nb = n;
	i = 0;
	if (n < 0)
		n = -n;
	while ((n / 10) != 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	str[i] = n % 10 + 48;
	if (nb < 0)
	{
		str[i + 1] = '-';
		i++;
	}
	str[i + 1] = '\0';
	return (alendroi(str, t));
}

static int		ftaille(int n)
{
	int			i;
	int			c;

	c = 0;
	i = 1;
	if (n < 0 && n >= -9)
		return (2);
	if (n >= 0 && n <= 9)
		return (1);
	if (n < -9)
	{
		n = -n;
		c = 1;
	}
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	return (i + c);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			t;

	if (n == -2147483648)
	{
		if (!(str = (char*)malloc(sizeof(char) * 12)))
			return (NULL);
		return (rempli(n, str, 12));
	}
	t = ftaille(n);
	if (!(str = (char*)malloc(sizeof(char) * t + 1)))
		return (NULL);
	return (rempli(n, str, t));
}
