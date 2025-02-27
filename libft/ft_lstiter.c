/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:20:22 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/08 10:30:31 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp && temp->next)
	{
		(*f)(temp->content);
		temp = temp->next;
	}
	if (temp)
		(*f)(temp->content);
}
