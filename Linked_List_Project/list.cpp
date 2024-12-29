/** 
 * Implementation file for List class functions
 * 
 * @author Troy Butler
 * @date 12/29/2024
 */ 

#include <sstream>
#include <iostream>
#include <cstdlib>
#include "list.h"

List::List() {
    // Initialize object with default values
    this->headNode = nullptr;
    this->listSize = 0;
}

void List::addNode(int v) {
    // Case 1: empty list
    if (this->empty()) {
        this->headNode = new Node(v);
    }
    // Case 2: non-empty list
    else {
        Node* temp = this->headNode;
        // Find last node in list
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        // Add node at end
        temp->setNext(new Node(v));
    }
    // Update list size
    this->listSize++;
}

void List::addRandom(int n) {
    // Add n nodes to end of list
    for (int i = 0; i < n; i++) {
        addNode(rand() % 99 + 1);
    }
}

void List::insertStart(int v) {
    // Case 1: empty list
    if (this->empty())
        this->addNode(v);
    // Case 2: non-empty list
    else {
        // Temporary pointer to current first node
        Node* temp = this->headNode;
        // Add new node at start and update pointers
        this->headNode = new Node(v);
        this->headNode->setNext(temp);
        // Update list size
        this->listSize++;
    }    
}

void List::insertAt(int p, int v) {
    // Case 1: insert at start of list
    if (p == 0) {
        this->insertStart(v);
    }
    // Case 2: insert at end of list
    else if (p == this->size()) {
        this->addNode(v);
    }
    // Case 3: insert elsewhere in list
    else {
        // Temporary pointers
        Node* prevNode = this->headNode;
        Node* currNode = this->headNode;
        // New node to insert
        Node* tempNode = new Node(v);
        int pos = 0;
        // Find specified index in list
        while (currNode->getNext() != nullptr && pos < p) {
            pos++;
            prevNode = currNode;
            currNode = currNode->getNext();
        }
        // Update pointers to accommodate new node
        prevNode->setNext(tempNode);
        tempNode->setNext(currNode);
        // Update list size
        this->listSize++;
    }
}

void List::removeFirst() {
    // Temporary pointer to first node
    Node* temp = this->headNode;
    // Update headnode pointer
    this->headNode = this->headNode->getNext();
    // Deallocate memory for removed node
    delete temp; 
    // Update list size
    this->listSize--;  
}

void List::removeLast() {
    // Temporary pointers
    Node* prevNode = this->headNode;
    Node* currNode = this->headNode;
    // Case 1: List contains only one node
    if (currNode->getNext() == nullptr) {
        // Update pointer
        this->headNode = nullptr;
        // Deallocate memory for removed node
        delete currNode;
    }
    // Case 2: List contains more than one node
    else {
        // Find last two nodes in list
        while (currNode->getNext() != nullptr) {
            prevNode = currNode;
            currNode = currNode->getNext();
        }
        // Update pointers
        prevNode->setNext(currNode->getNext());
        // Deallocate memory for removed node
        delete currNode;
    }
    // Update list size
    this->listSize--;
}

void List::removeAt(int p) {
    // Temporary pointer
    Node* currNode = this->headNode;
    // Case 1: remove start node
    if (p == 0) {
        // Update headnode pointer
        this->headNode = this->headNode->getNext();
        // Deallocate memory for removed node
        delete currNode;
    }
    // Case 2: remove any other node
    else {
        // Second temporary pointer
        Node* prevNode = this->headNode;
        int pos = 0;
        // Find node to remove along with its predecessor
        while (currNode->getNext() != nullptr && pos != p) {
            prevNode = currNode;
            currNode = currNode->getNext();
            pos++;
        }
        // Update pointers
        prevNode->setNext(currNode->getNext());
        // Deallocate memory for removed node
        delete currNode;
    }
    // Update list size
    this->listSize--;
}

void List::removeValue(int v) {
    // Only execute if list is non-empty
    if (!this->empty()) {
        // Temporary node pointers
        Node* prevNode = this->headNode;
        Node* currNode = this->headNode;
        // Case 1: Value found at start of list
        if (currNode->getValue() == v) {
            this->headNode = currNode->getNext();
            delete currNode;
            // Update list size
            this->listSize--; 
        }
        // Case 2: Value not found at start of list
        else {
            // Traverse list until value found or end of list reached
            while (currNode->getValue() != v && currNode->getNext() != nullptr) {
                prevNode = currNode;
                currNode = currNode->getNext();
            }
            // If value found, update pointers
            if (currNode->getValue() == v) {
                prevNode->setNext(currNode->getNext());
                // Deallocate memory for removed node
                delete currNode;
                // Update list size
                this->listSize--; 
            }
        }              
    }
}

