/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 16:42:30 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:45:43 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc(char const *s)
{
	size_t	i;
	int		cnt;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	cnt = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		cnt++;
	}
	if (i != ft_strlen((char *)s))
	{
		i = ft_strlen((char *)s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			cnt++;
		}
	}
	new = (char *)malloc(sizeof(char) * ft_strlen((char *)s) - cnt + 1);
	return (new);
}

static int	ft_sizeoftrim(char const *s)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		cnt++;
	}
	if (i != ft_strlen((char *)s))
	{
		i = ft_strlen((char *)s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			cnt++;
		}
	}
	return (ft_strlen((char *)s) - cnt);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*res;

	res = ft_alloc(s);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (ft_sizeoftrim(s) == 0)
	{
		res[0] = '\0';
		return (res);
	}
	while (j < ft_sizeoftrim(s))
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
