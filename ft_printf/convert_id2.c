/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_id2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:59:17 by kykim             #+#    #+#             */
/*   Updated: 2018/08/01 21:36:13 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printrealnum(intmax_t num)
{
	if (num < 0)
		ft_putonly_unbr(-num);
	else
		ft_putonlynbr(num);
}

int		no_p_digit(intmax_t num, int info[4], int buffsize)
{
	if (num < 0)
	{
		ft_putchar('-');
		buffsize += 1;
	}
	if ((info[0] % 100) / 10 == 1 && num >= 0)
	{
		ft_putchar('+');
		buffsize++;
	}
	else if ((info[0] % 10) == 1 && num >= 0)
	{
		ft_putchar(' ');
		buffsize++;
	}
	printrealnum(num);
	return (buffsize);
}

int		no_p_width(intmax_t num, int info[4], int buffsize, int digitvalue)
{
	int i;

	i = 0;
	if (num < 0 || ((info[0] % 100) / 10 == 1 && num >= 0) ||
	((info[0] % 10) == 1 && num >= 0))
	{
		if (num < 0)
			ft_putchar('-');
		else if (((info[0] % 100) / 10 == 1 && num >= 0))
			ft_putchar('+');
		else if (((info[0] % 10) == 1 && num >= 0))
			ft_putchar(' ');
		i = 1;
	}
	printrealnum(num);
	if (info[1] - digitvalue > 0)
	{
		while (i < info[1] - digitvalue)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (buffsize);
}

int		no_p_width2(intmax_t num, int info[4], int digitvalue)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((info[0] % 100) / 10 == 1 && num >= 0)
	{
		ft_putchar('+');
		i++;
	}
	else if ((info[0] % 10) == 1 && num >= 0)
	{
		ft_putchar(' ');
		i++;
	}
	if (num < 0)
		i++;
	if (num < 0)
		ft_putchar('-');
	while (j++ < info[1] - digitvalue - i)
		ft_putchar('0');
	printrealnum(num);
	return (info[1]);
}

int		no_p_width3(intmax_t num, int info[4], int digitvalue)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (num < 0 || ((info[0] % 100) / 10 == 1 && num >= 0) ||
	((info[0] % 10) == 1 && num >= 0))
	{
		if (num < 0)
			i = 1;
		else if (((info[0] % 100) / 10 == 1 && num >= 0))
			ft_putchar('+');
		else if (((info[0] % 10) == 1 && num >= 0))
			ft_putchar(' ');
		i = 1;
	}
	while (j < info[1] - digitvalue - i)
	{
		ft_putchar(' ');
		j++;
	}
	if (num < 0)
		ft_putchar('-');
	printrealnum(num);
	return (info[1]);
}
