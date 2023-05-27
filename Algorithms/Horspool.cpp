#include<iostream>
#include<string>
#include<vector>
using namespace std;


void createShiftTable(vector<int>& shiftTable,string pattern,int patternLen){
    for(int i = 0;i<patternLen-1;i++){
        shiftTable[pattern[i]] = patternLen - 1 - i;
    }
}

int horspool(vector<int>& shiftTable,string text,string pattern,int textLen,int patternLen){
    int i = patternLen - 1;

    while(i <= textLen - 1){
        int k = patternLen - 1;
        int j = i;
        while(k >= 0 && (pattern[k] == text[j])){
            k = k - 1;
            j = j - 1;
        }
        k = k + 1;
        if(k == 0){
            return j+1;
        }
        else{
            i += shiftTable[text[i]];
        }
    }
    return -1;
}

int main(){
    string text;
    string pattern;
    cout<<"Enter the text :";
    getline(cin,text);
    cout<<"Enter the pattern to be searched:";
    getline(cin,pattern);
    int patternLen = pattern.length();
    int textLen = text.length();

    vector<int> shiftTable(256,patternLen);
    createShiftTable(shiftTable,pattern,patternLen);

    int position = horspool(shiftTable,text,pattern,textLen,patternLen);
    if(position >= 0){
        cout<<"The pattern - "<<pattern<<" is present at starting index - "<<position<<endl;
    }
    else{
        cout<<"The pattern is not present in the text";
    }


    return 0;


}


    
