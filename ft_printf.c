/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:02:01 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:32:03 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**ft_printf_sub - structure
**	if character is not % :
**		print that character
**	if character is % and Next character is available :
**		init t_format (all 0)
**		[*]parse (increase idx)
**		if character isnt a type (d, i, c, p, %, ...) :
**			print that character
**		if not :
**			put as parsed data
*/

int						ft_printf_sub(const char *str, va_list var)
{
	int					cnt;
	int					idx;
	t_format			fmt;

	cnt = 0;
	idx = 0;
	while (str[idx])
	{
		fmt = ft_format_init();
		if (str[idx] != '%')
			cnt += ft_putchar(str[idx]);
		else if (str[idx] == '%' && str[idx + 1])
		{
			idx = ft_format_parse(str, ++idx, &fmt, var);
			if (ft_t(str[idx]) == 0)
				cnt += ft_putchar(str[idx]);
			else
				cnt += ft_format_put(fmt, var);
		}
		++idx;
	}
	return (cnt);
}

int						ft_printf(const char *fmt, ...)
{
	va_list				var;
	const char			*str;
	int					cnt;

	cnt = 0;
	str = ft_strdup(fmt);
	if (!str)
		return (0);
	va_start(var, fmt);
	cnt += ft_printf_sub(str, var);
	va_end(var);
	free((char *)str);
	return (cnt);
}
