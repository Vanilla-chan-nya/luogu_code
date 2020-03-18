#include <bits/stdc++.h>
using namespace std;
int word_count/*单词数量*/,use[21]/*字符串使用情况*/,line1 = 0,line2 = 0/*字符串长度*/; 
string word[21],sentence/*最终字符串*/;
int can(string str1){
	int g=1;
	for(int i = 1;i < min(str1.size(),sentence.size());i++){
		g=1;
		for(int j = 1;j <= i;j++)
			if(str1[str1.size() - i + j] != sentence[j]) g=0;
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
		int ch = can(word[i]);
		if(ch>0){
		use[i]++;
		line1 += ch;
		for(int j = ch;j<=word[i].size();j++)  news +=word[i].at(j);
		dsf(s1+news);//就差一点了：问题未知 
		use[i]--;
		line1 -= ch;
		} 
 	}
 	//if(sentence.size() > (s1+news).size()) sentence = (s1+news);
 	if(line1 > line2) line2 = line1;
 	return;
}
int main()
{
	
	cin>>word_count;//输入单词数量 
	for(int i=1;i<=word_count;i++) cin>>word[i];//输入单词 
//	cin>>word[0];//输入起始字母
	word[0]=getchar();
	dsf(word[0]);
	
	cout<<line2;
	return 0;
} 
