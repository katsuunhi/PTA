#include <bits/stdc++.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
Sample Input:
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50

Sample Output:
Case #1:
Alice 18 88888
Billy 24 5888
Bob_Volk 24 5888
Dobby 24 5888
Case #2:
Joe_Mike 32 3222
Zoe_Bill 35 2333
Williams 30 -22
Case #3:
Anny_Cin 95 999999
Michael 5 300000
Alice 18 88888
Cindy 76 76000
Case #4:
None
*/
int num, k;
int Min = 0, Max = 0;
long int n;
static int book[210];
struct person{
	string name;
	int age;
	long int net;
};

bool cmp1(person p1, person p2){
	if(p1.net != p2.net)
		return p1.net > p2.net;
	if(p1.age != p2.age)
		return p1.age < p2.age;
	return strcmp(p1.name.c_str(), p2.name.c_str()) < 0;
}


int main(int argc, char** argv){
	scanf("%ld%d", &n, &k);
	vector<person> p(n), p2;
	for(long int i = 0; i < n; i ++){
		cin >> p[i].name;
		cin >> p[i].age;
		cin >> p[i].net;
	}
	sort(&p[0], &p[n], cmp1);
	for(int i = 0; i < n; i ++){
		if(book[p[i].age] < 100){
			p2.push_back(p[i]);
			book[p[i].age] ++;
		}
	}
	n = p2.size();
	for(int i = 0; i < k; i ++){
		cin >> num;
		cin >> Min;
		cin >> Max;
		vector<person> t;
		t.clear();
		cout << "Case #" << i + 1 << ":" << endl;
		for(int i = 0; i < n && num > 0; i ++){
			
			if(p2[i].age >= Min && p2[i].age <= Max){
				t.push_back(p2[i]);
				num --;
			}
		}
		if(t.size() == 0)
			cout << "None" << endl;
		for(int j = 0; j < t.size(); j ++)
			cout << t[j].name << " " << t[j].age << " " << t[j].net << endl;
	}
	return 0;
}
