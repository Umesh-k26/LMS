#pragma once
#include "pch.h"
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
			fill_listbox1();
			fill_data_grid();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"hello", L"woewe" });
			this->listBox1->Location = System::Drawing::Point(709, 55);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(364, 344);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &list_of_students_page::listBox1_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(101, 83);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(552, 382);
			this->dataGridView1->TabIndex = 1;
			// 
			// list_of_students_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1131, 553);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->listBox1);
			this->Name = L"list_of_students_page";
			this->Text = L"list_of_students_page";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

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

	private: void fill_data_grid() {

		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data;", conDataBase);
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

	};
}
