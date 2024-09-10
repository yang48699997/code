#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <random>
using namespace std;

class Card{
    private:
        vector<int> card;//牌号 1-36对应筒 37-72对应条 73-108对应万 109-112 对应东风 113-116对应 西风 
                        // 117-120 对应南风 121-124对应北风 125-128 白板 129-132 发财 133-136 红中
        const string f[3]={"筒","条","万"};
        const string za[3]={"白板","发财","红中"};
        const string nums[9]={"一","二","三","四","五","六","七","八","九"};
        map<int,string> card_name;  // 把牌号与代表的名字对应上
        deque<int> dq; //剩余牌堆
        int tot;// 牌的总数
    public:
        /* 
            初始化
            card牌堆
            card_name每个编号对应的牌的具体名称
        */
        Card():card(137),card_name(),dq(){
            tot=136;
            for(int i=1;i<=136;i++)card[i]=i;
            for(int i=1;i<=108;i++){//处理 筒、条、万
                int p=(i-1)/36; //对应的大类 1-36筒 37-72条 73-108 万
                int n=(i-p*36-1)/4;//对应的数字每一类中四个为一组 对应 一、二···九
                card_name[i]=nums[n]+f[p];
            }
            for(int i=0;i<4;i++)card_name[i+109]="东风";
            for(int i=0;i<4;i++)card_name[i+113]="西风";
            for(int i=0;i<4;i++)card_name[i+117]="南风";
            for(int i=0;i<4;i++)card_name[i+121]="北风";
            for(int i=125;i<=136;i++){
                card_name[i]=za[(i-125)/4];
            }
        }
        /* 
            打乱牌
        */
     
        void start(){
            for(int i=1;i<=tot;i++){//打乱牌序
                int tar=rand()%tot+1;
                swap(card[i],card[tar]);
            }
            for(int i=1;i<=tot;i++){//把牌放入牌堆
                dq.push_back(card[i]);
            }
        }
        /* 
            玩家起牌
         */
        int get_card(){//从前面摸牌
            if(dq.size()==0)return 0;//当牌已经被摸完时 返回0
            int p=dq.front();
            dq.pop_front();
            return p;//摸牌成功，返回摸到的牌的序号
        }
        int get_back_card(){//逻辑同上，只不过是从后面摸牌
            if(dq.size()==0)return 0;
            int p=dq.back();
            dq.pop_back();
            return p;
        }
        /* 
            查询
         */
        string get_name(int n){//从牌的序号获取牌的名称
            return card_name[n];
        }
        /* 
            判断牌堆是否有牌
         */
        bool is_empty(){
            return dq.empty();
        }

};
