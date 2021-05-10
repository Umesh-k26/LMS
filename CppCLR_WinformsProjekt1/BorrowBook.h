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
		System::ComponentModel::Container^ components;

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
			this->stud_id_lbl->Location = System::Drawing::Point(96, 63);
			this->stud_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->stud_id_lbl->Name = L"stud_id_lbl";
			this->stud_id_lbl->Size = System::Drawing::Size(87, 20);
			this->stud_id_lbl->TabIndex = 0;
			this->stud_id_lbl->Text = L"Student ID";
			// 
			// book_id_lbl
			// 
			this->book_id_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_id_lbl->AutoSize = true;
			this->book_id_lbl->Location = System::Drawing::Point(96, 149);
			this->book_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->book_id_lbl->Name = L"book_id_lbl";
			this->book_id_lbl->Size = System::Drawing::Size(67, 20);
			this->book_id_lbl->TabIndex = 1;
			this->book_id_lbl->Text = L"Book ID";
			// 
			// borrow_button
			// 
			this->borrow_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrow_button->Location = System::Drawing::Point(176, 246);
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
			this->stud_id_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->stud_id_txt->Location = System::Drawing::Point(219, 58);
			this->stud_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->stud_id_txt->Name = L"stud_id_txt";
			this->stud_id_txt->Size = System::Drawing::Size(148, 26);
			this->stud_id_txt->TabIndex = 3;
			this->stud_id_txt->TextChanged += gcnew System::EventHandler(this, &BorrowBook::stud_id_txt_TextChanged);
			// 
			// book_id_txt
			// 
			this->book_id_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->book_id_txt->Location = System::Drawing::Point(219, 145);
			this->book_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->Size = System::Drawing::Size(148, 26);
			this->book_id_txt->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(78, 65);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(51, 45);
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
			this->groupBox1->Location = System::Drawing::Point(244, 188);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(480, 340);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Borrow Book";
			// 
			// BorrowBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 728);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(991, 758);
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

		String^ Book_status;
		String^ Book_name;
		String^ Book_author;
		String^ Book_publisher;
		int Book_edition_no;
		int copies_available;

		String^ constring = L"datasource=localhost;port=3306;username=root;password=25081998@nikhil";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT * FROM library_system.student_data WHERE student_id = '" + this->stud_id_txt->Text + "';", conDataBase);
		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT * FROM library_system.book_data WHERE book_id = '" + this->book_id_txt->Text + "';", conDataBase);
		MySqlCommand^ cmdDataBase3 = gcnew MySqlCommand("UPDATE  library_system.book_data set book_borrow_status = 'BORROWED' WHERE book_id ='" + this->book_id_txt->Text + "' ;", conDataBase);


		MySqlCommand^ cmdDataBase5 = gcnew MySqlCommand("INSERT INTO library_system.borrow_history \
		(book_id, student_id,date_issue) \
		VALUES('" + this->book_id_txt->Text + "',\
		'" + this->stud_id_txt->Text + "',\
		CURDATE());", conDataBase);

		MySqlCommand^ cmdDataBase6 = gcnew MySqlCommand("SELECT * FROM  library_system.borrow_history \
			WHERE  book_id ='" + this->book_id_txt->Text + "'\
            AND student_id = '" + this->stud_id_txt->Text + "'\
			AND date_issue = CURDATE()\
			; ", conDataBase);

		MySqlDataReader^ myReader, ^ Readdd;


		try {
			conDataBase->Open();
			myReader = cmdDataBase1->ExecuteReader();

			int count1 = 0, count2 = 0;
			while (myReader->Read())
			{
				count1 += 1;
			}
			if (count1 == 0)
			{
				MessageBox::Show("Student not found with given student id .");
			}
			else if (count1 == 1)
			{
				myReader->Close();
				myReader = cmdDataBase2->ExecuteReader();

				while (myReader->Read())
				{
					count2 += 1;
					Book_status = myReader->GetString("book_borrow_status");
					Book_name = myReader->GetString("book_name");
					Book_author = myReader->GetString("book_author");
					Book_publisher = myReader->GetString("book_publisher");
					Book_edition_no = myReader->GetInt32("book_edition_no");
					copies_available = myReader->GetInt32("copies_available");
				}
				if (count2 == 0)
				{
					MessageBox::Show("Book not found with given book id .");
				}
				else if (count2 == 1)
				{
					if (Book_status == "AVAILABLE")
					{

						myReader->Close();
						cmdDataBase3->ExecuteNonQuery(); //updates borrow_status(coloumn) in book data (table)
						cmdDataBase5->ExecuteNonQuery(); //updates borrow_history(table) inserts new row for this order

						MySqlCommand^ cmdDataBase4 = gcnew MySqlCommand("UPDATE  library_system.book_data set copies_available = copies_available -1 WHERE book_name ='" + Book_name + "'\
                             AND book_author ='" + Book_author + "' \
                             AND book_publisher ='" + Book_publisher + "'\
                             AND book_edition_no ='" + Book_edition_no + "' \
                             ;", conDataBase);

						cmdDataBase4->ExecuteNonQuery(); // updates copies__available(coloumn) in book data (table)

						myReader = cmdDataBase6->ExecuteReader();

						int orderid;

						while (myReader->Read())
						{
							orderid = myReader->GetInt32("order_id");
						}
						MessageBox::Show("Borrowed book successfully! \n book_id = '" + this->book_id_txt->Text + "',student_id = '" + this->stud_id_txt->Text + "',order_id = " + orderid);
						myReader->Close();


					}


					else if (Book_status == "BORROWED")
					{
						if (copies_available > 0)
							MessageBox::Show("Same Book is available , but with different book id");
						else if (copies_available == 0)
							MessageBox::Show("Book is Not available ");

					}

				}

				else if (count2 > 1)
					MessageBox::Show("Duplicate ID's of same book_id detected. Please resolve before updating.");

			}
			else if (count1 > 1)
				MessageBox::Show("Duplicate ID's of same student_id detected. Please resolve before updating.");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}


	}
	private: System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void stud_id_txt_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {
	}
	};
	}
