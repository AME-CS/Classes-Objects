/*
 * This is a program that will create a “list” like object that behaves similarly to the List object in Python.
 * Note the header structure and files.
 * The only thing included here is mylist.h
 * mylist.h contains all other directives 
 */
/* 
 * File:   mylist.cpp
 * Author: Ahmed Eid
 */

#include "mylist.h"

// constructor
MyList::MyList(int size) {
    srand(time(NULL)); 
    if (size>0) {
       array= new int [size];
       length = size; 
    } else {
        array= new int [default];//defaulting size of list to 1 if size is a bad input
        length=default;
    }
    setArray(0);// forcing arrays to initialize to all zeros
    sorted = true;
}

// destructor
MyList::~MyList() {
    delete array;
}

void MyList::printArray() {
    std::cout << "[";
    for (int i = 0; i < length; i++) {
        std::cout << array[i];
        if (i < length - 1) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

void MyList::setRandom(int x, int y){
    sorted=false;
    if(x!=y && x>=0 && y>=0){// these are good values
        int Max;
        int Min;
        if(x>y){ //checking mins and max
            Max=x;
            Min=y;
         } else {
            Max=y;
            Min=x;
         }
         for (int i=0; i<length; i++){
            // rand() % numebr will return numbers from 0 to number - 1
            array[i]= (rand() % (Max - Min + 1)) + Min;
         }
    } else {// these are bad values
        for (int i=0; i<length; i++){
        array[i]= (rand() % RMAX) + RMIN;
        }
    }
}
void MyList::setArray(int u){
    sorted=true;
    for(int i=0; i<length; i++){
        array[i]=u;
    }
}

bool MyList::setElement(int a, int b){
    sorted=false;
    bool response;
    if (b>=0 && b<length) {
        array[b] = a;
        response=true;
    } else {
      response=false;     
    }
    return response;
}
int MyList::getLength(){
    return length;
}
void MyList::swap(int *xp,int *yp){
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void MyList::sort(){
    if (sorted == false){
        bool swapped=true;
        int i, j;  

        for (i = 0; i < length-1 && swapped; i++){
      
    // Last i elements are already in place  
        for (j = 0; j < length-i-1; j++){  
            if (array[j] > array[j+1]){  
                swap(&array[j], &array[j+1]);
                swapped=true;
                }
            }    
        }
        sorted=true;
    } else {
    }
}
bool MyList::getSorted(){
    return sorted;
}
int MyList::getElement(int e){
      if (e>=0 && e<length) { 
         return array[e]; 
      } else {
          throw e;
      }
}
bool MyList::getElement(int e, int *ret){
    bool response= false;
    if(e>=0 && e<length){
        *ret=array[e];
        response=true;
    } else {
        *ret=0;
    }
    return response;
}
bool MyList::resizeArray(int newSize){
    bool valid = true;
    
    if (newSize<1){
        valid=false;
    } else if (newSize==length){
        valid=false;
    } else if (newSize>length){//resizing array into bigger array
        int *temparray= new int [newSize];
        for(int i=0; i<length; i++){
            temparray[i]=array[i];
        }
        delete [] array;
        array = temparray;

        for(int i=length; i<newSize; i++){
            array[i]=init;
        }
        length=newSize;
        valid=true;
        sorted= false;
    } else if (newSize<length){//resizing array into smaller array
        int *temparray= new int [newSize];
        for(int i=0; i<length-newSize; i++){
            temparray[i]=array[i];
        }
        delete [] array;
        array = temparray;
        valid=true;
        length=newSize;
    }
    return valid;
}
int MyList::linsearch(int key){
    int i; 
    int locatedkey= -1;
    for (i = 0; i < length; i++){
        if (array[i] == key){
            locatedkey=i; 
        }
    }
    return locatedkey; 
} 
int MyList::findElement(int element){
    int search;
    if (sorted==true){
        search=binsearch(element);
    } else {
        search=linsearch(element);
    }
    return search;
}
int MyList::binsearch(int key){
    int low= 0;
    int high = length-1;
    int foundkey=-1;
    if (high >= low) { 
        int mid = low + (high - low) / 2; 
        if (array[mid] == key){
            foundkey = mid;
        } else if (array[mid] > key){ 
            high=mid-1;
            foundkey= binsearch(key); 
        } else {
            low=mid+1;
            foundkey = binsearch(key); 
        }
    } 
    return foundkey;
}


