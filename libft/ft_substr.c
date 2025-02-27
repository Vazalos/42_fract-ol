/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:52:54 by david-fe          #+#    #+#             */
/*   Updated: 2024/10/29 11:18:43 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp_s;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	temp_s = malloc((len + 1) * sizeof(char));
	if (!temp_s)
		return (NULL);
	while (i < len)
	{
		temp_s[i] = s[start + i];
		i++;
	}
	temp_s[len] = 0;
	return (temp_s);
}
// "test" s_len=4 start=2 len=2 ->st
// "teste3" s_len=6 start=2 len=3 ->ste
/*
int	main(void)
{
	char	*s_ptr = "All I know is code!";
	unsigned int	s_index = 4;
	size_t	s_size = 6;
	char	*end_ptr;

	end_ptr = ft_substr(s_ptr, s_index, s_size);
	printf("%s", end_ptr);
	free(end_ptr);	  
}*/
