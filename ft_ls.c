/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 00:29:54 by syusof            #+#    #+#             */
/*   Updated: 2016/11/10 19:33:51 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"
//# include "push_swap/push_swap.h"


int main(int ac,char **av)
{
	t_lsto			*lstcmd;
	t_lsto			*lst;
	t_lsto			*lst1;
	int				i;
	t_ind			*ind;
	int j;
	t_lsto		*lstmp;
	t_lsto		*lsta;

	lstcmd = NULL;
	lsta = NULL;
	lstmp = NULL;
	ind = NULL;
	ind = (t_ind*)malloc(sizeof(t_ind));
	lst = NULL;
	lst1 = NULL;
	i = 1;
	while(av[i])
	{
		lstmp = ft_create_lsto_char(av[i]);
		lstcmd = lst_addo_down_char(lstcmd,lstmp);
		i++;
	}
	lstmp = NULL;
	i = 1;
	ft_init(ind);
	ft_scan_option(av,ind);
	if (!av[1] || (ac == 2 && ft_strcmp(av[1],"--") == 0))
	{
		lst = ft_getreplist(".");
		ft_printlist(lst);
	}
	else if (ft_p_illegal(ind))
		ft_ls_p1(av, lstcmd, ind);
	return (0);
}
