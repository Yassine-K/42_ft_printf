/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:43:38 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/22 22:23:43 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pr_b.h"

int	num_len(long long int n, int b)
{
	int	i;

	i = 0;
	if (b == 16)
		n = (unsigned int) n;
	if (n < 0 && b != 16)
	{
		n *= -1;
		i++;
	}
	while (n >= b)
	{
		n /= b;
		i++;
	}
	return (i + 1);
}

int	num_len_hex(unsigned long long n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	state_f(int act[F], int t[L], long long int n)
{
	int	i;

	i = 0;
	while (i < sp)
	{
		if (t[i] == '-' && i == 0)
			act[mi] = t[i + 1];
		else if (t[i] == '0')
			act[z] = t[i + 1];
		else if (t[i] == '.')
			act[p] = t[i + 1];
		else if (t[i] == 0 && t[i + 1])
			act[w] = t[i + 1];
		if (t[i] == '.' && !t[i + 1])
			act[p] = -1;
		i += 2;
	}
	if (act[z] && n == 0 && act[p] == -1)
		act[mi] = act[z];
	if (t[sp] != '%' && act[z] && act[p] && n != 0)
		act[w] = act[z];
	act[sign] = 1;
	if (n < 0)
		act[sign] *= -1;
}

int	fill_with(char c, int n, long long int num, int j)
{
	int	i;

	i = 0;
	if (num < 0 && c == '0' && j != 2)
	{
		n++;
		i += ft_putchar('-');
	}
	while (i < n)
		i += ft_putchar(c);
	if (num < 0 && c == ' ' && j < 0)
		i += ft_putchar('-');
	return (i);
}
