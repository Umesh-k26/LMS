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
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"hello", L"woewe" });
			this->listBox1->Location = System::Drawing::Point(196, 101);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(243, 204);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &list_of_students_page::listBox1_SelectedIndexChanged);
			// 
			// list_of_students_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(542, 400);
			this->Controls->Add(this->listBox1);
			this->Name = L"list_of_students_page";
			this->Text = L"list_of_students_page";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


		//
		//	This section still needs to be edited to work.
		//
		//
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);
		MySqlCommand^ print_students = gcnew MySqlCommand("select * from test.student_data;", conDataBase);
		MySqlDataReader^ myReader;
		//listBox1.Items.Add("Mahesh Chand");
		try {
			conDataBase->Open();
			myReader = print_students->ExecuteReader();
			int count = 0;
			while (myReader->Read())
			{
				count += 1;
			}
			if (count == 1)
			{
				MessageBox::Show("printing ");
			}
			else if (count > 1)
			{
				MessageBox::Show("Access denied");
				
			}
			else
				MessageBox::Show("Please try again");


		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}


	}
	};
}
