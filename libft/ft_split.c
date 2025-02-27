/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:38:08 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/05 19:12:08 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *str, char limit)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	if (str[0] != limit)
		flag = 1;
	while (str[i])
	{
		if (str[i] == limit && flag == 0)
			flag = 1;
		else if (str[i] != limit && flag == 1)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return (count);
}

void	ft_free(char **tofree, size_t index)
{
	size_t	i;

	i = 0;
	while (i <= index)
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

int	ft_freecheck(char **str_array, size_t word_n)
{
	if (!str_array[word_n])
	{
		ft_free(str_array, word_n);
		return (0);
	}
	else
		return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	word_n;
	size_t	i;
	size_t	start_i;
	size_t	end_i;

	i = 0;
	word_n = 0;
	str_array = ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!str_array || !s)
		return (NULL);
	while (word_n < ft_wordcount(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		start_i = i;
		while (s[i] != c && s[i])
			i++;
		end_i = i;
		str_array[word_n] = ft_substr(s, start_i, end_i - start_i);
		if (ft_freecheck(str_array, word_n) != 1)
			return (NULL);
		word_n++;
	}
	return (str_array);
}
/*
int	main(void)
{
	char	*tosplit = "1234567890 ewqewqewq      eqwewqe eee";
	char	limit = ' ';
	char	**check;

	check = ft_split(tosplit, limit);
	while (*check)
	{
		printf("'%s'\n", *check);
		check++;
	}
	int i = 0;
	while(check[i])
		free(check[i++]);
	free(check[i]);
}*/
