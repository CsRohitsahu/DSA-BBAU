#include<iostream> 
using namespace std;
class Recursion{
    public:
    int fib(int n){   // nth fibonacci number
        if(n==0||n==1) return n;
        return fib(n-1)+fib(n-2);
    }
};
int main(){
  Recursion r; 
  for(int i=0;i<=4;i++)
    cout<<r.fib(i)<<" ";
    return 0;
}