/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:24:07 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:24:22 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int						ft_putchar(char chr)
{
	write(1, &chr, 1);
	return (1);
}

int						ft_putstr(char *str)
{
	int					idx;

	idx = 0;
	while (str[idx])
		idx += ft_putchar(str[idx]);
	return (idx);
}

int						ft_putstr_prec(char *str, int pre)
{
	int					idx;

	idx = 0;
	while (str[idx] && idx < pre)
		ft_putchar(str[idx++]);
	return (idx);
}

char					*ft_tolower(char *str)
{
	int					idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] += 32;
		idx++;
	}
	return (str);
}
