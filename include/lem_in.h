/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:18:20 by akremer           #+#    #+#             */
/*   Updated: 2019/11/11 06:41:48 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <limits.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include "libft.h"
# include "mlx.h"

# define BLEU "\033[34m"
# define VERT "\033[32m"
# define JAUNE "\033[33m"
# define ROUGE "\033[31m"
# define BLANC "\033[0m"

# define TRANS 0x000000ff
# define WHITE 0xffffff
# define GREEN 0x3FCA29
# define BLUE 0x3368E1
# define YELLOW 0xECD72B
# define RED 0xB6371C
# define BLACK 0x000000
# define BROWN 0x846D11
# define BDX 0x543002
# define KAKI 0xC2E720

# define XPM_PATH "asset/terreau.xpm"
# define XPM2_PATH "asset/logo_lemin.xpm"
# define XPM3_PATH "asset/fourmis.xpm"
# define TXT_SPACE "Space = pause/play"
# define TXT_ESC "Esc   = exit"
# define TXT_RESET "r    = reset"
# define TXT_N_ANT "Remaining ants :"
# define TITLE "Lem-in"
# define SIGNATURE "Akremer & Lyhamrou"
# define SIZE_SCREEN 800
# define PANNEL_SIZE 300
# define WIN_X SIZE_SCREEN + PANNEL_SIZE
# define WIN_Y SIZE_SCREEN
# define IMG_X SIZE_SCREEN
# define IMG_Y SIZE_SCREEN
# define IMG_X2 200
# define IMG_Y2 500
# define KEY_ESC 53
# define KEY_R 15
# define KEY_SPACE 49
# define EDGE_W 3
# define BORDURE 4
# define DESPI 10
# define WAIT 100
# define FRAME 10
# define SIZE_ANT 8

typedef struct			s_point
{
	int					dx;
	int					dy;
	int					er;
	int					x1;
	int					x2;
	int					y1;
	int					y2;
}						t_point;

typedef struct			s_visu
{
	int					pause;
	int					dist;
	int					h;
	int					w;
	int					h2;
	int					w2;
	int					h4;
	int					w4;
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
	int					nb_x;
	int					nb_y;
	int					pas;
	int					bpp;
	int					sl;
	int					sl3;
	int					sl4;
	int					sl5;
	int					edn;
	int					*data;
	int					*data2;
	int					*data3;
	int					*data4;
	int					*data5;
	void				*mlx;
	void				*win;
	void				*img;
	void				*img2;
	void				*img3;
	void				*img4;
	void				*img5;
	int					**rpasu;
	t_point				p;
}						t_visu;

typedef struct			s_node
{
	int					value;//index du sommet voisin
	struct s_node		*next;
}						t_node;

typedef	struct			s_path
{
	char				done;
	int					index;
	int					size;
	int					*path;
	struct s_path		*next;
}						t_path;

typedef struct			s_neigh
{
	char				mark;
	char				done;
	char				act_done;
	int					nb_path;
	t_node				*begin;//liste des voisins
	t_path				*path;//utilise que pour l'algo
}						t_neigh;

typedef struct			s_graph
{
	int					nb_vertices;
	int					**combo;
	int					max_flow;
	t_neigh				*tab_neigh;//tableau de structure = matrice d'adjacence avec index
}						t_graph;

typedef struct			s_room
{
	int					index;
	int					x;
	int					y;
	char				*name;
	struct s_room		*next;
}						t_room;

typedef struct			s_best
{
	char				juju;
	int					size_long;
	int					size_long_tmp;
	int					size_best;
	int					size_banlist;
	int					size_tmp_best;
	int					*best;
	int					*tmp_best;
	int					*banlist;
}						t_best;

typedef struct			s_print
{
	int					max_flow;
	int					flow;
	int					ant;
	int					nb_ants;
	int					**pasu;
	int					**pos_ants;
}						t_print;

typedef struct			s_info
{
	char				algo;
	char				fatty_fat;
	int					init_visu;
	int					i;
	int					nb_ants;
	int					nb_room;
	int					start;
	int					end;
	int					tmp_nb_ants;
	t_room				*room;
	t_best				*best;//* a enlevee
	t_graph				*graph;//* a enlevee
	t_visu				visu;
	t_print				print;
}						t_info;

/*\
 *						lst_functions
\*/
int						count_arg(char *str);
int						check_less(t_info *handle, char *str, int i);
char					*name_of_index(t_info *handle, int index);
int						index_of_name(t_info *handle, char *str);
int						parsing(t_info *handle);
int						pars_room(t_info *handle, char **buf, int s, int end);
int						store_the_room(t_info *env, char **buf, int s, int e);
int						pars_edge(t_info *handle, char **buf);
/*\
 *						test_functions
\*/
void					test_pos_ants(t_print *out);
void					test_print_room(t_info handle);
void					test_affiche_path(t_graph *g);
void					test_done(t_graph *g);
void					test_size_path(t_graph *g);
void					test_combo(t_graph *g);
int						test_banlist(int *banlist);
void					test_print(t_print *print);
void					test_visu(t_info *handle);
void					test_rpasu(t_info *handle);
void					print_graph(t_info *g);
void					test_best(t_info *handle);
/*\
 *						verif_functions
\*/
int						verif_coor(char *str);
int						verif_room(t_info *handle, t_room *room);
int						verif_split(int x, int y, char **split);
int						edge_exit(t_graph *g, int src, int dest);
int						verif_nb_ants(int nb_ants, char *gnl);
int						verif_start_end_exist(t_info *handle);
/*\
 *						graph_functions
\*/
t_graph					*new_graph(int vertices);
t_node					*add_node(int value);
int						add_edge(t_info *handle, char *room1, char *room2);
void					free_graph(t_graph *g);
/*\
**						algo_function
\*/
int						resolve_lem_in(t_info *handle, char first);
int						seek_combo(t_graph *handle);
void					sort_combo(t_graph *g);
int						combo_match(int *act, int *next);
int						best_combo(t_info *handle);
int						setup_best(t_info *handle);
void					add_to_best(t_info *handle, int *to_add);
/*\
 *						free_function
\*/
void					retry(t_info *handle);
int						free_handle(t_info *handle);
void					free_at_combo(t_info *handle);
void					free_at_print(t_info *handle);
void					free_at_best(t_info *handle);
void					free_combo(t_info *handle);
void					free_room(t_info *handle);
void					free_best(t_info *handle);
void					free_path(t_info *handle);
void					free_print(t_info *handle);
void					quick_kill(void);

