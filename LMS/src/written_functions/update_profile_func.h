#pragma once

namespace update_profile_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	bool update_member_profile(String^ input_id, String^ profession_input, String^ email_input, String^ mobile_input, String^ address_input);
	
	//bool update_book_profile(String^ s);

}