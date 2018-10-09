/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:32:47 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 18:31:09 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_without_hash_o_no_p(int info[4], uintmax_t num, int digit, int i)
{
	int buffsize;

	buffsize = info[1];
	if (((info[0] % 1000) / 100) == 1)
	{
		print_oct_o(num);
		while (i++ < info[1] - digit)
			ft_putchar(' ');
	}
	else
	{
		if ((info[0] % 10000) / 1000 == 0)
		{
			while (i++ < info[1] - digit)
				ft_putchar(' ');
		}
		else
		{
			while (i++ < info[1] - digit)
				ft_putchar('0');
		}
		print_oct_o(num);
	}
	return (buffsize);
}

int	width_w_hash_largew_o_no_p(int info[4], uintmax_t num, int digit, int i)
{
	if (((info[0] % 1000) / 100) == 1)
	{
		ft_putstr("0");
		print_oct_o(num);
		while (i++ < info[1] - digit - 1)
			ft_putchar(' ');
	}
	else
	{
		while (i++ < info[1] - digit - 1)
			ft_putchar(' ');
		ft_putchar('0');
		print_oct_o(num);
	}
	return (info[1]);
}

int	same_oct_width_no_p(int info[4], uintmax_t num, int digit)
{
	int buffsize;
	int i;

	i = 0;
	if ((info[0] / 10000) == 0)
		buffsize = width_without_hash_o_no_p(info, num, digit, i);
	else
	{
		if (info[1] - digit < 1)
		{
			buffsize = info[1];
			ft_putstr("0");
			print_oct_o(num);
		}
		else
			buffsize = width_w_hash_largew_o_no_p(info, num, digit, i);
	}
	return (buffsize);
}

int	no_p_octal(int info[4])
{
	int i;

	i = 0;
	while (i++ < info[1])
		ft_putchar(' ');
	return (info[1]);
}
