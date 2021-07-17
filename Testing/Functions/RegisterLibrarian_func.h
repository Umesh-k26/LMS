#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	/// <summary>
	/// Registers new librarian with the given arguments/details
	/// </summary>
	/// <param name="username">Unique identifier for a librarian</param>
	/// <param name="password"></param>
	/// <param name="Name"></param>
	/// <param name="DOB"></param>
	/// <param name="Address"></param>
	/// <param name="Email"></param>
	/// <param name="Mobile"></param>
	/// <param name="Gender"></param>
	/// <returns>True, if Librarian registration is successful., else false</returns>
	bool RegisterLibrarian_func(String^ username, String^ password, String^ Name, \
		String^ DOB, String^ Address, String^ Email, String^ Mobile, String^ Gender);
}