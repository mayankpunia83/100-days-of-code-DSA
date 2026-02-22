#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_node(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
int count_nodes(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
int main()
{
    int n, value;
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        newnode = create_node(value);

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    int result = count_nodes(head);
    printf("%d\n", result);

    return 0;
}