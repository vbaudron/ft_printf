/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:33:57 by vbaudron          #+#    #+#             */
/*   Updated: 2017/09/27 14:35:45 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	int			(*f_args)(va_list, const char**, int);

typedef	struct		s_flag
{
	int	zero;
	int	diese;
	int	plus;
	int moins;
	int space;
}					t_flag;

typedef	struct		s_struct
{
	int		has_flag;
	t_flag	*flags;
	int		gab;
	int		prec;
	char	*modif;
	char	specif;
	int		todo_gab;
	int		todo_prec;
	int		neg;
	int		done_neg;
	int		prec_null;
	int		ret;
}					t_struct;

void				ft_putstr_i(const char *s, int i);
int					ft_search_str(char *s, char c);
int					ft_printf(const char *format, ...);
char				*crea_t_specif(void);
int					ft_format(const char **format, va_list args, char **t_specif, f_args **tab);
int					crea_targ(f_args **tab);
int					has_specif(const char **format, int i, char **t_specif);
int					has_flags(const char **format, int i, int j, char **t_specif);
int					ft_struct_has_prec(const char **format, int i, int j, char **t_specif);
int					ft_return(t_struct *elem, char *s);
t_struct			*crea_struct(t_struct *elem, const char **format, int i, char *t_specif);
int					ft_d(va_list args, const char **format, int i);
int					ft_s_maj(va_list args, const char **format, int i);
int					ft_s(va_list args, const char **format, int i);
int					ft_o(va_list args, const char **format, int i);
int					ft_u(va_list args, const char **format, int i);
int					ft_x(va_list args, const char **format, int i);
int					ft_c(va_list args, const char **format, int i);
int					ft_p(va_list args, const char **format, int i);
int					ft_pourcent(const char **format, int i);
int					ft_spec_len(int j, const char **format, int i, char **t_specif);
void				ft_free_struct(t_struct *elem);
char				*ft_imax_toa(intmax_t n);
char				*ft_oct_toa(uintmax_t n);
char				*ft_uimax_toa(uintmax_t n);
int					ft_uintmax_oct_toa(uintmax_t nb, char **s);
char				*ft_unsi_toa(unsigned int i);
char				*ft_ito_hexa(uintmax_t nb, t_struct *elem);
char				*ito_adress(uintmax_t nb);
void				free_targs(f_args **tab);
int					empty_specif(const char **format, int i, int point, int moins);
int					no_specif_gab(const char **format, int start);
int					make_d(t_struct *elem, char *s, int todo_flag);
int					make_o(t_struct *elem, char *s, int todo_flag);
int					make_p(t_struct *elem, char *s);
int					make_u(t_struct *elem, char *s);
int					make_x(t_struct *elem, char *s, int todo_flag);
t_flag				*what_flags(const char **format,int i, int j, char **t_specif);
void				free_wstr(wchar_t **s, size_t len);
#endif
