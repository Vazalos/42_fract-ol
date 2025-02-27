/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:53:33 by david-fe          #+#    #+#             */
/*   Updated: 2025/02/26 15:56:31 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win =  mlx_new_window(mlx, 500, 500, "test window");
	mlx_loop(mlx);
}
