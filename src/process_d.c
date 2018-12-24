/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_d.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 01:12:16 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 23:50:35 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		etape_neg(t_param *prm, long var)
{
	if (prm->type == 'x' || prm->type == 'X')
		var = check_diez(prm, var);
	if (prm->type != 'c')
		var = check_flags2(prm, var);
	if (prm->flags3 == 'z')
		var = check_flags_zer(prm, var);
	prm->preci2 = prm->preci;
	if ((prm->type != 'c'))
		var = check_preci(prm, var);
	prm->preci = prm->preci2;
	var = check_width(prm, var);
	if (prm->type != 'x' && prm->type != 'X')
		var = check_diez(prm, var);
}

void		etape_positif(t_param *prm, long var)
{
	if ((prm->type == 'x' || prm->type == 'X')
			&& (prm->flags == '0' || prm->flags2 == '0') && !prm->preci)
		var = check_diez(prm, var);
	var = check_width(prm, var);
	if ((prm->type != 'c'))
		var = check_flags2(prm, var);
	if (prm->flags3 == 'z')
		var = check_flags_zer(prm, var);
	if ((prm->type == 'x' || prm->type == 'X')
			&& ((prm->flags != '0' && prm->flags2 != '0') || prm->preci))
		var = check_diez(prm, var);
	if (prm->type != 'c')
		var = check_preci(prm, var);
	if (prm->type != 'x' && prm->type != 'X')
		var = check_diez(prm, var);
}

int			affiche_all(t_param *prm, long var)
{
	int flg;

	flg = 1;
	if (prm->var_type == 1 && ((prm->flags != '-' && prm->flags2 != '-')))
		ft_putnbrlong(var);
	else if (prm->var_type == 2 && ((prm->flags != '-' && prm->flags2 != '-')))
		ft_putnbr_u(var);
	else if (prm->type == 'u' && prm->flags != '-' && prm->flags2 != '-')
		prm = typee_u(var, prm);
	else if (prm->type == 'U')
		prm->len += ft_putnbr_uu(var);
	else if ((prm->type == 'o' || prm->type == 'O') && prm->temp != 1)
		prm = typee_o(var, prm);
	else if ((prm->type == 'x' || prm->type == 'X') && prm->temp != 1)
		prm = typee_x(var, prm);
	else
		flg = 0;
	return (flg);
}

void		affiche_all2(t_param *prm, long var)
{
	if (affiche_all(prm, var) == 0)
	{
		if (prm->type == 'c' && prm->temp != 1)
		{
			prm->len++;
			ft_putchar(var);
		}
		else if ((prm->flags != '-' && prm->flags2 != '-')
				|| (!prm->width && (prm->flags == '-' || prm->flags2 == '-')))
		{
			if (!prm->width && (prm->flags == '+' || prm->flags2 == '+')
					&& (prm->flags == '-' || prm->flags2 == '-'))
				ft_putchar('+');
			if (prm->temp != 1)
			{
				if (prm->var_type == 6)
					ft_putnbr_hhu(var);
				else if (prm->type == 'u')
					ft_putnbr_u(var);
				else
					ft_putnbr(var);
			}
		}
	}
}

long		process_d(t_param *prm, long var)
{
	int		flag;

	prm->j = 0;
	flag = 0;
	if (prm->flags == '-' && prm->flags2 == '0')
		prm->flags2 = 0;
	else if (prm->flags2 == '-' && prm->flags == '0')
		prm->flags = 0;
	if ((prm->flags == '-' || prm->flags2 == '-'))
		etape_neg(prm, var);
	else
		etape_positif(prm, var);
	if (!(prm->preci < 0 && var == 0))
		affiche_all2(prm, var);
	else if (prm->type == 'c')
		affiche_all2(prm, var);
	else if (prm->type == 'u')
		prm->len--;
	if (prm->var_type == 2)
		prm->len += ft_nbrlen(var);
	return (var);
}
