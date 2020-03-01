#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
	map<string, set<int>> title_map, author_map, word_map, publisher_map, year_map;

	int n;
	cin >> n;
	int id;
	string title, author, word, publisher, year;

	for(int i = 0;i < n; i ++){
		cin >> id;
		cin.ignore();

		getline(cin, title);
		title_map[title].insert(id);

		getline(cin, author);
		author_map[author].insert(id);

		while(cin >> word){
			word_map[word].insert(id);
			char c = getchar();
			if(c == '\n')
				break;
		}

		getline(cin, publisher);
		publisher_map[publisher].insert(id);

		getline(cin, year);
		year_map[year].insert(id);
	}

	int m;
	int index;
	string query;
	cin >> m;


	for(int i = 0; i < m; i ++){
		scanf("%d: ", &index);
		getline(cin, query);
		cout << index << ": " << query << endl;
		switch(index){
			case 1:
				if(title_map.find(query) == title_map.end()){
					cout << "Not Found" << endl;
				}
				else
					for(auto iter = title_map[query].begin(); iter != title_map[query].end(); iter ++){
						printf("%07d\n", *iter);
					}
				break;
			case 2:
				if(author_map.find(query) == author_map.end())
					cout << "Not Found" << endl;
				else
					for(auto iter = author_map[query].begin(); iter != author_map[query].end(); iter ++){
						printf("%07d\n", *iter);
					}
				break;
			case 3:
				if(word_map.find(query) == word_map.end())
					cout << "Not Found" << endl;
				else
					for(auto iter = word_map[query].begin(); iter != word_map[query].end(); iter ++){
						printf("%07d\n", *iter);
					}
				break;
			case 4:
				if(publisher_map.find(query) == publisher_map.end())
					cout << "Not Found" << endl;
				else
					for(auto iter = publisher_map[query].begin(); iter != publisher_map[query].end(); iter ++){
						printf("%07d\n", *iter);
					}
				break;
			case 5:
				if(year_map.find(query) == year_map.end())
					cout << "Not Found" << endl;
				else
					for(auto iter = year_map[query].begin(); iter != year_map[query].end(); iter ++){
						printf("%07d\n", *iter);
					}
				break;

		}
	}
	return 0;
}