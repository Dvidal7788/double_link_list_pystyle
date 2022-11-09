# double_link_list_pystyle
// DOUBLE LINK LIST (written in C)

    // Written in C
    
    // * Prints in style of Python list[]: ['item1', 'item2', ...]
    // * Appends list item by item to new csv file as you type them in

    // - Quit any time by typing "quit" or "q"
        // - Allows user to add the string "quit" or "q" as an item in the list with prompts that follow
    // - Remove last item (node) any time by typing "remove" or "r"
        // - Allows user to add the string "remove" or "r" as an item in the list with prompts that follow
        
    // - If any errors occur during null checks etc:
        // - Will append to error_log.csv:
            // - a positive non-zero error # in column A, an error message in column B, and the timestamp in column C before returning that number from main.
                // - If any errors while trying to append to error_log.csv, will return negative values. (All other error numbers will be positive)
                
        // List of error codes/error messages:
            1: "Failure while scanning command line for name of new list."
            2: "Failure while allocating memory for node."
            3: "Failure while allocating memory for string.
            4: "Failure while scanning from command line."
            5: "Failure while re-allocating memory for string."
            6: "Failure while appending last item in list to <filename.csv>"
            7: "Failure while writing list to <filename.csv>"
