#ifndef NODE_H
#define NODE_H

#include <string>

/**
 * A class representing each node stored in a linked list List object.
 * 
 * @author Troy Butler
 * @date 12/29/2024
 */
class Node {
    private:
        int value;
        Node* next;
    
    public:
        /**
         * Node class constructor. Creates a Node object
         * and initializes private variables.
         * 
         * @param v a value to store in the node.
         */
        Node(int v) : value{v}, next{nullptr} {}

        /**
         * Set the value of a Node object.
         * 
         * @param v a value to store in the node.
         * @return true if the value was updated, false otherwise.
         */
        bool setValue(int v);

        /**
         * Set the address of the next pointer in a Node object.
         * 
         * @param a the address of another Node object.
         * @return true if the address was updated, false otherwise.
         */
        bool setNext(Node* a);

        /**
         * Get the current value stored in a Node object.
         * 
         * @return the value stored in a Node object.
         */
        int getValue() {return value;}

        /**
         * Get the next Node address stored in a Node object.
         * 
         * @return a pointer to the next Node object.
         */
        Node* getNext() {return this->next;}
};

#endif