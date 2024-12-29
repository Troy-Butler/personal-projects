#ifndef LIST_H
#define LIST_H

#include <string>
#include "node.h"

/**
 * A class representing a linked list comprised of Node objects.
 * 
 * @author Troy Butler
 * @date 12/29/2024
 */
class List {
    private:
        Node* headNode;
        int listSize;

    public:
        /**
         * List class constructor. Creates an empty list object. 
         */
        List();

        /**
         * Adds a new node at the end of the list.
         * 
         * @param v value to be stored in new node.
         */
        void addNode(int v);

        /**
         * Adds n nodes to the list with randomly generated values.
         * New nodes are added to the end of the list.
         * 
         * @param n number of new nodes to be added.
         */
        void addRandom(int n);

        /**
         * Adds a new node to the start of the list. 
         * 
         * @param v value to be stored in new node.
         */
        void insertStart(int v);

        /**
         * Adds a new node at a designated index. Existing
         * nodes at or after that index are moved to the right.
         * If list is empty, new node is instead added to start.
         * 
         * @param p index to insert new node.
         * @param v value to be stored in new node.
         */
        void insertAt(int p, int v);

        /**
         * Removes node from start of list. 
         */
        void removeFirst();

        /**
         * Removes node from end of list.
         */
        void removeLast();

        /**
         * Removes node at designated index.
         * 
         * @param p index of node to be removed.
         */
        void removeAt(int p);

        /**
         * Removes the node for the first instance of a value
         * if that value exists in the list.
         * 
         * @param v value to be removed.
         */
        void removeValue(int v);

        /**
         * Removes all nodes from the list. 
         */
        void clear();

        /**
         * Reverses the order of nodes in the list in O(n) time.
         */
        void reverse();

        /**
         * Wrapper function to initiate mergeSort process.
         */
        void sort();

        /**
         * Recursively sort nodes in the list into ascending order
         * of value. Performs mergeSort in-place in O(nlogn) time.
         * 
         * @param start a pointer to the first node of an unsorted sublist.
         * @return a pointer to the first node of a sorted sublist.
         */
        Node* mergeSort(Node* start);

        /**
         * Merges two sorted sublists into a single sorted list.
         * 
         * @param left a pointer to the first node in a left sublist.
         * @param right a pointer to the first node in a right sublist.
         * @return a pointer to the start of a merged and sorted list.
         */
        Node* merge(Node* left, Node* right);

        /**
         * Checks if list is currently empty.
         * 
         * @return true if list is empty, false otherwise. 
         */
        bool empty();

        /**
         * Fetches the current list size.
         * 
         * @return the number of nodes in the list.
         */
        int size();

        /**
         * Searches nodes in the list for the first instance of
         * the specified value.
         * 
         * @param v a value to search for.
         * @return the index of the found node or -1 if not found.
         */
        int find(int v);   

        /**
         * Converts the current list to string format.
         * 
         * @return a string containing all list values.
         */
        std::string toString();

        /**
         * List class destructor. Removes and deallocates memory
         * for all existing nodes.
         * 
         */
        ~List();
};

#endif