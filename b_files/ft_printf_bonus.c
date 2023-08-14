/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:30:37 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/25 18:11:05 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pr_b.h"

int	ft_int(long long int n, int t[L], const char *s, int d[2])
{
	int	a[F];

	d[len] = 0;
	if (n < 0 && t[sp] == 'u')
		n = (unsigned int) n;
	fill_info(a, t, n);
	d[n_l] = num_len(n, 10);
	d[n_l] += check_p(s, n, a, d[n_l]);
	if (t[0] == 0 && t[1] == 0 && !in_str(s[d[0]], 3))
		return (hash_fill(a) + ft_num(n, t[sp], a[sign], 'a'));
	if (n == 0 && a[p] < a[z] && a[p] > 0)
		d[len] += fill_with(' ', a[z] - a[p], n, 'a');
	if (a[p] == -1 && n == 0 && !a[mi] && !a[z] && !a[w])
		return (ft_putstr(""));
	if (a[p] >= d[n_l] || (a[p] && !n && (a[mi] || a[z] || a[w])))
		return (d[len] + ft_precis_int(d[n_l], a, n));
	else if (a[w] || (a[z] && a[p]))
		d[len] += fill_with(' ', a[w] - d[n_l], n, a[sign]);
	else if (a[mi] && a[mi] > d[n_l])
		return (hash_fill(a) + ft_num(n, t[sp], a[sign], 'a')
			+ fill_with(' ', a[mi] - d[n_l] - a[es], n, a[sign] * -1));
	else if (a[z])
		return (hash_fill(a) + fill_with('0', a[z] - d[n_l]
				, n, a[sign]) + ft_num(n, t[sp], a[sign], 'b'));
	return (d[len] + hash_fill(a) + ft_num(n, t[sp], a[sign], 'a' + d[len]));
}

int	ft_hex_b(long long int n, int t[L], const char *s, int d[2])
{
	int	a[F];

	d[len] = 0;
	fill_info(a, t, n);
	d[n_l] = num_len(n, 16);
	if (t[sp] == 'p')
		d[n_l] = num_len_hex(n);
	d[n_l] += check_p(s, n, a, d[n_l]);
	if (t[0] == 0 && t[1] == 0 && (!in_str(s[d[0]], 3) || s[0] == '#'))
		return (hash_fill(a) + ft_hex(n, t[sp]));
	if (n == 0 && a[p] < a[z] && a[p] > 0)
		d[len] += fill_with(' ', a[z] - a[p], n, 'a');
	if (a[p] < 0 && n == 0 && !a[mi] && !a[z] && !a[w])
		return (hash_fill(a) + ft_putstr(""));
	if (a[p] >= d[n_l] || (a[p] && n)
		|| (a[p] && !n && (a[mi] || a[z] || a[w])))
		return (d[len] + ft_precis_hex(d[n_l], a, n));
	else if (a[w] || (a[z] && a[p]))
		d[len] += fill_with(' ', a[w] - d[n_l], n, 2) + hash_fill(a);
	else if (a[mi] && a[mi] > d[n_l])
		return (hash_fill(a) + ft_hex(n, t[sp]) + fill_with(' ',
				a[mi] - d[n_l], n, 2));
	else if (a[z])
		d[len] += hash_fill(a) + fill_with('0', a[z] - d[n_l], n, 2);
	return (d[len] + ft_hex(n, t[sp]));
}

int	ft_str(char *s, int t[L], int data[2])
{
	int	act[F];
	int	n;

	n = 1;
	data[len] = 0;
	if (!s && t[sp] == 's')
		s = "(null)";
	if (t[sp] == 's' && s)
		data[n_l] = ft_strlen(s);
	else if (t[sp] == 'c' || t[sp] == '%')
		data[n_l] = 1;
	fill_info(act, t, n);
	if (t[0] == 0 && t[1] == 0 && (t[sp] == 's'))
		return (ft_string(s, t[sp]));
	if (t[sp] == 's' && act[p] && s[0])
		return (ft_precis_str(s, data[n_l], act));
	else if (act[w])
		data[len] += fill_with(' ', act[w] - data[n_l], n, act[sign]);
	else if (act[mi] && act[mi] > data[n_l])
		return (ft_string(s, t[sp])
			+ fill_with(' ', act[mi] - data[n_l], n, act[sign] * -1));
	else if (act[z])
		data[len] += fill_with('0', act[z] - data[n_l], n, act[sign]);
	return (data[len] + ft_string(s, t[sp]));
}

int	normal_pr(const char *s, va_list args)
{	
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
				len += ft_putchar('%');
			else if (*(s + 1) == 's' || *(s + 1) == 'c')
				len += ft_string(va_arg(args, char *), *(s + 1));
			else if (*(s + 1) == 'p' || *(s + 1) == 'x' || *(s + 1) == 'X')
				len += ft_hex(va_arg(args, long long int), *(s + 1));
			else if (*(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'u')
				len += ft_num(va_arg(args, long long int), *(s + 1), 1, 'a');
			s++;
		}
		else
			len += ft_putchar(*s);
		s++;
	}
	return (len);
}

int	flag_pr(const char *s, va_list args, int f[M][L], int data[2])
{
	int	len;
	int	p;

	len = 0;
	p = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (f[p][sp] == '%')
				len += ft_str("%", f[p], data);
			else if (f[p][sp] == 's' || f[p][sp] == 'c')
				len += ft_str(va_arg(args, char *), f[p], data);
			else if (f[p][sp] == 'p' || f[p][sp] == 'x' || f[p][sp] == 'X')
				len += ft_hex_b(va_arg(args, long long int), f[p], s + 1, data);
			else if (f[p][sp] == 'd' || f[p][sp] == 'i' || f[p][sp] == 'u')
				len += ft_int((long int) va_arg(args, int), f[p], s + 1, data);
			s += f[p][pos] + 1;
			p++;
		}
		else
			len += ft_putchar(*s);
		s++;
	}
	return (len);
}
