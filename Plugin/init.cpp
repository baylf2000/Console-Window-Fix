#pragma once

#include "init.h"
#include <API/ARK/Ark.h>
#include <Logger/Logger.h>
#include <Tools.h>


void Fix_Window()
{
	HANDLE hInput;
	DWORD prev_mode;
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
	
	Log::GetLog()->info("Quick Edit Mode has been disabled for this window to prevent certain \"Hang Detection\" crashes.");
	
	return;

}


BOOL Load()
{
	Log::Get().Init("Console Window Fix");
	
	Fix_Window();

	return TRUE;
}

BOOL Unload()
{
	return TRUE;
}
