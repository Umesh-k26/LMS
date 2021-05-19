#pragma once

#include "list_of_students_page.h"
#include "AddBook.h"
#include "RegisterStudent.h"
#include "list_of_books_page.h"
#include "borrow_history_page.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "RegisterLibrarian.h"
#include "profile_student.h"
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
		String^ transfer_id;
		bool is_librarian;
	public:
		Form2(void)
		{
			InitializeComponent();
		}
		Form2(String^ input_transfer_id, bool is_librarian_input)
		{
			transfer_id = input_transfer_id;
			is_librarian = is_librarian_input;
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
	private: System::Windows::Forms::Button^ booklist_btn;
	private: System::Windows::Forms::Button^ studentslist_btn;
	private: System::Windows::Forms::Button^ addbook_btn;



	private: System::Windows::Forms::Button^ registerstudent_btn;
	private: System::Windows::Forms::Button^ borrowhistory_btn;






	private: System::Windows::Forms::Button^ borrowbook_btn;



	private: System::Windows::Forms::Button^ returnbook_btn;




	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ registerlibrarian_btn;
	private: System::Windows::Forms::Button^ view_profile_user_btn;



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
			this->booklist_btn = (gcnew System::Windows::Forms::Button());
			this->studentslist_btn = (gcnew System::Windows::Forms::Button());
			this->addbook_btn = (gcnew System::Windows::Forms::Button());
			this->registerstudent_btn = (gcnew System::Windows::Forms::Button());
			this->borrowhistory_btn = (gcnew System::Windows::Forms::Button());
			this->borrowbook_btn = (gcnew System::Windows::Forms::Button());
			this->returnbook_btn = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->registerlibrarian_btn = (gcnew System::Windows::Forms::Button());
			this->view_profile_user_btn = (gcnew System::Windows::Forms::Button());
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
			// booklist_btn
			// 
			this->booklist_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->booklist_btn->Location = System::Drawing::Point(312, 121);
			this->booklist_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->booklist_btn->Name = L"booklist_btn";
			this->booklist_btn->Size = System::Drawing::Size(121, 44);
			this->booklist_btn->TabIndex = 1;
			this->booklist_btn->Text = L"List of Books";
			this->booklist_btn->UseVisualStyleBackColor = true;
			this->booklist_btn->Click += gcnew System::EventHandler(this, &Form2::BookList_Click);
			// 
			// studentslist_btn
			// 
			this->studentslist_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->studentslist_btn->Location = System::Drawing::Point(312, 218);
			this->studentslist_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->studentslist_btn->Name = L"studentslist_btn";
			this->studentslist_btn->Size = System::Drawing::Size(121, 43);
			this->studentslist_btn->TabIndex = 2;
			this->studentslist_btn->Text = L"List of Students";
			this->studentslist_btn->UseVisualStyleBackColor = true;
			this->studentslist_btn->Click += gcnew System::EventHandler(this, &Form2::StudentsList_Click);
			// 
			// addbook_btn
			// 
			this->addbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addbook_btn->Location = System::Drawing::Point(507, 218);
			this->addbook_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->addbook_btn->Name = L"addbook_btn";
			this->addbook_btn->Size = System::Drawing::Size(116, 43);
			this->addbook_btn->TabIndex = 3;
			this->addbook_btn->Text = L"Add Book to Library";
			this->addbook_btn->UseVisualStyleBackColor = true;
			this->addbook_btn->Click += gcnew System::EventHandler(this, &Form2::AddBook_Click);
			// 
			// registerstudent_btn
			// 
			this->registerstudent_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registerstudent_btn->Location = System::Drawing::Point(126, 322);
			this->registerstudent_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->registerstudent_btn->Name = L"registerstudent_btn";
			this->registerstudent_btn->Size = System::Drawing::Size(111, 42);
			this->registerstudent_btn->TabIndex = 4;
			this->registerstudent_btn->Text = L"Register a Student";
			this->registerstudent_btn->UseVisualStyleBackColor = true;
			this->registerstudent_btn->Click += gcnew System::EventHandler(this, &Form2::RegisterStudent_Click);
			// 
			// borrowhistory_btn
			// 
			this->borrowhistory_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrowhistory_btn->Location = System::Drawing::Point(507, 121);
			this->borrowhistory_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->borrowhistory_btn->Name = L"borrowhistory_btn";
			this->borrowhistory_btn->Size = System::Drawing::Size(116, 44);
			this->borrowhistory_btn->TabIndex = 5;
			this->borrowhistory_btn->Text = L"Borrow History";
			this->borrowhistory_btn->UseVisualStyleBackColor = true;
			this->borrowhistory_btn->Click += gcnew System::EventHandler(this, &Form2::BorrowHistory_Click);
			// 
			// borrowbook_btn
			// 
			this->borrowbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrowbook_btn->Location = System::Drawing::Point(126, 121);
			this->borrowbook_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->borrowbook_btn->Name = L"borrowbook_btn";
			this->borrowbook_btn->Size = System::Drawing::Size(111, 44);
			this->borrowbook_btn->TabIndex = 7;
			this->borrowbook_btn->Text = L"Borrow A Book";
			this->borrowbook_btn->UseVisualStyleBackColor = true;
			this->borrowbook_btn->Click += gcnew System::EventHandler(this, &Form2::button8_Click);
			// 
			// returnbook_btn
			// 
			this->returnbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->returnbook_btn->Location = System::Drawing::Point(126, 218);
			this->returnbook_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->returnbook_btn->Name = L"returnbook_btn";
			this->returnbook_btn->Size = System::Drawing::Size(111, 43);
			this->returnbook_btn->TabIndex = 8;
			this->returnbook_btn->Text = L"Return A Book";
			this->returnbook_btn->UseVisualStyleBackColor = true;
			this->returnbook_btn->Click += gcnew System::EventHandler(this, &Form2::ReturnBook_Click);
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
			// registerlibrarian_btn
			// 
			this->registerlibrarian_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registerlibrarian_btn->Location = System::Drawing::Point(312, 322);
			this->registerlibrarian_btn->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->registerlibrarian_btn->Name = L"registerlibrarian_btn";
			this->registerlibrarian_btn->Size = System::Drawing::Size(111, 42);
			this->registerlibrarian_btn->TabIndex = 10;
			this->registerlibrarian_btn->Text = L"Register a Librarian";
			this->registerlibrarian_btn->UseVisualStyleBackColor = true;
			this->registerlibrarian_btn->Click += gcnew System::EventHandler(this, &Form2::RegisterLibrarian_Click);
			// 
			// view_profile_user_btn
			// 
			this->view_profile_user_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->view_profile_user_btn->Location = System::Drawing::Point(507, 322);
			this->view_profile_user_btn->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->view_profile_user_btn->Name = L"view_profile_user_btn";
			this->view_profile_user_btn->Size = System::Drawing::Size(116, 45);
			this->view_profile_user_btn->TabIndex = 11;
			this->view_profile_user_btn->Text = L"View Profile";
			this->view_profile_user_btn->UseVisualStyleBackColor = true;
			this->view_profile_user_btn->Visible = false;
			this->view_profile_user_btn->Click += gcnew System::EventHandler(this, &Form2::view_profile_user_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(742, 463);
			this->Controls->Add(this->view_profile_user_btn);
			this->Controls->Add(this->registerlibrarian_btn);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->returnbook_btn);
			this->Controls->Add(this->borrowbook_btn);
			this->Controls->Add(this->borrowhistory_btn);
			this->Controls->Add(this->registerstudent_btn);
			this->Controls->Add(this->addbook_btn);
			this->Controls->Add(this->studentslist_btn);
			this->Controls->Add(this->booklist_btn);
			this->Controls->Add(this->button1);
			this->MinimumSize = System::Drawing::Size(754, 489);
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

	private: System::Void StudentsList_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::list_of_students_page^ list_of_students_f = gcnew CppCLR_WinformsProjekt1::list_of_students_page(transfer_id, is_librarian);
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
		if (is_librarian == false)
		{
			this->borrowbook_btn->Visible = false;
			this->studentslist_btn->Visible = false;
			this->returnbook_btn->Visible = false;
			this->addbook_btn->Visible = false;
			this->registerlibrarian_btn->Visible = false;
			this->registerstudent_btn->Visible = false;
			this->view_profile_user_btn->Visible = true;
		}
		//this->view_profile_user->Visible = false;
	}
	private: System::Void AddBook_Click(System::Object^ sender, System::EventArgs^ e) {
		/*CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook;
		this->Hide();
		addbook_f->ShowDialog();*/
		CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook(transfer_id, is_librarian);
		this->Hide();
		if (addbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void RegisterStudent_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::RegisterStudent^ registerstudent_f = gcnew CppCLR_WinformsProjekt1::RegisterStudent(transfer_id, is_librarian);
		this->Hide();
		if (registerstudent_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void BookList_Click(System::Object^ sender, System::EventArgs^ e) {

		CppCLR_WinformsProjekt1::list_of_books_page^ list_of_books_f = gcnew CppCLR_WinformsProjekt1::list_of_books_page(transfer_id, is_librarian);
		this->Hide();
		//list_of_books_f->ShowDialog();
		if (list_of_books_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void BorrowHistory_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::borrow_history_page^ borrow_history_page_f = gcnew CppCLR_WinformsProjekt1::borrow_history_page(transfer_id, is_librarian);
		this->Hide();
		if (borrow_history_page_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::BorrowBook^ borrowbook_f = gcnew CppCLR_WinformsProjekt1::BorrowBook(transfer_id, is_librarian);
		this->Hide();
		if (borrowbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
	private: System::Void ReturnBook_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::ReturnBook^ returnbook_f = gcnew CppCLR_WinformsProjekt1::ReturnBook(transfer_id, is_librarian);
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
	private: System::Void RegisterLibrarian_Click(System::Object^ sender, System::EventArgs^ e) {
		CppCLR_WinformsProjekt1::RegisterLibrarian^ registerlibrarian_f = gcnew CppCLR_WinformsProjekt1::RegisterLibrarian(transfer_id, is_librarian);
		this->Hide();
		if (registerlibrarian_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->Show();
		}
	}
private: System::Void view_profile_user_Click(System::Object^ sender, System::EventArgs^ e) {
	CppCLR_WinformsProjekt1::profile_student^ profile_student_f = gcnew CppCLR_WinformsProjekt1::profile_student(transfer_id, is_librarian);
	this->Hide();
	if (profile_student_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}
}
};
}
