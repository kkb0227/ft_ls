/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:18:55 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 18:09:01 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	length_convert_i(int info[4], va_list ap)
{
	intmax_t num;

	if (info[3] == 1)
		num = (signed char)va_arg(ap, intmax_t);
	else if (info[3] == 2)
		num = (short)va_arg(ap, intmax_t);
	else if (info[3] == 3)
		num = (long long)va_arg(ap, intmax_t);
	else if (info[3] == 4)
		num = (long)va_arg(ap, intmax_t);
	else if (info[3] == 5)
		num = va_arg(ap, intmax_t);
	else if (info[3] == 6)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (int)va_arg(ap, intmax_t);
	return (num);
}
