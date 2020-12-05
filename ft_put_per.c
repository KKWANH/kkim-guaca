/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_per.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:16:58 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:16:58 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_put_per(t_format fmt)
{
	int					cnt;

	cnt = 0;
	if (fmt.min == 1)
		cnt += ft_putstr_prec("%", 1);
	cnt += ft_put_width(fmt.wid, 1, fmt.zer);
	if (fmt.min == 0)
		cnt += ft_putstr_prec("%", 1);
	return (cnt);
}
