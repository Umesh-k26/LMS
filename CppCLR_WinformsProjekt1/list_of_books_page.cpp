#include "pch.h"
#include "list_of_books_page.h"

namespace CppCLR_WinformsProjekt1 {


	list_of_books_page::list_of_books_page(void)
	{
		InitializeComponent();
		//fill_data_grid();
		sql_connection_func::fill_datagrid_book(dataGridView1);
	}

	list_of_books_page::list_of_books_page(String^ input_transfer_id, bool is_librarian_input)
	{
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
		InitializeComponent();
		//fill_data_grid();
		sql_connection_func::fill_datagrid_book(dataGridView1);
	}

	list_of_books_page::~list_of_books_page()
	{
		if (components)
		{
			delete components;
		}
	}

	void list_of_books_page::fill_data_grid()
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id AS ID, book_name as Title, book_author AS Author, book_edition_no AS Edition, book_publisher AS Publisher, book_borrow_status AS Status FROM library_system.book_data;", conDataBase);

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
		conDataBase->Close();
	}

	System::Void list_of_books_page::list_of_books_page_Load(System::Object^ sender, System::EventArgs^ e)
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		this->list_detail_search_book->SelectedIndex = 1;
	}

	System::Void list_of_books_page::back_button_book_list_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
		/*CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
		this->Hide();
		f2->ShowDialog();*/
	}

	System::Void list_of_books_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Application::Exit();
	}

	System::Void list_of_books_page::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) 
	{
		//
		// Copy code from list_of_students to open a different form and also try to use different DialogBox::OK
		//
		//
		if (e->ColumnIndex == 0)
		{
			int row_num = e->RowIndex;
			int col_num = e->ColumnIndex + 1;
			String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();
			MessageBox::Show("Your id is " + str);
			CppCLR_WinformsProjekt1::profile_book^ profile_book_f = gcnew CppCLR_WinformsProjekt1::profile_book(str, is_librarian);
			this->Hide();
			//testing_f->ShowDialog();

			if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
				sql_connection_func::fill_datagrid_book(dataGridView1);
			}

		}

	}

	System::Void list_of_books_page::search_button_book_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ str_list_detail_search_book;
		if (this->list_detail_search_book->Text == "Title")
		{
			str_list_detail_search_book = "book_name";
		}
		if (String::Equals(this->list_detail_search_book->Text, "ID"))
		{
			str_list_detail_search_book = "book_id";
		}
		if (String::Equals(this->list_detail_search_book->Text, "Author"))
		{
			str_list_detail_search_book = "book_author";
		}
		if (String::Equals(this->list_detail_search_book->Text, "Edition No."))
		{
			str_list_detail_search_book = "book_edition_no";
		}

		sql_connection_func::fill_datagrid_books_filtered(str_list_detail_search_book, this->search_bar_book->Text, dataGridView1);
	
	}

	System::Void list_of_books_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->search_bar_book->Text = "";
		search_button_book_Click(sender, e);
	}
}

