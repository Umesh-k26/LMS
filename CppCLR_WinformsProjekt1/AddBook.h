#pragma once
#include "pch.h"
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
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddBook::typeid));
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
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(17, 49);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(35, 13);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(17, 90);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(38, 13);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(17, 134);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(50, 13);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// category_lbl
			// 
			this->category_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->category_lbl->AutoSize = true;
			this->category_lbl->Location = System::Drawing::Point(18, 177);
			this->category_lbl->Name = L"category_lbl";
			this->category_lbl->Size = System::Drawing::Size(49, 13);
			this->category_lbl->TabIndex = 3;
			this->category_lbl->Text = L"Category";
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(17, 216);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(59, 13);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// no_of_copies_lbl
			// 
			this->no_of_copies_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->no_of_copies_lbl->AutoSize = true;
			this->no_of_copies_lbl->Location = System::Drawing::Point(17, 266);
			this->no_of_copies_lbl->Name = L"no_of_copies_lbl";
			this->no_of_copies_lbl->Size = System::Drawing::Size(70, 13);
			this->no_of_copies_lbl->TabIndex = 5;
			this->no_of_copies_lbl->Text = L"No. of copies";
			// 
			// price_lbl
			// 
			this->price_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(18, 317);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(31, 13);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(167, 46);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->Size = System::Drawing::Size(100, 20);
			this->bookname_txt->TabIndex = 8;
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(167, 87);
			this->author_txt->Name = L"author_txt";
			this->author_txt->Size = System::Drawing::Size(100, 20);
			this->author_txt->TabIndex = 9;
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(167, 131);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->Size = System::Drawing::Size(100, 20);
			this->publisher_txt->TabIndex = 10;
			this->publisher_txt->TextChanged += gcnew System::EventHandler(this, &AddBook::textBox3_TextChanged);
			// 
			// category_txt
			// 
			this->category_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->category_txt->Location = System::Drawing::Point(167, 174);
			this->category_txt->Name = L"category_txt";
			this->category_txt->Size = System::Drawing::Size(100, 20);
			this->category_txt->TabIndex = 11;
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(167, 213);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->Size = System::Drawing::Size(100, 20);
			this->edition_no_txt->TabIndex = 12;
			this->edition_no_txt->TextChanged += gcnew System::EventHandler(this, &AddBook::textBox5_TextChanged);
			// 
			// no_of_copies_txt
			// 
			this->no_of_copies_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->no_of_copies_txt->Location = System::Drawing::Point(167, 263);
			this->no_of_copies_txt->Name = L"no_of_copies_txt";
			this->no_of_copies_txt->Size = System::Drawing::Size(100, 20);
			this->no_of_copies_txt->TabIndex = 13;
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(167, 314);
			this->price_txt->Name = L"price_txt";
			this->price_txt->Size = System::Drawing::Size(100, 20);
			this->price_txt->TabIndex = 14;
			// 
			// add_button
			// 
			this->add_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->add_button->Location = System::Drawing::Point(642, 221);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(121, 43);
			this->add_button->TabIndex = 16;
			this->add_button->Text = L"Add";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &AddBook::AddBook_Click);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(58, 49);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 29);
			this->button1->TabIndex = 17;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddBook::button1_Click_1);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->no_of_copies_txt);
			this->groupBox1->Controls->Add(this->bookname_lbl);
			this->groupBox1->Controls->Add(this->author_lbl);
			this->groupBox1->Controls->Add(this->price_txt);
			this->groupBox1->Controls->Add(this->publisher_lbl);
			this->groupBox1->Controls->Add(this->category_lbl);
			this->groupBox1->Controls->Add(this->edition_no_txt);
			this->groupBox1->Controls->Add(this->edition_no_lbl);
			this->groupBox1->Controls->Add(this->category_txt);
			this->groupBox1->Controls->Add(this->no_of_copies_lbl);
			this->groupBox1->Controls->Add(this->publisher_txt);
			this->groupBox1->Controls->Add(this->price_lbl);
			this->groupBox1->Controls->Add(this->author_txt);
			this->groupBox1->Controls->Add(this->bookname_txt);
			this->groupBox1->Location = System::Drawing::Point(285, 88);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(289, 360);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Add Book";
			// 
			// AddBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(846, 572);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->add_button);
			this->Name = L"AddBook";
			this->Text = L"Add Book";
			this->Load += gcnew System::EventHandler(this, &AddBook::AddBook_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void AddBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	private: System::Void AddBook_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO library_system.book_data (book_name, book_author, book_publisher, book_price,book_edition_no,no_of_copies, category) \
		VALUES('" + this->bookname_txt->Text + "',\
		'" + this->author_txt->Text + "',\
		'" + this->publisher_txt->Text + "',\
		'" + this->price_txt->Text + "',\
		'" + this->edition_no_txt->Text + "',\
		'" + this->no_of_copies_txt->Text + "',\
		'" + this->category_txt->Text + "'	);", conDataBase);


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
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
};
}
