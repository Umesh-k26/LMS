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
	/// Summary for testing
	/// </summary>
	public ref class testing : public System::Windows::Forms::Form
	{
	public:
		testing(void)
		{
			InitializeComponent();
			calculate_fine();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~testing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(64, 55);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &testing::button1_Click);
			// 
			// testing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(185, 159);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(201, 198);
			this->Name = L"testing";
			this->Text = L"testing";
			this->Load += gcnew System::EventHandler(this, &testing::testing_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void testing_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: int calculate_fine()
	{
		int order_id_dummy = 1;
		int student_id_dummy = 3;
		int value_fine = 0;
		int num_date_difference;
		String^ borrower_profession;

		int default_student_allowance = 7, default_faculty_allowance = 14, default_alumni_allowance = 10;
		int perday_student = 10, perday_faculty = 20, perday_alumni = 20;

		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		MySqlCommand^ cmdDataBase1 = gcnew MySqlCommand("SELECT DATEDIFF(date_returned, date_issue) AS fine_column FROM library_system.borrow_history WHERE order_id = " + order_id_dummy +";", conDataBase);
		MySqlDataReader^ myReader;
		
		try {
			conDataBase->Open();
			myReader = cmdDataBase1->ExecuteReader();

			while (myReader->Read())
			{
				num_date_difference = myReader->GetInt16("fine_column");
				//MessageBox::Show(""+num_date_difference);
			}
			myReader->Close();

			MySqlCommand^ cmdDataBase2 = gcnew MySqlCommand("SELECT student_profession FROM library_system.student_data WHERE student_id = "+student_id_dummy+";", conDataBase);
			myReader = cmdDataBase2->ExecuteReader();
			while (myReader->Read())
			{
				borrower_profession = myReader->GetString("student_profession");
			}
			myReader->Close();

			if (borrower_profession == "Student")
			{
				if (num_date_difference <= default_student_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrower_profession + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_student_allowance;
					value_fine = num_date_difference * perday_student;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrower_profession + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrower_profession == "Faculty")
			{
				if (num_date_difference <= default_faculty_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrower_profession + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_faculty_allowance;
					value_fine = num_date_difference * perday_faculty;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrower_profession + "\n Fine = " + value_fine);
					return value_fine;
				}
			}
			if (borrower_profession == "Alumni")
			{
				if (num_date_difference <= default_alumni_allowance)
				{
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrower_profession + "\n Fine = " + value_fine);
					return 0;
				}
				else
				{
					num_date_difference = num_date_difference - default_alumni_allowance;
					value_fine = num_date_difference * perday_alumni;
					MessageBox::Show("No of days overdue = " + num_date_difference + "\n Profession = " + borrower_profession + "\n Fine = " + value_fine);
					return value_fine;
				}
			}


		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}

		
	}
	};
}
