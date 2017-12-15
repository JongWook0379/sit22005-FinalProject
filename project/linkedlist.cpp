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

//////////////////////////////////////////////////////////////
// LinkedList Manager
