/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:04:09 by maginist          #+#    #+#             */
/*   Updated: 2019/03/19 18:11:18 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"
#include <stdio.h>
#include <stdlib.h>

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;
	int		i;
	int		j;
	if (!(tab) || !(tab[0]) || !(tab[0][0]))
		return ;
	if (begin.x >= size.x || begin.y >= size.y)
		return ;
	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == c)
			{
				if ((j > 0 && tab[j - 1][i] == 'F') || (j < size.y - 1 && tab[j + 1][i] == 'F') || (i > 0 && tab[j][i - 1] == 'F') || (i < size.x - 1 && tab[j][i + 1] == 'F'))
				{
					tab[j][i] = 'F';
					i = 0;
					j = 0;
				}
				else
					i++;
			}
			else
				i++;
		}
		j++;
	}
}

int main(void)
{
	char	**area;
	int		l;
	int		j;
	int i;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};
	i = 0;
	l = 0;
	if (!(area = (char**)malloc(sizeof(char*) * (size.y + 1))))
		return (0);
	area[size.y] = 0;
	while (l < size.y)
	{
		if (!(area[l] = (char*)malloc(sizeof(char) * (size.x + 1))))
			return (0);
		area[l][size.x] = '\0';
		l++;
	}
	while (zone[i])
	{
		j = 0;
		while (zone[i][j])
		{
			area[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	flood_fill(area, size, begin);
	while (area[i])
	{
		printf("%s\n", area[i]);
		i++;
	}
	return (0);
}
