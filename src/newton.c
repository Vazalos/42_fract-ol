/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:51:59 by david-fe          #+#    #+#             */
/*   Updated: 2025/04/03 16:52:02 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_complex	next(t_complex z)
{
	t_complex	new;
	double		temp_deno;

	temp_deno = 3 * (z.x * z.x + z.y * z.y) * (z.x * z.x + z.y * z.y);
	new.x = ((z.x * z.x * z.x * z.x * z.x + 2 * z.x * z.x * z.x * z.y * z.y
				- z.x * z.x + z.x * z.y * z.y * z.y * z.y + z.y * z.y)
			/ temp_deno);
	new.y = ((z.y * (z.x * z.x * z.x * z.x + 2 * z.x * z.x
					* z.y * z.y + 2 * z.x + z.y * z.y * z.y * z.y))
			/ temp_deno);
	z.x -= new.x;
	z.y -= new.y;
	return (z);
}
