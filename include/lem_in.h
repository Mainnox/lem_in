/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:18:20 by akremer           #+#    #+#             */
/*   Updated: 2019/07/01 16:58:59 by akremer          ###   ########.fr       */
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
	t_room				*room;
}						t_info;

/*\
 *						lst_function
\*/

int						new_struct(t_info *handle, char *str);

/*\
 *						test_function
\*/

void					test_print_room(t_info handle);

/*\
 *						verif_function
\*/

int						verif_coor(char *str);
int						verif_room(t_info handle, t_room *room);

#endif
