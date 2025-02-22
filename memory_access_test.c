#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a simple struct
typedef struct {
    int data;
} SimpleStruct;

// Define a struct with padding
typedef struct {
    int data;
    char padding[16];
} PaddedStruct;

// Define a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/////// TODO -> Add a struct to pass iterations, linked list length, and search value
typedef struct {
    int iterations;
    int list_length;
    int search_value;
} SearchParams;

// Function to compare access times of SimpleStruct and PaddedStruct
void compare_struct_access_times(int iterations) {
    SimpleStruct simple;
    PaddedStruct padded;

    // Initialize data
    simple.data = 10;
    padded.data = 10;

    clock_t start, end;

    // Measure access time for SimpleStruct
    start = clock();
    for (int i = 0; i < iterations; i++) {
        //
        for (int j = 0; j < 500000; j++) {
            simple.data += 1;
        }
    }
    end = clock();
    printf("SimpleStruct access time (%d iterations): %f seconds\n", iterations, (double)(end - start) / CLOCKS_PER_SEC);

    // Measure access time for PaddedStruct
    start = clock();
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < 500000; j++) {
            padded.data += 1;
        }
    }
    end = clock();
    printf("PaddedStruct access time (%d iterations): %f seconds\n", iterations, (double)(end - start) / CLOCKS_PER_SEC);
}

// Function to compare search times of linked lists using linear search
void compare_linked_list_search_linear(SearchParams params) {
    Node* head = NULL;
    Node* current;

    // Create a linked list with params.list_length nodes
    for (int i = 0; i < params.list_length; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    clock_t start, end;

    // Measure search time using linear search
    start = clock();
    for (int i = 0; i < params.iterations; i++) {
        current = head;
        while (current != NULL) {
            if (current->data == params.search_value) {
                break;
            }
            current = current->next;
        }
    }
    end = clock();
    printf("Linear search time (%d iterations): %f seconds\n", params.iterations, (double)(end - start) / CLOCKS_PER_SEC);

    // Free the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to compare search times of linked lists using binary search
void compare_linked_list_search_binary(SearchParams params) {
    Node* head = NULL;
    Node* current;

    // Create a linked list with params.list_length nodes
    for (int i = 0; i < params.list_length; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    clock_t start, end;

    // Measure search time using binary search
    start = clock();
    for (int i = 0; i < params.iterations; i++) {
        int target = params.search_value;
        int low = 0;
        int high = params.list_length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            current = head;
            for (int j = 0; j < mid; j++) {
                current = current->next;
            }
            if (current->data == target) {
                break;
            } else if (current->data < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    end = clock();
    printf("Binary search time (%d iterations): %f seconds\n", params.iterations, (double)(end - start) / CLOCKS_PER_SEC);

    // Free the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    SearchParams params;
    params.iterations = 5000;
    params.list_length = 1000;
    params.search_value = 750;

    compare_struct_access_times(params.iterations);
    compare_linked_list_search_linear(params);
    compare_linked_list_search_binary(params);
    return 0;
}