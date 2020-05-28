#include "ft_printf.h"

int regex_validate(int *index, char *s1, t_config *config)
{
    if (s1[*index] == '0' || s1[*index] == '-')
    {    
        if (!(validate_cero_or_minus(index, s1, config)))
            return (0);
       
    }
    
    if (s1[*index] == '*')
    {
        config->is_width_arg = 1;
        *index += 1;
    }
    else
    {      
        if (s1[*index] >= '1' && s1[*index] <= '9')
        { 
            if (!(validate_width(index, s1, config)))
                return (0);
        }
    }
    if (s1[*index] == '.')
    {
        *index += 1;
        config->precision = 0;
        if (s1[*index] == '*')
        {
            config->is_precision_arg = 1;
            *index += 1;
        }
        else if (s1[*index] && (s1[*index] >= '0' && s1[*index] <= '9'))
        {
            if (!(validate_precision(index, s1, config)))
                return (0);
        }
        else
        {
            if (!(validate_flag(index, s1, config)))
                return (0);
            return (1);
        }

    }
    if (!(validate_flag(index, s1, config)))
        return (0);
    return (1);
}

int ft_transform_arg(int *index, char *s1, t_config *config, va_list *args) 
{    
    if (regex_validate(index, s1, config) == 1)
    {         
            // if (config->flag == 's')
            //     printf_arg_str(config, args);
            // if (config->flag == 'd' || config->flag == 'i')
            //     printf_arg_int(config, args);
            // if (config->flag == 'u')
            //     printf_arg_unsigned_int(config, args);
            if (config->flag == 'x' || config->flag == 'X' || config->flag == 'p')
                printf_arg_hex(config, args);
            return config->width;
    } 
    else 
        return (-1);
    return (0);
}


int ft_transform_data(char *s1, t_config *config, va_list *args)
{
    int index;
    int arg_count;

    arg_count = 0;
    while (s1[index])
    {
        if (s1[index] == '%')
        {
            index++;
            arg_count++;
            config->resp_transf_arg = ft_transform_arg(&index, s1, config, args);    
            if (config->resp_transf_arg == -1)
               return (config->total_width - arg_count + 1);
            config->total_width  += config->resp_transf_arg;
            *config = t_config_default;
        }
        else
           ft_putchar(s1[index]);
        index++;
        config->total_width += 1;
    }
    return (config->total_width  - arg_count);
}



int ft_printf(const char *s1, ...)
{ 
    int total;
    t_config config;

    total = 0;
    config = t_config_default;
    va_list args;
    va_start(args, s1);
    total = ft_transform_data((char *)s1, &config, &args);
    va_end(args);
    return (total);
}