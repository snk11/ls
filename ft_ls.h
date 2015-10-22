/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:30:22 by syusof            #+#    #+#             */
/*   Updated: 2015/10/22 20:05:58 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H



# include "libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>


typedef struct		s_lst
{
	void			*content;
	struct s_lst	*next;
}					t_lst;


typedef struct		s_stat
{
	char			*id;
	struct stat		stat1;
}					t_stat;




# endif
