/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 22:24:43 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/21 20:20:04 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	*ft_realloc_matches(int *matches, int new, int i)
{
	int		*tmp;
	int		j;

	j = 0;
	tmp = (int *)malloc(sizeof(int) * i + 1);
	if (!tmp)
		return (NULL);
	if (i == 0)
	{
		tmp[i] = new;
		return (tmp);
	}
	while (j < i)
	{
		tmp[j] = matches[j];
		j++;
	}
	tmp[j] = new;
	return (tmp);
}

static int	ft_get_match(char *line)
{
	size_t	i;
	int		res;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (ft_isdigit(line[i]) != 1)
			return (0);
		i++;
	}
	res = ft_atoi(line);
	return ((res > 0 && res <= 10000) ? res : 0);
}

int			*ft_read_file(char *file)
{
	int		*matches;
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	matches = NULL;
	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (ft_get_match(line))
			matches = ft_realloc_matches(matches, ft_get_match(line), i);
		else
			return (NULL);
		i++;
	}
	if (i == 0)
		return (NULL);
	matches[i] = 0;
	return (matches);
}

int			*ft_read_std(void)
{
	int		*matches;
	char	*line;
	int		i;

	line = NULL;
	matches = NULL;
	i = -1;
	ft_putstr("Welcome to Alum1 ! Enter number of matches (1 to 10000) per");
	ft_putendl(" row (Enter for each row). Press Enter when you are finished");
	while (!(get_next_line(0, &line) == 0) && i++ != -42)
	{
		if (ft_strlen(line) == 0)
		{
			if (i > 0)
				matches[i] = 0;
			return (matches);
		}
		if (ft_get_match(line))
			matches = ft_realloc_matches(matches, ft_get_match(line), i);
		else
			return (NULL);
	}
	ft_memdel((void **)&line);
	matches[i] = 0;
	return (matches);
}
