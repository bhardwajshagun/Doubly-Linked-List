// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================

void unitTest1() {
	printf("unitTest1\n\n");
	dll_t* test1 = create_dll();
	printf("Attempting to push front: 10\n");
	printf("Push front return: %d\n", dll_push_front(test1, 10));
	dll_print(test1);
	printf("Attempting to push front: 20\n");
	printf("Push front return: %d\n", dll_push_front(test1, 20));
	dll_print(test1);
	printf("Attempting to push front: 30\n");
	printf("Push front return: %d\n", dll_push_front(test1, 30));
	dll_print(test1);
	printf("Attempting to push front: 40\n");
	printf("Push front return: %d\n", dll_push_front(test1, 40));
	dll_print(test1);
	printf("Attempting to push front: 50\n");
	printf("Push front return: %d\n", dll_push_front(test1, 50));
	dll_print(test1);
	free_dll(test1);
	printf("\n\n");
}

void unitTest2() {
	printf("unitTest2\n\n");
	dll_t* test2 = create_dll();
	printf("Attempting to push back: 5\n");
	printf("Push back return: %d\n", dll_push_back(test2, 5));
	dll_print(test2);
	printf("Attempting to push back: 10\n");
	printf("Push back return: %d\n", dll_push_back(test2, 10));
	dll_print(test2);
	printf("Attempting to push back: 15\n");
	printf("Push back return: %d\n", dll_push_back(test2, 15));
	dll_print(test2);
	printf("Attempting to push back: 30\n");
	printf("Push back return: %d\n", dll_push_back(test2, 30));
	dll_print(test2);
	printf("Attempting to push back: 35\n");
	printf("Push back return: %d\n", dll_push_back(test2, 35));
	dll_print(test2);
	free_dll(test2);
	printf("\n\n");
}

void unitTest3() {
	printf("unitTest3\n\n");
	dll_t* test3 = create_dll();
	printf("Attempting to push front: 1\n");
	printf("Push front return: %d\n", dll_push_front(test3, 1));
	dll_print(test3);
	printf("Attempting to push front: 2\n");
	printf("Push front return: %d\n", dll_push_front(test3, 2));
	dll_print(test3);
	printf("Attempting to push front: 3\n");
	printf("Push front return: %d\n", dll_push_front(test3, 3));
	dll_print(test3);
	printf("Attempting to push front: 4\n");
	printf("Push front return: %d\n", dll_push_front(test3, 4));
	dll_print(test3);
	printf("Attempting to push front: 5\n");
	printf("Push front return: %d\n", dll_push_front(test3, 5));
	dll_print(test3);
	printf("Attempting to pop front: %d\n", dll_pop_front(test3));
	dll_print(test3);
	printf("Attempting to pop front: %d\n", dll_pop_front(test3));
	dll_print(test3);
	printf("Attempting to pop front: %d\n", dll_pop_front(test3));
	dll_print(test3);
	printf("Attempting to pop front: %d\n", dll_pop_front(test3));
	dll_print(test3);
	printf("Attempting to pop front: %d\n", dll_pop_front(test3));
	dll_print(test3);
	free_dll(test3);
	printf("\n\n");
}

void unitTest4() {
	printf("unitTest4\n\n");
	dll_t* test4 = create_dll();
	printf("Attempting to push back: 2\n");
	printf("Push back return: %d\n", dll_push_back(test4, 2));
	dll_print(test4);
	printf("Attempting to push back: 4\n");
	printf("Push back return: %d\n", dll_push_back(test4, 4));
	dll_print(test4);
	printf("Attempting to push back: 6\n");
	printf("Push back return: %d\n", dll_push_back(test4, 6));
	dll_print(test4);
	printf("Attempting to push back: 8\n");
	printf("Push back return: %d\n", dll_push_back(test4, 8));
	dll_print(test4);
	printf("Attempting to push back: 10\n");
	printf("Push back return: %d\n", dll_push_back(test4, 10));
	dll_print(test4);
	printf("Attempting to pop back: %d\n", dll_pop_back(test4));
	dll_print(test4);
	printf("Attempting to pop back: %d\n", dll_pop_back(test4));
	dll_print(test4);
	printf("Attempting to pop back: %d\n", dll_pop_back(test4));
	dll_print(test4);
	printf("Attempting to pop back: %d\n", dll_pop_back(test4));
	dll_print(test4);
	printf("Attempting to pop back: %d\n", dll_pop_back(test4));
	dll_print(test4);
	free_dll(test4);
	printf("\n\n");
}

