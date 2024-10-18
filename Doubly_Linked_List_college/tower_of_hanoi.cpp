#include <iostream>
using namespace std;
int count=0;

void toh(int n, int s, int d) {
    if (n == 1) {
        cout << "Move disk from tower " << s << " to tower " << d << endl;
        count++;
    } else {
        int aux = 6 - (s + d);
        toh(n - 1, s, aux);
        cout << "Move disk from tower " << s << " to tower " << d << endl;
        count++;
        toh(n - 1, aux, d);
    }
}

int main() {
    toh(3, 1, 3);
    cout<<"\ntotal step is "<<count;
    return 0;
}
