#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <time.h>

// // Declare struct
typedef struct node {
    char *s;
    struct node *prev;
    struct node *next;
} node;

// Function Prototypes
void print_list(node *head, char *file_name);
void free_list(node *head);
bool append_error_log(int8_t n, char *msg);
void if_error(int8_t n, char *msg, node *head);
void free_unused_node(node *n);
void write_to_file(node *head, char *file_name);
void append_to_file(node *head, node *last, char *file_name);
int8_t user_input_loop_1_2(char *prompt);

#endif // HEADER_H