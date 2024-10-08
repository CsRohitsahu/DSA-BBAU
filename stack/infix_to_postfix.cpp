#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> st;   // defining stack

// function to check precedence of operator
int precedence(char c){
    if(c=='^'){
        return 3; // higer precedence
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else 
        return 0;
    

}

string infixToPostfix(string infix){  // this methods convert infix to postfix and return postfix expression
    string postfix="";
    for(int i=0;i<infix.length();i++){ // this loop scans all the character of infix
     char c=infix[i];
     if(c=='('){
         st.push(c);
     }
     else if(c==')'){
        while(st.top()!='('){ // popping and appending all elemnt until ( comes
          char top_element=st.top();
          postfix+=top_element;
          st.pop();
        }
        st.pop(); // popping ( from stack
     }

     else if((c<='Z'&&c>='A')||(c>='a'&&c<='z')){  // checking whether character is operand or operator if operator then append to postfix
        postfix+=c;
     }
     else if(c=='^')  {   // exponent have higer precedence than any other so push it into stack
        st.push(c);
     }
     else if(!st.empty()&&precedence(st.top())<precedence(c)){   
        st.push(c);
     }
     else {
        while(!st.empty()&&precedence(c)>precedence(st.top())){
            postfix+=st.top();
            st.pop();
        }
        st.push(c);
     }


    }
    // for loops ends here 

 // now when all infix operator is inserted into stack we will append them into postfix expression
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }



    return postfix;
}


int main(){

    string infix;
    cout<<"enter infix expression"<<endl;
    cin>>infix;
    cout<<"postfix expression is "<<endl;
    cout<<infixToPostfix(infix);


    return 0;
}