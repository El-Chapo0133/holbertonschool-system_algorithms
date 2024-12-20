/*
 * ===========================================================================
 *
 *       Filename:  symbol.c
 *
 *    Description: Write a function that creates a symbol_t data structure
 *
 *        Version:  1.0
 *        Created:  20.12.2024 10:04:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Lévêque 9601@holbertonstudents.com
 *   Organization:  Holberton
 *
 * ===========================================================================
 */

#include "heap.h"

/**
 * symbol_create - create a symbol_t
 * @data: symbol's data
 * @freq: symbol's freq
 *
 * Return: newly created symbol_t, NULL otherwise
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol = NULL;

	symbol = malloc(sizeof(symbol_t));
	if (!symbol)
		return (NULL);

	symbol->data = data;
	symbol->freq = freq;

	return (symbol);
}
