#include "main.h"
/**
 * print_c - prints a single char
 * @args: arguments received from _printf
 * Return: numbers of chars
 */
int print_c(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}


/**
 * print_s - prints a string
 * @args: arguments received from _printf
 * Return: number of chars
 */
int print_s(va_list args)
{
	int i;
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
	return (i);
}



/**
 * print_i - print integers
 * @args: arguments for _printf
 * Return: number of arguments printed
 */
int print_i(va_list args)
{
	int i, j, cifras = 0, potencia, n, y = 0, bytes = 0;
	unsigned int a, b;

	n = va_arg(args, int);
	if (n == 0)
	{
		_putchar('0');
		bytes++;
		return (bytes);
	}
	if (n < 0)
	{
		_putchar('-');
		a = n * -1;
		bytes++;
	}
	else
	{
		a = n;
	}
	b = a;
	while ((a / 10) != 0)
	{
		cifras++;
		a /= 10;
	}

	for (i = 0; i < cifras; i++)
	{
		potencia = 1;
		for (j = i; j < cifras; j++)
		{
			potencia = potencia * 10;
		}
		y = b / potencia;
		b = b - (y * potencia);
		_putchar(y + '0');
	}
	_putchar(b + '0');
	return (bytes + cifras + 1);
}

/**
 * print_b - the unsigned int argument is converted to binary
 * @args: taking in arguments
 * Return: number of digits printed
 */
int print_b(va_list args)
{
	unsigned int n, buff[1024];
	int i, len = 0;
	char p;

	n = va_arg(args, int);
	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buff[len] = n % 2;
		n /= 2;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		p = buff[i] + '0';
		write(1, &p, 1);
	}
	return (len);
}

/**
 * print_o - the unsigned int argument is converted to octal
 * @args: pointer to arguments
 * Return: number of digits printed
 */
int print_o(va_list args)
{
	unsigned int n, buff[1024];
	int i, len = 0;
	char p;

	n = va_arg(args, int);
	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buff[len] = n % 8;
		n /= 8;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		p = buff[i] + '0';
		write(1, &p, 1);
	}
	return (len);
}
/**
 * print_x - unsigned int argument is converted to hexa in lowercase
 * @args: pointer to arguments
 * Return: number of digits printed
 */

int print_x(va_list args)
{
	unsigned int n, buff[1024];
	int i = 0, len = 0;
	char p;

	n = va_arg(args, int);
	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buff[len] = n % 16;
		n /= 16;
		if (buff[len] > 9)
			buff[i] = buff[len] + 39;
		else
			buff[i] = buff[len];
		i++;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		p = buff[i] + '0';
		write(1, &p, 1);
	}
	return (len);
}

/**
 * print_X - unsigned int argument is converted to hexa in uppercase
 * @args: pointer to arguments
 * Return: number of digits printed
 */

int print_X(va_list args)
{
	unsigned int n, buff[1024];
	int i = 0, len = 0;
	char p;

	n = va_arg(args, int);
	if (n < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buff[len] = n % 16;
		n /= 16;
		if (buff[len] > 9)
			buff[i] = buff[len] + 7;
		else
			buff[i] = buff[len];
		i++;
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		p = buff[i] + '0';
		write(1, &p, 1);
	}
	return (len);
}

/**
 * print_r - Prints a string in reverse.
 * @args: Variable string.
 *
 * Return: lenght of the string.
 */
int print_r(va_list args)
{
	char *p, s;
	int i = 0, len = 0;

	p = va_arg(args, char *);
	while (p[i] != '\0')
	{
		len++;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		s = p[i];
		write(1, &s, 1);
	}
	return (len);
}

/**
 * print_R - print a string to rot13 encode.
 * @args: Pointer to string.
 *
 * Return: lenght of the string encode in rot13
 */
int print_R(va_list args)
{
	int i, j, len = 0;
	char alpha[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char ch[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
	char *p, *m;

	p = va_arg(args, char *);
	for (i = 0; p[i] != '\0'; i++)
		len++;
	m = malloc(sizeof(char) * (len + 1));
	if (!m)
		return ('\0');
	for (i = 0; i <= len; i++)
	{
		m[i] = p[i];
	}
	for (i = 0 ; m[i] != '\0' ; i++)
	{
		for (j = 0 ; alpha[j] != '\0' ; j++)
		{
			if (m[i] == alpha[j])
			{
				m[i] = ch[j];
				break;
			}
		}
	}
	for (i = 0; m[i] != '\0'; i++)
		write(1, &m[i], 1);
	free(m);
	return (len);
}
/**
 * aux_func - selects the function to format the text
 *
 * @format: text to be formated
 * @args: list of arguments
 * @fx: list of functions to format text
 * Return: size of printed text
 */

int aux_func(const char *format, va_list args, print_fx *fx)
{
	int i = 0, j, size = 0, test = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (fx[j].c != NULL)
			{
				if (format[i + 1] == '%')
				{
					write(1, &format[i], 1);
					size++;
					i++;
					test = 1;
					break;
				}
				else if (fx[j].c[0] == format[i + 1])
				{
					size += fx[j].f(args);
					i++;
					test = 1;
					break;
				}
				j++;
			}
			if (test == 0)
			{
				write(1, &format[i], 1);
				size++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			size++;
		}
		i++;
	}
	return (size);
}
