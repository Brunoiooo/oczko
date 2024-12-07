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
	public:
		MenuForm(void)
		{
			InitializeComponent();
			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

	protected:
		~MenuForm()
		{
			if (components)
				delete components;
		}

	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::TextBox^ StartMoneyTextBox;
	private: System::Windows::Forms::Label^ start_money_label;
	private: System::Windows::Forms::MenuStrip^ menu_strip;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutMeToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ player_name_textbox;
	private: System::Windows::Forms::Label^ player_name_label;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuForm::typeid));
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->StartMoneyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->start_money_label = (gcnew System::Windows::Forms::Label());
			this->menu_strip = (gcnew System::Windows::Forms::MenuStrip());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutMeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->player_name_textbox = (gcnew System::Windows::Forms::TextBox());
			this->player_name_label = (gcnew System::Windows::Forms::Label());
			this->menu_strip->SuspendLayout();
			this->SuspendLayout();
			// 
			// StartButton
			// 
			this->StartButton->Location = System::Drawing::Point(723, 577);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(240, 101);
			this->StartButton->TabIndex = 0;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &MenuForm::StartButton_Click);
			// 
			// StartMoneyTextBox
			// 
			this->StartMoneyTextBox->Location = System::Drawing::Point(723, 209);
			this->StartMoneyTextBox->Name = L"StartMoneyTextBox";
			this->StartMoneyTextBox->Size = System::Drawing::Size(216, 22);
			this->StartMoneyTextBox->TabIndex = 1;
			this->StartMoneyTextBox->Text = L"1000";
			// 
			// start_money_label
			// 
			this->start_money_label->AutoSize = true;
			this->start_money_label->Location = System::Drawing::Point(720, 190);
			this->start_money_label->Name = L"start_money_label";
			this->start_money_label->Size = System::Drawing::Size(78, 16);
			this->start_money_label->TabIndex = 2;
			this->start_money_label->Text = L"Start money";
			// 
			// menu_strip
			// 
			this->menu_strip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu_strip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->exitToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menu_strip->Location = System::Drawing::Point(0, 0);
			this->menu_strip->Name = L"menu_strip";
			this->menu_strip->Size = System::Drawing::Size(1742, 34);
			this->menu_strip->TabIndex = 3;
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(56, 30);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuForm::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {
				this->aboutMeToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(62, 30);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutMeToolStripMenuItem
			// 
			this->aboutMeToolStripMenuItem->Name = L"aboutMeToolStripMenuItem";
			this->aboutMeToolStripMenuItem->Size = System::Drawing::Size(177, 30);
			this->aboutMeToolStripMenuItem->Text = L"About me";
			this->aboutMeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuForm::aboutMeToolStripMenuItem_Click);
			// 
			// player_name_textbox
			// 
			this->player_name_textbox->Location = System::Drawing::Point(723, 253);
			this->player_name_textbox->Name = L"player_name_textbox";
			this->player_name_textbox->Size = System::Drawing::Size(216, 22);
			this->player_name_textbox->TabIndex = 4;
			this->player_name_textbox->Text = L"Player";
			// 
			// player_name_label
			// 
			this->player_name_label->AutoSize = true;
			this->player_name_label->Location = System::Drawing::Point(720, 234);
			this->player_name_label->Name = L"player_name_label";
			this->player_name_label->Size = System::Drawing::Size(83, 16);
			this->player_name_label->TabIndex = 5;
			this->player_name_label->Text = L"Player name";
			// 
			// MenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1742, 833);
			this->Controls->Add(this->player_name_label);
			this->Controls->Add(this->player_name_textbox);
			this->Controls->Add(this->start_money_label);
			this->Controls->Add(this->StartMoneyTextBox);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->menu_strip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu_strip;
			this->Name = L"MenuForm";
			this->Text = L"MenuForm";
			this->menu_strip->ResumeLayout(false);
			this->menu_strip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void aboutMeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
