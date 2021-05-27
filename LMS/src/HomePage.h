#pragma once
//***********************************************************************************************
//UNCOMMENT button click functions after adding all other form files
// Keep in mind the new naming scheme instead of "student" it is now "member"
// shift to cpp file after completing
//***********************************************************************************************
#include "list_of_member_page.h"
#include "list_of_books_page.h"
#include "borrow_history_page.h"
#include "profile_member.h"
/*#include "AddBook.h"
#include "RegisterMember.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "RegisterLibrarian.h"*/

//NEW HEADER FILES NEED NOT BE NAMED EXACTLY SAME AS ABOVE BUT BETTER TO FOLLOW OLDER CONVENTION
namespace LMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for HomePage
	/// </summary>
	public ref class HomePage : public System::Windows::Forms::Form
	{
	public:
		String^ transfer_id;
		bool is_librarian;
	public:
		HomePage(void)
		{
			InitializeComponent();
		}
		HomePage(String^ input_transfer_id, bool is_librarian_input)
		{
			transfer_id = input_transfer_id;
			is_librarian = is_librarian_input;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HomePage()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Button^ booklist_btn;
	private: System::Windows::Forms::Button^ member_list_btn;
	private: System::Windows::Forms::Button^ addbook_btn;
	private: System::Windows::Forms::Button^ register_member_btn;
	private: System::Windows::Forms::Button^ borrowhistory_btn;
	private: System::Windows::Forms::Button^ borrowbook_btn;
	private: System::Windows::Forms::Button^ returnbook_btn;
	private: System::Windows::Forms::Button^ logout_button;
	private: System::Windows::Forms::Button^ registerlibrarian_btn;
	private: System::Windows::Forms::Button^ view_profile_member_btn;

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
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->booklist_btn = (gcnew System::Windows::Forms::Button());
			this->member_list_btn = (gcnew System::Windows::Forms::Button());
			this->addbook_btn = (gcnew System::Windows::Forms::Button());
			this->register_member_btn = (gcnew System::Windows::Forms::Button());
			this->borrowhistory_btn = (gcnew System::Windows::Forms::Button());
			this->borrowbook_btn = (gcnew System::Windows::Forms::Button());
			this->returnbook_btn = (gcnew System::Windows::Forms::Button());
			this->logout_button = (gcnew System::Windows::Forms::Button());
			this->registerlibrarian_btn = (gcnew System::Windows::Forms::Button());
			this->view_profile_member_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// exit_button
			// 
			this->exit_button->Location = System::Drawing::Point(12, 632);
			this->exit_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(188, 69);
			this->exit_button->TabIndex = 0;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = true;
			this->exit_button->Click += gcnew System::EventHandler(this, &HomePage::exit_button_Click);
			// 
			// booklist_btn
			// 
			this->booklist_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->booklist_btn->Location = System::Drawing::Point(468, 186);
			this->booklist_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->booklist_btn->Name = L"booklist_btn";
			this->booklist_btn->Size = System::Drawing::Size(182, 68);
			this->booklist_btn->TabIndex = 1;
			this->booklist_btn->Text = L"List of Books";
			this->booklist_btn->UseVisualStyleBackColor = true;
			this->booklist_btn->Click += gcnew System::EventHandler(this, &HomePage::booklist_btn_Click);
			// 
			// member_list_btn
			// 
			this->member_list_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->member_list_btn->Location = System::Drawing::Point(468, 335);
			this->member_list_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->member_list_btn->Name = L"member_list_btn";
			this->member_list_btn->Size = System::Drawing::Size(182, 66);
			this->member_list_btn->TabIndex = 2;
			this->member_list_btn->Text = L"List of Members";
			this->member_list_btn->UseVisualStyleBackColor = true;
			this->member_list_btn->Click += gcnew System::EventHandler(this, &HomePage::member_list_btn_Click);
			// 
			// addbook_btn
			// 
			this->addbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->addbook_btn->Location = System::Drawing::Point(760, 335);
			this->addbook_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addbook_btn->Name = L"addbook_btn";
			this->addbook_btn->Size = System::Drawing::Size(174, 66);
			this->addbook_btn->TabIndex = 3;
			this->addbook_btn->Text = L"Add Book to Library";
			this->addbook_btn->UseVisualStyleBackColor = true;
			this->addbook_btn->Click += gcnew System::EventHandler(this, &HomePage::addbook_btn_Click);
			// 
			// register_member_btn
			// 
			this->register_member_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->register_member_btn->Location = System::Drawing::Point(189, 495);
			this->register_member_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->register_member_btn->Name = L"register_member_btn";
			this->register_member_btn->Size = System::Drawing::Size(166, 65);
			this->register_member_btn->TabIndex = 4;
			this->register_member_btn->Text = L"Register a Member";
			this->register_member_btn->UseVisualStyleBackColor = true;
			this->register_member_btn->Click += gcnew System::EventHandler(this, &HomePage::register_member_btn_Click);
			// 
			// borrowhistory_btn
			// 
			this->borrowhistory_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrowhistory_btn->Location = System::Drawing::Point(760, 186);
			this->borrowhistory_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->borrowhistory_btn->Name = L"borrowhistory_btn";
			this->borrowhistory_btn->Size = System::Drawing::Size(174, 68);
			this->borrowhistory_btn->TabIndex = 5;
			this->borrowhistory_btn->Text = L"Borrow History";
			this->borrowhistory_btn->UseVisualStyleBackColor = true;
			this->borrowhistory_btn->Click += gcnew System::EventHandler(this, &HomePage::borrowhistory_btn_Click);
			// 
			// borrowbook_btn
			// 
			this->borrowbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->borrowbook_btn->Location = System::Drawing::Point(189, 186);
			this->borrowbook_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->borrowbook_btn->Name = L"borrowbook_btn";
			this->borrowbook_btn->Size = System::Drawing::Size(166, 68);
			this->borrowbook_btn->TabIndex = 7;
			this->borrowbook_btn->Text = L"Borrow A Book";
			this->borrowbook_btn->UseVisualStyleBackColor = true;
			this->borrowbook_btn->Click += gcnew System::EventHandler(this, &HomePage::borrowbook_btn_Click);
			// 
			// returnbook_btn
			// 
			this->returnbook_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->returnbook_btn->Location = System::Drawing::Point(189, 335);
			this->returnbook_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->returnbook_btn->Name = L"returnbook_btn";
			this->returnbook_btn->Size = System::Drawing::Size(166, 66);
			this->returnbook_btn->TabIndex = 8;
			this->returnbook_btn->Text = L"Return A Book";
			this->returnbook_btn->UseVisualStyleBackColor = true;
			this->returnbook_btn->Click += gcnew System::EventHandler(this, &HomePage::returnbook_btn_Click);
			// 
			// logout_button
			// 
			this->logout_button->Location = System::Drawing::Point(14, 45);
			this->logout_button->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->logout_button->Name = L"logout_button";
			this->logout_button->Size = System::Drawing::Size(146, 66);
			this->logout_button->TabIndex = 9;
			this->logout_button->Text = L"Logout";
			this->logout_button->UseVisualStyleBackColor = true;
			this->logout_button->Click += gcnew System::EventHandler(this, &HomePage::logout_button_Click);
			// 
			// registerlibrarian_btn
			// 
			this->registerlibrarian_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registerlibrarian_btn->Location = System::Drawing::Point(468, 495);
			this->registerlibrarian_btn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->registerlibrarian_btn->Name = L"registerlibrarian_btn";
			this->registerlibrarian_btn->Size = System::Drawing::Size(166, 65);
			this->registerlibrarian_btn->TabIndex = 10;
			this->registerlibrarian_btn->Text = L"Register a Librarian";
			this->registerlibrarian_btn->UseVisualStyleBackColor = true;
			this->registerlibrarian_btn->Click += gcnew System::EventHandler(this, &HomePage::registerlibrarian_btn_Click);
			// 
			// view_profile_member_btn
			// 
			this->view_profile_member_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->view_profile_member_btn->Location = System::Drawing::Point(760, 495);
			this->view_profile_member_btn->Name = L"view_profile_member_btn";
			this->view_profile_member_btn->Size = System::Drawing::Size(174, 69);
			this->view_profile_member_btn->TabIndex = 11;
			this->view_profile_member_btn->Text = L"View Profile";
			this->view_profile_member_btn->UseVisualStyleBackColor = true;
			this->view_profile_member_btn->Visible = false;
			this->view_profile_member_btn->Click += gcnew System::EventHandler(this, &HomePage::view_profile_member_btn_Click);
			// 
			// HomePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1113, 712);
			this->Controls->Add(this->view_profile_member_btn);
			this->Controls->Add(this->registerlibrarian_btn);
			this->Controls->Add(this->logout_button);
			this->Controls->Add(this->returnbook_btn);
			this->Controls->Add(this->borrowbook_btn);
			this->Controls->Add(this->borrowhistory_btn);
			this->Controls->Add(this->register_member_btn);
			this->Controls->Add(this->addbook_btn);
			this->Controls->Add(this->member_list_btn);
			this->Controls->Add(this->booklist_btn);
			this->Controls->Add(this->exit_button);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(1120, 722);
			this->Name = L"HomePage";
			this->Text = L"HomePage";
			this->Load += gcnew System::EventHandler(this, &HomePage::HomePage_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void borrowbook_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	/*LMS::BorrowBook^ borrowbook_f = gcnew LMS::BorrowBook(transfer_id, is_librarian);
	this->Hide();
	if (borrowbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}*/
}

private: System::Void booklist_btn_Click(System::Object^ sender, System::EventArgs^ e) 	{
	LMS::list_of_books_page^ list_of_books_f = gcnew LMS::list_of_books_page(transfer_id, is_librarian);
	this->Hide();
	if (list_of_books_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}
}

private: System::Void borrowhistory_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	LMS::borrow_history_page^ borrow_history_page_f = gcnew LMS::borrow_history_page(transfer_id, is_librarian);
	this->Hide();
	if (borrow_history_page_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}
}

private: System::Void returnbook_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	/*CppCLR_WinformsProjekt1::ReturnBook^ returnbook_f = gcnew CppCLR_WinformsProjekt1::ReturnBook(transfer_id, is_librarian);
	this->Hide();
	if (returnbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}*/
}

