#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int id;
    int value;
    int weight;
    double ratio; // value-to-weight ratio
} Item;

// Comparison function used by qsort to sort items by ratio in descending order
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Function to calculate the maximum value possible
double fractionalKnapsack(Item items[], int n, int capacity) {
    // 1. Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // 2. Sort items by ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    int currentWeight = 0;
    double totalValue = 0.0;

    printf("\n--- Selection Process ---\n");
    for (int i = 0; i < n; i++) {
        // If adding the complete item won't overflow capacity
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d taken fully (Weight: %d, Value: %d)\n", 
                   items[i].id, items[i].weight, items[i].value);
        } 
        // If we can only take a fraction of the item
        else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            printf("Item %d taken fractionally: %d/%d units (Value added: %.2f)\n", 
                   items[i].id, remainingCapacity, items[i].weight, 
                   items[i].value * ((double)remainingCapacity / items[i].weight));
            break; // The knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(items, n, capacity);
    
    printf("\nMaximum profit earned = %.2f\n", maxProfit);

    free(items);
    return 0;
}
