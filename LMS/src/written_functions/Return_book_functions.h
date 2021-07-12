#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;


namespace LMS::dbInteract {


	/// <summary>
	/// Function to get Borrow status of the book Borrowed with given Order Id
	/// </summary>
	/// <param name="Order_Id"></param>
	/// <returns></returns>
	String^ Get_Borrow_status(int Order_Id);

	/// <summary>
	/// Function to check whether that Order exists with given Order Id in Borrow History Table
	/// </summary>
	/// <param name="Order_Id"></param>
	/// <returns></returns>
	bool check_Order_Id(int Order_Id);

	/// <summary>
	/// Function to get the profession of the Member who borrowed book with the given Order Id
	/// </summary>
	/// <param name="Member_Id"></param>
	/// <returns></returns>
	String^ Get_Profession(int Member_Id);

	/// <summary>
	/// Function to get the Member Id of the member who borrowed book with the given Order Id
	/// </summary>
	/// <param name="Order_Id"></param>
	/// <returns></returns>
	int Get_Member_Id(int Order_Id);

	/// <summary>
	/// Function to get the Book Id of the Book which was Borrowed with the given Order Id
	/// </summary>
	/// <param name="Order_Id"></param>
	/// <returns></returns>
	int Get_Book_Id(int Order_Id);

	/// <summary>
	/// Function to Update Book data table
	/// </summary>
	/// <param name="Book_Id"></param>
	void Update_Book_data(int Book_Id);

	/// <summary>
	/// Function to Update Borrow satus and Return Date in Borrow History table 
	/// </summary>
	/// <param name="Order_Id"></param>
	void Updata_Borrow_history_data(int Order_Id);

	/// <summary>
	/// Function to Update Fine in Borrow History table
	/// </summary>
	/// <param name="Order_Id"></param>
	/// <param name="fine"></param>
	void Update_Borrow_history_fine(int Order_Id, int fine);

	/// <summary>
	/// Function to Update Member data table
	/// </summary>
	/// <param name="Member_Id"></param>
	void Update_Member_data(int Member_Id);

	/// <summary>
	///  Function to Show Message that Book is Returned Successfully with given Order Id 
	/// </summary>
	/// <param name="Order_id"></param>
	/// <param name="Book_Id"></param>
	/// <param name="Member_Id"></param>
	void Message_Return_Successfully(int Order_id, int Book_Id, int Member_Id);

}
