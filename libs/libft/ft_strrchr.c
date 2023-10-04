#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

// int main(void)
// {
//     char str[13] = "Hello World";
//     char c = 'r';
//     printf("%s\n", ft_strrchr(str, c)); // rld
//     return 0;
// }