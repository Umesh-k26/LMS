#pragma once

//
//	FINE FUNCTION HEADER
//
namespace extra_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	int calculate_fine(int order_id_input, int student_id_input, String^ borrow_proffesion_input);

}