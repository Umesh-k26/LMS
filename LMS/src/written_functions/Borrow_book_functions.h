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
	/// Function to Check whether Book exists and it is available, with given Book Id in Book data table
	/// </summary>
	/// <param name="Book_Id"></param>
	/// <returns></returns>
	bool Check_book(String^ Book_Id);

	/// <summary>
	/// Function to Check whether Member exists with Active Membership status ,with given Member Id in Member data table
	/// </summary>
	/// <param name="Member_Id"></param>
	/// <returns></returns>
	bool Check_Memeber(String^ Member_Id);

	/// <summary>
	/// Function to Update Book data , when Book is Borrowed succesfully
	/// </summary>
	/// <param name="Book_Id"></param>
	void Update_Book_data(String^ Book_Id);

	/// <summary>
	/// Function to Update Member data ,when Book is Borrowed succesfully
	/// </summary>
	/// <param name="Member_id"></param>
	void Update_member_data(String^ Member_id);

	/// <summary>
	/// Function to UPdate Borrow History ,When Book is Borrowed succesfully
	/// </summary>
	/// <param name="Book_Id"></param>
	/// <param name="Member_Id"></param>
	void Take_New_order(String^ Book_Id, String^ Member_Id);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="Book_Id"></param>
	/// <param name="Member_Id"></param>
	void Message_Borrowed_succesfully(String^ Book_Id, String^ Member_Id);

	/// <summary>
	/// Function to check other copies of a book , when specific copy of the book is not available
	/// </summary>
	/// <param name="Book_Id"></param>
	void Check_copies_available(String^ Book_Id);

}