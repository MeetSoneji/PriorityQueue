#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int priority;
    struct Node *next;
};
struct Node *createNode(int data, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(struct Node *head)
{
    return (head == NULL);
}
void enqueue(struct Node **head, int data, int priority)
{
    struct Node *newNode = createNode(data, priority);
    if (isEmpty(*head) || priority < (*head)->priority)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d enqueued with priority %d.\n", data, priority);
}
int dequeue(struct Node **head)
{
    if (isEmpty(*head))
    {
        printf("Priority queue is empty!\n");
        exit(1);
    }
    struct Node *temp = *head;
    int dequeued = temp->data;
    *head = (*head)->next;
    free(temp);
    return dequeued;
}
void display(struct Node *head)
{
    if (isEmpty(head))
    {
        printf("Priority queue is empty!\n");
        return;
    }
    printf("Priority queue elements:\n");
    while (head != NULL)
    {
        printf("%d (Priority: %d)\n", head->data, head->priority);
        head = head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    int choice, data, priority;

    while (1)
    {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display the priority queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            printf("Enter the priority: ");
            scanf("%d", &priority);
            enqueue(&head, data, priority);
            break;
        case 2:
            if (!isEmpty(head))
            {
                int dequeued = dequeue(&head);
                printf("Dequeued: %d\n", dequeued);
            }
            else
            {
                printf("Priority queue is empty! Cannot dequeue.\n");
            }
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}
