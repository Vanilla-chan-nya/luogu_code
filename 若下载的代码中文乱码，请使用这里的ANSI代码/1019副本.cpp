#include <bits/stdc++.h>
using namespace std;
int word_count/*单词数量*/,use[21]/*字符串使用情况*/,line = 0,line_end = 0/*字符串长度*/; 
string word[21];
int can(string str1,string str2){
	int g=1;
	for(int i = 1;i < min(str1.size(),str2.size());i++){
		g=1;
		for(int j = 1;j <= i;j++)
			if(str1[str1.size() - i + j] != str2[j]) g=0;
		if(g==1) return i;
			
	}
	return 0;
}

void dsf(string s1)
{
	
	string news;
	for(int i=1;i<=word_count;i++)
	{
		if(use[i]>=2) continue;
		int ch = can(s1,word[i]);//使用ch存储两个字符串的相同部分的长度 
		if(ch>0){
		use[i]++;
		line += ch;
		for(int j = ch;j<=word[i].size();j++)  news +=word[i].at(j);
		dsf(s1+news);//就差一点了：问题未知 
		if(line_end<line) line_end = line;
		use[i]--;
		line -= ch;
		} 
 	}
 	
 	return;
}
int main()
{
	
	cin>>word_count;//输入单词数量 
	for(int i=1;i<=word_count;i++) cin>>word[i];//输入单词 
	cin>>word[0];//输入起始字母 
	dsf(word[0]);
	
	cout<<line;
	return 0;
} 
