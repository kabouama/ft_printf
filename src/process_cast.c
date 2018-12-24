/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_cast.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:03:25 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 18:38:14 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long			process_dsp(t_param *prm, va_list list, long var)
{
	if (ft_strchr("diD", prm->type))
	{
		if (prm->size)
			var = type(prm, var, list);
		else if (prm->type == 'i' || prm->type == 'd')
			var = va_arg(list, int);
		else if (prm->type == 'D')
			var = va_arg(list, long);
		process_dd(prm, var, 0);
	}
	else if (ft_strchr("p", prm->type))
	{
		var = va_arg(list, unsigned long);
		prm->var_type = 50;
		process_p(prm, var);
	}
	else if (prm->type == '%')
		process_percent(prm);
	return (var);
}

long			process_oxc(t_param *prm, va_list list, long var)
{
	if (prm->type == 'U')
	{
		var = va_arg(list, unsigned long long);
		prm->var_type = 3;
	}
	else if (prm->type == 'o' || prm->type == 'O')
	{
		var = va_arg(list, int);
		prm->var_type = 10;
	}
	else if (prm->type == 'x' || prm->type == 'X')
	{
		var = va_arg(list, unsigned int);
		prm->var_type = 20;
	}
	else if (prm->type == 'c')
	{
		var = va_arg(list, int);
		prm->var_type = 30;
	}
	return (var);
}

long			process_other(t_param *prm, va_list list, long var)
{
	if (prm->size || prm->type == 'D')
	{
		prm->var_type = 1;
		var = type(prm, var, list);
	}
	else if (prm->type == 'i' || prm->type == 'd')
		var = va_arg(list, int);
	else if (prm->type == 'u')
	{
		prm->var_type = 2;
		var = va_arg(list, unsigned int);
	}
	else
		var = process_oxc(prm, list, var);
	process_d(prm, var);
	return (var);
}

long double		process_f(t_param *prm, va_list list, long double varf)
{
	if (prm->size && prm->size[0] == 'L' && prm->size[1] == '\0')
		varf = (long double)va_arg(list, long double);
	else
		varf = (long double)va_arg(list, double);
	process_dd(prm, 0, varf);
	return (varf);
}

t_param			*process(t_param *prm, t_stock *stck, va_list list)
{
	long			var;
	char			*var_s;
	long double		varf;

	var = 0;
	var_s = NULL;
	varf = 0;
	prm->var_type = 0;
	actu_param(prm, stck);
	prm->len_o = 0;
	if (ft_strchr("uUoOxXc", prm->type))
		var = process_other(prm, list, var);
	else if (ft_strchr("s", prm->type))
	{
		var_s = va_arg(list, char *);
		prm->var_type = 40;
		process_s(prm, var_s);
	}
	else if (prm->type == 'f' || prm->type == 'F')
		varf = process_f(prm, list, varf);
	if (ft_strchr("diDp%", prm->type))
		var = process_dsp(prm, list, var);
	return (prm);
}
