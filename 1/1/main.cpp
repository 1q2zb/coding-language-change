#include <bits/stdc++.h>

using namespace std;

string pass,language,cinrule,temp;
int f1,f2;
string lang[2];
string res;

void str_find(string a){
    a.insert(0," ");//����ո��Ա�֤f1��f2ȡֵͳһ
    int x1=-1,x2=-1;int t=0;int i=0;//x1x2���λ��
    lang[0]=lang[1]="";//�������
    for(;i<a.length();i++){
        if(a[i]==' ')t++;//������
        if(t==f1&&x1==-1){x1=i+1;}//�������1λ��
        if(t==f1+1&&lang[0]==""){lang[0]=a.substr(x1,i-x1);}//����1����
        if(t==f2&&x2==-1){x2=i+1;}//�������2λ��
        if(t==f2+1&&lang[1]==""){lang[1]=a.substr(x2,i-x2);}//����2����
    }
    if(lang[0]=="")lang[0]=a.substr(x1,i);//��ֹ����û�д���
    if(lang[1]=="")lang[1]=a.substr(x2,i-x2);
    return;
}

int main()
{
    fstream cin1,cin2,cout1;//���ļ�
    cin1.open("language.txt",fstream::in);//���趨�ļ�
    cout1.open("result",fstream::out);//����ļ�
    getline(cin1,language);//��ȡ�������
    getline(cin1,cinrule);//��ȡ�������
    cout<<cinrule;
    cin>>pass;//��д�ļ�·��
    cin2.open("then.txt",fstream::in);//bzd��ôд
    getline(cin1,cinrule);//��ȡ�������
    cout<<language<<endl<<cinrule;
    cin>>f1;//��������
    getline(cin1,cinrule);//��ȡ�������
    cout<<cinrule;
    cin>>f2;//�������
    while(getline(cin2,res)){//��ȡÿһ�г���
        cin1.clear();//��������ļ���ȡ����
        cin1.seekg(0,ios::beg);
        for(int i=0;i<4;i++)getline(cin1,temp);
        while(getline(cin1,language)){//ÿһ������
            str_find(language);//�ҵ�����������������λ�ò��洢
            int index;
            while(res.find(lang[0])>=0&&res.find(lang[0])<res.length()){//�ж��Ƿ����
                index=res.find(lang[0]);//��ȡԭ��������λ��
                res.erase(index,lang[0].length());//ɾ��ԭ����
                res.insert(index,lang[1]);//��Ϊ������
            }
        }
        cout1<<res<<endl;
    }
    return 0;
}
