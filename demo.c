#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node * prev ; 
        int val ; 
    struct Node * next;
};

void Display ( struct Node * Head , struct Node * Tail)
{
    int iCount = 0 ;
    if ( Head == NULL && Tail == NULL)
    {
        return;
    }

    do
    {
        printf(" : %d :", Head -> val);
        Head = (Head) -> next;

    }while(Head != Tail -> next);
            printf ( "\n");

}

int Count ( struct Node * Head , struct Node * Tail)
{
    int iLength = 0 ;
    if ( Head != NULL && Tail != NULL)
    {
    
    do {
        iLength++;
        Head = (Head) -> next;
    }while(Head != Tail -> next);
    }

    return iLength;
}

void InsertFirst (struct Node ** Head , struct Node ** Tail , int No )
{
    struct Node * newn = (struct Node *) malloc(sizeof(struct Node));
        newn -> prev = NULL;
        newn -> val = No;
        newn -> next = NULL;

    if ( *Head == NULL && *Tail == NULL)
    {
        *Head = newn ;
        *Tail = newn ;
    }
    else
    {
        newn -> next = *Head;
        (*Head) -> prev = newn ;
        *Head = newn;

    }
        (*Head) -> prev = *Tail;
        (*Tail) -> next = *Head;
}

void InsertLast (struct Node ** Head , struct Node ** Tail , int  No )
{
    struct Node * newn = ( struct Node * ) malloc(sizeof(struct Node));
        newn -> prev = NULL;
        newn -> val = No;
        newn -> next = NULL;

    if ( *Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn ;
    }
    else{
        (*Tail) -> next = newn;
        newn -> prev = *Tail;
        *Tail = (*Tail) -> next;
    }
    (*Head) -> prev  = *Tail;
    (*Tail) -> next = *Head;
}


void InsertAtPos (struct Node ** Head , struct Node ** Tail , int iPos, int No )
{
    int iLength = Count( *Head , *Tail );
    if ( iPos < 1 || iPos > iLength +1)
    {
        return ;
    }

    if ( iPos == 1)
    {
        InsertFirst ( Head , Tail  , No);
    }
    else if ( iPos == iLength + 1)
    {
        InsertLast(Head , Tail , No);
    }
    else
    {
        struct Node * newn = ( struct Node *) malloc(sizeof(struct Node));
                    newn -> prev = NULL;
                    newn -> val = No;
                    newn -> next = NULL;

        struct Node * temp = *Head;

    for ( int iCnt = 1 ; iCnt < iPos - 1 ; iCnt++ )
    {
        temp = temp -> next;
    }
    newn -> next = temp -> next;
    temp -> next -> prev = newn;

    newn -> prev = temp ;
    temp -> next = newn;
    }
}

void DeleteLast (struct Node ** Head , struct Node ** Tail )
{
    if ( *Head == NULL && *Tail == NULL)
    {
        return ;
    }
    else if ( (*Head )-> next == NULL)
    {
        free( *Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else 
    {
        *Tail = (*Tail) -> prev;
        free (( *Tail) -> next);
    }
    (*Head) -> prev = *Tail;
    (*Tail) -> next = *Head;
}

void DeleteFirst (struct Node ** Head , struct Node ** Tail )
{
    if ( *Head == NULL && *Tail == NULL)
    {
        return ;
    }   
    else if ( (*Head ) -> next == NULL)
    {
        free( *Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else 
    {
        *Head = (*Head) -> next;
        free((*Head) -> prev);
    }

    (*Head ) -> prev = *Tail;
    (*Tail) -> next = *Head;
}
void DeleteAtPos (struct Node ** Head , struct Node ** Tail , int iPos )
{
    int iLength = Count( *Head , *Tail);
    if ( iPos < 1 || ( iPos > iLength +1  ))  
    {
        return;
    }
    if ( iPos == 1)
    {
        DeleteFirst(Head , Tail);
    }
    else if (iPos == iLength)
    {
        DeleteLast ( Head , Tail);
    }
    else
    {
        struct Node * temp = *Head;
        for ( int iCnt = 1 ; iCnt < iPos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        free(temp -> next -> prev);
        temp -> next -> prev  = temp;
    }
}


int main()
{
    struct Node * First = NULL;
    struct Node * Last = NULL;

 int iRet = 0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);
    InsertAtPos(&First, &Last, 4 , 55);

    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);

    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);

    DeleteAtPos(&First, &Last, 4);
    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&First, &Last);
    DeleteLast(&First, &Last);
    
    Display(First,Last);

    iRet = Count(First,Last);
    printf("Number of nodes are : %d\n",iRet);


    return 0;
}