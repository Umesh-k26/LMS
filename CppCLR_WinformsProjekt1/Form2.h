#pragma once

#include "list_of_students_page.h"
#include "AddBook.h"
#include "RegisterStudent.h"
#include "list_of_books_page.h"
#include "borrow_history_page.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "RegisterLibrarian.h"
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
		}

	protected:
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
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		//Description of buttons over here.
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
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 411);
			this->button1->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 45);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Location = System::Drawing::Point(312, 121);
			this->button2->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 44);
			this->button2->TabIndex = 1;
			this->button2->Text = L"List of Books";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->Location = System::Drawing::Point(312, 218);
			this->button3->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 43);
			this->button3->TabIndex = 2;
			this->button3->Text = L"List of Students";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button4->Location = System::Drawing::Point(507, 218);
			this->button4->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(116, 43);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Add Book to Library";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button5->Location = System::Drawing::Point(126, 322);
			this->button5->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(111, 42);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Register a Student";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form2::button5_Click);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button6->Location = System::Drawing::Point(507, 121);
			this->button6->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(116, 44);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Borrow History";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form2::button6_Click);
			// 
			// button8
			// 
			this->button8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button8->Location = System::Drawing::Point(126, 121);
			this->button8->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(111, 44);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Borrow A Book";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form2::button8_Click);
			// 
			// button7
			// 
			this->button7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button7->Location = System::Drawing::Point(126, 218);
			this->button7->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(111, 43);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Return A Book";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form2::button7_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(9, 29);
			this->button9->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(97, 43);
			this->button9->TabIndex = 9;
			this->button9->Text = L"Logout";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form2::button9_Click_1);
			// 
			// button10
			// 
			this->button10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button10->Location = System::Drawing::Point(312, 322);
			this->button10->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(111, 42);
			this->button10->TabIndex = 10;
			this->button10->Text = L"Register a Librarian";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form2::button10_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(742, 463);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->MinimumSize = System::Drawing::Size(756, 495);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		// The function carried out by clicking the button comes here.
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::list_of_students_page^ list_of_students_f = gcnew CppCLR_WinformsProjekt1::list_of_students_page;
		this->Hide();
		//list_of_students_f->ShowDialog();
		if (list_of_students_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		/*CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook;
		this->Hide();
		addbook_f->ShowDialog();*/
		CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook;
		this->Hide();
		if (addbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::RegisterStudent^ registerstudent_f = gcnew CppCLR_WinformsProjekt1::RegisterStudent;
		this->Hide();
		if (registerstudent_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		CppCLR_WinformsProjekt1::list_of_books_page^ list_of_books_f = gcnew CppCLR_WinformsProjekt1::list_of_books_page;
		this->Hide();
		//list_of_books_f->ShowDialog();
		if (list_of_books_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::borrow_history_page^ borrow_history_page_f = gcnew CppCLR_WinformsProjekt1::borrow_history_page;
		this->Hide();
		if (borrow_history_page_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::BorrowBook^ borrowbook_f = gcnew CppCLR_WinformsProjekt1::BorrowBook;
		this->Hide();
		if (borrowbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::ReturnBook^ returnbook_f = gcnew CppCLR_WinformsProjekt1::ReturnBook;
		this->Hide();
		if (returnbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button9_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::RegisterLibrarian^ registerlibrarian_f = gcnew CppCLR_WinformsProjekt1::RegisterLibrarian;
		this->Hide();
		if (registerlibrarian_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
};
}
