#include <iostream>
#include <bitset>
#define SIZE 100000000
#define MAX (int)(SIZE-3)/2
using namespace std;

bool primes[MAX+1];
bitset<MAX+1> bset;
void setPrimes()
{
    int i,j;
    for(i=0;i*i<=SIZE;i++)
        if(!bset.test(i))
             for(j=i+1;(2*j+1)*(2*i+3)<=SIZE;j++)
                  bset.set(((2*j+1)*(2*i+3)-3)/2);
}
int main() {

	cout<<2<<endl;
	setPrimes();
	int coun = 0,p,j,cn=0,v;
	for (int i = 0; i < MAX+1; i++)
		if (!bset.test(i))
        {
            p = 2*i+3 ;j = 0;
            while(p!=0)
            {
                j *=10;
                j += p%10;
                p/=10;
            }

            v = (j-3)/2;
            if(j==2*v+3&&!(bset.test(v))&&j<=(2*i+3))
            {
                //cn++;
                cout<<2*i+3<<endl;
            }
        }
    //cout<<cn<<endl;
        return 0;
}
