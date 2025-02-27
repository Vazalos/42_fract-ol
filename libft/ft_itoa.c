/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:21:57 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/30 12:22:32 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillint(long n, int len, int sign)
{
	int		i;
	char	*int_str;

	if (sign < 0)
		len++;
	int_str = malloc((len + 1) * sizeof(char));
	if (!int_str)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		int_str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
		if (sign < 0 && i == 0)
		{
			int_str[i] = '-';
			i--;
		}
	}
	int_str[len] = '\0';
	return (int_str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	int		divd;
	long	temp_n;

	temp_n = n;
	sign = 1;
	len = 1;
	divd = 1;
	if (n == -2147483648)
		return (ft_fillint(2147483648, 10, -1));
	if (temp_n < 0)
	{
		sign = -sign;
		temp_n = -temp_n;
	}
	while ((temp_n / divd) >= 10)
	{
		divd = divd * 10;
		len++;
	}
	return (ft_fillint(temp_n, len, sign));
}
/*
int	main(void)
{
	char	*end_ptr;
	//int		num = -2147483648LL;

	end_ptr = ft_itoa(-2147483648LL);
	printf("%s", end_ptr);
	free(end_ptr);
}*/
