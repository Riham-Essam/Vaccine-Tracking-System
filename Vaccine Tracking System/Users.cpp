#include "Users.h"
#include "Linkedlist.cpp"
#include <assert.h>
#include <iostream>

using namespace std;

LinkedList<Users> list;
LinkedList<Users> Waitinglist;
Users user;
string Admin_name1 = "zain11@gmail.com";
string Admin_pass1 = "123456";
string Admin_name2 = "mohamed22@gmail.com";
string Admin_pass2 = "101010";

Users::Users(string user_name, string user_id, string user_pass, string user_gender, int user_age, string user_country, string user_govern, string user_vaccinted, string user_num_of_dose)
{
	this->full_name = user_name;
	this->id = user_id;
	this->password = user_pass;
	this->gender = user_gender;
	this->age = user_age;
	this->country = user_country;
	this->governorate = user_govern;
	this->vaccinated = user_vaccinted;
	this->num_of_dose = user_num_of_dose;
}

Users::Users() {}

Users::Users(string user_id, string user_pass)
{
	this->id = user_id;
	this->password = user_pass;
}

Users::Users(string user_id, string user_name, string vaccinated)
{
	this->id = user_id;
	this->full_name = user_name;
	this->vaccinated = vaccinated;
}


void Users::SignUp()
{
	cout << "Enter your Full name" << endl;
	cin >> full_name;
	cout << "Enter your id" << endl;
	cin >> id;
	for (int i = 0; i < list.Length(); ++i)
	{
		Users user = list.At(i);
		while (true) {
			if (id == user.id)
			{
				cout << "this id is exist please enter another id " << endl;
				cin >> id;
			}
			else {
				break;
			}
		}
		
	}
	cout << "Enter your password" << endl;
	cin >> password;

	while (true) {
		cout << "Enter your Gender" << endl;
		cin >> gender;
		if (gender == "m" || gender == "f")
			break;
		cout << "Incorrect format!" << endl;

	}

	cout << "Enter your Age" << endl;
	cin >> age;
	cout << "Enter your Country" << endl;
	cin >> country;
	cout << "Enter your Governorate" << endl;
	cin >> governorate;
	cout << "Enter your Vaccinated" << endl;
	cin >> vaccinated;
	if (vaccinated == "y")
	{
		cout << "do you take one dose or two" << endl;
		cin >> num_of_dose;
	}
	else {
		num_of_dose = "zero";
		Users users(id, full_name, vaccinated);
		Waitinglist.Append(users);
	}

	Users u(full_name, id, password, gender, age, country, governorate, vaccinated, num_of_dose);

	list.Append(u);

}

string Users::Login(string user_id, string user_pass)
{
	int checkUser = 0;
	for (int i = 0; i < list.Length(); ++i) {

		Users user = list.At(i);
		if (user_pass == user.password && user_id == user.id)
		{
			cout << "correct" << endl;

			checkUser = 1;
			break;

		}
		else {

			checkUser = 0;
		}
	}

	if (checkUser == 1)
	{
		return user_id;
	}
	else {
		cout << "incorrect \n";
		cout << "Enter your id \n";
		cin >> id;
		cout << "Enter your password \n";
		cin >> password;
		user.Login(id, password);
	}
	return id;
}

void Users::DisplayInfo(string id)
{
	for (int i = 0; i < list.Length(); ++i)
	{
		Users user = list.At(i);
		if (id == user.id)
		{
			cout << "full name is :" << user.full_name << endl;
			cout << "Id is :" << user.id << endl;
			cout << "Passowrd is : " << user.password << endl;
			cout << "Gender is :" << user.gender << endl;
			cout << "Age is : " << user.age << endl;
			cout << "Country is : " << user.country << endl;
			cout << "Governorate is : " << user.governorate << endl;
			cout << "Vaccinated is : " << user.vaccinated << endl;
			cout << "Num_of_dose is : " << user.num_of_dose << endl;
			break;
		}
	}
}


void Users::Delete_user_record(string user_id) {
	for (int i = 0; i < list.Length(); ++i)
	{
		Users user = list.At(i);
		if (user_id == user.id)
		{
			list.DeleteAt(i);
			cout << "User is deleted" << endl;
		}
	}
	for (int i = 0; i < Waitinglist.Length(); ++i)
	{
		Users user = Waitinglist.At(i);
		if (user_id == user.id)
		{
			Waitinglist.DeleteAt(i);
		}
	}
}


void Users::Login_Admin(string Admin_name, string Admine_pass)
{

	if (Admin_name == Admin_name1 && Admine_pass == Admin_pass1) {
		cout << "correct!! \n";
	}
	else if (Admin_name == Admin_name2 && Admine_pass == Admin_pass2)
	{
		cout << "correct!! \n";
	}
	else {
		cout << "incorrect \n";
		cout << "Enter your username \n";
		cin >> Admin_name;
		cout << "Enter your password \n";
		cin >> Admine_pass;
		user.Login_Admin(Admin_name, Admine_pass);
	}

}

