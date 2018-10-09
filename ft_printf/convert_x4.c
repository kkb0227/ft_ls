/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:14:47 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 20:18:02 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_without_hash_0(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		print_hex_x(num);
		while (i++ < info[1] - digit)
			ft_putchar(' ');
	}
	else
	{
		while (i++ < info[1] - digit)
			ft_putchar('0');
		print_hex_x(num);
	}
	return (buffsize);
}

int	width_with_hash_largewidth_0(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		ft_putstr("0x");
		print_hex_x(num);
		while (i++ < info[1] - digit - 2)
			ft_putchar(' ');
	}
	else
	{
		ft_putstr("0x");
		while (i++ < info[1] - digit - 2)
			ft_putchar('0');
		print_hex_x(num);
	}
	return (buffsize);
}

int	same_hex_width_0(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	if ((info[0] / 10000) == 0)
		buffsize = width_without_hash_0(info, num, digit, i);
	else
	{
		if (info[1] - digit < 2)
		{
			buffsize = info[1] + (info[1] - digit);
			ft_putstr("0x");
			print_hex_x(num);
		}
		else
			buffsize = width_with_hash_largewidth_0(info, num, digit, i);
	}
	return (buffsize);
}
