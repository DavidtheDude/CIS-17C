/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on August 27, 2014, 8:05 PM
* Purpose: First Data Structure Triangular Array
* Modified on Sept 3rd, 2014
*/
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
//Template
template <class T>
T destroy(T array){
        delete []array;
}
template <class T>
T destroy(T **array, T rows){
    //Destroy cols
        for(int row=0;row<rows;row++){
                delete []array[row];
        }
        //Destroy row pointers
        delete []array;
}
template <class T>
T * fillArray(T cols){
        //Declare the 1-D Array
        int * array=new int[cols];
        //Fill the array with random 2 digit numbers
        for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
        }
        return array;
}
template <class T>
T** fillArray(T rows,T *colAry){
        //Declare the 2-D Array
        int ** array=new int*[rows];
        for(int row=0;row<rows;row++){
        //cout<<"Number of Cols = "<<colAry[row]<<endl;
        array[row]=new int[colAry[row]];
        }
        //Fill the array with random 2 digit numbers
        for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
        array[row][col]=rand()%90+10;
        //cout<<"Row Col"<<row<<" "<<col<<endl;
        }
        }
        return array;
}
template <class T>
T** fillArray(T rows,T cols){
        //Declare the 2-D Array
        int ** array=new int*[rows];
        for(int row=0;row<rows;row++){
        array[row]=new int[cols];
        }
        //Fill the array with random 2 digit numbers
        for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
        array[row][col]=rand()%90+10;
        }
        }
        return array;
}
template <class T>
T printArray(T*array,T cols,T perLine){
        //Print the Array
        cout<<endl;
        for(int col=0;col<cols;col++){
        cout<<array[col]<<" ";
        if(col%perLine==(perLine-1))cout<<endl;
        }
        cout<<endl;
}
template <class T>
T printArray(T**array,T rows,T *colAry){
        //Print the Array
        cout<<endl;
        for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
        cout<<array[row][col]<<" ";
        }
        cout<<endl;
        }
        cout<<endl;
}
template <class T>
void printArray(T**array,T rows,T cols){
        //Print the Array
        cout<<endl;
        for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
        cout<<array[row][col]<<" ";
        }       
        cout<<endl;
        }
        cout<<endl;
}

//Execution Begins Here
int main(int argc, char** argv) {
 //Initialize the random number generator
srand(static_cast<unsigned int>(time(0)));
//Declare the 2-D Array
int rows=5,cols=10;
int cls=rows,perLine=10;
int **array=fillArray(rows,cols);
int *colAry=fillArray(cls);
int **triAry=fillArray(rows,colAry);
//Print the array
printArray(array,rows,cols);
printArray(colAry,cls,perLine);
printArray(triAry,rows,colAry);
//Delete the array
destroy(array,rows);
destroy(triAry,rows);
destroy(colAry);
//Exit stage right
return 0;
}