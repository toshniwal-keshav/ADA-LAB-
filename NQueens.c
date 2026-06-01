#include <stdio.h>
#include <stdlib.h>

int x[20];

int place(int k, int i){
    for (int j = 1; j < k; j++) 
        if (x[j] == i || abs(j - k) == abs(x[j] - i))
            return 0;
    return 1;
}

void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i)){
            x[k] = i;
            if (k == n){
                for (int j = 1; j <= n; j++)
                    printf("%d ", x[j]);
                printf("\n");
            }
            else
                NQueens(k + 1, n);
        }
    }
}

int main(){
    int n;
    printf("Enter number of queens:");
    scanf("%d", &n);

    NQueens(1, n);
    return 0;
}