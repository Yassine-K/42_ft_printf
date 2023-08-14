/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:20:52 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/20 23:23:42 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pr_b.h"

int	in_str(char s, int k)
{
	int		i;
	char	*str[4];

	str[0] = "0123456789";
	str[1] = "0.-";
	str[2] = "c%spdiuxX";
	str[3] = "+ #";
	i = -1;
	while (str[k][++i])
		if (str[k][i] == s)
			return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 1;
	j = 0;
	while (s[i] < 33)
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			j *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		j = j * 10 + s[i] - 48;
		i++;
	}
	return (j * c);
}

int	mark_f(const char *s, int r[M][L], int of)
{
	int	k[2];

	k[0] = 0;
	k[1] = 0;
	while (!in_str(s[k[0]], 2) && s[k[0]])
	{
		r[sm][fl_c]++;
		while (in_str(s[k[0]], 3))
			k[0]++;
		if (in_str(s[k[0]], 1))
			r[of][k[1]] = s[k[0]++];
		while ((s[k[0]] == s[k[0] - 1] && r[of][k[1]]) || s[k[0]] == '#')
			k[0]++;
		if (in_str(s[k[0]], 0) || in_str(s[k[0]], 1))
			r[of][++k[1]] = ft_atoi(&s[k[0]]);
		while (in_str(s[k[0]], 0))
			k[0]++;
		k[1]++;
	}
	r[of][pos] = k[0];
	r[sm][sp_c]++;
	r[of][sp] = s[k[0]];
	return (k[0]);
}

void	ft_scan(const char *s, int f[M][L])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	f[sm][sp_c] = 0;
	f[sm][fl_c] = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			f[sm][fl_c] += in_str(s[i + 1], 3);
			j = mark_f(&s[++i], f, f[sm][sp_c]);
			i += j + 1;
		}
		else
			i++;
	}
	f[f[sm][sp_c]][sp] = -1;
}

void	fill_info(int act[F], int t[L], long long int n)
{
	int	i;

	i = -1;
	while (++i < F)
		act[i] = 0;
	state_f(act, t, n);
	act[c_sp] = t[sp];
	if (t[sp] == 'p')
	{
		if (act[p] == -1 && n == 0)
			act[p] = -1337;
		if (act[w])
			act[w] -= 2;
		if (act[mi])
			act[mi] -= 2;
		if (n < 0 && (act[p] > act[w] || act[z]))
			act[p]++;
	}
}
