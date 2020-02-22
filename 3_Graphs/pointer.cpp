#include<iostream>
using namespace std;

void test1(){
    int a = 10;
    int* b= &a;
    int **c = &b;
    cout<<a<<" "<<&a<<endl;
    cout<<b<<" "<<&b<<endl;
    cout<<c<<" "<<&c<<endl;
    cout<<*c<<" "<<*b<<" "<<**c<<endl;
} 

void stackgrowth(int *a){
    int b;
    if(a>&b)
        cout<<"Top down";
    else
    {
        cout<<"Bottom";
    }
    

}
int main(){
    //test1();
    // int*a;
    // cout<<&a<<endl;
    // int*b;
    // cout<<&b;
    int a;
    stackgrowth(&a);
    return 0;
}