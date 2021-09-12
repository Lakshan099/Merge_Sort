#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void MergeSort(int A[], int p, int r);
void Merge(int A[], int p, int q, int r);

int main()
{

    int A[10], i;
    for (i = 0; i < 10; i++)
    {
        printf("Enter %d Number: ", i + 1);
        scanf("%d", &A[i]);
    }
    MergeSort(A, 0, 9);
    printf("\nSorted Array\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", A[i]);
    }
}

void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

void Merge(int A[], int p, int q, int r)
{
    double Inf = INFINITY;
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j];
    }

    L[n1 + 1] = Inf;
    R[n2 + 1] = Inf;
    i = 1;
    j = 1;

    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[i])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}