#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/* Prompt for display */
char *prompt(void);

/* Function to compare string */
int compare_string(char *s1, char *s2);
size_t compare_nchar_string(char *string1, char *string2, size_t nchar);

/* String functions */
int string_length(char *s);
char *copy_string(char *dest, char *src);
char *concat_string(char *destination, char *source);
int string_length(char *str);
char *string_token(char *str, const char *str_delim);

/* Get environment */
char *get_environment_path(char **envp);
void get_environment(char **env);

/* Get path */
int get_path_value(char **path, char **envp);

/* Get token */
char **retrieve_token(char *user_input);

/* Exit prompt */
void user_exit_command(char **alloc_mem, char *input_cmd, int exit_cmd);

/* Fork processes */
int fork_process(char **path_val, char **prgrm_nme, char **envp,
		char *cmd_ln, int prcs_id, int checker);

/* Charater manipulation */
char *character_occurence(const char *str, int chtr);
size_t compute_string_segment_str1(const char *str1, const char *str2);
size_t compute_string_segment(const char *str1, const char *str2);

#endif
