#include <iostream>
#include "string"
bool check(char symbol) {
  if (symbol=='!' || symbol >= 35 && symbol <= 39 || symbol >= 42 && symbol <= 43 || symbol >= 45 && symbol <= 57
	  || symbol >= 65 && symbol <= 90 || symbol >= 94 && symbol <= 126) {
	return true;
  } else {
	return false;
  }
}
int main() {
  std::string email;
  std::cout << "Input Email: ";
  std::getline(std::cin , email);
  bool atSymbol = false;
  for (int symbol = 0, count = 1; symbol < email.length(); symbol++, count++) {
	if (email[symbol]=='@' && atSymbol==false) {
	  if (count > 0 && count <= 64) {
		count = 0;
	  } else {
		std::cout << "No!" << std::endl;
		return 1;
	  }
	  atSymbol = true;
	} else if (email[symbol]=='@' && atSymbol==true) {
	  std::cout << "No!" << std::endl;
	  return 1;
	} else if (symbol==email.length() - 1 && count > 63) {
	  std::cout << "No!" << std::endl;
	  return 1;
	} else if (email[symbol]=='.' && symbol!=0 && email[symbol- 1] =='.') {
	  std::cout << "No!" << std::endl;
	  return 1;
	} else if (!check(email[symbol])) {
	  std::cout << "No!" << std::endl;
	  return 1;
	}
  }
  if(atSymbol) {
	std::cout << "Yes!";
  }else{
	std::cout << "No!" << std::endl;
	return 1;
  }
  return 0;
}
