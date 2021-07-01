#pragma once

namespace Return_book_functions {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	String^ Get_Borrow_status(String^ Order_Id);

	bool check_Order_Id(String^ Order_Id);

	String^ Get_Profession(int Member_Id);

	int Get_Member_Id(String^ Order_Id);

	int Get_Book_Id(String^ Order_Id);

	void Update_Book_data(int Book_Id);

	void Updata_Borrow_history_data(String^ Order_Id);

	void Update_Borrow_history_fine(String^ Order_Id, int fine);

	void Update_Member_data(int Member_Id);

	void Message_Return_Successfully(String^ Order_id, int Book_Id, int Member_Id);

}
