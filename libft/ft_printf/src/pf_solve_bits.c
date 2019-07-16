/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 04:28:23 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/16 16:28:20 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	solve_bits(t_ftask *ftask, va_list *args)
{
	t_res	res;

	res.len = 0;
	if ((res.str = ft_btoa((unsigned long)va_arg(*args, unsigned long),
	(ftask->prc == -1) ? ftask->size.value * 8
	: ftask->prc, ftask->flags.sharp)))
	{
		res.len = ft_strlen(res.str);
		if (ftask->width > res.len)
			set_width(&res, ftask, ' ');
	}
	else
		res.len = -1;
	return (res);
}
