#include<iostream>
#include<fstream>
using namespace std;
class check
{
	private:
		int tempmax = 0;
		int max = 0;
		string s1 = "";
		string s2 = "";
		string tempmatch = "";
		string maxmatch = "";
	public:	
		check()
		{	ifstream file;
			file.open("input.txt");
			char r;
			int i=0;
			while(!file.eof())
			{
				file.read(&r,sizeof(char));
				if(r=='\n')
					i++;
				if(i==0)	
					s1 += r;
				else if(!file.eof())
					s2 += r;	
			}
			string temp = "";
			for(i=1;i<s2.length();i++)
			{
				temp += s2[i];
		    }
		    s2 = "";
		    for(i=0;i<temp.length();i++)
		    	s2 += temp[i];
		}
		void maxstring()
		{
			for(int y=0;y<s2.length();y++)
			{
				int j=y;
				tempmatch = "";
				tempmax = 0;
				for(int i=0;i<=s1.length();i++)
				{
					if(s1[i]==s2[j])
					{
						j++;
						tempmatch += s1[i];
						tempmax++;
						if(tempmax>max)
						{
							max = tempmax;
							maxmatch = "";	
							for(int k=0;k<tempmatch.length();k++)
							{
								maxmatch += tempmatch[k];
							}
						}
					}
					else if(s1[i]==s2[j-1])
					{
						tempmatch += "*";
						if(tempmax==max)
						{
							maxmatch = "";	
							for(int k=0;k<tempmatch.length();k++)
							{
								maxmatch += tempmatch[k];
							}
						}
					}
					else{
						tempmatch = "";
						tempmax=0;
						j=0;
					}
				}
			}
		ofstream outfile("output.txt");
		for(int k=0;k<maxmatch.length();k++)
			outfile.write(&maxmatch[k],sizeof(char));
	}
};
int main()
{
	check c;
	c.maxstring();
}

