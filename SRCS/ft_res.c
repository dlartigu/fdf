/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:47:08 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/19 15:47:10 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_qhd(int keycode, t_map *fdf)
{
	if (keycode == 3)
	{
		fdf->win_hight = 1440;
		fdf->win_width = 2560;
		fdf->move_x = 0;
		if (fdf->width > fdf->win_width)
			fdf->zoom = 5;
		fdf->res = 1;
	}
}

void	ft_fhd(int keycode, t_map *fdf)
{
	if (keycode == 5)
	{
		fdf->win_hight = 1080;
		fdf->win_width = 1920;
		if (fdf->width > fdf->win_width)
			fdf->zoom = 4;
		fdf->move_x = -300;
		fdf->res = 2;
	}
}

void	ft_hd(int keycode, t_map *fdf)
{
	if (keycode == 4)
	{
		fdf->win_hight = 720;
		fdf->win_width = 1280;
		if (fdf->width > fdf->win_width)
			fdf->zoom = -10;
		fdf->move_x = -500;
		fdf->res = 3;
	}
}

void	ft_repeat(int keycode, t_map *fdf)
{
	if (keycode == 15)
		fdf->hook = fdf->hook == 0 ? 1 : 0;
}

void	ft_res(int keycode, t_map *fdf)
{
	ft_repeat(keycode, fdf);
	ft_qhd(keycode, fdf);
	ft_fhd(keycode, fdf);
	ft_hd(keycode, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->window_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->window_ptr);
	fdf->mlx_ptr = mlx_init();
	fdf->window_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width,
		fdf->win_hight, fdf->name);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width, fdf->win_hight);
	fdf->pixel_buffer = mlx_get_data_addr(fdf->img_ptr,
		&fdf->bpp, &fdf->sizeline, &fdf->endian);
	fdf->bpp = fdf->bpp / 8;
	if (fdf->hook == 0)
		mlx_key_hook(fdf->window_ptr, &ft_mod, fdf);
	if (fdf->hook == 1)
		mlx_hook(fdf->window_ptr, 2, 5, &ft_mod, fdf);
	mlx_hook(fdf->window_ptr, 17, 0, &ft_exit, fdf);
	mlx_expose_hook(fdf->window_ptr, &ft_draw, fdf);
	mlx_loop(fdf->mlx_ptr);
}
