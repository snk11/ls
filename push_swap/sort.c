/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <syusof@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 21:14:19 by syusof            #+#    #+#             */
/*   Updated: 2015/10/08 14:28:30 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


int		ft_comptelem(t_lst *lsta)
{
	int		nb;

	nb = 0;
	if (lsta)
	{
		nb = 1;
		while (lsta)
		{
			nb++;
			lsta = lsta->next;
		}
	}
	return (nb - 1);
}

#include <stdio.h>
int		get_index(t_lst **lstmp, int nbelemc)
{
	int index;

	index = 0;
	while (((t_numb*)(*lstmp)->content)->val < ((t_numb*)((*lstmp)->next)->content)->val && (index < nbelemc - 1))
	{
		index++;
		if (((*lstmp)->next)->next)
			(*lstmp) = (*lstmp)->next;
		printf("lstmp:%d\n",((t_numb*)(*lstmp)->content)->val);
	}
	return index;
}



void		ft_sort(t_lst **lsta)
{
	t_lst	*lstmp;
	t_lst	*lstmp2;
	int		index;
	int		index2;
	int		nbelem;
	int		nbelemc;
	t_lst	*lstb;


	index = 0;
	index2 = 0;
	lstmp = NULL;
	lstmp2 = NULL;


	int bug = 0;
	int		a;
	int		b;

	int n;

	lstb = NULL;

	nbelem = ft_comptelem(*lsta);

	if ((*lsta)->next)
	{
		if (((t_numb*)(*lsta)->content)->val > ((t_numb*)((*lsta)->next)->content)->val)
			swap(lsta);
	}

	while (index < nbelem - 1)
	{
		index = 0;
		bug++;
		lstmp = *lsta;
		nbelemc = ft_comptelem(*lsta);
		printf("------------------\n");
		lstmp = *lsta;
		if  (lstmp->next)
		{
			printf("ff\n");
			index = get_index(&lstmp,nbelemc);
			printf("index = %d\n", index);
			if (lstb)
				printf("lstb = %d\n",((t_numb*)(lstmp)->content)->val);
		}
		if (((t_numb*)lstmp->content)->val > ((t_numb*)(lstmp->next)->content)->val || index2 > 0)
		{
			printf("A\n");
			if (lstb == NULL)
			{
				while (index > 0)
				{
					push(&lstb, lsta);
					index--;
					index2++;
					printf("pb\n");
				}
				printf("out\n");
			}
			else
			{
				while ((index2) > 0)
				{
					push(lsta, &lstb);
					index2--;
					printf("index2 = %d\n",index2);
					printf("pa\n");
				}
				lstmp = *lsta;
				nbelemc = ft_comptelem(*lsta);
			}
			if ((*lsta)->next)
			{
				if (((t_numb*)(*lsta)->content)->val > ((t_numb*)((*lsta)->next)->content)->val)
					swap(lsta);
			}
		}
		lstmp = *lsta;
		if ((lstmp)->next)
		{
			printf("lsta: %d\n",((t_numb*)(lstmp)->content)->val);
			while ((lstmp->next)->next)
			{
				printf("lsta: %d\n",((t_numb*)(lstmp->next)->content)->val);
				lstmp = lstmp->next;
			}
			printf("lsta: %d\n",((t_numb*)(lstmp->next)->content)->val);
		}

	}
}


