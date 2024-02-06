#pragma once
#include<fstream> 
#include "clsScreen.h"
#include "Global.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include "clsDate.h"
#include"clsutil.h"
class clsLoign : protected clsScreen
{
	
	static bool _Login() {
		short count = 0;
		string username, password;
		bool login = false;
		do
		{

			if (login)
			{
				count++;
				cout << "Re Enter User - password " << "You Have " << (3 - count) << "Tries \n";
			}
			if (count == 3)
			{
				cout << "System locked ";
				return false;
			}




			cout << "Enter UserName : ";
			username = clsInputValidate::ReadString();
			cout << "Enter Password : ";
			password = clsInputValidate::ReadString();
	
			current = clsUser::Find(username,password);
			login = current.IsEmpty();//checl if global is empty means false and so on 
		} while (login);

		current.RegisterLogIn();
		clsMainScreen::ShowMenu();

		return true;




	}



public:
	static bool show() {
		system("cls");


		_DrawHeader("\t\tLogin screen");

		return _Login();




	}



};

