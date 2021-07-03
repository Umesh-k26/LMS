#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::Presenter {
	int RegisterMember_func(String^ Name, String^ DOB, String^ Address, \
		String^ EmailId, String^ MobileNo, String^ Profession, String^ Gender, String^ Password);
}