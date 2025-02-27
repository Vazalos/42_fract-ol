/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:41:29 by david-fe          #+#    #+#             */
/*   Updated: 2024/08/13 16:35:32 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
/*
#include <stdio.h>

int	main()
{
	char str1[] = "Please make this all uppercase";

	printf("uppercase %s", ft_strupcase(str1));
}*/
