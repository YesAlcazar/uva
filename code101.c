#include <stdio.h>
#include <stdlib.h>


typedef struct s_node {
    struct s_node *next = NULL;
    struct s_node *previous = NULL;
} Node;

Node vetor[26];
int size;

void undoStack(Node *node)
{
    if (!node)
        return;
    undoStack(node->next);
    node->next = NULL;
    node->previous = NULL;
}

void cleanStack(Node *node)
{
    if (!node)
        return;
    undoStack(node->next);
    node->next = NULL;
}

void putBlock(Node *top, Node *bottom)
{
    bottom->next = top;
    top->previous = bottom;
}

Node* endStack(Node *node)
{
    if (node->next)
        return endStack(node->next);
    return node;
}

int readExecute()
{
    char[5] cmd1,cmd2;
    int a, b;
    scanf ("%s", cmd1);
    if (cmd1[0] ==' q') //quit
        return 0;
    else
        scanf("%d %s %d",&a,cmd2,&b);
    if (cmd1[0] == 'm')
    {
        if (cmd2[1] == 't') //onto
        {
            cleanStack(vetor[a]);
            cleanStack(vetor[b]);
            putBlock(vetor[a],vetor[b]);
        }
        else if (cmd2[1]=='v') //over
        {
            cleanStack(vetor[a]);
            putBlock(vetor[a],vetor[b]);
        }
        else
            return -2;
    }
    else if (cmd1[0] == 'p') // pile
    {
        if (cmd2[1]=='t') //onto
        {
            cleanStack(vetor[b]);
            putBlock(vetor[a],vetor[b]);
        }
        else if (cmd2[1]=='v') //over
        {
            putBlock(vetor[a],endStack(vetor[b]));
        }
        else
            return -3;
    }
    else
        return -1;
}

void printStack()
{
    int i;
    node *curr;
    for (int i = 0; i <= size; i++) {
        printf("%d:",i);
        if(vetor[i]->previous == NULL)
        {
            curr = vetor[i];
            while (curr) {
                printf(" %d",(curr-vetor));
                curr = curr->next
            }
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]) {
    int verifier;
    scanf("%d", &size);
    do {
        verifier = readExecute();
    } while(verifier > 0);
    printStack();
    return verifier;
}
