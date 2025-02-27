/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:00:05 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:43 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

size_t	ft_formatchr(va_list arg_ptr, char format, int fd)
{
	size_t	n;

	fd = 1;
	n = 0;
	if (format == 'c')
		n = ft_putchar_fd(va_arg(arg_ptr, int), fd);
	else if (format == 's')
		n = ft_putstr_fd(va_arg(arg_ptr, char *), fd);
	else if (format == 'p')
		n = ft_putptr(va_arg(arg_ptr, void *));
	else if (format == 'd' || format == 'i')
		n = ft_putnbr_fd(va_arg(arg_ptr, int), fd);
	else if (format == 'u')
		n = ft_putunbr(va_arg(arg_ptr, unsigned int));
	else if (format == 'x' || format == 'X')
		n = ft_puthex(va_arg(arg_ptr, unsigned int), format);
	else if (format == '%')
		n = ft_putchar_fd('%', fd);
	return (n);
}

int	ft_printf(const char *arg_str, ...) //ALTER if FD is needed
{
	va_list	arg_ptr;
	size_t	i;
	size_t	count;
	int		fd;

	fd = 1;
	va_start(arg_ptr, arg_str);
	count = 0;
	i = 0;
	while (arg_str[i])
	{
		if (arg_str[i] == '%')
		{
			count += ft_formatchr(arg_ptr, arg_str[i + 1], fd);
			i += 2;
		}
		else
		{
			ft_putchar_fd(arg_str[i], fd);
			count++;
			i += 1;
		}
	}
	va_end(arg_ptr);
	return (count);
}
/*
int	main(void)
{
	char	*test1 = "\n";
	int		test2 = -2147483648;
	//unsigned int	test3 = 0;
	char	c = 'a';
	char	*ptr = &c;
 	//
	printf("string\n");
	printf("I am %s\n", test1);
	ft_printf("I am %s\n\n", test1);
	//
	printf("digit\n");
	printf("num: %d\n", test2);
	ft_printf("num: %d\n\n", test2);
	//
	printf("unsigned\n");
	printf("num: %u\n", test2);
	ft_printf("num: %u\n\n", test2);//
	//
	printf("hex\n");
	printf("num: %x\n", test2);
	ft_printf("num: %x\n\n", test2);
	//
	printf("HEX\n");
	printf("num: %X\n", test2);
	ft_printf("num: %X\n\n", test2);
	//
	printf("pointer\n");
	printf("num: %p\n", NULL);
	ft_printf("num: %p\n\n", NULL);
	//
	printf("int\n");
	printf("num: %i\n", test2);
	ft_printf("num: %i\n\n", test2);
	//
	printf("%% + u\n");
	printf("num: %% %u\n", test2);
	ft_printf("num: %% %u\n\n", test2);
	//
	printf("I am %s, I believe in:%% %d, %x, %X, %i, %c, %p\n",
		"David", 1, 15, 15, 9000, 'a', (void *)ptr);
	ft_printf("I am %s, I believe in:%% %d, %x, %X, %i, %c, %p\n", 
		   "David", 1, 15, 15, 9000, 'a', (void *)ptr);
}*/
/*
#include "stddef.h"

int main(void)
{
    int real_return, my_return;

    // Test with strings
    real_return = printf("Real: %s\n", "Hello, World!");
    my_return = ft_printf("Mine: %s\n", "Hello, World!");
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with NULL string
    real_return = printf("Real: %s\n", (char *)NULL);
    my_return = ft_printf("Mine: %s\n", (char *)NULL);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with characters
    real_return = printf("Real: %c\n", 'A');
    my_return = ft_printf("Mine: %c\n", 'A');
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with integers
    real_return = printf("Real: %d\n", 12345);
    my_return = ft_printf("Mine: %d\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with unsigned integers
    real_return = printf("Real: %u\n", 12345);
    my_return = ft_printf("Mine: %u\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with hexadecimal (lowercase)
    real_return = printf("Real: %x\n", 12345);
    my_return = ft_printf("Mine: %x\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Additional tests for %x (lowercase)
    real_return = printf("Real: %x\n", 0);
    my_return = ft_printf("Mine: %x\n", 0);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %x\n", 255);
    my_return = ft_printf("Mine: %x\n", 255);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %x\n", 4294967295U);
    my_return = ft_printf("Mine: %x\n", 4294967295U);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with hexadecimal (uppercase)
    real_return = printf("Real: %X\n", 12345);
    my_return = ft_printf("Mine: %X\n", 12345);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Additional tests for %X (uppercase)
    real_return = printf("Real: %X\n", 0);
    my_return = ft_printf("Mine: %X\n", 0);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %X\n", 255);
    my_return = ft_printf("Mine: %X\n", 255);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    real_return = printf("Real: %X\n", 4294967295U);
    my_return = ft_printf("Mine: %X\n", 4294967295U);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with pointer
    int x = 42;
    real_return = printf("Real: %p\n", (void *)&x);
    my_return = ft_printf("Mine: %p\n", (void *)&x);
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    // Test with percentage
    real_return = printf("Real: %%\n");
    my_return = ft_printf("Mine: %%\n");
    printf("Real return: %d | Mine return: %d\n\n", real_return, my_return);

    return 0;
}*/
