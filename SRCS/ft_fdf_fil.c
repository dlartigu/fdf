/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_fil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:50:40 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/08 14:50:42 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

t_map	*ft_fdf_fil(t_map *fdf)
{
	fdf->win_hight = 1440;
	fdf->win_width = 2560;
	if (fdf->width < 40 || fdf->hight < 40)
		fdf->zoom = 50;
	else if ((fdf->width > 40 || fdf->hight > 40)
		&& (fdf->width < 100 || fdf->hight < 100))
		fdf->zoom = 20;
	fdf->obj_w = (fdf->win_width / 2) - (fdf->width * fdf->zoom) / 2;
	fdf->obj_h = (fdf->win_hight / 2) - (fdf->hight * fdf->zoom) / 2;
	return (fdf);
}
