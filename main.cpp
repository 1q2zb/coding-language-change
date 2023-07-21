#include <bits/stdc++.h>

using namespace std;

string pass,language,cinrule;
int f1,f2;
string lang[2];
string res;

void str_find(string a){
    a.insert(0," ");
    int x1=-1,x2=-1;int t=0;int i=0;//x1x2标记位置
    lang[0]=lang[1]="";//定义输出
    for(;i<a.length();i++){
        if(a[i]==' ')t++;//换语言
        if(t==f1&&x1==-1){x1=i+1;}//标记语言1位置
        if(t==f1+1&&lang[0]==""){lang[0]=a.substr(x1,i-x1);}//语言1结束
        if(t==f2&&x2==-1){x2=i+1;}//标记语言2位置
        if(t==f2+1&&lang[1]==""){lang[1]=a.substr(x2,i-x2);}//语言2结束
    }
    if(lang[0]=="")lang[0]=a.substr(x1,i);//防止结束没有存入
    if(lang[1]=="")lang[1]=a.substr(x2,i-x2);
    return;
}

int main()
{
    fstream cin1,cin2,cout1;//打开文件
    cin1.open("language.txt",fstream::in);//打开设定文件
    cout1.open("result",fstream::out);//输出文件
    getline(cin1,language);//获取输出规则
    getline(cin1,cinrule);//获取输出规则
    cout<<cinrule;
    cin>>pass;//填写文件路径
    cin2.open("then.txt",fstream::in);//bzd怎么写
    getline(cin1,cinrule);//获取输出规则
    cout<<language<<endl<<cinrule;
    cin>>f1;//输入语言
    getline(cin1,cinrule);//获取输出规则
    cout<<cinrule;
    cin>>f2;//输出语言
    while(getline(cin1,language)){//每一条程序
        str_find(language);//找到输入和输出语言所在位置并存储
//        cout<<lang[0]<<" "<<lang[1]<<endl;
        while(getline(cin2,res)){

        }
    }
    return 0;
}
