/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:01:05 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 13:58:38 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		double_check(char *option, char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (option[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_option(char *option, char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (option[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	add_option(char *option, char c)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (option[i] == 0)
		{
			option[i] = c;
			break ;
		}
		i++;
	}
}

void	check_valid(char *option, int i, int j, char **argv)
{
	if (check_option(option, argv[i][j]))
		add_option(option, argv[i][j]);
}

int		option_parsing(char *option, char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
		if (argv[i][j] == '\0')
			return (i);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == 'a' || argv[i][j] == 'r' ||
			argv[i][j] == 't' || argv[i][j] == 'R' || argv[i][j] == 'l')
				check_valid(option, i, j, argv);
			else
			{
				ft_printf("Error : Invalid option! (put only a, r, t, l, R)\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (i);
}
