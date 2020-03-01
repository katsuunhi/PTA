#include <iostream>
#include <set>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> course[2510];
string name[40010];
bool cmp(int a, int b){
	return strcmp(name[a].c_str(), name[b].c_str())< 0;
}
int main(){
	int n, k, num, index;
    cin >> n;
    cin >> k;
	for(int i = 0; i < n; i ++){
        cin >> name[i];
        cin >> num;
		for(int j = 0; j < num; j ++){
			scanf("%d", &index);
			course[index].push_back(i);
		}
	}
	for(int i = 1; i <= k; i ++){
        printf("%d %d", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j ++)
            printf("\n%s", name[course[i][j]].c_str());
        printf("\n");
	}
	return 0;
}
