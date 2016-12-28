/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:52:22 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:47:13 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(char const *str)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]) == 1)
			i++;
		if (ft_isspace(str[i]) == 0)
			if ((ft_isspace(str[i + 1]) == 1) || str[i + 1] == '\0')
				size++;
		i++;
	}
	return (size);
}

static size_t	ft_length(char const *s, int i)
{
	size_t	len;

	len = 0;
	while ((ft_isspace(s[i]) == 0) && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_splitspace(char const *s)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * ft_size(s));
	if (res == NULL)
		return (res);
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 0)
		{
			res[j] = ft_strsub(s, i, ft_length(s, i));
			j++;
			while ((ft_isspace(s[i]) == 0) && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
