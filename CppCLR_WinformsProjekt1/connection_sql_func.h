#pragma once


namespace sql_connection_func {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	String^ sql_user_pass_string();
	void fill_datagrid_student(System::Windows::Forms::DataGridView^ dataGridView1);
	void fill_datagrid_students_filtered(String^ str_list_detail_search_person, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1);

	void fill_datagrid_book(System::Windows::Forms::DataGridView^ dataGridView1);
	void fill_datagrid_books_filtered(String^ str_list_detail_search_book, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1);

	void fill_datagrid_borrow_history(System::Windows::Forms::DataGridView^ dataGridView1);
	void fill_datagrid_borrow_history_filtered(String^ str_list_detail_search_order, String^ search_bar_text, System::Windows::Forms::DataGridView^ dataGridView1);
}