#include <bits/stdc++.h>
using namespace std;
int word_count/*��������*/,use[21]/*�ַ���ʹ�����*/,line1 = 0,line2 = 0/*�ַ�������*/; 
string word[21],sentence/*�����ַ���*/;
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
		dsf(s1+news);//�Ͳ�һ���ˣ�����δ֪ 
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
	
	cin>>word_count;//���뵥������ 
	for(int i=1;i<=word_count;i++) cin>>word[i];//���뵥�� 
//	cin>>word[0];//������ʼ��ĸ
	word[0]=getchar();
	dsf(word[0]);
	
	cout<<line2;
	return 0;
} 
