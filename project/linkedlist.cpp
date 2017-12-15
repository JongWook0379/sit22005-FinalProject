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
        value[strlen(val)] = '\0'
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







