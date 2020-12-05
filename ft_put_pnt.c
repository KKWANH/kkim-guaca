/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:17:35 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:17:36 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**ft_put_pnt_input structure
**	set count as 2(result from put "0x")
**	if precision(fmt:pre) isnt negative :
**		put width by precision(fmt:pre), length:pointer, 1 and increase count
**		put pointer with precision(fmt:pre)
**	if not :
**		put pointer with length:pointer
*/

int						ft_put_pnt_input(t_format fmt, char *pnt)
{
	int					cnt;

	cnt = ft_putstr("0x");
	if (fmt.pre >= 0)
	{
		cnt += ft_put_width(fmt.pre, ft_strlen(pnt), 1);
		cnt += ft_putstr_prec(pnt, fmt.pre);
	}
	else
		cnt += ft_putstr_prec(pnt, ft_strlen(pnt));
	return (cnt);
}

/*
**ft_put_pnt_sub structure
**	if width(fmt:wid) isnt negative and minus is 0 (means right align) :
**		put width by width(fmt:wid) - 2 and increase count
**		put 0x and increase count
**	if not :
**		put 0x and increase count
**		put width by width(fmt:wid) - 2 and increase count
*/

int						ft_put_pnt_sub(t_format fmt, int cnt)
{
	if (fmt.wid >= 0 && fmt.min == 0)
	{
		cnt += ft_put_width(fmt.wid - 2, 0, 0);
		cnt += ft_putstr("0x");
	}
	else
	{
		cnt += ft_putstr("0x");
		cnt += ft_put_width(fmt.wid - 2, 0, 0);
	}
	return (cnt);
}

/*
**ft_put_pnt structure
**	if precision is 0 and num is unavailable :
**		set coutn as result that came from ft_put_pnt_sub by format and count
**		break program
**	set pointer(char *) :
**		set as result that came from ft_utl_base by ull to 16
**		set as small letter
**	if minus(fmt.min) = 1 : (means left align)
**		put pointer by ft_put_pnt_input and increase count
**	if precision isnt negative :
**		put width by width(fmt.wid), length:string and increase count
**	if minus(fmt.min) = 0 : (means right align)
**		put pointer by ft_put_pnt_input and increase count
*/

int						ft_put_pnt(t_format fmt, unsigned long long num)
{
	int					cnt;
	char				*pnt;

	cnt = 0;
	if (fmt.pre == 0 && !num)
	{
		cnt = ft_put_pnt_sub(fmt, cnt);
		return (cnt);
	}
	pnt = ft_utl_base(num, 16);
	pnt = ft_tolower(pnt);
	if (fmt.pre < ft_strlen(pnt))
		fmt.pre = ft_strlen(pnt);
	if (fmt.min == 1)
		cnt += ft_put_pnt_input(fmt, pnt);
	if (fmt.pre >= 0)
		cnt += ft_put_width(fmt.wid, ft_strlen(pnt) + 2, 0);
	if (fmt.min == 0)
		cnt += ft_put_pnt_input(fmt, pnt);
	free(pnt);
	return (cnt);
}
