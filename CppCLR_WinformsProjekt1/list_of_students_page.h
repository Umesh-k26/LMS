#pragma once
#include "pch.h"
//#include "Form2.h"
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
	/// Summary for list_of_students_page
	/// </summary>
	public ref class list_of_students_page : public System::Windows::Forms::Form
	{
	public:
		list_of_students_page(void)
		{
			InitializeComponent();
			//fill_listbox1();
			fill_data_grid();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~list_of_students_page()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ComboBox^ comboBox1;




	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(list_of_students_page::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Open = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open });
			this->dataGridView1->Location = System::Drawing::Point(116, 121);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(637, 285);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &list_of_students_page::dataGridView1_CellContentClick);
			// 
			// Open
			// 
			this->Open->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Open->HeaderText = L"Profile";
			this->Open->MinimumWidth = 8;
			this->Open->Name = L"Open";
			this->Open->ReadOnly = true;
			this->Open->Text = L"Open";
			this->Open->UseColumnTextForButtonValue = true;
			this->Open->Width = 42;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 21);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(310, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(9, 8);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 29);
			this->button1->TabIndex = 3;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &list_of_students_page::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(722, 8);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &list_of_students_page::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(8, 121);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 29);
			this->button3->TabIndex = 5;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &list_of_students_page::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(541, 21);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(62, 25);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Search";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &list_of_students_page::button4_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"student_name", L"student_address" });
			this->comboBox1->Location = System::Drawing::Point(429, 19);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(82, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &list_of_students_page::comboBox1_SelectedIndexChanged);
			// 
			// list_of_students_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 419);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"list_of_students_page";
			this->Text = L"list_of_students_page";
			this->Load += gcnew System::EventHandler(this, &list_of_students_page::list_of_students_page_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
/*
	private: void fill_listbox1() {
		//
		//	This section works but can print only one thing
		//
		//
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);
		MySqlCommand^ print_students = gcnew MySqlCommand("select * from test.student_data;", conDataBase);
		MySqlDataReader^ myReader;
		//listBox1.Items.Add("Mahesh Chand");
		try {
			conDataBase->Open();
			myReader = print_students->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_names;
				printing_names = myReader->GetString("gender");
				listBox1->Items->Add(printing_names);

			}

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}


	}
	*/
	private: void fill_data_grid() {

		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from library_system.student_data;", conDataBase);
		MySqlDataReader^ myReader;

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


	private: System::Void list_of_students_page_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;


	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//CppCLR_WinformsProjekt1::Form2^ f2 = gcnew CppCLR_WinformsProjekt1::Form2;
	//this->Hide();
	//f2->ShowDialog();
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();


}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	CppCLR_WinformsProjekt1::testing^ testing_f = gcnew CppCLR_WinformsProjekt1::testing;
	this->Hide();
	//testing_f->ShowDialog();
	if (testing_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}
}


private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex == 0)
	{
		/*CppCLR_WinformsProjekt1::testing^ testing_f = gcnew CppCLR_WinformsProjekt1::testing;
		this->Hide();
		//testing_f->ShowDialog();
		if (testing_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}*/
		int row_num = e->RowIndex;
		int col_num = e->ColumnIndex + 1;
		String^ str = this->dataGridView1->Rows[row_num]->Cells[col_num]->Value->ToString();
		MessageBox::Show("Your id is "+ str);


	}
	


}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.student_data\
		WHERE " + this->comboBox1->Text+" LIKE '%"+this->textBox1->Text+"%';", conDataBase);
	MySqlDataReader^ myReader;

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
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
