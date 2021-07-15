#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {
	bool RegisterLibrarian_func(String^ username, String^ password, String^ Name, \
		String^ DOB, String^ Address, String^ Email, String^ Mobile, String^ Gender);
}