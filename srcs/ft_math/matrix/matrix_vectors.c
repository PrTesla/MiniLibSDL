/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vectors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:00:54 by dbirge-c          #+#    #+#             */
/*   Updated: 2018/04/26 16:00:55 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_math/matrix.h"

/*
** Applies a matrix on a point
*/

t_vector3d	m_pt_apply(const t_vector3d v, const t_matrix m)
{
	t_vector3d	vec;
	float		w;

	vec.x = v.x * m.m[0][0] + v.y * m.m[0][1] + v.z * m.m[0][2] + m.m[0][3];
	vec.y = v.x * m.m[1][0] + v.y * m.m[1][1] + v.z * m.m[1][2] + m.m[1][3];
	vec.z = v.x * m.m[2][0] + v.y * m.m[2][1] + v.z * m.m[2][2] + m.m[2][3];
	w = v.x * m.m[3][0] + v.y * m.m[3][1] + v.z * m.m[3][2] + m.m[3][3];
	if (w != 0 && w != 1)
		v3d_scale(vec, w);
	return (vec);
}

/*
** Applies a matrix on a vector
*/

t_vector3d	m_vec_apply(const t_vector3d v, const t_matrix m)
{
	t_vector3d	vec;

	vec.x = v.x * m.m[0][0] + v.y * m.m[0][1] + v.z * m.m[0][2];
	vec.y = v.x * m.m[1][0] + v.y * m.m[1][1] + v.z * m.m[1][2];
	vec.z = v.x * m.m[2][0] + v.y * m.m[2][1] + v.z * m.m[2][2];
	return (vec);
}

/*
** Gets the position from a matrix
*/

t_vector3d	m_to_pos(const t_matrix m)
{
	t_vector3d	v;

	v.x = m.m[0][3];
	v.y = m.m[1][3];
	v.z = m.m[2][3];
	return (v);
}

/*
** Gets the scale from a matrix
*/

t_vector3d	m_to_scale(const t_matrix m)
{
	t_vector3d	v;

	v.x = m.m[0][0];
	v.y = m.m[1][1];
	v.z = m.m[2][2];
	return (v);
}

t_vector3d	m_to_rot(const t_matrix m)
{
	t_vector3d	v;
	double		sy;

	sy = sqrt(m.m[0][0] * m.m[0][0] + m.m[0][1] * m.m[0][1]);
	if (!(sy < 1e-6))
	{
		v.x = atan2(m.m[1][2], m.m[2][2]);
		v.y = atan2(-m.m[0][2], sy);
		v.z = atan2(m.m[0][1], m.m[0][0]);
	}
	else
	{
		v.x = atan2(-m.m[2][1], m.m[1][1]);
		v.y = atan2(-m.m[0][2], sy);
		v.z = 0;
	}
	return (v);
}
