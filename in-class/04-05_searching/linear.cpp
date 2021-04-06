#include <iostream>
using namespace std;

int LinearSearch(int *numbers, int numbersSize, int key) {
  for (int i = 0; i < numbersSize; i++) {
    if (numbers[i] == key) {
      return i;
    }
  }
  return -1; // not found
}

int main() {
  // TODO Change numbers to play with input size
  int numbers[] = {28, 85, 96, 50, 10, 69, 54, 50, 65, 32, 19, 25, 33, 75, 66, 31, 47, 34, 21};
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
  cout << "NUMBERS: [" << numbers[0];
  for (int i = 1; i < numbersSize; i++) {
    cout << ", " << numbers[i];
  }
  cout << "]" << endl;

  // Prompt for an integer to search for
  cout << "Enter an integer value: ";
  int key = 0;
  cin >> key;

  int keyIndex = LinearSearch(numbers, numbersSize, key);
  if (keyIndex == -1) {
    cout << key << " was not found." << endl;
  } else {
    cout << "Found " << key << " at index ";
    cout << keyIndex << "." << endl;
  }
}
