
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define mod 100000007LL
/* Source of nlogn Suffix array : http://apps.topcoder.com/forums/?module=RevisionHistory&messageID=1171511*/
#define maxn 2000000
#define sd(x) scanf("%d", &x)
#define LL long long

char in[maxn];

int str[maxn];
int rnk[maxn], pos[maxn];
int cnt[maxn], nxt[maxn];
bool bh[maxn], b2h[maxn];

bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}
// Begin of the O(n) longest common prefix algorithm

int height[maxn];

void getHeight(int n){
  for (int i=0; i<n; ++i) rnk[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (rnk[i] > 0){
      int j = pos[rnk[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[rnk[i]] = h;
      if (h > 0) h--;
    }
  }
}
// End of LCP

/**
Begins Suffix Arrays implementation
* O(n log n) - Manber and Myers algorithm
*/
/**
Usage:
* Fill str with the characters of the string.
* Call SuffixSort(n), where n is the length of the string stored in str.
*/

/**
Output:
* pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
Each suffix is represented as a single integer (the position of str where it starts).
* rank = The inverse of the suffix array. rank[i] = the index of the suffix str[i..n)
in the pos array. (In other words, pos[i] = k <==> rank[k] = i)
With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
than str[j..n) if and only if rank[i] < rank[j]
*/

void suffixSort(int n){
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);

  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }

  for (int h = 1; h < n; h <<= 1){
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      nxt[i] = j;
      buckets++;
    }
    if (buckets == n) break;

    for (int i = 0; i < n; i = nxt[i]){
      cnt[i] = 0;
      for (int j = i; j < nxt[i]; ++j){
        rnk[pos[j]] = i;
      }
    }

    cnt[rnk[n - h]]++;
    b2h[rnk[n - h]] = true;
    for (int i = 0; i < n; i = nxt[i]){
      for (int j = i; j < nxt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = rnk[s];
          rnk[s] = head + cnt[head]++;
          b2h[rnk[s]] = true;
        }
      }
      for (int j = i; j < nxt[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[rnk[s]]){
          for (int k = rnk[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[rnk[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    rnk[pos[i]] = i;
  }
}

string s, AA, BB;
int sl, a1, a2;
int p1[maxn], p2[maxn];
int brr[maxn], err[maxn];
void kmp()
{
    int k = 0;
		for(int i = 2; i < a1; i++){
			while(k > 0){
				if(AA[k + 1] == AA[i]){
					break;
				}
				k = p1[k];
			}
			if(AA[k + 1] == AA[i]){
				k++;
			}
			p1[i] = k;
		}
		p2[1] = 0;
		k = 0;
		for(int i = 2; i < a2; i++){
			while(k > 0){
				if(BB[k + 1] == BB[i]){
					break;
				}
				k = p2[k];
			}
			if(BB[k + 1] == BB[i]){
				k++;
			}
			p2[i] = k;
		}
		k = 0;
		for(int i = 1; i < sl; i++){
			while(k > 0){
				if(AA[k + 1] == s[i]){
					break;
				}
				k = p1[k];
			}
			if(AA[k + 1] == s[i]){
				k++;
			}
			if(k == a1 - 1){
				k = p1[k];
				brr[i - a1 + 2] = 1;
			}
		}
		err[0] = 0;
		for(int i = 1; i < sl; i++){
			while(k > 0){
				if(BB[k + 1] == s[i]){
					break;
				}
				k = p2[k];
			}
			if(BB[k + 1] == s[i]){
				k++;
			}
			err[i] = err[i - 1];
			if(k == a2 - 1){
				k = p2[k];
				err[i]++;
			}
		}
		for(int i = 1; i < sl; i++){
			str[i - 1] = s[i] - 'a';
		}
}
void inp()
{
        memset(brr, 0, sizeof brr);
		memset(err, 0, sizeof err);
		memset(height, 0, sizeof height);
        s = " " + s;
		sl = s.length();
		scanf("%s", in);
		AA = in;
		AA = " " + AA;
		a1 = AA.length();
		scanf("%s", in);
		BB = in;
		BB = " " + BB;
		a2 = BB.length();
		p1[1] = 0;
		kmp();
}
int main(){
	while(cin>>s){
        inp();
		suffixSort(sl - 1);
		getHeight(sl - 1);
		LL ans = 0;
		a1 = max(a1, a2);
		height[sl - 1] = 0;
		for(int i = 1; i < sl; i++){
			if(brr[pos[i - 1] + 1] == 1){
                if(sl - 1 - pos[i - 1] >= a1 - 1){
					ans += err[sl - 1] - err[pos[i - 1] + a1 - 1 - 1];
				}
				if(height[i] >= a1 - 1){
					ans -= err[pos[i - 1] + height[i]] - err[pos[i - 1] + a1 - 1 - 1];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
