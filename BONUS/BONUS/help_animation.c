/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:54:32 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:46:01 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	animated(t_mlx *ptr)
{
	if (ptr->timer == 1200)
	{
		ptr->timer = 0;
		swap_images(ptr);
		ptr->index_e++;
		ptr->index_c++;
	}
	if (ptr->index_c == 4)
		ptr->index_c = 0;
	if (ptr->index_e == 15)
		ptr->index_e = 0;
	ptr->timer++;
	return (0);
}

t_mlx	*creation_c(t_mlx *ptr)
{
	ptr->coin[0] = syntax_creation(ptr->mlx, "textures/collect1.xpm");
	ptr->coin[1] = syntax_creation(ptr->mlx, "textures/collect2.xpm");
	ptr->coin[2] = syntax_creation(ptr->mlx, "textures/collect3.xpm");
	ptr->coin[3] = syntax_creation(ptr->mlx, "textures/collect4.xpm");
	ptr->coin[4] = syntax_creation(ptr->mlx, "textures/collect5.xpm");
	return (ptr);
}

t_mlx	*creation_e(t_mlx *ptr)
{
	ptr->enm[0] = syntax_creation(ptr->mlx, "textures/enm1.xpm");
	ptr->enm[1] = syntax_creation(ptr->mlx, "textures/enm2.xpm");
	ptr->enm[2] = syntax_creation(ptr->mlx, "textures/enm3.xpm");
	ptr->enm[3] = syntax_creation(ptr->mlx, "textures/enm4.xpm");
	ptr->enm[4] = syntax_creation(ptr->mlx, "textures/enm5.xpm");
	ptr->enm[5] = syntax_creation(ptr->mlx, "textures/enm6.xpm");
	ptr->enm[6] = syntax_creation(ptr->mlx, "textures/enm7.xpm");
	ptr->enm[7] = syntax_creation(ptr->mlx, "textures/enm8.xpm");
	ptr->enm[8] = syntax_creation(ptr->mlx, "textures/enm1a.xpm");
	ptr->enm[9] = syntax_creation(ptr->mlx, "textures/enm2a.xpm");
	ptr->enm[10] = syntax_creation(ptr->mlx, "textures/enm3a.xpm");
	ptr->enm[11] = syntax_creation(ptr->mlx, "textures/enm4a.xpm");
	ptr->enm[12] = syntax_creation(ptr->mlx, "textures/enm5a.xpm");
	ptr->enm[13] = syntax_creation(ptr->mlx, "textures/enm6a.xpm");
	ptr->enm[14] = syntax_creation(ptr->mlx, "textures/enm7a.xpm");
	ptr->enm[15] = syntax_creation(ptr->mlx, "textures/enm8a.xpm");
	return (ptr);
}

void	swap_images(t_mlx *ptr)
{
	t_loopy	index;

	index.i = 0;
	while (index.i < ptr->size.x)
	{
		index.j = 0;
		while (index.j < ptr->size.y)
		{
			if (ptr->area[index.i][index.j] == 'C')
			{
				mlx_put_image_to_window(ptr->mlx, ptr->win,
					ptr->coin[ptr->index_c], index.j * 100, index.i * 100);
			}
			if (ptr->area[index.i][index.j] == 'S')
				mlx_put_image_to_window(ptr->mlx, ptr->win,
					ptr->enm[ptr->index_e], index.j * 100, index.i * 100);
			index.j++;
		}
		index.i++;
	}
}
