/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prog_float2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 18:48:37 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 04:29:41 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*preci_positif_f(t_param *prm, long double zer_cink,
		t_float *flt, double varf)
{
	char *str;

	str = NULL;
	if (prm->preci > 0)
	{
		str = init_str(prm, zer_cink, varf);
		str = arrondi_f(str, prm);
		c_str(prm, varf, flt);
		ft_putstr(str);
		prm->len += ft_strlen(str);
	}
	else
		c_str(prm, varf, flt);
	return (str);
}

char	*preci_f2(t_param *prm, double varf, long double zer_cink, char *str)
{
	int			x;
	t_float		*flt;

	if (!(flt = (t_float*)malloc(sizeof(t_float))))
		return (NULL);
	flt->tmp = 0;
	x = 0;
	if (prm->preci)
		str = preci_positif_f(prm, zer_cink, flt, varf);
	else
	{
		prm->preci = 6;
		str = init_str(prm, zer_cink, varf);
		x = -1;
		prm->len += ft_putnbr_lf((long double)varf, flt);
		if (varf < 0)
			prm->len++;
		ft_putchar('.');
		while (++x < 6)
			ft_putchar(str[x]);
		prm->len += 6;
	}
	free(flt);
	return (str);
}
