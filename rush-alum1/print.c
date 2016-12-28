/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 18:05:04 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/21 20:57:12 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			ft_get_max(int *matches)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (matches[i] != 0)
	{
		if (matches[i] > max)
			max = matches[i];
		i++;
	}
	return (max);
}

static void	ft_print_spaces_odd(int row, int max)
{
	int		cpt;

	cpt = 0;
	if (row < max)
	{
		if (row % 2 == 1)
		{
			while (cpt < (max / 2 - row / 2))
			{
				ft_putstr("  ");
				cpt++;
			}
		}
		else
		{
			while (cpt < (max / 2 - row / 2))
			{
				ft_putstr("  ");
				cpt++;
			}
			ft_putstr(" ");
		}
	}
}

static void	ft_print_spaces_peer(int row, int max)
{
	int		cpt;

	cpt = 0;
	if (row % 2 == 1 && row < max)
	{
		ft_putstr(" ");
		while (cpt++ < ((max / 2 - row / 2) - 1))
			ft_putstr("  ");
	}
	else if (row < max)
	{
		ft_putstr(" ");
		while (cpt < (max / 2 - row / 2) && row < max - 2)
		{
			ft_putstr(" ");
			cpt++;
		}
		if (row == 2)
			ft_putstr("  ");
		if (row == 4)
			ft_putstr(" ");
		ft_putstr(" ");
	}
}

static void	ft_print_matches(int row)
{
	int		i;

	i = 0;
	while (row > 1)
	{
		ft_putstr("| ");
		row--;
	}
	ft_putstr("|\n");
	i++;
}

void		ft_print_board(int *matches, int max)
{
	int			i;

	i = 0;
	ft_putchar('\n');
	while (matches[i] != 0)
	{
		if (max % 2 == 1)
			ft_print_spaces_odd(matches[i], max);
		else
			ft_print_spaces_peer(matches[i], max);
		ft_print_matches(matches[i]);
		i++;
	}
}
