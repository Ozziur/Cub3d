///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   raycast_calc.c                                     :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2023/01/23 18:42:27 by mruizzo           #+#    #+#             */
///*   Updated: 2023/01/24 13:49:05 by mruizzo          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */

//#include "../../incl/cub3d.h"

///*Questa funzione statica definisce i valori del raggio e dell'offset per un raggio che colpisce i muri verticali. La funzione prende in input un puntatore alla struttura dati "t_rules", un puntatore alla struttura dati "t_ray", un valore double chiamato "n_tan" e un array di float chiamato "xy".
//La funzione utilizza una condizione if per determinare se l'angolo del raggio è inferiore a M_PI/2 o maggiore di 3M_PI/2. In caso affermativo, imposta il valore x del raggio come la posizione x del giocatore più la larghezza del blocco (che è l'altezza del muro) meno il valore restituito dalla funzione "our_modulo" (che fornisce il resto della divisione tra la posizione x del giocatore e la larghezza del blocco).
//Imposta il valore y del raggio come la posizione y del giocatore meno (la posizione x del giocatore meno il valore x del raggio) moltiplicato per la tangente negativa.
//Imposta i valori dell'offset x e y come la larghezza del blocco e la larghezza del blocco moltiplicato per la tangente negativa.
//In caso contrario, se l'angolo del raggio è maggiore o uguale a M_PI/2 e minore o uguale a 3M_PI/2, imposta il valore x del raggio come la posizione x del giocatore meno il valore restituito dalla funzione "our_modulo" (che fornisce il resto della divisione tra la posizione x del giocatore e la larghezza del blocco).
//Imposta il valore y del raggio come la posizione y del giocatore meno (la posizione x del giocatore meno il valore x del raggio) moltiplicato per la tangente negativa.
//Imposta i valori dell'offset x e y come -larghezza del blocco e -larghezza del blocco moltiplicato per la tangente negativa.
//Infine, la funzione restituisce 0 in caso di angolo del raggio inferiore a M_PI/2 o maggiore di 3*M_PI/2 e 1 in caso contrario.
//In sintesi, questa funzione calcola la posizione iniziale di un raggio virtuale che colpisce i muri verticali, e definisce i valori dell'offset x e y utilizzati per aggiornare la posizione del raggio durante il controllo delle collisioni.*/
//static int	define_ver_ray_and_offset(t_rules *rules, t_ray *ray,
//	double n_tan, float xy[2])
//{
//	if (ray->angle < M_PI / 2 || ray->angle > 3 * M_PI / 2)
//	{
//		ray->x = xy[0] + (rules->inpmap.block_width - our_modulo(xy[0],
//					rules->inpmap.block_width));
//		ray->y = xy[1] - (xy[0] - ray->x) * n_tan;
//		ray->xyoff[0] = rules->inpmap.block_width;
//		ray->xyoff[1] = ray->xyoff[0] * n_tan;
//		return (0);
//	}
//	else if (ray->angle >= M_PI / 2 && ray->angle <= 3 * M_PI / 2)
//	{
//		ray->x = xy[0] - our_modulo(xy[0], rules->inpmap.block_width);
//		ray->y = xy[1] - (xy[0] - ray->x) * n_tan;
//		ray->xyoff[0] = -rules->inpmap.block_width;
//		ray->xyoff[1] = ray->xyoff[0] * n_tan;
//		return (1);
//	}
//	return (0);
//}

///*Questo codice rappresenta una funzione statica che controlla le linee verticali per il calcolo del raggio. La funzione prende in input un angolo double chiamato "angle", un puntatore a una struttura dati chiamata "t_rules" e un array di float chiamato "ret" che verrà utilizzato per archiviare i punti calcolati.
//La funzione utilizza una struttura dati chiamata "t_ray" per archiviare informazioni sul raggio, come l'angolo.
//La funzione calcola anche il valore tangente negativo dell'angolo del raggio e utilizza una funzione chiamata "define_ver_ray_and_offset" per definire i valori del raggio e dell'offset.
//Quindi, utilizza un ciclo while per controllare se il raggio sta andando a collidere con un muro virtuale utilizzando la funzione "virtual_vertical_colliding". Se non c'è collisione e l'angolo del raggio non è M_PI/2 o 3*M_PI/2 e l'ascissa non è INT_MAX, allora il ciclo continua e aggiorna la posizione del raggio utilizzando i valori dell'offset.
//Infine, la funzione assegna i valori finali di x e y del raggio all'array di float "ret" e restituisce l'array come risultato.
//In sintesi, questa funzione calcola i punti in cui un raggio virtuale colpisce i muri verticali della mappa.*/
//static void	vertical_lines_check(double angle,	t_rules *rules, float ret[3])
//{
//	t_ray	ray;
//	double	n_tan;
//	float	xy[2];

//	xy[0] = rules->player.x;
//	xy[1] = rules->player.y;
//	ray.angle = angle;
//	n_tan = -tan(ray.angle);
//	ret[2] = define_ver_ray_and_offset(rules, &ray, n_tan, xy);
//	while (!virtual_vertical_colliding(ray.x, ray.y, rules, ret[2])
//		&& ray.angle != (double) M_PI / 2
//		&& ray.angle != (double)(3 * M_PI / 2) && ray.x != INT_MAX)
//	{
//		ray.x += ray.xyoff[0];
//		ray.y += ray.xyoff[1];
//	}
//	ret[0] = ray.x;
//	ret[1] = ray.y;
//}

