#include "pch.h"
#include "list_of_students_page.h"

namespace CppCLR_WinformsProjekt1 {
	///Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Non-Librarian Users
	///@see InitializeComponent(), sql_connection_func::fill_datagrid_student()
	list_of_students_page::list_of_students_page(void)
	{ 
		InitializeComponent();
		//fill_listbox1();
		//fill_data_grid();
		//
		//TODO: Add the constructor code here
		//
		sql_connection_func::fill_datagrid_student(dataGridView1);
	}

	/// <summary>
	/// Constructor calls for functions to Initialize all the components of the form and to fill the Data Grid with list of all Non-Librarian Users
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent(), sql_connection_func::fill_datagrid_student()
	list_of_students_page::list_of_students_page(String^ input_id_transfer, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_id_transfer;
		is_librarian = is_librarian_input;
		//fill_listbox1();
		//fill_data_grid();
		//
		//TODO: Add the constructor code here
		//
		sql_connection_func::fill_datagrid_student(dataGridView1);
	}

	list_of_students_page::~list_of_students_page()
	{
		if (components)
		{
			delete components;
		}
	}

	void list_of_students_page::fill_data_grid()
	{
		MySqlConnection^ conDataBase = gcnew MySqlConnection(sql_connection_func::sql_user_pass_string());
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT student_id AS ID, student_name AS Name, student_mobile AS Mobile, student_email as 'E-Mail', student_no_book_stat AS 'No. of Books Borrowed' FROM library_system.student_data;", conDataBase);

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

	/// <summary>
	/// It loads the Form in full screen mode
	/// </summary>
	System::Void list_of_students_page::list_of_students_page_Load(System::Object^ sender, System::EventArgs^ e)
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		this->list_detail_search_person->SelectedIndex = 1;

	}

	/// <summary>
	/// Function for Back Button which goes back to the previous Form by closing the current form
	/// </summary>
	System::Void list_of_students_page::back_button_student_list_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
		//this->Hide();
		//f2->ShowDialog();
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	System::Void list_of_students_page::button3_Click(System::Object^ sender, System::EventArgs^ e)
	{

		CppCLR_WinformsProjekt1::testing^ testing_f = gcnew CppCLR_WinformsProjekt1::testing;
		this->Hide();
		//testing_f->ShowDialog();
		if (testing_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
		//String^ str = text_combo_data(this->list_detail_search_person->Text);
		//MessageBox::Show(str);
	}

	/// <summary>
	/// Button OnClick function to Open Profile of Non-Librarin User with their details
	/// </summary>
	System::Void list_of_students_page::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (e->ColumnIndex == 0)
		{
			int row_num = e->RowIndex;
			int col_num = e->ColumnIndex + 1;
			String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();

			MessageBox::Show("Your id is " + str);
			CppCLR_WinformsProjekt1::profile_student^ profile_student_f = gcnew CppCLR_WinformsProjekt1::profile_student(str, is_librarian);
			this->Hide();
			//testing_f->ShowDialog();

			if (profile_student_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
				//fill_data_grid();
				sql_connection_func::fill_datagrid_student(dataGridView1);
			}

		}

	}

	/// <summary>
	/// Button OnClick function to search and fill the Data Grid with filtered results from the Drop Down List
	/// </summary>
	/// @see sql_connection_func::fill_datagrid_students_filtered()
	System::Void list_of_students_page::search_button_student_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ str_list_detail_search_person;
		if (this->list_detail_search_person->Text == "Name")
		{
			str_list_detail_search_person = "student_name";
		}
		if (String::Equals(this->list_detail_search_person->Text, "ID"))
		{
			str_list_detail_search_person = "student_id";
		}
		if (String::Equals(this->list_detail_search_person->Text, "Phone"))
		{
			str_list_detail_search_person = "student_mobile";
		}
		if (String::Equals(this->list_detail_search_person->Text, "Email"))
		{
			str_list_detail_search_person = "student_email";
		}
		if (String::Equals(this->list_detail_search_person->Text, "Number of books borrowed currently"))
		{
			str_list_detail_search_person = "student_no_book_stat";
		}

		sql_connection_func::fill_datagrid_students_filtered(str_list_detail_search_person, this->search_bar_student->Text, dataGridView1);

	}

	/// <summary>
	/// Exit Button Function to Exit the application from the current Form
	/// </summary>
	System::Void list_of_students_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}

	/// <summary>
	/// Clear Search Results function and present original default data.
	/// </summary>
	/// @see search_button_student_Click()
	System::Void list_of_students_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->search_bar_student->Text = "";
		search_button_student_Click(sender, e);
	}

}

