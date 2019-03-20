#include "vector.h"
#include "libft.h"

int		vector_del_elem(void **vector, size_t i)
{
	size_t	*arr1;
	size_t	*arr2;
	size_t	*arr;
	size_t	size;

	arr = (size_t *)(*vector);
	if (i >= arr[2])
		return (1);
	if (i == arr[2] - 1)
		return (vector_pop_back(vector));
	arr1 = (size_t *)((char *)(arr + 3) + arr[0] * i);
	arr2 = (size_t *)((char *)(arr + 3) + arr[0] * (i + 1));
	size = arr[0] * (arr[2] - i - 1);
	ft_memmove((void *)arr1, (void *)arr2, size);
	arr[2]--;
	return (1);
}
