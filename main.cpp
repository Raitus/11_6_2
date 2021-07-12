#include <iostream>
#include "string"
bool checkSymbols(char symbol) {
  if (symbol=='!' || (symbol >= 35 && symbol <= 39) || (symbol >= 42 && symbol <= 43) || (symbol >= 45 && symbol <= 57)
	  || (symbol >= 65 && symbol <= 90) || (symbol >= 94 && symbol <= 126)) {
	return true;
  } else {
	return false;
  }
}
void validation(std::string email) {
  bool atSymbol = false, finalCheck = true;
  for (int symbol = 0, count = 0; symbol < email.length(); symbol++, count++) {
	if (email[symbol]=='@' && !atSymbol) {
	  if (count > 0 && count <= 64) {
		if (symbol==email.length() - 1){
		  std::cout << "No!";
		  finalCheck = false;
		  break;
		}else{
		  count = 0;
		}
	  } else {
		std::cout << "No!";
		finalCheck = false;
		break;
	  }
	  atSymbol = true;
	} else if (email[symbol]=='@' && atSymbol) {
	  std::cout << "No!";
	  finalCheck = false;
	  break;
	} else if (symbol==email.length() - 1 && count > 63 ) {
	  std::cout << "No!";
	  finalCheck = false;
	  break;
	} else if (email[symbol]=='.' && symbol!=0 && email[symbol - 1]=='.') {
	  std::cout << "No!";
	  finalCheck = false;
	  break;
	} else if (!checkSymbols(email[symbol])) {
	  std::cout << "No!";
	  finalCheck = false;
	  break;
	} else if (symbol==email.length() - 1 && !atSymbol) {
	  std::cout << "No!";
	  finalCheck = false;
	  break;
	}
  }
  if (finalCheck) {
	std::cout << "Yes!";
  }
}
int main() {
  std::string email;
  std::cout << "Input Email: ";
  std::getline(std::cin, email);
  validation(email);
  return 0;
}
