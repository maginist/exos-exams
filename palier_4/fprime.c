/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:15:38 by maginist          #+#    #+#             */
/*   Updated: 2019/04/01 13:42:47 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		nb;
	int		p;

	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	p = 2;
	nb = atoi(av[1]);
	if (nb == 1)
	{
		printf("1\n");
		return (0);
	}
	if (nb == 0)
	{
		printf("0\n");
		return (0);
	}
	if (nb < 1)
		return (0);
	while (p <= nb)
	{
		if (nb % p == 0)
		{
			printf("%d", p);
			if (p == nb)
			{
				printf("\n");
				return (0);
			}
			printf("*");
			nb = nb / p;
			p = 1;
		}
		p++;
	}
	return (0);
}
