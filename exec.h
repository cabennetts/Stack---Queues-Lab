/* -----------------------------------------------------------------------------
 *
 * File Name: exec.h
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: 
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #ifndef EXEC_H
 #define EXEC_H
 #include "Node.h"
 #include "Queue.h"
 #include "Stack.h"
 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;

template <typename T>
class exec{

     public:
        exec(string fileName);
        void start(string process, Queue<T>& myQueue);
        void call(string functCall, Stack<T>& myStack, Queue<T>& myQueue);

        void returnn(Stack<T>& myStack, Queue<T>& myQueue);
        void thrw(Stack<T>& myStack, Queue<T>& myQueue);
        void run(string fileName);

 };
 #endif
