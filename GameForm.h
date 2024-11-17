#pragma once

#include "Core.hpp"

namespace oczko {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace std;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	private:
		Core::Core* core;

	public:
		GameForm(float money)
		{
			core = new Core::Core(money);

			InitializeComponent();

			WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1787, 777);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
