#include <iostream>
#include <algorithm>
using namespace std;

#define ORDER 1

float d[1000][1000];

void printArr(float arr[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		printf("%.1lf  ", arr[i]);
		// cout << arr[i] << " ";
	}
	cout << "\n";
}

float EditDistance(string src, string target, float icost, float dcost, float ccost, int flag = 0) {
	cout << "Source : " << src << " / Target : " << target << "\n";
	cout << "insertion cost : " << icost << " / deletion cost : " << dcost << " / change cost : " << ccost;
	if (flag == ORDER) cout << " / print order";
	cout << endl;

	int m = src.length(), n = target.length();
	src = " " + src;
	target = " " + target;

	d[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		d[i][0] = d[i - 1][0] + icost;
	}
	for (int j = 1; j <= m; j++) {
		d[0][j] = d[0][j - 1] + dcost;
	}

	float cost = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (src[j] == target[i]) cost = 0;
			else cost = ccost;
			d[i][j] = min({ d[i][j - 1] + dcost, d[i - 1][j] + icost, d[i - 1][j - 1] + cost });
		}
	}

	for (int i = 0; i <= n; i++) {
		printArr(d[i], m);
	}
	if (flag == ORDER) {
		int i = n, j = m;
		i = n; j = m;
		float cur = d[n][m];
		while (cur != 0) {
			cur = d[i][j];
            cout<<cur-d[i-1][j]<<endl;

			if (cur - d[i][j - 1] == dcost) {
				cout << "Delete " << src[j] << endl;
				j--;
			}
			else if (cur - d[i - 1][j - 1] == ccost) {
				cout << "Change " << src[j] << " to " << target[i] << endl;
				i--; j--;
			}
			else if (cur - d[i - 1][j] == icost) {
				cout << "Insert " << target[i] << endl;
				i--;
			}
			else {
				i--; j--;
			}

		}
	}
	return d[n][m];
}

int main() {
	string src = "GUMBO";
	string target = "GAMBOL";
	float result;

	result = EditDistance(src, target, 1, 1, 1);
	cout << "Least Distance : " << result << "\n\n";

	result = EditDistance(src, target, 0.7, 0.5, 0.3);
	cout << "Least Distance : " << result << "\n\n";

	//src = "Levenshtein"; target = "Meilenstein";
	//result = EditDistance(src, target, 0.7, 0.5, 0.3, ORDER);
	//cout << "Least Distance : " << result << "\n\n";

	src = "TACTG"; target = "CATGACTG";
	result = EditDistance(src, target, 0.7, 0.5, 0.3, ORDER);
	cout << "Least Distance : " << result << "\n\n";

	// src = "데이타마이닝"; target = "데이터베이스설계";
	// result = EditDistance(src, target, 0.7, 0.5, 0.3, ORDER);
	// cout << "Least Distance : " << result << "\n\n";
}