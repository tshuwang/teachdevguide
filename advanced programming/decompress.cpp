// C++ program to decode a string recursively 
// encoded as count followed substring 
#include<bits/stdc++.h> 
using namespace std; 

// Returns decoded string for 'str' 
string decode(string str) 
{ 
	stack<int> integerstack; 
	stack<char> stringstack; 
	string temp = "", result = ""; 

	// Traversing the string 
	for (int i = 0; i < str.length(); i++) 
	{ 
		int count = 0; 

		// If number, convert it into number 
		// and push it into integerstack. 
		if (str[i] >= '0' && str[i] <='9') 
		{ 
			while (str[i] >= '0' && str[i] <= '9') 
			{ 
				count = count * 10 + str[i] - '0'; 
				i++; 
			} 

			i--; 
			integerstack.push(count); 
		} 

		// If closing bracket ']', pop elemment until 
		// '[' opening bracket is not found in the 
		// character stack. 
		else if (str[i] == ']') 
		{ 
			temp = ""; 
			count = 0; 

			if (! integerstack.empty()) 
			{ 
				count = integerstack.top(); 
				integerstack.pop(); 
			} 

			while (! stringstack.empty() && stringstack.top()!='[' ) 
			{ 
				temp = stringstack.top() + temp; 
				stringstack.pop(); 
			} 

			if (! stringstack.empty() && stringstack.top() == '[') 
				stringstack.pop(); 

			// Repeating the popped string 'temo' count 
			// number of times. 
			for (int j = 0; j < count; j++) 
				result = result + temp; 

			// Push it in the character stack. 
			for (int j = 0; j < result.length(); j++) 
				stringstack.push(result[j]); 

			result = ""; 
		} 

		// If '[' opening bracket, push it into character stack. 
		else if (str[i] == '[') 
		{ 
			if (str[i-1] >= '0' && str[i-1] <= '9') 
				stringstack.push(str[i]); 

			else
			{ 
				stringstack.push(str[i]); 
				integerstack.push(1); 
			} 
		} 

		else
			stringstack.push(str[i]); 
	} 

	// Pop all the elmenet, make a string and return. 
	while (! stringstack.empty()) 
	{ 
		result = stringstack.top() + result; 
		stringstack.pop(); 
	} 

	return result; 
} 


string decompress(string str)
{
	stack<int> sint;
	stack<char> schr;
	string res="";
	string temp="";
	for (int i = 0; i <str.length(); i++)
	{
		//数字
		int count=0;
		if(str[i]>='0'&&str[i]<='9')
		{
			while (str[i]>='0'&&str[i]<='9')
			{
				count=count*10+str[i]-'0';
				i++;//移动到下一个
			}
			sint.push(count);
			i--;
		}
		
		// [ 字符
		else if(str[i]=='[')
		{
			if(str[i-1]>='0'&&str[i-1]<='9')//前面是数字
			{
				schr.push(str[i]);
			}

			else
			{
				schr.push(str[i]);
				sint.push(1);
			}		

		}

		// ] 字符
		else if(str[i]==']')
		{
			temp="";
			count=0;

			if(!sint.empty())
			{
				count=sint.top();
				sint.pop();
			}

			while(!schr.empty()&&schr.top()!='[')
			{
				temp=schr.top()+temp;
				schr.pop();
			}

			while (!schr.empty()&&schr.top()=='[')
			{
				schr.pop();
			}

			for(int j=0;j<count;j++)
			{
				res=res+temp;
			}
			
			for(int j=0;j<res.length();j++)
			{
				schr.push(res[j]);
			}

			res="";
		}
		
		//字母
		else
		{
			schr.push(str[i]);
		}		
	}
	
	
	while(!schr.empty())
	{
		res=schr.top()+res;
		schr.pop();
	}

	return res;
}

// Driven Program 
int main() 
{ 
	string str = "3[b2[ca]]"; 
	cout << decode(str) << endl;
	cout << decompress(str)<< endl; 
	return 0; 
} 