//static int	define_hor_ray_and_offset(t_rules *rules, t_ray *ray,
//	double co_tan, float xy[2])
//{
//	if (ray->angle < M_PI)
//	{
//		ray->y = xy[1] - (rules->inpmap.block_width - (rules->inpmap.block_width
//					- our_modulo(xy[1], rules->inpmap.block_width)));
//		ray->x = (xy[1] - ray->y) * co_tan + xy[0];
//		ray->xyoff[1] = -rules->inpmap.block_width;
//		ray->xyoff[0] = -ray->xyoff[1] * co_tan;
//		return (0);
//	}
//	else
//	{
//		ray->y = xy[1] + (rules->inpmap.block_width - our_modulo(xy[1],
//					rules->inpmap.block_width));
//		ray->x = (xy[1] - ray->y) * co_tan + xy[0];
//		ray->xyoff[1] = rules->inpmap.block_width;
//		ray->xyoff[0] = -ray->xyoff[1] * co_tan;
//		return (1);
//	}
//}

///*Questo codice rappresenta una funzione statica che controlla le linee orizzontali per il calcolo del raggio. La funzione prende in input un angolo double chiamato "angle", un puntatore a una struttura dati chiamata "t_rules" e un array di float chiamato "ret" che verrà utilizzato per archiviare i punti calcolati.
//La funzione utilizza una struttura dati chiamata "t_ray" per archiviare informazioni sul raggio, come l'angolo.
//La funzione calcola anche il valore tangente inverso dell'angolo del raggio e utilizza una funzione chiamata "define_hor_ray_and_offset" per definire i valori del raggio e dell'offset.
//Quindi, utilizza un ciclo while per controllare se il raggio sta andando a collidere con un muro virtuale utilizzando la funzione "virtual_horizontal_colliding". Se non c'è collisione e l'angolo del raggio non è 0 o M_PI e l'ascissa non è INT_MAX, allora il ciclo continua e aggiorna la posizione del raggio utilizzando i valori dell'offset.
//Infine, la funzione assegna i valori finali di x e y del raggio all'array di float "ret" e restituisce l'array come risultato.*/
//static void	horizontal_lines_check(double angle, t_rules *rules, float ret[3])
//{
//	t_ray	ray;
//	double	co_tan;
//	float	xy[2];

//	xy[0] = rules->player.x;
//	xy[1] = rules->player.y;
//	ray.angle = angle;
//	co_tan = 1 / tan(ray.angle);
//	ret[2] = define_hor_ray_and_offset(rules, &ray, co_tan, xy);
//	while (!virtual_horizontal_colliding(ray.x, ray.y, rules, ret[2])
//		&& ray.angle != 0 && ray.angle != (double)M_PI && ray.x != INT_MAX)
//	{
//		ray.x += ray.xyoff[0];
//		ray.y += ray.xyoff[1];
//	}
//	ret[0] = ray.x;
//	ret[1] = ray.y;
//}

///*Questo codice rappresenta una funzione che calcola un raggio per un gioco o un'applicazione di tipo "raycasting". La funzione prende in input tre parametri: un puntatore a una struttura dati chiamata "t_bres_data", un puntatore a una struttura dati chiamata "t_rules" e due puntatori a una struttura dati chiamata "t_image", uno per la visualizzazione e l'altro per la mappa minima.
//La funzione utilizza due array di float chiamati "f_pts" e "s_pts" per archiviare i punti calcolati dalle funzioni "horizontal_lines_check" e "vertical_lines_check".
//Successivamente, la funzione imposta i valori x e y del giocatore come i valori x e y per il primo punto del raggio.
//Quindi, utilizza una condizione if per determinare quale dei due array di punti (f_pts o s_pts) è più vicino al giocatore e utilizza quel punto come il secondo punto del raggio.
//Infine, la funzione utilizza la funzione "bresenham" per tracciare il raggio e decrementa l'angolo del raggio di 1.*/
//void	raycast_calc(t_bres_data *data, t_rules *rules,
//			t_image *view, t_image *minimap)
//{
//	float	h_pts[3];
//	float	v_pts[3];

//	horizontal_lines_check(data->ray_angle, rules, h_pts);
//	vertical_lines_check(data->ray_angle, rules, v_pts);
//	data->xy[0] = rules->player.x;
//	data->xy[1] = rules->player.y;
//	if (final_length(rules->player.x, rules->player.y, v_pts) == INT_MAX
//		|| final_length(rules->player.x, rules->player.y, h_pts)
//		< final_length(rules->player.x, rules->player.y, v_pts))
//	{
//		data->xy2[0] = h_pts[0];
//		data->xy2[1] = h_pts[1];
//		bresenham(data, minimap, view, rules);
//	}
//	else
//	{
//		data->xy2[0] = v_pts[0];
//		data->xy2[1] = v_pts[1];
//		bresenham(data, minimap, view, rules);
//	}
//	data->ray_angle = decrement_angle(data->ray_angle, 1);
//}
