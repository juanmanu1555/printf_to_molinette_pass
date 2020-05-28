#include "ft_printf.h"

void get_width_precision_from_va_args(t_config *config, va_list *args)
{
    if (config->is_width_arg == 1)
	{
		config->width = va_arg(*args, int);
		if (config->width < 0)
		{
			config->width *= -1;
			config->is_minus = 1;
		}
	}
	if (config->is_precision_arg == 1)
		config->precision = va_arg(*args, int);
}

void  print_arg_with_null_value(t_config *config, va_list *args)
{
    int precisionReal = 0;
    int spaces = 0;
    int z = 0;
  
        if (config->flag == 'p')
        {		
			if (config->precision == -1)
				precisionReal = 3;
			else if (config->precision == 0)
				precisionReal = 2;
			else if (config->precision > 0)
				precisionReal = (config->precision + 2); 
		
	        spaces = config->width - precisionReal;
            while(z < spaces)
            {
                ft_putchar(config->width_char);
                z++;
            }
            ft_putchar('0');
            ft_putchar('x');
			 z = 0;
			if (config->precision > 0)			
         	{	 
				 	if (config->width < config->precision)
						config->width = precisionReal;
				 
				  while (z < config->precision)
				  {
					  ft_putchar('0');
					  z++;
				  }
			} 
			else if (config->precision == -1)
			{
				ft_putchar('0');
				if (config->width < 3)
						config->width = 3;
			}
			else
			{
				if (config->width < 3)
					config->width = 2;
			}
        } 
}