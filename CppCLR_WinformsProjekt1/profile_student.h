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
	/// Summary for profile_student
	/// </summary>
	public ref class profile_student : public System::Windows::Forms::Form
	{
	public:
		String^ transfer_id_student;
	public:
		profile_student(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		profile_student(String^ label_text_id)
		{
			InitializeComponent();
			transfer_id_student = label_text_id;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~profile_student()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Label^ name_lbl;
	private: System::Windows::Forms::Label^ dob_lbl;
	private: System::Windows::Forms::Label^ profession_lbl;

	private: System::Windows::Forms::Label^ email_id_lbl;
	private: System::Windows::Forms::Label^ mobile_no_lbl;
	private: System::Windows::Forms::TextBox^ address_txt;
	private: System::Windows::Forms::Label^ address_lbl;
	private: System::Windows::Forms::TextBox^ mobile_no_txt;
	private: System::Windows::Forms::TextBox^ name_txt;
	private: System::Windows::Forms::TextBox^ email_id_txt;
	private: System::Windows::Forms::TextBox^ profession_txt;
	private: System::Windows::Forms::TextBox^ student_id_txt;
	private: System::Windows::Forms::TextBox^ dob_student_txt;
	private: System::Windows::Forms::Button^ delete_profile_button;
	private: System::Windows::Forms::Button^ update_profile_button;
	private: System::Windows::Forms::Button^ confirm_change_button;
	private: System::Windows::Forms::ComboBox^ profession_selector;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewButtonColumn^ Open;
	private: System::Windows::Forms::Button^ back_button;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(profile_student::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->profession_selector = (gcnew System::Windows::Forms::ComboBox());
			this->dob_student_txt = (gcnew System::Windows::Forms::TextBox());
			this->student_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->name_lbl = (gcnew System::Windows::Forms::Label());
			this->dob_lbl = (gcnew System::Windows::Forms::Label());
			this->profession_lbl = (gcnew System::Windows::Forms::Label());
			this->email_id_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_lbl = (gcnew System::Windows::Forms::Label());
			this->address_txt = (gcnew System::Windows::Forms::TextBox());
			this->address_lbl = (gcnew System::Windows::Forms::Label());
			this->mobile_no_txt = (gcnew System::Windows::Forms::TextBox());
			this->name_txt = (gcnew System::Windows::Forms::TextBox());
			this->email_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->profession_txt = (gcnew System::Windows::Forms::TextBox());
			this->delete_profile_button = (gcnew System::Windows::Forms::Button());
			this->update_profile_button = (gcnew System::Windows::Forms::Button());
			this->confirm_change_button = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Open = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 25);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->profession_selector);
			this->groupBox1->Controls->Add(this->dob_student_txt);
			this->groupBox1->Controls->Add(this->student_id_txt);
			this->groupBox1->Controls->Add(this->dateTimePicker);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->name_lbl);
			this->groupBox1->Controls->Add(this->dob_lbl);
			this->groupBox1->Controls->Add(this->profession_lbl);
			this->groupBox1->Controls->Add(this->email_id_lbl);
			this->groupBox1->Controls->Add(this->mobile_no_lbl);
			this->groupBox1->Controls->Add(this->address_txt);
			this->groupBox1->Controls->Add(this->address_lbl);
			this->groupBox1->Controls->Add(this->mobile_no_txt);
			this->groupBox1->Controls->Add(this->name_txt);
			this->groupBox1->Controls->Add(this->email_id_txt);
			this->groupBox1->Controls->Add(this->profession_txt);
			this->groupBox1->Location = System::Drawing::Point(94, 9);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(399, 422);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Student Profile";
			// 
			// profession_selector
			// 
			this->profession_selector->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->profession_selector->FormattingEnabled = true;
			this->profession_selector->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Faculty", L"Alumini" });
			this->profession_selector->Location = System::Drawing::Point(287, 148);
			this->profession_selector->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->profession_selector->Name = L"profession_selector";
			this->profession_selector->Size = System::Drawing::Size(99, 21);
			this->profession_selector->TabIndex = 19;
			this->profession_selector->Visible = false;
			// 
			// dob_student_txt
			// 
			this->dob_student_txt->Location = System::Drawing::Point(171, 97);
			this->dob_student_txt->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dob_student_txt->Name = L"dob_student_txt";
			this->dob_student_txt->ReadOnly = true;
			this->dob_student_txt->Size = System::Drawing::Size(101, 20);
			this->dob_student_txt->TabIndex = 18;
			// 
			// student_id_txt
			// 
			this->student_id_txt->Location = System::Drawing::Point(171, 27);
			this->student_id_txt->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->student_id_txt->Name = L"student_id_txt";
			this->student_id_txt->ReadOnly = true;
			this->student_id_txt->Size = System::Drawing::Size(99, 20);
			this->student_id_txt->TabIndex = 17;
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(287, 96);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(99, 20);
			this->dateTimePicker->TabIndex = 16;
			this->dateTimePicker->Visible = false;
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(36, 58);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(35, 13);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(36, 103);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(66, 13);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// profession_lbl
			// 
			this->profession_lbl->AutoSize = true;
			this->profession_lbl->Location = System::Drawing::Point(36, 154);
			this->profession_lbl->Name = L"profession_lbl";
			this->profession_lbl->Size = System::Drawing::Size(56, 13);
			this->profession_lbl->TabIndex = 2;
			this->profession_lbl->Text = L"Profession";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(36, 206);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(44, 13);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(36, 258);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(58, 13);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(171, 307);
			this->address_txt->Name = L"address_txt";
			this->address_txt->ReadOnly = true;
			this->address_txt->Size = System::Drawing::Size(100, 20);
			this->address_txt->TabIndex = 11;
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(36, 310);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(45, 13);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(171, 255);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->ReadOnly = true;
			this->mobile_no_txt->Size = System::Drawing::Size(100, 20);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(171, 55);
			this->name_txt->Name = L"name_txt";
			this->name_txt->ReadOnly = true;
			this->name_txt->Size = System::Drawing::Size(100, 20);
			this->name_txt->TabIndex = 6;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(171, 203);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->ReadOnly = true;
			this->email_id_txt->Size = System::Drawing::Size(100, 20);
			this->email_id_txt->TabIndex = 9;
			// 
			// profession_txt
			// 
			this->profession_txt->Location = System::Drawing::Point(171, 151);
			this->profession_txt->Name = L"profession_txt";
			this->profession_txt->ReadOnly = true;
			this->profession_txt->Size = System::Drawing::Size(100, 20);
			this->profession_txt->TabIndex = 8;
			// 
			// delete_profile_button
			// 
			this->delete_profile_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->delete_profile_button->Location = System::Drawing::Point(621, 43);
			this->delete_profile_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->delete_profile_button->Name = L"delete_profile_button";
			this->delete_profile_button->Size = System::Drawing::Size(135, 29);
			this->delete_profile_button->TabIndex = 19;
			this->delete_profile_button->Text = L"DELETE PROFILE";
			this->delete_profile_button->UseVisualStyleBackColor = true;
			this->delete_profile_button->Click += gcnew System::EventHandler(this, &profile_student::delete_profile_button_Click);
			// 
			// update_profile_button
			// 
			this->update_profile_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->update_profile_button->Location = System::Drawing::Point(621, 6);
			this->update_profile_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->update_profile_button->Name = L"update_profile_button";
			this->update_profile_button->Size = System::Drawing::Size(137, 32);
			this->update_profile_button->TabIndex = 20;
			this->update_profile_button->Text = L"UPDATE PROFILE";
			this->update_profile_button->UseVisualStyleBackColor = true;
			this->update_profile_button->Click += gcnew System::EventHandler(this, &profile_student::update_profile_button_Click);
			// 
			// confirm_change_button
			// 
			this->confirm_change_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->confirm_change_button->Location = System::Drawing::Point(621, 77);
			this->confirm_change_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->confirm_change_button->Name = L"confirm_change_button";
			this->confirm_change_button->Size = System::Drawing::Size(135, 44);
			this->confirm_change_button->TabIndex = 21;
			this->confirm_change_button->Text = L"MAKE CHANGES";
			this->confirm_change_button->UseVisualStyleBackColor = true;
			this->confirm_change_button->Visible = false;
			this->confirm_change_button->Click += gcnew System::EventHandler(this, &profile_student::confirm_change_button_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Open });
			this->dataGridView1->Location = System::Drawing::Point(8, 8);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(458, 363);
			this->dataGridView1->TabIndex = 20;
			// 
			// Open
			// 
			this->Open->HeaderText = L"Profile";
			this->Open->MinimumWidth = 8;
			this->Open->Name = L"Open";
			this->Open->ReadOnly = true;
			this->Open->Text = L"Open";
			this->Open->UseColumnTextForButtonValue = true;
			this->Open->Width = 42;
			// 
			// back_button
			// 
			this->back_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button.Image")));
			this->back_button->Location = System::Drawing::Point(8, 541);
			this->back_button->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(54, 29);
			this->back_button->TabIndex = 22;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &profile_student::back_button_Click);
			// 
			// profile_student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 591);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->confirm_change_button);
			this->Controls->Add(this->update_profile_button);
			this->Controls->Add(this->delete_profile_button);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"profile_student";
			this->Text = L"profile_student";
			this->Load += gcnew System::EventHandler(this, &profile_student::profile_student_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void profile_student_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;
		//this->label1->Text = list_of_students_page::global_student_id_passed;
		//this->label1->Text = transfer_id_student;



		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		//MySqlCommand^ cmdDataBase = gcnew MySqlCommand("select * from test.student_data WHERE username='" + this->username_txt->Text + "' and password = '" + this->password_txt->Text + "' ;", conDataBase);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.student_data\
		WHERE student_id = " + transfer_id_student + ";", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_name;
				String^ printing_id;
				String^ printing_profession;
				String^ printing_email;
				String^ printing_mobile;
				String^ printing_address;
				//String^ printing_dob;
				printing_id = myReader->GetString("student_id");
				printing_name = myReader->GetString("student_name");
				printing_profession = myReader->GetString("student_profession");
				printing_email = myReader->GetString("student_email");
				printing_mobile = myReader->GetString("student_mobile");
				printing_address = myReader->GetString("student_address");
				//printing_dob = myReader->GetString("student_dob");

				MySql::Data::Types::MySqlDateTime new_dob;
				new_dob = myReader->GetMySqlDateTime("student_dob");
				this->name_txt->Text = printing_name;
				this->student_id_txt->Text = printing_id;
				this->email_id_txt->Text = printing_email;
				this->mobile_no_txt->Text = printing_mobile;
				this->address_txt->Text = printing_address;

				//this->dob_student_txt->Text = printing_dob;
				this->dob_student_txt->Text = new_dob.ToString();

				this->profession_txt->Text = printing_profession;
				//listBox1->Items->Add(printing_names);

				this->dateTimePicker->Value = new_dob.GetDateTime();

			}
			fill_data_grid();

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
	private: System::Void update_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Update profile");
		//this->dob_student_txt->Visible = false;
		this->update_profile_button->Visible = false;
		this->confirm_change_button->Visible = true;
		this->dateTimePicker->Visible = true;
		this->name_txt->ReadOnly = false;
		this->profession_txt->ReadOnly = true;
		this->email_id_txt->ReadOnly = false;
		this->mobile_no_txt->ReadOnly = false;
		this->address_txt->ReadOnly = false;
		this->profession_selector->Visible = true;
		this->profession_selector->Text = this->profession_txt->Text;



	}
	private: System::Void delete_profile_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Delete Profile");
		/*String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE * FROM library_system.student WHERE student_id = "+this->student_id_txt->Text+";", conDataBase);
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

		}*/
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void confirm_change_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Changes made");


		this->profession_txt->Text = this->profession_selector->Text;
		this->dob_student_txt->Text = this->dateTimePicker->Text;


		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("UPDATE library_system.student_data set student_id = \
		" + this->student_id_txt->Text + ",student_name = '" + this->name_txt->Text + "',student_dob = '" + this->dob_student_txt->Text + "', student_profession = '" + this->profession_txt->Text + "', student_email='" + this->email_id_txt->Text + "', student_mobile=" + this->mobile_no_txt->Text + ", student_address = '" + this->address_txt->Text + "'WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();
			MessageBox::Show("Profile is updated");
			while (myReader->Read())
			{

			}


		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		//this->dob_student_txt->Visible = true;
		this->update_profile_button->Visible = true;
		this->confirm_change_button->Visible = false;
		this->dateTimePicker->Visible = false;
		this->name_txt->ReadOnly = true;
		this->profession_txt->ReadOnly = true;
		this->email_id_txt->ReadOnly = true;
		this->mobile_no_txt->ReadOnly = true;
		this->address_txt->ReadOnly = true;
		this->profession_selector->Visible = false;
		//this->Refresh();
		//profile_student(transfer_id_student);
		profile_student_Load(sender, e);
		//
		//	FORM NOT RELOADING OVER HERE NEED TO FIX
		//

	}
	private: void fill_data_grid() {

		//String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history WHERE student_id = " + this->student_id_txt->Text + " AND borrow_status = 'BORROWED';", conDataBase);
		MySqlDataReader^ myReader;
		//student_id,student_name,student_mobile, student_profession, student_no_book_stat 
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
	private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	};
}
