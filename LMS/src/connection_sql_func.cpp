#include "pch.h"
#include "fine_function.h"
#include "connection_sql_func.h"

///	SQL function definitions to fill datagrids and to connect to database

namespace sql_connection_func {

	//
	//	FUNCTION FOR SETTING USERNAME PASSWORD TO ESTABLISH CONNECTION TO MYSQL SERVER
	//
	String^ sql_user_pass_string()
	{
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=lovebcmm**,02";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234; SslMode=Required";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		return constring;
	}

	// 
	//FUNCTION FOR FILLING MEMBER DATAGRID IN LIST OF MEMBERS PAGE
	//

	/// <summary>
	/// Void function to fill member datagrid
	/// </summary>
	/// <param name="dataGridView"></param>
	void fill_datagrid_member(System::Windows::Forms::DataGridView^ dataGridView)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT member_id AS ID, member_name AS Name, member_mobile AS Mobile, member_email as 'E-Mail', member_no_book_stat AS 'No. of Books Borrowed' FROM library_system_db.member_data WHERE membership_stat = 'ACTIVATED';", conDataBase);

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		conDataBase->Close();
	}

	/// <summary>
	/// void function to fill filtered member datagrid
	/// </summary>
	void fill_datagrid_members_filtered(String^ str_list_detail_search_person, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT member_id AS ID, member_name AS Name, member_mobile AS Mobile, member_email as 'E-Mail', member_no_book_stat AS 'No. of Books Borrowed' FROM library_system_db.member_data\
		WHERE " + str_list_detail_search_person + " LIKE '%" + search_bar_text + "%' AND membership_stat = 'ACTIVATED';", conDataBase);

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		conDataBase->Close();
	}
	//
	//FUNCTION FOR FILLING BOOK DATAGRID IN LIST OF BOOKS PAGE
	//

	/// <summary>
	/// void function to fill book datagrid
	/// </summary>
	void fill_datagrid_book(System::Windows::Forms::DataGridView^ dataGridView)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id AS ID, book_name as Title, book_author AS Author, book_edition_no AS Edition, book_publisher AS Publisher, book_borrow_status AS Status FROM library_system_db.book_data WHERE NOT book_borrow_status = 'LOST';", conDataBase);

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		conDataBase->Close();
	}

	/// <summary>
	/// void function to fill filtered book datagrid
	/// </summary>
	void fill_datagrid_books_filtered(String^ str_list_detail_search_book, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id AS ID, book_name as Title, book_author AS Author, book_edition_no AS Edition, book_publisher AS Publisher, book_borrow_status AS Status FROM library_system_db.book_data\
		WHERE " + str_list_detail_search_book + " LIKE '%" + search_bar_text + "%' AND NOT book_borrow_status = 'LOST';", conDataBase);

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		conDataBase->Close();
	}
	//
	//FUNCTION FOR FILLING BORROW HISTORY DATAGRID IN BORROW HISTORY PAGE
	//

	/// <summary>
	/// void function to fill borrow history datagrid
	/// </summary>
	void fill_datagrid_borrow_history(System::Windows::Forms::DataGridView^ dataGridView, bool is_librarian_input, String^ transfer_id_input)
	{
		if (is_librarian_input == true)
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', member_id AS 'Member ID', date_issue AS 'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system_db.borrow_history;", conDataBase);

			try {
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^ bSource = gcnew BindingSource();
				bSource->DataSource = dbdataset;
				dataGridView->DataSource = bSource;
				sda->Update(dbdataset);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);

			}
			conDataBase->Close();
		}

		else
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', member_id AS 'Member ID', date_issue AS \
			'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system_db.borrow_history WHERE member_id = " + transfer_id_input + ";", conDataBase);

			try {
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^ bSource = gcnew BindingSource();
				bSource->DataSource = dbdataset;
				dataGridView->DataSource = bSource;
				sda->Update(dbdataset);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);

			}
			conDataBase->Close();
		}


	}

	/// <summary>
	/// void function to fill filtered borrow history datagrid
	/// </summary>
	void fill_datagrid_borrow_history_filtered(String^ str_list_detail_search_order, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView, bool is_librarian_input, String^ transfer_id_input)
	{
		if (is_librarian_input == true)
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', member_id AS 'Member ID', date_issue AS \
			'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system_db.borrow_history\
			WHERE " + str_list_detail_search_order + " LIKE '%" + search_bar_text + "%';", conDataBase);

			try {
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^ bSource = gcnew BindingSource();
				bSource->DataSource = dbdataset;
				dataGridView->DataSource = bSource;
				sda->Update(dbdataset);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
			conDataBase->Close();
		}
		else
		{
			MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', member_id AS 'Member ID', date_issue AS \
			'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system_db.borrow_history\
			WHERE " + str_list_detail_search_order + " LIKE '%" + search_bar_text + "%' AND member_id = " + transfer_id_input + ";", conDataBase);

			try {
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbdataset = gcnew DataTable();
				sda->Fill(dbdataset);
				BindingSource^ bSource = gcnew BindingSource();
				bSource->DataSource = dbdataset;
				dataGridView->DataSource = bSource;
				sda->Update(dbdataset);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
			conDataBase->Close();
		}
	}

	/// <summary>
	/// This function hashes the password of the user and also salts it with ID of the user before being hashed
	/// </summary>
	String^ password_hasher(String^ input_id, String^ input_pass)
	{
		String^ final_password_for_hash = input_pass + input_id;
		array<Byte>^ byte_array_password = System::Text::Encoding::ASCII->GetBytes(final_password_for_hash);
		System::Security::Cryptography::MD5CryptoServiceProvider^ md5_hash_gen = gcnew System::Security::Cryptography::MD5CryptoServiceProvider();
		array<Byte>^ byte_array_hash = md5_hash_gen->ComputeHash(byte_array_password);
		return BitConverter::ToString(byte_array_hash);
		
	}

	


}


