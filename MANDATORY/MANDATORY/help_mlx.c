/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:53:36 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:46:49 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*syntax_creation(void *texture, char *name)
{
	int	height;
	int	width;

	texture = mlx_xpm_file_to_image(texture, name, &width, &height);
	if (!texture)
		exit(1);
	return (texture);
}

t_mlx	*creation_textures(t_mlx *ptr)
{
	ptr->player = syntax_creation(ptr->mlx, "textures/player.xpm");
	ptr->collect = syntax_creation(ptr->mlx, "textures/collect.xpm");
	ptr->space = syntax_creation(ptr->mlx, "textures/space.xpm");
	ptr->exit_0 = syntax_creation(ptr->mlx, "textures/exit_0.xpm");
	ptr->exit_1 = syntax_creation(ptr->mlx, "textures/exit_1.xpm");
	ptr->wall0_0 = syntax_creation(ptr->mlx, "textures/wall0_0.xpm");
	ptr->wall0_1 = syntax_creation(ptr->mlx, "textures/wall0_1.xpm");
	ptr->wall0_x = syntax_creation(ptr->mlx, "textures/wall0_x.xpm");
	ptr->wall1_0 = syntax_creation(ptr->mlx, "textures/wall1_0.xpm");
	ptr->wallin0 = syntax_creation(ptr->mlx, "textures/wallin0.xpm");
	ptr->wallin1 = syntax_creation(ptr->mlx, "textures/wallin1.xpm");
	ptr->wall1_x = syntax_creation(ptr->mlx, "textures/wall1_x.xpm");
	ptr->wallx_0 = syntax_creation(ptr->mlx, "textures/wallx_0.xpm");
	ptr->wallx_1 = syntax_creation(ptr->mlx, "textures/wallx_1.xpm");
	ptr->wallx_x = syntax_creation(ptr->mlx, "textures/wallx_x.xpm");
	ptr->left1 = syntax_creation(ptr->mlx, "textures/left1.xpm");
	ptr->left2 = syntax_creation(ptr->mlx, "textures/left2.xpm");
	ptr->right1 = syntax_creation(ptr->mlx, "textures/right1.xpm");
	ptr->right2 = syntax_creation(ptr->mlx, "textures/right2.xpm");
	return (ptr);
}

void	full_wall(t_mlx *ptr, t_loopy index)
{
	int			x;
	int			y;
	static int	a;

	x = index.j * 100;
	y = index.i * 100;
	if (index.i == 0 && index.j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_0, x, y);
	else if (index.i == 0 && index.j == ptr->size.y - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_x, x, y);
	else if (index.i == ptr->size.x - 1 && index.j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallx_0, x, y);
	else if (index.i == ptr->size.x - 1 && index.j == ptr->size.y - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallx_x, x, y);
	else if (index.i == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_1, x, y);
	else if (index.i == ptr->size.x - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallx_1, x, y);
	else if (index.j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall1_0, x, y);
	else if (index.j == ptr->size.y - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall1_x, x, y);
	else
		a = chose_inside_wall(ptr, x, y, a);
}

int	chose_inside_wall(t_mlx *ptr, int x, int y, int a)
{
	if (a % 2)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallin1, x, y);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallin0, x, y);
	a++;
	return (a);
}

void	ft_put_image(t_mlx ptr, void *item, t_loopy index)
{
	mlx_put_image_to_window(ptr.mlx, ptr.win, item, index.j * 100, index.i
		* 100);
}
