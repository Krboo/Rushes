/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:44:56 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/21 20:39:39 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "libft.h"
# include <fcntl.h>

int		*ft_read_file(char *file);
int		*ft_read_std();
void	ft_print_board(int *matches, int max);
int		ft_game(int *matches);
int		ft_ask_player(int *matches, int len, int *res, int max);
int		*ft_ask_ai(int *tab, int move, int i, int max);
int		ft_move(int *tab, int *res, int i);
int		*ft_res_tab(int *tab, int size);
int		ft_get_max(int *matches);

#endif
