/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:52:38 by ykhayri           #+#    #+#             */
/*   Updated: 2022/12/03 18:09:29 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pr_b.h"

int	ft_precis_int(int n_l, int act[F], long long int n)
{
	int	len;

	len = 0;
	if (n < 0)
		act[p]++;
	if (n == 0 && act[p] < 0 && act[w])
		return (fill_with(' ', act[w] - act[pl], n, 'a') + hash_fill(act));
	if ((act[p] >= act[w] && !act[mi]) || (act[p] >= act[mi] && !act[w]))
		len += hash_fill(act) + fill_with('0', act[p] - n_l, n, 'a');
	else if (act[p] < act[w] && act[w] && act[w] > n_l)
		len += fill_with(' ', act[w] - act[p] - act[pl], n, 'a')
			+ hash_fill(act) + fill_with('0', act[p] - n_l + act[pl], n, 'a');
	else if ((act[p] < act[mi] && act[mi]) || act[z])
	{
		if (act[p] == -1 && (act[mi] > n_l || act[z] >= n_l) && n == 0)
			return (fill_with(' ', act[mi], n, 'a'));
		len += hash_fill(act) + fill_with('0', act[p] - n_l, n, 'a');
		len += ft_num(n, act[c_sp], act[sign], 'a' + len);
		if (act[mi] > n_l)
			len += fill_with(' ', act[mi] - act[p] - act[es], 0, 'a');
		return (len);
	}
	len += ft_num(n, act[c_sp], act[sign], 'a' + len);
	return (len);
}

int	ft_precis_hex(int n_l, int act[F], long long int n)
{
	int	len	;

	len = 0;
	if (n == 0 && act[p] < 0 && act[w])
		return (fill_with(' ', act[w], n, 'a') + hash_fill(act));
	if (act[p] && act[p] <= num_len(n, 16) && n)
		act[p] = num_len(n, 16);
	if ((act[p] > act[w] && !act[mi]) || (act[p] >= act[mi] && !act[w]))
		len += hash_fill(act) + fill_with('0', act[p] - n_l, n, 2);
	else if (act[p] < 0 && !act[w] && !act[z] && !act[mi])
		len += hash_fill(act);
	else if (act[p] < act[w] && act[w] && act[w] > n_l)
		len += fill_with(' ', act[w] - act[p], n, 2)
			+ hash_fill(act) + fill_with('0', act[p] - n_l, n, 2);
	else if ((act[p] < act[mi] && act[mi]) || act[z])
	{
		if (act[p] < 0 && (act[mi] >= n_l || act[z] >= n_l) && n == 0)
			return (hash_fill(act) + fill_with(' ', act[mi], n, 2));
		len = hash_fill(act);
		len += fill_with('0', act[p] - n_l, n, 2) + ft_hex(n, act[c_sp]);
		if (act[mi] > n_l)
			len += fill_with(' ', act[mi] - len, 0, 2);
		return (len);
	}
	return (len + ft_hex(n, act[c_sp]));
}

int	ft_precis_str(char *s, int len, int act[F])
{
	int	l;
	int	i;

	l = 0;
	i = -1;
	if (act[p] < 0)
		act[p]++;
	if (act[w] && act[p] > len)
		l += fill_with(' ', act[w] - len, 0, 'a');
	else if (act[w] && act[p] <= len)
		l += fill_with(' ', act[w] - act[p], 0, 'a');
	if (len >= act[p])
		while (++i < act[p])
			l += ft_putchar(s[i]);
	else
		l += ft_putstr(s);
	if (act[mi])
		l += fill_with(' ', act[mi] - l, 0, 'a');
	return (l);
}

int	check_p(const char *s, long long int n, int a[F], int n_len)
{
	unsigned int	u;
	int				i;
	int				len;

	u = n;
	i = -1;
	len = 0;
	while (s[++i] && !in_str(s[i], 2))
	{
		if (n >= 0 && (a[c_sp] == 'd' || a[c_sp] == 'i' || a[c_sp] == 'u'))
		{
			if (s[i] == ' ' && (!a[w] || (!a[z] && a[w] < a[p])
					|| (!a[w] && a[z] < a[p]) || a[w] <= n_len))
				a[es] = 1;
			else if (s[i] == '+')
				a[pl] = 1;
		}
		else if (s[i] == '#' && u && (a[c_sp] == 'X' || a[c_sp] == 'x'))
			a[h] = 1;
	}
	if (a[pl])
		len = 1;
	if (a[w] && a[h])
		a[w] -= 2;
	return (len);
}

int	hash_fill(int act[F])
{
	int	i;

	i = 0;
	if (act[es])
		i += ft_putchar(' ');
	if (act[pl])
		i += ft_putchar('+');
	if ((act[h] && act[c_sp] == 'x') || act[p] == -1337)
		i += ft_putstr("0x");
	if (act[h] && act[c_sp] == 'X')
		i += ft_putstr("0X");
	if (act[h] && (act[c_sp] == 'x' || act[c_sp] == 'X'))
	{
		if (act[z])
			act[z] -= 2;
		if (act[mi])
			act[mi] -= 2;
	}
	return (i);
}
