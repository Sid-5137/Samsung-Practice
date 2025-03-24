/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of wormholes; each wormhole has 5 values. First 2 values are starting co-ordinate
of wormhole and after that value no. 3 and 4 represents ending co-ordinate of wormhole and last 5th
value is represents cost to pass through this wormhole. Now these wormholes are bi-directional. Now
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum
distance for spaceship to reach from source to destination co-ordinate using any number of worm-hole.
It is ok if you wont use any wormhole.
*/


#include <iostream>
#include <climits>

using namespace std;

int ANS = INT_MAX, n, temp = 0;
int w[35][5];
int mask[35];

int abs(int i) {
	return (i >= 0) ? i : -1 * i;
}

int min(int x, int y) {
	return (x >= y) ? y : x;
}

int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

void wormhole(int sX, int sY, int tX, int tY, int value) {
	ANS = min(ANS, dist(sX, sY, tX, tY) + value);
	for (int i = 0; i < n; i++) {
		if (mask[i] == 0) {
			mask[i] = 1;
			temp = dist(sX, sY, w[i][0], w[i][1]) + w[i][4] + value;
			wormhole(w[i][2], w[i][3], tX, tY, temp);

			temp = dist(sX, sY, w[i][2], w[i][3]) + w[i][4] + value;
			wormhole(w[i][0], w[i][1], tX, tY, temp);
			mask[i] = 0;
		}
	}
}

int main() {
		
	int t, sX, sY, tX, tY;
	cin >> t;

	while (t--) {	
		cin >> n;
		cin >> sX >> sY >> tX >> tY;
		ANS = INT_MAX;

		for (int i = 0; i < n; i++) {
			mask[i] = 0;
			for (int j = 0; j < 5; j++) {
				cin >> w[i][j];
			}
		}

		wormhole(sX, sY, tX, tY, 0);
		cout << "Answer is: " << ANS;
	}
	return 0;
}