#include <iostream>
#include<bits/stdc++.h>
#include<string>
#define LL long long int
using namespace std;
int main() {
    LL len;
    string str;
    while(cin>>str)
        {
        	LL flag=1;
        	if(int(str[0]-'0') == 0)
        		return 0;
            len = str.length();
            LL dp[100000] = {0}    ;
            dp[0]=1;
            dp[1]=1;
            for(int i=1;i<len;i++){
                    LL tmp = (int)( 10* ((int)(str[i-1]-'0'))  + ( (int)(str[i]-'0')  )    );
                    if(str[i] != '0'  && str[i-1] != '0'   ){
                            if(  tmp < 27  )
                                dp[i+1]=dp[i]+dp[i-1];

                            else
                                dp[i+1] = dp[i];
                        }

                	else
                        if(str[i] != '0' && str[i-1] == '0'   )
                			{
                				dp[i+1]=dp[i];
                            }

                    else
                        dp[i+1] = dp[i-1] ;
                }

                if(flag)
                	cout<<dp[len]<<endl;
}
	return 0;
}
