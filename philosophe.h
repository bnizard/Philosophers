/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:59:14 by bnizard           #+#    #+#             */
/*   Updated: 2015/05/27 15:59:15 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHE_H
# define PHILOSOPHE_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL/SDL.h>

# define MAX_LIFE 5
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 100
# define PHILO 7
# define A (85 / MAX_LIFE)

typedef struct	s_env
{
	int			vie[PHILO];
	int			etat[PHILO];
	int			i;
	SDL_Rect	position[7];
	SDL_Rect	position_life[7];
	SDL_Surface	img[3];
	SDL_Surface	*ecran;
}				t_env;

struct s_env	g_e;

typedef struct	s_mutex
{
	pthread_mutex_t mutex[PHILO];
}				t_mutex;

void			ft_loose_life(void);
void			ft_loop(int i);
int				main(int argc, char *argv[]);
void			ft_manage1(int z, t_mutex *fourchette);
void			ft_manage2(int z, t_mutex *fourchette);
void			ft_manage3(int z, t_mutex *fourchette);
void			ft_manage4(int z, t_mutex *fourchette);
void			*task(void *arg);
void			diplay_life(void);
void			display(void);
void			ft_init_pictures(void);
void			ft_init_life(void);
void			ft_mega_init(t_mutex *fourchette);
void			event();
void			print_philo(int j);
void			ft_init(t_mutex *fourchette);
void			ft_putchar(char c);
void			ft_putnbr(int n);

#endif
