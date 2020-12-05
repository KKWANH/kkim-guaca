/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:05:12 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:05:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_put_chr(t_format fmt, char chr)
{
	int					cnt;

	cnt = 0;
	if (fmt.min == 1)
		ft_putchar(chr);
	cnt = ft_put_width(fmt.wid, 1, 0);
	if (fmt.min == 0)
		ft_putchar(chr);
	return (cnt + 1);
}
