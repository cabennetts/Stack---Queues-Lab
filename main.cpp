/* -----------------------------------------------------------------------------
 *
 * File Name: main.cpp
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: 
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #include "Stack.h"
 #include "Node.h"
 #include "Queue.h"
 #include "exec.h"
 #include "Stack.cpp"
 #include "Node.cpp"
 #include "Queue.cpp"
 #include "exec.cpp"
 #include <string>
 #include <iostream>
 using namespace std;

 int main(int argc, char* argv[]){
     try{
         exec<string> driver(argv[1]);
     }
     catch(char* error){
        cout << error << endl;
     }
     return(0);
 }