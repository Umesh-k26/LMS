#include "pch.h"
#include "delete_profile_func.h"
#include "connection_sql_func.h"

/// <summary>
/// This function simply deactivates the membership of a member instead of completetly removing from the database
/// </summary>
bool delete_profile_func::delete_member_profile(String^ input_id)
{
	bool return_value = false;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system_db.member_data WHERE member_id = " + this->member_id_txt->Text + ";", conDataBase);
	MySqlCommand^ update_member_stat_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.member_data set member_id = " + input_id + ", membership_stat = 'DEACTIVATED' WHERE member_id = " + input_id + ";", conDataBase);
	MySqlCommand^ delete_user_pass_cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system_db.user_pass WHERE member_id = " + input_id + ";", conDataBase);

	try {
		conDataBase->Open();
		update_member_stat_cmdDataBase->ExecuteNonQuery();
		delete_user_pass_cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Profile is deleted");
		return_value = true;
	}
	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);
		return_value = false;
	}
	conDataBase->Close();
	/*this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();*/
	return return_value;
}

/// <summary>
/// This function simply changes the status of the book as lost instead of completetly removing from the database
/// </summary>
bool delete_profile_func::delete_book_profile(String^ input_id, String^ book_name_input, String^ book_author_input, String^ book_pub_input, String^ book_edition_input, String^ borrow_status_input, String^ final_fine)
{
	bool return_val = false;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlCommand^ update_lost_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.book_data SET book_borrow_status = 'LOST' WHERE book_id = " + input_id + ";", conDataBase);
	//
	//	STILL NEED TO ADD FUNCTION TO REMOVE THE NUMBER OF COPIES
	//
	MySqlCommand^ update_no_copies_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.book_data set copies_available = copies_available - 1, no_of_copies= no_of_copies-1 WHERE \
								book_name = '" + book_name_input + "'\
								AND book_author = '" + book_author_input + "'\
								AND book_publisher = '" + book_pub_input + "'\
								AND book_edition_no = " + book_edition_input + ";", conDataBase);
	MySqlCommand^ update_last_borrow_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.borrow_history SET borrow_fine = '"+ final_fine+"', date_returned = CURDATE(), borrow_status = 'LOST' WHERE order_id = (SELECT order_id FROM (SELECT * FROM library_system_db.borrow_history WHERE book_id = '"+ input_id+ "' ORDER BY order_id DESC Limit 1) as X);", conDataBase);
	try {
		conDataBase->Open();
		update_lost_cmdDataBase->ExecuteNonQuery();
		//update_no_copies_cmdDataBase->ExecuteNonQuery();
		if (borrow_status_input == "BORROWED")
		{
			update_last_borrow_cmdDataBase->ExecuteNonQuery();
		}
		//MessageBox::Show("Profile is deleted");
		return_val = true;
	}
	catch (Exception^ ex)
	{
		//MessageBox::Show(ex->Message);
		return_val = false;
	}
	conDataBase->Close();
	return return_val;
}
