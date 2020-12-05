/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:24:42 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:24:42 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_numlen(int num)
{
	size_t				len;
	int					neg;

	len = 0;
	neg = 0;
	if (num < 0)
	{
		len++;
		neg++;
		num = -num;
	}
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char					*ft_generate(char *rst, long num, int len, int neg)
{
	if (num != 0)
		rst = malloc(sizeof(char) * (len + 1));
	else
		return (rst = ft_strdup("0"));
	if (!rst)
		return (0);
	neg = 0;
	if (num < 0)
	{
		++neg;
		num *= -1;
	}
	rst[len] = '\0';
	while (--len)
	{
		rst[len] = (num % 10) + '0';
		num /= 10;
	}
	if (neg == 1)
		rst[0] = '-';
	else
		rst[0] = (num % 10) + '0';
	return (rst);
}

char					*ft_itoa(int nm1)
{
	int					len;
	char				*rst;
	long				num;
	int					neg;

	num = nm1;
	len = ft_numlen(num);
	rst = 0;
	neg = 0;
	rst = ft_generate(rst, num, len, neg);
	if (!rst)
		return (0);
	return (rst);
}

char					*ft_base(unsigned long long num, int bas,
						int cnt, char *str)
{
	while (num != 0)
	{
		if ((num % bas) < 10)
			str[cnt - 1] = (num % bas) + 48;
		else
			str[cnt - 1] = (num % bas) + 55;
		num /= bas;
		cnt--;
	}
	return (str);
}

char					*ft_utl_base(unsigned long long num, int bas)
{
	unsigned long long	tmp;
	int					cnt;
	char				*str;

	tmp = num;
	str = 0;
	cnt = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		num /= bas;
		cnt++;
	}
	if (!(str = malloc(cnt + 1)))
		return (0);
	str[cnt] = '\0';
	str = ft_base(tmp, bas, cnt, str);
	return (str);
}
