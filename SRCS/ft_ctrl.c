/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:20:54 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/13 15:20:55 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_ctrl(t_map *fdf)
{
	fdf->ctrl = fdf->ctrl == 0 ? 1 : 0;
	fdf->alt = 0;
	fdf->cmd = 0;
}

void	ft_alt(t_map *fdf)
{
	fdf->alt = fdf->alt == 0 ? 1 : 0;
	fdf->ctrl = 0;
	fdf->cmd = 0;
}

void	ft_cmd(t_map *fdf)
{
	fdf->cmd = fdf->cmd == 0 ? 1 : 0;
	fdf->alt = 0;
	fdf->ctrl = 0;
}

void	ft_reset(t_map *fdf)
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
}

void	ft_ctrlcommand(int keycode, t_map *fdf)
{
	if (keycode == 256)
		ft_ctrl(fdf);
	else if (keycode == 261)
		ft_alt(fdf);
	else if (keycode == 259)
		ft_cmd(fdf);
	else if (keycode == 257)
		ft_reset(fdf);
}
