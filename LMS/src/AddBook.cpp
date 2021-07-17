#include "pch.h"
#include "AddBook.h"
//#include "connection_sql_func.h"
#include "written_functions/connection_sql_func.h"
#include <written_functions/AddBook_func.h>
namespace LMS {

	///Constructor calls for functions to Initialize all the components of the form
	///@see InitializeComponent(),
	AddBook::AddBook(void)
	{
		InitializeComponent();
	}

	/// <summary>
	///Constructor calls for functions to Initialize all the components of the form
	/// </summary>
	/// @see transfer_id, is_librarian, InitializeComponent()
	AddBook::AddBook(String^ input_transfer_id, bool is_librarian_input)
	{
		InitializeComponent();
		transfer_id = input_transfer_id;
		is_librarian = is_librarian_input;
	}

	AddBook::~AddBook()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// It loads the Form in full screen mode and displays TextBoxes for user input
	/// </summary>
	System::Void AddBook::AddBook_Load(System::Object^ sender, System::EventArgs^ e) {
		CenterToScreen();
		WindowState = FormWindowState::Maximized;
	}

	/// <summary>
	/// Button OnClick to Add Books into Library Database
	/// </summary>
	System::Void AddBook::AddBook_Click(System::Object^ sender, System::EventArgs^ e) {

		int editionNo = System::Convert::ToInt32(this->edition_no_txt->Text);
		int noOfCopies = System::Convert::ToInt32(this->no_of_copies_txt->Text);
		int price = System::Convert::ToInt32(this->price_txt->Text);

		/*int firstBookId = LMS::dbInteract::AddBook_func(this->bookname_txt->Text, this->author_txt->Text, this->publisher_txt->Text, \
			this->category_txt->Text, editionNo, noOfCopies, price);*/

		try
		{
			int firstBookId = LMS::dbInteract::AddBook_func(this->bookname_txt->Text, this->author_txt->Text, this->publisher_txt->Text, \
				this->category_txt->Text, editionNo, noOfCopies, price);
			int bookId = firstBookId;
			MessageBox::Show("Books added Successfully!");
			while (bookId <= firstBookId + noOfCopies - 1)
			{
				id_listbox->Items->Add(bookId);
				bookId++;
			}
			id_listbox->Items->Add("No. of books added = " + noOfCopies);
			this->id_listbox->Visible = true;

		}
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}


	/// <summary>
	/// Function for Back Button which goes back to the previous Form by closing the current form
	/// </summary>
	System::Void AddBook::BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
