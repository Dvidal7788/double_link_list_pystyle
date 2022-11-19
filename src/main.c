// DOUBLE LINK LIST

    // * Prints in style of Python list[]: ['item1', 'item2', ...]
    // * Appends list item by item to new csv file as you type them in

    // - Quit at any time by typing "quit" or "q"
        // - Allows user to add the word "quit" or "q" as an item in the list with prompts that follow
    // - Remove last item (node) at any time by typing "remove" or "r"
        // - Allows user to add the word "remove" or "r" as an item in the list with prompts that follow
    // - If any errors occur during null checks etc, will append to error_log.csv a positive non-zero error # in column A, an error message in column B, and the timestamp in column C before returning that number from main.
        // - If any errors while trying to append to error_log.csv, will return negative values. (All other error numbers will be positive)

#include <header.h>

int main(void)
{
    // MAIN POINTERS
    node *head = NULL, *last = NULL;
    uint64_t node_count = 0;

    // ASK USER FOR - FILE NAME -
    printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t\t\t\t~~~~ CREATE YOUR OWN LIST ~~~~\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\n\t\t(Type \"quit\" any time to quit. Type \"remove\" to remove last entry.)\n\n\n");
    printf("ENTER NAME OF NEW LIST: (This will create a csv file with that name. Do not add \".csv\" or any other file extensions. That will be added for you.) \n");
    char user_list_name[51];
    int16_t scan_return = 0;

    // Scan command line
    while (scan_return != EOF) scan_return = scanf("%50s", user_list_name);
    if (scan_return == EOF) if_error(1, "Failure while scanning command line for name of new list.", head);
    while (getchar() != '\n');

    // Quit (if user chose to)
    if (strcasecmp(user_list_name, "quit") == 0 || strcasecmp(user_list_name, "q") == 0) return 0;
    
    // Add .csv to file name
    uint8_t null_pos = strlen(user_list_name);
    sprintf(&user_list_name[null_pos], ".csv");


    // -------------------- CREATE DOUBLE LINK LIST --------------------
    printf("\n");

    // Separate from node_count, which can be 0 at various points, if the user adds, then removes items, loop_count will only be 0 once.
        // Only used to know whether or not to display message when user quits that csv file was created with list.
        // No file will be created if user quits before entering 1st item, and no message at the end will be displayed
        // If user inputs items and deletes all items, file is created, each item added AND removed along the way, leaving a file with a blank list
    uint64_t loop_count = 0;
    while (true)
    {
        // Create new node
        node *n = malloc(sizeof(node));
        if (n == NULL) if_error(2, "Failure while allocating memory for node.", head);
        n->prev = n->next = NULL;

        // Allocate 1st char for string in node
        n->s = malloc(sizeof(char));
        if (n->s == NULL) if_error(3, "Failure while allocating memory for string in node.", head);

        // USER INPUT
        printf("Enter data: ");

        // Scan char by char
        unsigned int i = 0;
        while (true) {
            // Scan
            scan_return = scanf("%c", &n->s[i]);

            // Error check scan
            if (scan_return != 1) if_error(4, "Failure while scanning from command line", head);

            // Reallocate
            if (n->s[i] != '\n') {
                n->s = realloc(n->s, sizeof(char)*(i+2));
                if (n->s == NULL) if_error(5, "Failure while re-allocating memory for string in node.", head);
                i++;
            }
            else break;
        }
        n->s[i] = '\0';


        // ---------  QUIT, REMOVE OR APPEND NODE  ---------
        if (strcasecmp(n->s, "quit") == 0 || strcasecmp(n->s, "q") == 0)
        {
            // ---- QUIT ----

            int8_t c = user_input_loop_1_2("\n\nDo you want to QUIT? (1 for YES. 2 for NO.)\n");

            // If NO to quitting:
            if (c == '2') {

                // Add "quit" to list?
                // Keep asking until 1 or 2 is answered
                printf("\n\nDo you want to add \"%s\" to the list? (1 for YES. 2 for NO.)\n", n->s);
                c = user_input_loop_1_2("");

                // If NO to add "quit "to list: free node and continue. If yes, let it get to rest of code below on its own to append
                // This is not a redundant if statement. The outer if(c=='2') above refers to previous question
                if (c == '2') {
                    free_unused_node(n);
                    n = NULL;
                    print_list(head, user_list_name);
                    continue;
                }
            }
            else
            {
                free_unused_node(n);
                n = NULL;
                break;
            }


        }
        else if (strcasecmp(n->s, "remove") == 0 || strcasecmp(n->s, "r") == 0)
        {
            // ---- REMOVE ----

            // Remove last item?
            int8_t c = user_input_loop_1_2("\n\nDo you want to REMOVE to last item in the list? (1 for YES. 2 for NO.)\n");

            // -- IF NO to remove --
            if (c == '2') {

                // Keep asking until 1 or 2 is answered
                printf("\n\nDo you want to ADD \"%s\" as an item to the list? (1 for YES. 2 for NO.)\n", n->s);
                c = user_input_loop_1_2("");


                // If no, free node and continue. If yes, let it get to rest of code below on its own to append
                if (c == '2') {
                    free_unused_node(n);
                    n = NULL;
                    print_list(head, user_list_name);
                    continue;
                }
            }
            else
            {
                // -- IF YES to REMOVE --
                // Remove last item in list (last node)
                if (head == NULL) {
                    printf("\n** Nothing to remove. List is empty.**s");
                }
                else if (head == last) {
                    free(last->s);
                    last->s = NULL;
                    last->prev = last->next = NULL;
                    free(last);
                    head = last = NULL;
                }
                else {
                    node *tmp = last->prev;
                    tmp->next = NULL;
                    free(last->s);
                    last->s = NULL;
                    last->prev = last->next = NULL;
                    free(last);
                    last = tmp;
                    tmp = NULL;
                }
                node_count--;
                write_to_file(head, user_list_name);
                print_list(head, user_list_name);
                free_unused_node(n);
                n = NULL;
                continue;
            }
        }

        // APPEND NODE TO LIST
        if (head == NULL) {
            head = last = n;
        }
        else {
            last->next = n;
            n->prev = last;
            last = n;
        }
        print_list(head, user_list_name);

        // Append to file
        append_to_file(head, last, user_list_name);
        loop_count++;
    }
    print_list(head, user_list_name);



    // END
    printf("\nGOODBYE!!\n\n");
    if (loop_count > 0) printf(" ** A file named \"%s\" has been created for you with your list. **\n\n", user_list_name);
    free_list(head);
    head = last = NULL;

    return 0;
}
