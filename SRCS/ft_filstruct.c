/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:42:18 by dlartigu          #+#    #+#             */
/*   Updated: 2019/07/18 11:42:20 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

t_map	*ft_filstruct(t_map *fdf)
{
	fdf->deep = 0.8;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->rotate = 1;
	fdf->zoom = 5;
	fdf->view = 1;
	fdf->colorbase1 = CL_DKBL;
	fdf->colorbase = CL_DKGREEN;
	fdf->color = CL_DKGREEN;
	fdf->color2 = CL_DARKBROWN;
	fdf->color3 = CL_GREY;
	fdf->ctrl = 0;
	fdf->alt = 0;
	fdf->cmd = 0;
	fdf->space = 0;
	fdf->res = 1;
	fdf->hook = 0;
	return (fdf);
}
