#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <random>
#include "board.h"
using namespace std;

class Player{
    /* 
        初始化玩家
     */
    private:
        set<int> own_card;//当前玩家所拥有的牌
        string name;//玩家名称
        int cur_num;//当前玩家所拥有的牌的数量
        Card* card;//牌堆，所有玩家共享
    public:
        Player(){
            
        }
        Player(string name,Card* card):own_card(){//初始化玩家名称和牌堆，牌的数量
            this->name=name;
            cur_num=0;
            this->card=card;
        }
        void get_card(){//玩家摸牌
            cur_num++;//拥有牌的数量增加
            int p=card->get_card();//调用牌堆函数获取牌
            own_card.insert(p);//把获取到的牌的序号插入拥有的牌中
        }
        void get_back_card(){//逻辑同上，从后面摸牌
            cur_num++;
            int p=card->get_back_card();
            own_card.insert(p);
        }
        int round(){//玩家回合函数
            get_card();//摸牌
            if(check_win())return 666;//检查是否胡牌，是则返回666
            int choice=*own_card.begin();//这里是默认出第一张牌，但可以通过qt传参来控制出牌
            // choice= 
            // discard(choice)=  QT;
            /* 
                qt调用 选择弃牌
             */
            discard(choice);//打出一张牌
            return choice;//返回打出的牌的序号
        }
        int discard(int n){//打出牌
            cur_num--;//牌的数量减一
            own_card.erase(own_card.find(n));//从拥有的牌中删除打出的牌
            return n;//返回打出的牌
        }
        bool check_win(){//检查是否胡牌
            vector<int> cur_card(cur_num);
            int i=0;
            for(auto it=own_card.begin();it!=own_card.end();it++)cur_card[i++]=*it;
            vector<int> dp(1<<cur_num,-1);
            return check((1<<cur_num)-1,cur_card,dp);//返回是否胡牌，是则为true
        }
        bool check(int n,vector<int>& cur_card,vector<int> &dp){//dp+状压 计算是否胡牌
            if(dp[n]!=-1)return dp[n];
            int l=__builtin_popcount(n);
            if(l==2){
                int c1=0;
                for(int i=0;i<31;i++){
                    if(n&(1<<i)){
                        n^=1<<i;
                        break;
                    }else c1++;
                }
                int c2=0;
                for(int i=0;i<31;i++){
                    if(n&(1<<i)){
                        n^=1<<i;
                        break;
                    }else c2++;
                }
                return card->get_name(cur_card[c1])==card->get_name(cur_card[c2]);
            }
            for(int j=n;j;j=(j-1)&n){
                if(__builtin_popcount(j)!=3)continue;
                int c1=0;
                int jj=j;
                for(int i=0;i<31;i++){
                    if(jj&(1<<i)){
                        jj^=1<<i;
                        break;
                    }else c1++;
                }
                int c2=0;
                for(int i=0;i<31;i++){
                    if(jj&(1<<i)){
                        jj^=1<<i;
                        break;
                    }else c2++;
                }
                int c3=0;
                for(int i=0;i<31;i++){
                    if(jj&(1<<i)){
                        jj^=1<<i;
                        break;
                    }else c3++;
                }
                bool key=false;
                string s1,s2,s3;
                s1=card->get_name(cur_card[c1]);
                s2=card->get_name(cur_card[c2]);
                s3=card->get_name(cur_card[c3]);
                if(s1==s2&&s2==s3){
                    key=check(n^j,cur_card,dp);
                    if(key){
                        dp[j]=1;
                        return true;
                    }
                    continue;
                }
                int n1=cur_card[c1],n2=cur_card[c2],n3=cur_card[c3];
                int p1=(n1-1)/36,p2=(n2-1)/36,p3=(n3-1)/36;
                if(p1!=p2||p1!=p3)continue;
                int num1=(n1-p1*36-1)/4,num2=(n2-p2*36-1)/4,num3=(n3-p3*36-1)/4;
                if(num1>num2)swap(num1,num2);
                if(num2>num3)swap(num2,num3);
                if(num1>num2)swap(num1,num2);
                if(num1+1!=num2||num2+1!=num3)continue;
                key=check(n^j,cur_card,dp);
                if(key){
                    dp[j]=1;
                    return true;
                }
            }
            dp[n]=0;
            return false;
        }
        vector<pair<int,int>> check_chi(int n){//检查是否可以吃，并返回一个数组，表示选择的方案（数组为空表示不能吃）
            vector<int> cur_card(cur_num);
            int i=0;
            for(auto it=own_card.begin();it!=own_card.end();it++)cur_card[i++]=*it;
            vector<pair<int,int>> ans;
            for(int j=cur_num;j;j=(j-1)&cur_num){
                int cnt=__builtin_popcount(j);
                if(j!=2)continue;
                int jj=j;
                int c1=0;
                for(int i=0;i<31;i++){
                    if(jj&(1<<i)){
                        jj^=1<<i;
                        break;
                    }else c1++;
                }
                int c2=0;
                for(int i=0;i<31;i++){
                    if(jj&(1<<i)){
                        jj^=1<<i;
                        break;
                    }else c2++;
                }
                int n1=cur_card[c1],n2=cur_card[c2],n3=n;
                int p1=(n1-1)/36,p2=(n2-1)/36,p3=(n3-1)/36;
                if(p1!=p2||p1!=p3)continue;
                int num1=(n1-p1*36-1)/4,num2=(n2-p2*36-1)/4,num3=(n3-p3*36-1)/4;
                if(num1>num2)swap(num1,num2);
                if(num2>num3)swap(num2,num3);
                if(num1>num2)swap(num1,num2);
                if(num1+1!=num2||num2+1!=num3)continue;
                ans.emplace_back(n1,n2);
            }
            return ans;
        }
        
        bool check_peng(int n){//检查是否可以碰
            map<string,int> cnt;
            for(auto it=own_card.begin();it!=own_card.end();it++)cnt[card->get_name(*it)]++;
            return cnt[card->get_name(n)]>=2;
        }
        void peng(int n){//碰函数
            int cnt=2;
            for(auto it=own_card.begin();it!=own_card.end()&&cnt;it++){
                if(card->get_name(*it)==card->get_name(n)){
                    discard(*it);
                    cnt--;
                }
            }
            int choice;//这里用qt来传递参数，表示要打出的牌
            // choice=
            // QT选择
            discard(choice);//打出这张牌
        }
        bool check_gang(int n){//检查是否可以杠
            map<string,int> cnt;
            for(auto it=own_card.begin();it!=own_card.end();it++)cnt[card->get_name(*it)]++;
            return cnt[card->get_name(n)]>=3;
        }
        int gang(int n){//杠函数
            int cnt=3;
            for(auto it=own_card.begin();it!=own_card.end()&&cnt;it++){
                if(card->get_name(*it)==card->get_name(n)){
                    discard(*it);
                    cnt--;
                }
            }
            get_back_card();//杠完要从后面摸牌
            if(check_win())return 666;//检查是否胡牌 胡牌返回666
            int choice=*own_card.begin();//这里是默认出第一张牌，但可以通过qt传参来控制出牌
            // choice= 
            // discard(choice)=  QT;
            /* 
                qt调用 选择弃牌
             */
            discard(choice);//打出一张牌
            return choice;//返回打出的牌的序号
        }
        string get_name(){
            return name;//获得玩家名称
        }
};