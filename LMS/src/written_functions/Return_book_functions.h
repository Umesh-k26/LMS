#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

namespace LMS::dbInteract {

	String^ Get_Borrow_status(int Order_Id);

	bool check_Order_Id(int Order_Id);

	String^ Get_Profession(int Member_Id);

	int Get_Member_Id(int Order_Id);

	int Get_Book_Id(int Order_Id);

	void Update_Book_data(int Book_Id);

	void Updata_Borrow_history_data(int Order_Id);

	void Update_Borrow_history_fine(int Order_Id, int fine);

	void Update_Member_data(int Member_Id);

	void Message_Return_Successfully(int Order_id, int Book_Id, int Member_Id);

}
