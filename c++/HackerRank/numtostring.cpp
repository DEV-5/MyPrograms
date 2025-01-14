#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    // Write your code here
    string str;
    switch(n){
        case 1:
            str = "one";
            break;
        case 2:
            str = "two";
            break;
        case 3:
            str = "three";
            break;
        case 4:
            str = "four";
            break;
        case 5:
            str = "five";
            break;
        case 6:
            str = "six";
            break;
        case 7:
            str = "seven";
            break;
        case 8:
            str = "eight";
            break;
        case 9:
            str = "nine";
            break;
        default:
            str = "Greater than 9";
            break;        
    }
    cout<<str<<endl;
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

