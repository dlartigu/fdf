/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:31:58 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/12 16:32:03 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		ft_altcolor(t_map *fdf, int i, int j)
{
	int		color;

	color = 0;
	if (fdf->map[i][j] <= fdf->mincolor || fdf->map[i][j] == 0)
		color = fdf->colorbase1;
	else if (fdf->map[i][j] >= fdf->mincolor
		&& fdf->map[i][j] <= fdf->maxcolor / 3)
		color = fdf->color;
	else if (fdf->map[i][j] > (fdf->maxcolor / 3)
		&& fdf->map[i][j] <= (fdf->maxcolor / 3 * 2))
		color = fdf->color2;
	else if (fdf->map[i][j] > (fdf->maxcolor / 3 * 2)
		&& fdf->map[i][j] <= (fdf->maxcolor))
		color = fdf->color3;
	return (color);
}
