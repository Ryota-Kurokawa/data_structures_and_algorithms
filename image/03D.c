#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20000

// スタックの構造体
typedef struct {
    int *data;
    int size;
    int capacity;
} Stack;

// スタックを初期化する関数
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

// スタックにプッシュする関数
void push(Stack *stack, int value) {
    if (stack->size < stack->capacity) {
        stack->data[stack->size++] = value;
    }
}

// スタックからポップする関数
int pop(Stack *stack) {
    if (stack->size > 0) {
        return stack->data[--stack->size];
    }
    return -1;
}

// スタックを空にする関数
int isEmpty(Stack *stack) {
    return stack->size == 0;
}

// スタックを解放する関数
void freeStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

int main() {
    char terrain[MAX_LENGTH];
    scanf("%s", terrain);
    
    int n = strlen(terrain);
    Stack *startStack = createStack(n);
    Stack *areaStack = createStack(n);
    
    int totalArea = 0;
    int numPuddles = 0;
    int puddleAreas[MAX_LENGTH];
    
    for (int i = 0; i < n; i++) {
        if (terrain[i] == '\\') {
            push(startStack, i);
        } else if (terrain[i] == '/' && !isEmpty(startStack)) {
            int start = pop(startStack);
            int area = i - start;
            totalArea += area;
            
            while (!isEmpty(areaStack) && areaStack->data[areaStack->size - 1] > start) {
                area += pop(areaStack);
            }
            
            puddleAreas[numPuddles++] = area;
            push(areaStack, area);
        }
    }
    
    printf("%d\n", totalArea);
    printf("%d", numPuddles);
    for (int i = 0; i < numPuddles; i++) {
        printf(" %d", puddleAreas[i]);
    }
    printf("\n");
    
    freeStack(startStack);
    freeStack(areaStack);
    
    return 0;
}
