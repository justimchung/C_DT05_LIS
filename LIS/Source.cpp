#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
int LIS(vector<int>& LISTbl);
void splitStr(string s, vector<int>& buf, char c);
int main()
{
	string stmp;
	cin >> stmp;
	vector<int> buf;
	splitStr(stmp, buf, ',');
	cout << LIS(buf) << endl;
}

int LIS(vector<int>& LISTbl)
{
	if (LISTbl.size() == 0) return 0;
	vector<int> LISLen(LISTbl.size(), 1);
	for (int i = 1; i < LISTbl.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (LISTbl[j] < LISTbl[i])
				LISLen[i] = max(LISLen[i], LISLen[j] + 1);
		}
	}

	int maxlen = *max_element(LISLen.begin(), LISLen.end());
	return maxlen;
}

void splitStr(string s, vector<int>& buf, char c)
{
	buf.clear();
	stringstream ss(s);
	string token;
	while (getline(ss, token, c)) {
		buf.push_back(stoi(token));
	}
}
