/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:20:50 by maginist          #+#    #+#             */
/*   Updated: 2019/04/15 17:28:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	use_prime(int p, int nb)
{
	while (p <= nb)
	{
		if (nb % p == 0)
		{
			printf("%d", p);
			if (p == nb)
			{
				printf("\n");
				return ;
			}
			printf("*");
			nb = nb / p;
			p = 1;
		}
		p++;
	}
}

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
	if (nb < 1)
		return (0);
	if (nb == 0)
	{
		printf("0\n");
		return (0);
	}
	use_prime(p, nb);
	return (0);
}
