#include<iostream>
#include<vector>

using namespace std;

vector<vector<string>> hashmap(60);

int myHash(string &name){
    int len=name.length();
    int res=0;
    for(int i=0;i<len;i++){
        res+=(name[i]-'A')*(i+1);
    }
    return res;
}

void insert(string &name){
    int tar=myHash(name)%60;
    hashmap[tar].push_back(name);
    return ;
}

bool find(string &name){
    int tar=myHash(name)%60;
    for(auto f:hashmap[tar]){
        if(f==name) return true;
    }
    return false;
}

int main(){
    string name[30]={"MaYun","MaHuateng","WangWenbin","HuaChunying","YuYang",
                            "RenZhengfei","XiaoMing","XiaoHong","XiaoGang","DaLang",
                            "LiuBei","GuanYu","ZhangFei","CaoCao","SunQuan",
                            "ZhuGeliang","ZhaoYun","HuangZhuong","MaChao","LiuChe",
                            "LiuBang","LiKui","YongChu","TaFei","YuanShen",
                            "QiDong","JieGe","BuYao","YunTa","ChiFan"};
    for(int i=0;i<30;i++){
        insert(name[i]);
    }
    cout<<"请输入要查找的名字"<<"\n";
    string n;
    cin>>n;
    if(find(n)){
        cout<<"找到了"<<n<<endl;
    }else{
        cout<<"未找到"<<n<<endl;
    }
    return 0;
}