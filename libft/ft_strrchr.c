/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:04:18 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/28 15:06:44 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	long	len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("wrong!");
		return(0);
	printf("%s", ft_strchr(argv[1], (int)argv[2][0]));
	printf("%s", ft_strchr("test", ''));
}*/
