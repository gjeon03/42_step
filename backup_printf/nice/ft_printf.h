/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:40:39 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 21:48:30 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX(a, b) (a > b) ? a : b
# define MIN(a, b) (a < b) ? a : b
# define ABS(a) (a < 0) ? -a : a
# define X7 0x40
# define X8 0x80
# define FC1 0x80
# define FC2 0x800
# define FC3 0x10000
# define FC4 0x200000
# define FC5 0x4000000
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

typedef struct				s_print
{
	char	flag;
	char	sharp;
	int		sharp_x;
	char	plus;
	long	field;
	long	pcs;
	char	hhll;
	char	spec;
	long	width;
	int		minus;
	long	show;
	char	isnan;
	int		ians[401];
	int		dans[2101];
	long	exp;
	int		sdig;
	int		gflag;
}							t_print;

typedef union				u_uni
{
	double					d;
	struct
	{
		unsigned long long	manti:52;
		unsigned int		index:11;
		unsigned char		sign:1;
	}						data;
}							t_uni;

int							ft_isnum(char c);
int							ft_isnump(char c);
t_print						def(char c, long n);
t_print						get_field(const char **s, va_list *list, t_print p);
t_print						get_flag(const char **s, t_print p);
int							get_precision(const char **s, va_list *list);
char						get_hhll(const char **s);
int							putp(char c);
void						putleft_num(char *save, t_print *p);
void						putleft(char *save, t_print p);
void						putzero(char *save, t_print p);
char						*putright_num(char *save, t_print *p);
void						putright(char *save, t_print p);
void						pout(char *save, t_print p);
char						*ft_itoa_st(size_t n);
char						*ft_convert(size_t n, const char *set, int base);
char						*ft_convert_p(size_t n, char *set, t_print p);
int							ft_wbyte(long n);
char						*ft_chrdup(long n);
int							unicode_topindex(int size, long n);
char						*ft_addplus(char *save, t_print p);
char						*ft_sharp(char *save, t_print *p);
char						*ft_deci(va_list *list, t_print *p);
char						*ft_convert_c(va_list *list, t_print p);
int							ft_convert_n(va_list *list, size_t len, t_print p);
char						*ft_convert_di(va_list *list, t_print *p);
char						*ft_convert_uxp(va_list *list, t_print p);
int							make_save1(va_list *list, t_print p, size_t len);
int							make_save2(va_list *list, t_print p, char *save);
int							parse(const char **s, va_list *list, size_t len);
int							ft_printf(const char *s, ...);
int							is_deci(char c);
int							is_spec(char c);
void						dans_fix(t_print *p, int j);
void						make_dans2(int	dbox[2101]
							, int dbit[2101], t_print *p);
void						make_dans(unsigned long long manti
							, int exp, t_print *p);
void						ians_fix(t_print *p, int j);
void						make_ians2(int	ibox[801]
							, int ibit[2101], t_print *p);
void						make_ians(unsigned long long manti
							, int exp, t_print *p);
void						ft_nanflag(unsigned long long manti, t_print *p);
void						make_fans(double d, t_print *p);
void						ft_round_over5(int i, t_print *p);
void						ft_round_is5(int pcs, t_print *p);
void						ft_round_moveup(int pcs, t_print *p);
void						ft_round(t_print *p);
char						*make_esaf2(t_print *p);
char						*make_esaf(char *saf, t_print *p);
char						*make_sgsaf(t_print *p);
char						*make_gsaf(t_print *p);
char						*make_fsaf(t_print *p);
char						*make_fpre(t_print *p);
char						*ft_isnan(char c);
void						convert_deci2(t_print *p);
void						convert_deci(t_print *p);
void						ft_echeck(t_print *p);
void						check_deci2(t_print *p);
void						check_deci(t_print *p);
char						*ft_deci_save(t_print *p);
char						*ft_deci(va_list *list, t_print *p);
#endif
