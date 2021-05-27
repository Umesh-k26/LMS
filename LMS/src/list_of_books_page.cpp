#include "pch.h"
#include "list_of_books_page.h"

///Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Books
///@see InitializeComponent(), sql_connection_func::fill_datagrid_book()
LMS::list_of_books_page::list_of_books_page(void)
{
	InitializeComponent();
	sql_connection_func::fill_datagrid_book(list_of_books_dataGridView);
}

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Books
/// </summary>
/// @see transfer_id, is_librarian, InitializeComponent(), sql_connection_func::fill_datagrid_book()
LMS::list_of_books_page::list_of_books_page(String^ input_transfer_id, bool is_librarian_input)
{
	transfer_id = input_transfer_id;
	is_librarian = is_librarian_input;
	InitializeComponent();
	//fill_data_grid();
	sql_connection_func::fill_datagrid_book(list_of_books_dataGridView);
}

LMS::list_of_books_page::~list_of_books_page()
{
	if (components)
	{
		delete components;
	}
}


/// <summary>
/// It loads the Form in full screen mode
/// </summary>
System::Void LMS::list_of_books_page::list_of_books_page_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;
	this->list_detail_search_book->SelectedIndex = 1;
}

/// <summary>
	/// Function for Back Button which goes back to the previous Form by closing the current form
	/// </summary>
System::Void LMS::list_of_books_page::back_button_book_list_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
	/*CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
	this->Hide();
	f2->ShowDialog();*/
}

/// <summary>
/// Exit Button Function to Exit the application from the current Form
/// </summary>
System::Void LMS::list_of_books_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

/// <summary>
/// Button OnClick function to Open Profile of Books with their details
/// </summary>
System::Void LMS::list_of_books_page::list_of_books_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->ColumnIndex == 0)
	{
		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->list_of_books_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();
		MessageBox::Show("Your id is " + str);
		LMS::profile_book^ profile_book_f = gcnew LMS::profile_book(str, is_librarian);
		this->Hide();
		//testing_f->ShowDialog();

		if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
			sql_connection_func::fill_datagrid_book(list_of_books_dataGridView);
		}

	}

}

/// <summary>
/// Button OnClick function to search and fill the Data Grid with filtered results from the Drop Down List
/// </summary>
/// @see sql_connection_func::fill_datagrid_books_filtered()
System::Void LMS::list_of_books_page::search_button_book_Click(System::Object^ sender, System::EventArgs^ e)
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

	sql_connection_func::fill_datagrid_books_filtered(str_list_detail_search_book, this->search_bar_book->Text, list_of_books_dataGridView);

}

/// <summary>
/// Clear Search Results function and present original default data.
/// </summary>
/// @see search_button_student_Click()
System::Void LMS::list_of_books_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->search_bar_book->Text = "";
	search_button_book_Click(sender, e);
}