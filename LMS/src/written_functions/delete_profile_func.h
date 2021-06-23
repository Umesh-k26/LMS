#pragma once

namespace delete_profile_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	bool delete_member_profile(String^ input_id);

	bool delete_book_profile(String^ input_id, String^ book_name_input, String^ book_author_input, String^ book_pub_input, String^ book_edition_input);

}