#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int sz = s.size();
	int cnt = 0;
	for (int i = 0; i < sz; i++) {
		if (s[i] == '(') {
			cnt++;
		}
		else if (s[i] == ')') {
			cnt--;
		}
		if (cnt < 0) break;
	}
	if (cnt != 0) {
		cout << "False" << endl;
	}
	else {
		cout << "True" << endl;
	}
}