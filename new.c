#include<stdio.h>
#include<stdlib.h>

#define n 3 
struct huffman
{
    char c;
    int freq;
};

typedef struct huffman st ;

struct node
{
    st *left , *right;
    int total ;
};

int main()
{
    char a ;
    st *arr[n], *temp = (st*)malloc(sizeof(st)) ;
    struct node* new[n];

    for (int i = 0; i < n ; i++)
    {
        arr[i] = (st*)malloc(sizeof(st));
        printf("Enter Character and frequency :");
        scanf("%c",&arr[i]->c);
        scanf("%d",&arr[i]->freq);
        scanf("%c", &a);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c -> %d\n",arr[i]->c, arr[i]->freq);
    }
    for (int j = 0, i = 0; i < n-j; i++)
    {
        for ( j = 0; j < n-1 ; j++)
        {
            if ( arr[j]->freq < arr[j+1]->freq )
            {
                temp->c = arr[j]->c;
                arr[j]->c = arr[j+1]->c;
                arr[j+1]->c = temp->c ;

                temp->freq = arr[j]->freq;
                arr[j]->freq = arr[j+1]->freq;
                arr[j+1]->freq = temp->freq ;
            }   
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c -> %d\n",arr[i]->c, arr[i]->freq);
    }

    for ( int x = 0, i = n-2; i >= 2 ; i++ )
    {
        new[x] = (struct node*)malloc(sizeof(struct node));
        struct node *l , *r ;
        l = r = (struct node*)malloc(sizeof(struct node));
        l->total = arr[i]->freq ;      
        r->total = arr[i+1]->freq ;
        new[x]->left = arr[i] ;           //st *l , *r ;       l = arr[i];      r = arr[i+1];
        new[x]->right = arr[i+1] ;
        new[x]->total = arr[i]->freq + arr[i+1]->freq ;
    }
    
}

void print_node(struct node* root, int arr[], int top) 
{
    if (root->left) 
    {
        arr[top] = 0;
        print_node(root->left, arr, top + 1);
    }

    if (root->right) 
    {
        arr[top] = 1;
        print_node(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) 
    {
        printf("'%c': ", root->total );
        for (int i = 0; i < top; i++) 
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

