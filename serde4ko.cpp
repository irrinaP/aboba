#include <iostream>
 #include <fstream>
 #include <string>

 using namespace std;
 struct count {
   char letter;
   int repeats = 0;
 };
 struct doubleCount {
   char letter1;
   char letter2;
   int repeats = 0;
 };

 int main() {
   ifstream file;
   string lineMas;
   char alphabet;
   count letter[1000];

   doubleCount doubleLetter[1000];
   int number1;
   int number2;
   int number3;
   int maxNumber1 = 0;
   int maxNumber2 = 0;
   int buffer1 = 0;
   int buffer2 = 0;
   int doubleFrequency = 0;

   file.open("txt");

   if (!file.is_open()) {
     cout << "Данный файл не найден";
     return 0;
   }

   while (getline(file, lineMas)) { 
     for (number1 = 0; number1 < lineMas.length(); ++number1) {
       lineMas[number1] = (lineMas[number1]);

       if (isalpha(lineMas[number1])) {
         for (number2 = 0; number2 < maxNumber1; ++number2) {
           if (lineMas[number1] == letter[number2].letter) {
             ++buffer1;
             ++letter[number2].repeats;
              break;
           }
         }

         for (number3 = 0; number3 < maxNumber2; ++number3) {
           if (lineMas[number1] == doubleLetter[number3].letter2 && alphabet == doubleLetter[number3].letter1 && isalpha (alphabet)) {
             ++buffer2;
             ++doubleLetter[number3].repeats;
             break;
           }
         }

         if (buffer1 == 0) {
           letter[number2].letter = lineMas[number1];
           ++maxNumber1;
         } else {
             --buffer1;
         }

         if (buffer2 == 0) {
           doubleLetter[number3].letter2 = lineMas[number1] ;
           doubleLetter[number3].letter1 = alphabet;
           ++maxNumber2;
         } else {
             --buffer2;
         }
       }
       alphabet = lineMas[number1];
     }
   }
   file.close();

   for (number1 = 0; number1 < maxNumber1; ++number1) {
     if (letter[number1].repeats > 1) {
       cout << "Частота буквы " << letter[number1].letter << " повторяется =  " << letter[number1].repeats + 1  << " раз(а) \n";
     }
   }
   cout << "\n";

   for (number1 = 0; number1 < maxNumber2; ++number1) {
     if (doubleLetter[number1].repeats > 1) {
       cout << "Частота двухбуквенных символов " << doubleLetter[number1].letter1 << doubleLetter[number1].letter2  << " повторяется " << doubleLetter[number1].repeats + 1 << " раз(а) \n";
     }
   }
   return 0;
 }
