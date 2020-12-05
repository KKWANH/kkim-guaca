/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:10:03 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:10:27 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_put_hex_input(t_format fmt, char *str)
{
	int					cnt;

	cnt = 0;
	if (fmt.pre >= 0)
		cnt += ft_put_width(fmt.pre - 1, ft_strlen(str) - 1, 1);
	cnt += ft_putstr_prec(str, ft_strlen(str));
	return (cnt);
}

int						ft_put_hex_sub(t_format fmt, char *str)
{
	int					cnt;

	cnt = 0;
	if (fmt.min == 1)
		cnt += ft_put_hex_input(fmt, str);
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
		cnt += ft_put_hex_input(fmt, str);
	return (cnt);
}

/*
**ft_put_hex structure
**	if precision(fmt.pre) is 0 and number is 0 too :
**		put width with width(fmt.wid) and increase count
**		break program
**	set string by ft_utl_base by num setted unsigned long long
**	if low flag is 0 : (means x)
**		set string lower letter
**	put str and increase count
*/

int						ft_put_hex(t_format fmt, unsigned int num, int low)
{
	char				*str;
	int					cnt;

	cnt = 0;
	if (fmt.pre == 0 && num == 0)
	{
		cnt += ft_put_width(fmt.wid, 0, 0);
		return (cnt);
	}
	str = ft_utl_base((unsigned long long)num, 16);
	if (low == 0)
		str = ft_tolower(str);
	cnt += ft_put_hex_sub(fmt, str);
	free(str);
	return (cnt);
}
