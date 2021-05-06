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

	String^ Gender;

	private: System::Windows::Forms::Label^ name_lbl;
	protected:

	private: System::Windows::Forms::Label^ dob_lbl;
	protected:

	private: System::Windows::Forms::Label^ profession_lbl;

	private: System::Windows::Forms::Label^ email_id_lbl;

	private: System::Windows::Forms::Label^ mobile_no_lbl;

	private: System::Windows::Forms::Label^ address_lbl;

	private: System::Windows::Forms::TextBox^ name_txt;

	private: System::Windows::Forms::TextBox^ profession_txt;
	private: System::Windows::Forms::TextBox^ email_id_txt;
	private: System::Windows::Forms::TextBox^ mobile_no_txt;
	private: System::Windows::Forms::TextBox^ address_txt;
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Label^ status_lbl;
	private: System::Windows::Forms::TextBox^ status_no_txt;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ female_rbtn;

	private: System::Windows::Forms::RadioButton^ male_rbtn;




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
			this->profession_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->status_lbl = (gcnew System::Windows::Forms::Label());
			this->status_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->female_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->male_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(36, 81);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(35, 13);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(36, 145);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(66, 13);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// profession_lbl
			// 
			this->profession_lbl->AutoSize = true;
			this->profession_lbl->Location = System::Drawing::Point(36, 256);
			this->profession_lbl->Name = L"profession_lbl";
			this->profession_lbl->Size = System::Drawing::Size(56, 13);
			this->profession_lbl->TabIndex = 2;
			this->profession_lbl->Text = L"Profession";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(36, 299);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(44, 13);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(36, 342);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(58, 13);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(36, 386);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(45, 13);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(170, 81);
			this->name_txt->Name = L"name_txt";
			this->name_txt->Size = System::Drawing::Size(100, 20);
			this->name_txt->TabIndex = 6;
			// 
			// profession_txt
			// 
			this->profession_txt->Location = System::Drawing::Point(172, 253);
			this->profession_txt->Name = L"profession_txt";
			this->profession_txt->Size = System::Drawing::Size(100, 20);
			this->profession_txt->TabIndex = 8;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(171, 296);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->Size = System::Drawing::Size(100, 20);
			this->email_id_txt->TabIndex = 9;
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(172, 339);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->Size = System::Drawing::Size(100, 20);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(172, 383);
			this->address_txt->Name = L"address_txt";
			this->address_txt->Size = System::Drawing::Size(100, 20);
			this->address_txt->TabIndex = 11;
			// 
			// add_button
			// 
			this->add_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->add_button->Location = System::Drawing::Point(626, 278);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(117, 32);
			this->add_button->TabIndex = 12;
			this->add_button->Text = L"Register";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &RegisterStudent::add_button_Click);
			// 
			// status_lbl
			// 
			this->status_lbl->AutoSize = true;
			this->status_lbl->Location = System::Drawing::Point(36, 428);
			this->status_lbl->Name = L"status_lbl";
			this->status_lbl->Size = System::Drawing::Size(91, 13);
			this->status_lbl->TabIndex = 13;
			this->status_lbl->Text = L"Borrow status No.";
			// 
			// status_no_txt
			// 
			this->status_no_txt->Location = System::Drawing::Point(172, 425);
			this->status_no_txt->Name = L"status_no_txt";
			this->status_no_txt->Size = System::Drawing::Size(100, 20);
			this->status_no_txt->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(35, 33);
			this->button1->Margin = System::Windows::Forms::Padding(1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(37, 34);
			this->button1->TabIndex = 15;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterStudent::button1_Click);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(171, 145);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(99, 20);
			this->dateTimePicker->TabIndex = 16;
			this->dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &RegisterStudent::dateTimePicker_ValueChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->female_rbtn);
			this->groupBox1->Controls->Add(this->male_rbtn);
			this->groupBox1->Controls->Add(this->status_no_txt);
			this->groupBox1->Controls->Add(this->dateTimePicker);
			this->groupBox1->Controls->Add(this->name_lbl);
			this->groupBox1->Controls->Add(this->dob_lbl);
			this->groupBox1->Controls->Add(this->profession_lbl);
			this->groupBox1->Controls->Add(this->status_lbl);
			this->groupBox1->Controls->Add(this->email_id_lbl);
			this->groupBox1->Controls->Add(this->mobile_no_lbl);
			this->groupBox1->Controls->Add(this->address_txt);
			this->groupBox1->Controls->Add(this->address_lbl);
			this->groupBox1->Controls->Add(this->mobile_no_txt);
			this->groupBox1->Controls->Add(this->name_txt);
			this->groupBox1->Controls->Add(this->email_id_txt);
			this->groupBox1->Controls->Add(this->profession_txt);
			this->groupBox1->Location = System::Drawing::Point(235, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(333, 522);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Register Student";
			// 
			// female_rbtn
			// 
			this->female_rbtn->AutoSize = true;
			this->female_rbtn->Location = System::Drawing::Point(170, 204);
			this->female_rbtn->Name = L"female_rbtn";
			this->female_rbtn->Size = System::Drawing::Size(59, 17);
			this->female_rbtn->TabIndex = 19;
			this->female_rbtn->TabStop = true;
			this->female_rbtn->Text = L"Female";
			this->female_rbtn->UseVisualStyleBackColor = true;
			this->female_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterStudent::female_rbtn_CheckedChanged);
			// 
			// male_rbtn
			// 
			this->male_rbtn->AutoSize = true;
			this->male_rbtn->Location = System::Drawing::Point(54, 204);
			this->male_rbtn->Name = L"male_rbtn";
			this->male_rbtn->Size = System::Drawing::Size(48, 17);
			this->male_rbtn->TabIndex = 18;
			this->male_rbtn->TabStop = true;
			this->male_rbtn->Text = L"Male";
			this->male_rbtn->UseVisualStyleBackColor = true;
			this->male_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterStudent::male_rbtn_CheckedChanged);
			// 
			// RegisterStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 633);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->add_button);
			this->MinimumSize = System::Drawing::Size(857, 666);
			this->Name = L"RegisterStudent";
			this->Text = L"Register Student";
			this->Load += gcnew System::EventHandler(this, &RegisterStudent::RegisterStudent_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {

		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO library_system.student_data (student_name, student_dob, student_address, student_email, \
		student_mobile, student_profession, student_no_book_stat,student_fine, student_gender) \
		VALUES('" + this->name_txt->Text + "',\
		'" + this->dateTimePicker->Text + "',\
		'" + this->address_txt->Text + "',\
		'" + this->email_id_txt->Text + "',\
		" + this->mobile_no_txt->Text + ",\
		'" + this->profession_txt->Text + "',\
		" + this->status_no_txt->Text + ", 0, '"+Gender+"')	;", conDataBase);


		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			MessageBox::Show("Student registered successfully!");
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

private: System::Void dob_txt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void male_rbtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Gender = "Male";
}
private: System::Void female_rbtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Gender = "Female";
}
};
}
