/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:05:45 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 20:00:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	same_hex_digit(int info[4], uintmax_t num, int digit)
{
	int buffsize;

	buffsize = digit;
	if ((info[0] / 10000) == 1 && num != 0)
	{
		ft_putstr("0x");
		buffsize += 2;
	}
	print_hex_x(num);
	return (buffsize);
}

int	same_hex_precision(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	buffsize = info[2];
	if ((info[0] / 10000) == 1)
	{
		ft_putstr("0x");
		buffsize += 2;
	}
	while (i < info[2] - digit)
	{
		write(1, "0", 1);
		i++;
	}
	print_hex_x(num);
	return (buffsize);
}

int	width_without_hash(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_x(num);
		i = 0;
		while (i++ < info[1] - bigger(info[2], digit))
			ft_putchar(' ');
	}
	else
	{
		while (i++ < info[1] - bigger(info[2], digit))
			ft_putchar(' ');
		i = 0;
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_x(num);
	}
	return (buffsize);
}

int	width_with_hash_largewidth(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		ft_putstr("0x");
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_x(num);
		i = 0;
		while (i++ < info[1] - bigger(info[2], digit) - 2)
			ft_putchar(' ');
	}
	else
	{
		while (i++ < info[1] - bigger(info[2], digit) - 2)
			ft_putchar(' ');
		ft_putstr("0x");
		i = 0;
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_x(num);
	}
	return (buffsize);
}

int	same_hex_width(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	if ((info[0] / 10000) == 0)
		buffsize = width_without_hash(info, num, digit, i);
	else
	{
		if (info[1] - bigger(info[2], digit) < 2)
		{
			buffsize = info[1] + (info[1] - bigger(info[2], digit));
			ft_putstr("0x");
			while (i++ < info[2] - digit)
				ft_putchar('0');
			print_hex_x(num);
		}
		else
			buffsize = width_with_hash_largewidth(info, num, digit, i);
	}
	return (buffsize);
}
