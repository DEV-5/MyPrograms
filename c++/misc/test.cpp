//DATE:30-3-17
#include<iostream>
#include<string>
using namespace std;

 class newer
 {
  public:
   int a;
   template<typename any,int ind>
   void find_max(any(&arr)[ind])
   {
    int max = arr[0];
    for(int i=1;i<ind;i++)
      if(arr[i]>max)
	max=arr[i];

    cout<<"the highest value in the array is "<<max<<endl;
   }
   newer()
   {
    a=9;
   }
 };

 int main()
{
 int array[]={12,3,2,1,222,1,546,499,70};
 newer io;
 cout<<io.a<<endl; 
 io.find_max(array);
}
