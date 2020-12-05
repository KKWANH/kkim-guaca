/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:01:48 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:01:50 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_format_put(t_format fmt, va_list var)
{
	int					cnt;

	if (fmt.typ == 1)
		cnt = ft_put_int(fmt, va_arg(var, int));
	if (fmt.typ == 2)
		cnt = ft_put_chr(fmt, va_arg(var, int));
	if (fmt.typ == 3)
		cnt = ft_put_str(fmt, va_arg(var, char *));
	if (fmt.typ == 4)
		cnt = ft_put_pnt(fmt, va_arg(var, unsigned long long));
	if (fmt.typ == 5)
		cnt = ft_put_unt(fmt, (unsigned int)va_arg(var, int));
	if (fmt.typ == 6)
		cnt = ft_put_hex(fmt, va_arg(var, unsigned int), 0);
	if (fmt.typ == 7)
		cnt = ft_put_hex(fmt, va_arg(var, unsigned int), 1);
	if (fmt.typ == 8)
		cnt = ft_put_per(fmt);
	return (cnt);
}
