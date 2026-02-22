/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 01:56:12 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 01:56:13 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// failmalloc.c
#include <stdlib.h>

void	*malloc(size_t size)
{
	return (NULL);
}

// static int count = 0;

// void *malloc(size_t size) {
//     if (++count == 3)
//         return (NULL);
//     return (__builtin_malloc(size));
// }