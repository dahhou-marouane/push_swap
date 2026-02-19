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