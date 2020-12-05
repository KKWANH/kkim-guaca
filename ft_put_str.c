/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:18:16 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:20:35 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_put_str_input structure
**	if precision(fmt.pre) isnt negative
**		put width by precision(fmt.pre), length:string and increase count
**		put string by string, precision(fmt.pre) ;cut and increase count
*/

int						ft_put_str_input(t_format fmt, char *str)
{
	int					cnt;

	cnt = 0;
	if (fmt.pre >= 0)
	{
		cnt += ft_put_width(fmt.pre, ft_strlen(str), 0);
		cnt += ft_putstr_prec(str, fmt.pre);
	}
	else
		cnt += ft_putstr_prec(str, ft_strlen(str));
	return (cnt);
}

/*
**ft_put_str structure
**	if str is empty :
**		set str as "(null)"
**	if precision(fmt.pre) isnt negative and
**	   precision is bigger than length:string :
**		set precision as length:string
**	if minus(fmt.min) = 1 : (means left align)
**		put string by ft_put_str_input and increase count
**	if precision isnt negative :
**		put width by width(fmt.wid), precision(fmt.pre) and increase count
**	if not :
**		put width by width(fmt.wid), length:string and increase count
**	if minus(fmt.min) = 0 : (means right align)
**		put string by ft_put_str_input and increase count
*/

int						ft_put_str(t_format fmt, char *str)
{
	int					cnt;

	cnt = 0;
	if (!str)
		str = "(null)";
	if (fmt.pre >= 0 && fmt.pre > ft_strlen(str))
		fmt.pre = ft_strlen(str);
	if (fmt.min == 1)
		cnt += ft_put_str_input(fmt, str);
	if (fmt.pre >= 0)
		cnt += ft_put_width(fmt.wid, fmt.pre, fmt.zer);
	else
		cnt += ft_put_width(fmt.wid, ft_strlen(str), fmt.zer);
	if (fmt.min == 0)
		cnt += ft_put_str_input(fmt, str);
	return (cnt);
}
