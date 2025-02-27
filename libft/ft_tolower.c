/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:27:52 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/31 15:31:14 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
#include <stdio.h>

int     main()
{
        char str1[] = "Please Make This All Lowercase";

        printf("%s", ft_strlowcase(str1));
}*/
