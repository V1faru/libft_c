/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurtone <amurtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:06:16 by amurtone          #+#    #+#             */
/*   Updated: 2020/03/05 17:23:10 by amurtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <float.h>
# include "libft.h"

# define H				1
# define HH				2
# define L				3
# define LL				4
# define J				5
# define Z				6
# define BIGL			7

# define POSITIVE	 	66
# define NEGATIVE		88

# define SCONVERSIONS 	"cspdiouxXf%"
# define SFLAGS 		"#-+ .*0123456789hljz"
# define ALLSYMBOLS 	"cspdiouxXfb%#-+ .*0123456789hLljz"

# define BLACK			"\033[0;30m"
# define BOLD_GRAY		"\033[1;30m"
# define RED			"\033[0;31m"
# define BOLD_RED		"\033[1;31m"
# define GREEN			"\033[0;32m"
# define BOLD_GREEN		"\033[1;32m"
# define YELLOW			"\033[0;33m"
# define BOLD_YELLOW	"\033[01;33m"
# define BLUE			"\033[0;34m"
# define BOLD_BLUE		"\033[1;34m"
# define MAGENTA		"\033[0;35m"
# define BLD_MAGENTA	"\033[1;35m"
# define CYAN			"\033[0;36m"
# define BOLD_CYAN		"\033[1;36m"
# define RESET			"\033[0m"

typedef	struct			s_struct1
{
	char				*fmt;
	int					printed;
	int					i;
	int					len;
	int					minus;
	int					plus;
	int					space;
	int					zero;
	int					hash;
	int					width;
	int					precision;
	int					precisdot;
	int					length;
}						t_struct;

typedef	struct			s_struct2
{
	char				*s1;
	char				*s2;
	int					precision;
	long double			i;
	long double			fl;
	int					zeros;
	int					precisionaddon;
	int					padding;
	int					beforedcmnbr;
	char				c;
	char				sign;
	int					signint;
	int					hash;
	int					dot;
}						t_struct2;

void					ft_error(void);
void					writeblanks(int n);
void					writezeros(int n);
int						signed_nbr_len(intmax_t n, int base);
int						unsigned_nbr_len(uintmax_t n, int base);
void					ft_widthasterisk(const char *fmt,
						t_struct *stru, va_list ap);
char					*ft_itoa_base_m(uintmax_t nbr, uintmax_t base);
char					*ft_itoa_base_upper(intmax_t nbr, intmax_t base);
char					findchar(t_struct *stru);
int						ft_fmtparse(const char *fmt,
						t_struct *stru, va_list ap, int i);
void					reinitialize(t_struct *stru);
void					ft_modifiers(const char *fmt,
						t_struct *stru, va_list ap);
void					ft_conversions(char c, t_struct *stru, va_list ap);
void					ifchar(t_struct *stru, va_list ap);
void					ifpercent(t_struct *stru);
void					ifstring(t_struct *stru, va_list ap);
void					ifp(t_struct *stru, va_list ap, int oxheading);
void					ifint(t_struct *stru, va_list ap, int sign, intmax_t n);
void					ifoctal(t_struct *stru, va_list ap);
void					ifudint(t_struct *stru, va_list ap);
void					ifhex(t_struct *stru, va_list ap, char x);
void					iffloat(t_struct *stru, va_list ap);
void					lalignedfloat(t_struct *stru, t_struct2 fstru);
void					ralignedfloat(t_struct *stru, t_struct2 fstru);
void					ifbinary(t_struct *stru, va_list ap);
#endif
