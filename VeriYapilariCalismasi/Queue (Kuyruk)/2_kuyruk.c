#include<stdlib.h>
#include<stdio.h>
struct queue{
    int start,end;
    int *elements;
};
void removee(struct queue *q){
    if(q->start==q->end){
        printf("QUEUE UNDERFLOW...\n");
        system("pause");
    }
    q->elements[q->start]=NULL;
    for(int i=0;i<q->end;i++)
        q->elements[i]=q->elements[i+1];
    q->elements[q->end-1]=NULL;
    q->end--;
}
void insertt(struct queue *q, int a){
    if(q->elements==NULL)
        q->elements=(int*)malloc(sizeof(int));
        
    else{
        sizeof(q->elements)++;
        q->elements=(int*)realloc(q->elements, (sizeof(q->elements))*(sizeof(int)));
    }
    
	q->elements[q->end]=a;
	
    q->end++;
}
int main(){
    struct queue q;
    q.start=0;
    q.end=0;
    q.elements = NULL;
    
int selection=0;
    while(selection!=4){
        printf("1. INSERT\n");
        printf("2. REMOVE\n");
        printf("3. LISTING\n");
        printf("4. EXIT\n\n");
        printf("PLEASE MAKE A SELECTION: "); 
        scanf("%d",&selection);
        switch(selection){
            case 1:
                printf("ENTER THE INTEGER THAT YOU INSERT: "); 
                int add;
                scanf("%d", &add);
                insertt(&q, add);
                break;
            case 2:
                removee(&q);
                break;
            case 3:
                for(int i=0;i<q.end;i++)
                    printf("%d ", q.elements[i]);
                printf("\n");
                break;          
        }
        if(q.end==0){
            printf("QUEUE UNDERFLOW...\n");
            break;
        }
    }
    system("pause");
}