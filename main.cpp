#include <iostream>
#include "string"

bool checkSymbols(char symbol) {
  return (symbol=='!' || (symbol >= '#' && symbol <= 39) || (symbol >= '*' && symbol <= '+')
	  || (symbol >= '-' && symbol <= '9') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '^' && symbol <= '~'));
}

bool validation(std::string email) {
  bool atSymbol = false;
  for (int i = 0, count = 0; i < email.length(); i++, count++) {
	if (email[i]=='@' && !atSymbol) {
	  if (count > 0 && count <= 64) {
		if (i==email.length() - 1) {
		  return false;
		} else {
		  count = 0;
		}
	  } else {
		return false;
	  }
	  atSymbol = true;
	} else if (email[i]=='@' && atSymbol) {
	  return false;
	} else if (i==email.length() - 1 && count > 63) {
	  return false;
	} else if (email[i]=='.' && i!=0 && email[i - 1]=='.') {
	  return false;
	} else if (!checkSymbols(email[i])) {
	  return false;
	} else if (i==email.length() - 1 && !atSymbol) {
	  return false;
	}
  }
  return true;
}

int main() {
  std::string email;
  std::cout << "Input Email: ";
  std::getline(std::cin, email);
  if (validation(email)) {
	std::cout << "Yes!";
  } else {
	std::cout << "No!";
  }
  return 0;
}
