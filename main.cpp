/*
 * This is a program that will create a “list” like object that behaves similarly to the List object in Python.
 * Note the header structure and files.
 * The only thing included here is main.h
 * main.h contains all other directives 
 */
/* 
 * File:   main.cpp
 * Author: Ahmed Eid
 */

#include "main.h"

int main(int argc, char** argv) {

    /* This will create a "list" of size LISTSIZE
     * and initialize it to all zeros */
    cout << "create and initialize mylist" << endl;
    MyList mylist(LISTSIZE);
    mylist.printArray();
    cout << endl;

    /* This will set the list to all 50 */
    cout << "set mylist to all 50" << endl;
    mylist.setArray(50);
    mylist.printArray();
    cout << endl;

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers -2 to 4" << endl;
    mylist.setRandom(-2,4);
    mylist.printArray();
    cout << endl;

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers 4 to 4" << endl;
    mylist.setRandom(4,4);
    mylist.printArray();
    cout << endl;

    /* This will succeed and set the array to the
     * random 1-100 values */
    cout << "attempt to set to random numbers 1 to 100" << endl;
    mylist.setRandom(1,100);
    mylist.printArray();
    cout << endl;

    /* This will succeed and set the array to the
     * random 500-1000 values */
    cout << "attempt to set to random numbers 500 to 1000" << endl;
    mylist.setRandom(1000,500);
    mylist.printArray();
    cout << endl;

    /* These next two sets will succeed and set the 1st and last
     * elements to 1000 and 2000 respectively */
    if(mylist.setElement(1000, 0)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(2000, LISTSIZE-1)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    /* These next two sets will fail and leave the array unmodified */
    if(mylist.setElement(9999, -1)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(9999, LISTSIZE)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    /* print out the array using getElement(int) */
    cout << "Testing new and/or modified code...\n\nprinting the array element by element using: int getElement(int);\n(going one too far to test out of range)" << endl;
    for(int i=0; i<LISTSIZE+1; i++){
        try{
            cout << mylist.getElement(i) << endl;
        }
        catch (int e){
            cout << "error, out of range"<< endl;
        }
    }
    cout << endl;

    /* this will fail and return 0 */
    cout << "attempting to get element 4000 using: int getElement(int);" << endl;
    try{
        cout << mylist.getElement(4000) << endl;
    }
    catch (int e){
        cout << "error, out of range"<< endl;
    }
    cout << endl;

     /* print out the array using getElement(int,int*) */
    cout<<"printing the array element by element using: bool getElement(int,int*);\n(going one too far to test out of range)" << endl;
    for(int i=0; i<LISTSIZE+1; i++){
        int output;
        bool list_contains_element= mylist.getElement(i, &output);
        if (list_contains_element){
            cout << output << endl;
        } else {
            cout << "error, out of range"<< endl;
        }
    }
    cout << endl;
    /* this will fail and return 0 */
    cout << "attempting to get element 4000 using: bool getElement(int, int*);" << endl;
    int output;
    bool list_contains_element= mylist.getElement(4000, &output);
    if (list_contains_element){
        cout << output << endl;
    } else {
        cout << "error, out of range"<< endl;
    }
    cout << endl;
    // resizing array to listsize, should fail
    cout << "resizing array to LISTSIZE" << endl;
    //cout<<mylist.resizeArray(LISTSIZE)<<endl;
    if (mylist.resizeArray(LISTSIZE)==1){
        cout << "resized..." << endl;
        mylist.resizeArray(LISTSIZE);
        mylist.printArray();
    } else {
        cout << "failed to resize" << endl;
    }
    cout << endl;
    // resizing array to listsize+5, should pass
    cout << "resizing array to LISTSIZE+5" << endl;
    //cout<<mylist.resizeArray(LISTSIZE+5)<<endl;
    if (mylist.resizeArray(LISTSIZE+5)==1){
        cout << "resized..." << endl;
        mylist.resizeArray(LISTSIZE+5);
        mylist.sort();
        mylist.printArray();
    } else {
        cout << "failed to resize" << endl;
    }
    cout << endl; 
    // resizing array to listsize-5, should pass
    cout << "resizing array to LISTSIZE-5" << endl;
    //cout<<mylist.resizeArray(LISTSIZE-5)<<endl;
    if (mylist.resizeArray(LISTSIZE-5)==1){
        cout << "resized..." << endl;
        mylist.resizeArray(LISTSIZE-5);
        mylist.printArray();
    } else {
        cout << "failed to resize" << endl;
    }
    cout << endl; 
    // resizing array to 0,should fail
    cout << "resizing array to 0" << endl;
    //cout<<mylist.resizeArray(LISTSIZE-LISTSIZE)<<endl;
    //these lines are present throughout this block, was used for debugging
    if (mylist.resizeArray(LISTSIZE-LISTSIZE)==1){
        cout << "resized..." << endl;
        mylist.resizeArray(LISTSIZE-LISTSIZE);
        mylist.printArray();
    } else {
        cout << "failed to resize" << endl;
    }
    cout << endl;
    cout << "resizing array to LISTSIZE+10" << endl;
    if (mylist.resizeArray(LISTSIZE+10)==1){
        cout << "resized..." << endl;
        mylist.resizeArray(LISTSIZE+10);
        cout<<"Setting new array to random numbers ranging from 20-1, and printing the array before and after the sort function is called;"<<endl;
        mylist.setRandom(21,0);
        cout<<"Before Sorting function is called:"<<endl;
        mylist.printArray();
        mylist.sort();
        cout<<"After Sorting function is called:"<<endl;
        mylist.printArray();
        cout<<"Checking the length and sorted state of this array"<<endl;
        cout<<"The length of this array is "<<mylist.getLength()<<endl;
        if (mylist.getSorted()==1){
            cout<< "This Array is Sorted"<<endl;
        } else {
            cout<<"This Array is not Sorted"<<endl;
        }
    } else {
        cout << "failed to resize" << endl;
    }
    cout << endl;
    cout << "resizing array to LISTSIZE-2" << endl;
    if (mylist.resizeArray(LISTSIZE-2)==1){
        cout << "resized..." << endl;
        mylist.resizeArray(LISTSIZE-2);
        cout<<"Setting new array to random numbers ranging from 9-1, and printing the array before and after the sort function is called;"<<endl;
        mylist.setRandom(10,0);
        cout<<"Before Sorting function is called:"<<endl;
        mylist.printArray();
        mylist.sort();
        cout<<"After Sorting function is called:"<<endl;
        mylist.printArray();
        cout<<"Checking the length and sorted state of this array:"<<endl;
        cout<<"The length of this array is "<<mylist.getLength()<<endl;
        if (mylist.getSorted()==1){
            cout<< "This Array is Sorted"<<endl;
        } else {
            cout<<"This Array is not Sorted"<<endl;
        }
    } else {
        cout << "failed to resize" << endl;
    }
    cout << endl;
    cout<<"Testing setArray by printing the Array before and after setArray(50) is sorted with the sort funtion;"<<endl;
    mylist.setArray(50);
    cout<<"Before Sorting function is called:"<<endl;
    mylist.printArray();
    mylist.sort();
    cout<<"After Sorting function is called:"<<endl;
    mylist.printArray();
    cout << endl;
    cout<<"Testing setElement by printing the Array before and after setElement(45,5) is sorted with the sort funtion;"<<endl;
    mylist.setElement(45,5);
    cout<<"Before Sorting function is called:"<<endl;
    mylist.printArray();
    mylist.sort();
    cout<<"After Sorting function is called:"<<endl;
    mylist.printArray();
    cout << endl;
    // testing linsearch, binsearch, and findElement
    cout<< "Testing linsearch and findElement by searching for the integer 5 in an unsorted array set at random values from 10-1;"<<endl;
    mylist.setRandom(10,0);
    mylist.printArray();
    if (mylist.findElement(5)==-1){
        cout<<"This element was not found in this array"<<endl;
    } else {
        cout<< "This element is present at index "<<mylist.findElement(5)<<endl;
    }
    cout << endl;
    cout<< "Testing binsearch and findElement by searching for the integer 5 with a sorted array set at random values from 10-1;"<<endl;
    mylist.sort();
    mylist.printArray();
    if (mylist.findElement(5)==-1){
        cout<<"This element was not found in this array"<<endl;
    } else {
        cout<< "This element is present at index "<<mylist.findElement(5)<<endl;
    }
    
    return 0;
}
