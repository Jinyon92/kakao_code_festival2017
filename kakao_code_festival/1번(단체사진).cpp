#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

class kakao {
public:
	int a, b, type, value;

	void init(string &s, map<char, int> & mapping)
	{
		a = mapping[s[0]];
		b = mapping[s[2]];
		if (s[3] == '=')
			type = 0;
		if (s[3] == '<')
			type = 1;
		if (s[3] == '>')
			type = 2;
		value = s[4] - '0' + 1;
	}
};

int solve(vector<string> &data)
{
	int result = 0;
	string sk = "ACFJMNRT";
	map<char, int>mapping;
	for (int i = 0; i < 8; i++)
	{
		mapping[sk[i]] = i;
	}
	vector<kakao> v_ka;
	for (auto & s : data)
	{
		kakao ka;
		ka.init(s, mapping);
		v_ka.push_back(ka);
	}

	vector<int>a;
	for (int i = 0; i < 8; i++)
	{
		a.push_back(i);
	}
	
	do {
		bool isSat = true;
		for (auto & k : v_ka)
		{
			int gap = abs(a[k.a] - a[k.b]);
			if (k.type == 0)
			{
				if (gap != k.value) isSat = false;
			}
			if (k.type == 1 && gap >= k.value) isSat = false;
			if (k.type == 2 && gap <= k.value) isSat = false;
			if (!isSat) break;
		}
		if (isSat) result++;
	} while (next_permutation(a.begin(), a.end()));

	return result;
}

int main()
{
	int N, result;
	cin >> N;

	string *s = new string[N];
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}

	vector<string> data;
	for (int i = 0; i < N; i++)
	{
		data.push_back(s[i]);
	}
	result = solve(data);
	cout << result;

}