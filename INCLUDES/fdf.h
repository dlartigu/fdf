/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:58:16 by jcharrou          #+#    #+#             */
/*   Updated: 2019/07/11 10:55:50 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <math.h>
# include "struct.h"
# include "colors.h"
# include "keys.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

int		main(int ac, char **av);
int		ft_main_display(t_map *fdf);
int		ft_valide_file(int ac, char **av, t_map *fdf);
char	*ft_fil_content(char **av, t_map *fdf);
t_map	*ft_int_tab(char **av, int i, int j, t_map *fdf);
int		ft_mod(int keycode, t_map *fdf);
int		ft_exit(t_map *fdf);
int		ft_draw(t_map *fdf);
void	ft_clear_fdf(t_map *fdf);
void	ft_par(t_map *fdf, int i, int j);
void	ft_menu(t_map *fdf);
void	ft_move(int keycode, t_map *fdf);
void	ft_color(int keycode, t_map *fdf);
void	ft_zd(int keycode, t_map *fdf);
t_map	*ft_filstruct(t_map *fdf);
void	ft_freetab(char **tab);
int		ft_exit(t_map *fdf);
t_map	*ft_fdf_fil(t_map *fdf);
void	ft_pixel_put(t_map *fdf, int x, int y, unsigned int color);
int		ft_altcolor(t_map *fdf, int i, int j);
void	ft_ctrlcommand(int keycode, t_map *fdf);
void	ft_ctrlaltcmd(int keycode, t_map *fdf);
void	ft_ctrlcl(int keycode, t_map *fdf);
void	ft_cmdcl(int keycode, t_map *fdf);
void	ft_altcl(int keycode, t_map *fdf);
int		ft_tooglemenu(int keycode, t_map *fdf);
void	ft_menufull(t_map *fdf);
void	ft_res(int keycode, t_map *fdf);
#endif
