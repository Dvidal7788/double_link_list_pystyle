#include "double_link_header.h"

///////////////////////////////////////////////////////////
//          ~~ FUNCTION DEFINITIONS ~~
//////////////////////////////////////////////////////////

//          -- WRITE TO FILE --
void write_to_file(node *head, char *file_name)
{
    // Open file
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        char msg[sizeof(char)*150];
        sprintf(msg, "Failure while writing list to \"%s\"", file_name);
        if_error(6, msg, head);
    }

    node *tmp = head;
    while (tmp != NULL) {
        fprintf(file, "%s\n", tmp->s);
        tmp = tmp->next;
    }

    fclose(file);
    file = NULL;
    tmp = NULL;
    return;
}


//          -- APPEND TO FILE --
void append_to_file(node *head, node *last, char *file_name)
{
    // Open file
    FILE *file = fopen(file_name, "a");
    if (file == NULL) {
        char msg[sizeof(char)*150];
        sprintf(msg, "Failure while appending last item in list to \"%s\"", file_name);
        if_error(5, msg, head);
    }

    // Append
    fprintf(file, "%s\n", last->s);

    // Close file
    fclose(file);
    file = NULL;
    return;
}

//          -- PRINT LIST --
void print_list(node *head, char *file_name)
{
    node *tmp = head;
    printf("\n\n\t\t\t\t~~~~ CREATE YOUR OWN LIST ~~~~\n%s :\n\n[", file_name);
    while (tmp != NULL)
    {
        if (tmp->next == NULL) {
            printf("\'%s\'", tmp->s);
        }
        else printf("\'%s\', ", tmp->s);

        tmp = tmp->next;
    }
    printf("]\n\n");
    tmp = head = NULL;
    file_name = NULL;
    return;
}

//          -- FREE LIST --
void free_list(node *head)
{
    node *tmp = NULL;
    while (head != NULL)
    {
        tmp = head->next;
        free(head->s);
        head->s = NULL;
        head->prev = head->next = NULL;
        free(head);
        head = tmp;
    }

    head = tmp = NULL;
    return;
}

//          -- IF ERROR --
void if_error(int8_t n, char *msg, node *head)
{
    free_list(head);

    // Print error message
    printf("\n** ERROR # %i: %s **\n\n", n, msg);

    // Append to error_log.csv
    // Open file
    FILE *log_file = fopen("error_log.csv", "a");
    if (log_file == NULL) {msg = NULL; head = NULL; exit(-1);}

    // Time
    time_t t;
    t = time(0);
    uint8_t l = strlen(ctime(&t));

    // ctime() returns pointer to static buffer. Can not free() it.
    char *timestamp = ctime(&t);

    // Cut off 2 '\n's at the end of string
    timestamp[l-2] = '\0';

    // Append to file
    signed int print_return = 0;
    if ((print_return = fprintf(log_file, "%i, %s, %s\n", n, msg, timestamp)) < 0) {
        msg = timestamp = NULL;
        exit(-2);
    }

    fclose(log_file);
    log_file = NULL;
    msg = timestamp = NULL;
    head = NULL;
    exit(n);
}
//          -- FREE UNUSED NODE --
void free_unused_node(node *n)
{
    free(n->s);
    n->s = NULL;
    n->prev = n->next = NULL;
    free(n);
    n = NULL;
    return;
}

//          -- user_input_loop_1_2 --
int8_t user_input_loop_1_2(char *prompt)
{
    // This function will keep asking the user the prompt until either 1 or 2 is answered
        // Using getchar() to easily be abe to change code to check for 'y'/'n' without havig to rewrite code with different function
        // int8_t for max portability
        int8_t c = 0;
        while (c != '1' && c != '2') {
            printf("%s", prompt);
            c = getchar();

            if (c != '1' && c != '2') {
                printf("\n*Enter 1 for YES or 2 for NO only.\n\n");
                while (getchar() != '\n');
            }
        }
        while (getchar() != '\n');

        prompt = NULL;
        return c;
}
