/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:04:04 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:44:49 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	getpermission(char permission[11], mode_t mode)
{
	if (S_ISBLK(mode))
		permission[0] = 'b';
	else if (S_ISCHR(mode))
		permission[0] = 'c';
	else if (S_ISDIR(mode))
		permission[0] = 'd';
	else if (S_ISREG(mode))
		permission[0] = '-';
	else if (S_ISFIFO(mode))
		permission[0] = 'p';
	else if (S_ISLNK(mode))
		permission[0] = 'l';
	else if (S_ISSOCK(mode))
		permission[0] = 's';
}

int		year(char *timeinfo)
{
	int i;

	i = 0;
	while (timeinfo[i] != '\0')
		i++;
	i -= 2;
	if (timeinfo[i] != '8')
	{
		timeinfo[11] = '2';
		timeinfo[12] = '0';
		timeinfo[13] = '1';
		timeinfo[14] = timeinfo[i];
		timeinfo[15] = '\0';
		return (1);
	}
	return (0);
}

void	longformat(char *path, int info[3])
{
	char		permission[11];
	char		timeinfo[26];
	struct stat	filestat;

	permission[10] = '\0';
	lstat(path, &filestat);
	getpermission(permission, filestat.st_mode);
	ft_printf("%c", permission[0]);
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf("  %*d", info[0], (int)filestat.st_nlink);
	ft_printf(" %s ", getusername(filestat.st_uid));
	ft_printf(" %s ", getgroupname(filestat.st_gid));
	ft_printf(" %*lld ", info[1], filestat.st_size);
	ft_strcpy(timeinfo, getlastmodifiedtime(&(filestat.st_mtime)));
	year(timeinfo);
	timeinfo[16] = '\0';
	ft_printf("%s", timeinfo + 4);
}
