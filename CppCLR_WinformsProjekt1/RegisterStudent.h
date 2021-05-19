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
		String^ transfer_id;
		bool is_librarian;

	public:
		RegisterStudent(void);
		RegisterStudent(String^ input_transfer_id, bool is_librarian_input);

	protected:
		~RegisterStudent();

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


	private: System::Windows::Forms::TextBox^ email_id_txt;
	private: System::Windows::Forms::TextBox^ mobile_no_txt;
	private: System::Windows::Forms::TextBox^ address_txt;
	private: System::Windows::Forms::Button^ register_button;

	private: System::Windows::Forms::Label^ status_lbl;
	private: System::Windows::Forms::TextBox^ status_no_txt;
	private: System::Windows::Forms::Button^ back_button;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::GroupBox^ register_student_grp_box;

	private: System::Windows::Forms::RadioButton^ female_rbtn;

	private: System::Windows::Forms::RadioButton^ male_rbtn;
	private: System::Windows::Forms::TextBox^ re_password_txt;

	private: System::Windows::Forms::TextBox^ password_txt;
	private: System::Windows::Forms::Label^ password_lbl;
	private: System::Windows::Forms::Label^ re_password_lbl;
	private: System::Windows::Forms::ComboBox^ profession_comboBox;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterStudent::typeid));
			this->name_lbl = (gcnew System::Windows::Forms::Label());
			this->dob_lbl = (gcnew System::Windows::Forms::Label());
			this->profession_lbl = (gcnew System::Windows::Forms::Label());
			this->email_id_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_lbl = (gcnew System::Windows::Forms::Label());
			this->address_lbl = (gcnew System::Windows::Forms::Label());
			this->name_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->register_button = (gcnew System::Windows::Forms::Button());
			this->status_lbl = (gcnew System::Windows::Forms::Label());
			this->status_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->register_student_grp_box = (gcnew System::Windows::Forms::GroupBox());
			this->profession_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->re_password_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_lbl = (gcnew System::Windows::Forms::Label());
			this->re_password_lbl = (gcnew System::Windows::Forms::Label());
			this->female_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->male_rbtn = (gcnew System::Windows::Forms::RadioButton());
			this->register_student_grp_box->SuspendLayout();
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
			// register_button
			// 
			this->register_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_button->Location = System::Drawing::Point(626, 278);
			this->register_button->Name = L"register_button";
			this->register_button->Size = System::Drawing::Size(117, 32);
			this->register_button->TabIndex = 12;
			this->register_button->Text = L"Register";
			this->register_button->UseVisualStyleBackColor = true;
			this->register_button->Click += gcnew System::EventHandler(this, &RegisterStudent::RegisterStudent_Click);
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
			// back_button
			// 
			this->back_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button.Image")));
			this->back_button->Location = System::Drawing::Point(35, 33);
			this->back_button->Margin = System::Windows::Forms::Padding(1);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(37, 34);
			this->back_button->TabIndex = 15;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &RegisterStudent::BackButton_Click);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Checked = false;
			this->dateTimePicker->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(171, 145);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(99, 20);
			this->dateTimePicker->TabIndex = 16;
			// 
			// register_student_grp_box
			// 
			this->register_student_grp_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_student_grp_box->Controls->Add(this->profession_comboBox);
			this->register_student_grp_box->Controls->Add(this->re_password_txt);
			this->register_student_grp_box->Controls->Add(this->password_txt);
			this->register_student_grp_box->Controls->Add(this->password_lbl);
			this->register_student_grp_box->Controls->Add(this->re_password_lbl);
			this->register_student_grp_box->Controls->Add(this->female_rbtn);
			this->register_student_grp_box->Controls->Add(this->male_rbtn);
			this->register_student_grp_box->Controls->Add(this->status_no_txt);
			this->register_student_grp_box->Controls->Add(this->dateTimePicker);
			this->register_student_grp_box->Controls->Add(this->name_lbl);
			this->register_student_grp_box->Controls->Add(this->dob_lbl);
			this->register_student_grp_box->Controls->Add(this->profession_lbl);
			this->register_student_grp_box->Controls->Add(this->status_lbl);
			this->register_student_grp_box->Controls->Add(this->email_id_lbl);
			this->register_student_grp_box->Controls->Add(this->mobile_no_lbl);
			this->register_student_grp_box->Controls->Add(this->address_txt);
			this->register_student_grp_box->Controls->Add(this->address_lbl);
			this->register_student_grp_box->Controls->Add(this->mobile_no_txt);
			this->register_student_grp_box->Controls->Add(this->name_txt);
			this->register_student_grp_box->Controls->Add(this->email_id_txt);
			this->register_student_grp_box->Location = System::Drawing::Point(235, 51);
			this->register_student_grp_box->Name = L"register_student_grp_box";
			this->register_student_grp_box->Size = System::Drawing::Size(333, 570);
			this->register_student_grp_box->TabIndex = 17;
			this->register_student_grp_box->TabStop = false;
			this->register_student_grp_box->Text = L"Register Student";
			// 
			// profession_comboBox
			// 
			this->profession_comboBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->profession_comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->profession_comboBox->FormattingEnabled = true;
			this->profession_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Faculty", L"Alumini" });
			this->profession_comboBox->Location = System::Drawing::Point(170, 253);
			this->profession_comboBox->Name = L"profession_comboBox";
			this->profession_comboBox->Size = System::Drawing::Size(121, 21);
			this->profession_comboBox->TabIndex = 24;
			// 
			// re_password_txt
			// 
			this->re_password_txt->Location = System::Drawing::Point(172, 529);
			this->re_password_txt->Name = L"re_password_txt";
			this->re_password_txt->PasswordChar = '*';
			this->re_password_txt->Size = System::Drawing::Size(100, 20);
			this->re_password_txt->TabIndex = 23;
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(172, 479);
			this->password_txt->Name = L"password_txt";
			this->password_txt->PasswordChar = '*';
			this->password_txt->Size = System::Drawing::Size(100, 20);
			this->password_txt->TabIndex = 22;
			// 
			// password_lbl
			// 
			this->password_lbl->AutoSize = true;
			this->password_lbl->Location = System::Drawing::Point(36, 482);
			this->password_lbl->Name = L"password_lbl";
			this->password_lbl->Size = System::Drawing::Size(72, 13);
			this->password_lbl->TabIndex = 21;
			this->password_lbl->Text = L"Set Password";
			// 
			// re_password_lbl
			// 
			this->re_password_lbl->AutoSize = true;
			this->re_password_lbl->Location = System::Drawing::Point(36, 532);
			this->re_password_lbl->Name = L"re_password_lbl";
			this->re_password_lbl->Size = System::Drawing::Size(97, 13);
			this->re_password_lbl->TabIndex = 20;
			this->re_password_lbl->Text = L"Re-enter Password";
			// 
			// female_rbtn
			// 
			this->female_rbtn->AutoSize = true;
			this->female_rbtn->Location = System::Drawing::Point(170, 204);
			this->female_rbtn->Name = L"female_rbtn";
			this->female_rbtn->Size = System::Drawing::Size(59, 17);
			this->female_rbtn->TabIndex = 19;
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
			this->male_rbtn->Text = L"Male";
			this->male_rbtn->UseVisualStyleBackColor = true;
			this->male_rbtn->CheckedChanged += gcnew System::EventHandler(this, &RegisterStudent::male_rbtn_CheckedChanged);
			// 
			// RegisterStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 633);
			this->Controls->Add(this->register_student_grp_box);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->register_button);
			this->MinimumSize = System::Drawing::Size(857, 666);
			this->Name = L"RegisterStudent";
			this->Text = L"Register Student";
			this->Load += gcnew System::EventHandler(this, &RegisterStudent::RegisterStudent_Load);
			this->register_student_grp_box->ResumeLayout(false);
			this->register_student_grp_box->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RegisterStudent_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RegisterStudent_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BackButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void male_rbtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Gender = "Male";
	}
	private: System::Void female_rbtn_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Gender = "Female";
	}
	};
}
