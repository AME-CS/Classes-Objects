/*
 * This is a program that will create a “list” like object that behaves similarly to the List object in Python.
 * Note the header structure and files.
 * The only thing included in mylist.cpp is this functions.h file
 * mylist.h contains all directives for functions.cpp
 */
/* 
 * File:   mylist.h
 * Author: Ahmed Eid
 */

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand, atoi */
#include <time.h>       /* time */


#define RMIN 1
#define RMAX 10
#define default 1
#define init 0

class MyList {
public:

    MyList(int); 
    ~MyList(); 

    
    int getElement(int);
    bool getElement(int, int*);
    int getLength();
    bool getSorted();


    void setArray(int);
    bool setElement(int, int);
    void setRandom(int, int);

    void sort();
    void printArray();
    bool resizeArray(int);
    int findElement(int);


private:
    void swap(int*, int*);
    bool sorted;
    int length;
    int *array;
    int binsearch(int);
    int linsearch(int);
};

#endif //MYLIST_H
