# Library Management System

## Our Design Principle
- Our methodology consists of being Feature-Driven and what should the "End User See or Look At" but with every new feature there also comes the responsibility that no new feature should break any other feature or tamper with the database
- So if any new feature that you are trying to add tries to add, modify, or remove data from the database then it is preferable to not directly use the main database upon which the entire application links with instead create some other test database and test all your functions on that
- Also while developing, it is preferable to keep things as simple and to the point as possible
- If you are adding a new form then do everything step by step and not rush into adding everything in the form at once

| Table of contents |
|------------------|
|[Working Principle](#Working-Principle)|
|[Prerequisites and Installations](#Prerequisites-and-Installations) |
|[Writing Code](#Writing-Code)|
|[Adding New Form](Adding-New-Form)|
|[Adding New Element](Adding-New-Element)|
|[Adding Functions or Methods](Adding-Functions-or-Methods)|
|[Unit Testing Framework](Unit-Testing-Framework)|

## Working Principle
- According to File System for the source code, for every Form/Page, its _.h_ _.cpp_ files are saved in the _**src**_ folder
- Specific to each button and form loading there is a specific function that should be in a separate _.h_ _.cpp_ file or some group of those similar functions should be in a separate _.h_ _.cpp_ file inside _**written_functions**_ folder
- The entire application is based on the Event-Driven Application approach, i.e. the application will do something only on Click-Events such as Button Clicks

## Prerequisites and Installations
1. It is important to be familiar with using Visual Studio as an Integrated Development Environment and install the following packages from Visual Studio Installer
<img src="Screenshots/installation_package1.png" width="75%"></img> <img src="Screenshots/installation_package2.png" width="75%"></img>
<img src="Screenshots/installation_package3.png" width="75%"></img> <img src="Screenshots/installation_package4.png" width="75%"></img>
<img src="Screenshots/installation_package5.png" width="75%"></img>

2. Clone the GitHub Repository in a folder and open the .sln file i.e. LMS.sln (present at the top of the directory)
3. Go to Extensions and Install the following extensions that would be needed to perform certain tasks
[screenshot of extensions]()
4. Make sure that all the NuGet Packages are also installed for the project and added into references for the project

![references for LMS](Screenshots/references_LMS_new.png)
![NuGet Packages](Screenshots/NuGetPackages_new.png)
![references for UnitTesting framework](Screenshots/references_UnitTest_new.png)

5. Install MySQL Community Version from the official website (link) and install for these configurations

## Writing Code
- The entire application is written in C++ and Windows Forms Application Libraries or else known as Microsoft .NET libraries
- The advantages of the libraries being used is that it was developed by Microsoft to enhance C++ to work with Windows API and GUI Framework
- But developers may call ISO C++ Library for functions/methods which are independent of the application or for any other general purpose
- This form of C++ is officially known as C++/CLI according to ECMA
- There are a few minute differences from ISO C++ which the .NET libraries use, i.e. 

System^

gcnew

public ref class 

## Adding New Form
1. To add a new Form, right-click on the project
2. Click on Add → New Item
3. Choose Windows Form from UI
4. Give Appropriate Name which signifies its function or purpose
5. Save the Form in _**src**_ folder

## Adding Functions or Methods

To add a function or a method, it is preferable to add the function in a new _**.h .cpp**_ file inside the folder **written functions**
1. Right-Click on the Project
2. Click on Add → New Item
3. Choose Header File (_.h_) and name it appropriately and save it in the folder **written functions**
4. Repeat the same for Adding Source File (_.cpp_)

If you are adding a method similar to the one which has already been written inside a specific file then add your method to that file as well.

DO NOT forget to include the header file which contains the function in which it is being called

## Unit Testing Framework
In order to use the test framework, make sure that the required references and NuGet Packages are installed and added

1. Copy Paste all the files that need to be tested inside a separate folder in **UnitTesting** (in solution directory)
2. Right Click on _UnitTesting_ Project and then Click Add → Existing Item
3. Choose the required files and click on add
4. Include the files in the _.cpp_ file where all the tests are being written
5. Write the test in this particular format so that the Test Framework can recognize the Test Class

```cpp
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;
using namespace NUnit::Framework;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace Microsoft::VisualStudio::TestTools;

namespace TestLibrary {
	[TestFixture]
	public ref class TestClass1
	{
	public:
		[Test]
		void methodclass() 
    {
			// write expected variables

      //write actual variables which calls the function to be tested

			NUnit::Framework::Assert::AreEqual(expected, actual);

		}
	};
}
```

6. From the menu select **Test** and **Run All tests**