#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cout << "enter a word:";
    cin >> s;

    cout << "length :"<< s.length ()<< endl;
    cout<<"upper:";
    for (char c:s) cout << (char) toupper(c);
    cout<< endl;
    bool pal=true;

    for(size_t i=0,j=s.length()-1; i<j; ++i,--j)

        if(s[i]!=s[j]){pal=false;break;}
cout << s<< (pal ?"IS" :"IS NOT") << " a palindrome \n";

size_t pos=s.find("an");
if ( pos!=string ::npos)
cout << " 'an'found at index"<< pos<< endl;
else cout<< "'an' not found \n";
return 0;
}