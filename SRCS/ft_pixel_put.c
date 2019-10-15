/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:42:50 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/12 14:42:51 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_pixel_put(t_map *fdf, int x, int y, unsigned int color)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)&color;
	if (x >= fdf->win_width || y >= fdf->win_hight || x < 0 || y < 0)
		return ;
	while (i < fdf->bpp)
	{
		fdf->pixel_buffer[(fdf->sizeline * y) + (x * fdf->bpp) + i] = ptr[i];
		i++;
	}
}
