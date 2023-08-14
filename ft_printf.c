/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:30:37 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/20 18:08:33 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *s, char c)
{
	int	len;

	len = 0;
	if (!s && c == 'c')
		return (ft_putchar(0));
	if (c == 'c')
		return (ft_putchar((char) s));
	if (!s)
		return (ft_putstr("(null)"));
	else if (c == 's' && !s[0])
		len += ft_putstr("");
	else
		len += ft_putstr(s);
	return (len);
}

int	ft_hex(long long int i, char c)
{
	int		len;
	char	*s1;
	char	*s2;

	len = 0;
	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	if (c == 'p')
	{
		ft_putstr("0x");
		len += 2 + ft_putnbr_hex((unsigned long long) i, c, s1);
	}
	else if (c == 'X')
		len += ft_putnbr_hex((int) i, c, s2);
	else if (c == 'x')
		len += ft_putnbr_hex((int) i, c, s1);
	return (len);
}

int	ft_putnbr_hex(long long int n, char c, char *s)
{
	int	i;
	int	b;

	i = 0;
	if (c == 'p')
		i += hex_long(n, s);
	else
	{
		b = (unsigned int) n;
		i += hex_int(b, s);
	}
	return (i);
}

int	ft_num(long long int i, char c, int sign, int s)
{
	int	len;

	len = 0;
	if (s == 'a')
		sign = 1;
	if (c == 'd' || c == 'i')
		len += ft_putnbr((int)(i * sign), s);
	else if (c == 'u')
		len += ft_putnbr((unsigned int) i, s);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		f[M][L];
	int		data[2];

	len = 0;
	data[len] = 0;
	data[n_l] = 0;
	ft_scan(s, f);
	va_start(args, s);
	if (f[sm][fl_c] == 0)
		len = normal_pr(s, args);
	else
		len += flag_pr(s, args, f, data);
	va_end(args);
	return (len);
}
