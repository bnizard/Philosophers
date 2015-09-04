/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:36:56 by bnizard           #+#    #+#             */
/*   Updated: 2015/05/27 14:36:57 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

void	ft_loose_life(void)
{
	int i;

	i = -1;
	while (++i < PHILO)
	{
		if (g_e.vie[i] - 1 <= 0)
		{
			write(1, "Philo ", 6);
			ft_putnbr(i + 1);
			write(1, " mort\n", 7);
			while (42)
				event();
			exit(0);
		}
		g_e.vie[i]--;
	}
}

void	ft_loop(int i)
{
	SDL_FillRect(g_e.ecran, NULL, SDL_MapRGB(g_e.ecran->format, 17, 206, 112));
	event();
	usleep(500000);
	event();
	usleep(500000);
	i++;
	display();
	diplay_life();
	print_philo(i);
	SDL_Flip(g_e.ecran);
	ft_loose_life();
	if (i >= TIMEOUT)
	{
		write(1, "Now, it is time... To DAAAAAAAANCE ! ! !\n", 42);
		while (42)
			event();
		SDL_Quit();
		exit(0);
	}
}

int		main(int argc, char *argv[])
{
	pthread_t		*threads;
	int				i;
	t_mutex			fourchette;

	(void)argc;
	(void)argv;
	threads = (pthread_t*)malloc(sizeof(pthread_t) * PHILO);
	ft_mega_init(&fourchette);
	i = -1;
	while (++i < PHILO)
		pthread_create(&threads[i], NULL, task, (void*)&fourchette);
	SDL_FillRect(g_e.ecran, NULL, SDL_MapRGB(g_e.ecran->format, 17, 206, 112));
	display();
	diplay_life();
	SDL_Flip(g_e.ecran);
	i = -1;
	while (42)
		ft_loop(i++);
	return (0);
}
