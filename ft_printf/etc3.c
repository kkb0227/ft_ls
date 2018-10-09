/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:46:36 by kykim             #+#    #+#             */
/*   Updated: 2018/07/24 23:35:30 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			hex_digit(uintmax_t num)
{
	int digit;

	digit = 1;
	while (num / 16)
	{
		num /= 16;
		digit++;
	}
	return (digit);
}

void		print_hex_x(uintmax_t num)
{
	if (num < 16)
	{
		if (num == 10)
			write(1, "a", 1);
		else if (num == 11)
			write(1, "b", 1);
		else if (num == 12)
			write(1, "c", 1);
		else if (num == 13)
			write(1, "d", 1);
		else if (num == 14)
			write(1, "e", 1);
		else if (num == 15)
			write(1, "f", 1);
		else
			ft_putchar(num + 48);
	}
	else
	{
		print_hex_x(num / 16);
		print_hex_x(num % 16);
	}
}

void		print_hex_largex(uintmax_t num)
{
	if (num < 16)
	{
		if (num == 10)
			write(1, "A", 1);
		else if (num == 11)
			write(1, "B", 1);
		else if (num == 12)
			write(1, "C", 1);
		else if (num == 13)
			write(1, "D", 1);
		else if (num == 14)
			write(1, "E", 1);
		else if (num == 15)
			write(1, "F", 1);
		else
			ft_putchar(num + 48);
	}
	else
	{
		print_hex_largex(num / 16);
		print_hex_largex(num % 16);
	}
}

uintmax_t	length_convert_x(int info[4], va_list ap)
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

uintmax_t	length_convert_o(int info[4], va_list ap)
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
