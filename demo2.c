#include <stdio.h>
#include <stdlib.h>

int main() {
	char key[] = "the quick brown fox jumps over the lazy dog";
	char message[] = "vkbs bs t suepuv";
	char alpha[30];
	for (int i = 0; i <= 26; i++)
		alpha[i] = 0;
	int j = 'a';
	for (int i = 0; key[i] != '\0'; i++) {
		if (key[i] != ' ' && alpha[key[i] - 'a'] == 0) {
			alpha[key[i] - 'a'] = j;
			j++;
		}
	}
	for (int i = 0; message[i] != '\0'; i++) {
		if (message[i] != ' ')
			message[i] = alpha[message[i] - 'a'];
	}
	printf("%s\n", message);
	system("pause");
	return 0;
}