#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct record{
	string name;
	int mm;
	int dd;
	int hh;
	int m;
	int time;
	string word;
};

bool cmp(record &re1, record &re2){
	return re1.time < re2.time;
}

int main(int argc, char const *argv[])
{
	int prices[24];
	map<string, int> m;
	map<string, int>::iterator iter;
	for(int i = 0; i < 24; i ++){
		cin >> prices[i];
	}
	int n;
	cin >> n;
	struct record rec[n];

	for(int i = 0; i < n; i ++){
		scanf("%s%2d:%2d:%2d:%2d%s", &rec[i].name, &rec[i].mm, &rec[i].dd, &rec[i].hh, &rec[i].m, &rec[i].word);
		rec[i].time = rec[i].m + rec[i].hh*60 + (rec[i].dd-1)*60*24;
	}
	// cout << "over";
	sort(rec, rec + n, cmp);
	for(int i = 0; i < n; i ++){
		printf("%s %02d:%02d:%02d:%02d %s\n", rec[i].name, rec[i].mm, rec[i].dd, rec[i].hh, rec[i].m, rec[i].word);
	//	if(m.find(rec[i].name) == m.end())
		m.insert(pair<string, int>(rec[i].name, 1));
		cout << m[rec[i].name];
	}

	for(iter = m.begin(); iter != m.end(); iter ++)
		cout << 1 << iter -> first << endl;


	return 0;
}