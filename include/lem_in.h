/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:18:20 by akremer           #+#    #+#             */
/*   Updated: 2019/08/24 17:59:53 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

typedef struct			s_room
{
	int					index;
	int					x;
	int					y;
	char				*name;
	int					*connect;
	struct s_room		*next;
}						t_room;

typedef struct			s_info
{
	int					nb_ants;
	int					nb_room;
	int					start;
	int					end;
	t_room				*room;
}						t_info;

/*\
 *						lst_functions
\*/

int						new_struct(t_info *handle, char *str);

/*\
 *						test_functions
\*/

void					test_print_room(t_info handle);

/*\
 *						verif_functions
\*/

int						verif_coor(char *str);
int						verif_room(t_info handle, t_room *room);

/*\
 *						hashtag_functions
\*/

int						hashtag_parsing(char **str, t_info *handle);

/*\
 *						gnl_functions
\*/

void					store_room(t_info *handle, char **gnl);

#endif
