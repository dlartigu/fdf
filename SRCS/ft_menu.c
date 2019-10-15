/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:14:51 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/19 13:14:52 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_menupart4(t_map *fdf)
{
	if (fdf->res == 1)
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			fdf->win_width - 350, 10, COL_WH, "Current Resolution: 2560*1440");
	if (fdf->res == 2)
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			fdf->win_width - 350, 10, COL_WH, "Current Resolution: 1920*1080");
	if (fdf->res == 3)
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			fdf->win_width - 350, 10, COL_WH, "Current Resolution: 1280*720");
}

void	ft_menupart3(t_map *fdf)
{
	if (fdf->space == 1)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 50, CL_AZ, "'8' / '5'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 50, COL_WH, "Altitude");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 70, CL_AZ, "'A' / 'D'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 70, COL_WH, "Move L R");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			(fdf->win_width / 2) - 90, 10, COL_RED, "hide Menu");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 10, 210, COL_WH,
			"F / G / H to switch resolution");
	}
}

void	ft_menupart2(t_map *fdf)
{
	if (fdf->space == 1)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 90, CL_AZ, "'W' / 'S'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 90, COL_WH, "Move U D");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 110, CL_AZ, "'Q' / 'E'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 110, COL_WH, "Zoom");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 130, CL_AZ, "'4' / '6'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 130, COL_WH, "Rotate");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 150, CL_AZ, "'1' to '-'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 150, COL_WH, "Color");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 170, CL_AZ, "' Shift '");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 170, COL_WH, "Reset All");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr, 10, 190, COL_WH,
			"Ctrl / Alt / Cmd to switch color level");
	}
}

void	ft_menufull(t_map *fdf)
{
	ft_menupart4(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
		(fdf->win_width / 2) - 300, 10, COL_WH, "Toogle 'Spacebar' to ");
	if (fdf->space == 1)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 10, 0255000000, "'ESC'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 10, COL_WH, "Exit");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			10, 30, CL_AZ, "'P'");
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			115, 30, COL_WH, "Sw Cam");
		ft_menupart2(fdf);
		ft_menupart3(fdf);
	}
	if (fdf->space == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			(fdf->win_width / 2) - 90, 10, COL_GREEN, "see Full Menu");
}

int		ft_tooglemenu(int keycode, t_map *fdf)
{
	if (keycode == 49)
		fdf->space = fdf->space == 1 ? 0 : 1;
	else if (keycode == 256 || keycode == 261
		|| keycode == 259 || keycode == 257)
		ft_ctrlcommand(keycode, fdf);
	else if (keycode == 3 || keycode == 5 || keycode == 4 || keycode == 15)
		ft_res(keycode, fdf);
	else
		return (0);
	mlx_clear_window(fdf->mlx_ptr, fdf->window_ptr);
	ft_draw(fdf);
	return (1);
}
