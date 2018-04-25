/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2i_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:01:12 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/25 16:01:14 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_math.h"

float		v2i_dot(t_vector2i v1, t_vector2i v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float		v2i_angle(t_vector2i v1, t_vector2i v2)
{
	return (acosf(v2i_dot(v1, v2) / (v2i_mag(v1) * v2i_mag(v2))) * 180.0 / PI);
}

float		v2i_mag(t_vector2i vec2i)
{
	return (sqrtf(vec2i.x * vec2i.x + vec2i.y * vec2i.y));
}
