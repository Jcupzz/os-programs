#include <stdio.h>
int main()
{
    int n, head, size, temp, pos, seek_no = 0;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the disk size:");
    scanf("%d", &size);
    int a[n + 1];
    printf("Enter the request sequence:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the head position: ");
    scanf("%d", &head);
    a[n] = head;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == head)
        {
            pos = i;
        }
    }
    seek_no += ((size - 1) - head) + size - 1 + a[pos - 1];
    head = a[pos + 1];
    printf("%d\n", head);
    for (int i = pos + 2; i < n + 1; i++)
    {
        if (i == pos)
        {
            break;
        }
        printf("%d\n", a[i]);
        if (i == n)
        {
            printf("%d\n0\n", size - 1);
            i = -1;
            continue;
        }
    }
    printf("%d is the total seek time", seek_no);
}