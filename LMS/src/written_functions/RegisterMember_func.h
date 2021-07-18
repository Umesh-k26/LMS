#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	/// <summary>
	/// Registers Student/Faculty/Alumini with given arugments/details
	/// </summary>
	/// <param name="Name"></param>
	/// <param name="DOB"></param>
	/// <param name="Address"></param>
	/// <param name="EmailId"></param>
	/// <param name="MobileNo"></param>
	/// <param name="Profession"></param>
	/// <param name="Gender"></param>
	/// <param name="Password"></param>
	/// <returns>True if registration is successful, else false</returns>
	bool RegisterMember_func(int& memberId, String^ Name, String^ DOB, String^ Address, \
		String^ EmailId, String^ MobileNo, String^ Profession, String^ Gender, String^ Password);
}