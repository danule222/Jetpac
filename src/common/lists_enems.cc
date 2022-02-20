#define TList EnemNode // Llamamos al tipo genérico EnemNode como TList
// #include "structs.cc"
#include <stdlib.h>


void CrearList(EnemNode **List)
{
    *List = nullptr;
}

bool ListEmpty(EnemNode *List)
{
    // Checking if list is empty.
    return (List == nullptr);
}

bool InsertarList(EnemNode **List, Enemy aux_enem)
{
    // Insertion of the new node in the list.
    EnemNode *newnode;
    // Allocates space to store new node in the list.
    if ((newnode = (EnemNode *) malloc(1 * sizeof(EnemNode))) == nullptr)
    {
        // No memory.
        return false;
    }
    else
    {
        //Copy the aux_enem in the new node.
        newnode->enem = aux_enem;
        // Memory available.
        // Loads content.
        newnode->next = nullptr;
        // Linking new node to the list.
        // If first node, ->
        if (ListEmpty(*List))
        {
            *List = newnode;
        }
        else
        {
            newnode->next = *List;
            *List = newnode;
        }
        return true;
    }
}

/*
void ShowList(EnemNode *List){
    EnemNode *p;
    //Recorrido base de List con puntero auxiliar p

    for(p=List;p!=nullptr;p=p->next){
        printf("%d, ",p->index);
    }
}
*/


EnemNode *IndexList(EnemNode *List, int index){
    EnemNode *p;
    //Recorrido sobre List con desplazamiento offset entre los elementos de la List
    //con acceso directo a la posición índice

    if(index >=0 && !ListEmpty(List)){
      p=List;
      for(int i=0;p->next!=nullptr && i<index;i++){
        p=p->next;
      }
      return p;
    }
    else return nullptr;
}


/*EnemNode *SearchInList(EnemNode *List, int value, int option)
{
    // Búsqueda de elemento en la List por contenido de nodo con posibilidad de acceso al nodo localizado, parámetro 0
    // o con posibilidad de acceso al nodo anterior al nodo que contiene el value (se usará para eliminación)
    EnemNode *p;
    bool found = false;

    if (!ListEmpty(List))
    {
        p = List;
        // Using do while to control the advancement of the pointer.
        do
        {
            switch (option)
            { // Deciding if we're searching current position or one before.
            case 0:
                found = (p->index == value); 
                break;
            case -1:
                found = (p->next->index == value); 
                break;
            }

            if (!found)
            {
                p = p->next; // Stop advancing when found.
            }
        } while (!found && p != nullptr);
    }
    return p;
}*/

void DelFromList(EnemNode **List, int index)
{
    EnemNode *p, *q;
    if (!ListEmpty(*List))
    {
        p = *List;
       if(index == 0){
           *List = p->next;
           free(p);
       }else{
           p = IndexList(*List, index - 1);
           q = p->next;
           p->next = q->next;
           free(q);
       }
    }
}

int ListLength(EnemNode *List)
{
    EnemNode *p;
    p = List;
    int length = 0;
    for (p = List; p != nullptr; p = p->next)
    {
        length++;
    }
    return length;
}

void DelWholeList(EnemNode **List)
{
    if (!ListEmpty(*List))
    {
        for (int i = 0; i < ListLength(*List); i++)
        {
            DelFromList(List, 0);
        }
    }
}
