/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:03:42 by kimkwanho         #+#    #+#             */
/*   Updated: 2020/12/05 14:04:44 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
**typ : types
**		0 : none (not yet)
**		1 : d, i (int)
**		2 : c (char)
**		3 : s (char *)
**		4 : p (pointer)
**		5 : u (unsigned int)
**		6 : x (unsigned hex)
**		7 : X (UNSIGNED HEX)
**		8 : %
**wid : width
**str : * : 0=off, 1=on]
**dot : . : 0=off, 1=on : precision
**zer : 0 : 0=off, 1=on
**min : - : 0=off, 1=on
*/
typedef struct			s_format
{
	int					typ;
	int					wid;
	int					sta;
	int					pre;
	int					zer;
	int					min;
}						t_format;

/*
** ft_format_ini_par.c
*/
t_format				ft_format_init(void);
int						ft_format_parse(const char *s, int i,
						t_format *fmt, va_list var);

/*
** ft_format_check.c
*/
int						ft_t(char chr);
int						ft_f(char chr);
int						ft_n(char chr);

/*
** ft_format_menu.c
*/
int						ft_format_put(t_format fmt, va_list var);

/*
** ft_put_int.c
*/
int						ft_put_int(t_format fmt, int num);

/*
** ft_put_chr.c
*/
int						ft_put_chr(t_format fmt, char chr);

/*
** ft_put_str.c
*/
int						ft_put_str(t_format fmt, char *str);

/*
** ft_put_pnt.c
*/
int						ft_put_pnt(t_format fmt, unsigned long long num);

/*
** ft_put_unt.c
*/
int						ft_put_unt(t_format fmt, unsigned int num);

/*
** ft_put_hex.c
*/
int						ft_put_hex(t_format fmt, unsigned int num, int low);
/*
** ft_put_per.c
*/
int						ft_put_per(t_format fmt);

/*
** ft_put_width.c
*/
int						ft_put_width(int wid, int min, int zer);

/*
** ft_util_0.c
*/
char					*ft_strdup(const char *src);
int						ft_putchar(char chr);
int						ft_putstr(char *str);
int						ft_putstr_prec(char *str, int pre);
char					*ft_tolower(char *str);

/*
** ft_util_1.c
*/
int						ft_numlen(int num);
char					*ft_itoa(int nm1);
char					*ft_utl_base(unsigned long long num, int bas);

/*
** ft_util_2.c
*/
int						ft_strlen(char *str);
char					*ft_itoa_u(unsigned int num);

#endif
