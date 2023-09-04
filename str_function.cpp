/// @file str_function.cpp

#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#include "str_function.h"
#include "error.h"

int my_puts (const char* str)
{
    my_assert (str != NULL);

    while (*str != '\0')
    {
        str++;

        if (putchar (*str) == EOF)
        {
            return EOF;
        }
    }
    if (putchar ('\n') == EOF)
    {
        return EOF;
    }

    return 0;
}

void test_msg (bool expr, const char* name_func)
{
    if (expr)
    {
        printf("Функция %s выполнена корректно\n", name_func);
    }
    else
    {
        fprintf(stderr, "ERROR: %s выполнена с ошибкой\n", name_func);
    }
}

size_t my_strlen (const char* str)
{
    my_assert (str != NULL);

    size_t len = 0;

    while (*(str++) != '\0')
    {
        len++;
    }

    return len;
}

char* my_strcpy (char* dest, const char* src)
{
    my_assert (dest != NULL);
    my_assert (src  != NULL);

    char* dest_new = dest;

    while (*src != '\0')
    {
        *(dest_new++) = *(src++);
    }

    *dest_new = '\0';

    return dest;
}

char* my_strncpy (char* dest, const char* src, size_t n)
{
    my_assert (dest != NULL);
    my_assert (src  != NULL);

    char* dest_new = dest;

    while (n > 0 && *(src++) != '\0')
    {
        *(dest_new++) = *src;

        n--;
    }

    return dest;
}

char* my_strcat (char* dest, const char* src)
{
    my_assert (dest != NULL);
    my_assert (src != NULL);

    size_t dest_len = my_strlen (dest);
    char* dest_new = dest + dest_len;

    while (*src != '\0')
    {
        *(dest_new++) = *(src++);
    }

    *dest_new = '\0';

    return dest;
}

char* my_strncat (char* dest, const char* src, size_t n)
{
    my_assert (dest != NULL);
    my_assert (src != NULL);

    size_t dest_len = my_strlen (dest);

    for (size_t i = 0; i < n; i++)
    {
        dest[dest_len + i] = src[i];
    }

    return dest;
}

char* my_strdup (const char* src)
{
    my_assert (src != NULL);

    size_t src_len = my_strlen (src);

    char* src_copy = (char *) malloc (sizeof(char) * src_len);

    my_assert (src_copy != NULL);

    strncpy (src_copy, src, src_len);

    return src_copy;
}

char* my_strchr (const char* str, int ch)
{
    my_assert (str != NULL);

    while (*(str++) != '\0')
    {
        if (*str == ch)
        {
            return (char *) str;
        }
    }

    return NULL;
}

char* my_strstr (const char* s1, const char* s2)
{
    size_t s1_len = my_strlen (s1), s2_len = my_strlen (s2);

    size_t t = s2_len;

    char s2_copy[s2_len];

    int sum_s1 = 0;
    int sum_s2 = 0;
    int c = 0;

    for (size_t i = 0; i < s2_len; i++)
    {
        sum_s2 += s2[i];
    }

    for (size_t i = 0; i < s1_len; i++)
    {
        if (t != 0)
        {
            sum_s1 += s1[i - c];
            s2_copy[s2_len - t] = s1[i - c];
            t--;
        }
        if (t == 0)
        {
            if (sum_s1 == sum_s2 && strcmp (s2_copy, s2) == 0)
            {
                return (char *) s1 + i - s2_len;
            }
            sum_s1 = 0;
            t = s2_len;
            c += s2_len - 1;
        }
    }

    return NULL;
}

int my_strcmp (const char* s1, const char* s2)
{
    size_t s1_len = my_strlen (s1);
    size_t s2_len = my_strlen (s2);

    while ((*s1++ == *s2++) && (*s1 != '\0'))
    {
        s1_len--;
        s2_len--;
    }
    if (s1_len == s2_len)
    {
        return 0;
    }
    else if (*s1 > *s2)
    {
        return (int) *s1 - *s2;
    }
    else
    {
        return (int) *s2 - *s1;

        //abcd
    }   //abccd
}

#if 1

size_t getline (char** lineptr, size_t *n, FILE *stream)
{
    my_assert (lineptr != NULL);
    my_assert (n != NULL);
    my_assert (stream != NULL);

    size_t i = 0;

    while (((*lineptr)[i] = fgetc (stream)) != EOF)
    {
        if (i == *n)
        {
            lineptr = (char **) realloc (*lineptr, *n + 1);
        }
        i++;
    }
    return i;
}
#endif