private: System::Void member_list_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	LMS::list_of_member_page^ list_of_member_f = gcnew LMS::list_of_member_page(transfer_id, is_librarian);
	this->Hide();
	if (list_of_member_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}
}

private: System::Void addbook_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	/*CppCLR_WinformsProjekt1::AddBook^ addbook_f = gcnew CppCLR_WinformsProjekt1::AddBook(transfer_id, is_librarian);
	this->Hide();
	if (addbook_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}*/
}

private: System::Void register_member_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	//	CHANGE TO REGISTER MEMBER
	//
	/*CppCLR_WinformsProjekt1::RegisterStudent^ registerstudent_f = gcnew CppCLR_WinformsProjekt1::RegisterStudent(transfer_id, is_librarian);
	this->Hide();
	if (registerstudent_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}*/
}

private: System::Void registerlibrarian_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	/*CppCLR_WinformsProjekt1::RegisterLibrarian^ registerlibrarian_f = gcnew CppCLR_WinformsProjekt1::RegisterLibrarian(transfer_id, is_librarian);
	this->Hide();
	if (registerlibrarian_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}*/
}

private: System::Void view_profile_member_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	//	CHANGE TO PROFILE MEMBER
	//
	LMS::profile_member^ profile_member_f = gcnew LMS::profile_member(transfer_id, is_librarian);
	this->Hide();
	if (profile_member_f->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		this->Show();
	}
}

private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

private: System::Void logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}

private: System::Void HomePage_Load(System::Object^ sender, System::EventArgs^ e) {
	CenterToScreen();
	WindowState = FormWindowState::Maximized;
	if (is_librarian == false)
	{
		this->borrowbook_btn->Visible = false;
		this->member_list_btn->Visible = false;
		this->returnbook_btn->Visible = false;
		this->addbook_btn->Visible = false;
		this->registerlibrarian_btn->Visible = false;
		this->register_member_btn->Visible = false;
		this->view_profile_member_btn->Visible = true;
	}
}
};
}
