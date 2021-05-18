#include "pch.h"
#include "list_of_students_page.h"

namespace CppCLR_WinformsProjekt1 {

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

	System::Void list_of_students_page::list_of_students_page_Load(System::Object^ sender, System::EventArgs^ e)
	{
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		this->list_detail_search_person->SelectedIndex = 1;

	}
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
	System::Void list_of_students_page::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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
			CppCLR_WinformsProjekt1::profile_student^ profile_student_f = gcnew CppCLR_WinformsProjekt1::profile_student(str);
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

		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		/*String^ constring = sql_connection_func::sql_user_pass_string();

		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);
		//student_id,student_name,student_mobile, student_profession, student_no_book_stat
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT student_id AS ID, student_name AS Name, student_mobile AS Mobile, student_email as 'E-Mail', student_no_book_stat AS 'No. of Books Borrowed' FROM library_system.student_data\
		WHERE " + str_list_detail_search_person + " LIKE '%" + this->search_bar_student->Text + "%';", conDataBase);
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
		sql_connection_func::fill_datagrid_students_filtered(str_list_detail_search_person, this->search_bar_student->Text, dataGridView1);

	}
	System::Void list_of_students_page::exit_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
	System::Void list_of_students_page::clear_all_button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->search_bar_student->Text = "";
		search_button_student_Click(sender, e);
	}

}

