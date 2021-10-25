#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "library.h"

int main() {
    song_node * list = NULL;
    list = insert_front(list, "Patrick Watson", "Je te laisserai des mots");
    list = insert_order(list, "twenty one pilots", "Stressed Out");
    list = insert_order(list, "Duncan Laurence", "Arcade");
    list = insert_order(list, "Martin Garrix", "Animals");
    list = insert_order(list, "Maroon 5", "Animals");
    list = insert_order(list, "Jaymes Young", "I'll Be Good");
    list = insert_order(list, "Jaymes Young", "Happiest Year");


    printf("LINKED LIST TESTING\n\n");

    printf("Compare_data: \n");
    printf("Equal: %d\n", compare_data(list, "Duncan Laurence", "Arcade"));
    printf("Larger: %d\n", compare_data(list, "Euncan Laurence", "Arcade"));
    printf("Smaller: %d\n", compare_data(list, "Cuncan Laurence", "Arcade"));
    printf("Larger: %d\n", compare_data(list, "Duncan Laurence", "Brcade"));
    printf("Smaller: %d\n", compare_data(list, "Duncan Laurence", "Aqcade"));


    printf("Print_list:\n");
    print_list(list);
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
    printf("\n\n");

    return 0;
}