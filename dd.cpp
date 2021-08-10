#include <iostream>
#include <algorithm>

using namespace std;

bool univ[101][101][101];

int r, n;
int temp;
bool ret;

int findstar(int x, int y, int z) {


	for (int i = x - r; i <= x + r; i++) {
		for (int j = y - r; j <= y + r; j++) {
			for (int k = z - r; k <= z + r; k++) {
				if (x == i && y == j && z == k) continue;
				if (x<0 || x>n - 1 || y<0 || y>n - 1 || z<0 || z>n - 1)continue;

				if (univ[i][j][k] == 1) return 0;
			}
		}
	}
	return 1;
}



int main() {
	//cout << "r,n ";
	cin >> r >> n;

	for (int i = 0; i < n; i++) {
		//cout << i << endl;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> univ[i][j][k];

			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//cout << i << endl;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (univ[i][j][k] == 1) {
					cnt = cnt + findstar(i, j, k);
				}
			}
		}
	}
	cout << cnt << endl;

}