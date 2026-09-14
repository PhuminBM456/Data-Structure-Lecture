#include<bits/stdc++.h>
using namespace std;

bool isOpen(string tag){
    for(int i=0;i<tag.length();i++){
        if(tag[i] == '/'){
            return false;
        }
    }

    return true;
}

string delSlash(string tag){
    string format = "";

    for(int i=0;i<tag.length();i++){
        if(tag[i] != '/')
            format += tag[i];
    }

    return format;
}

string format(string tag){ // format string to tag only.
    bool check = false;
    string dummy = "";

    for(int i=0;i<tag.length();i++){
        if(tag[i] == '<'){
            check = true;
        }

        if(check){
            dummy += tag[i];

            if(tag[i] == '>'){
                check = false;
            }
        }
    }

    return dummy;
}

int main(){
    vector<string> stack;
    string tag,dummy;
    bool isValid;

    getline(cin,tag);

    tag = format(tag);

    //cout << tag;

    dummy = "";
    isValid = true;

    for(int i=0;i<tag.length();i++){
        dummy += tag[i];

        if(tag[i] == '>'){
            if(isOpen(dummy)){
                stack.push_back(dummy);
                dummy = "";
            }else{
                if(stack.empty()){
                    isValid = false;
                    break;
                }

                string top = stack.back();
                dummy = delSlash(dummy);

                if(top == dummy){
                    dummy = "";
                    stack.pop_back();
                }else{
                    isValid = false;
                    break;
                }
            }
        }
    }

    if(isValid && stack.empty()){
        cout << "Valid" << endl;
    }else{
        cout << "Not Valid" << endl;
    }

    return 0;
}