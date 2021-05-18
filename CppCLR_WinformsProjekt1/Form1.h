#pragma once
//#include "sdf.h"
#include "pch.h"
#include "Form2.h"
#include "connection_sql_func.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
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
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
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
			this->login_button->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
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
			this->username_lbl->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
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
			this->password_lbl->Click += gcnew System::EventHandler(this, &Form1::password_lbl_Click);
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(709, 585);
			this->Controls->Add(this->SignIn_box);
			this->MinimumSize = System::Drawing::Size(725, 624);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->SignIn_box->ResumeLayout(false);
			this->SignIn_box->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{

		String^ constring;
		constring = sql_connection_func::sql_user_pass_string();

		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE \
	    username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			int count = 0;
			while (myReader->Read())
			{
				count += 1;
			}
			if (count == 1)
			{
				MessageBox::Show("Username and password is correct");

				CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
				this->Hide();
				if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					this->username_txt->Text = "";
					this->password_txt->Text = "";
					this->Show();

				}

			}
			else if (count > 1)
			{
				MessageBox::Show("Duplicate username and password ...Access denied");
			}
			else
				MessageBox::Show("Username and password is incorrect ...Please try again");


		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}




		/*MessageBox::Show(L"Your employment application appears to be incomplete"
			 L"\nPlease complete it first before clicking Resume",
			 L"Georgetown Dry Cleaning Services",
			 MessageBoxButtons::OK, MessageBoxIcon::Information);
		*/
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void password_lbl_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Form1_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	}
	};
}
