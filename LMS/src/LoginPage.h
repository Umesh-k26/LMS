#pragma once

#include "pch.h"

namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class LoginPage : public System::Windows::Forms::Form
	{
	public:
		LoginPage(void);

	protected:
		~LoginPage();

	private: System::Windows::Forms::Button^ login_button;
	protected:

	private: System::Windows::Forms::TextBox^ username_txt;
	private: System::Windows::Forms::TextBox^ password_txt;
	protected:

	protected:



	private: System::Windows::Forms::Label^ username_lbl;
	private: System::Windows::Forms::Label^ password_lbl;
	private: System::Windows::Forms::GroupBox^ SignIn_box;


	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->username_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->username_lbl = (gcnew System::Windows::Forms::Label());
			this->password_lbl = (gcnew System::Windows::Forms::Label());
			this->SignIn_box = (gcnew System::Windows::Forms::GroupBox());
			this->SignIn_box->SuspendLayout();
			this->SuspendLayout();
			// 
			// login_button
			// 
			this->login_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->login_button->Location = System::Drawing::Point(126, 181);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(76, 28);
			this->login_button->TabIndex = 0;
			this->login_button->Text = L"Login";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &LoginPage::LoginButton_Click);
			// 
			// username_txt
			// 
			this->username_txt->Location = System::Drawing::Point(182, 68);
			this->username_txt->Name = L"username_txt";
			this->username_txt->Size = System::Drawing::Size(100, 20);
			this->username_txt->TabIndex = 1;
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(182, 118);
			this->password_txt->Name = L"password_txt";
			this->password_txt->PasswordChar = '*';
			this->password_txt->Size = System::Drawing::Size(100, 20);
			this->password_txt->TabIndex = 2;
			// 
			// username_lbl
			// 
			this->username_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->username_lbl->AutoSize = true;
			this->username_lbl->Location = System::Drawing::Point(72, 68);
			this->username_lbl->Name = L"username_lbl";
			this->username_lbl->Size = System::Drawing::Size(55, 13);
			this->username_lbl->TabIndex = 5;
			this->username_lbl->Text = L"Username";
			// 
			// password_lbl
			// 
			this->password_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->password_lbl->AutoSize = true;
			this->password_lbl->Location = System::Drawing::Point(72, 121);
			this->password_lbl->Name = L"password_lbl";
			this->password_lbl->Size = System::Drawing::Size(53, 13);
			this->password_lbl->TabIndex = 6;
			this->password_lbl->Text = L"Password";
			// 
			// SignIn_box
			// 
			this->SignIn_box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SignIn_box->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->SignIn_box->Controls->Add(this->login_button);
			this->SignIn_box->Controls->Add(this->password_lbl);
			this->SignIn_box->Controls->Add(this->username_txt);
			this->SignIn_box->Controls->Add(this->username_lbl);
			this->SignIn_box->Controls->Add(this->password_txt);
			this->SignIn_box->Location = System::Drawing::Point(170, 156);
			this->SignIn_box->Name = L"SignIn_box";
			this->SignIn_box->Size = System::Drawing::Size(349, 261);
			this->SignIn_box->TabIndex = 7;
			this->SignIn_box->TabStop = false;
			this->SignIn_box->Text = L"Sign In";
			// 
			// LoginPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(709, 585);
			this->Controls->Add(this->SignIn_box);
			this->MinimumSize = System::Drawing::Size(725, 624);
			this->Name = L"LoginPage";
			this->Text = L"LoginPage";
			this->Load += gcnew System::EventHandler(this, &LoginPage::LoginPage_Load);
			this->SignIn_box->ResumeLayout(false);
			this->SignIn_box->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoginButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LoginPage_Load(System::Object^ sender, System::EventArgs^ e);

	};
}
