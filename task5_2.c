#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void createArr(int size_n, float arr[size_n][size_n]){
    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_n;j++){
            arr[i][j]= (rand()%201-100)/10.;
            printf("%g\t",arr[i][j]);
        }
        printf("\n");
    }
}
void findX(int size_n, float x, float arr[size_n][size_n]){
    int count=0;
   
    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_n;j++){
            if(x == arr[i][j]){
                count++;
            }
        }
    }
    printf("\nТаблиця містить %d елементів %g", count, x);
}
void findMaxMin(int size_n, float arr[size_n][size_n]){
    int maxIndexI=0, maxIndexJ=0, minIndexI=0, minIndexJ=0;
   
    for(int i=0;i<size_n;i++){
        for(int j=0;j<size_n;j++){
            if(arr[i][j]>arr[maxIndexI][maxIndexJ]){
                maxIndexI = i;
                maxIndexJ = j;
            }else if (arr[i][j]<arr[minIndexI][minIndexJ])
            {
                minIndexI = i;
                minIndexJ = j;
            }
            
        }
    }
    printf("\nМаксимальний елемент:%g\nМінімальний елемент:%g",arr[maxIndexI][maxIndexJ], arr[minIndexI][minIndexJ]);

}
int main(){
    SetConsoleOutputCP(CP_UTF8);

    srand(time(NULL));
    int n;
    do{
        printf("Введіть натуральне число n: ");
        scanf("%d", &n);
    }while (n<=0);
    float arr[n][n];
    float x;
    printf("Введіть натуральне число x (від -10 до 10): ");
    scanf("%f", &x);

    createArr(n, arr);
    findX(n, x, arr);
    findMaxMin(n, arr);
}