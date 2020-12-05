/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:23:40 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:23:44 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_put_width(int wid, int min, int zer)
{
	int					cnt;

	cnt = 0;
	while (wid > min)
	{
		if (zer)
			ft_putchar('0');
		else
			ft_putchar(' ');
		--wid;
		++cnt;
	}
	return (cnt);
}
