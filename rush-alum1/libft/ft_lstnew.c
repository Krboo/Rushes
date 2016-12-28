/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:06:26 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:15:12 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	new = (t_list *)malloc(sizeof(t_list));
	if (content == NULL && new != NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if (new != NULL)
	{
		new->content = (void *)content;
		new->content_size = content_size;
		new->next = NULL;
		return (new);
	}
	else
		return (NULL);
}
