/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:00:57 by akremer           #+#    #+#             */
/*   Updated: 2019/06/20 16:25:54 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_extra
{
	int			moins;
	int			plus;
	int			hastag;
	int			precision;
	int			blanck;
	int			done;
	int			width;
	int			size;
	int			zero;
}				t_extra;

typedef struct	s_printf
{
	int			i;
	const char	*str;
	int			nbprint;
	va_list		ap;
	t_extra		*extra;
}				t_printf;

void			ft_flags_printf(t_printf *h);
int				ft_atoi_printf(t_printf *h);
int				ft_nbrlen(unsigned long long nb, char signe, unsigned int ba);
void			ft_set_moins(t_printf *h);
void			ft_set_blanck(t_printf *h);
void			ft_set_precision(t_printf *h);
void			ft_set_zero(t_printf *h);
void			ft_set_width(t_printf *h);
void			ft_set_plus(t_printf *h);
void			ft_set_hastag(t_printf *h);
void			ft_set_star(t_printf *h);
void			ft_set_size(t_printf *h);
int				ft_printf(const char *str, ...);
void			ft_print_printf(t_printf *h);
void			ft_print_c(t_printf *h, unsigned *c);
void			ft_print_while(t_printf *h, int len, char c);
void			ft_print_str(t_printf *h, char *str);
void			ft_print_s(t_printf *h, unsigned *s);
void			ft_print_signed(t_printf *h, int base);
void			ft_print_unsigned(t_printf *h, unsigned int base);
void			ft_print_gx(t_printf *h, unsigned int base);
void			ft_print_hastag(t_printf *h, char c, unsigned int ba);
int				ft_cal_nbdisplay(t_printf *h, int len,
		unsigned int ba, unsigned long long nb);
int				ft_cal_p(t_printf *h, int len, char c, unsigned int ba);
int				ft_cal_nbdisplay_signed(t_printf *h, int len, char signe);
void			ft_print_signe(t_printf *h, char signe);
void			ft_print_pc(t_printf *h);
void			ft_print_char(t_printf *h, char c);
void			ft_display_unsigned(t_printf *h, char *base,
		unsigned int ba, unsigned long long nb);
void			ft_f_u(t_printf *h, char *base,
		unsigned int ba, unsigned long long nb);
void			ft_f_s(t_printf *h, char *base
		, unsigned int ba, long long nb);
void			ft_flags_gx(t_printf *h, char *base,
		unsigned int ba, unsigned long long nb);
void			ft_print_float(t_printf *h);
#endif
