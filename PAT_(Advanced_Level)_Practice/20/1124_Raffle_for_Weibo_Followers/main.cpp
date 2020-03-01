/*

Sample Input 1:
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
Sample Output 1:
PickMe
Imgonnawin!
TryAgainAgain
Sample Input 2:
2 3 5
Imgonnawin!
PickMe
Sample Output 2:
Keep going...

*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{

	int m, n, s;
	int flag = 0;
	string follower;
	map<string, int> winners;
	map<string, int>::iterator iter;
	scanf("%d%d%d", &m, &s, &n);

	if(m < n){
		cout << "Keep going...";
		return 0;
	}

	for(int i = 0; i < n; i ++){  //前n个用户
		cin >> follower;
//		cout << i << endl;
	}

	winners.insert(pair<string, int>(follower, 1)); //把第n个存入字典
	cout << follower << endl;
	for(int i = n; i < m - 1; ){				//从第n+1个开始读取
		for(int j = 0; j < s; j ++){		//往后读s个数
			cin >> follower;
//			cout << follower << " pass" << endl;
			i ++;
			if(i == m)
				break;
			
		}
		if(i == m)    //如果已经是最后一个，退出
			break;
		
		while(winners.find(follower) != winners.end()){  //判断是否已经中奖，如果是，再读入一个
//			cout << follower << " had " << i << endl;
			cin >> follower;
			if(i == m){
				flag = 1;
//				cout << "exit" << endl;
				break;
			}
			i ++;
			
		}
		if(flag == 1)
			break;
		flag = 0;
		winners.insert(pair<string, int>(follower, 1));
		cout << follower << endl;
//		cout << follower << " save" << endl;
	}

	/*for(iter = winners.begin(); iter != winners.end(); iter ++){
		cout << iter -> first << endl;
	}*/
	return 0;
}