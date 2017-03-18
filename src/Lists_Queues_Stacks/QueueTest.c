
#include <stdio.h>
#include "LinkedQueue.h"

int main(){

    LinkedQueue* queue = createLinkedQueue();

    if(isEmpty(queue)) printf("The queue is empty \n");
    else printf("The queue isn't empty \n");

    for(int i = 0; i < 20; i++){
        enqueue(queue, i);
    }

    if(isEmpty(queue)) printf("The queue is empty \n");
    else printf("The queue isn't empty \n");

    printf("\n");
    printf("%d \n", size(queue));

    for(int i = 0; i< 20; i++){
        printf("%d ", peek(queue));
        int a = dequeue(queue);
        printf("%d ", a);
    }

    printf("\n");

    if(isEmpty(queue)) printf("The queue is empty \n");
    else printf("The queue isn't empty \n");

    printf("%d ", size(queue));

    return  0;
}
