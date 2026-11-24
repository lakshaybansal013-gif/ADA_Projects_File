
#include <stdio.h>

int main() {
    int n, capacity;
    int value[100], weight[100], id[100];
    float ratio[100];
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);

        if (weight[i] <= 0 || value[i] < 0) {
            printf("Invalid value or weight.\n");
            return 1;
        }

        ratio[i] = (float)value[i] / weight[i];
        id[i] = i + 1;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    if (capacity < 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    // Sort items in descending order of ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (ratio[j] < ratio[j + 1]) {

                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                int temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }

    // Select items greedily
    int remainingCapacity = capacity;

    printf("\nSelected Items:\n");

    for (int i = 0; i < n; i++) {

        if (remainingCapacity == 0)
            break;

        if (weight[i] <= remainingCapacity) {

            // Take complete item
            remainingCapacity -= weight[i];
            totalProfit += value[i];

            printf("Item %d taken completely\n", id[i]);
        }

        else {

            // Take fractional item
            float fraction =
                (float)remainingCapacity / weight[i];

            totalProfit += value[i] * fraction;

            printf("Item %d taken fractionally: %.2f\n",
                   id[i], fraction);

            remainingCapacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
