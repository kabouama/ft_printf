/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 18:26:01 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 06:31:16 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef struct			s_stock
{
	char				*str;
	struct s_stock		*next;
}						t_stock;

typedef struct			s_flag
{
	int					i;
	int					len;
	int					flag;
	int					flag2;
	int					prec;
	int					prec2;
	int					tmp;
	int					x;
	int					y;
}						t_flag;

typedef struct			s_param
{
	int					i;
	int					j;
	int					len;
	char				flags;
	char				flags2;
	char				flags3;
	int					width;
	int					width2;
	int					width3;
	int					preci;
	int					preci2;
	char				*size;
	char				type;
	int					var_type;
	char				*res;
	int					temp;
	int					tmp;
	int					tmp2;
	int					flagos;
	int					len_o;
	int					test;
	int					flg_f;
	int					flt;
}						t_param;

typedef struct			s_float
{
	int					tmp;
}						t_float;

int						ft_printf(const char *format, ...)
	 __attribute__((format(printf,1,2)));
t_stock					*ft_fillnew(int size);
void					ft_filladdback(t_stock **alst, int size);
int						check_cv(char format);
int						char_atoi(t_stock *stck, t_param *prm);
/*
**		Fonctions d'affichage du type et actualisiation des flas :
*/
t_stock					*ft_decoupe(const char *format);
t_param					*typee_x(long var, t_param *prm);
t_param					*typee_o(long var, t_param *prm);
t_param					*typee_u(long var, t_param *prm);
t_flag					*ft_size(int var, t_flag *flg);
t_param					*actu_flags(t_param *prm, t_stock *s);
t_param					*actu_precision(t_param *prm, t_stock *stck);
void					actu_size(t_param *prm, t_stock *stck);
t_param					*actu_size2(t_param *prm, t_stock *stck);
t_param					*actu_param(t_param *prm, t_stock *stck);
t_param					*actu_param2(t_param *prm, t_stock *stck);
t_param					*process(t_param *prm, t_stock *stck, va_list list);
/*
**		Fonctions de l'algo de chaque type
*/
long					process_d(t_param *prm, long var);
long					process_dd(t_param *prm, long var, double varf);
char					*process_s(t_param *prm, char *var);
long					process_p(t_param *prm, long var);
long double				process_f(t_param *prm, va_list list, long double varf);
void					process_percent(t_param *prm);
long					type(t_param *prm, long var, va_list list);
char					*type_s(t_param *prm, char *var, va_list list);
/*
**		Fonctions des putnbr
*/
long long				ft_putnbr_lf(long double n, t_float *flt);
long long				ft_putnbr_long(long long n);
unsigned int			ft_putnbr_u(unsigned int n);
unsigned long long		ft_putnbr_uu(unsigned long long n);
int						ft_nbrlen_lf(long double n, t_param *prm);
unsigned long long		ft_nbrlen_ll(unsigned long long n);
unsigned long			ft_putnbr_lu(unsigned long n);
long long				ft_putnbr_ll(long long n);
int						ft_putnbr_hu(unsigned short n);
int						ft_putnbr_hhu(unsigned char n);
int						ft_putnbr_base3(unsigned int nbr,
		char const *base, t_param *prm);
int						ft_putnbr_base_diez(unsigned char nbr,
		char const *base, t_param *prm);
int						ft_putnbr_base_ho(unsigned short nbr,
		char const *base, t_param *prm);
int						ft_putnbr_base_lo(unsigned long nbr,
		char const *base, t_param *prm);
int						ft_putnbr_base_llo(unsigned long long nbr,
		char const *base, t_param *prm);
int						ft_nbrlen_base_o(unsigned long long nbr,
		char const *base, t_param *prm);
int						ft_nbrlen_base_oo(unsigned int nbr,
		char const *base, t_param *prm);
/*
**		Fonctions de check de width et des flags
*/
long					check_width(t_param *prm, long var);
void					width_neg(t_param *prm, long var);
long					check_flags_zer(t_param *prm, long var);
long					check_preci(t_param *prm, long var);
long					check_flags(t_param *prm, long var);
long					check_flags2(t_param *prm, long var);
long					check_diez(t_param *prm, long var);
void					process_diez(t_param *prm, long var);
void					supp_zer(t_param *prm, long var, double varf);
void					affiche_plus(t_param *prm, long var);
char					*check_preci_f(t_param *prm, double varf);
void					width_x(t_param *prm, long var);
void					preci_x(t_param *prm, long var);
/*
**		Fonctions d'affichage
*/
void					affiche_var(t_param *prm, long var);
void					check_width_d(t_param *prm, long var, float varf);
void					affiche_space_here(t_param *prm);
void					affiche_space(t_param *prm);
/*
**		Check du type s'il y en a un
*/
long					type(t_param *prm, long var, va_list list);
long					check_hh(t_param *prm, long var, va_list list);
long					check_ll(t_param *prm, long var, va_list list);
long					check_h(t_param *prm, long var, va_list list);
long					check_l(t_param *prm, long var, va_list list);
/*
**		Init and free
*/
void					free_list(t_stock *begin);
void					init_prm(t_param *prm);
void					init_prm2(t_param *prm);
void					free_prm(t_param *prm, t_stock *begin);
/*
**		float
*/
char					*arrondi_f(char *str, t_param *prm);
void					c_str(t_param *prm, double varf, t_float *flt);
char					*init_str(t_param *prm,
		long double zer_cink, double varf);
char					*boucle_str(t_param *prm, long double zer_cink,
		int prec, char *str);
char					*check_preci_f(t_param *prm, double varf);
char					*preci_f2(t_param *prm, double varf,
		long double zer_cink, char *str);
char					*preci_positif_f(t_param *prm, long double zer_cink,
		t_float *flt, double varf);

#endif
