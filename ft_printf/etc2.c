/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:48:26 by kykim             #+#    #+#             */
/*   Updated: 2018/07/24 11:31:07 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		digit(intmax_t num)
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

void	ft_putonlynbr(intmax_t n)
{
	if (n < 0)
	{
		ft_putonlynbr(-n);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putonlynbr(n / 10);
		ft_putonlynbr(n % 10);
	}
}

void	putzero(int info[4], int digit)
{
	int i;

	i = info[2] - digit;
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
	}
}