int						set_print(t_info *handle);
void					sim_ants(t_info *handle);

void					ft_wait(void);
int						visu(t_info *handle, int ant);
void					bresenham(t_info *handle, t_point p);
void					draw_big_line(t_info *handle, t_visu v, int i);
void					one_octant(t_info *handle, t_point p);;
void					two_octant(t_info *handle, t_point p);;
void					three_octant(t_info *handle, t_point p);;
void					four_octant(t_info *handle, t_point p);;
void					five_octant(t_info *handle, t_point p);;
void					six_octant(t_info *handle, t_point p);;
void					seven_octant(t_info *handle, t_point p);;
void					eight_octant(t_info *handle, t_point p);;
int						key_event(int key, t_info *handle);
int						is_finish(t_print *out);
void					create_pannel(t_info *handle);
void					create_bordure(t_visu v, int i);
int						init_rpasu(t_info *handle, t_visu *v);
void					init_mlx(t_info *handle);
void					init_point(t_visu *visu);
void					find_extrem(t_visu *visu, t_room *tmp);
void					init_visu(t_info *handle, t_visu*visu);
void					create_background(t_info *handle, int i, int j);
void					put_room_name(t_info *handle, t_visu v);
void					image_to_screen(t_info *handle, t_visu v, int ant);
void					init_point(t_visu *visu);
void					create_movement(t_info *handle);
void					push_swap(t_print *out);
void					rotate_ants(t_print *out);
int						key_event(int key, t_info *h);

#endif
