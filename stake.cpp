#include <iostream>
using namespace std;
#include <stack>


int main(){
    stack <int> a;
    
    int size,i,choice,v;
    do{
    cout<<"press 1 for push \npress 2 for pop\npress 3 for Display top the Element\npress 4 for empty\npress 5 for fullstack\npress 0 for exit";
    cin>>choice;
    switch(choice){
        case 1:
           cout<<"How many enter value for stack";
           cin>>size;
           for(i = 0; i < size; i++){
               cout<<"Enter "<<i+1<<" value";
               cin>>v;
               
               a.push(v);
           }
           cout<<endl;
           
           break;
        case 2:
        if(!a.empty()){
            cout<<"Popped value form stack"<<a.top();
            a.pop();
        }
        else{
            cout<<"Stack is empty";
            cout<<endl;
        }
        break;
        cout<<endl;
        
        case 3:
        if(!a.empty()){
            cout<<"top value from stack"<<a.top();
        }
        else{
            cout<<"Stack is empty";
        }
        cout<<endl;
        break;
        cout<<endl;
        
        case 4:
          if(a.empty()){
              cout<<"Stack is empty";
          }
          else{
              cout<<"Stack is not empty";
          }
          cout<<endl;
          break;
          cout<<endl;
          
         case 5:
         if(!a.empty()){
             cout<<"Stack is Almost Full";
         }
         else{
             cout<<"Stack is not full";
         }
         cout<<endl;
         case 0:
         cout<<"exit";
         break;
         default:
         cout<<"invalid choice";
         
    }
    }while(choice != 0);
    
    while(!a.empty()){
        cout<<"Value of Stack "<<a.top()<<" ";
        a.pop();
    }
    
    
    return 0;
}
