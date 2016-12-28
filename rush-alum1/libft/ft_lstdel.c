/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicolas <mnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:24:15 by mnicolas          #+#    #+#             */
/*   Updated: 2015/11/30 18:19:13 by mnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp2;

	if (alst && del)
	{
		temp = *alst;
		while (temp != NULL)
		{
			temp2 = temp->next;
			ft_lstdelone(&temp, del);
			temp = temp2;
		}
		*alst = NULL;
	}
}
