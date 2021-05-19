#pragma once

#include "profile_order.h"
#include "connection_sql_func.h"
namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;


	public ref class borrow_history_page : public System::Windows::Forms::Form
	{
	public:
		String^ transfer_id;
		bool is_librarian;
	public:
		borrow_history_page(void);
		borrow_history_page(String^ input_transfer_id, bool is_librarian_input);

	protected:
		~borrow_history_page();

	private: System::Windows::Forms::Button^ back_button_borrow_his;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: System::Windows::Forms::TextBox^ search_bar;
	private: System::Windows::Forms::ComboBox^ list_detail_search_order;
	private: System::Windows::Forms::Button^ search_button;
	private: System::Windows::Forms::Button^ clear_all_button;

	private: System::Windows::Forms::Button^ exit_button;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(borrow_history_page::typeid));
			this->back_button_borrow_his = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Open = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->search_bar = (gcnew System::Windows::Forms::TextBox());
			this->list_detail_search_order = (gcnew System::Windows::Forms::ComboBox());
			this->search_button = (gcnew System::Windows::Forms::Button());
			this->clear_all_button = (gcnew System::Windows::Forms::Button());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// back_button_borrow_his
			// 
			this->back_button_borrow_his->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button_borrow_his.Image")));
			this->back_button_borrow_his->Location = System::Drawing::Point(12, 12);
			this->back_button_borrow_his->Name = L"back_button_borrow_his";
			this->back_button_borrow_his->Size = System::Drawing::Size(75, 52);
			this->back_button_borrow_his->TabIndex = 0;
			this->back_button_borrow_his->UseVisualStyleBackColor = true;
			this->back_button_borrow_his->Click += gcnew System::EventHandler(this, &borrow_history_page::back_button_borrow_his_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open });
			this->dataGridView1->Location = System::Drawing::Point(242, 103);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(956, 383);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &borrow_history_page::dataGridView1_CellContentClick);
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
			// search_bar
			// 
			this->search_bar->Location = System::Drawing::Point(194, 12);
			this->search_bar->Name = L"search_bar";
			this->search_bar->Size = System::Drawing::Size(500, 26);
			this->search_bar->TabIndex = 2;
			// 
			// list_detail_search_order
			// 
			this->list_detail_search_order->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->list_detail_search_order->FormattingEnabled = true;
			this->list_detail_search_order->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Order ID", L"Student ID", L"Book ID" });
			this->list_detail_search_order->Location = System::Drawing::Point(700, 12);
			this->list_detail_search_order->Name = L"list_detail_search_order";
			this->list_detail_search_order->Size = System::Drawing::Size(146, 28);
			this->list_detail_search_order->TabIndex = 3;
			// 
			// search_button
			// 
			this->search_button->Location = System::Drawing::Point(852, 12);
			this->search_button->Name = L"search_button";
			this->search_button->Size = System::Drawing::Size(119, 40);
			this->search_button->TabIndex = 4;
			this->search_button->Text = L"Search";
			this->search_button->UseVisualStyleBackColor = true;
			this->search_button->Click += gcnew System::EventHandler(this, &borrow_history_page::search_button_Click);
			// 
			// clear_all_button
			// 
			this->clear_all_button->Location = System::Drawing::Point(992, 12);
			this->clear_all_button->Name = L"clear_all_button";
			this->clear_all_button->Size = System::Drawing::Size(140, 39);
			this->clear_all_button->TabIndex = 5;
			this->clear_all_button->Text = L"Clear Search";
			this->clear_all_button->UseVisualStyleBackColor = true;
			this->clear_all_button->Click += gcnew System::EventHandler(this, &borrow_history_page::clear_all_button_Click);
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(1243, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(82, 38);
			this->exit_button->TabIndex = 7;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &borrow_history_page::exit_button_Click);
			// 
			// borrow_history_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1337, 685);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->clear_all_button);
			this->Controls->Add(this->search_button);
			this->Controls->Add(this->list_detail_search_order);
			this->Controls->Add(this->search_bar);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->back_button_borrow_his);
			this->Name = L"borrow_history_page";
			this->Text = L"borrow_history_page";
			this->Load += gcnew System::EventHandler(this, &borrow_history_page::borrow_history_page_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void back_button_borrow_his_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	private: void fill_data_grid();

	private: System::Void borrow_history_page_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	private: System::Void search_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void clear_all_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
