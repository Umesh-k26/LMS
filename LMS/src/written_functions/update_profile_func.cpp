#include "pch.h"
#include "update_profile_func.h"
#include "connection_sql_func.h"


/// <summary>
/// This function updates details such as Profession, email, mobile number and address of the member whose ID is given as inout
/// </summary>
bool update_profile_func::update_member_profile(String^ input_id, String^ profession_input, String^ email_input, String^ mobile_input, String^ address_input)
{
	bool return_val = false;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.member_data set member_id = \
		" + input_id + ", member_profession = '" + profession_input + "', member_email='" + email_input + "', member_mobile=" + mobile_input + ", member_address = '" + address_input + "'WHERE member_id = " + input_id + ";", conDataBase);

	try {
		conDataBase->Open();
		cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Profile is updated");
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

/// <summary>
/// This function adds new copies to the database for the particular Book ID
/// </summary>
bool update_profile_func::update_book_profile(String^ input_id, int num_copies)//, String^ book_name_input, String^ book_edition_input)
{
	bool return_val = false;

	//MessageBox::Show("" + num_copies + "");

	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());

	MySqlCommand^ duplicate_book_copies_cmdDataBase = gcnew MySqlCommand("INSERT INTO library_system_db.book_data (book_name, book_author, book_publisher, book_price, book_edition_no, no_of_copies, category, copies_available)\
		SELECT  book_name, book_author, book_publisher, book_price, book_edition_no, no_of_copies, category, copies_available\
		FROM library_system_db.book_data\
		WHERE book_id = '" + input_id + "'; ", conDataBase);

	/*MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("UPDATE library_system_db.book_data SET \
				no_of_copies = no_of_copies + '" + num_copies + "', copies_available = copies_available + '" + num_copies + "'\
				WHERE book_name = '" + book_name_input + "' AND \
				book_edition_no = '" + book_edition_input + "';", conDataBase);*/

	try {
		conDataBase->Open();
		for (int i = 0; i < num_copies; i++)
		{
			duplicate_book_copies_cmdDataBase->ExecuteNonQuery();
		}
			

		//MessageBox::Show("cmdb1 executed");
		//cmdDataBase2->ExecuteNonQuery();
		//MessageBox::Show("cmdb2 executed");
		//conDataBase->Close();
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

/// <summary>
/// This function updates the password of the member by taking Password in hashed form as an input and ID of the member
/// </summary>
bool update_profile_func::change_pass_member(String^ input_id, String^ new_pass_input)
{
	bool return_val = false;
	MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
	//MySqlCommand^ change_pass_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.user_pass set member_id = " + this->member_id_txt->Text + ", user_password = "+ this->new_pass_txt->Text +" WHERE member_id = " + this->member_id_txt->Text + ";", conDataBase);
	MySqlCommand^ change_pass_cmdDataBase = gcnew MySqlCommand("UPDATE library_system_db.user_pass set member_id = ' " + input_id + " ', user_password = '" + new_pass_input + "' WHERE member_id =' " + input_id + " ';", conDataBase);
	try {
		conDataBase->Open();
		change_pass_cmdDataBase->ExecuteNonQuery();
		//MessageBox::Show("Password is updated");
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
