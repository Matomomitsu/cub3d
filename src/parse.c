/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etomiyos <etomiyos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:38 by etomiyos          #+#    #+#             */
/*   Updated: 2023/02/21 15:47:06 by etomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *msg)
{
	printf(MSG_ERROR);
	printf("%s\n", msg);
	printf(MSG_USAGE);
	exit(EXIT_FAILURE);
}

void	invalid_args(int argc, char **argv)
{
	if (argc < 2)
		exit_error(MSG_FEW_ARGS);
	if (argc > 2)
		exit_error(MSG_MANY_ARGS);
	if (is_valid_file_extension(argv[1]) == FALSE)
		exit_error(MSG_INVALID_MAP);
}
