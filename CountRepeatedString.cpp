#include <bits/stdc++.h> 

using namespace std;
  
int counter = 0;

void CountRepeat(char* pat, char* txt, int pat_len, int txt_len, int i){ 
	int j = i;
    while (i < txt_len) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
        if (j == pat_len) { 
            counter++;
			j = 0; 
        } 
        else if (pat[j] != txt[i]) 
			return;
	} 
} 

int main() { 
	char input[30], temp[30], pat_len=1, last_pat=0;
    cin>>input;
    int txt_len=strlen(input);
    
    int max = 0, x=0;

    for(int i=0; i<txt_len; i++){
    	counter=0;
    	temp[i] = input[i];
    	
		CountRepeat(temp, input, pat_len, txt_len, last_pat);
    	if(max < counter){
			max = counter;
			x=i;
		}
		
		last_pat++;
		pat_len++;
	}
	
	if(max > 1){
		cout<<"(";
		for(int i=0; i<=x; i++) 
			cout<<input[i];
		cout<<") "<<max<<endl;
	}
	else cout<<"none\n";
    return 0; 
} 
