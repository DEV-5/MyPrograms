//#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string valid_id =" is a VALID ip address";
    string invalid_id =" is an INVALID ip address";
public:
    string validIPAddress(string IP) {
        cout<<"The IP address to be verified is :"<<IP<<endl;
        return this->valid_id;
    }
};

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        cout<<"Invalid input, correct usage: verfy_ip <ip_to_be_verified>"<<endl;
        exit(1);
    }
    Solution s1;
    string result_str = s1.validIPAddress(argv[1]);
    cout<<"The Ip address "<<argv[1]<<result_str<<endl;
}
