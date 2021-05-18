#pragma once


namespace connection_to_librarian_db {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	bool is_librarian(String^ username_input, String^ password_input);

	}