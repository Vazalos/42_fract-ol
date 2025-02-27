/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:23:59 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/28 14:53:32 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
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
