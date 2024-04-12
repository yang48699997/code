#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student{
    public:
        string name;
        string gender;
        int identity;
        int tot_score;
        int maths;
        int English;
        int Chines;
        Student(string name,string gender,int identity,int scores,int score1,int score2,int score3){
            this->name=name;
            this->gender=gender;
            this->identity=identity;
            this->tot_score=scores;
            this->maths=score1;
            this->English=score2;
            this->Chines=score3;
        }
        void print_inf(int rate){
            cout<<"学生姓名为:"<<name<<endl;
            cout<<"学号为:"<<identity<<endl;
            cout<<"总分为:"<<tot_score<<",排名为:"<<rate<<endl;
            cout<<"数学分数为:"<<maths<<endl;
            cout<<"英语分数为:"<<English<<endl;
            cout<<"语文分数为:"<<Chines<<endl;
        }
};
int main(){
    vector<Student> f={
        {"学生1","男",2022211001,279,90,100,89},
        {"学生2","男",2022211002,240,80,80,80},
        {"学生3","女",2022211003,257,90,90,77},
        {"学生4","女",2022211004,271,90,92,89},
        {"学生5","男",2022211005,285,95,95,95},
        {"学生6","男",2022211006,243,80,74,89},
        {"学生7","女",2022211007,293,97,99,97},
        {"学生8","男",2022211008,289,94,95,100},
        {"学生9","女",2022211009,267,90,90,87},
        {"学生10","男",2022211010,274,93,92,89}
    };
    sort(f.begin(),f.end(),[&](auto a,auto b)->bool{
        return a.tot_score>b.tot_score;
    });
    for(int i=1;i<=10;i++){
        auto s=f[i-1];
        s.print_inf(i);
    }
    return 0;
}