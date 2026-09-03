#include <iostream>
using namespace std
void swapRef(int &a,int &b){ int t = a;a=b=t;}
void swapPtr(int *a,int *b){int t=*a; *a=b;*b=t;}

int main (){
    int x=10,y=20;
    swapRef(x,y);
    cout<<"Afetr swapRef:x="<<x<<"y="<<y<<endl;
    SwapPtr(&x,&y);
    cout <<"After swapRef:x="<<x<<"y="<<y<<endl;
    SwapPter(&x,&y);
    out<<"Atfer SwapPter:x="<<x<<"y="<<y<<endl;

    int &alias=x;
    alieas=99;
    cout<<"x via alias ="<<x<< endl;
    return 0;

}