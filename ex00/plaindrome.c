#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char	*dup_rev(char *s)
{
	int		i;
	int		j;
	char	*rev;

	if (!s)
		return (NULL);
	rev = calloc(strlen(s) + 1, sizeof(char));
	if (!rev)
		return (NULL);
	i = -1;
	j = strlen(s) - 1;
	while (s[++i])
		rev[i] = s[j--];
	return (rev);
}

bool	is_plaindrome(char *s)
{
	char	*rev;
	bool	res;

	if (!s)
		return (false);
	rev = dup_rev(s);
	res = !strncmp(s, rev, strlen(s));
	free(rev);
	return (res);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (is_plaindrome(av[1]))
		printf("\"%s\" is a plaindrome\n", av[1]);
	else
		printf("\"%s\" is not a plaindrome\n", av[1]);
	return (0);	
}