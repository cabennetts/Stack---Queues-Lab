/* -----------------------------------------------------------------------------
 *
 * File Name: exec.cpp
 * Author: Caleb Bennetts
 * Assignment:   EECS-268 Lab03
 * Description: 
 * Date: 03/06/2021
 *
 ---------------------------------------------------------------------------- */
 #include "exec.h"
 #include "Node.h"
 #include "Stack.h"
 #include "Queue.h"
 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;

/*
* start: new process is created & added to queue. 
* all processes start with a main as their function call
* print a message to screen: outputs name of process (ex, WINSCP)
* main cannot catch exception
*/
 template <typename T>
 void exec<T>::start(string process, Queue<T>& myQueue){
   myQueue.enqueue(process);                                // adds process to queue
   cout << process << " added to queue" << endl;            //outputs "process added to queue"
   
 }
/*
* process at front of queue gets CPU time: calls a function(which is put on call stack for its process)
* after function call made, process goes to back of queue with call still on top of call stack
* print message to screen : which process called func and name of function
*/
 template <typename T>
 void exec<T>::call(string functCall, Stack<T>& myStack, Queue<T>& myQueue){
   
   try{
       myStack.push(functCall);
       cout << myQueue.peekFront() << " calls " << myStack.peek() << endl;
       myQueue.enqueue(myQueue.peekFront());
       myQueue.dequeue();  
   }
   catch(runtime_error& rte){
       cout << "Error " << rte.what() << endl;
   }
 }
/*
* rocess at front of queue has function at top of its call stack return
*  if(process has and functions left on call-stack, put it at back of queue)
* else(if main returns, pop it from stack )
*/
 template <typename T>
 void exec<T>::returnn(Stack<T>& myStack, Queue<T>& myQueue){
     
     try{
            myStack.pop();
            cout << myQueue.peekFront() << " " << myStack.peek() << " function return" << endl;
           
     }
     catch(runtime_error& rte){
         cout << "Error " << rte.what() << endl;
     }
 }

 template <typename T>
 void exec<T>::thrw(Stack<T>& myStack, Queue<T>& myQueue){
        try{
            myStack.pop();
        }
        catch(runtime_error& rte){
            if(myStack.isEmpty()){
                cout << myQueue.peekFront() << " terminated due to unhandled exception" << endl;
            }
            if(myQueue.isEmpty()){
                cout << myQueue.peekFront() << " exception caught by " << myStack.peek() << " function" << endl;
                myQueue.enqueue(myQueue.peekFront());
                myQueue.dequeue(); 
            }
 }
 }

 template <typename T>
 void exec<T>::run(string fileName){

        Queue<string> procQue; //process queue
        Stack<string> callStck; //call-stack
        string command = " "; //START, CALL, RETURN, THROW
        string process = " "; //putty, winscp
        string functCall = " "; //connect, login, writefile

        ifstream inFile;
        inFile.open(fileName.c_str());
        if(inFile.is_open()){

            while(inFile >> command){
                if(command == "START"){
                    inFile >> process;
                    start(process, procQue);
                }
                else if(command == "CALL"){
                    inFile >> functCall;
                    call(functCall, callStck, procQue);
                }
                else if(command == "RETURN"){
                    returnn(callStck, procQue);
                }
                else if(command == "THROW"){
                    thrw(callStck, procQue);
                }
                
            }
            inFile.close();
        }
        else{
            throw "Invalid file name";
        }
 }

 template <typename T>
 exec<T>::exec(string fileName){
     run(fileName);
 }