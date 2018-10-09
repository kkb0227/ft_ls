/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:54:38 by kykim             #+#    #+#             */
/*   Updated: 2018/08/30 15:32:50 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

typedef struct	s_dirent
{
	char			d_name[255 + 1];
	struct s_dirent *next;
}				t_dirent;

int				double_check(char *option, char c);
int				check_option(char *option, char c);
void			add_option(char *option, char c);
int				option_parsing(char *option, char **argv, int argc);
void			check_valid(char *option, int i, int j, char **argv);

void			argument_sort(t_dirent *first, t_dirent *second);
void			add_argument_node(t_dirent *target, char *name);
t_dirent		*make_arguments_list(int argc, char **argv,
t_dirent *first, int i);
t_dirent		*arguments(int argc, char **argv, int i);

t_dirent		*reverse_order_arg(t_dirent *first);
int				arg_time_cmp(t_dirent *x, t_dirent *y);
void			sort_in_time_arg(t_dirent *first, t_dirent *second);

void			delete_arg(t_dirent *before);
t_dirent		*arg_chck(t_dirent *first);
void			sort_arg(t_dirent *first, char *option);

t_dirent		*ft_ls_without_large_r(char *dir, char *option);
void			printing(t_dirent *tmp, char *option, char *dir, int info[3]);

char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(char *s1, char *s2);
void			init_to_null(char *option);
int				is_directory(char *path);

int				is_file(char *path);
int				is_slink(char *path);
void			print_arg(t_dirent *first);
void			print_file(t_dirent *first);

int				get_digit(int x);
char			*make_path(char *path, char *name);
void			free_nodes(t_dirent *first);

void			ft_ls_large_r(char *dir, char *option, int argc, int i);

void			getpermission(char permission[11], mode_t mode);
void			longformat(char *path, int info[3]);
int				year(char *timeinfo);

int				without_r_hardlink_max(char *name, char *path, int max);
int				without_r_size_max(char *name, char *path, int max);
int				total(char *name, char *path, int total_block);
void			print_name_longformat(char *name, char *path, int info[3]);

char			*getusername(uid_t userid);
char			*getgroupname(gid_t groupid);
char			*getlastmodifiedtime(time_t *modifiedtime);

void			add_newnode(t_dirent *target, struct dirent *temp);
t_dirent		*make_list(char *dir);
void			sorting(t_dirent *start, t_dirent *second);
int				time_cmp(t_dirent *x, t_dirent *y, char *path);
void			sort_in_time(t_dirent *first, t_dirent *second, char *path);

t_dirent		*reverse_order(t_dirent *first);
void			print_name(t_dirent *start, char *option);
int				initial_print(t_dirent *first, char *option);
int				option_a_initial_print(t_dirent *tmp, int i);

void			total_initial_print(t_dirent *first,
char *option, int argc, int i);
void			print_new_and_dirname(int last, int argc, t_dirent *tmp, int i);
int				print_dir_l(char *option, t_dirent *tmp, int last);
void			print_directory(t_dirent *first, char *option, int argc, int i);

void			put_info(int info[3], t_dirent *tmp, char *path);
void			get_info(int info[3], t_dirent *first,
char *path, char *option);
int				initial_print_with_l(t_dirent *first, char *option);
void			get_info2(int info[3], t_dirent *first,
char *path, char *option);

int				option_manage(int ac, char **av, char *option);
void			no_argument(char *option, int argc, char **argv, int i);
t_dirent		*before_ls(t_dirent *first, int argc, char **argv, int i);
t_dirent		*ls_main(t_dirent *tmp, int i, int argc, char *option);

#endif
