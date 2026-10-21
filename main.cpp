#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;
map<string,string>mpp;

void storage(string &head,string &key,string &value){
    int a=0;
    if(head=="set"){
        mpp[key]=value;
    }
    else if(head=="get"){
        auto it=mpp.find(key);
        if (it != mpp.end()) {
            cout << it->second << "\n";
        } else {
            cout << "(nil)\n";
        }
    }
    else if(head=="del"){
        auto it=mpp.find(key);
        if(it!=mpp.end()){
            mpp.erase(it);
        }
    }
}

void loadData(){
    //Loading data from file and seperating set, get, del, exit
    ifstream file("data.txt");
    string line; int count=0;
    string key="",value="",head="";
    while(getline(file,line)){
        for(char ch:line){
            if(ch!=' ' && count==0){
                head+=ch;
            }
            else if(ch==' ' && count==0){
                count++;
            }
            else if(ch!=' ' && count==1){
                key+=ch;
            } //count==1
            else if(ch==' ' && count==1){
                count++;
            } //count==2
            else if(count==2){
                value+=ch;
            }
        }
        if(head=="set"){
            storage(head,key,value);
        }
        else if(head=="get"){
            storage(head,key,value);
        }
        else if(head=="del"){
            storage(head,key,value);
        }
        key="",value="",head="";
        count=0;
    }
    file.close();
}

int main(){
    loadData();
    cout<<"==== Redis-Lite CLI Engine ====\n";
    while(true){
        string input;
        string key="",value="",head="";
        int count=0,i;
        //Taking input as getline to read whole
        cout<<"db> ";
        getline(cin,input);

        //Seprating set, get, del, exit from getline
        for(i=0;i<input.length();i++){
            if(input[i]!=' ' && count==0){
                head+=input[i];
            }
            else if(input[i]==' ' && count==0){
                count++;
            }
            else if(input[i]!=' ' && count==1){
                key+=input[i];
            } //count==1
            else if(input[i]==' ' && count==1){
                count++;
            } //count==2
            else if(count==2){
                value+=input[i];
            }
        }

        //Opening and appending the file
        fstream file("data.txt",ios::app);
        if(head!="get"){
            file<<input<<endl;
        }
        file.close();

        //Putting head,key and value in function
        if(head=="set"){
            storage(head,key,value);
            cout<<"OK"<<endl;
        }
        else if(head=="get"){
            storage(head,key,value);
        }
        else if(head=="del"){
            storage(head,key,value);
            cout<<"OK"<<endl;
        }
        else if(input=="exit"){
            return 0;
        }
        else{
            cout<<"error...\n";
        }
    }
    return 0;
}