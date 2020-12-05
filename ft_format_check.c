#include "ft_printf.h"

int						ft_is_type(char chr)
{
	if (chr == 'd' || chr == 'i')
		return (1);
	if (chr == 'c')
		return (2);
	if (chr == 's')
		return (3);
	if (chr == 'p')
		return (4);
	if (chr == 'u')
		return (5);
	if (chr == 'x')
		return (6);
	if (chr == 'X')
		return (7);
	if (chr == '%')
		return (8);
	return (0);
}

int						ft_is_flag(char chr)
{
	if (chr == '.' || chr == '*' || chr == '0' ||
		chr == '-' || chr == ' ')
		return (1);
	return (0);
}

int						ft_is_numb(char chr)
{
	if (chr >= '0' && chr <= '9')
		return (1);
	return (0);
}