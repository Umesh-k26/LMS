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
	/// Summary for ReturnBook
	/// </summary>
	public ref class ReturnBook : public System::Windows::Forms::Form
	{
	public:
		ReturnBook(void)
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
		~ReturnBook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ order_id_lbl;
	protected:
	private: System::Windows::Forms::TextBox^ order_id_txt;
	private: System::Windows::Forms::Button^ return_button;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReturnBook::typeid));
			this->order_id_lbl = (gcnew System::Windows::Forms::Label());
			this->order_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->return_button = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// order_id_lbl
			// 
			this->order_id_lbl->AutoSize = true;
			this->order_id_lbl->Location = System::Drawing::Point(459, 197);
			this->order_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->order_id_lbl->Name = L"order_id_lbl";
			this->order_id_lbl->Size = System::Drawing::Size(70, 20);
			this->order_id_lbl->TabIndex = 0;
			this->order_id_lbl->Text = L"Order ID";
			// 
			// order_id_txt
			// 
			this->order_id_txt->Location = System::Drawing::Point(652, 192);
			this->order_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->order_id_txt->Name = L"order_id_txt";
			this->order_id_txt->Size = System::Drawing::Size(148, 26);
			this->order_id_txt->TabIndex = 1;
			this->order_id_txt->TextChanged += gcnew System::EventHandler(this, &ReturnBook::order_id_txt_TextChanged);
			// 
			// return_button
			// 
			this->return_button->Location = System::Drawing::Point(552, 428);
			this->return_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->return_button->Name = L"return_button";
			this->return_button->Size = System::Drawing::Size(112, 35);
			this->return_button->TabIndex = 2;
			this->return_button->Text = L"Return ";
			this->return_button->UseVisualStyleBackColor = true;
			this->return_button->Click += gcnew System::EventHandler(this, &ReturnBook::return_button_Click);
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(105, 85);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(51, 38);
			this->button1->TabIndex = 16;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ReturnBook::button1_Click);
			// 
			// ReturnBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1144, 834);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->return_button);
			this->Controls->Add(this->order_id_txt);
			this->Controls->Add(this->order_id_lbl);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"ReturnBook";
			this->Text = L"ReturnBook";
			this->Load += gcnew System::EventHandler(this, &ReturnBook::ReturnBook_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ReturnBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void return_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);
		MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("UPDATE library_system.borrow_history set \
        date_returned = CURDATE(),borrow_fine = 0,borrow_status = 'RETURNED'\
		WHERE order_id = '" + this->order_id_txt->Text + "';", conDataBase);

		MySqlCommand^ cmdDataBase3;

		MySqlDataReader^ myReader;

		int Book_id;
		int Student_id;
		String^ Book_name;
		String^ Book_author;
		String^ Book_publisher;
		int Book_edition_no;

		try {
			conDataBase->Open();
			myReader = cmdDataBase1->ExecuteReader();

			int count = 0;
			String^ Borrow_status;

			while (myReader->Read())
			{
				count += 1;
				Borrow_status = myReader->GetString("borrow_status");
				Book_id = myReader->GetInt32("book_id");
				Student_id = myReader->GetInt32("student_id");
			}
			myReader->Close();
			if (count == 0)
			{
				MessageBox::Show("Order not found with given Order id .");
			}
			else if (count == 1)
			{
				if (Borrow_status == "RETURNED")
					MessageBox::Show("Book with given Order id is already Returned! .Please resolve if any before updating");

				else if (Borrow_status = "BORROWED")
				{
					cmdDataBase3 = gcnew MySqlCommand("SELECT * FROM library_system.book_data WHERE book_id ='" + Book_id + "';", conDataBase);

					int count1 = 0;
					myReader = cmdDataBase3->ExecuteReader();
					while (myReader->Read())
					{
						count1 += 1;
						Book_name = myReader->GetString("book_name");
						Book_author = myReader->GetString("book_author");
						Book_publisher = myReader->GetString("book_publisher");
						Book_edition_no = myReader->GetInt32("book_edition_no");
					}
					myReader->Close();
					if (count1 == 0)
						MessageBox::Show("Book id of Borrowed book with given order_id is not found. Please resolve before updating.");
					else if (count1 == 1)
					{
						MySqlCommand^ cmdDataBase4 = gcnew MySqlCommand("UPDATE library_system.book_data set copies_available = copies_available +1 WHERE \
                      book_name = '" + Book_name + "'\
                      AND book_author = '" + Book_author + "'\
                      AND book_publisher = '" + Book_publisher + "'\
                      AND book_edition_no = " + Book_edition_no + "\
                      ; UPDATE library_system.book_data set book_borrow_status = 'AVAILABLE' WHERE book_id = " + Book_id + " ;", conDataBase);

						MySqlCommand^ cmdDataBase5 = gcnew MySqlCommand("UPDATE  library_system.student_data\
                     set student_no_book_stat = student_no_book_stat - 1 \
                     WHERE student_id ='" + Student_id + "';", conDataBase);

						//Below Query Updates Borrow_history (Table)
						cmdDataBase2->ExecuteNonQuery();

						//Below Query Updates student_data(Table)
						cmdDataBase5->ExecuteNonQuery();

						//Below Query Updates Book_data (Table) {increases copies_available by 1 for all copies and book_borrow_Status = AVAILABLE for partciular book id}
						cmdDataBase4->ExecuteNonQuery();

						MessageBox::Show("Returned book successfully! \n book_id = " + Book_id + ",student_id = " + Student_id + ",order_id = " + this->order_id_txt->Text + " ");
					}
					else if (count1 > 1)
						MessageBox::Show("Duplicate ID's of same book_id detected. Please resolve before updating.");

				}
				else
					MessageBox::Show("borrow_status is neither 'BORROWED' nor 'RETURNED' of given order_id, detected. Please resolve before updating.");
			}
			else if (count > 1)
				MessageBox::Show("Duplicate ID's of same order_id detected. Please resolve before updating.");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
	private: System::Void order_id_txt_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
