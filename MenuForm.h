#pragma once

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MenuForm : public System::Windows::Forms::Form
	{
		//Constructors
	public:
		MenuForm(void)
		{
			InitializeComponent();
			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

		//Destructor
	protected:
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}

		//Handlers
	private: 
		System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e);

		//Componenst
	private: 
		System::Windows::Forms::Button^ StartButton;
		System::Windows::Forms::TextBox^ StartMoneyTextBox;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			StartButton = (gcnew System::Windows::Forms::Button());
			StartMoneyTextBox = (gcnew System::Windows::Forms::TextBox());
			SuspendLayout();
			// 
			// StartButton
			// 
			StartButton->Location = System::Drawing::Point(723, 577);
			StartButton->Name = L"StartButton";
			StartButton->Size = System::Drawing::Size(240, 101);
			StartButton->TabIndex = 0;
			StartButton->Text = L"Start";
			StartButton->UseVisualStyleBackColor = true;
			StartButton->Click += gcnew System::EventHandler(this, &MenuForm::StartButton_Click);
			// 
			// StartMoneyTextBox
			// 
			StartMoneyTextBox->Location = System::Drawing::Point(723, 209);
			StartMoneyTextBox->Name = L"StartMoneyTextBox";
			StartMoneyTextBox->Size = System::Drawing::Size(216, 22);
			StartMoneyTextBox->TabIndex = 1;
			StartMoneyTextBox->Text = L"1000";
			// 
			// MenuForm
			// 
			AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			ClientSize = System::Drawing::Size(1742, 833);
			Controls->Add(StartMoneyTextBox);
			Controls->Add(StartButton);
			Name = L"MenuForm";
			Text = L"MenuForm";
			ResumeLayout(false);
			PerformLayout();

		}
#pragma endregion
	};
}
