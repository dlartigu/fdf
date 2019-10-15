/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:40:13 by jcharrou          #+#    #+#             */
/*   Updated: 2019/07/11 15:31:30 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_bresenham(t_map *fdf)
{
	double	tx;
	double	dx;
	double	dy;

	tx = 0;
	dx = fdf->x1 - fdf->x0;
	dy = fdf->y1 - fdf->y0;
	while (tx <= 1)
	{
		fdf->x = fdf->x0 + (dx * tx);
		fdf->y = fdf->y0 + (dy * tx);
		ft_pixel_put(fdf, fdf->x + fdf->move_x,
			fdf->y + fdf->move_y, fdf->colorbase);
		tx += 1 / ft_sqrt((dx * dx) + (dy * dy));
	}
}

void	ft_par(t_map *fdf, int i, int j)
{
	fdf->colorbase = ft_altcolor(fdf, i, j);
	if (i < fdf->hight - 1)
	{
		fdf->y1 = fdf->obj_h + (i * fdf->zoom)
			- (fdf->deep * fdf->map[i][j]) * sin(fdf->rotate);
		fdf->y0 = fdf->obj_h + ((i + 1) * fdf->zoom)
			- (fdf->deep * fdf->map[i + 1][j]) * sin(fdf->rotate);
		fdf->x1 = fdf->obj_w + (j * fdf->zoom) * sin(fdf->rotate);
		fdf->x0 = fdf->obj_w + (j * fdf->zoom) * sin(fdf->rotate);
		ft_bresenham(fdf);
	}
	if (j < fdf->width - 1)
	{
		fdf->y1 = fdf->obj_h + (i * fdf->zoom)
			- (fdf->deep * fdf->map[i][j]) * sin(fdf->rotate);
		fdf->y0 = fdf->obj_h + (i * fdf->zoom)
			- (fdf->deep * fdf->map[i][j + 1]) * sin(fdf->rotate);
		fdf->x1 = fdf->obj_w + (j * fdf->zoom) * sin(fdf->rotate);
		fdf->x0 = fdf->obj_w + ((j + 1) * fdf->zoom) * sin(fdf->rotate);
		ft_bresenham(fdf);
	}
}

void	ft_iso(t_map *fdf, int i, int j)
{
	fdf->colorbase = ft_altcolor(fdf, i, j);
	if (i < fdf->hight - 1)
	{
		fdf->x0 = fdf->obj_w + (j * fdf->zoom)
			+ (i * fdf->zoom) * sin(fdf->rotate);
		fdf->x1 = fdf->obj_w + (j * fdf->zoom)
			+ ((i + 1) * fdf->zoom) * sin(fdf->rotate);
		fdf->y0 = fdf->obj_h + (((i * fdf->zoom))) - (((j * fdf->zoom)
					+ (fdf->deep * fdf->map[i][j]))) * sin(fdf->rotate);
		fdf->y1 = fdf->obj_h + ((i + 1) * fdf->zoom) - (((j * fdf->zoom)
					+ (fdf->deep * fdf->map[i + 1][j]))) * sin(fdf->rotate);
		ft_bresenham(fdf);
	}
	if (j < fdf->width - 1)
	{
		fdf->x0 = fdf->obj_w + (j * fdf->zoom)
			+ (i * fdf->zoom) * sin(fdf->rotate);
		fdf->x1 = fdf->obj_w + ((j + 1) * fdf->zoom)
			+ (i * fdf->zoom) * sin(fdf->rotate);
		fdf->y0 = fdf->obj_h + (((i * fdf->zoom))) - (((j * fdf->zoom)
					+ (fdf->deep * fdf->map[i][j]))) * sin(fdf->rotate);
		fdf->y1 = fdf->obj_h + (i * fdf->zoom) - ((((j + 1) * fdf->zoom)
					+ (fdf->deep * fdf->map[i][j + 1]))) * sin(fdf->rotate);
		ft_bresenham(fdf);
	}
}

int		ft_draw(t_map *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_memset((void *)fdf->pixel_buffer, 0, fdf->sizeline * fdf->win_hight);
	while (i < fdf->hight)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->view == 1)
				ft_par(fdf, i, j);
			else
				ft_iso(fdf, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->window_ptr, fdf->img_ptr, 0, 0);
	ft_menu(fdf);
	return (1);
}

int		ft_main_display(t_map *fdf)
{
	fdf = ft_filstruct(fdf);
	if (fdf->error == 1)
	{
		ft_putendl_fd("wrong type of datas", 2);
		ft_clear_fdf(fdf);
		return (-1);
	}
	fdf = ft_fdf_fil(fdf);
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
	return (0);
}
