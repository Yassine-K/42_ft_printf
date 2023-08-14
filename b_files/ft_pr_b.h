/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:24:26 by ykhayri           #+#    #+#             */
/*   Updated: 2022/11/29 18:01:52 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PR_B_H
# define FT_PR_B_H

# define M 200000
# define L 8
# define F 9

# include <stdarg.h>

void	ft_scan(const char *s, int f[M][L]);
int		in_str(char s, int k);

int		flag_pr(const char *s, va_list args, int flags[M][L], int data[2]);
int		normal_pr(const char *s, va_list args);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long long int i, char s);
int		ft_putnbr_hex(long long int nbr, char c, char *s);
int		hex_int(unsigned int num, char *str);
int		hex_long(unsigned long long num, char *s);
int		ft_string(char *s, char c);
int		ft_hex(long long int i, char c);
int		ft_num(long long int i, char c, int sign, int s);

int		ft_str(char *s, int t[L], int data[2]);
int		ft_int(long long int n, int t[L], const char *s, int data[2]);
int		ft_hex_b(long long int n, int t[L], const char *s, int data[2]);

int		ft_strlen(char *s);
int		num_len(long long int num, int b);
int		num_len_hex(unsigned long long n);

void	fill_info(int act[F], int t[L], long long int n);
void	state_f(int act[F], int t[L], long long int n);

int		fill_with(char c, int n, long long int num, int j);
int		ft_precis_int(int n_l, int act[F], long long int n);
int		ft_precis_hex(int n_l, int act[F], long long int n);
int		ft_precis_str(char *s, int len, int act[F]);
int		check_p(const char *s, long long int n, int a[F], int n_len);
int		hash_fill(int act[F]);

enum e_case {sp_c, sm = M - 1, pos = L - 1, sp = L - 2, fl_c = 1};
enum e_state {mi, z, w , p, es, pl, h, c_sp};
enum e_data {len, sign = F - 1, n_l = 1};

#endif
