#include <string>
#include <iostream>
#include <algorithm>
#include "trash.hpp"

std::string format(std::string str)
{
	if(str.length() > 10)
	{
		return (str.substr(0, 9) + "." );
	}
	else
	{
		while(str.length() < 10)
		{
			str += " ";
		}
	}
		return (str);
}

void	show(Phonebook *book,int index)
{
	std::cout << "First name :" << book[index].Firstname << std::endl;
	std::cout << "Last name :" << book[index].Lastname << std::endl;
	std::cout << "Nickname :" << book[index].Nickname << std::endl;
	std::cout << "Login :" << book[index].Login << std::endl;
	std::cout << "Postal address :" << book[index].Postaladdress << std::endl;
	std::cout << "Address email :" << book[index].Adressmail << std::endl;
	std::cout << "Phone number :" << book[index].Phonenumber << std::endl;
	std::cout << "Birthday date :" << book[index].Birthdaydate << std::endl;
	std::cout << "Favorite meal :" << book[index].Favoritemeal << std::endl;
	std::cout << "Underwear Color :" << book[index].Underwearcolor << std::endl;
	std::cout << "Darkest secret :" << book[index].Darkestsecret << std::endl;
}


void	search(Phonebook *book,int index)
{
	if(index == 0)
	{
		std::cout << "NO DATA" << std::endl;
	}
	else
	{
		std::cout << "**********************************************************" << std::endl;
		for (int i = 0;i < index;i++)
		{
			std::cout << "|" << i ;
			std::cout << "|" << format(book[i].Firstname) ;
			std::cout << "|" << format(book[i].Lastname);
			std::cout << "|" << format(book[i].Nickname) << "|" << std::endl ;
		}
		int temp;
		std::cout << "Type an index to fetch all infos" << std::endl;
		std::cin >> temp;
		if(temp < index){
			show( book, temp);
		}
		else
			std::cout << "Nope , index invalid" << std::endl;
	}
}

void	add(Phonebook *book,int index)
{
	std::cout << "Enter first name :" << std::endl;
	std::cin >> book[index].Firstname;
	std::cout << "Enter last name :" << std::endl;
	std::cin >> book[index].Lastname;
	std::cout << "Enter nickname :" << std::endl;
	std::cin >> book[index].Nickname;
	std::cout << "Enter login :" << std::endl;
	std::cin >> book[index].Login;
	std::cout << "Enter postal address :" << std::endl;
	std::cin >> book[index].Postaladdress;
	std::cout << "Enter address email :" << std::endl;
	std::cin >> book[index].Adressmail;
	std::cout << "Enter phone number :" << std::endl;
	std::cin >> book[index].Phonenumber;
	std::cout << "Enter birthday date :" << std::endl;
	std::cin >> book[index].Birthdaydate;
	std::cout << "Enter favorite meal :" << std::endl;
	std::cin >> book[index].Favoritemeal;
	std::cout << "Enter underwear color :" << std::endl;
	std::cin >> book[index].Underwearcolor;
	std::cout << "Enter darkest secret :" << std::endl;
	std::cin >> book[index].Darkestsecret;
}


int main()
{
	Phonebook *book;
	int	index  = 0;
	book = new Phonebook[8];

	std::cout << "HELLO , WELCOME TO A USELESS PHONEBOOK !!!" << std::endl;
	while(1)
	{
		std::cout << "HOW CAN I HELP YOU ?" << std::endl; 
		std::string s;
		std::cin >> s;
		if(s == "EXIT"){ delete book;return (0);}
		else if(s == "ADD"){
			if(index < 8)
				add(book,index++ );
			else
				std::cout << "Ouch error,can't add anymore !" << std::endl;
		}
		else if(s == "SEARCH"){search(book,index);  }
		else{std::cout << "Nope , try again" << std::endl;  }
	}
}