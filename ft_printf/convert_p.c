/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:52:36 by kykim             #+#    #+#             */
/*   Updated: 2018/08/01 12:42:54 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_p_width(int info[4], uintmax_t ptr, int digit)
{
	int i;

	i = 0;
	if ((info[0] % 1000) / 100 != 1)
	{
		while (i++ < info[1] - digit)
			ft_putchar(' ');
		print_hex_x(ptr);
	}
	else
	{
		print_hex_x(ptr);
		while (i++ < info[1] - digit)
			ft_putchar(' ');
	}
}

int		convert_p(int info[4], va_list ap)
{
	uintmax_t	ptr;
	int			digit;
	int			buffsize;
	int			i;

	i = 0;
	ptr = (uintmax_t)va_arg(ap, void *);
	digit = hex_digit(ptr);
	buffsize = bigger(info[1], digit);
	ft_putstr("0x");
	if (buffsize == info[1])
		convert_p_width(info, ptr, digit);
	else
		print_hex_x(ptr);
	return (buffsize + 2);
}
