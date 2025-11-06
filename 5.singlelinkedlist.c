#include <stdio.h>
#define MAX 100
int data[MAX];
int next[MAX];
int head = -1;
int free_index = 0;
int create_node(int value) {
    if (free_index >= MAX) {
        printf("Error: List is full.\n");
        return -1;
    }
    int index = free_index;
    data[index] = value;
    next[index] = -1;
    free_index++;
    return index;
}
void insert_end(int value) {
    int new_node = create_node(value);
    if (new_node == -1) return;
    if (head == -1) {
        head = new_node;
    } else {
        int temp = head;
        while (next[temp] != -1) {
            temp = next[temp];
        }
        next[temp] = new_node;
    }
}
void display_list() {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }
    int temp = head;
    printf("Linked List: ");
    while (temp != -1) {
        printf("%d -> ", data[temp]);
        temp = next[temp];
    }
    printf("NULL\n");
}
int main() {
    int n, val;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        insert_end(val);
    }
    display_list();
    return 0;
}
