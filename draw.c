/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:48:59 by bnizard           #+#    #+#             */
/*   Updated: 2015/08/27 18:49:00 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

void	ft_manage1(int z, t_mutex *fourchette)
{
	int time;

	time = EAT_T;
	pthread_mutex_lock(&fourchette->mutex[z]);
	g_e.etat[z] = 1;
	pthread_mutex_lock(&fourchette->mutex[z + 1]);
	g_e.etat[z] = 2;
	g_e.vie[z] = MAX_LIFE;
	usleep(time * 1000000);
	g_e.etat[z] = 0;
	pthread_mutex_unlock(&fourchette->mutex[z]);
	pthread_mutex_unlock(&fourchette->mutex[z + 1]);
	usleep(10000);
}

void	ft_manage2(int z, t_mutex *fourchette)
{
	int time;

	time = EAT_T;
	pthread_mutex_lock(&fourchette->mutex[PHILO - 1]);
	g_e.etat[z] = 1;
	pthread_mutex_lock(&fourchette->mutex[0]);
	g_e.etat[z] = 2;
	g_e.vie[z] = MAX_LIFE;
	usleep(time * 1000000);
	g_e.etat[z] = 0;
	pthread_mutex_unlock(&fourchette->mutex[PHILO - 1]);
	pthread_mutex_unlock(&fourchette->mutex[0]);
	usleep(10000);
}

void	ft_manage3(int z, t_mutex *fourchette)
{
	int time;

	time = EAT_T;
	pthread_mutex_lock(&fourchette->mutex[z + 1]);
	g_e.etat[z] = 1;
	pthread_mutex_lock(&fourchette->mutex[z]);
	g_e.etat[z] = 2;
	g_e.vie[z] = MAX_LIFE;
	usleep(time * 1000000);
	g_e.etat[z] = 0;
	pthread_mutex_unlock(&fourchette->mutex[z + 1]);
	pthread_mutex_unlock(&fourchette->mutex[z]);
	usleep(10000);
}

void	ft_manage4(int z, t_mutex *fourchette)
{
	int time;

	time = EAT_T;
	pthread_mutex_lock(&fourchette->mutex[0]);
	g_e.etat[z] = 1;
	pthread_mutex_lock(&fourchette->mutex[PHILO - 1]);
	g_e.etat[z] = 2;
	g_e.vie[z] = MAX_LIFE;
	usleep(time * 1000000);
	g_e.etat[z] = 0;
	pthread_mutex_unlock(&fourchette->mutex[0]);
	pthread_mutex_unlock(&fourchette->mutex[PHILO - 1]);
	usleep(10000);
}

void	*task(void *arg)
{
	int		z;

	z = g_e.i;
	g_e.i++;
	while (42)
	{
		if (!(z % 2))
		{
			if (z != PHILO - 1)
				ft_manage1(z, (t_mutex*)arg);
			else
				ft_manage2(z, (t_mutex*)arg);
		}
		else
		{
			if (z != PHILO - 1)
				ft_manage3(z, (t_mutex*)arg);
			else
				ft_manage4(z, (t_mutex*)arg);
		}
	}
	return (NULL);
}
