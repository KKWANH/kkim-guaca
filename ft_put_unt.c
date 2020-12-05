/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:22:29 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:23:22 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_put_unt_input(t_format fmt, char *unt)
{
	int					cnt;

	cnt = 0;
	if (fmt.pre >= 0)
		cnt += ft_put_width(fmt.pre - 1, ft_strlen(unt) - 1, 1);
	cnt += ft_putstr_prec(unt, ft_strlen(unt));
	return (cnt);
}

/*
**ft_put_unt_sub structure
**	if minus(fmt.min) is 1 : (means left align)
**		put unt and increase count
**	if precision(fmt.pre) isnt negative and
**	   precision(fmt.pre) is smaller than length:unt :
**		set precision as length:unt
**	if precision(fmt.pre) isnt negative :
**		set width(fmt.wid) as width(fmt.wid) - precision(fmt.pre)
**		put width by width(fmt.wid) and increase count
**	if not :
**		put width by width(fmt.wid), length:unt, zero(fmt.zer) and
**		 increase count
**	if minus(fmt.min) is 0 : (means right align)
**		put unt and increase count
*/

int						ft_put_unt_sub(t_format fmt, char *unt)
{
	int					cnt;

	cnt = 0;
	if (fmt.min == 1)
		cnt += ft_put_unt_input(fmt, unt);
	if (fmt.pre >= 0 && fmt.pre < ft_strlen(unt))
		fmt.pre = ft_strlen(unt);
	if (fmt.pre >= 0)
	{
		fmt.wid -= fmt.pre;
		cnt += ft_put_width(fmt.wid, 0, 0);
	}
	else
		cnt += ft_put_width(fmt.wid, ft_strlen(unt), fmt.zer);
	if (fmt.min == 0)
		cnt += ft_put_unt_input(fmt, unt);
	return (cnt);
}

/*
**ft_put_unt structure
**	set num as (4294967295(max number of unsigned int) + num + 1)
**	 to unsigned int
**	if precision(fmt.pre) is 0 and number is 0 too :
**		put width with width(fmt.wid) and increase count
**		break program
**	set unt(char *) as result of ft_itoa:num
**	put unt with ft_put_unt_sub and increase count
*/

int						ft_put_unt(t_format fmt, unsigned int num)
{
	char				*unt;
	int					cnt;

	cnt = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	if (fmt.pre == 0 && num == 0)
	{
		cnt += ft_put_width(fmt.wid, 0, 0);
		return (cnt);
	}
	unt = ft_itoa_u(num);
	cnt = ft_put_unt_sub(fmt, unt);
	free(unt);
	return (cnt);
}
