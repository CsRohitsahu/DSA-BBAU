#include<iostream>
#include<stack>
using namespace std;




stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while(not input.empty()){
        // do the process till the time input stack does not become empty
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(not temp.empty()){
        // do the process till the time temp stack does not become empty
        int curr=temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    stack<int> res=copyStack(st);
    while(not res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }





//     cout<<st.top()<<endl; // this returns top element of stack
//     st.pop();  // pop top element 
//     cout<<st.top()<<endl;
//    cout<< st.empty();  // return 0 if stack is empty
    return 0;
}