#pragma once

namespace Borrow_book_functions {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;



	bool Check_book(String^ Book_Id);

	bool Check_Memeber(String^ Member_Id);

	void Update_Book_data(String^ Book_Id);

	void Update_member_data(String^ Member_id);

	void Take_New_order(String^ Book_Id, String^ Member_Id);

	void Message_Borrowed_succesfully(String^ Book_Id, String^ Member_Id);

	void Check_copies_available(String^ Book_Id);

}