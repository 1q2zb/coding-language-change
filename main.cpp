#include <bits/stdc++.h>

using namespace std;

string pass,language,cinrule,temp;
int f1,f2;
string lang[2];
string res;

int get(string a){//判断注释以保证注释后文字不会被翻译
    int t=0;
    for(int i=0;i<a.length();i++){
        if(t==1&&a[i]!='/')t=0;
        if(a[i]=='/')t++;
        if(t==2)return i-1;//返回注释前第一个'/'的位置
    }
    return a.length();
}

void str_find(string a){
    a.insert(0," ");//插入空格以保证f1和f2取值统一
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
    cin2.open(pass.c_str(),fstream::in);//bzd怎么写
    getline(cin1,cinrule);//获取输出规则
    cout<<language<<endl<<cinrule;
    cin>>f1;//输入语言
    getline(cin1,cinrule);//获取输出规则
    cout<<cinrule;
    cin>>f2;//输出语言
    while(getline(cin2,res)){//读取每一行程序
        cin1.clear();//清除语言文件读取进度
        cin1.seekg(0,ios::beg);
        for(int i=0;i<4;i++)getline(cin1,temp);
        while(getline(cin1,language)){//每一条语言
            str_find(language);//找到输入和输出语言所在位置并存储
            int index;
            while(res.find(lang[0])>=0&&res.find(lang[0])<get(res)){//判断是否存在
                index=res.find(lang[0]);//获取原语言所在位置
                res.erase(index,lang[0].length());//删除原语言
                res.insert(index,lang[1]);//改为新语言
            }
        }
        cout1<<res<<endl;
    }
    return 0;
}
