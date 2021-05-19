#include "pch.h"
#include "borrow_history_page.h"

namespace CppCLR_WinformsProjekt1 {


	borrow_history_page::borrow_history_page(void)
	{
		InitializeComponent();
		//fill_data_grid();
		sql_connection_func::fill_datagrid_borrow_history(dataGridView1, is_librarian, transfer_id);
		//
		//TODO: Add the constructor code here
		//
	}

	borrow_history_page::borrow_history_page(String^ input_transfer_id, bool is_librarian_input)
	{
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
		InitializeComponent();
		//fill_data_grid();
		sql_connection_func::fill_datagrid_borrow_history(dataGridView1, is_librarian, transfer_id);
		//
		//TODO: Add the constructor code here
		//
	}

	borrow_history_page::~borrow_history_page()
	{
		if (components)
		{
			delete components;
		}
	}

	void borrow_history_page::fill_data_grid() 
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

	System::Void borrow_history_page::borrow_history_page_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		this->list_detail_search_order->SelectedIndex = 0;
	}

	System::Void borrow_history_page::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{
		if (e->ColumnIndex == 0)
		{
			/*CppCLR_WinformsProjekt1::testing^ testing_f = gcnew CppCLR_WinformsProjekt1::testing;
			this->Hide();
			//testing_f->ShowDialog();
			if (testing_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
			}*/
			int row_num = e->RowIndex;
			int col_num = e->ColumnIndex + 1;
			String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();

			MessageBox::Show("Your id is " + str);
			CppCLR_WinformsProjekt1::profile_order^ profile_order_f = gcnew CppCLR_WinformsProjekt1::profile_order(str);
			this->Hide();
			if (profile_order_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
				//fill_data_grid();
				sql_connection_func::fill_datagrid_borrow_history(dataGridView1, is_librarian, transfer_id);
			}

		}
	}

	System::Void borrow_history_page::search_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ str_list_detail_search_order;
		if (this->list_detail_search_order->Text == "Order ID")
		{
			str_list_detail_search_order = "order_id";
		}
		if (String::Equals(this->list_detail_search_order->Text, "Student ID"))
		{
			str_list_detail_search_order = "student_id";
		}
		if (String::Equals(this->list_detail_search_order->Text, "Book ID"))
		{
			str_list_detail_search_order = "book_id";
		}
		/*
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		String^ constring = sql_connection_func::sql_user_pass_string();
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);
		//student_id,student_name,student_mobile, student_profession, student_no_book_stat
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT order_id AS ID, book_id AS 'Book ID', student_id AS 'Borrower ID', date_issue AS 'Issue Date', date_returned AS 'Return Date', borrow_fine AS 'Fine', borrow_status AS 'Status' FROM library_system.borrow_history\
		WHERE " + str_list_detail_search_order + " LIKE '%" + this->search_bar->Text + "%';", conDataBase);
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

		}*/
		sql_connection_func::fill_datagrid_borrow_history_filtered(str_list_detail_search_order, this->search_bar->Text, dataGridView1, is_librarian, transfer_id);
	}

	System::Void borrow_history_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->search_bar->Text = "";
		search_button_Click(sender, e);
	}

	System::Void borrow_history_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
}

