/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:39:33 by mnicolas          #+#    #+#             */
/*   Updated: 2015/12/20 13:56:35 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_check_endofline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		++i;
	}
	return (0);
}

static int		ft_read_fd(int fd, char *buffer)
{
	int		ret;

	ret = read(fd, buffer, BUFF_SIZE);
	if (ret != -1)
		buffer[ret] = '\0';
	return (ret);
}

static char		*ft_strfreejoin(char *s1, char *s2, int lib)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (s1 && (lib == 3 || lib == 2))
	{
		free(s1);
		s1 = NULL;
	}
	if (s2 && (lib == 3 || lib == 1))
	{
		free(s2);
		s2 = NULL;
	}
	return (temp);
}

static t_fd		*ft_get_fd(t_fd *list_fd, int fd)
{
	t_fd	*l_temp;

	l_temp = list_fd;
	if (l_temp)
	{
		while (l_temp->next)
		{
			if (l_temp->fd == fd)
				return (l_temp);
			l_temp = l_temp->next;
		}
		if (l_temp->fd == fd)
			return (l_temp);
		if (!(l_temp->next = (t_fd *)malloc(sizeof(t_fd))))
			return (NULL);
		l_temp = l_temp->next;
	}
	else
	if (!(l_temp = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	l_temp->fd = fd;
	l_temp->text = ft_strdup("");
	l_temp->next = NULL;
	l_temp->begin_list = (!list_fd) ? l_temp : list_fd;
	return (l_temp);
}

int				get_next_line(int const fd, char **dest)
{
	static t_fd		*current_fd = NULL;
	char			buffer[BUFF_SIZE + 1];
	char			*line;
	int				len;
	int				ret;

	ret = 0;
	current_fd = ft_get_fd(current_fd, fd);
	if ((fd < 0 || fd == 1 || fd == 2) || dest == NULL)
		return (-1);
	while (fd >= 0 && ((len = ft_check_endofline(current_fd->text)) ||
				(ret = ft_read_fd(fd, buffer)) > 0) && len <= 0)
		current_fd->text = ft_strfreejoin(current_fd->text, buffer, 2);
	if (ret == -1)
		return (-1);
	if (len > 0)
		current_fd->text[len - 1] = '\0';
	*dest = ft_strdup(current_fd->text);
	line = current_fd->text;
	current_fd->text = ((len > 0) ? ft_strdup(current_fd->text + len) :
									ft_strdup(""));
	free(line);
	current_fd = current_fd->begin_list;
	return ((len || **dest) ? 1 : 0);
}
