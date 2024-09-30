#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st,int x){
    stack<int> temp;
    while(not st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(not temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtBottom(st,200);
    while(not st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}