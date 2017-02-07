/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_permission2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:41:42 by syusof            #+#    #+#             */
/*   Updated: 2017/02/07 20:44:28 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_permission_p5(struct stat sb)
{
	if (sb.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
		ft_putchar('t');
	else if (sb.st_mode & S_IXOTH)
		ft_putchar('x');
	else if (sb.st_mode & S_ISVTX)
		ft_putchar('T');
	else
		ft_putchar('-');
}

void	ft_print_permission_p6(ssize_t xattr, acl_t acl)
{
	if (xattr > 0)
	{
		ft_putchar('@');
		ft_putchar(' ');
	}
	else if (acl != NULL)
	{
		ft_putchar('+');
		ft_putchar(' ');
	}
	else
		ft_putstr("  ");
}
