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