/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:39:08 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/08 12:53:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lststart(t_list *list, void *(*f)(void *),
					void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_ptr;
	void	*content;
	t_list	*new_elem;

	first_ptr = ft_lststart(lst, f, del);
	if (!first_ptr)
		return (NULL);
	new_elem = first_ptr;
	lst = lst->next;
	while (lst)
	{
		content = (*f)(lst->content);
		new_elem->next = ft_lstnew(content);
		if (new_elem->next == NULL)
		{
			del(content);
			ft_lstclear(&first_ptr, del);
			return (NULL);
		}
		lst = lst->next;
		new_elem = new_elem->next;
	}
	return (first_ptr);
}

static t_list	*ft_lststart(t_list *list, void *(*f)(void *),
					void (*del)(void *))
{
	void	*cont;
	t_list	*new_list;

	if (!list || !del || !f)
		return (NULL);
	cont = f(list->content);
	new_list = ft_lstnew(cont);
	if (!new_list)
	{
		del(cont);
		return (NULL);
	}
	return (new_list);
}
