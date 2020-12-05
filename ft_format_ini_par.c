/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ini_par.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:45:35 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:32:55 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format				ft_format_init(void)
{
	t_format			fmt;

	fmt.typ = 0;
	fmt.wid = 0;
	fmt.sta = 0;
	fmt.pre = -1;
	fmt.zer = 0;
	fmt.min = 0;
	return (fmt);
}

t_format				ft_format_parse_star(t_format fmt, va_list var)
{
	fmt.sta = 1;
	fmt.wid = va_arg(var, int);
	if (fmt.wid < 0)
	{
		fmt.min = 1;
		fmt.wid *= -1;
		fmt.zer = 0;
	}
	return (fmt);
}

/*
** ft_format_parse_dot - structure
**	get (string, start index), format, va_list
**	set index as start index + 1
**	if character is * :
**		set precision(fmt.pre) as vaarg(int)
**	if not :
**		set precision(fmt.pre) as 0
**		while character is number :
**			increase precision as character
*/

int						ft_format_parse_dot(const char *str, int stt,
						t_format *fmt, va_list var)
{
	int					idx;

	idx = stt + 1;
	if (str[idx] == '*')
	{
		fmt->pre = va_arg(var, int);
		++idx;
	}
	else
	{
		fmt->pre = 0;
		while (ft_n(str[idx]) != 0)
		{
			fmt->pre = (fmt->pre * 10) + (str[idx] - '0');
			++idx;
		}
	}
	return (idx);
}

t_format				ft_format_parse_digit(char chr, t_format fmt)
{
	if (fmt.sta == 1)
		fmt.wid = 0;
	fmt.wid = (fmt.wid * 10) + (chr - '0');
	return (fmt);
}

/*
** ft_format_parse_structure
**	if character is not for t_format :
**		break
**	if character is a type :
**		put that in fmt, and break
**	if character is 0 and width/minus is 0 :
**		put that in zero(fmt.zer)
**	if character is * :
**		execute fmt_format_parse_star
**	if character is number :
**		if star_flag(fmt.sta) is 1 :
**			set width(fmt.wid) 0
**		increase width(fmt.wid) as the character
**	if character is minus :
**		set minus(fmt.min) 1
**	if character is .
**		execute fmt_format_parse_dot
*/

int						ft_format_parse(const char *s, int i,
						t_format *fmt, va_list var)
{
	while (s[i])
	{
		if (ft_t(s[i]) == 0 && ft_f(s[i]) == 0 && ft_n(s[i]) == 0)
			break ;
		if (s[i] == '0' && fmt->wid == 0 && fmt->min == 0)
			fmt->zer = 1;
		if (s[i] == '*')
			*fmt = ft_format_parse_star(*fmt, var);
		if (s[i] == '.')
			i = ft_format_parse_dot(s, i, fmt, var);
		if (s[i] == '-')
		{
			fmt->min = 1;
			fmt->zer = 0;
		}
		if (ft_n(s[i]) == 1)
			*fmt = ft_format_parse_digit(s[i], *fmt);
		if (ft_t(s[i]) != 0)
		{
			fmt->typ = ft_t(s[i]);
			break ;
		}
		++i;
	}
	return (i);
}
