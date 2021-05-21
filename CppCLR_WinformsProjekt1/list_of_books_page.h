#pragma once
//#include "Form2.h"
#include "profile_book.h"
#include "connection_sql_func.h"
namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class list_of_books_page : public System::Windows::Forms::Form
	{
	public:
		String^ transfer_id;
		bool is_librarian;
	public:
		list_of_books_page(void);
		list_of_books_page(String^ input_transfer_id, bool is_librarian_input);

	protected:
		~list_of_books_page();

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ back_button_book_list;
	private: System::Windows::Forms::Button^ exit_button;

	private: System::Windows::Forms::TextBox^ search_bar_book;
	private: System::Windows::Forms::ComboBox^ list_detail_search_book;
	private: System::Windows::Forms::Button^ search_button_book;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: System::Windows::Forms::Button^ clear_all_button;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(list_of_books_page::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Open = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->back_button_book_list = (gcnew System::Windows::Forms::Button());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->search_bar_book = (gcnew System::Windows::Forms::TextBox());
			this->list_detail_search_book = (gcnew System::Windows::Forms::ComboBox());
			this->search_button_book = (gcnew System::Windows::Forms::Button());
			this->clear_all_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open });
			this->dataGridView1->Location = System::Drawing::Point(116, 129);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(707, 314);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &list_of_books_page::dataGridView1_CellContentClick);
			// 
			// Open
			// 
			this->Open->HeaderText = L"Profile";
			this->Open->MinimumWidth = 8;
			this->Open->Name = L"Open";
			this->Open->ReadOnly = true;
			this->Open->Text = L"Open";
			this->Open->UseColumnTextForButtonValue = true;
			// 
			// back_button_book_list
			// 
			this->back_button_book_list->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button_book_list.Image")));
			this->back_button_book_list->Location = System::Drawing::Point(8, 8);
			this->back_button_book_list->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->back_button_book_list->Name = L"back_button_book_list";
			this->back_button_book_list->Size = System::Drawing::Size(35, 33);
			this->back_button_book_list->TabIndex = 1;
			this->back_button_book_list->UseVisualStyleBackColor = true;
			this->back_button_book_list->Click += gcnew System::EventHandler(this, &list_of_books_page::back_button_book_list_Click);
			// 
			// exit_button
			// 
			this->exit_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exit_button->Location = System::Drawing::Point(773, 8);
			this->exit_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(50, 26);
			this->exit_button->TabIndex = 2;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &list_of_books_page::exit_button_Click);
			// 
			// search_bar_book
			// 
			this->search_bar_book->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_bar_book->Location = System::Drawing::Point(169, 8);
			this->search_bar_book->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->search_bar_book->Name = L"search_bar_book";
			this->search_bar_book->Size = System::Drawing::Size(286, 20);
			this->search_bar_book->TabIndex = 3;
			// 
			// list_detail_search_book
			// 
			this->list_detail_search_book->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->list_detail_search_book->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->list_detail_search_book->FormattingEnabled = true;
			this->list_detail_search_book->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"ID", L"Title", L"Author", L"Edition No." });
			this->list_detail_search_book->Location = System::Drawing::Point(458, 8);
			this->list_detail_search_book->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->list_detail_search_book->Name = L"list_detail_search_book";
			this->list_detail_search_book->Size = System::Drawing::Size(90, 21);
			this->list_detail_search_book->TabIndex = 4;
			this->list_detail_search_book->SelectedIndexChanged += gcnew System::EventHandler(this, &list_of_books_page::list_detail_search_book_SelectedIndexChanged);
			// 
			// search_button_book
			// 
			this->search_button_book->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->search_button_book->Location = System::Drawing::Point(551, 8);
			this->search_button_book->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->search_button_book->Name = L"search_button_book";
			this->search_button_book->Size = System::Drawing::Size(62, 26);
			this->search_button_book->TabIndex = 5;
			this->search_button_book->Text = L"Search";
			this->search_button_book->UseVisualStyleBackColor = true;
			this->search_button_book->Click += gcnew System::EventHandler(this, &list_of_books_page::search_button_book_Click);
			// 
			// clear_all_button
			// 
			this->clear_all_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->clear_all_button->Location = System::Drawing::Point(617, 8);
			this->clear_all_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->clear_all_button->Name = L"clear_all_button";
			this->clear_all_button->Size = System::Drawing::Size(81, 26);
			this->clear_all_button->TabIndex = 6;
			this->clear_all_button->Text = L"Clear Search";
			this->clear_all_button->UseVisualStyleBackColor = true;
			this->clear_all_button->Click += gcnew System::EventHandler(this, &list_of_books_page::clear_all_button_Click);
			// 
			// list_of_books_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(934, 568);
			this->Controls->Add(this->clear_all_button);
			this->Controls->Add(this->search_button_book);
			this->Controls->Add(this->list_detail_search_book);
			this->Controls->Add(this->search_bar_book);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->back_button_book_list);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MinimumSize = System::Drawing::Size(950, 607);
			this->Name = L"list_of_books_page";
			this->Text = L"list_of_books_page";
			this->Load += gcnew System::EventHandler(this, &list_of_books_page::list_of_books_page_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void fill_data_grid();

	private: System::Void list_of_books_page_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void back_button_book_list_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	private: System::Void search_button_book_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void list_detail_search_book_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void clear_all_button_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
