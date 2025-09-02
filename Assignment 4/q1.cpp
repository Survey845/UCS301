#include <iostream>
using namespace std;

int q[5];
int front = 0;
int rear = 0;

void enqueue(){
    if(rear<4){
        cout<<"Enter the number you want to queue: ";
        cin>>q[rear];
        rear++;
    } else{
        cout<<"Queue is full..."<<endl;
    }
    
}

void dequeue(){
    if(!(rear==front)){
    cout<<"Dequeueing from the front..."<<endl;
    cout<<q[front]<<endl;
    front++;
    } else{
        cout<<"The queue is empty..."<<endl;
    }
}

bool isEmpty(){
    if(front==rear){
        cout<<"The queue is empty..."<<endl;
        return true;
    } else{
        cout<<"The queue is not empty..."<<endl;
        return false;
    }
} 

bool isFull(){
    if(rear==4){
        cout<<"The queue is full..."<<endl;
        return true;
    } else{
        cout<<"The queue is not full..."<<endl;
        return false;
    }

}

void display(){
    for(int i=front;i<rear;i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
}

void peek(){
    if(!(rear==front)){
        cout<<q[front]<<endl;
    }
}

int main(){
    bool flag = true;
    while(flag==true){
    int command;
    cout<<"Simple Queue"<<endl;
    cout<<"1.Enqueue"<<endl;
    cout<<"2.Dequeue"<<endl;
    cout<<"3.isEmpty"<<endl;
    cout<<"4.isFull"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Peek"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<"Enter the number corresponding to the command: ";
    cin>>command;
    switch(command){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            isEmpty();
            break;
        case 4:
            isFull();
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            flag = false;
            cout<<"Logging off..."<<endl;
            break;
    }
    }
    return 0;
}