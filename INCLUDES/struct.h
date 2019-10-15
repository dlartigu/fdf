/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:58:16 by jcharrou          #+#    #+#             */
/*   Updated: 2019/07/11 15:14:43 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct		s_map
{
	char			*name;
	char			*pixel_buffer;
	char			*cmp;
	double			x;
	double			y;
	double			x0;
	double			x1;
	double			y0;
	double			y1;
	double			deep;
	double			rotate;
	double			obj_h;
	double			obj_w;
	double			win_hight;
	double			win_width;
	int				bpp;
	int				sizeline;
	int				endian;
	int				error;
	int				move_x;
	int				move_y;
	int				view;
	int				mincolor;
	int				maxcolor;
	int				ctrl;
	int				alt;
	int				cmd;
	int				width;
	int				hight;
	int				zoom;
	int				**map;
	int				space;
	int				res;
	int				hook;
	void			*mlx_ptr;
	void			*img_ptr;
	void			*window_ptr;
	unsigned int	color;
	unsigned int	colorbase;
	unsigned int	colorbase1;
	unsigned int	color2;
	unsigned int	color3;
}					t_map;

#endif
