#pragma once

namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for profile_book
	/// </summary>
	public ref class profile_book : public System::Windows::Forms::Form
	{
	public:
		String^ transfer_id_book;
	public:
		profile_book(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		profile_book(String^ label_book_id)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			transfer_id_book = label_book_id;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~profile_book()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ bookname_lbl;
	private: System::Windows::Forms::Label^ author_lbl;
	private: System::Windows::Forms::TextBox^ price_txt;
	private: System::Windows::Forms::Label^ publisher_lbl;
	private: System::Windows::Forms::TextBox^ edition_no_txt;
	private: System::Windows::Forms::Label^ edition_no_lbl;
	private: System::Windows::Forms::TextBox^ publisher_txt;
	private: System::Windows::Forms::Label^ price_lbl;
	private: System::Windows::Forms::TextBox^ author_txt;
	private: System::Windows::Forms::TextBox^ bookname_txt;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->bookname_lbl = (gcnew System::Windows::Forms::Label());
			this->author_lbl = (gcnew System::Windows::Forms::Label());
			this->price_txt = (gcnew System::Windows::Forms::TextBox());
			this->publisher_lbl = (gcnew System::Windows::Forms::Label());
			this->edition_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->edition_no_lbl = (gcnew System::Windows::Forms::Label());
			this->publisher_txt = (gcnew System::Windows::Forms::TextBox());
			this->price_lbl = (gcnew System::Windows::Forms::Label());
			this->author_txt = (gcnew System::Windows::Forms::TextBox());
			this->bookname_txt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->bookname_lbl);
			this->groupBox1->Controls->Add(this->author_lbl);
			this->groupBox1->Controls->Add(this->price_txt);
			this->groupBox1->Controls->Add(this->publisher_lbl);
			this->groupBox1->Controls->Add(this->edition_no_txt);
			this->groupBox1->Controls->Add(this->edition_no_lbl);
			this->groupBox1->Controls->Add(this->publisher_txt);
			this->groupBox1->Controls->Add(this->price_lbl);
			this->groupBox1->Controls->Add(this->author_txt);
			this->groupBox1->Controls->Add(this->bookname_txt);
			this->groupBox1->Location = System::Drawing::Point(294, 51);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(434, 554);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Add Book";
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(26, 75);
			this->bookname_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(51, 20);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(26, 138);
			this->author_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(57, 20);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(250, 483);
			this->price_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->price_txt->Name = L"price_txt";
			this->price_txt->ReadOnly = true;
			this->price_txt->Size = System::Drawing::Size(148, 26);
			this->price_txt->TabIndex = 14;
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(26, 206);
			this->publisher_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(74, 20);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(250, 328);
			this->edition_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->ReadOnly = true;
			this->edition_no_txt->Size = System::Drawing::Size(148, 26);
			this->edition_no_txt->TabIndex = 12;
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(26, 332);
			this->edition_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(86, 20);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(250, 202);
			this->publisher_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->ReadOnly = true;
			this->publisher_txt->Size = System::Drawing::Size(148, 26);
			this->publisher_txt->TabIndex = 10;
			// 
			// price_lbl
			// 
			this->price_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(27, 488);
			this->price_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(44, 20);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(250, 134);
			this->author_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->author_txt->Name = L"author_txt";
			this->author_txt->ReadOnly = true;
			this->author_txt->Size = System::Drawing::Size(148, 26);
			this->author_txt->TabIndex = 9;
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(250, 71);
			this->bookname_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->ReadOnly = true;
			this->bookname_txt->Size = System::Drawing::Size(148, 26);
			this->bookname_txt->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 20);
			this->label1->TabIndex = 20;
			this->label1->Text = L"ID";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(240, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(157, 26);
			this->textBox1->TabIndex = 21;
			// 
			// profile_book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1023, 645);
			this->Controls->Add(this->groupBox1);
			this->Name = L"profile_book";
			this->Text = L"profile_book";
			this->Load += gcnew System::EventHandler(this, &profile_book::profile_book_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void profile_book_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.book_data\
		WHERE book_id = " + transfer_id_book + ";", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_name;
				String^ printing_id;
				String^ printing_author;
				String^ printing_publisher;
				String^ printing_price;
				String^ printing_edition_no;
				printing_id = myReader->GetString("book_id");
				printing_name = myReader->GetString("book_name");
				printing_author = myReader->GetString("book_author");
				printing_publisher = myReader->GetString("book_publisher");
				printing_price = myReader->GetString("book_price");
				printing_edition_no= myReader->GetString("book_edition_no");
				this->bookname_txt->Text = printing_name;
				this->textBox1->Text = printing_id;
				this->author_txt->Text = printing_author;
				this->publisher_txt->Text = printing_publisher;
				this->price_txt->Text = printing_price;
				this->edition_no_txt->Text = printing_edition_no;

				//listBox1->Items->Add(printing_names);

			}

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
	};
}
