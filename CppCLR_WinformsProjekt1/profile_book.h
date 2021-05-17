#pragma once
#include "connection_sql_func.h"
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
			//fill_data_grid();
		}
		profile_book(String^ label_book_id)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			transfer_id_book = label_book_id;
			//fill_data_grid();
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
	private: System::Windows::Forms::TextBox^ book_id_txt;
	protected:

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
	private: System::Windows::Forms::Button^ update_profile_button;
	private: System::Windows::Forms::Button^ delete_profile_button;
	private: System::Windows::Forms::Button^ confirm_change_button;
	private: System::Windows::Forms::TextBox^ borrow_stat_txt;
	private: System::Windows::Forms::Label^ borrow_stat_lbl;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: System::Windows::Forms::TextBox^ no_copies_txt;
	private: System::Windows::Forms::Label^ no_copies_lbl;
	private: System::Windows::Forms::Button^ back_button;
	private: System::Windows::Forms::NumericUpDown^ numeric_updown_no_copies;
	private: System::Windows::Forms::TextBox^ category_txt;
	private: System::Windows::Forms::Label^ category_lbl;













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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(profile_book::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->category_txt = (gcnew System::Windows::Forms::TextBox());
			this->category_lbl = (gcnew System::Windows::Forms::Label());
			this->no_copies_lbl = (gcnew System::Windows::Forms::Label());
			this->no_copies_txt = (gcnew System::Windows::Forms::TextBox());
			this->borrow_stat_txt = (gcnew System::Windows::Forms::TextBox());
			this->borrow_stat_lbl = (gcnew System::Windows::Forms::Label());
			this->book_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->update_profile_button = (gcnew System::Windows::Forms::Button());
			this->delete_profile_button = (gcnew System::Windows::Forms::Button());
			this->confirm_change_button = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Open = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->numeric_updown_no_copies = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_updown_no_copies))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->category_txt);
			this->groupBox1->Controls->Add(this->category_lbl);
			this->groupBox1->Controls->Add(this->no_copies_lbl);
			this->groupBox1->Controls->Add(this->no_copies_txt);
			this->groupBox1->Controls->Add(this->borrow_stat_txt);
			this->groupBox1->Controls->Add(this->borrow_stat_lbl);
			this->groupBox1->Controls->Add(this->book_id_txt);
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
			this->groupBox1->Location = System::Drawing::Point(490, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(289, 372);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Book Profile";
			// 
			// category_txt
			// 
			this->category_txt->Location = System::Drawing::Point(167, 287);
			this->category_txt->Margin = System::Windows::Forms::Padding(2);
			this->category_txt->Name = L"category_txt";
			this->category_txt->ReadOnly = true;
			this->category_txt->Size = System::Drawing::Size(100, 20);
			this->category_txt->TabIndex = 27;
			// 
			// category_lbl
			// 
			this->category_lbl->AutoSize = true;
			this->category_lbl->Location = System::Drawing::Point(20, 290);
			this->category_lbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->category_lbl->Name = L"category_lbl";
			this->category_lbl->Size = System::Drawing::Size(49, 13);
			this->category_lbl->TabIndex = 26;
			this->category_lbl->Text = L"Category";
			// 
			// no_copies_lbl
			// 
			this->no_copies_lbl->AutoSize = true;
			this->no_copies_lbl->Location = System::Drawing::Point(17, 257);
			this->no_copies_lbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->no_copies_lbl->Name = L"no_copies_lbl";
			this->no_copies_lbl->Size = System::Drawing::Size(70, 13);
			this->no_copies_lbl->TabIndex = 25;
			this->no_copies_lbl->Text = L"No. of copies";
			// 
			// no_copies_txt
			// 
			this->no_copies_txt->Location = System::Drawing::Point(167, 257);
			this->no_copies_txt->Margin = System::Windows::Forms::Padding(2);
			this->no_copies_txt->Name = L"no_copies_txt";
			this->no_copies_txt->ReadOnly = true;
			this->no_copies_txt->Size = System::Drawing::Size(100, 20);
			this->no_copies_txt->TabIndex = 24;
			// 
			// borrow_stat_txt
			// 
			this->borrow_stat_txt->Location = System::Drawing::Point(167, 168);
			this->borrow_stat_txt->Margin = System::Windows::Forms::Padding(2);
			this->borrow_stat_txt->Name = L"borrow_stat_txt";
			this->borrow_stat_txt->ReadOnly = true;
			this->borrow_stat_txt->Size = System::Drawing::Size(99, 20);
			this->borrow_stat_txt->TabIndex = 23;
			// 
			// borrow_stat_lbl
			// 
			this->borrow_stat_lbl->AutoSize = true;
			this->borrow_stat_lbl->Location = System::Drawing::Point(17, 170);
			this->borrow_stat_lbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->borrow_stat_lbl->Name = L"borrow_stat_lbl";
			this->borrow_stat_lbl->Size = System::Drawing::Size(73, 13);
			this->borrow_stat_lbl->TabIndex = 22;
			this->borrow_stat_lbl->Text = L"Borrow Status";
			// 
			// book_id_txt
			// 
			this->book_id_txt->Location = System::Drawing::Point(160, 17);
			this->book_id_txt->Margin = System::Windows::Forms::Padding(2);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->ReadOnly = true;
			this->book_id_txt->Size = System::Drawing::Size(106, 20);
			this->book_id_txt->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 23);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"ID";
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(17, 55);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(35, 13);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(17, 96);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(38, 13);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(167, 320);
			this->price_txt->Name = L"price_txt";
			this->price_txt->ReadOnly = true;
			this->price_txt->Size = System::Drawing::Size(100, 20);
			this->price_txt->TabIndex = 14;
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(17, 140);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(50, 13);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(167, 219);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->ReadOnly = true;
			this->edition_no_txt->Size = System::Drawing::Size(100, 20);
			this->edition_no_txt->TabIndex = 12;
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(17, 222);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(59, 13);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(167, 137);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->ReadOnly = true;
			this->publisher_txt->Size = System::Drawing::Size(100, 20);
			this->publisher_txt->TabIndex = 10;
			// 
			// price_lbl
			// 
			this->price_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(18, 323);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(31, 13);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(167, 93);
			this->author_txt->Name = L"author_txt";
			this->author_txt->ReadOnly = true;
			this->author_txt->Size = System::Drawing::Size(100, 20);
			this->author_txt->TabIndex = 9;
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(167, 52);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->ReadOnly = true;
			this->bookname_txt->Size = System::Drawing::Size(100, 20);
			this->bookname_txt->TabIndex = 8;
			// 
			// update_profile_button
			// 
			this->update_profile_button->Location = System::Drawing::Point(913, 8);
			this->update_profile_button->Margin = System::Windows::Forms::Padding(2);
			this->update_profile_button->Name = L"update_profile_button";
			this->update_profile_button->Size = System::Drawing::Size(137, 32);
			this->update_profile_button->TabIndex = 22;
			this->update_profile_button->Text = L"UPDATE PROFILE";
			this->update_profile_button->UseVisualStyleBackColor = true;
			this->update_profile_button->Click += gcnew System::EventHandler(this, &profile_book::update_profile_button_Click);
			// 
			// delete_profile_button
			// 
			this->delete_profile_button->Location = System::Drawing::Point(915, 44);
			this->delete_profile_button->Margin = System::Windows::Forms::Padding(2);
			this->delete_profile_button->Name = L"delete_profile_button";
			this->delete_profile_button->Size = System::Drawing::Size(135, 29);
			this->delete_profile_button->TabIndex = 21;
			this->delete_profile_button->Text = L"DELETE PROFILE";
			this->delete_profile_button->UseVisualStyleBackColor = true;
			this->delete_profile_button->Click += gcnew System::EventHandler(this, &profile_book::delete_profile_button_Click);
			// 
			// confirm_change_button
			// 
			this->confirm_change_button->Location = System::Drawing::Point(918, 77);
			this->confirm_change_button->Margin = System::Windows::Forms::Padding(2);
			this->confirm_change_button->Name = L"confirm_change_button";
			this->confirm_change_button->Size = System::Drawing::Size(132, 27);
			this->confirm_change_button->TabIndex = 23;
			this->confirm_change_button->Text = L"MAKE CHANGES";
			this->confirm_change_button->UseVisualStyleBackColor = true;
			this->confirm_change_button->Visible = false;
			this->confirm_change_button->Click += gcnew System::EventHandler(this, &profile_book::confirm_change_button_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open });
			this->dataGridView1->Location = System::Drawing::Point(8, 8);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(464, 221);
			this->dataGridView1->TabIndex = 24;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &profile_book::dataGridView1_CellContentClick);
			// 
			// Open
			// 
			this->Open->HeaderText = L"Profile";
			this->Open->MinimumWidth = 8;
			this->Open->Name = L"Open";
			this->Open->ReadOnly = true;
			this->Open->Text = L"Open";
			this->Open->UseColumnTextForButtonValue = true;
			this->Open->Width = 150;
			// 
			// back_button
			// 
			this->back_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button.Image")));
			this->back_button->Location = System::Drawing::Point(8, 455);
			this->back_button->Margin = System::Windows::Forms::Padding(2);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(49, 31);
			this->back_button->TabIndex = 25;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &profile_book::back_button_Click);
			// 
			// numeric_updown_no_copies
			// 
			this->numeric_updown_no_copies->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numeric_updown_no_copies->Location = System::Drawing::Point(784, 294);
			this->numeric_updown_no_copies->Margin = System::Windows::Forms::Padding(2);
			this->numeric_updown_no_copies->Name = L"numeric_updown_no_copies";
			this->numeric_updown_no_copies->Size = System::Drawing::Size(80, 20);
			this->numeric_updown_no_copies->TabIndex = 26;
			this->numeric_updown_no_copies->Visible = false;
			// 
			// profile_book
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1058, 494);
			this->Controls->Add(this->numeric_updown_no_copies);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->confirm_change_button);
			this->Controls->Add(this->update_profile_button);
			this->Controls->Add(this->delete_profile_button);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"profile_book";
			this->Text = L"profile_book";
			this->Load += gcnew System::EventHandler(this, &profile_book::profile_book_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_updown_no_copies))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void profile_book_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;

		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		String^ constring = sql_connection_func::sql_user_pass_string();

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
				String^ printing_book_borrow_stat;
				String^ printing_category;
				printing_id = myReader->GetString("book_id");
				printing_name = myReader->GetString("book_name");
				printing_author = myReader->GetString("book_author");
				printing_publisher = myReader->GetString("book_publisher");
				printing_price = myReader->GetString("book_price");
				printing_edition_no = myReader->GetString("book_edition_no");
				printing_book_borrow_stat = myReader->GetString("book_borrow_status");
				printing_category = myReader->GetString("category");
				this->bookname_txt->Text = printing_name;
				this->book_id_txt->Text = printing_id;
				this->author_txt->Text = printing_author;
				this->publisher_txt->Text = printing_publisher;
				this->price_txt->Text = printing_price;
				this->edition_no_txt->Text = printing_edition_no;
				this->borrow_stat_txt->Text = printing_book_borrow_stat;
				this->category_txt->Text = printing_category;
				//listBox1->Items->Add(printing_names);

			}
			fill_data_grid();
			int num_row = this->dataGridView1->RowCount;
			this->no_copies_txt->Text = num_row.ToString();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}

	private: System::Void update_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Update Profile");
		this->numeric_updown_no_copies->Visible = true;
		this->confirm_change_button->Visible = true;
		this->update_profile_button->Visible = false;
	}
	private: System::Void delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Delete Profile");
		if (MessageBox::Show("The profile will be deleted. Do you want to contiue?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		{
			//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
			String^ constring = sql_connection_func::sql_user_pass_string();

			MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM library_system.book_data WHERE book_id = " + this->book_id_txt->Text + ";", conDataBase);
			MySqlDataReader^ myReader;
			try {
				conDataBase->Open();
				myReader = cmdDataBase->ExecuteReader();
				MessageBox::Show("Profile is deleted");
				while (myReader->Read())
				{

				}


			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);

			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
		else
		{
			//do nothing
		}
	}
	private: System::Void confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->numeric_updown_no_copies->Visible = false;
		this->confirm_change_button->Visible = false;
		this->update_profile_button->Visible = true;

		updating_no_of_copies((int)this->numeric_updown_no_copies->Value);
		profile_book_Load(sender, e);
	}
	private: void fill_data_grid() {

		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		String^ constring = sql_connection_func::sql_user_pass_string();

		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT book_id, book_name, book_author, book_edition_no, book_publisher, book_borrow_status FROM library_system.book_data WHERE book_name = '" + this->bookname_txt->Text + "' AND book_edition_no = " + this->edition_no_txt->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		//
		//
		//	THIS PART IS NOT FILLING THE DATA PROPERLY IN DATAGRIDVIEW NEED TO CHECK
		//


		try {
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
			sda->SelectCommand = cmdDataBase;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			dataGridView1->DataSource = bSource;
			sda->Update(dbdataset);
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}

	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->ColumnIndex == 0)
		{
			int row_num = e->RowIndex;
			int col_num = e->ColumnIndex + 1;
			String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();
			MessageBox::Show("Your id is " + str);
			CppCLR_WinformsProjekt1::profile_book^ profile_book_f = gcnew CppCLR_WinformsProjekt1::profile_book(str);
			this->Hide();
			profile_book_f->ShowDialog();

			/*if (profile_book_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				this->Show();
			}*/

		}
	}
	private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: void updating_no_of_copies(int num_new_copies)
	{
		if (num_new_copies <= 0)
		{
			MessageBox::Show("" + num_new_copies + "");
			return;
		}
		else
		{
			MessageBox::Show("" + num_new_copies + "");

			//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
			//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
			String^ constring = sql_connection_func::sql_user_pass_string();

			MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

			MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("INSERT INTO library_system.book_data \
			(book_name, book_author, book_publisher, book_price,book_edition_no,no_of_copies, category) \
			VALUES('" + this->bookname_txt->Text + "',\
			'" + this->author_txt->Text + "',\
			'" + this->publisher_txt->Text + "',\
			'" + this->price_txt->Text + "',\
			'" + this->edition_no_txt->Text + "',\
			'" + this->no_copies_txt->Text + "',\
			'" + this->category_txt->Text + "');", conDataBase);

			MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("UPDATE library_system.book_data SET \
			no_of_copies = no_of_copies + '" + num_new_copies + "' WHERE book_name = '" + this->bookname_txt->Text + "' AND \
			book_edition_no = '" + this->edition_no_txt->Text + "';", conDataBase);

			try {
				conDataBase->Open();
				for (int i = 0; i < num_new_copies; i++)
					cmdDataBase1->ExecuteNonQuery();

				MessageBox::Show("cmdb1 executed");
				cmdDataBase2->ExecuteNonQuery();
				MessageBox::Show("cmdb2 executed");
				conDataBase->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}
	}
	};
}
