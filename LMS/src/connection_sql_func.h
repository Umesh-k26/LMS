#pragma once


namespace sql_connection_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	///FUNCTION FOR SETTING USERNAME PASSWORD TO ESTABLISH CONNECTION TO MYSQL SERVER
	String^ sql_user_pass_string();

	/// <summary>
	/// //FUNCTION FOR FILLING STUDENT DATAGRID IN LIST OF STUDENTS PAGE
	/// </summary>
	/// <param name="dataGridView1"></param>
	void fill_datagrid_member(System::Windows::Forms::DataGridView^ dataGridView1);
	void fill_datagrid_members_filtered(String^ str_list_detail_search_person, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1);

	//FUNCTION FOR FILLING BOOK DATAGRID IN LIST OF BOOKS PAGE
	void fill_datagrid_book(System::Windows::Forms::DataGridView^ dataGridView1);
	void fill_datagrid_books_filtered(String^ str_list_detail_search_book, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1);

	//FUNCTION FOR FILLING BORROW HISTORY DATAGRID IN BORROW HISTORY PAGE
	void fill_datagrid_borrow_history(System::Windows::Forms::DataGridView^ dataGridView1, bool is_librarian_input, String^ transfer_id_input);
	void fill_datagrid_borrow_history_filtered(String^ str_list_detail_search_order, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1, bool is_librarian_input, String^ transfer_id_input);
}