void List::clear() {
    // Execute only if list is non-empty
    if (!this->empty()) {
        // Temporary copy of list size to prevent miscounts as list size changes
        int count = this->listSize;
        // Repeatedly remove first node until list is empty
        for (int i = 0; i < count; i++) {
            this->removeFirst();
        }
    }
}

void List::reverse() {   
    // Temporary pointers 
    Node* reversed = nullptr;
    Node* currNode = nullptr;
    // Traverse list and update pointers so list is in reverse order
    while (this->headNode != nullptr) {
        currNode = this->headNode;
        this->headNode = this->headNode->getNext();
        currNode->setNext(reversed);
        reversed = currNode;
    }
    // Update headnode pointer
    this->headNode = reversed;
}

void List::sort() {
    // Call mergeSort() function and update headnode pointer
    this->headNode = this->mergeSort(this->headNode);
}

Node* List::mergeSort(Node* start) {
    // Base Case
    if (start == nullptr || start->getNext() == nullptr) {
        return start;
    }

    // Recursive Case
    // Temporary pointers
    Node* left = start;
    Node* mid = start;
    Node* endPtr = start;

    // Find midpoint in current sublist using fast/slow pointer method
    while (endPtr->getNext() != nullptr && endPtr->getNext()->getNext() != nullptr) {
        mid = mid->getNext();
        endPtr = endPtr->getNext()->getNext();        
    }

    // Set pointer to start of right sublist
    Node* right = mid->getNext();
    // Separate left and right sublists
    mid->setNext(nullptr); 

    // Recursive mergeSorts of left and right sublists
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge sorted nodes
    Node* merged = merge(left, right);
    return merged;
}

Node* List::merge(Node* left, Node* right) {  
    // Temporary pointers
    Node* startNode = nullptr;  
    Node* currNode = nullptr;
    // Variable to handle special case of empty merged list
    bool empty = true;

    // Case 1: left and right sublists contain nodes
    while (left != nullptr && right != nullptr) {
        // Add left node if left node value is smallest
        if (left->getValue() <= right->getValue()) {
            // Merged list is empty
            if (empty) {
                startNode = left;
                currNode = startNode;
            }
            // Merged list is non-empty
            else {
                currNode->setNext(left);
                currNode = currNode->getNext();
            }
            // Increment left sublist pointer
            left = left->getNext();
        }
        // Add right node if right node value is smallest
        else {
            // Merged list is empty
            if (empty) {
                startNode = right;
                currNode = startNode;
            }
            // Merged list is non-empty
            else {
                currNode->setNext(right);
                currNode = currNode->getNext();
            }
            // Increment right sublist pointer
            right = right->getNext();
        }
        // Merged list is now non-empty
        empty = false;
    }

    // Case 2: left sublist contains nodes but right sublist is empty
    while (left != nullptr) {
        // Add all nodes in left sublist to merged list
        currNode->setNext(left);
        currNode = currNode->getNext();
        // Increment left sublist pointer
        left = left->getNext();
    }

    // Case 3: right sublist contains nodes but left sublist is empty
    while (right != nullptr) {
        // Add all nodes in right sublist to merged list
        currNode->setNext(right);
        currNode = currNode->getNext();
        // Increment right sublist pointer
        right = right->getNext();
    }

    return startNode;
}

bool List::empty() {
    // Check size of current list
    if (this->size() == 0)
        return true;
    return false;
}

int List::size() {   
    // Fetch size of current list
    return this->listSize;
}

int List::find(int v) {
    // Temporary pointer
    Node* temp = this->headNode;
    // Temporary variable to track index of each node
    int index = 0;
    // Traverse list until end of list reached or value found
    while (temp != nullptr && temp->getValue() != v) {        
        temp = temp->getNext();
        index++;
    }
    // Check if value was found
    if (temp == nullptr)
        index = -1;
    return index;
}

std::string List::toString() {
    // Temporary pointer
    Node* temp = this->headNode;
    // Declare string stream object
    std::stringstream tempStream;
    // Traverse list and add node values to string stream
    tempStream << "{";
    while (temp != nullptr) {
        tempStream << temp->getValue();
        if (temp->getNext() != nullptr)
            tempStream << ", ";
        temp = temp->getNext();
    }
    tempStream << "}";
    return tempStream.str();
}

List::~List() {
    // Temporary pointer
    Node* temp = this->headNode;
    // Traverse list
    while (temp != nullptr) {
        // Update headnode pointer to next node in list
        this->headNode = this->headNode->getNext();
        // Deallocate memory for current node
        delete temp;
        // Update temporary pointer to next node in list
        temp = this->headNode;
    }
}