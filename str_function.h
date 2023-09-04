/// @file str_fucntion.h

#ifndef STR_FUNCTION_H
#define STR_FUNCTION_H

int my_puts (const char* str);

void test_msg (bool expr, const char* func_name);

char* my_gets (char* src);

size_t my_strlen (const char* str);

char* my_strcpy (char* dest, const char* src);

char* my_strncpy (char* dest, const char* src, size_t n);

char* my_strcat (char* dest, const char* src);

char* my_strncat (char* dest, const char* src, size_t n);

char* my_strdup (const char* s);

char* my_strchr (const char *s, int c);

char* my_strstr (const char* s1, const char* s2);

int my_strcmp (const char* s1, const char* s2);

size_t my_getline (char ** lineptr, size_t *n, FILE *stream);

#endif // STR_FUNCTION_H
