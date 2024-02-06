
#pragma once
#include<iostream>
#include <cmath> 
#include <string>
#include <cstdlib>
using namespace std;
enum en_random { small = 1, capital = 2, special = 3, digit = 4 };
enum en_number_type { prime = 1, NotPrime = 2 };
class clsutil
{
public:
	static void check_odd_even(int number) {

		if (number % 2 == 0)

			cout << "It Is even number";

		else
			cout << "It Is odd number";


	}

    static void Print_number_in_each_reverse(int number) {

        int reminder = 0;
        while (number > 0)
        {
            reminder = number % 10;
            number = number / 10;
            cout << reminder << endl;
        }



    }



    static int Print_number_reverse_one_Line(int number) {

        int reminder = 0, number2 = 0;

        while (number > 0)
        {
            reminder = number % 10;
            number = number / 10;
            number2 = number2 * 10 + reminder;


        }

        return number2;

    }


    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

   static int random_number(int from, int to) {
        int random = rand() % (to - from + 1) + from;
        return random;
    }

   char random_of_4_type(en_random num) {
       //fun to return a random value of your selection
       switch (num)
       {
       case en_random::small:
       {
           return  char(random_number(97, 122));
       }
       case en_random::capital:
       {
           return char(random_number(65, 90));

       } case en_random::special:
       {
           return char(random_number(33, 47));

       }
       case en_random::digit:
       {
           return char(random_number(48, 57));

       }
       default: {

           cout << "Wrong Opereation number";
       }
       }

   }

   static void key_generator(int num) {
       int count = 0;
       en_random type;
       do
       {
           count++;
           if (en_random::capital)
           {
               cout << "\nKey  [ " << count << " ] : " << " ";
               for (int a = 1; a < 5; a++)
               {
                   if (a > 1)
                   {
                       cout << "-";
                   }
                   cout << char(random_number(65, 90));


                   for (int i = 1; i < 4; i++)
                   {

                       cout << char(random_number(65, 90));


                   }



               }


           }
       } while (count < num);
       



   }
   static string  Encrypt_text(string Text, short EncryptionKey=2)
   {

       for (int i = 0; i <= Text.length(); i++)
       {

           Text[i] = char((int)Text[i] + EncryptionKey);

       }

       return Text;

   }

   static string  Decrypt_text(string Text, short DecryptionKey=2)
   {

       for (int i = 0; i <= Text.length(); i++)
       {

           Text[i] = char((int)Text[i] - DecryptionKey);

       }
       return Text;

   }
  static en_number_type check_prime_or_not(int number) {
       int M = round(number / 2);
       for (int i = 2; i <= M; i++)
       {
           if (number % i == 0)

               return en_number_type::NotPrime;


       }
       return en_number_type::prime;


   }


  static void print_is_prime_or_not(int number) {

      if (check_prime_or_not(number) == en_number_type::NotPrime)
      {
          cout << "\n Number is not a prime number  ";
      }
      else
          cout << "Number is a prime";

  }

  //round using my logic 
  static float GetFractionPart(float Number) {
      return Number - int(Number);
  }

  static int MyRound(float Number) {
      int IntPart;
      IntPart = int(Number);
      float FractionsPart = GetFractionPart(Number);

      if (abs(FractionsPart) >= 0.5) {
          if (Number > 0)
              return ++IntPart;
          else
              return --IntPart;
      }
      else {
          return IntPart;
      }
  }



    
};

