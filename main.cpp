#include <bits/stdc++.h>

using namespace std;

string passin,passout,language,cinrule,temp;
long long f1,f2,num;
string lang[2];
string res;
string tempstring;

void strnum(){//字符串转换为数字
    num=0;
    for(long long i=0;i<tempstring.length();i++){
        num=num*10+tempstring[i]-'0';
    }
    return;
}

long long get(string a){//判断注释以保证注释后文字不会被翻译
    long long t=0;
    for(long long i=0;i<a.length();i++){
        if(t==1&&a[i]!='/')t=0;
        if(a[i]=='/')t++;
        if(t==2)return i-1;//返回注释前第一个'/'的位置
    }
    return a.length();//返回行长度+1
}

void str_find(string a){//找到输入和输出语言所在位置并存储
    a.insert(0," ");//插入空格以保证f1和f2取值统一
    long long x1=-1,x2=-1;long long t=0;long long i=0;//x1x2标记位置
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
    getline(cin1,tempstring);//获取语言数量以便集中操作
    strnum();
    getline(cin1,language);//获取输出规则
    for(long long i=0;i<num;i++){//引导填写原始文件路径
        getline(cin1,cinrule);
        cout<<cinrule<<endl;
    }
    cin>>passin;//填写原始文件路径
    cin2.open(passin.c_str(),fstream::in);//打开原始文件
    for(long long i=0;i<num;i++){//引导填写更改后文件路径
        getline(cin1,cinrule);
        cout<<cinrule<<endl;
    }
    cin>>passout;//填写更改后文件路径
    cout1.open(passout.c_str(),fstream::out);//打开输出文件
    cout<<language<<endl;//引导输入语言
    for(long long i=0;i<num;i++){//引导输入原始语言
        getline(cin1,cinrule);
        cout<<cinrule<<endl;
    }
    cin>>f1;//输入原始语言
    for(long long i=0;i<num;i++){//引导输入更改后语言
        getline(cin1,cinrule);
        cout<<cinrule<<endl;
    }
    cin>>f2;//输入更改后语言
    while(getline(cin2,res)){//读取每一行程序
        cin1.clear();//清除语言文件读取进度
        cin1.seekg(0,ios::beg);
        for(long long i=0;i<4*num+2;i++)getline(cin1,temp);//读取进度快进到主体
        while(getline(cin1,language)){//每一条语言
            str_find(language);//找到原始和更改后语言位置
//            cout<<lang[0]<<" "<<lang[1]<<endl;
            long long index;//标记位置
            while(res.find(lang[0])>=0&&res.find(lang[0])<get(res)){//判断注释前是否存在关键词
                index=res.find(lang[0]);//获取原语言所在位置
                res.erase(index,lang[0].length());//删除原语言
                res.insert(index,lang[1]);//改为新语言
            }
        }
        cout1<<res<<endl;//输出到更改后文件
    }
    return 0;
}
//这就是完整的翻译程序了。
//
//              ——by 1q2zb
