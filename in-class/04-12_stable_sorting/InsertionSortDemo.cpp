#include <iostream>
#include <string>
using namespace std;

void SelectionSort(int* numbers, int numbersSize) {
   for (int i = 0; i < numbersSize - 1; i++) {
      // Find index of smallest remaining element
      int indexSmallest = i;
      for (int j = i + 1; j < numbersSize; j++) {
         if (numbers[j] < numbers[indexSmallest]) {
            indexSmallest = j;
         }
      }
         
      // Swap numbers[i] and numbers[indexSmallest]
      int temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }
   
   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);
   
   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }
   
   // Add closing ']' and return result
   result += "]";
   return result;
}

int main() {
   // Create an array of numbers to sort
   int numbers[] = { 10, 2, 78, 2, 45, 32, 7, 11 };
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
      
   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;
     
   // Call the SelectionSort function
   SelectionSort(numbers, numbersSize);
      
   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}