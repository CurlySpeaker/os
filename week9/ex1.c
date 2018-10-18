#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define page_size 8

//----- Page block -----//
struct Page
{
    int name;
    int history[page_size];
};


void shift(struct Page* pages, int name, int total){
    for(int k=0;k<total;k++){
        struct Page* page = &pages[k];
        for(int i=page_size-1;i>0;i--){
            page->history[i] = page->history[i-1];
        }
        if(page->name == name){
            page->history[0]=1;
        }
        else{
            page->history[0]=0;
        }
    }
}


int zero_sum(struct Page page){
    int max = 0;
    for(int i=0;i<page_size;i++)
        if(page.history[i]==0) max += 1;
    return max;
}


struct Page* find_useless(struct Page* pages, int total){
    int most = 0;
    struct Page* page;
    for(int i=0;i<total;i++){
        if(zero_sum(pages[i])>most){
            most = zero_sum(pages[i]);
            page = &pages[i];
        }
    }
    return page;
}


int update(struct Page* pages, int name, int* free, int total){
    int found = 0;
    for (int i=0;i<total-*free;i++)
        if(pages[i].name == name){
            found = 1;
            break;
        }
    if(!found){
        if(*free>0){
            pages[total-*free].name = name;
            *free -= 1;
        }
        else{
            struct Page* most_useless = find_useless(pages, total);
            most_useless->name=name;
        }
    }

    shift(pages, name, total);
    return found;
}


//----- End page block -----//

int main()
{
    int hits=0, misses=0;
    int total;
    printf("Enter number of pages:");
    scanf("%d", &total);
    struct Page* table = malloc(total*sizeof(struct Page));
    int free = total;

    FILE* in_f = fopen("input.txt","r");
    int status;
    int name;
    while(fscanf(in_f, "%d", &name)==1){
        status = update(table, name, &free, total);
        if(status) hits += 1;
        else misses += 1;
    }

    printf("Total hits: %d\nTotal misses: %d\n", hits, misses);

    return 0;
}
