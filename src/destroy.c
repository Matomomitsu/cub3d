/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:43 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/23 01:46:01 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *msg, t_bool usage)
{
	printf(MSG_ERROR);
	printf("%s\n", msg);
	if (usage == TRUE)
		printf(MSG_USAGE);
	exit(EXIT_FAILURE);
}

void	free_file_data(t_file_data *file_data)
{
	free(file_data->ea_path);
	free(file_data->we_path);
	free(file_data->no_path);
	free(file_data->so_path);
	free(file_data);
}

void	destroy_all(t_cub3d *c)
{
	mlx_destroy_image(c->mlx, c->img.image);
	mlx_destroy_window(c->mlx, c->win);
	mlx_destroy_display(c->mlx);
	free_file_data(c->file_data);
	free(c->mlx);
	free(c->map);
}
