/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 20:41:01 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 20:59:32 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long	check_l(t_param *prm, long var, va_list list)
{
	if (prm->type == 'u')
	{
		prm->var_type = 5;
		var = va_arg(list, unsigned long);
	}
	else if (prm->type == 'o')
	{
		prm->var_type = 12;
		var = (unsigned long)va_arg(list, unsigned long);
	}
	else if (prm->type == 'x' || prm->type == 'X')
	{
		prm->var_type = 21;
		var = (unsigned long)va_arg(list, unsigned long);
	}
	else if (ft_strchr("di", prm->type))
	{
		prm->var_type = 80;
		var = va_arg(list, long);
	}
	else
		var = va_arg(list, long long);
	return (var);
}

long	check_h(t_param *prm, long var, va_list list)
{
	if (prm->type == 'o')
	{
		prm->var_type = 11;
		var = (unsigned short)va_arg(list, unsigned long);
	}
	else if (prm->type == 'x' || prm->type == 'X')
	{
		prm->var_type = 22;
		var = (unsigned short)va_arg(list, unsigned long);
	}
	else if (ft_strchr("di", prm->type))
	{
		prm->var_type = 81;
		var = (short)va_arg(list, long);
	}
	else
		var = (short)va_arg(list, long);
	if (prm->type == 'u')
		prm->var_type = 7;
	return (var);
}

long	check_ll(t_param *prm, long var, va_list list)
{
	var = va_arg(list, unsigned long long);
	if (prm->type == 'd' || prm->type == 'i')
		prm->var_type = 82;
	if (prm->type == 'u')
		prm->var_type = 3;
	if (prm->type == 'o')
		prm->var_type = 13;
	if (prm->type == 'x' || prm->type == 'X')
		prm->var_type = 23;
	return (var);
}

long	check_hh(t_param *prm, long var, va_list list)
{
	if (prm->type == 'x' || prm->type == 'X')
	{
		prm->var_type = 24;
		var = (unsigned char)va_arg(list, unsigned long);
	}
	else if (prm->type == 'u')
	{
		var = (char)va_arg(list, long);
		prm->var_type = 6;
	}
	else if (prm->type == 'o')
	{
		prm->var_type = 14;
		var = (unsigned char)va_arg(list, unsigned long);
	}
	else if (ft_strchr("di", prm->type))
	{
		prm->var_type = 83;
		var = (char)va_arg(list, long);
	}
	else
		var = (char)va_arg(list, long);
	return (var);
}

long	type(t_param *prm, long var, va_list list)
{
	if (prm->size)
	{
		if (prm->size[1] == '\0')
		{
			if (prm->size[0] == 'l'
					|| prm->size[0] == 'j' || prm->size[0] == 'z')
				var = check_l(prm, var, list);
			else if (prm->size[0] == 'z')
				var = va_arg(list, size_t);
			else if (prm->size[0] == 'h')
				var = check_h(prm, var, list);
		}
		else if (prm->size[0] == 'l' && prm->size[1] == 'l')
			var = check_ll(prm, var, list);
		else if (prm->size[0] == 'h' && prm->size[1] == 'h')
			var = check_hh(prm, var, list);
	}
	else if (prm->size[0] == 'z')
	{
		var = (long)va_arg(list, long);
		prm->var_type = 80;
	}
	else if (prm->type == 'D')
		var = va_arg(list, long);
	return (var);
}
