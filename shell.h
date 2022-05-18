#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
extern char **environ;
/* malloc string */
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void free_array(char **array);
char **strtow(char *str);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
int _putchar(char c);
void _puts(char *str);
/* numbers */
void exit_shell(char **built_in);
int _isnumber(char *str);
int _atoi(char *s);
/* process */
void execve_cmd(char **cmd);
int get_path(char **cmd);
char *_getenv(char *name);
/* built in */
int check_built_in(char *cmd);
void exec_built_in(char **built_in);
void print_env(void);
#endif
