/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:50:30 by kykim             #+#    #+#             */
/*   Updated: 2018/07/31 19:26:37 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_percent(int info[4])
{
	int buffsize;
	int i;

	i = 0;
	buffsize = 1;
	if (info[1] > 1)
		buffsize = info[1];
	if ((info[0] % 10000) / 1000 == 1)
	{
		if ((info[0] % 1000) / 100 == 1)
		{
			while (i++ < buffsize - 1)
				ft_putchar('0');
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			while (i++ < buffsize - 1)
				ft_putchar('0');
		}
	}
	convert_percent2(info);
	return (buffsize);
}

void	convert_percent2(int info[4])
{
	int buffsize;
	int i;

	i = 0;
	buffsize = 1;
	if (info[1] > 1)
		buffsize = info[1];
	if ((info[0] % 1000) / 100 != 1)
	{
		while (i++ < buffsize - 1)
			ft_putchar(' ');
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		while (i++ < buffsize - 1)
			ft_putchar(' ');
	}
}
