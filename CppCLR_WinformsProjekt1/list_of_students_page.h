#pragma once
#include "pch.h"
//#include "Form2.h"
#include "testing.h"
#include "profile_student.h"
#include "connection_sql_func.h"
namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	/// <summary>
	/// Summary for list_of_students_page
	/// </summary>
	public ref class list_of_students_page : public System::Windows::Forms::Form
	{
	public:
		list_of_students_page(void)
		{
			InitializeComponent();
			//fill_listbox1();
			//fill_data_grid();
			//
			//TODO: Add the constructor code here
			//
			sql_connection_func::fill_datagrid_student(dataGridView1);
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~list_of_students_page()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ search_bar_student;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ back_button_student_list;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: System::Windows::Forms::Button^ search_button_student;
	private: System::Windows::Forms::ComboBox^ list_detail_search_person;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Button^ clear_all_button;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(list_of_students_page::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Open = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->search_bar_student = (gcnew System::Windows::Forms::TextBox());
			this->back_button_student_list = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->search_button_student = (gcnew System::Windows::Forms::Button());
			this->list_detail_search_person = (gcnew System::Windows::Forms::ComboBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->clear_all_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open });
			this->dataGridView1->Location = System::Drawing::Point(174, 148);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1439, 560);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &list_of_students_page::dataGridView1_CellContentClick);
			// 
			// Open
			// 
			this->Open->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Open->HeaderText = L"Profile";
			this->Open->MinimumWidth = 8;
			this->Open->Name = L"Open";
			this->Open->ReadOnly = true;
			this->Open->Text = L"Open";
			this->Open->UseColumnTextForButtonValue = true;
			// 
			// search_bar_student
			// 
			this->search_bar_student->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->search_bar_student->Location = System::Drawing::Point(198, 12);
			this->search_bar_student->Name = L"search_bar_student";
			this->search_bar_student->Size = System::Drawing::Size(463, 26);
			this->search_bar_student->TabIndex = 2;
			// 
			// back_button_student_list
			// 
			this->back_button_student_list->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button_student_list.Image")));
			this->back_button_student_list->Location = System::Drawing::Point(12, 12);
			this->back_button_student_list->Name = L"back_button_student_list";
			this->back_button_student_list->Size = System::Drawing::Size(75, 45);
			this->back_button_student_list->TabIndex = 3;
			this->back_button_student_list->UseVisualStyleBackColor = true;
			this->back_button_student_list->Click += gcnew System::EventHandler(this, &list_of_students_page::back_button_student_list_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 63);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 45);
			this->button3->TabIndex = 5;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &list_of_students_page::button3_Click);
			// 
			// search_button_student
			// 
			this->search_button_student->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_button_student->Location = System::Drawing::Point(950, 12);
			this->search_button_student->Name = L"search_button_student";
			this->search_button_student->Size = System::Drawing::Size(105, 30);
			this->search_button_student->TabIndex = 6;
			this->search_button_student->Text = L"Search";
			this->search_button_student->UseVisualStyleBackColor = true;
			this->search_button_student->Click += gcnew System::EventHandler(this, &list_of_students_page::search_button_student_Click);
			// 
			// list_detail_search_person
			// 
			this->list_detail_search_person->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->list_detail_search_person->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->list_detail_search_person->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"ID", L"Name", L"Phone", L"Email",
					L"Number of books borrowed currently"
			});
			this->list_detail_search_person->Location = System::Drawing::Point(667, 12);
			this->list_detail_search_person->Name = L"list_detail_search_person";
			this->list_detail_search_person->Size = System::Drawing::Size(277, 28);
			this->list_detail_search_person->TabIndex = 7;
			this->list_detail_search_person->SelectedIndexChanged += gcnew System::EventHandler(this, &list_of_students_page::list_detail_search_person_SelectedIndexChanged);
			// 
			// exit_button
			// 
			this->exit_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->exit_button->Location = System::Drawing::Point(1510, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(103, 46);
			this->exit_button->TabIndex = 8;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &list_of_students_page::exit_button_Click);
			// 
			// clear_all_button
			// 
			this->clear_all_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->clear_all_button->Location = System::Drawing::Point(1061, 12);
			this->clear_all_button->Name = L"clear_all_button";
			this->clear_all_button->Size = System::Drawing::Size(115, 30);
			this->clear_all_button->TabIndex = 9;
			this->clear_all_button->Text = L"Clear Search";
			this->clear_all_button->UseVisualStyleBackColor = true;
			this->clear_all_button->Click += gcnew System::EventHandler(this, &list_of_students_page::clear_all_button_Click);
			// 
			// list_of_students_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1642, 955);
			this->Controls->Add(this->clear_all_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->list_detail_search_person);
			this->Controls->Add(this->search_button_student);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->back_button_student_list);
			this->Controls->Add(this->search_bar_student);
			this->Controls->Add(this->dataGridView1);
			this->MinimumSize = System::Drawing::Size(1664, 1011);
			this->Name = L"list_of_students_page";
			this->Text = L"list_of_students_page";
			this->Load += gcnew System::EventHandler(this, &list_of_students_page::list_of_students_page_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/*
			private: void fill_listbox1() {
				//
				//	This section works but can print only one thing
				//
				//
				String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
				MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
				//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);
				MySqlCommand^ print_students = gcnew MySqlCommand("select * from test.student_data;", conDataBase);
				MySqlDataReader^ myReader;
				//listBox1.Items.Add("Mahesh Chand");
				try {
					conDataBase->Open();
					myReader = print_students->ExecuteReader();

					while (myReader->Read())
					{
						String^ printing_names;
						printing_names = myReader->GetString("gender");
						listBox1->Items->Add(printing_names);

					}

				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);

				}


			}
			*/
	private: void fill_data_grid() {

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


	private: System::Void list_of_students_page_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		this->list_detail_search_person->SelectedIndex = 1;


	}
	private: System::Void back_button_student_list_Click(System::Object^ sender, System::EventArgs^ e) {
		//CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
		//this->Hide();
		//f2->ShowDialog();
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();


	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

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


	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
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
	private: System::Void search_button_student_Click(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void list_detail_search_person_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void clear_all_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->search_bar_student->Text = "";
		search_button_student_Click(sender, e);
	}
	};
}
