/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:27 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/21 11:00:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_hexcount(unsigned int to_count)
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

char	*ft_fillhex(unsigned int to_hex, char *hex_str,
				char format, unsigned int i)
{
	unsigned int	temp_num;

	while (to_hex != 0)
	{
		temp_num = to_hex % 16;
		if (temp_num < 10)
			temp_num += '0';
		else if (format == 'X')
			temp_num += 55;
		else if (format == 'x')
			temp_num += 87;
		hex_str[i--] = temp_num;
		to_hex /= 16;
	}
	return (hex_str);
}

unsigned int	ft_puthex(unsigned int to_hex, char format)
{
	char			*hex_str;
	unsigned int	i;
	int				fd;

	fd = 1;
	if (to_hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = ft_hexcount(to_hex);
	hex_str = ft_calloc((i + 1), sizeof(char *));
	if (!hex_str)
		return (0);
	i--;
	hex_str = ft_fillhex(to_hex, hex_str, format, i);
	i = (unsigned int)ft_strlen(hex_str);
	ft_putstr_fd(hex_str, fd);
	free (hex_str);
	hex_str = NULL;
	return (i);
}
/*
int	main(void)
{
	unsigned int	hex = 12312312;
	void	*hex_ptr = &hex;
	printf("%x\n", hex);
	ft_puthex(hex, 'x');
	printf("\n%X\n", hex);
	ft_puthex(hex, 'X');
	printf("\n%p", hex_ptr);
	//ft_puthex(hex_ptr, 'p');
	printf("\n%d", hex);
	//	printf("number of digits post conversion:\n%d\n", i);
}*/
