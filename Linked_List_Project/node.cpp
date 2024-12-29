/**
 * Implementation file for Node class functions
 * 
 * @author Troy Butler
 * @date 12/29/2024
 */

#include "node.h"

bool Node::setValue(int v) {
    // Set node value
    this->value = v;
    // Check that node value was updated correctly
    if (this->value == v) {
        return true;
    }
    return false;
}

bool Node::setNext(Node* a) {
    // Set node pointer
    this->next = a;
    // Check that node pointer was updated correctly
    if (this->next == a) {
        return true;
    }
    return false;
}