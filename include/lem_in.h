/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:18:20 by akremer           #+#    #+#             */
/*   Updated: 2019/10/24 16:00:46 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

# define BLEU "\033[34m"
# define VERT "\033[32m"
# define JAUNE "\033[33m"
# define ROUGE "\033[31m"
# define BLANC "\033[0m"

typedef struct			s_node
{
	int					value;
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
	char				done;
	char				mark;
	char				act_done;
	int					nb_path;
	t_node				*begin;
	t_path				*path;
}						t_neigh;

typedef struct			s_graph
{
	int					nb_vertices;
	int					nb_edge;
	int					max_flow;
	int					**combo;
	t_neigh				*tab_neigh;
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

//--------------------------------
//--------------------------------
//--------------------------------
typedef struct			s_print
{
	int					max_flow;
	int					flow;
	int					ant;
	int					nb_ants;
	int					**pasu;
	int					**pos_ants;
}						t_print;
//--------------------------------
//--------------------------------
//--------------------------------

typedef struct			s_info
{
	char				algo;
	int					i;
	int					nb_ants;
	int					nb_room;
	int					start;
	int					end;
	int					tmp_nb_ants;
	t_print				print;
	t_best				*best;
	t_room				*room;
	t_graph				*graph;
}						t_info;

/*\
 *						lst_functions
\*/

int						parsing(t_info *handle);
int						pars_room(t_info *handle, char **buf, int s, int end);
int						store_the_room(t_info *env, char **buf, int s, int e);
int						pars_edge(t_info *handle, char **buf);
int						new_struct(t_info *handle, char *str);
int						new_edge(t_info *handle, char *str);
int						lycos(t_info *handle, char *str);

/*\
 *						test_functions
\*/

int						printroom(t_info *handle);
void					test_pos_ants(t_print *out);
void					test_print_room(t_info handle);
void					test_graph(void);
void					test_affiche_path(t_graph *g);
void					test_done(t_graph *g);
void					test_size_path(t_graph *g);
void					test_combo(t_graph *g);
int						test_banlist(int *banlist, int size);
void					test_print(t_print *print);
void					test_best(t_info *handle);

/*\
 *						verif_functions
\*/

char					*name_of_index(t_info *handle, int index);
int						index_of_name(t_info *handle, char *str);
t_room					*find_room_index(t_room *room, int index);
t_room					*find_room_name(t_room *room, char *name);
int						verif_coor(char *str);
int						verif_room(t_info *handle, t_room *room);
int						verif_split(int x, int y, char **split);
int						edge_exit(t_graph *g, int src, int dest);
int						verif_nb_ants(int nb_ants, char *gnl);
int						verif_start_end_exist(t_info *handle);

/*\
 *						hashtag_functions
\*/

int						hashtag_parsing(char **str, t_info *handle);

/*\
 *						gnl_functions
\*/

void					store_room(t_info *handle, char **gnl);

/*\
 *						graph_functions
\*/

t_graph					*new_graph(int vertices);
t_node					*add_node(int value);
int						add_edge(t_graph *g, int src, int dest);
void					free_graph(t_graph *g);
void					print_graph(t_graph *g);

/*\
 *						algo_function
\*/

int						resolve_lem_in(t_info *handle, char first);

/*\
 *						combo_function
\*/

int						seek_combo(t_graph *handle);
void					sort_combo(t_graph *g);
int						combo_match(int *act, int *next);

/*\
 *						best_function
\*/

int						best_combo(t_info *handle);

/*\
 *						free_function
\*/

void					free_handle(t_info *handle, char code);

/*\
 *						print_function
\*/

void					print_error(t_info *handle, char code);
int						set_print(t_info *handle);
void					sim_ants(t_info *handle);

#endif
