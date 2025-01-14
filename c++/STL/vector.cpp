//Basic program on vector container capabilities
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string strq;
    int arr[5] = {12,23,34,45,56};
    vector <int> vect(10);//creating a vector of int type with size as 10 
    for(int i=0; i<(int)vect.size();i++) 
        cout<<*(vect.data()+i);
    cout<<endl;
    //inserting first variables of array at the beginning of vector
    vect.insert(vect.begin(),arr,arr+3);
    for(int i=0; i<(int)vect.size();i++) 
        cout<<*(vect.data()+i);
    cout<<endl;
    //removing variable in 2nd indice in vector
    vect.erase(vect.begin()+2);
    for(int i=0; i<(int)vect.size();i++) 
        cout<<*(vect.data()+i);
    cout<<endl;
    //pop
    vect.pop_back();
    for(int i=0; i<(int)vect.size();i++) 
        cout<<*(vect.data()+i);
    cout<<endl;
    vect.push_back(77);
    for(int i=0; i<(int)vect.size();i++) 
        cout<<*(vect.data()+i);
    cout<<endl;
//    cout<<vect.crend()<<endl;
}
