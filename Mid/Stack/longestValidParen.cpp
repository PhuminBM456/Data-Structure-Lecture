#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> stack;
    string paren,format;
    int len,Max;

    getline(cin,paren);

    len = paren.length();
    format = "";

    for(int i=0;i<len;i++){
        if(paren[i] != ' ')
            format += paren[i];
    }

    len = format.length();

    stack.push_back(-1);
    Max = 0;

    for(int i=0;i<len;i++){
        if(format[i] == ')' || format[i] == ']' || format[i] == '}' || format[i] == '>'){
            stack.pop_back();

            if(stack.empty()){
                stack.push_back(i);
            }else{
                int top = stack.back();
                Max = max(Max,i-top);
            }
        }else{
            stack.push_back(i);
        }
    }

    cout << Max;

    return 0;
}