#pragma once
#include "pch.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {
	int AddBook_func(String^ Name, String^ Author, String^ Publisher, \
		String^ Category, const int EditionNo, const int NoOfCopies, const int Price);
}