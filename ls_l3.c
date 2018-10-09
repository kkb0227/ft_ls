/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:44:19 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 14:45:50 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*getusername(uid_t userid)
{
	struct passwd *user;

	user = getpwuid(userid);
	return (user->pw_name);
}

char	*getgroupname(gid_t groupid)
{
	struct group *user;

	user = getgrgid(groupid);
	return (user->gr_name);
}

char	*getlastmodifiedtime(time_t *modifiedtime)
{
	return (ctime(modifiedtime));
}
