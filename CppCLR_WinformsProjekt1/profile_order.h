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
	/// Summary for profile_order
	/// </summary>
	public ref class profile_order : public System::Windows::Forms::Form
	{
		String^ transfer_order_id;
	public:
		profile_order(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		profile_order(String^ input_for_orderid)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			transfer_order_id = input_for_orderid;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~profile_order()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^ dob_student_txt;
	private: System::Windows::Forms::TextBox^ student_id_txt;
	private: System::Windows::Forms::Label^ label1;
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
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ no_copies_lbl;
	private: System::Windows::Forms::TextBox^ no_copies_txt;
	private: System::Windows::Forms::TextBox^ borrow_stat_txt;
	private: System::Windows::Forms::Label^ borrow_stat_lbl;
	private: System::Windows::Forms::TextBox^ book_id_txt;
	private: System::Windows::Forms::Label^ label2;
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
	private: System::Windows::Forms::Label^ date_issue_lbl;
	private: System::Windows::Forms::Label^ date_return_lbl;
	private: System::Windows::Forms::Label^ fine_lbl;
	private: System::Windows::Forms::TextBox^ date_issue_txt;
	private: System::Windows::Forms::TextBox^ date_return_txt;

	private: System::Windows::Forms::TextBox^ order_fine_txt;
	private: System::Windows::Forms::Label^ order_id_lbl;
	private: System::Windows::Forms::TextBox^ order_id_txt;
	private: System::Windows::Forms::Button^ back_button;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(profile_order::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dob_student_txt = (gcnew System::Windows::Forms::TextBox());
			this->student_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->no_copies_lbl = (gcnew System::Windows::Forms::Label());
			this->no_copies_txt = (gcnew System::Windows::Forms::TextBox());
			this->borrow_stat_txt = (gcnew System::Windows::Forms::TextBox());
			this->borrow_stat_lbl = (gcnew System::Windows::Forms::Label());
			this->book_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->date_issue_lbl = (gcnew System::Windows::Forms::Label());
			this->date_return_lbl = (gcnew System::Windows::Forms::Label());
			this->fine_lbl = (gcnew System::Windows::Forms::Label());
			this->date_issue_txt = (gcnew System::Windows::Forms::TextBox());
			this->date_return_txt = (gcnew System::Windows::Forms::TextBox());
			this->order_fine_txt = (gcnew System::Windows::Forms::TextBox());
			this->order_id_lbl = (gcnew System::Windows::Forms::Label());
			this->order_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->Controls->Add(this->dob_student_txt);
			this->groupBox1->Controls->Add(this->student_id_txt);
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
			this->groupBox1->Location = System::Drawing::Point(88, 86);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(599, 545);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Student Profile";
			// 
			// dob_student_txt
			// 
			this->dob_student_txt->Location = System::Drawing::Point(256, 149);
			this->dob_student_txt->Name = L"dob_student_txt";
			this->dob_student_txt->ReadOnly = true;
			this->dob_student_txt->Size = System::Drawing::Size(150, 26);
			this->dob_student_txt->TabIndex = 18;
			// 
			// student_id_txt
			// 
			this->student_id_txt->Location = System::Drawing::Point(257, 42);
			this->student_id_txt->Name = L"student_id_txt";
			this->student_id_txt->ReadOnly = true;
			this->student_id_txt->Size = System::Drawing::Size(146, 26);
			this->student_id_txt->TabIndex = 17;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(54, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// name_lbl
			// 
			this->name_lbl->AutoSize = true;
			this->name_lbl->Location = System::Drawing::Point(54, 89);
			this->name_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->name_lbl->Name = L"name_lbl";
			this->name_lbl->Size = System::Drawing::Size(51, 20);
			this->name_lbl->TabIndex = 0;
			this->name_lbl->Text = L"Name";
			// 
			// dob_lbl
			// 
			this->dob_lbl->AutoSize = true;
			this->dob_lbl->Location = System::Drawing::Point(54, 158);
			this->dob_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->dob_lbl->Name = L"dob_lbl";
			this->dob_lbl->Size = System::Drawing::Size(99, 20);
			this->dob_lbl->TabIndex = 1;
			this->dob_lbl->Text = L"Date of Birth";
			// 
			// profession_lbl
			// 
			this->profession_lbl->AutoSize = true;
			this->profession_lbl->Location = System::Drawing::Point(54, 237);
			this->profession_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->profession_lbl->Name = L"profession_lbl";
			this->profession_lbl->Size = System::Drawing::Size(84, 20);
			this->profession_lbl->TabIndex = 2;
			this->profession_lbl->Text = L"Profession";
			// 
			// email_id_lbl
			// 
			this->email_id_lbl->AutoSize = true;
			this->email_id_lbl->Location = System::Drawing::Point(54, 317);
			this->email_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->email_id_lbl->Name = L"email_id_lbl";
			this->email_id_lbl->Size = System::Drawing::Size(66, 20);
			this->email_id_lbl->TabIndex = 3;
			this->email_id_lbl->Text = L"Email Id";
			// 
			// mobile_no_lbl
			// 
			this->mobile_no_lbl->AutoSize = true;
			this->mobile_no_lbl->Location = System::Drawing::Point(54, 397);
			this->mobile_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->mobile_no_lbl->Name = L"mobile_no_lbl";
			this->mobile_no_lbl->Size = System::Drawing::Size(83, 20);
			this->mobile_no_lbl->TabIndex = 4;
			this->mobile_no_lbl->Text = L"Mobile No.";
			// 
			// address_txt
			// 
			this->address_txt->Location = System::Drawing::Point(256, 472);
			this->address_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->address_txt->Name = L"address_txt";
			this->address_txt->ReadOnly = true;
			this->address_txt->Size = System::Drawing::Size(148, 26);
			this->address_txt->TabIndex = 11;
			// 
			// address_lbl
			// 
			this->address_lbl->AutoSize = true;
			this->address_lbl->Location = System::Drawing::Point(54, 477);
			this->address_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->address_lbl->Name = L"address_lbl";
			this->address_lbl->Size = System::Drawing::Size(68, 20);
			this->address_lbl->TabIndex = 5;
			this->address_lbl->Text = L"Address";
			// 
			// mobile_no_txt
			// 
			this->mobile_no_txt->Location = System::Drawing::Point(256, 392);
			this->mobile_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->mobile_no_txt->Name = L"mobile_no_txt";
			this->mobile_no_txt->ReadOnly = true;
			this->mobile_no_txt->Size = System::Drawing::Size(148, 26);
			this->mobile_no_txt->TabIndex = 10;
			// 
			// name_txt
			// 
			this->name_txt->Location = System::Drawing::Point(256, 85);
			this->name_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->name_txt->Name = L"name_txt";
			this->name_txt->ReadOnly = true;
			this->name_txt->Size = System::Drawing::Size(148, 26);
			this->name_txt->TabIndex = 6;
			// 
			// email_id_txt
			// 
			this->email_id_txt->Location = System::Drawing::Point(256, 312);
			this->email_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->email_id_txt->Name = L"email_id_txt";
			this->email_id_txt->ReadOnly = true;
			this->email_id_txt->Size = System::Drawing::Size(148, 26);
			this->email_id_txt->TabIndex = 9;
			// 
			// profession_txt
			// 
			this->profession_txt->Location = System::Drawing::Point(256, 232);
			this->profession_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->profession_txt->Name = L"profession_txt";
			this->profession_txt->ReadOnly = true;
			this->profession_txt->Size = System::Drawing::Size(148, 26);
			this->profession_txt->TabIndex = 8;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox2->Controls->Add(this->no_copies_lbl);
			this->groupBox2->Controls->Add(this->no_copies_txt);
			this->groupBox2->Controls->Add(this->borrow_stat_txt);
			this->groupBox2->Controls->Add(this->borrow_stat_lbl);
			this->groupBox2->Controls->Add(this->book_id_txt);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->bookname_lbl);
			this->groupBox2->Controls->Add(this->author_lbl);
			this->groupBox2->Controls->Add(this->price_txt);
			this->groupBox2->Controls->Add(this->publisher_lbl);
			this->groupBox2->Controls->Add(this->edition_no_txt);
			this->groupBox2->Controls->Add(this->edition_no_lbl);
			this->groupBox2->Controls->Add(this->publisher_txt);
			this->groupBox2->Controls->Add(this->price_lbl);
			this->groupBox2->Controls->Add(this->author_txt);
			this->groupBox2->Controls->Add(this->bookname_txt);
			this->groupBox2->Location = System::Drawing::Point(724, 95);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Size = System::Drawing::Size(434, 554);
			this->groupBox2->TabIndex = 20;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Book Profile";
			// 
			// no_copies_lbl
			// 
			this->no_copies_lbl->AutoSize = true;
			this->no_copies_lbl->Location = System::Drawing::Point(26, 396);
			this->no_copies_lbl->Name = L"no_copies_lbl";
			this->no_copies_lbl->Size = System::Drawing::Size(101, 20);
			this->no_copies_lbl->TabIndex = 25;
			this->no_copies_lbl->Text = L"No. of copies";
			// 
			// no_copies_txt
			// 
			this->no_copies_txt->Location = System::Drawing::Point(250, 396);
			this->no_copies_txt->Name = L"no_copies_txt";
			this->no_copies_txt->ReadOnly = true;
			this->no_copies_txt->Size = System::Drawing::Size(148, 26);
			this->no_copies_txt->TabIndex = 24;
			// 
			// borrow_stat_txt
			// 
			this->borrow_stat_txt->Location = System::Drawing::Point(250, 259);
			this->borrow_stat_txt->Name = L"borrow_stat_txt";
			this->borrow_stat_txt->ReadOnly = true;
			this->borrow_stat_txt->Size = System::Drawing::Size(147, 26);
			this->borrow_stat_txt->TabIndex = 23;
			// 
			// borrow_stat_lbl
			// 
			this->borrow_stat_lbl->AutoSize = true;
			this->borrow_stat_lbl->Location = System::Drawing::Point(26, 262);
			this->borrow_stat_lbl->Name = L"borrow_stat_lbl";
			this->borrow_stat_lbl->Size = System::Drawing::Size(110, 20);
			this->borrow_stat_lbl->TabIndex = 22;
			this->borrow_stat_lbl->Text = L"Borrow Status";
			// 
			// book_id_txt
			// 
			this->book_id_txt->Location = System::Drawing::Point(240, 26);
			this->book_id_txt->Name = L"book_id_txt";
			this->book_id_txt->ReadOnly = true;
			this->book_id_txt->Size = System::Drawing::Size(157, 26);
			this->book_id_txt->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 20);
			this->label2->TabIndex = 20;
			this->label2->Text = L"ID";
			// 
			// bookname_lbl
			// 
			this->bookname_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_lbl->AutoSize = true;
			this->bookname_lbl->Location = System::Drawing::Point(26, 75);
			this->bookname_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->bookname_lbl->Name = L"bookname_lbl";
			this->bookname_lbl->Size = System::Drawing::Size(51, 20);
			this->bookname_lbl->TabIndex = 0;
			this->bookname_lbl->Text = L"Name";
			// 
			// author_lbl
			// 
			this->author_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_lbl->AutoSize = true;
			this->author_lbl->Location = System::Drawing::Point(26, 138);
			this->author_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->author_lbl->Name = L"author_lbl";
			this->author_lbl->Size = System::Drawing::Size(57, 20);
			this->author_lbl->TabIndex = 1;
			this->author_lbl->Text = L"Author";
			// 
			// price_txt
			// 
			this->price_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_txt->Location = System::Drawing::Point(250, 483);
			this->price_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->price_txt->Name = L"price_txt";
			this->price_txt->ReadOnly = true;
			this->price_txt->Size = System::Drawing::Size(148, 26);
			this->price_txt->TabIndex = 14;
			// 
			// publisher_lbl
			// 
			this->publisher_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_lbl->AutoSize = true;
			this->publisher_lbl->Location = System::Drawing::Point(26, 206);
			this->publisher_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->publisher_lbl->Name = L"publisher_lbl";
			this->publisher_lbl->Size = System::Drawing::Size(74, 20);
			this->publisher_lbl->TabIndex = 2;
			this->publisher_lbl->Text = L"Publisher";
			// 
			// edition_no_txt
			// 
			this->edition_no_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_txt->Location = System::Drawing::Point(250, 328);
			this->edition_no_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->edition_no_txt->Name = L"edition_no_txt";
			this->edition_no_txt->ReadOnly = true;
			this->edition_no_txt->Size = System::Drawing::Size(148, 26);
			this->edition_no_txt->TabIndex = 12;
			// 
			// edition_no_lbl
			// 
			this->edition_no_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->edition_no_lbl->AutoSize = true;
			this->edition_no_lbl->Location = System::Drawing::Point(26, 332);
			this->edition_no_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->edition_no_lbl->Name = L"edition_no_lbl";
			this->edition_no_lbl->Size = System::Drawing::Size(86, 20);
			this->edition_no_lbl->TabIndex = 4;
			this->edition_no_lbl->Text = L"Edition No.";
			// 
			// publisher_txt
			// 
			this->publisher_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->publisher_txt->Location = System::Drawing::Point(250, 202);
			this->publisher_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->publisher_txt->Name = L"publisher_txt";
			this->publisher_txt->ReadOnly = true;
			this->publisher_txt->Size = System::Drawing::Size(148, 26);
			this->publisher_txt->TabIndex = 10;
			// 
			// price_lbl
			// 
			this->price_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->price_lbl->AutoSize = true;
			this->price_lbl->Location = System::Drawing::Point(27, 488);
			this->price_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->price_lbl->Name = L"price_lbl";
			this->price_lbl->Size = System::Drawing::Size(44, 20);
			this->price_lbl->TabIndex = 6;
			this->price_lbl->Text = L"Price";
			// 
			// author_txt
			// 
			this->author_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->author_txt->Location = System::Drawing::Point(250, 134);
			this->author_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->author_txt->Name = L"author_txt";
			this->author_txt->ReadOnly = true;
			this->author_txt->Size = System::Drawing::Size(148, 26);
			this->author_txt->TabIndex = 9;
			// 
			// bookname_txt
			// 
			this->bookname_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->bookname_txt->Location = System::Drawing::Point(250, 71);
			this->bookname_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bookname_txt->Name = L"bookname_txt";
			this->bookname_txt->ReadOnly = true;
			this->bookname_txt->Size = System::Drawing::Size(148, 26);
			this->bookname_txt->TabIndex = 8;
			// 
			// date_issue_lbl
			// 
			this->date_issue_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_issue_lbl->AutoSize = true;
			this->date_issue_lbl->Location = System::Drawing::Point(1236, 106);
			this->date_issue_lbl->Name = L"date_issue_lbl";
			this->date_issue_lbl->Size = System::Drawing::Size(108, 20);
			this->date_issue_lbl->TabIndex = 26;
			this->date_issue_lbl->Text = L"Date Of Issue";
			// 
			// date_return_lbl
			// 
			this->date_return_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_return_lbl->AutoSize = true;
			this->date_return_lbl->Location = System::Drawing::Point(1236, 229);
			this->date_return_lbl->Name = L"date_return_lbl";
			this->date_return_lbl->Size = System::Drawing::Size(115, 20);
			this->date_return_lbl->TabIndex = 27;
			this->date_return_lbl->Text = L"Date of Return";
			// 
			// fine_lbl
			// 
			this->fine_lbl->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->fine_lbl->AutoSize = true;
			this->fine_lbl->Location = System::Drawing::Point(1261, 313);
			this->fine_lbl->Name = L"fine_lbl";
			this->fine_lbl->Size = System::Drawing::Size(40, 20);
			this->fine_lbl->TabIndex = 28;
			this->fine_lbl->Text = L"Fine";
			// 
			// date_issue_txt
			// 
			this->date_issue_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_issue_txt->Location = System::Drawing::Point(1247, 144);
			this->date_issue_txt->Name = L"date_issue_txt";
			this->date_issue_txt->ReadOnly = true;
			this->date_issue_txt->Size = System::Drawing::Size(103, 26);
			this->date_issue_txt->TabIndex = 29;
			// 
			// date_return_txt
			// 
			this->date_return_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_return_txt->Location = System::Drawing::Point(1243, 269);
			this->date_return_txt->Name = L"date_return_txt";
			this->date_return_txt->ReadOnly = true;
			this->date_return_txt->Size = System::Drawing::Size(100, 26);
			this->date_return_txt->TabIndex = 30;
			// 
			// order_fine_txt
			// 
			this->order_fine_txt->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->order_fine_txt->Location = System::Drawing::Point(1247, 365);
			this->order_fine_txt->Name = L"order_fine_txt";
			this->order_fine_txt->ReadOnly = true;
			this->order_fine_txt->Size = System::Drawing::Size(103, 26);
			this->order_fine_txt->TabIndex = 31;
			// 
			// order_id_lbl
			// 
			this->order_id_lbl->AutoSize = true;
			this->order_id_lbl->Location = System::Drawing::Point(405, 38);
			this->order_id_lbl->Name = L"order_id_lbl";
			this->order_id_lbl->Size = System::Drawing::Size(74, 20);
			this->order_id_lbl->TabIndex = 32;
			this->order_id_lbl->Text = L"Order ID:";
			// 
			// order_id_txt
			// 
			this->order_id_txt->Location = System::Drawing::Point(502, 32);
			this->order_id_txt->Name = L"order_id_txt";
			this->order_id_txt->ReadOnly = true;
			this->order_id_txt->Size = System::Drawing::Size(133, 26);
			this->order_id_txt->TabIndex = 33;
			// 
			// back_button
			// 
			this->back_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_button.Image")));
			this->back_button->Location = System::Drawing::Point(74, 905);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(74, 44);
			this->back_button->TabIndex = 35;
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &profile_order::back_button_Click);
			// 
			// profile_order
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1445, 1019);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->order_id_txt);
			this->Controls->Add(this->order_id_lbl);
			this->Controls->Add(this->order_fine_txt);
			this->Controls->Add(this->date_return_txt);
			this->Controls->Add(this->date_issue_txt);
			this->Controls->Add(this->fine_lbl);
			this->Controls->Add(this->date_return_lbl);
			this->Controls->Add(this->date_issue_lbl);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"profile_order";
			this->Text = L"profile_order";
			this->Load += gcnew System::EventHandler(this, &profile_order::profile_order_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void profile_order_Load(System::Object^ sender, System::EventArgs^ e) {

		CenterToScreen();
		//FormBorderStyle = Windows::Forms::FormBorderStyle::None;
		WindowState = FormWindowState::Maximized;

		//
		//
		//
		//		NEED TO ADD LOADING PROFILES
		//
		//
		this->order_id_txt->Text = transfer_order_id;
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";

		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.borrow_history\
		WHERE order_id = " + transfer_order_id + ";", conDataBase);
		MySqlDataReader^ myReader;
		//MessageBox::Show(transfer_order_id);

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_student_id;
				String^ printing_book_id;
				//String^ printing_date_issue;
				//String^ printing_date_return;
				String^ printing_fine;

				MySql::Data::Types::MySqlDateTime print_date_of_issue;
				MySql::Data::Types::MySqlDateTime print_date_of_return;
				print_date_of_issue = myReader->GetMySqlDateTime("date_issue");
				print_date_of_return = myReader->GetMySqlDateTime("date_returned");


				printing_student_id = myReader->GetString("student_id");
				printing_book_id = myReader->GetString("book_id");
				//printing_date_issue = myReader->GetString("date_issue");
				//printing_date_return = myReader->GetString("date_returned");
				printing_fine = myReader->GetString("borrow_fine");

				this->student_id_txt->Text = printing_student_id;
				this->book_id_txt->Text = printing_book_id;
				//this->date_issue_txt->Text = printing_date_issue;
				//this->date_return_txt->Text = printing_date_return;
				this->order_fine_txt->Text = printing_fine;

				this->date_issue_txt->Text = print_date_of_issue.ToString();
				this->date_return_txt->Text = print_date_of_return.ToString();
			}
			

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
		fill_student_data();
		fill_book_data();
		
	}
	private: void fill_student_data()
	{
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";

		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.student_data WHERE student_id = " + this->student_id_txt->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_name;
				//String^ printing_id;
				String^ printing_profession;
				String^ printing_email;
				String^ printing_mobile;
				String^ printing_address;
				//String^ printing_dob;
				//printing_id = myReader->GetString("student_id");
				MySql::Data::Types::MySqlDateTime print_dob;
				printing_name = myReader->GetString("student_name");
				printing_profession = myReader->GetString("student_profession");
				printing_email = myReader->GetString("student_email");
				printing_mobile = myReader->GetString("student_mobile");
				printing_address = myReader->GetString("student_address");
				//printing_dob = myReader->GetString("student_dob");
				print_dob = myReader->GetMySqlDateTime("student_dob");
				this->name_txt->Text = printing_name;
				//this->student_id_txt->Text = printing_id;
				this->email_id_txt->Text = printing_email;
				this->mobile_no_txt->Text = printing_mobile;
				this->address_txt->Text = printing_address;
				//this->dob_student_txt->Text = printing_dob;
				this->dob_student_txt->Text = print_dob.ToString();
				this->profession_txt->Text = printing_profession;

			}


		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);

		}
	}
	private: void fill_book_data()
	{
		String^ constring = L"datasource=localhost;port=3306;username=root;password=server@?!1234";
		//String^ constring = L"datasource=localhost;port=3306;username=root;password=MySQL";

		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM library_system.book_data WHERE book_id = " + this->book_id_txt->Text + ";", conDataBase);
		MySqlDataReader^ myReader;
		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader();

			while (myReader->Read())
			{
				String^ printing_name;
				
				String^ printing_author;
				String^ printing_publisher;
				String^ printing_price;
				String^ printing_edition_no;
				String^ printing_book_borrow_stat;
				String^ printing_no_of_copies;

				printing_name = myReader->GetString("book_name");
				printing_author = myReader->GetString("book_author");
				printing_publisher = myReader->GetString("book_publisher");
				printing_price = myReader->GetString("book_price");
				printing_edition_no = myReader->GetString("book_edition_no");
				printing_book_borrow_stat = myReader->GetString("book_borrow_status");
				printing_no_of_copies = myReader->GetString("no_of_copies");
				this->bookname_txt->Text = printing_name;
				
				this->author_txt->Text = printing_author;
				this->publisher_txt->Text = printing_publisher;
				this->price_txt->Text = printing_price;
				this->edition_no_txt->Text = printing_edition_no;
				this->borrow_stat_txt->Text = printing_book_borrow_stat;
				this->no_copies_txt->Text = printing_no_of_copies;
				//listBox1->Items->Add(printing_names);

			}
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
