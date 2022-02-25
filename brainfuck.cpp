#include <string>
#include <iostream>

using namespace std;

void error() {
	cout << "UNBALANCED BRAKCTES" << endl;
	exit(1);
}

void interpret(string code, char *ptr) {
	int c=0;
	int j;
	for(int i=0; i<code.length(); i++) {
		switch(code[i]) {
			case '>':
				ptr++;
				break;
			case '<':
				ptr--;
				break;
			case '+':
				(*ptr)++;
				break;
			case '-':
				(*ptr)--;
				break;
			case '.':
				putchar(*ptr);
				break;
			case ',':
				*ptr = getchar();
				break;
			case '[':
				for(j=i; j<=code.length(); ++j) {
					if(code[j] == '[') c++;
					if(code[j] == ']') {
						c--;
						if(c==0) break;
					}
				}
				if(c>0) error();
				while(*ptr) interpret(code.substr(i+1, j-(i+1)), ptr);
				i = j;
				break;
			case ']':
				error()
				break;
		}
	}
}

int main() {
	char array[30000] = {0};
	char *ptr = array;
	string code;
	getline(cin, code);
	interpret(code, ptr);
	exit(0);
}
