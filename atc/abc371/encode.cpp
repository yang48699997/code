#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned;

std::map<std::string, std::string> source_codes_1 = {
    {"业务报送数据", "1"},
    {"存在感知数据", "2"},
    {"其他数据", "3"}
};
std::map<std::string, std::string> source_codes_2[3] = {
    {
        {"前方地震应急指挥部", "00"},
        {"后方地震应急指挥部", "01"},
        {"应急指挥技术系统", "20"},
        {"社会服务工程应急救援系统", "21"},
        {"危险区预评估工作组", "40"},
        {"地震应急指挥技术协调组", "41"},
        {"震后政府信息支持工作项目组", "42"},
        {"灾情快速上报接收处理系统", "80"},
        {"地方地震局应急信息服务相关技术系统", "81"},
        {"其他", "99"}
    }, {
        {"互联网感知", "00"},
        {"通信网感知", "01"},
        {"气候网感知", "02"},
        {"电力系统感知", "03"},
        {"交通系统感知", "04"},
        {"其他", "05"}
    }, {
        {"", "00"}
    }
};
std::map<std::string, std::string> file = {
    {"文字", "0"},
    {"图像", "1"},
    {"音频", "2"}
    {"视频", "3"}
    {"其他", "4"}
};
std::map<std::string, std::string> earthquake_information_1 = {
    {"震情", "1"},
    {"人员伤亡及失踪", "2"},
    {"房屋破坏", "3"},
    {"生命线工程灾情", "4"},
    {"次生灾害", "5"}
};
std::map<std::string, std::string> earthquake_information_2[5] = {
    {
        {"震情信息", "01"}
    }, {
        {"死亡", "01"},
        {"受伤", "02"},
        {"失踪", "03"}
    }, {
        {"土木", "01"},
        {"砖木", "02"},
        {"砖混", "03"},
        {"框架", "04"},
        {"其他", "05"}
    }, {
        {"交通", "01"},
        {"供水", "02"},
        {"输油", "03"},
        {"燃气", "04"},
        {"电力", "05"},
        {"通信", "06"},
        {"水利", "07"}
    }, {
        {"崩塌", "01"},
        {"滑坡", "02"},
        {"泥石流", "03"},
        {"岩溶坍塌", "04"},
        {"地裂缝", "05"},
        {"地面沉降", "06"},
        {"其他（沙土液化、火灾、毒气、池露、爆炸、环境污染、瘟疫、海啸等）", "07"}
    }
};

std::map<std::string, std::string> earthquake_information_3[5] = { 
    {
        {"地理位置", "001"},
        {"时间", "002"},
        {"震级", "003"},
        {"震源深度", "004"},
        {"烈度", "005"}
    }, {
        {"受灾人数", "001"},
        {"受灾程度", "002"}
    }, {
        {"一般损坏面积", "001"},
        {"严重损坏面积", "002"},
        {"受灾程度", "003"}
    }, {
        {"受灾设施数", "001"},
        {"受灾范围", "002"},
        {"受灾程度", "003"}
    }, {
        {"灾害损失", "001"},
        {"灾害范围", "002"},
        {"受灾程度", "003"}
    }
};

void get() {
    std::cout << "1" << std::endl;
    CoInitialize(nullptr);  // 初始化 COM
    
    CLSID clsid;
    CLSIDFromProgID(L"Excel.Application", &clsid);
    
    IDispatch* excelApp = nullptr;
    HRESULT hr = CoCreateInstance(clsid, nullptr, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void**)&excelApp);
    if (SUCCEEDED(hr)) {
        VARIANT x;
        VariantInit(&x);
        x.vt = VT_BSTR;
        x.bstrVal = SysAllocString(L"region.xls");
        
        VARIANT result;
        VariantInit(&result);
        hr = excelApp->Invoke(DISPID_VALUE, IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, nullptr, &result, nullptr, nullptr);
        if (SUCCEEDED(hr)) {
            std::cout << "Excel 文件已加载" << std::endl;
        } else {
            std::cout << "加载失败" << std::endl;
        }
        VariantClear(&x);
    } else {
        std::cout << "加载失败" << std::endl;
    }
    CoUninitialize();  // 释放 COM
}


void solve() {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}