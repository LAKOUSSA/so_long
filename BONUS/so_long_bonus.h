/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:48:35 by gloukas           #+#    #+#             */
/*   Updated: 2023/04/27 20:48:38 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ppos
{
	int			px;
	int			py;
}				t_ppos;

typedef struct s_epos
{
	int			ex;
	int			ey;
}				t_epos;

typedef struct s_loopy
{
	int			i;
	int			j;
}				t_loopy;

typedef struct s_found
{
	int			i;
	int			j;
	int			p;
	int			e;
	int			c;
}				t_found;

typedef struct s_lenght
{
	int			x;
	int			y;
}				t_lenght;

typedef struct s_reg
{
	int			*t;
	int			n;
	int			s;
	int			k;
	int			m;
}				t_reg;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*wind;
	char		**area;
	t_lenght	size;
	t_ppos		p;
	t_epos		e;
	int			key;
	int			col;
	int			move;
	char		**areacopy;
	void		*player;
	void		*collect;
	void		*space;
	void		*exit_0;
	void		*exit_1;
	void		*wall0_0;
	void		*wall0_1;
	void		*wall0_x;
	void		*wall1_0;
	void		*wallin0;
	void		*wallin1;
	void		*wall1_x;
	void		*wallx_0;
	void		*wallx_1;
	void		*wallx_x;
	void		*moves;
	void		*left1;
	void		*left2;
	void		*right1;
	void		*right2;
	int			h;
	int			w;
	int			timer;
	int			index_c;
	int			index_e;
	void		*enm[16];
	void		*coin[5];

}				t_mlx;

//check_base_map.c
int				ft_check_param_and_exist(int ac, char **av);
void			ft_check_if_rectangular(char *s, t_mlx ptr);
void			ft_check_characters(t_mlx ptr);
void			ft_check_if_close(t_mlx ptr);
void			ft_check_cep(t_mlx ptr);

//help_check.c
t_mlx			ft_counint(char *s);
t_mlx			ft_count_collec(t_mlx ptr);
t_mlx			rev_search_p(t_mlx ptr);
t_mlx			rev_search_e(t_mlx ptr);
void			ft_free(char **t, int n);

//check_path.c
char			**ft_copy_area(t_mlx ptr);
void			rev_path_c(char **s, int x, int y, t_mlx ptr);
void			rev_path_e(char **s, int x, int y, t_mlx ptr);
void			rev_path_collec(char **s, t_mlx ptr);
void			ft_check_path(t_mlx ptr);

//main_check.c
void			ft_check_extension(char *s);
t_mlx			make_area(char *zone, t_mlx ptr);
t_mlx			ft_check_all(t_mlx ptr, char *zone);
t_mlx			ft_read_check(int ac, char *av[]);

//display_loop.c
t_mlx			display_all(t_mlx *ptr);
int				right_moves(t_mlx ptr, int d, t_loopy index);
int				left_moves(t_mlx ptr, int a, t_loopy index);
void			mini_loop(t_mlx ptr, t_loopy index, int a, int d);
t_mlx			ft_loop(int keycode, t_mlx ptr);

//moves.c
int				my_key_funct(int keycode, t_mlx *ptr);
void			move_w(t_mlx *ptr, int *move);
void			move_a(t_mlx *ptr, int *move);
void			move_d(t_mlx *ptr, int *move);
void			move_s(t_mlx *ptr, int *move);

//moves_help
void			end_move(t_mlx *ptr, int *move);
void			curr_move(t_mlx *ptr, int *move);

//help_mlx.c
void			*syntax_creation(void *texture, char *name);
t_mlx			*creation_textures(t_mlx *ptr);
void			ft_put_image(t_mlx ptr, void *item, t_loopy index);
void			full_wall(t_mlx *ptr, t_loopy index);
int				chose_inside_wall(t_mlx *ptr, int x, int y, int a);

//help_animation.c
int				animated(t_mlx *ptr);
t_mlx			*creation_c(t_mlx *ptr);
t_mlx			*creation_e(t_mlx *ptr);
void			swap_images(t_mlx *ptr);

//main

#endif
