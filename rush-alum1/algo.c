/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:44:45 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/21 21:05:07 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
#include "libft.h"

static void	ft_put_choice(int *matches, int len)
{
	if (matches[len] == 1)
	{
		ft_putstr("Only one match left on the last row. You can only ");
		ft_putendl("ask to remove 1 match");
	}
	else if (matches[len] == 2)
	{
		ft_putstr("2 matches left on the last row. How many matches");
		ft_putendl(" do you want to remove? (1 or 2)");
	}
	else if (matches[len] >= 3)
	{
		ft_putnbr(matches[len]);
		ft_putstr(" matches left on the last row. How many matches ");
		ft_putendl("do you want to remove? (1 to 3)");
	}
}

static int	ft_valid_move(int *matches, int data, int *res, int max)
{
	int		i;

	i = 0;
	while (matches[i + 1])
		i++;
	matches[i] -= data;
	if (matches[0] == 0)
		return (0);
	if (matches[i] == 0)
		i--;
	matches = ft_ask_ai(matches, ft_move(matches, res, i), i, max);
	return (ft_ask_player(matches, i, res, max));
}

int			ft_ask_player(int *matches, int len, int *res, int max)
{
	char	*line;
	int		data;

	line = NULL;
	if (matches[0] == 0)
		return (1);
	if (matches[len] == 0)
		len--;
	ft_print_board(matches, max);
	ft_put_choice(matches, len);
	while (!(get_next_line(0, &line) == 0))
	{
		data = ft_atoi(line);
		if (((data < 1 || data > 3) || (data > matches[len])))
		{
			ft_putendl("invalid move / can't be played. Try again");
			return (ft_ask_player(matches, len, res, max));
		}
		else if (ft_strlen(line) == 1)
		{
			return (ft_valid_move(matches, data, res, max));
		}
	}
	return (ft_ask_player(matches, len, res, max));
}

int			ft_game(int *matches)
{
	int		len;
	int		*res;
	int		max;

	max = ft_get_max(matches);
	len = 0;
	while (matches[len])
		len++;
	res = ft_res_tab(matches, len);
	if (ft_ask_player(matches, len, res, max) == 1)
		ft_putendl("------You  Win!------");
	else
		ft_putendl("------Computer Wins------");
	ft_memdel((void **)&res);
	return (0);
}
