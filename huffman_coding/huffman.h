#ifndef HUFFMAN_H
#define HUFFMAN_H
/*
 * ===========================================================================
 *
 *       Filename:  huffman.h
 *
 *    Description: huffman header file 
 *
 *        Version:  1.0
 *        Created:  13.12.2024 10:00:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Lévêque (loris@leveque.website), 9601@holbertonstudents.com
 *   Organization:  
 *
 * ===========================================================================
 */


/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
} symbol_t;

#endif
