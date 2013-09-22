#include<iostream>
#include<vector>
using namespace std;

int size;
unsigned long long *numbers;

int numOnes(unsigned long long n) {
    int num=0;
    while(n) {
        n = n&(n-1);
        num++;
    }
    return num;
}

int foo(vector<unsigned long long>& comps, int n) {
    if(n>=size)
        return 0;

    int ans=0;
    for(int i=n;i<size;i++) {
        vector<unsigned long long> *tempComps = new vector<unsigned long long>(comps);
        unsigned long long total=0;
        bool connected=false;
        if(numbers[i]!=0){
        for(int j=0;j<tempComps->size();j++) {
            if(numbers[i]&(*tempComps)[j]) {
                (*tempComps)[j] = numbers[i]|(*tempComps)[j];
                total |= (*tempComps)[j];
                connected=true;
                //break;
            }
            total |= (*tempComps)[j];
        }
        if(!connected) {
            total |= numbers[i];
            tempComps->push_back(numbers[i]);
        }}
        ans += tempComps->size();
        ans += (64-numOnes(total));
        ans += foo(*tempComps,i+1);
    }
    return ans;
}

int main() {
    size=0;
    cin>>size;
    numbers = new unsigned long long[size];
    for(int i=0;i<size;i++) {
        cin>>numbers[i];
    }
    int ans=0;
    ans += 64;
    ans += foo(*new vector<unsigned long long>,0);
    cout<<ans<<"\n";
    return 0;
}
