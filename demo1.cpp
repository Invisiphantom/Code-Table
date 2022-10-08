#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int num;
	cin >> num;
	bool signn = 0;
	if (num < 0) {
		signn = 1;
		num = -num;
	}
	char* hep = (char*)malloc(sizeof(char) * 32);
	int point = 0;
	do
		hep[point++] = num % 7 + 48;
	while ((num /= 7) > 0);
	if (signn)
		hep[point++] = '-';
	int l = 0, r = point - 1;
	while (l < r) {
		char mid = hep[l];
		hep[l] = hep[r];
		hep[r] = mid;
		l++;
		r--;
	}
	for (int i = 0; i <= point - 1; i++)
		cout << hep[i] << endl;
	system("pause");
	return 0;
}