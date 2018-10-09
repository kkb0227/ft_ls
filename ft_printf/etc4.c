/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:36:00 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 11:44:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			oct_digit(uintmax_t num)
{
	int digit;

	digit = 1;
	while (num / 8)
	{
		num /= 8;
		digit++;
	}
	return (digit);
}

void		print_oct_o(uintmax_t num)
{
	if (num < 8)
		ft_putchar(num + 48);
	else
	{
		print_oct_o(num / 8);
		print_oct_o(num % 8);
	}
}

uintmax_t	length_convert_u(int info[4], va_list ap)
{
	uintmax_t num;

	if (info[3] == 1)
		num = (unsigned char)va_arg(ap, uintmax_t);
	else if (info[3] == 2)
		num = (unsigned short)va_arg(ap, uintmax_t);
	else if (info[3] == 3)
		num = (unsigned long long)va_arg(ap, uintmax_t);
	else if (info[3] == 4)
		num = (unsigned long)va_arg(ap, uintmax_t);
	else if (info[3] == 5)
		num = va_arg(ap, uintmax_t);
	else if (info[3] == 6)
		num = (size_t)va_arg(ap, uintmax_t);
	else
		num = (unsigned int)va_arg(ap, uintmax_t);
	return (num);
}

int			u_digit(uintmax_t num)
{
	int count;

	count = 1;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

void		ft_putonly_unbr(uintmax_t n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putonly_unbr(n / 10);
		ft_putonly_unbr(n % 10);
	}
}
