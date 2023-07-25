 #include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int numItems) {
    int dp[numItems + 1][capacity + 1];

    // Initialize the DP table
    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Final result is in the bottom-right cell of the DP table
    return dp[numItems][capacity];
}

int main() {
    int numItems, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    int weights[numItems], values[numItems];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapsack(capacity, weights, values, numItems);
    printf("Maximum value in the knapsack = %d\n", maxValue);

    return 0;
}
