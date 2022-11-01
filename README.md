# double_link_list_pystyle
// DOUBLE LINK LIST (written in C)

    // * Prints in style of Python list[]: ['item1', 'item2', ...]
    // * Appends list item by item to new csv file as you type them in

    // - Quit at any time by typing "quit" or "q"
        // - Allows user to add the word "quit" or "q" as an item in the list with prompts that follow
    // - Remove last item (node) at any time by typing "remove" or "r"
        // - Allows user to add the word "remove" or "r" as an item in the list with prompts that follow
    // - If any errors occur during null checks etc, will append to error_log.csv a positive non-zero error # in column A, an error message in column B, and the timestamp in column C before returning that number from main.
        // - If any errors while trying to append to error_log.csv, will return negative values. (All other error numbers will be positive)
