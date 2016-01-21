#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string needle	;
string haystack	;
int main()  {
    long long int t ;
    size_t start	;
    while(scanf ("%lld\n",  &t) == 1){
        	cin >> needle >> haystack	;
        	start = -1	;
        	if (haystack.find(needle,start + 1) == std::string::npos)
        		continue	;
        	while (1) {
        			if (haystack.find(needle,start + 1) == std::string::npos)
        				break	;
        			start = haystack.find(needle,start + 1)	;
        			printf("%zd\n", start)	;
        	}
        	printf("\n\n")	;
        }



    return 0    ;

	}
