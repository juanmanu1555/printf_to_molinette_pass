#include "ft_printf.h"

char    *ft_strinv(char *s1)
{
    long long int len;
    char *s2;
    size_t j;

    j = 0;
    len = ft_strlen(s1);
    if (!(s2 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
    while (len > 0)
    {
        s2[j] = s1[len - 1];
        j++;
        len--;
    }
    s2[j] = 0;
    return (s2);
}

char *ft_utohex(unsigned long int numb, char flag)
{
	char *s1;
	char *s2;
	unsigned long int res;
	unsigned long int div;
	char *hexa_array;
	int j;

	if (numb == 0)
	{
		s1 = malloc(2);
		s1[0] = '0';
		s1[1] = '\0';
		return (s1);
	}
	if (!(s1 = (char *)malloc((8 + 1) * sizeof(char))))
		return (NULL);
	res = numb;
	div = 0;
	j = 0;

	if (flag == 'x' || flag == 'p')
		hexa_array = ft_strdup("0123456789abcdef");
	else if (flag == 'X')
		hexa_array = ft_strdup("0123456789ABCDEF");
	while (res > 0)
	{
		if (numb > 15)
		{
			div = numb % 16;
			numb /= 16;
			s1[j] = hexa_array[div];
			res = numb;
		}
		else
		{
			div = numb;
			s1[j] = hexa_array[div];
			res = 0;
		}

		j++;
	}
	s1[j] = '\0';
	s2 = ft_strinv(s1);
	free(s1);
	return (s2);
}

void print_arg_with_minus_true(t_config *config, t_data_config *data_config, int ceros) 
{
    int z;
    int j;

    j = 0;
    z = 0;
       
    while (ceros > 0)
    {
        ft_putchar('0');
        ceros--;
        z++;
    }
    if (config->precision > 0)
    {
        if (config->flag == 'p')
        {
            ft_putchar('0');
            ft_putchar('x');
        }
        while (j < data_config->len)
        {
            ft_putchar(data_config->string_to_print[j]);
            j++;
        }
    }        
    z = 0;
    data_config->len =  config->flag == 'p' ? (config->width - config->precision - 2) : (config->width -config->precision);
    while (z < data_config->len)
    {
        ft_putchar(config->width_char);
        z++;
    }
}

void print_arg_with_minus_false(t_config *config, t_data_config *data_config, int ceros) 
{
    int z;
    int j;
    int len_width_char;

    j = 0;
    z = 0;
    len_width_char =  config->flag == 'p' ? (config->width - config->precision - 2) : (config->width -config->precision);

    while (z < len_width_char)
    {
        ft_putchar(config->width_char);
        z++;
    }
    if (config->flag == 'p')
    {
        ft_putchar('0');
        ft_putchar('x');
    }
    z = 0;
    while (ceros > 0)
    {
        ft_putchar('0');
        ceros--;
    }   
    if (config->precision > 0)
    {
        while (j < data_config->len)
        {
            ft_putchar(data_config->string_to_print[j]);
            j++;                    
        }
    }
}

void is_numb_negative(unsigned long int *numb, int *is_negative) 
{
    *numb = 400;
    *is_negative = 44;
    // if (*numb < 0)
    // {
    //     *numb *= -1;
    //     *is_negative = 1;
    // }
}