/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:41:50 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/23 20:15:50 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ptrlen(unsigned long to_count)
{
	unsigned int	i;

	i = 0;
	while (to_count != 0)
	{
		to_count = to_count / 16;
		i++;
	}
	return (i);
}

char	*ft_fillptr(unsigned long to_hex, char *hex_str, unsigned int i)
{
	unsigned int	temp_num;

	while (to_hex != 0)
	{
		temp_num = to_hex % 16;
		if (temp_num < 10)
			temp_num += '0';
		else
			temp_num += 87;
		hex_str[i--] = temp_num;
		to_hex /= 16;
	}
	return (hex_str);
}

unsigned int	ft_putptr(void *to_ptr)
{
	char			*hex_str;
	unsigned int	i;
	int				fd;

	fd = 1;
	if (!to_ptr)
		return (ft_putstr_fd("(nil)", fd));
	i = ft_ptrlen((unsigned long)to_ptr);
	hex_str = ft_calloc((i + 1), sizeof(char *));
	if (!hex_str)
		return (0);
	i--;
	hex_str = ft_fillptr((unsigned long)to_ptr, hex_str, i);
	i = (unsigned int)ft_strlen(hex_str);
	i += ft_putstr_fd("0x", fd);
	ft_putstr_fd(hex_str, fd);
	free (hex_str);
	hex_str = NULL;
	return (i);
}
/*
int	main(void)
{
	unsigned long hex = 1;
	unsigned long *hex_ptr = &hex;
	ft_putptr((void *)hex_ptr);	
	printf("\n%p\n", (void *)hex_ptr);
	//	printf("number of digits post conversion:\n%d\n", i);
}*/
