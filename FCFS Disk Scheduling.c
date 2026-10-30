#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int request[100];
    int head;
    int total_head_movement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk queue:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Sequence: %d", head);

    for(i = 0; i < n; i++)
    {
        total_head_movement += abs(request[i] - head);
        head = request[i];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d \n", total_head_movement);

    return 0;
}