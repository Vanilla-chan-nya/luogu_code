#include <bits/stdc++.h>
using namespace std;
int word_count/*��������*/,use[21]/*�ַ���ʹ�����*/,line = 0,line_end = 0/*�ַ�������*/; 
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
		int ch = can(s1,word[i]);//ʹ��ch�洢�����ַ�������ͬ���ֵĳ��� 
		if(ch>0){
		use[i]++;
		line += ch;
		for(int j = ch;j<=word[i].size();j++)  news +=word[i].at(j);
		dsf(s1+news);//�Ͳ�һ���ˣ�����δ֪ 
		if(line_end<line) line_end = line;
		use[i]--;
		line -= ch;
		} 
 	}
 	
 	return;
}
int main()
{
	
	cin>>word_count;//���뵥������ 
	for(int i=1;i<=word_count;i++) cin>>word[i];//���뵥�� 
	cin>>word[0];//������ʼ��ĸ 
	dsf(word[0]);
	
	cout<<line;
	return 0;
} 
