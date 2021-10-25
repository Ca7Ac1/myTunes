#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "library.h"

int main()
{
    song_node *list = NULL;
    list = insert_front(list, "Patrick Watson", "Je te laisserai des mots");
    list = insert_order(list, "twenty one pilots", "Stressed Out");
    list = insert_order(list, "Duncan Laurence", "Arcade");
    list = insert_order(list, "Martin Garrix", "Animals");
    list = insert_order(list, "Maroon 5", "Animals");
    list = insert_order(list, "Jaymes Young", "I'll Be Good");
    list = insert_order(list, "Jaymes Young", "Happiest Year");
    list = insert_order(list, "5 Seconds of Summer", "Youngblood");

    printf("LINKED LIST TESTING\n\n");

    printf("Compare_data: \n");
    printf("Equal: %d\n", compare_data(list->next, "Duncan Laurence", "Arcade"));
    printf("Larger: %d\n", compare_data(list->next, "Euncan Laurence", "Arcade"));
    printf("Smaller: %d\n", compare_data(list->next, "Cuncan Laurence", "Arcade"));
    printf("Larger: %d\n", compare_data(list->next, "Duncan Laurence", "Brcade"));
    printf("Smaller: %d\n", compare_data(list->next, "Duncan Laurence", "Aqcade"));

    printf("Print_list:\n");
    print_list(list);
    printf("\n\n\n");

    printf("Print_list_artist:\n");
    print_list_artist(list, "Jaymes Young");
    printf("\n\n\n");

    printf("Find:\n");
    print_node(find(list, "Martin Garrix", "Animals"));
    printf("\n\n\n");

    printf("Find_artist:\n");
    print_node(find_first(list, "Jaymes Young"));
    printf("\n\n\n");

    printf("Random:\n");
    print_node(find_rand(list));
    printf("\n");
    print_node(find_rand(list));
    printf("\n");
    print_node(find_rand(list));
    printf("\n\n\n");

    printf("Remove_song:\n\n");
    printf("Original List:\n");
    print_list(list);
    printf("\n\n");

    printf("Removing Maroon 5 - Animals\n");
    list = remove_song(list, "Maroon 5", "Animals");
    print_list(list);
    printf("\n\n");

    printf("Removing twenty one pilots - Stressed Out\n");
    list = remove_song(list, "twenty one pilots", "Stressed Out");
    print_list(list);
    printf("\n\n");

    printf("Removing Duncan Laurence - Arcade\n");
    list = remove_song(list, "Duncan Laurence", "Arcade");
    print_list(list);
    printf("\n\n\n");

    printf("Free_list:\n");
    list = free_list(list);
    print_list(list);
    printf("\n\n\n\n");

    printf("MUSIC LIBRARY TESTING\n\n");

    library *lib = create_lib();
    lib = add_song(lib, "Patrick Watson", "Je te laisserai des mots");
    lib = add_song(lib, "twenty one pilots", "Stressed Out");
    lib = add_song(lib, "Duncan Laurence", "Arcade");
    lib = add_song(lib, "Martin Garrix", "Animals");
    lib = add_song(lib, "Maroon 5", "Animals");
    lib = add_song(lib, "Jaymes Young", "I'll Be Good");
    lib = add_song(lib, "Jaymes Young", "Happiest Year");
    lib = add_song(lib, "5 Seconds of Summer", "Youngblood");
    lib = add_song(lib, "50 Cent", "Candy Shop");
    lib = add_song(lib, "Jason Derulo", "Savage Love");
    lib = add_song(lib, "JP Saxe", "If the World was Ending");

    printf("getindex:\n");
    char i = 'i';
    printf("%d\n", get_index("a"));
    printf("%d\n", get_index("A"));
    printf("%d\n", get_index("3"));
    printf("%d\n", get_index(&i));
    printf("\n\n");

    print_lib(lib);
    printf("\n\n");

    printf("print_lib_entries:\n");
    print_lib_entries(lib, '3');
    printf("\n");
    print_lib_entries(lib, 'j');
    printf("\n");
    print_lib_entries(lib, 'J');
    printf("\n");
    printf("\n\n");

    printf("print_lib_artist:\n");
    print_lib_artist(lib, "Jaymes Young");
    printf("\n\n\n");

    printf("search_song:\n");
    printf("Searching for Maroon 5 - Animals\n");
    print_node(search_song(lib, "Maroon 5", "Animals"));
    printf("\n");

    printf("Searching for Maroon 5 - Payphone\n");
    if (search_song(lib, "Maroon 5", "Payphone") == NULL)
        printf("Could not find Payphone\n");
    printf("\n");

    printf("search_artist:\n");
    printf("Searching for Jaymes Young\n");
    print_list(search_artist(lib, "Jaymes Young"));
    printf("\n");

    printf("Searching for CG5\n");
    if (search_artist(lib, "CG5") == NULL)
        printf("Could not find artist CG5\n");
    printf("\n\n\n");

    printf("Delete_song:\n");
    printf("Deleting Maroon 5 - Animals\n");
    lib = delete_song(lib, "Maroon 5", "Animals");
    print_lib(lib);
    printf("\n\n");

    printf("Deleting Duncan Laurence - Arcade\n");
    lib = delete_song(lib, "Duncan Laurence", "Arcade");
    print_lib(lib);
    printf("\n");

    printf("Shuffle:\n");
    shuffle(lib);
    shuffle(lib);
    printf("\n\n");

    printf("Free_lib:\n");
    free_lib(lib);
    print_lib(lib);

    return 0;
}