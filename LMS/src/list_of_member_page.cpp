#include "pch.h"
#include "list_of_member_page.h"

///Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Members.
///@see InitializeComponent(), sql_connection_func::fill_datagrid_member()
LMS::list_of_member_page::list_of_member_page(void)
{
	InitializeComponent();
	sql_connection_func::fill_datagrid_member(list_of_member_dataGridView);
}

/// <summary>
/// Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Members
/// </summary>
/// @see transfer_id, is_librarian, InitializeComponent(), sql_connection_func::fill_datagrid_member()
LMS::list_of_member_page::list_of_member_page(String^ input_id_transfer, bool is_librarian_input)
{
	InitializeComponent();
	transfer_id = input_id_transfer;
	is_librarian = is_librarian_input;
	//fill_listbox1();
	//fill_data_grid();
	sql_connection_func::fill_datagrid_member(list_of_member_dataGridView);
}

LMS::list_of_member_page::~list_of_member_page()
{
	if (components)
	{
		delete components;
	}
}

/// <summary>
/// Function for Back Button which goes back to the previous Form by closing the current form
/// </summary>
System::Void LMS::list_of_member_page::back_button_member_list_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

/// <summary>
/// Button OnClick function to Open Profile of Non-Librarin User with their details
/// </summary>
System::Void LMS::list_of_member_page::list_of_member_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->ColumnIndex == 0)
	{
		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->list_of_member_dataGridView->Rows[row_num]->Cells[col_num]->Value->ToString();

		MessageBox::Show("Your id is " + str);
		LMS::profile_member^ profile_member_f = gcnew LMS::profile_member(str, is_librarian);
		this->Hide();
		if (profile_member_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
			sql_connection_func::fill_datagrid_member(list_of_member_dataGridView);
		}

	}
}

/// <summary>
/// Button OnClick function to search and fill the Data Grid with filtered results from the Drop Down List
/// </summary>
/// @see sql_connection_func::fill_datagrid_members_filtered()
System::Void LMS::list_of_member_page::search_button_member_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ str_list_detail_search_member;
	if (this->list_detail_search_member->Text == "Name")
	{
		str_list_detail_search_member = "member_name";
	}
	if (String::Equals(this->list_detail_search_member->Text, "ID"))
	{
		str_list_detail_search_member = "member_id";
	}
	if (String::Equals(this->list_detail_search_member->Text, "Phone"))
	{
		str_list_detail_search_member = "member_mobile";
	}
	if (String::Equals(this->list_detail_search_member->Text, "Email"))
	{
		str_list_detail_search_member = "member_email";
	}
	if (String::Equals(this->list_detail_search_member->Text, "Number of books borrowed currently"))
	{
		str_list_detail_search_member = "member_no_book_stat";
	}

	sql_connection_func::fill_datagrid_members_filtered(str_list_detail_search_member, this->search_bar_member->Text, list_of_member_dataGridView);

}

/// <summary>
/// Clear Search Results function and present original default data.
/// </summary>
/// @see search_button_member_Click()
System::Void LMS::list_of_member_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->search_bar_member->Text = "";
	search_button_member_Click(sender, e);
}

/// <summary>
/// Exit Button Function to Exit the application from the current Form
/// </summary>
System::Void LMS::list_of_member_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

/// <summary>
/// It loads the Form in full screen mode
/// </summary>
System::Void LMS::list_of_member_page::list_of_member_page_Load(System::Object^ sender, System::EventArgs^ e)
{
	CenterToScreen();
	//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
	WindowState = FormWindowState::Maximized;
	this->list_detail_search_member->SelectedIndex = 1;
}