void unitTest5() {
	printf("unitTest5\n\n");
	dll_t* test5 = create_dll();
	printf("Attempting to push front: 10\n");
	printf("Push front return: %d\n", dll_push_front(test5, 10));
	dll_print(test5);
	printf("Attempting to push front: 20\n");
	printf("Push front return: %d\n", dll_push_front(test5, 20));
	dll_print(test5);
	printf("Attempting to push front: 30\n");
	printf("Push front return: %d\n", dll_push_front(test5, 30));
	dll_print(test5);
	printf("Attempting to push front: 40\n");
	printf("Push front return: %d\n", dll_push_front(test5, 40));
	dll_print(test5);
	printf("Attempting to push front: 50\n");
	printf("Push front return: %d\n", dll_push_front(test5, 50));
	dll_print(test5);
	printf("Attempting to insert at position 0: 60\n");
	printf("Insert return: %d\n", dll_insert(test5, 0, 60));
	dll_print(test5);
	printf("Attempting to insert at position 3: 22\n");
	printf("Insert return: %d\n", dll_insert(test5, 3, 22));
	dll_print(test5);
	printf("Attempting to insert at position 6: 3\n");
	printf("Insert return: %d\n", dll_insert(test5, 6, 3));
	dll_print(test5);
	free_dll(test5);
	printf("\n\n");
}

void unitTest6() {
	printf("unitTest6\n\n");
	dll_t* test6 = create_dll();
	printf("Attempting to push back: 3\n");
	printf("Push back return: %d\n", dll_push_back(test6, 3));
	dll_print(test6);
	printf("Attempting to push back: 6\n");
	printf("Push back return: %d\n", dll_push_back(test6, 6));
	dll_print(test6);
	printf("Attempting to push back: 9\n");
	printf("Push back return: %d\n", dll_push_back(test6, 9));
	dll_print(test6);
	printf("Attempting to push back: 12\n");
	printf("Push back return: %d\n", dll_push_back(test6, 12));
	dll_print(test6);
	printf("Attempting to push back: 15\n");
	printf("Push back return: %d\n", dll_push_back(test6, 15));
	dll_print(test6);
	printf("Attempting to push back: 18\n");
	printf("Push back return: %d\n", dll_push_back(test6, 18));
	dll_print(test6);
	printf("Attempting to push back: 21\n");
	printf("Push back return: %d\n", dll_push_back(test6, 21));
	dll_print(test6);
	printf("Attempting to push back: 24\n");
	printf("Push back return: %d\n", dll_push_back(test6, 24));
	dll_print(test6);
	printf("Attempting to delete at position 3: %d\n", dll_remove(test6, 3));
	dll_print(test6);
	printf("Attempting to delete at position 1: %d\n", dll_remove(test6, 1));
	dll_print(test6);
	printf("Attempting to delete at position 0: %d\n", dll_remove(test6, 0));
	dll_print(test6);
	printf("Attempting to delete at position 1: %d\n", dll_remove(test6, 1));
	dll_print(test6);
	printf("Attempting to delete at position 3: %d\n", dll_remove(test6, 3));
	dll_print(test6);
	free_dll(test6);
	printf("\n\n");
}

void unitTest7() {
	printf("unitTest7\n\n");
	dll_t* test7 = create_dll();
	printf("Attempting to push front: 3\n");
	printf("Push back return: %d\n", dll_push_front(test7, 3));
	dll_print(test7);
	printf("Attempting to push back: 6\n");
	printf("Push back return: %d\n", dll_push_back(test7, 6));
	dll_print(test7);
	printf("Attempting to push front: 9\n");
	printf("Push back return: %d\n", dll_push_front(test7, 9));
	dll_print(test7);
	printf("Attempting to push back: 12\n");
	printf("Push back return: %d\n", dll_push_back(test7, 12));
	dll_print(test7);
	printf("Attempting to get at position 0: %d\n", dll_get(test7, 0));
	dll_print(test7);
	printf("Attempting to get at position 2: %d\n", dll_get(test7, 2));
	dll_print(test7);
	printf("Attempting to get at position 3: %d\n", dll_get(test7, 3));
	dll_print(test7);
	free_dll(test7);
	printf("\n\n");
}

void unitTest8() {
	printf("unitTest8\n\n");
	dll_t* test8 = create_dll();
	printf("Attempting to insert at position 0: 10\n");
	printf("Insert return: %d\n", dll_insert(test8, 0, 10));
	dll_print(test8);
	printf("Attempting to get at position 0: %d\n", dll_get(test8, 0));
	dll_print(test8);
	printf("Attempting to insert at position 1: 20\n");
	printf("Insert return: %d\n", dll_insert(test8, 1, 20));
	dll_print(test8);
	printf("Attempting to delete at position 0: %d\n", dll_remove(test8, 0));
	dll_print(test8);
	printf("Attempting to delete at position 0: %d\n", dll_remove(test8, 0));
	dll_print(test8);
	free_dll(test8);
	printf("\n\n");
}

int main() {

	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();
	unitTest6();
	unitTest7();
	unitTest8();
	return 0;

}
