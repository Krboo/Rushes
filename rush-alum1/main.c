/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:46:36 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/21 20:01:59 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	ft_error(void)
{
	ft_putendl_fd("ERROR", 2);
	return (1);
}

int			main(int argc, char **argv)
{
	int		*matches;
	int		i;

	i = 0;
	matches = NULL;
	if (argc > 2)
		return (ft_error());
	if (argc == 2)
	{
		if ((matches = ft_read_file(argv[1])) == NULL)
			return (ft_error());
		while (matches[i])
		{
			ft_putendl(ft_itoa(matches[i]));
			i++;
		}
	}
	if (argc == 1)
		if ((matches = ft_read_std()) == NULL)
			return (ft_error());
	ft_putendl("------The game begins!-----");
	ft_game(matches);
	ft_memdel((void **)&matches);
	return (0);
}
