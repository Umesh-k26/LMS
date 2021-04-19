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
	/// Summary for AddBook
	/// </summary>
	public ref class AddBook : public System::Windows::Forms::Form
	{
	public:
		AddBook(void)
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
		~AddBook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ bookname_lbl;
	private: System::Windows::Forms::Label^ author_lbl;
	private: System::Windows::Forms::Label^ publisher_lbl;
	private: System::Windows::Forms::Label^ category_lbl;
	private: System::Windows::Forms::Label^ edition_no_lbl;
	private: System::Windows::Forms::Label^ no_of_copies_lbl;
	private: System::Windows::Forms::Label^ price_lbl;
	private: System::Windows::Forms::TextBox^ bookname_txt;
	private: System::Windows::Forms::TextBox^ author_txt;
	private: System::Windows::Forms::TextBox^ publisher_txt;
	private: System::Windows::Forms::TextBox^ category_txt;
	private: System::Windows::Forms::TextBox^ edition_no_txt;
	private: System::Windows::Forms::TextBox^ no_of_copies_txt;
	private: System::Windows::Forms::TextBox^ price_txt;
	protected:

	protected:















	private: System::Windows::Forms::Button^ button1;

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
			this->bookname_lbl = (gcnew System::Windows::Forms::Label());
			this->author_lbl = (gcnew System::Windows::Forms::Label());
			this->publisher_lbl = (gcnew System::Windows::Forms::Label());
			this->category_lbl = (gcnew System::Windows::Forms::Label());
			this->edition_no_lbl = (gcnew System::Windows::Forms::Label());
			this->no_of_copies_lbl = (gcnew System::Windows::Forms::Label());
			this->price_lbl = (gcnew System::Windows::Forms::Label());
			this->bookname_txt = (gcnew System::Windows::Forms::TextBox());
			this->author_txt = (gcnew System::Windows::Forms::TextBox());
			this->publisher_txt = (gcnew System::Windows::Forms::TextBox());
			this->category_txt = (gcnew System::Windows::Forms::TextBox());
			this->edition_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->no_of_copies_txt = (gcnew System::Windows::Forms::TextBox());
			this->price_txt = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(245, 120);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(35, 13);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(245, 161);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(38, 13);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(245, 205);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(50, 13);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// category_lbl
			// 
			this->category_lbl->AutoSize = true;
			this->category_lbl->Location = System::Drawing::Point(246, 248);
			this->category_lbl->Name = L"category_lbl";
			this->category_lbl->Size = System::Drawing::Size(49, 13);
			this->category_lbl->TabIndex = 3;
			this->category_lbl->Text = L"Category";
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(245, 287);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(59, 13);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// no_of_copies_lbl
			// 
			this->no_of_copies_lbl->AutoSize = true;
			this->no_of_copies_lbl->Location = System::Drawing::Point(245, 337);
			this->no_of_copies_lbl->Name = L"no_of_copies_lbl";
			this->no_of_copies_lbl->Size = System::Drawing::Size(70, 13);
			this->no_of_copies_lbl->TabIndex = 5;
			this->no_of_copies_lbl->Text = L"No. of copies";
			// 
			// price_lbl
			// 
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(246, 388);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(31, 13);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// bookname_txt
			// 
			this->bookname_txt->Location = System::Drawing::Point(395, 117);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->Size = System::Drawing::Size(100, 20);
			this->bookname_txt->TabIndex = 8;
			// 
			// author_txt
			// 
			this->author_txt->Location = System::Drawing::Point(395, 158);
			this->author_txt->Name = L"author_txt";
			this->author_txt->Size = System::Drawing::Size(100, 20);
			this->author_txt->TabIndex = 9;
			// 
			// publisher_txt
			// 
			this->publisher_txt->Location = System::Drawing::Point(395, 202);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->Size = System::Drawing::Size(100, 20);
			this->publisher_txt->TabIndex = 10;
			this->publisher_txt->TextChanged += gcnew System::EventHandler(this, &AddBook::textBox3_TextChanged);
			// 
			// category_txt
			// 
			this->category_txt->Location = System::Drawing::Point(395, 245);
			this->category_txt->Name = L"category_txt";
			this->category_txt->Size = System::Drawing::Size(100, 20);
			this->category_txt->TabIndex = 11;
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Location = System::Drawing::Point(395, 284);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->Size = System::Drawing::Size(100, 20);
			this->edition_no_txt->TabIndex = 12;
			this->edition_no_txt->TextChanged += gcnew System::EventHandler(this, &AddBook::textBox5_TextChanged);
			// 
			// no_of_copies_txt
			// 
			this->no_of_copies_txt->Location = System::Drawing::Point(395, 334);
			this->no_of_copies_txt->Name = L"no_of_copies_txt";
			this->no_of_copies_txt->Size = System::Drawing::Size(100, 20);
			this->no_of_copies_txt->TabIndex = 13;
			// 
			// price_txt
			// 
			this->price_txt->Location = System::Drawing::Point(395, 385);
			this->price_txt->Name = L"price_txt";
			this->price_txt->Size = System::Drawing::Size(100, 20);
			this->price_txt->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(642, 221);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 43);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddBook::button1_Click);
			// 
			// AddBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 572);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->price_txt);
			this->Controls->Add(this->no_of_copies_txt);
			this->Controls->Add(this->edition_no_txt);
			this->Controls->Add(this->category_txt);
			this->Controls->Add(this->publisher_txt);
			this->Controls->Add(this->author_txt);
			this->Controls->Add(this->bookname_txt);
			this->Controls->Add(this->price_lbl);
			this->Controls->Add(this->no_of_copies_lbl);
			this->Controls->Add(this->edition_no_lbl);
			this->Controls->Add(this->category_lbl);
			this->Controls->Add(this->publisher_lbl);
			this->Controls->Add(this->author_lbl);
			this->Controls->Add(this->bookname_lbl);
			this->Name = L"AddBook";
			this->Text = L"AddBook";
			this->Load += gcnew System::EventHandler(this, &AddBook::AddBook_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void AddBook_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO 'library_system'.'book_data' ('book_name', 'book_author', 'book_publisher', 'book_price','book_edition_no','no_of_copies', 'category') \
		VALUES('" + this->bookname_txt->Text + "',\
		'" + this->author_txt->Text + "',\
		'" + this->publisher_txt->Text + "',\
		'" + this->price_txt->Text + "',\
		" + this->edition_no_txt->Text + "',\
		'" + this->no_of_copies_txt->Text + "',\
		'" + this->category_txt->Text + "'	;", conDataBase);


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
	};
}
