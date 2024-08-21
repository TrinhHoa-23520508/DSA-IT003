#include<iostream>
#include<string.h>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
struct user
{
	string username;
	vector<string> password;
};
typedef unordered_map<string, user> HASHTABLE;
void Insert(HASHTABLE& ht, const string& username, const string& password)
{
	if (ht.find(username) == ht.end())
	{
		user newuser;
		newuser.username = username;
		ht[username] = newuser;
	}
	ht[username].password.push_back(password);
}
string FindPassword(HASHTABLE& ht, const string& username)
{
	if (ht.find(username) == ht.end())
	{
		return "Unregistered User.";
	}
	else
	{
		return ht[username].password.back();
	}
}
void CreateHashTable(HASHTABLE& ht, int &M, int &N)
{
	string username;
	string password;
	cin >> M;
	cin >> N;
	while (M-- > 0)
	{
		cin >> username;
		cin >> password;
		Insert(ht, username, password);
	}
}
void Output(HASHTABLE ht, int N)
{
	vector<string> username;
	string user;
	while (N-- > 0)
	{
		cin >> user;
		username.push_back(user);
	}
	for (vector<string>::iterator a = username.begin(); a != username.end(); ++a)
	{
		cout << FindPassword(ht, *a);
		cout << endl;
	}
}
int main()
{
	HASHTABLE ht;
	int M;
	int N;
	CreateHashTable(ht, M, N);
	Output(ht, N);
	return 0;
}
