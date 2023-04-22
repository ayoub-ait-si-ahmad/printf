#include "main.h"
#include <stdio.h>
/**
  *main -Entry point
  *
  *Return: always 0
  */
int main(void)
{
	_printf("let's print a simple sentence.\n");
	printf("let's print a simple sentence.\n");
	_printf("let's try %%i: [%i]\n", 10);
	printf("let's try %%i: [%i]\n", 10);
	_printf("let's try %%d: [%d]\n", 12);
	printf("let's try %%d: [%d]\n", 12);
	_printf("let's try %%c: [%c]\n", 'A');
	printf("let's try %%c: [%c]\n", 'A');
	_printf("Let's try %%s: [%s]\n", "this is a string");
	printf("Let's try %%s: [%s]\n", "this is a string");
	return (0);
}
