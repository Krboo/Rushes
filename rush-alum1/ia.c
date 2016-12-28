/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:47:06 by mnicolas          #+#    #+#             */
/*   Updated: 2015/12/21 20:52:31 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_move_last_row(int *tab)
{
	if (tab[0] % 4 == 1)
		return (1);
	else if (tab[0] > 5 && tab[0] % 4 > 1)
		return (tab[0] - (tab[0] - (tab[0] % 4 - 1)));
	else if (tab[0] > 5 && tab[0] % 4 == 0)
		return (3);
	else if (tab[0] > 1 && tab[0] < 5)
		return (tab[0] - 1);
	else
		return (1);
}

int			ft_move(int *tab, int *res, int i)
{
	if (i == 0)
		return (ft_move_last_row(tab));
	if (res[i - 1] == 1)
	{
		if (tab[i] % 4 == 1)
			return (1);
		else if (tab[i] > 5 && tab[i] % 4 > 1)
			return (tab[i] - (tab[i] - (tab[i] % 4 - 1)));
		else if (tab[i] > 5 && tab[i] % 4 == 0)
			return (3);
		if (tab[i] > 1 && tab[i] < 5)
			return (tab[i] - 1);
		else
			return (1);
	}
	if (tab[i] % 4 == 1)
		return (1);
	if (tab[i] % 4 == 0)
		return (1);
	else if (tab[i] > 5 && tab[i] % 4 != 1)
		return (tab[i] % 4);
	if (tab[i] < 4)
		return (tab[i]);
	return (1);
}

int			*ft_ask_ai(int *tab, int move, int i, int max)
{
	ft_print_board(tab, max);
	ft_putstr("--Computer plays his turn : removes ");
	ft_putnbr(move);
	if (move == 1)
		ft_putendl(" match--");
	else
		ft_putendl(" matches--");
	tab[i] -= move;
	return (tab);
}

static int	*ft_get_res(int *tab, int *res, int i, int size)
{
	if (i == size)
		return (res);
	if (i == 0)
	{
		if (tab[i] % 4 == 1)
			res[i] = 2;
		else
			res[i] = 1;
		return (ft_get_res(tab, res, i + 1, size));
	}
	if (res[i - 1] == 1)
	{
		if (tab[i] % 4 == 1)
			res[i] = 2;
		else
			res[i] = 1;
		return (ft_get_res(tab, res, i + 1, size));
	}
	if (tab[i] % 4 == 1 || tab[i] < 4)
		res[i] = 1;
	else
		res[i] = 2;
	return (ft_get_res(tab, res, i + 1, size));
}

int			*ft_res_tab(int *tab, int size)
{
	int		*res;

	res = (int *)malloc(sizeof(int) * size);
	if (!(res))
		return (NULL);
	return (res = ft_get_res(tab, res, 0, size));
}
