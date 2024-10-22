#include<iostream>
using namespace std;
int count=0;
void toh(int no_of_disk,string source,string helper,string destination){ //A ->source, C->destination ,B-> helper
     if(no_of_disk==1){
        cout<<"Move disk 1 from rod "<<source<<" to rod "<<destination<<endl;
        count++;
        return; 
    }
    toh(no_of_disk-1,source,destination,helper);// this will transfer upper n-1 disks to helper
    cout<<"Move disk "<<no_of_disk<<" from rod "<<source<<" to rod "<<destination<<endl;// moving last disk from source to destination
    count++;
    toh(no_of_disk-1,helper,source,destination);

    

} 
int main(){ 

    toh(4,"A","B","C");
    cout<<"minimum no of step required "<<count;
    return 0;
}