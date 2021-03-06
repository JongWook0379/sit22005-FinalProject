#include "linkedlist.h"
#include <stdlib.h>
#include <cstring>

//////////////////////////////////////////////////////////////
// Node
Node::Node(Node* next, NodeType node)
:pNext(next), node_type(node)
{
    
}


//////////////////////////////////////////////////////////////
// IntegerNode
IntegerNode::IntegerNode()
:Node(nullptr, INT_NODE)
{
    
}

int IntegerNode::get_value()
{
    return value;
}

void IntegerNode::set_value(int val)
{
    value=val;
}

//////////////////////////////////////////////////////////////
// StringNode
StringNode::StringNode()
:Node(nullptr, STRING_NODE)
{
    
}


StringNode::STRING_NODE(char* val, Node* next)
:Node(next, STRING_NODE)
{
    value = new char[strlen(val)+1];
    strcpy(vale, val);
    value[strlen(val)] = '\0'
}

StringNode::~StringNode()
{
    delete [] value;
}

char* StringNode::get_value()
{
    return value;
}

void StringNode::set_value(char* val)
{
    if(value != val)
    {
        delete [] value;
        value = new char[strlen(val)+1];
        strcpy(value, val);
        value[strlen(val)] = '\0';
    }
}


//////////////////////////////////////////////////////////////
// LinkedList Manager
linkedlist::linkedlist()
:pHead(nullptr)
{
    
}

void linkedlist::InsertToFront(int val)
{
    IntegerNode* inode = new IntegerNode(val, pHead);
    pHead = inode;
}


void linkedlist::InsertToBack(int val)
{
    if(isEmpty())
    {
        InsertToFront(val);
    }
    else
    {
        Node* last_node = find_prev_node(nullptr);
        
        IntegerNode* inode = new IntegerNode(val, nullptr);
        last_node -> set_next(inode);
    }
}


int linkedlist::RemoveFromFront_Integer()
{
    int temp=0;
    if(!isEmpty())
    {
        Node* cur = pHead;
        IntegerNode* inode = static_cast<IntegerNode*>(cur);
        temp = inode -> get_value();
        
        pHead = cur -> get_next();
        
        delete cur;
    }
    return temp;
}

void linkedlist::InsertToBack(int val)
{
    if(isEmpty())
    {
        InsertToFront(val);
    }
    else
    {
        Node* last_node = find_prev_node(nullptr);
        
        IntegerNode* inode = new IntegerNode(val, nullptr);
        last_node -> set_next(inode);
    }
}

int linkedlist::RemoveFromFront_Integer()
{
    int temp = 0;
    if(!isEmpty())
    {
        Node* cur = pHead;
        IntegerNode* inode = static_cast<IntegerNode*>(cur);
        temp = inode -> get_value();
        
        pHead = cur -> get_next();
        
        delete cur;
    }
    return temp;
    
}



int linkedlist::RemoveFromBack_Integer()
{
    int temp = 0;
    if(!isEmpty())
    {
        if(pHead -> get_next() == nullptr)
        {
            IntegerNode* inode = static_cast<IntegerNode*>(pHead);
            temp = inode -> get_value();
        
            delete inode;
        
            pHead = nullptr;
        }
        else
        {
            Node* last_node = find_prev_node(nullptr);
            Node* prev_node = find_prev_node(last_node);
            prev_node -> set_next(nullptr);
            IntegerNode* inode = static_cast<IntegerNode*>(last_node);
            temp = inode -> get_value();
        
            delete inode;
        }
    }
    return temp;
}


void linkedlist::InsertToFront(char* val)
{
    struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    *new = *newNode;

    new->next = target->next;
    target->next = new;

    return new;
}

void linkedlist::InsertToBack(char* val)
{
    struct Node *del;
    del = target->next;
    if(del==NULL) {
        return 0;
    }
    target->next = del->next;
    free(del);
    return 1;    
}

char* linkedlist::RemoveFromBack_String()
{
    char* temp;
    return temp;
}


char* linkedlist::RemoveFromBack_String()
{
    char* temp;
    return temp;
}

bool linkedlist::isEmpty()
{
    return pHead == nullptr? true:false;
}

Node* linkedlist::find_prev_node(Node* next)
{
    Node* cur = pHead;
    if(next == cur)
    {
        return nullptr;
    }
    
    while(cur -> get_next() != next && cur != nullptr)
    {
        cur = cur -> get_next();
    }
    
    return cur;
}

void linkedlist::print(std::ostream& os)
{
    for(Node* cur = pHead; cur != nullptr; cur = cur -> get_next())
    {
        if(cur -> get_node_type() == INT_NODE)
        {
            IntegerNode* node = static_cast<IntegerNode*>(cur);
            os << node->get_value() << " ";
        }
        else if(cur -> get_node_type() == STRING_NODE)
        {
            StringNode* node = static_cast<StringNode*>(cur);
            os << node->get_value() << " ";
        }
    }
    os << std::endl;
}


void linkedlist::InsertNextTo(int find_val, int val)
{
    struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    *new = *newNode;

    new->next = target->next;
    target->next = new;

    return new;
}

void linkedlist::InsertNextTo(char* find_val, char val)
{
    struct Node *new;
    new = (struct Node*)malloc(sizeof(struct Node));
    *new = *newNode;

    new->next = target->next;
    target->next = new;

    return new;    
}

void linkedlist::RemoveNode(int val)
{
  if(*cur == NULL || del == NULL)
    return;
 
  if(*cur == del)
    *head_ref = del->next;
 
  if(del->next != NULL)
    del->next->prev = del->prev;
 
  if(del->prev != NULL)
    del->prev->next = del->next;     
 
  free(del);
  return;
}

void linkedlist::RemoveNode(char* val)
{
  if(*cur == NULL || del == NULL)
    return;
 
  if(*cur == del)
    *head_ref = del->next;
 
  if(del->next != NULL)
    del->next->prev = del->prev;
 
  if(del->prev != NULL)
    del->prev->next = del->next;     
 
  free(del);
  return;
    
}


Node* linkedlist::find_node(int val)
{
    int i = 0;
    for (*n = root; *n != NULL && (*n)->v != v; ++i) {
        *pn = *n;
        *n = (*n)->next;
    }
    return i;   
}


Node* linkedlist::find_node(char* val)
{
    int i = 0;
    for (*n = root; *n != NULL && (*n)->v != v; ++i) {
        *pn = *n;
        *n = (*n)->next;
    }
    return i;  
}
