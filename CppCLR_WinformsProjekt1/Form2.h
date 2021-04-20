#pragma once

#include "list_of_students_page.h"
#include "AddBook.h"
#include "RegisterStudent.h"
#include "list_of_books_page.h"
namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;


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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(296, 145);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(140, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"List of Books";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(296, 222);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 35);
			this->button3->TabIndex = 2;
			this->button3->Text = L"List of Students";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(296, 294);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(178, 54);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Add Book to Library";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(296, 374);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(176, 55);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Register a Student";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form2::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(300, 74);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(135, 43);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Borrow History";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(86, 186);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(144, 40);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Borrow A Book";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(86, 309);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(144, 46);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Return A Book";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1586, 840);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::list_of_students_page^ list_of_students_f = gcnew CppCLR_WinformsProjekt1::list_of_students_page;
		this->Hide();
		list_of_students_f->ShowDialog();
	}
	private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		/*CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook;
		this->Hide();
		addbook_f->ShowDialog();*/
		CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook;
		this->Hide();
		addbook_f->ShowDialog();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::RegisterStudent^ registerstudent_f = gcnew CppCLR_WinformsProjekt1::RegisterStudent;
		this->Hide();
		registerstudent_f->ShowDialog();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	CppCLR_WinformsProjekt1::list_of_books_page^ list_of_books_f = gcnew CppCLR_WinformsProjekt1::list_of_books_page;
	this->Hide();
	list_of_books_f->ShowDialog();
}
};
}
