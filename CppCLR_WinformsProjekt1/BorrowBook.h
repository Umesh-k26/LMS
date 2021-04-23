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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
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
			this->stud_id_lbl->AutoSize = true;
			this->stud_id_lbl->Location = System::Drawing::Point(312, 137);
			this->stud_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->stud_id_lbl->Name = L"stud_id_lbl";
			this->stud_id_lbl->Size = System::Drawing::Size(87, 20);
			this->stud_id_lbl->TabIndex = 0;
			this->stud_id_lbl->Text = L"Student ID";
			// 
			// book_id_lbl
			// 
			this->book_id_lbl->AutoSize = true;
			this->book_id_lbl->Location = System::Drawing::Point(312, 217);
			this->book_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->book_id_lbl->Name = L"book_id_lbl";
			this->book_id_lbl->Size = System::Drawing::Size(67, 20);
			this->book_id_lbl->TabIndex = 1;
			this->book_id_lbl->Text = L"Book ID";
			// 
			// borrow_button
			// 
			this->borrow_button->Location = System::Drawing::Point(350, 328);
			this->borrow_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->borrow_button->Name = L"borrow_button";
			this->borrow_button->Size = System::Drawing::Size(112, 35);
			this->borrow_button->TabIndex = 2;
			this->borrow_button->Text = L"Borrow ";
			this->borrow_button->UseVisualStyleBackColor = true;
			this->borrow_button->Click += gcnew System::EventHandler(this, &BorrowBook::borrow_button_Click);
			// 
			// stud_id_txt
			// 
			this->stud_id_txt->Location = System::Drawing::Point(416, 132);
			this->stud_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->stud_id_txt->Name = L"stud_id_txt";
			this->stud_id_txt->Size = System::Drawing::Size(148, 26);
			this->stud_id_txt->TabIndex = 3;
			// 
			// book_id_txt
			// 
			this->book_id_txt->Location = System::Drawing::Point(416, 212);
			this->book_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->Size = System::Drawing::Size(148, 26);
			this->book_id_txt->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(78, 65);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(51, 45);
			this->button1->TabIndex = 16;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BorrowBook::button1_Click);
			// 
			// BorrowBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(921, 649);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->book_id_txt);
			this->Controls->Add(this->stud_id_txt);
			this->Controls->Add(this->borrow_button);
			this->Controls->Add(this->book_id_lbl);
			this->Controls->Add(this->stud_id_lbl);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"BorrowBook";
			this->Text = L"BorrowBook";
			this->Load += gcnew System::EventHandler(this, &BorrowBook::BorrowBook_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