void Users::UpdateInfo(string id) {

	int option;
	for (int i = 0; i < list.Length(); ++i) {
		Users user = list.At(i);
		if (id == user.id) {
			cout << "Please choose your option:(1/password - 2/Country - 3/Governorate)" << endl;
			cout << "Enter your option" << endl;
			cin >> option;

			switch (option)
			{

			case 1: {
				string  new_pass;
				cout << "please enter new password" << endl;
				cin >> new_pass;
				user.password = new_pass;
				cout << "Your password is updated" << endl;
				Users u(user.full_name, id, user.password, user.gender, user.age, user.country, user.governorate, user.vaccinated, user.num_of_dose);
				list.DeleteAt(i);
				list.InsertAt(i, u);
				break;
			}

			case 2: {
				string  new_country;
				cout << "please enter new country" << endl;
				cin >> new_country;
				user.country = new_country;
				cout << "Your country is updated" << endl;
				Users u(user.full_name, id, user.password, user.gender, user.age, user.country, user.governorate, user.vaccinated, user.num_of_dose);
				list.DeleteAt(i);
				list.InsertAt(i, u);
				break;

			}
			case 3: {
				string  new_governorate;
				cout << "please enter new country" << endl;
				cin >> new_governorate;
				user.governorate = new_governorate;
				cout << "Your governorate is updated" << endl;
				Users u(user.full_name, id, user.password, user.gender, user.age, user.country, user.governorate, user.vaccinated, user.num_of_dose);
				list.DeleteAt(i);
				list.InsertAt(i, u);
				break;
			}

			}
		}

	}
}


void Users::DisplayAllUsers() {
	for (int i = 0; i < list.Length(); ++i) {
		Users user = list.At(i);
		cout << "full name is :" << user.full_name << endl;
		cout << "Id is :" << user.id << endl;
		cout << "Passowrd is : " << user.password << endl;
		cout << "Gender is :" << user.gender << endl;
		cout << "Age is : " << user.age << endl;
		cout << "Country is : " << user.country << endl;
		cout << "Governorate is : " << user.governorate << endl;
		cout << "Vaccinated is : " << user.vaccinated << endl;
		cout << "Number of doses is : " << user.num_of_dose << endl;
		cout << "******************************" << endl;
	}

	cout << "Waiting list" << endl;
	for (int i = 0; i < Waitinglist.Length(); i++) {
		Users user = Waitinglist.At(i);
		cout << "Name is :" << user.full_name << endl;
		cout << "Id is :" << user.id << endl;
		cout << "******************************" << endl;

	}
}

void Users::DeleteAllUsers() {
	while (list.Length() != 0) {
		for (int i = 0; i < list.Length(); ++i) {
			list.DeleteAt(i);
		}
	}
	while (Waitinglist.Length() != 0) {
		for (int i = 0; i < Waitinglist.Length(); ++i) {
			Waitinglist.DeleteAt(i);
		}
	}
	cout << "All users are deleted" << endl;
}

void Users::calcAllpeople() //% of egyptains whether vac or not 
{
	float counteregy = 0.0;
	for (int i = 0; i < list.Length(); ++i)
	{
		user = list.At(i);
		if (user.country == "Egypt")
		{
			counteregy++;
		}
	}
	float percentage = (counteregy / list.Length()) * 100;
	cout << "percentage of all people = " << percentage << " %" << endl;
}


void Users::calcUnvacinated()
{

	float percentage = ((float)Waitinglist.Length() / list.Length()) * 100;
	cout << "percentage of unvaccinated people = " << percentage << " %" << endl;
}


void Users::Vac_with_oneDose()
{
	float countervacOne = 0.0;
	float  counterva = 0.0;
	for (int i = 0; i < list.Length(); ++i)
	{
		user = list.At(i);
		if (user.vaccinated == "y")
		{
			counterva++;
			if (user.num_of_dose == "one")
			{
				countervacOne++;
			}
		}
	}
	float percentage = (countervacOne / counterva) * 100;
	cout << "percentage of vaccinated people = " << percentage << " %" << endl;
}


void Users::Vac_with_twoDoses()
{
	float countervacTWO = 0.0;
	float  counterva = 0.0;
	for (int i = 0; i < list.Length(); ++i)
	{
		user = list.At(i);
		if (user.vaccinated == "y")
		{
			counterva++;
			if (user.num_of_dose == "two")
				countervacTWO++;
		}
	}
	float percentage = (countervacTWO / counterva) * 100;
	cout << "percentage of vaccinated people = " << percentage << " %" << endl;
}

void Users::calcVac_age()
{
	float counter = 0.0;
	for (int i = 0; i < list.Length(); i++)
	{
		user = list.At(i);
		if (user.age >= 18 && user.age <= 30 && user.vaccinated == "y")
		{
			counter++;
		}
	}
	float percentage = (counter / list.Length()) * 100;
	cout << "percentage of(18 -30) years old = " << percentage << " % " << endl;
}

void Users::calcVac_female()
{
	float counterF = 0.0;
	float counterV = 0.0;
	for (int i = 0; i < list.Length(); ++i)
	{
		user = list.At(i);
		if (user.gender == "f") {
			counterF++;
			if (user.vaccinated == "y")
				counterV++;
		}
	}
	float percentage = (counterV / counterF) * 100;
	cout << "percentage of vaccinated females = " << percentage << " % " << endl;

}

void Users::calcunVac_female()
{
	float counterF = 0.0;
	float counterunV = 0.0;
	for (int i = 0; i < list.Length(); ++i)
	{
		user = list.At(i);
		if (user.gender == "f") {
			counterF++;
			if (user.vaccinated == "n")
				counterunV++;
		}
	}
	float percentage = (counterunV / counterF) * 100;
	cout << "percentage of unvaccinated females = " << percentage << " % " << endl;
}

void Users::calcVac_country()
{
	float counter = 0.0;
	for (int i = 0; i < list.Length(); ++i)
	{
		user = list.At(i);
		if (user.country != "Egypt" && user.vaccinated == "y")
			counter++;
	}
	float percentage = (counter / list.Length()) * 100;
	cout << "percentage of vaccinated people out of Egypt  = " << percentage << " % " << endl;
}

Users::~Users(void) {

}