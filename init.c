/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 18:58:51 by bnizard           #+#    #+#             */
/*   Updated: 2015/08/27 18:58:52 by bnizard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophe.h"

void	diplay_life(void)
{
	SDL_Surface r[7];
	int			val;

	val = SDL_HWSURFACE;
	r[0] = *SDL_CreateRGBSurface(val, A * g_e.vie[0], 10, 32, 0, 0, 0, 0);
	r[1] = *SDL_CreateRGBSurface(val, A * g_e.vie[1], 10, 32, 0, 0, 0, 0);
	r[2] = *SDL_CreateRGBSurface(val, A * g_e.vie[2], 10, 32, 0, 0, 0, 0);
	r[3] = *SDL_CreateRGBSurface(val, A * g_e.vie[3], 10, 32, 0, 0, 0, 0);
	r[4] = *SDL_CreateRGBSurface(val, A * g_e.vie[4], 10, 32, 0, 0, 0, 0);
	r[5] = *SDL_CreateRGBSurface(val, A * g_e.vie[5], 10, 32, 0, 0, 0, 0);
	r[6] = *SDL_CreateRGBSurface(val, A * g_e.vie[6], 10, 32, 0, 0, 0, 0);
	SDL_FillRect(&r[0], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_FillRect(&r[1], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_FillRect(&r[2], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_FillRect(&r[3], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_FillRect(&r[4], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_FillRect(&r[5], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_FillRect(&r[6], NULL, SDL_MapRGB(g_e.ecran->format, 255, 0, 0));
	SDL_BlitSurface(&r[0], NULL, g_e.ecran, &g_e.position_life[0]);
	SDL_BlitSurface(&r[1], NULL, g_e.ecran, &g_e.position_life[1]);
	SDL_BlitSurface(&r[2], NULL, g_e.ecran, &g_e.position_life[2]);
	SDL_BlitSurface(&r[3], NULL, g_e.ecran, &g_e.position_life[3]);
	SDL_BlitSurface(&r[4], NULL, g_e.ecran, &g_e.position_life[4]);
	SDL_BlitSurface(&r[5], NULL, g_e.ecran, &g_e.position_life[5]);
	SDL_BlitSurface(&r[6], NULL, g_e.ecran, &g_e.position_life[6]);
}

void	display(void)
{
	SDL_BlitSurface(&g_e.img[g_e.etat[0]], NULL, g_e.ecran, &g_e.position[0]);
	SDL_BlitSurface(&g_e.img[g_e.etat[1]], NULL, g_e.ecran, &g_e.position[1]);
	SDL_BlitSurface(&g_e.img[g_e.etat[2]], NULL, g_e.ecran, &g_e.position[2]);
	SDL_BlitSurface(&g_e.img[g_e.etat[3]], NULL, g_e.ecran, &g_e.position[3]);
	SDL_BlitSurface(&g_e.img[g_e.etat[4]], NULL, g_e.ecran, &g_e.position[4]);
	SDL_BlitSurface(&g_e.img[g_e.etat[5]], NULL, g_e.ecran, &g_e.position[5]);
	SDL_BlitSurface(&g_e.img[g_e.etat[6]], NULL, g_e.ecran, &g_e.position[6]);
}

void	ft_init_pictures(void)
{
	g_e.position[0].x = 600;
	g_e.position[0].y = 50;
	g_e.position[1].x = 750;
	g_e.position[1].y = 250;
	g_e.position[2].x = 600;
	g_e.position[2].y = 450;
	g_e.position[3].x = 450;
	g_e.position[3].y = 600;
	g_e.position[4].x = 300;
	g_e.position[4].y = 450;
	g_e.position[5].x = 150;
	g_e.position[5].y = 250;
	g_e.position[6].x = 300;
	g_e.position[6].y = 50;
}

void	ft_init_life(void)
{
	g_e.position_life[0].x = 600;
	g_e.position_life[0].y = 50 + 95;
	g_e.position_life[1].x = 750;
	g_e.position_life[1].y = 250 + 95;
	g_e.position_life[2].x = 600;
	g_e.position_life[2].y = 450 + 95;
	g_e.position_life[3].x = 450;
	g_e.position_life[3].y = 600 + 95;
	g_e.position_life[4].x = 300;
	g_e.position_life[4].y = 450 + 95;
	g_e.position_life[5].x = 150;
	g_e.position_life[5].y = 250 + 95;
	g_e.position_life[6].x = 300;
	g_e.position_life[6].y = 50 + 95;
}

void	ft_mega_init(t_mutex *fourchette)
{
	ft_init_pictures();
	ft_init_life();
	SDL_Init(SDL_INIT_VIDEO);
	g_e.ecran = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Philosophes", NULL);
	g_e.img[2] = *SDL_LoadBMP("images/eat.bmp");
	g_e.img[0] = *SDL_LoadBMP("images/sleep.bmp");
	g_e.img[1] = *SDL_LoadBMP("images/fourchettte.bmp");
	ft_init(fourchette);
	SDL_Init(SDL_INIT_VIDEO);
}
