# Linked List Implementation in C++

A comprehensive implementation of a singly linked list data structure featuring common operations such as insertion, deletion, reversal, and sorting. Dynamic memory allocation is used for node management.
The implementation includes an optimized in-place merge sort algorithm (O(nlogn)) and an efficient list reversal algorithm (O(n)).

This program was built as a refresher project to practice C++ and linked list implementations, and was developed without the help of generative AI, online resources, or course notes.

Note: generative AI was used for the creation of the makefile.

## Features
- Add nodes (start/end/index)
- Remove nodes (start/end/index/value)
- List operations (empty/size/find/clear)
- Reverse list - O(n) time complexity
- Sort list - In-place merge sort, O(nlogn) time complexity
- String conversion for display

## How to Use
Download the project directory to a local device. In a terminal environment, navigate to the project directory and use the makefile commands outlined below.

## Build and Run
Project includes a cross-platform makefile. From the project directory:
```bash
make        # compile
make run    # execute
make clean  # cleanup
