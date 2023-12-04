#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

int max(int a, int b) {
    return (a > b) ? a : b;
}

t_list *circularLIS(t_list *head, int *lisSize) {
    if (head == NULL) {
        *lisSize = 0;
        return NULL;
    }

    t_list *current = head;
    int n = 0;

    // Count the number of nodes in the linked list
    while (current != NULL) {
        n++;
        current = current->next;
    }

    // Convert the linked list to an array
    int *arr = (int *)malloc(sizeof(int) * n);
    current = head;
    for (int i = 0; i < n; i++) {
        arr[i] = *((int *)current->content);
        current = current->next;
    }

    int *lis = (int *)malloc(sizeof(int) * n);
    int *prevIndex = (int *)malloc(sizeof(int) * n);

    // Initialize LIS values for all indexes
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        prevIndex[i] = -1;
    }

    int maxLength = 1;
    int endIndex = 0;

    // Compute optimized LIS values in bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prevIndex[i] = j;
            }
        }
        // Check if a circular connection is possible
        if (arr[i] > arr[0] && lis[i] < lis[0] + 1) {
            lis[i] = lis[0] + 1;
            prevIndex[i] = 0;
        }

        // Update maxLength and endIndex
        if (lis[i] > maxLength) {
            maxLength = lis[i];
            endIndex = i;
        }
    }

    // Construct the LIS as a linked list
    t_list *result = NULL;
    t_list *currentResult = NULL;
    int currentIndex = endIndex;
    for (int i = maxLength - 1; i >= 0; i--) {
        t_list *node = (t_list *)malloc(sizeof(t_list));
        node->content = malloc(sizeof(int));
        *((int *)node->content) = arr[currentIndex];
        node->next = NULL;

        if (result == NULL) {
            result = node;
            currentResult = result;
        } else {
            currentResult->next = node;
            currentResult = node;
        }

        currentIndex = prevIndex[currentIndex];
    }

    *lisSize = maxLength;

    free(arr);
    free(lis);
    free(prevIndex);

    return result;
}

void printList(t_list *head) {
    while (head != NULL) {
        printf("%d ", *((int *)head->content));
        head = head->next;
    }
    printf("\n");
}

void freeList(t_list *head) {
    while (head != NULL) {
        t_list *temp = head;
        head = head->next;
        free(temp->content);
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    t_list *head = NULL;
    t_list *current = NULL;

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; i++) {
        int *element = (int *)malloc(sizeof(int));
        scanf("%d", element);

        t_list *node = (t_list *)malloc(sizeof(t_list));
        node->content = element;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            current = head;
        } else {
            current->next = node;
            current = node;
        }
    }

    int lisSize;
    t_list *circularLISResult = circularLIS(head, &lisSize);

    printf("Longest Increasing Subsequence (LIS) in the circular linked list: ");
    printList(circularLISResult);

    freeList(head);
    freeList(circularLISResult);

    return 0;
}