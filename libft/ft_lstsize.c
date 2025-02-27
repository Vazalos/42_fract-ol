/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:40:05 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/07 10:55:50 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	n;
	t_list	*tmp;

	if (!lst)
		return (0);
	n = 0;
	tmp = lst;
	while (tmp && tmp->next != NULL)
	{
		tmp = tmp->next;
		n++;
	}
	if (tmp)
		n++;
	return (n);
}
