#include "pch.h"
#include "fine_function.h"
#include "connection_sql_func.h"

//
//	SQL FUNCTION DEFINITIONS
//
namespace sql_connection_func {

	//
	//	FUNCTION FOR SETTING USERNAME PASSWORD TO ESTABLISH CONNECTION TO MYSQL SERVER
	//
	String^ sql_user_pass_string()
	{
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=lovebcmm**,02";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";

		return constring;
	}
	// 
	//FUNCTION FOR FILLING STUDENT DATAGRID IN LIST OF STUDENTS PAGE
	//
	void fill_datagrid_student(System::Windows::Forms::DataGridView^ dataGridView1)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT student_id AS ID, student_name AS Name, student_mobile AS Mobile, student_email as 'E-Mail', student_no_book_stat AS 'No. of Books Borrowed' FROM library_system.student_data;", conDataBase);
		MySqlDataReader^ myReader;
		//student_id,student_name,student_mobile, student_profession, student_no_book_stat 
		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	void fill_datagrid_students_filtered(String^ str_list_detail_search_person, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT student_id AS ID, student_name AS Name, student_mobile AS Mobile, student_email as 'E-Mail', student_no_book_stat AS 'No. of Books Borrowed' FROM library_system.student_data\
		WHERE " + str_list_detail_search_person + " LIKE '%" + search_bar_text + "%';", conDataBase);
		MySqlDataReader^ myReader;

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
	//
	//FUNCTION FOR FILLING BOOK DATAGRID IN LIST OF BOOKS PAGE
	//
	void fill_datagrid_book(System::Windows::Forms::DataGridView^ dataGridView1)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id AS ID, book_name as Title, book_author AS Author, book_edition_no AS Edition, book_publisher AS Publisher, book_borrow_status AS Status FROM library_system.book_data;", conDataBase);
		MySqlDataReader^ myReader;

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	void fill_datagrid_books_filtered(String^ str_list_detail_search_book, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id AS ID, book_name as Title, book_author AS Author, book_edition_no AS Edition, book_publisher AS Publisher, book_borrow_status AS Status FROM library_system.book_data\
		WHERE " + str_list_detail_search_book + " LIKE '%" + search_bar_text + "%';", conDataBase);
		MySqlDataReader^ myReader;

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
	//
	//FUNCTION FOR FILLING BORROW HISTORY DATAGRID IN BORROW HISTORY PAGE
	//
	void fill_datagrid_borrow_history(System::Windows::Forms::DataGridView^ dataGridView1)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', student_id AS 'Borrower ID', date_issue AS 'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system.borrow_history;", conDataBase);
		MySqlDataReader^ myReader;

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	void fill_datagrid_borrow_history_filtered(String^ str_list_detail_search_order, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1)
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', student_id AS 'Borrower ID', date_issue AS 'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system.borrow_history\
		WHERE " + str_list_detail_search_order + " LIKE '%" + search_bar_text + "%';", conDataBase);
		MySqlDataReader^ myReader;

		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}


}


