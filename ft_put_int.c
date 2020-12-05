/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:14:48 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:14:50 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_put_int_input(char *str, int num, t_format fmt)
{
	int					cnt;

	cnt = 0;
	if (fmt.pre >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (fmt.pre >= 0)
		cnt += ft_put_width(fmt.pre - 1, ft_strlen(str) - 1, 1);
	cnt += ft_putstr_prec(str, ft_strlen(str));
	return (cnt);
}

int						ft_put_int_sub(char *str, int num, t_format fmt)
{
	int					cnt;

	cnt = 0;
	if (fmt.min == 1)
		cnt += ft_put_int_input(str, num, fmt);
	if (fmt.pre >= 0 && fmt.pre < ft_strlen(str))
		fmt.pre = ft_strlen(str);
	if (fmt.pre >= 0)
	{
		fmt.wid -= fmt.pre;
		cnt += ft_put_width(fmt.wid, 0, 0);
	}
	else
		cnt += ft_put_width(fmt.wid, ft_strlen(str), fmt.zer);
	if (fmt.min == 0)
		cnt += ft_put_int_input(str, num, fmt);
	return (cnt);
}

int						ft_put_int(t_format fmt, int nm1)
{
	int					cnt;
	char				*str;
	int					nm2;

	cnt = 0;
	nm2 = nm1;
	if (fmt.pre == 0 && nm1 == 0)
	{
		cnt = ft_put_width(fmt.wid, 0, 0);
		return (cnt);
	}
	if (nm1 == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nm1 < 0 && (fmt.pre >= 0 || fmt.zer == 1) && nm2 != -2147483648)
	{
		if (fmt.pre <= -1 && fmt.zer == 1)
			ft_putchar('-');
		nm1 *= -1;
		fmt.zer = 1;
		--fmt.wid;
		++cnt;
	}
	cnt += ft_put_int_sub((str = ft_itoa(nm1)), nm2, fmt);
	free(str);
	return (cnt);
}
