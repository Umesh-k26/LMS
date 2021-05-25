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
	///This is a public ref class whose object lifetime is administered automatically. When the object is no longer accessible or goes out of scope, the memory is released.
	/// It supports the Windows Runtime type system.
	public ref class list_of_students_page : public System::Windows::Forms::Form
	{

	public:
		/// <summary>
		/// Public variable for transfering the ID of the user
		/// </summary>
		/// It transfers the ID of the user as String which is part of the public ref class and a member of System.
		String^ transfer_id;
		/// <summary>
		/// Public variables for transfering whether the user is a librarian or not
		/// </summary>
		/// It transfers a boolean value with true representing the user is a librarian and false if the user is not a librarian
		bool is_librarian;
	public:
		/// <summary>
		/// Constructor function for the form
		/// </summary>
		/// <param name="void"></param>
		list_of_students_page(void);

		/// <summary>
		/// Constructor function for the form with transferable variables as parameters
		/// </summary>
		/// <param name="input_id_transfer">
		/// It is the input argument for the ID to be transfered while calling the constructor
		/// </param>
		/// <param name="is_librarian_input">
		/// It is the input argument for the boolean value, if the User is a librarian or not, to be transfered while calling the constructor
		/// </param>
		list_of_students_page(String^ input_id_transfer, bool is_librarian_input);

	protected:
		/// <summary>
		/// Destructor function for the form
		/// </summary>
		~list_of_students_page();

	private: 
		/// <summary>
		/// TextBox for the Search Bar
		/// </summary>
		/// @see search_button_student, list_detail_search_person, clear_all_button
		System::Windows::Forms::TextBox^ search_bar_student;
	private: 
		/// <summary>
		/// Data Grid to present the General details of Non-Librarian Users which includes Students, Faculty and Alumni.
		/// </summary>
		/// @see Open
		System::Windows::Forms::DataGridView^ dataGridView1;
	private:
		/// <summary>
		/// Back Button to navigate backward
		/// </summary>
		System::Windows::Forms::Button^ back_button_student_list;

	private: System::Windows::Forms::Button^ button3;
	private: 
		/// <summary>
		/// A dedicated button inside the Data Grid to open the profile of Non-Librarian Users with more details
		/// </summary>
		/// @see dataGridView1
		System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: 
		/// <summary>
		/// Search Button to show search results based on input in the Search Bar and Drop Down List
		/// </summary>
		/// @see search_bar_student, list_detail_search_person, clear_all_button
		System::Windows::Forms::Button^ search_button_student;
	private: 
		/// <summary>
		/// Drop Down List to filter the list based on different attributes of Non-Librarian Users.
		/// </summary>
		System::Windows::Forms::ComboBox^ list_detail_search_person;
	private: 
		/// <summary>
		/// Exit Button to exit the application
		/// </summary>
		System::Windows::Forms::Button^ exit_button;
	private: 
		/// <summary>
		/// Clear All Search Results Button to show default data
		/// </summary>
		/// @see search_bar_student, list_detail_search_person, search_button_student
		System::Windows::Forms::Button^ clear_all_button;

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
		/// To Initialize all the components required to load the form
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
	private: void fill_data_grid();


	private:
		/// <summary>
		/// System::Void function to load the form
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void list_of_students_page_Load(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick of back button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void back_button_student_list_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick cell in the Data Grid
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled by the Data Grid.
		/// </param>
		System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick Search Button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void search_button_student_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void list_detail_search_person_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}

	private:
		/// <summary>
		/// System::Void function for OnClick Exit Button
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e);

	private:
		/// <summary>
		/// System::Void function for OnClick Clear All Search Results
		/// </summary>
		/// <param name="sender">
		///Provides a reference to the object that raised the event
		/// </param>
		/// <param name="e">
		///Passes an object specific to the event that is being handled.
		/// </param>
		System::Void clear_all_button_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
