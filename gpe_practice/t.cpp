//概率题
//先求出每一次中，抽到两个红球的概率为pi，qi=1-pi,表示每一次中不是抽到两个红球的概率
//pi=(1/i)*(1/(i+1))=1/(i*i+i)
//题目要求所有抽取中，至少有一次抽到两个红球的概率
//我们算出所有抽取中，每次都没有抽到两个红球的概率Q=(q1*q2*q3……qn)，则1-Q为所求答案
//另外要求出，每一次都抽到两个红球的概率，即P=(p1*p2*p3……pn)
//但P这个数值必定非常小，所以题目只需要输出P小数点后有多少个连续的0
//我们来分析P这个数字，令P=10^a，易知a是个负数，令a=i+d，i为整数部分，d为小时部分
//则P=10^i*10^d，可知10^i是决定倍数的。而-1<d<=0,所以 0.1<10^d<=1，所以i就是0的个数

#include <cstdio>
#include <cmath>
#define N 1000000

double ans[N+10];
int c[N+10];

int main()
{
    double p=1,q=1,a=0;
    for(long long i=1; i<=N; i++) //用int会爆
    {
        p=1./(i*i+i);
        q*=(1-p);
        ans[i]=1-q;
        a+=log10(1.*i*i+i);
        c[i]=(int)(a-fmod(a,1));
    }
    
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%.6f %d\n",ans[n],c[n]);
    return 0;
}