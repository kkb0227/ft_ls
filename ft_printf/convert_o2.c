/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:55:24 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 18:21:27 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_without_hash_o(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_oct_o(num);
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
		print_oct_o(num);
	}
	return (buffsize);
}

void	width_with_hash_largew_o_l(int info[4], uintmax_t num, int digit, int i)
{
	if (info[2] < digit)
		ft_putstr("0");
	while (i++ < info[2] - digit)
		ft_putchar('0');
	print_oct_o(num);
	i = 0;
	if (info[2] < digit)
		i = 1;
	while (i++ < info[1] - bigger(info[2], digit))
		ft_putchar(' ');
}

int		width_with_hash_largew_o(int info[4], uintmax_t num, int digit, int i)
{
	if (((info[0] % 1000) / 100) == 1)
		width_with_hash_largew_o_l(info, num, digit, i);
	else
	{
		if (info[1] - bigger(info[2], digit) > 1)
		{
			while (i++ < info[1] - bigger(info[2], digit) - 1)
				ft_putchar(' ');
		}
		if (info[2] < digit)
			ft_putstr("0");
		else
			ft_putchar(' ');
		i = 0;
		while (i++ < info[2] - digit)
			ft_putchar('0');
		print_oct_o(num);
	}
	return (info[1]);
}
