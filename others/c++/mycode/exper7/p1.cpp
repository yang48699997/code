#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <functional>

using namespace std;

class Index {
public:
    int comparisonCount=0;
    int movementCount=0;
};

Index insertionSort(vector<int> array) {
    int n = array.size();
    Index index;
    index.comparisonCount=0;
    index.movementCount=0;
    for (int i = 1; i < n; i++ ) {
        int key = array[i];
        int j = i - 1;
        index.comparisonCount++;
        while (j >= 0 && array[j] > key) {
            index.comparisonCount++;
            index.movementCount++;
            array[j + 1] = array[j];
            j--;
        }
        array[++j] = key;
    }
    return index;
}

Index shellSort(vector<int> array) {
    int n = array.size();
    Index index;
    index.comparisonCount=0;
    index.movementCount=0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = array[i];
            int j = i;
            index.comparisonCount++;
            while (j >= gap && array[j - gap] > temp) {
                index.comparisonCount++;
                index.movementCount++;
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
    }
    return index;
}

Index bubbleSort(vector<int> arr) {
    int n = arr.size();
    Index index;
    index.comparisonCount=0;
    index.movementCount=0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            index.comparisonCount++;
            if (arr[j] > arr[j + 1]) {
                index.movementCount+=3;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return index;
}

Index quickSort(vector<int> array){
    int n=array.size();
    Index index;
    index.comparisonCount=0;
    index.movementCount=0;
    function<void(vector<int>,int,int)> f =[&](vector<int> arr,int l,int r)->void {
        if (l >= r) return; 
        int i = l; 
        int j = r; 
        int val = arr[l];
        while (i < j) {  
            while (i < j && arr[j] >= val) {
                j--;
                index.comparisonCount++;
            }
            if (i < j) { 
                arr[i] = arr[j]; 
                index.comparisonCount++;
                index.movementCount++;
                i++; 
            } 
            while (i < j && arr[i] < val)  {
                i++; 
                index.comparisonCount++;
            }
            if (i < j) { 
                arr[j] = arr[i]; 
                index.comparisonCount++;
                index.movementCount++;
                j--; 
            } 
        }
        arr[i] = val; 
        f(arr,l,i-1);
        f(arr,i+1,r);
    };
    f(array,0,n-1);
    return index;
}


Index SelectionSort(vector<int> arr){  
    int n=arr.size();
    Index index;
    index.comparisonCount=0;
    index.movementCount=0;
    for(int  i=0;i<n;i++){
        int temp=i;
        for(int j=i+1;j<n;j++){
            index.comparisonCount++;
            if(arr[j]<arr[temp]){
                temp=j;
                index.movementCount++;
            }
        }
        if(temp!=i){
            index.comparisonCount++;
            index.movementCount+=3;
            int x=arr[i];
            arr[i]=arr[temp];
            arr[temp]=x;
        }
    }    
    return index;
}

Index HeapSort(vector<int> arr){
    int n=arr.size();
    Index index;
    index.comparisonCount=0;
    index.movementCount=0;
    function<void(int)> adj=[&] (int i)->void{
        int cur=i;
        int l=i*2+1;
        int r=i*2+2;
        index.comparisonCount++;
        if(l<n&&arr[l]>arr[cur]){
            cur=l;
        }
        index.comparisonCount++;
        if(r<n&&arr[r]>arr[cur]){
            cur=r;
        }
        if(cur!=i){
            index.comparisonCount++;
            index.movementCount+=3;
            int tmp=arr[i];
            arr[i]=arr[cur];
            arr[cur]=tmp;
            adj(cur);
        }
    };
    for(int i=n/2-1;i>=0;i--){
        adj(i);
    }
    for(int i=n-1;i>=0;i--){
        index.movementCount++;
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        adj(0);
    }
    return index;
}


void merge(vector<int>& arr, int left, int mid, int right,vector<int> &cnt) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftHalf(n1), rightHalf(n2);
    for (int i = 0; i < n1; i++) {
        cnt[1]++;
        cnt[0]++;
        leftHalf[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        cnt[1]++;
        cnt[0]++;
        rightHalf[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        cnt[0]++;
        if (leftHalf[i] <= rightHalf[j]) {
            cnt[1]++;
            cnt[0]++;
            arr[k++] = leftHalf[i++];
        } else {
            cnt[1]++;
            cnt[0]++;
            arr[k++] = rightHalf[j++];
        }
    }
    while (i < n1) {
        cnt[1]++;
        cnt[0]++;
        arr[k++] = leftHalf[i++];
    }
    while (j < n2) {
        cnt[1]++;
        cnt[0]++;
        arr[k++] = rightHalf[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right,vector<int> &cnt) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid,cnt);
        mergeSort(arr, mid + 1, right,cnt);
        merge(arr, left, mid, right,cnt);
    }
}

int main() {
    vector<int> len={200,500,1000,1500,2000};
    vector<vector<int>> nums(300);
    srand((unsigned)time(NULL));
    random_device seed;
	ranlux48 engine(seed());
    uniform_int_distribution<> dis(1, 1000);
    for(int i=0;i<5;i++){
        
        for(int j=0;j<len[i];j++){
            nums[i].push_back(dis(engine));
        }
    }
    for(int i=0;i<5;i++){
        Index index1=insertionSort(nums[i]);
        Index index2=shellSort(nums[i]);
        Index index3=bubbleSort(nums[i]);
        Index index4=quickSort(nums[i]);
        Index index5=SelectionSort(nums[i]);
        Index index6=HeapSort(nums[i]);
        vector<int> cnt(2,0);
        mergeSort(nums[i],0,len[i]-1,cnt);
        cout<<"第"<<(i+1)<<"次测试，数据长度为"<<len[i]<<endl;
        cout<<"插入排序的比较次数为"<<index1.comparisonCount<<"移动元素次数为"<<index1.movementCount<<endl;
        cout<<"希尔排序的比较次数为"<<index2.comparisonCount<<"移动元素次数为"<<index2.movementCount<<endl;
        cout<<"冒泡排序的比较次数为"<<index3.comparisonCount<<"移动元素次数为"<<index3.movementCount<<endl;
        cout<<"快速排序的比较次数为"<<index4.comparisonCount<<"移动元素次数为"<<index4.movementCount<<endl;
        cout<<"选择排序的比较次数为"<<index5.comparisonCount<<"移动元素次数为"<<index5.movementCount<<endl;
        cout<<"堆排序的比较次数为"<<index6.comparisonCount<<"移动元素次数为"<<index6.movementCount<<endl;
        cout<<"归并排序的比较次数为"<<cnt[0]<<"移动元素次数为"<<cnt[1]<<endl;
    }

    return 0;
}
