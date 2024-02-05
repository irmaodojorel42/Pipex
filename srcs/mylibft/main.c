#include "libft.h"

int main(void)
{
    char const  *s = "@ir@mao@do@jorel@42";
    char    **result;

    result = ft_split(s, '@');
    ft_printf("%p\n", result);
    ft_printf("%s\n", result[0]);
    ft_printf("%s\n", result[1]);
    ft_printf("%s\n", result[2]);
    ft_printf("%s\n", result[3]);
    ft_printf("%p\n", result[4]);
    return (0);
}