//example for file io operations in c++
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    string str1;
    ofstream fo1("anewfile.txt",ios::app);
    if(!fo1.is_open())
    {
        cout<<"Failed to open anewfile.txt"<<endl;
        return 0;
    }
    fo1<<"This is the first sentence of the file.";
    fo1.close();
    ifstream fo2("anewfile,txt",ios::ate);
    
    fo2>>str1;
    cout<<str1<<endl;
    //fp1.open("anew_file.txt",fp1.in);    
}
