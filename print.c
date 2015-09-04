/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 19:00:08 by bnizard           #+#    #+#             */
/*   Updated: 2015/08/27 19:00:09 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

void	event(void)
{
	SDL_Event event;

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_SPACE)
	{
		SDL_Quit();
		exit(0);
	}
}

void	print_philo(int j)
{
	int i;

	i = -1;
	write(1, "--------------------", 20);
	ft_putnbr(j);
	write(1, "--------------------\n", 22);
	while (++i < PHILO)
	{
		write(1, "PHILO[", 6);
		ft_putnbr(i + 1);
		write(1, "] a ", 4);
		ft_putnbr(g_e.vie[i]);
		write(1, " points de vie et son etat est ", 31);
		ft_putnbr(g_e.etat[i]);
		write(1, "\n", 1);
	}
	write(1, "----------------------------------------\n", 42);
}

void	ft_init(t_mutex *fourchette)
{
	int	i;

	i = -1;
	while (++i < PHILO)
	{
		pthread_mutex_init(&fourchette->mutex[i], NULL);
		g_e.vie[i] = MAX_LIFE;
		g_e.etat[i] = 1;
	}
	g_e.i = 0;
}
