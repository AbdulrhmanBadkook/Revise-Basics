#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cmath> 
#include <string>
#include <cstdlib>
#include "clsString.h";
#include "clsDate.h"
#include "clsutil.h"
#include "clsInputValidate.h"
using namespace std;


int main()

{
    
   clsutil::check_odd_even(23);
   cout << "\n\n";
   clsInputValidate::in_validate_number();
   cout << "\n\n";
  // clsutil::Print_number_in_each_reverse(1234);
   cout << "\n\n";
  // cout << clsutil::Print_number_reverse_one_Line(1234);
   cout << "Random number is : ";
  // clsutil::Srand();
  // cout << clsutil::random_number(13, 1000);
   cout << "\n\n";
   clsutil::key_generator(9);
   cout << "\n\n";
  // clsutil::print_is_prime_or_not(7);
   short key = 6;
   string Encrypted = clsutil::Encrypt_text("Abdurahman", key);
   cout << "Encrypted text Is : " << Encrypted <<endl;
   string Decrypted= clsutil::Decrypt_text(Encrypted, key);
   cout << "Decrypted text Is : " << Decrypted;
    return 0;
}