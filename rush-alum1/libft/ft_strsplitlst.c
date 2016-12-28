/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:13:51 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:38:40 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizeofcontent(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

t_list			*ft_strsplitlst(char const *s, char c)
{
	t_list	*res;
	t_list	*temp;
	int		i;
	int		len;

	i = 0;
	res = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = ft_sizeofcontent(s, c, i);
			temp = ft_lstnew((void *)ft_strsub(s, i, len), len + 1);
			res = ft_lstaddend(&res, temp);
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (res);
}
