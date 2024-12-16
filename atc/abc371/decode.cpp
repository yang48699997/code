#include <bits/stdc++.h>

using ll = long long;

std::map<std::string, std::string> source_codes_1 = {
    {"1", "业务报送数据"},
    {"2", "存在感知数据"},
    {"3", "其他数据"}
};

std::map<std::string, std::string> source_codes_2[3] = {
    {
        {"00", "前方地震应急指挥部"},
        {"01", "后方地震应急指挥部"},
        {"20", "应急指挥技术系统"},
        {"21", "社会服务工程应急救援系统"},
        {"40", "危险区预评估工作组"},
        {"41", "地震应急指挥技术协调组"},
        {"42", "震后政府信息支持工作项目组"},
        {"80", "灾情快速上报接收处理系统"},
        {"81", "地方地震局应急信息服务相关技术系统"},
        {"99", "其他"}
    }, {
        {"00", "互联网感知"},
        {"01", "通信网感知"},
        {"02", "气候网感知"},
        {"03", "电力系统感知"},
        {"04", "交通系统感知"},
        {"05", "其他"}
    }, {
        {"00", ""}
    }
};

std::map<std::string, std::string> file = {
    {"0", "文字"},
    {"1", "图像"},
    {"2", "音频"},
    {"3", "视频"},
    {"4", "其他"}
};

std::map<std::string, std::string> earthquake_information_1 = {
    {"1", "震情"},
    {"2", "人员伤亡及失踪"},
    {"3", "房屋破坏"},
    {"4", "生命线工程灾情"},
    {"5", "次生灾害"}
};

std::map<std::string, std::string> earthquake_information_2[5] = {
    {
        {"01", "震情信息"}
    }, {
        {"01", "死亡"},
        {"02", "受伤"},
        {"03", "失踪"}
    }, {
        {"01", "土木"},
        {"02", "砖木"},
        {"03", "砖混"},
        {"04", "框架"},
        {"05", "其他"}
    }, {
        {"01", "交通"},
        {"02", "供水"},
        {"03", "输油"},
        {"04", "燃气"},
        {"05", "电力"},
        {"06", "通信"},
        {"07", "水利"}
    }, {
        {"01", "崩塌"},
        {"02", "滑坡"},
        {"03", "泥石流"},
        {"04", "岩溶坍塌"},
        {"05", "地裂缝"},
        {"06", "地面沉降"},
        {"07", "其他（沙土液化、火灾、毒气、池露、爆炸、环境污染、瘟疫、海啸等）"}
    }
};

std::map<std::string, std::string> earthquake_information_3[5] = { 
    {
        {"001", "地理位置"},
        {"002", "时间"},
        {"003", "震级"},
        {"004", "震源深度"},
        {"005", "烈度"}
    }, {
        {"001", "受灾人数"},
        {"002", "受灾程度"}
    }, {
        {"001", "一般损坏面积"},
        {"002", "严重损坏面积"},
        {"003", "受灾程度"}
    }, {
        {"001", "受灾设施数"},
        {"002", "受灾范围"},
        {"003", "受灾程度"}
    }, {
        {"001", "灾害损失"},
        {"002", "灾害范围"},
        {"003", "受灾程度"}
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