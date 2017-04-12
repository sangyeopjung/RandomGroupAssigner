/*
 * Random group assigner
 * By Sang Yeop Jung 2017
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int isNoExtra(int& extra) {
	if(extra) {
		extra--;
		return 0;
	} else
		return 1;
}

int main() {
	int num_groups, num_participants;

	cout << "# of groups? " << endl;
	cin >> num_groups;
	cout << "# of participants? " << endl;
	cin >> num_participants;

	vector<int> participants;
	for (int i = 0; i < num_participants; i++)
		participants.push_back(i+1);
	random_shuffle(participants.begin(), participants.end());

	int index = 0;
	int extra = num_participants % num_groups;
	for (int i = 0; i < num_groups; i++) {
		cout << "Group " << (char) (i+65) << ":\t";
		for (int j = isNoExtra(extra); j < num_participants/num_groups + 1; j++)
			cout << participants[index++] << "\t";
		cout << endl;
	}

	return 0;
}