#include <fstream>
#include <stdio.h>      
#include <time.h> 
#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
	ofstream fout;
    fout.open("output.txt");

	srand (time(NULL));
	int keyLength = 16;
	int temp;

	int S[256];
	int Key[keyLength];

	int iterations = 25600;
	while(iterations--) {
		for(int i = 0; i < 256; ++i) {
			S[i] = i;
		}
		int j = 0;

		cout << keyLength << " " << endl;

		/*randomize key */
		for(int i = 0; i < keyLength; ++i) {
			Key[i] = rand() % 255 + 1;
		}

		/* initialize */
		for(int i = 0; i <= 255; ++i) {
			j = (j + S[i] + Key[i % keyLength]) % 256;
			temp = S[i];
			S[i] = S[j];
			S[j] = temp;
		}

		/* generate stream */
		int i = 0;
		j = 0;
		int counter = 1;

		while(counter <= 2) {
			i = (i + 1) % 256;
			j = (j + S[i]) % 256;
			counter++;
			temp = S[i];
			S[i] = S[j];
			S[j] = temp;
			fout << S[(S[i] + S[j]) % 256] << " ";
		}
		fout << "\n";
	}
}

