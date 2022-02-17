#define TList EnemNode // Llamamos al tipo genérico EnemNode como TList

void CrearList(EnemNode **List)
{
    *List = nullptr;
}

bool ListEmpty(EnemNode *List)
{
    // Checking if list is empty.
    return (List == nullptr);
}

bool InsertarList(EnemNode **List, int value, Enemy enem)
{
    // Insertion of the new node in the list.
    EnemNode *newnode;
    // Allocates space to store new node in the list.
    if ((newnode = (EnemNode *)malloc(1 * sizeof(EnemNode))) == nullptr)
    {
        // No memory.
        return false;
    }
    else
    {
        // Memory available.
        // Loads content.
        newnode->index = value;
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

/*
EnemNode *IndexList(EnemNode *List,int indice){
    EnemNode *p;
    //Recorrido sobre List con desplazamiento offset entre los elementos de la List
    //con acceso directo a la posición índice

    if(indice>=0 && !ListEmpty(List)){
      p=List;
      for(int i=0;p->next!=nullptr && i<indice;i++){
        p=p->next;
      }
      return p;
    }
    else return nullptr;
}
*/

EnemNode *SearchInList(EnemNode *List, int value, int option)
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
}

void DelFromList(EnemNode **List, int value)
{
    EnemNode *p, *q;
    if (!ListEmpty(*List))
    {
        p = *List;
        if (p->index == value)
        {
            *List = p->next;
            free(p);
        }
        else
        {
            // Using -1 SearchInList.
            // The previous one to the containing one.
            p = SearchInList(*List, value, -1);
            // Locating q node (.. next to last...).
            q = p->next;
            if (p != nullptr)
            {
                p->next = q->next;
                free(q); // Free used memory.
            }
        }
    }
}

int ListLength(EnemNode *List)
{
    EnemNode *p;
    p = List;
    int length;
    for (p = List; p != nullptr; p = p->next)
    {
        length++;
    }
    return length;
}

EnemNode DelWholeList(EnemNode *List)
{
    if (!ListEmpty(List))
    {
        for (int i = 0; i < ListLength(List); i++)
        {
            DelFromList(&List, i);
        }
    }
    return *List;
}
