#include<stdio.h>
    #include<stdlib.h>
    #include<math.h>

    void floyd(double weight[][100], int n);
    void printMinGraph(double weight[][100], int n);

    void main(){
        int n, i, j;
        double weight[100][100];

        printf("Enter the number of vertices: ");
        scanf("%d", &n);

        printf("Enter the vertice edges in matrix form! Enter 999 for infinite!\n");
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%lf", &weight[i][j]);
                if(weight[i][j] == -1)
                    weight[i][j] = pow(10, 7);
            }
        }
        floyd(weight, n);
        printf("\nMinimum distance graph is:\n");
        printMinGraph(weight, n);
    }

    void floyd(double weight[][100], int n){
        int i, j, k;

        for(k=0; k<n; k++)
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    if(weight[i][k] + weight[k][j] < weight[i][j])
                        weight[i][j] = weight[i][k] + weight[k][j];
    }

    void printMinGraph(double weight[][100], int n){
        int i, j;
        printf("\t");
        for(i=0; i<n; i++)
            printf("%d\t\t", i+1);
        printf("\n");
        for(i=0; i<n; i++){
            printf("%d\t", i+1);
            for(j=0; j<n; j++){
                if(weight[i][j] == pow(10, 7))
                    printf("INF\t");
                else
                    printf("%.2f\t", weight[i][j]);
            }
            printf("\n");
        }
    }
