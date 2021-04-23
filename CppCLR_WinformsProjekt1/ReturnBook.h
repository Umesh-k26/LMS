#pragma once
namespace CppCLR_WinformsProjekt1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ReturnBook
	/// </summary>
	public ref class ReturnBook : public System::Windows::Forms::Form
	{
	public:
		ReturnBook(void)
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
		~ReturnBook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ order_id_lbl;
	protected:
	private: System::Windows::Forms::TextBox^ order_id_txt;
	private: System::Windows::Forms::Button^ return_button;
	private: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReturnBook::typeid));
			this->order_id_lbl = (gcnew System::Windows::Forms::Label());
			this->order_id_txt = (gcnew System::Windows::Forms::TextBox());
			this->return_button = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// order_id_lbl
			// 
			this->order_id_lbl->AutoSize = true;
			this->order_id_lbl->Location = System::Drawing::Point(459, 197);
			this->order_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->order_id_lbl->Name = L"order_id_lbl";
			this->order_id_lbl->Size = System::Drawing::Size(70, 20);
			this->order_id_lbl->TabIndex = 0;
			this->order_id_lbl->Text = L"Order ID";
			// 
			// order_id_txt
			// 
			this->order_id_txt->Location = System::Drawing::Point(652, 192);
			this->order_id_txt->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->order_id_txt->Name = L"order_id_txt";
			this->order_id_txt->Size = System::Drawing::Size(148, 26);
			this->order_id_txt->TabIndex = 1;
			// 
			// return_button
			// 
			this->return_button->Location = System::Drawing::Point(552, 428);
			this->return_button->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->return_button->Name = L"return_button";
			this->return_button->Size = System::Drawing::Size(112, 35);
			this->return_button->TabIndex = 2;
			this->return_button->Text = L"Return ";
			this->return_button->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(105, 85);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(51, 39);
			this->button1->TabIndex = 16;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ReturnBook::button1_Click);
			// 
			// ReturnBook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1144, 834);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->return_button);
			this->Controls->Add(this->order_id_txt);
			this->Controls->Add(this->order_id_lbl);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"ReturnBook";
			this->Text = L"ReturnBook";
			this->Load += gcnew System::EventHandler(this, &ReturnBook::ReturnBook_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ReturnBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
};
}
