/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:51:26 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/23 21:42:13 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long int i, char s)
{
	int	c;

	c = 0;
	if (i < 0)
	{
		if (s == 'a')
		{
			ft_putchar('-');
			c++;
		}
		i *= -1;
	}
	if (i < 10 && i >= 0)
	{
		ft_putchar(i + 48);
		c++;
	}
	else
	{
		c += ft_putnbr(i / 10, s);
		c += ft_putchar((i % 10) + 48);
	}
	return (c);
}

int	hex_long(unsigned long long num, char *s)
{
	int					i;
	char				a;

	i = 0;
	if (num >= 16)
		i += hex_long((num / 16), s);
	a = s[num % 16];
	i += ft_putchar(a);
	return (i);
}

int	hex_int(unsigned int num, char *str)
{
	int		i;
	char	a;

	i = 0;
	if (num >= 16)
		i += hex_int((num / 16), str);
	a = str[num % 16];
	i += ft_putchar(a);
	return (i);
}
