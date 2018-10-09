/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:16:35 by kykim             #+#    #+#             */
/*   Updated: 2018/07/24 23:27:56 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	same_hex_digit_l(int info[4], uintmax_t num, int digit)
{
	int buffsize;

	buffsize = digit;
	if ((info[0] / 10000) == 1)
	{
		ft_putstr("0X");
		buffsize += 2;
	}
	print_hex_largex(num);
	return (buffsize);
}

int	same_hex_precision_l(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	buffsize = info[2];
	if ((info[0] / 10000) == 1)
	{
		ft_putstr("0X");
		buffsize += 2;
	}
	while (i < info[2] - digit)
	{
		write(1, "0", 1);
		i++;
	}
	print_hex_largex(num);
	return (buffsize);
}

int	width_without_hash_l(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_largex(num);
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
		print_hex_largex(num);
	}
	return (buffsize);
}

int	width_with_hash_largewidth_l(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		ft_putstr("0X");
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_largex(num);
		i = 0;
		while (i++ < info[1] - bigger(info[2], digit) - 2)
			ft_putchar(' ');
	}
	else
	{
		while (i++ < info[1] - bigger(info[2], digit) - 2)
			ft_putchar(' ');
		ft_putstr("0X");
		i = 0;
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_hex_largex(num);
	}
	return (buffsize);
}

int	same_hex_width_l(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	if ((info[0] / 10000) == 0)
		buffsize = width_without_hash_l(info, num, digit, i);
	else
	{
		if (info[1] - bigger(info[2], digit) < 2)
		{
			buffsize = info[1] + (info[1] - bigger(info[2], digit));
			ft_putstr("0X");
			while (i++ < info[2] - digit)
				ft_putchar('0');
			print_hex_largex(num);
		}
		else
			buffsize = width_with_hash_largewidth_l(info, num, digit, i);
	}
	return (buffsize);
}
