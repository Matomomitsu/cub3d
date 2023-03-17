/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:36 by etomiyos          #+#    #+#             */
/*   Updated: 2023/03/16 21:30:24 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	menu(t_cub3d *c)
{
	c->menu.active = FALSE;
	c->menu.fullscreen.toggle = FALSE;
	c->menu.img.ptr = mlx_xpm_file_to_image(c->mlx.ptr,
			"./assets/images/paused.xpm",
			&c->menu.img.win_width,
			&c->menu.img.win_height);
	c->menu.img.addr = mlx_get_data_addr(c->menu.img.ptr,
			&c->menu.img.bits_per_pixel, &c->menu.img.line_length,
			&c->menu.img.endian);
	c->menu.img.win_width = c->mlx.win.width;
	c->menu.img.win_height = c->mlx.win.height;
	c->menu.resize.ptr = NULL;
	c->menu.resize.addr = NULL;
	c->menu.width_ratio = 0;
	c->menu.height_ratio = 0;
}

static void	mlx(t_cub3d *c)
{
	c->mlx.ptr = mlx_init();
	c->mlx.win.ptr = mlx_new_window(c->mlx.ptr, WIDTH, HEIGHT, WIN_NAME);
	c->mlx.img.ptr = mlx_new_image(c->mlx.ptr, WIDTH, HEIGHT);
	if (c->mlx.ptr == NULL || c->mlx.win.ptr == NULL || c->mlx.img.ptr == NULL)
		exit_error(MSG_ERR_MLX_INIT, FALSE);
	c->mlx.img.addr = mlx_get_data_addr(c->mlx.img.ptr,
			&c->mlx.img.bits_per_pixel, &c->mlx.img.line_length,
			&c->mlx.img.endian);
	c->mlx.win.width = WIDTH;
	c->mlx.win.height = HEIGHT;
	c->mlx.img.win_width = WIDTH;
	c->mlx.img.win_height = HEIGHT;
	mlx_get_screen_size(c->mlx.ptr,
		&c->mlx.screen_width, &c->mlx.screen_height);
	c->mlx.screen_width -= 16;
	c->mlx.screen_height -= 32;
	c->menu.quit.height = 0;
	c->menu.quit.width = 0;
	c->menu.quit.x = 0;
	c->menu.quit.y = 0;
}

void	map_init(t_map *map, char *file)
{
	map->file = ft_strdup(file);
	map->infos = 0;
	map->f_color = 0;
	map->c_color = 0;
	map->map = NULL;
	map->ea_path = NULL;
	map->we_path = NULL;
	map->so_path = NULL;
	map->no_path = NULL;
}

static void	player(t_cub3d *c)
{
	c->dda.pixel = 0;
	c->dda.perpendicular = 0;
	c->player.camera.speed.x = DEF_CAM_SPEED_X;
	c->player.camera.speed.y = DEF_CAM_SPEED_Y;
	c->light_mode = FALSE;
	c->distortion = FALSE;
	c->animate = FALSE;
	c->mini_map = FALSE;
	c->player.speed = DEF_PLAYER_SPEED;
}

static void	textures(t_cub3d *c)
{
	c->draw = (t_draw){0};
	c->mlx.ea_tex = (t_texture){0};
	c->mlx.so_tex = (t_texture){0};
	c->mlx.no_tex = (t_texture){0};
	c->mlx.we_tex = (t_texture){0};
}

void	init(char **argv, t_cub3d *c)
{
	player(c);
	map_init(&c->map, argv[1]);
	textures(c);
	mlx(c);
	menu(c);
}
