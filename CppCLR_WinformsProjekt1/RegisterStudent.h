#pragma once
#include "testing.h"
namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for RegisterStudent
	/// </summary>
	public ref class RegisterStudent : public System::Windows::Forms::Form
	{
	public:
		RegisterStudent(void)
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
		~RegisterStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ name_lbl;
	protected:

	private: System::Windows::Forms::Label^ dob_lbl;
	protected:

	private: System::Windows::Forms::Label^ profession_lbl;

	private: System::Windows::Forms::Label^ email_id_lbl;

	private: System::Windows::Forms::Label^ mobile_no_lbl;

	private: System::Windows::Forms::Label^ address_lbl;

	private: System::Windows::Forms::TextBox^ name_txt;
	private: System::Windows::Forms::TextBox^ dob_txt;
	private: System::Windows::Forms::TextBox^ profession_txt;
	private: System::Windows::Forms::TextBox^ email_id_txt;
	private: System::Windows::Forms::TextBox^ mobile_no_txt;
	private: System::Windows::Forms::TextBox^ address_txt;
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Label^ status_lbl;
	private: System::Windows::Forms::TextBox^ status_no_txt;
	private: System::Windows::Forms::Button^ button1;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterStudent::typeid));
			this->name_lbl = (gcnew System::Windows::Forms::Label());
			this->dob_lbl = (gcnew System::Windows::Forms::Label());
			this->profession_lbl = (gcnew System::Windows::Forms::Label());
			this->email_id_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_lbl = (gcnew System::Windows::Forms::Label());
			this->address_lbl = (gcnew System::Windows::Forms::Label());
			this->name_txt = (gcnew System::Windows::Forms::TextBox());
			this->dob_txt = (gcnew System::Windows::Forms::TextBox());
			this->profession_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->status_lbl = (gcnew System::Windows::Forms::Label());
			this->status_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(328, 240);
			this->name_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(51, 20);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(328, 309);
			this->dob_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(99, 20);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// profession_lbl
			// 
			this->profession_lbl->AutoSize = true;
			this->profession_lbl->Location = System::Drawing::Point(328, 388);
			this->profession_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->profession_lbl->Name = L"profession_lbl";
			this->profession_lbl->Size = System::Drawing::Size(84, 20);
			this->profession_lbl->TabIndex = 2;
			this->profession_lbl->Text = L"Profession";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(328, 468);
			this->email_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(66, 20);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(328, 548);
			this->mobile_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(83, 20);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(328, 628);
			this->address_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(68, 20);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(531, 235);
			this->name_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->name_txt->Name = L"name_txt";
			this->name_txt->Size = System::Drawing::Size(148, 26);
			this->name_txt->TabIndex = 6;
			// 
			// dob_txt
			// 
			this->dob_txt->Location = System::Drawing::Point(531, 305);
			this->dob_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dob_txt->Name = L"dob_txt";
			this->dob_txt->Size = System::Drawing::Size(148, 26);
			this->dob_txt->TabIndex = 7;
			// 
			// profession_txt
			// 
			this->profession_txt->Location = System::Drawing::Point(531, 383);
			this->profession_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->profession_txt->Name = L"profession_txt";
			this->profession_txt->Size = System::Drawing::Size(148, 26);
			this->profession_txt->TabIndex = 8;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(531, 463);
			this->email_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->Size = System::Drawing::Size(148, 26);
			this->email_id_txt->TabIndex = 9;
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(531, 543);
			this->mobile_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->Size = System::Drawing::Size(148, 26);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(531, 623);
			this->address_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->address_txt->Name = L"address_txt";
			this->address_txt->Size = System::Drawing::Size(148, 26);
			this->address_txt->TabIndex = 11;
			// 
			// add_button
			// 
			this->add_button->Location = System::Drawing::Point(884, 406);
			this->add_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(176, 49);
			this->add_button->TabIndex = 12;
			this->add_button->Text = L"Add";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &RegisterStudent::add_button_Click);
			// 
			// status_lbl
			// 
			this->status_lbl->AutoSize = true;
			this->status_lbl->Location = System::Drawing::Point(328, 703);
			this->status_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->status_lbl->Name = L"status_lbl";
			this->status_lbl->Size = System::Drawing::Size(135, 20);
			this->status_lbl->TabIndex = 13;
			this->status_lbl->Text = L"Borrow status No.";
			// 
			// status_no_txt
			// 
			this->status_no_txt->Location = System::Drawing::Point(531, 698);
			this->status_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->status_no_txt->Name = L"status_no_txt";
			this->status_no_txt->Size = System::Drawing::Size(148, 26);
			this->status_no_txt->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(52, 51);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 29);
			this->button1->TabIndex = 15;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterStudent::button1_Click);
			// 
			// RegisterStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

			this->ClientSize = System::Drawing::Size(811, 590);
			this->Controls->Add(this->button1);

			this->Controls->Add(this->status_no_txt);
			this->Controls->Add(this->status_lbl);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->address_txt);
			this->Controls->Add(this->mobile_no_txt);
			this->Controls->Add(this->email_id_txt);
			this->Controls->Add(this->profession_txt);
			this->Controls->Add(this->dob_txt);
			this->Controls->Add(this->name_txt);
			this->Controls->Add(this->address_lbl);
			this->Controls->Add(this->mobile_no_lbl);
			this->Controls->Add(this->email_id_lbl);
			this->Controls->Add(this->profession_lbl);
			this->Controls->Add(this->dob_lbl);
			this->Controls->Add(this->name_lbl);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"RegisterStudent";
			this->Text = L"RegisterStudent";
			this->Load += gcnew System::EventHandler(this, &RegisterStudent::RegisterStudent_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO library_system.student_data (student_name, student_dob, student_address, student_email, \
		student_mobile, student_profession, student_no_book_stat) \
		VALUES('" + this->name_txt->Text + "',\
		'" + this->dob_txt->Text + "',\
		'" + this->address_txt->Text + "',\
		'" + this->email_id_txt->Text + "',\
		" + this->mobile_no_txt->Text + "',\
		'" + this->profession_txt->Text + "',\
		'" + this->status_no_txt->Text + "'	;", conDataBase);


		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			MessageBox::Show("Book added successfully!");
			while (myReader->Read())
			{

			}

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
private: System::Void RegisterStudent_Load(System::Object^ sender, System::EventArgs^ e) {
	CenterToScreen();

	WindowState = FormWindowState::Maximized;
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

};
}
