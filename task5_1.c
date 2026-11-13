#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


void createArr(int size_n, int size_m, int arr[size_n][size_m]){
    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_m;j++){
            arr[i][j]= (rand()%21);
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void sumRows(int size_n, int size_m, int arr[size_n][size_m]){
    int sumRows = 0;

    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_m;j++){
            if(i==0 || i==size_n-1) sumRows += arr[i][j];
        }
    }
    printf("Сума першого та останнього рядка:%d",sumRows);
}
void productColum(int size_n, int size_m, int arr[size_n][size_m]){
    long int productColum = 1;

    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_m;j++){
            if(j==0 || j==size_m-1) productColum *= arr[i][j];
        }
    }
    printf("\nДобуток першого та останнього стовпця:%d",productColum);
}
void minElem(int size_n, int size_m, int arr[size_n][size_m]){
    int minIndexI = 0;
    int minIndexJ = 0;
    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_m;j++){
            if(( (j==0 || j==(size_m-1)) || (i==0 || i==(size_n-1)) ) && arr[i][j]<arr[minIndexI][minIndexJ]){
                minIndexI = i;
                minIndexJ = j;
            }
        }
    }
    printf("\nМінімальний елементи: %d індекси i:%d j:%d",arr[minIndexI][minIndexJ], minIndexI, minIndexJ);
}
int main(){
    SetConsoleOutputCP(CP_UTF8);

    int n, m;

    do{
        printf("Введіть натуральне число n: ");
        scanf("%d", &n);
    }while (n<=0);
    do{
        printf("Введіть натуральне число m: ");
        scanf("%d", &m);
    }while (m<=0);
    int arr[n][m];
    srand(time(NULL));
    createArr(n, m, arr);
    sumRows(n, m, arr);
    productColum(n, m, arr);
    minElem(n, m, arr);
}