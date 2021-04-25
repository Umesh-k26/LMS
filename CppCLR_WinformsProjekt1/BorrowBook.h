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
	/// Summary for BorrowBook
	/// </summary>
	public ref class BorrowBook : public System::Windows::Forms::Form
	{
	public:
		BorrowBook(void)
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
		~BorrowBook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;
	private: System::Windows::Forms::TextBox^ book_id_txt;
	private: System::Windows::Forms::TextBox^ stud_id_txt;
	private: System::Windows::Forms::Button^ borrow_button;
	private: System::Windows::Forms::Label^ book_id_lbl;
	private: System::Windows::Forms::Label^ stud_id_lbl;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BorrowBook::typeid));
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->stud_id_lbl = (gcnew System::Windows::Forms::Label());
			this->book_id_lbl = (gcnew System::Windows::Forms::Label());
			this->borrow_button = (gcnew System::Windows::Forms::Button());
			this->stud_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->book_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			this->fileSystemWatcher1->Changed += gcnew System::IO::FileSystemEventHandler(this, &BorrowBook::fileSystemWatcher1_Changed);
			// 
			// stud_id_lbl
			// 
			this->stud_id_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->stud_id_lbl->AutoSize = true;
			this->stud_id_lbl->Location = System::Drawing::Point(64, 41);
			this->stud_id_lbl->Name = L"stud_id_lbl";
			this->stud_id_lbl->Size = System::Drawing::Size(58, 13);
			this->stud_id_lbl->TabIndex = 0;
			this->stud_id_lbl->Text = L"Student ID";
			// 
			// book_id_lbl
			// 
			this->book_id_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_id_lbl->AutoSize = true;
			this->book_id_lbl->Location = System::Drawing::Point(64, 97);
			this->book_id_lbl->Name = L"book_id_lbl";
			this->book_id_lbl->Size = System::Drawing::Size(46, 13);
			this->book_id_lbl->TabIndex = 1;
			this->book_id_lbl->Text = L"Book ID";
			// 
			// borrow_button
			// 
			this->borrow_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrow_button->Location = System::Drawing::Point(117, 160);
			this->borrow_button->Name = L"borrow_button";
			this->borrow_button->Size = System::Drawing::Size(75, 23);
			this->borrow_button->TabIndex = 2;
			this->borrow_button->Text = L"Borrow ";
			this->borrow_button->UseVisualStyleBackColor = true;
			this->borrow_button->Click += gcnew System::EventHandler(this, &BorrowBook::borrow_button_Click);
			// 
			// stud_id_txt
			// 
			this->stud_id_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->stud_id_txt->Location = System::Drawing::Point(146, 38);
			this->stud_id_txt->Name = L"stud_id_txt";
			this->stud_id_txt->Size = System::Drawing::Size(100, 20);
			this->stud_id_txt->TabIndex = 3;
			// 
			// book_id_txt
			// 
			this->book_id_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_id_txt->Location = System::Drawing::Point(146, 94);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->Size = System::Drawing::Size(100, 20);
			this->book_id_txt->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(52, 42);
			this->button1->Margin = System::Windows::Forms::Padding(1, 1, 1, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(34, 29);
			this->button1->TabIndex = 16;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BorrowBook::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->borrow_button);
			this->groupBox1->Controls->Add(this->stud_id_lbl);
			this->groupBox1->Controls->Add(this->book_id_txt);
			this->groupBox1->Controls->Add(this->book_id_lbl);
			this->groupBox1->Controls->Add(this->stud_id_txt);
			this->groupBox1->Location = System::Drawing::Point(163, 122);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(320, 221);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Borrow Book";
			// 
			// BorrowBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(652, 473);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->MinimumSize = System::Drawing::Size(668, 512);
			this->Name = L"BorrowBook";
			this->Text = L"Borrow Book";
			this->Load += gcnew System::EventHandler(this, &BorrowBook::BorrowBook_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
	}
	private: System::Void BorrowBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	private: System::Void borrow_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
};
}
