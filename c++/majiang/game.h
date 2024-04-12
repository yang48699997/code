#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <random>
#include "player.h"
using namespace std;

class Game{
    private:
        Card card;//牌堆（玩家共享
        vector<Player> player; //玩家
        int round;//回合数
        string winner;//胜者
        int cur;//当前出牌的玩家序号（0-3，0为自己
    public:
        Game(string name):card(){
            player.resize(4);//初始化玩家和牌堆
            for(int i=1;i<=3;i++){
                string ss="robot";
                ss+=to_string(i);
                player[i]=Player{ss,&card};
            }
            player[0]=Player{name,&card};
            cur=rand()%4;//随机从一名玩家开始
        }
        void start(){
            bool is_finish=false;//记录是否游戏是否结束
            cout<<"游戏开始,先手为"<<player[cur].get_name();
            card.start();//打乱牌堆
            for(int i=0;i<4;i++){//每个玩家摸13张牌
                for(int j=0;j<13;j++)player[i].get_card();
            }
            while(!card.is_empty()){//循环直到牌被摸完
                if(card.is_empty())break;//判断是否还有牌，没牌则退出
                int ans=player[cur].round();//当前玩家出牌，ans为打出的牌
                if(ans==666){//666表示胡牌了
                    cout<<player[cur].get_name()+"赢得了胜利"<<endl;
                    is_finish=true;//游戏结束
                    break;
                }
                cout<<player[cur].get_name()+"打出了"<<card.get_name(ans)<<endl;
                cur=(cur+1)%4;//换到下一位玩家
                if(cur==0&&player[cur].check_chi(ans).size()!=0){//如果上一位玩家的下位是我，且我可以吃牌
                    auto res=player[cur].check_chi(ans);//获得数组，表示可选则的方法
                    cout<<"你是选择吃?"<<endl;
                    int cnt=res.size();
                    cout<<"可选择的方法有"+cnt<<"种"<<endl;
                    for(int i=0;i<res.size();i++){//展示（可以用qt来
                        string s1=card.get_name(res[i].first);
                        string s2=card.get_name(res[i].second);
                        cout<<s1<<' '<<s2<<endl;
                    }
                    string choice;//输入选择，（qt来选
                    cin>>choice;
                    if(choice.length()==3){//也可用qt传的参数来判断
                        string yes="yes";
                        bool ok=true;
                        for(int i=0;i<3;i++){
                            int cur=choice[i]^yes[i];
                            if(cur!=0&&cur!=32){
                                ok=false;
                                break;
                            }
                        }
                        while(ok){//当你选择出牌时
                            cout<<"请选择要打出的牌(0放弃)"<<endl;
                            string choice;//输入选择的方案（前面已经列出
                            cin>>choice;
                            if(choice=="0")break;
                            for(int i=1;i<=res.size();i++){
                                if(choice==to_string(i)){
                                    player[0].discard(res[i-1].first);
                                    player[0].discard(res[i-1].second);
                                    ok=false;
                                }
                            }
                        }
                    }
                }
                if(cur!=1&&player[0].check_gang(ans)){//当别的玩家出牌，且你可以杠时
                    cout<<"是否要杠？"<<endl;//逻辑大致同上，也是输入选择
                    string choice;
                    cin>>choice;
                    if(choice.length()==3){
                        string yes="yes";
                        bool ok=true;
                        for(int i=0;i<3;i++){
                            int cur=choice[i]^yes[i];
                            if(cur!=0&&cur!=32){
                                ok=false;
                                break;
                            }
                        }
                        if(ok){
                            int gg=player[0].gang(ans);
                            if(gg=666){
                                cout<<player[0].get_name()+"赢得了胜利"<<endl;
                                is_finish=true;
                            }
                        }
                    }
                }
                if(cur!=1&&player[0].check_peng(ans)){//当别的玩家出牌，且你可以杠时
                    cout<<"是否要碰？"<<endl;
                    string choice;
                    cin>>choice;
                    if(choice.length()==3){
                        string yes="yes";
                        bool ok=true;
                        for(int i=0;i<3;i++){
                            int cur=choice[i]^yes[i];
                            if(cur!=0&&cur!=32){
                                ok=false;
                                break;
                            }
                        }
                        if(ok)player[0].peng(ans);
                    }
                }
            }
            if(!is_finish)cout<<"游戏结束，和牌了！！！"<<endl;
        }

};