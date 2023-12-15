#pragma once

#include <string>
#include <msclr\marshal_cppstd.h>
#include <random>
#include "stack.h"
const int c = 36;

namespace VisPart {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected: TQueue<int>* qq;
	protected:  Graphics^ g;
	protected: int s, u = 0;
	protected: Random^ rnd;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 64);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(67, 116);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 252);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 600);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

			this-> qq= new TQueue<int>(36);
			this-> g = CreateGraphics();
			this->rnd = gcnew Random();;

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		size_t tmp = 0;
		try {
			string a = msclr::interop::marshal_as<std::string>(textBox1->Text);
			s = stoi(a, &tmp);
		}
		catch (...) {}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		size_t tmp = 0;
		try {
			string a = msclr::interop::marshal_as<std::string>(textBox2->Text);
			u = stoi(a, &tmp);
		}
		catch (...) {}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		if (s&&(rnd->Next() % 100 < s) && (!(qq->IsFull()))) { qq->Push(rnd->Next() % 25); }
		if (u&&(rnd->Next() % 100 < u) && (!(qq->IsEmpty()))) { qq->Pop(); }


		Pen^ l = gcnew Pen(SystemColors::Control);
		l->Width = 40;
		int red = 255 * (qq->GetCount())/c;
		if ((red <200)&&(red>50)) red-=50;
		if (qq->IsFull()) { red = 255; label1->Text = "FILL";}
		Pen^ p = gcnew Pen(System::Drawing::Color::FromArgb(255,red-200*(red==255), 255 - red, 0));
		p->Width = 30;

		g->DrawArc(l, 200, 70, 230, 230, 0,360);
		g->DrawArc(p, 200, 70, 230, 230, 360 * ((qq->GetStart()*1.0) / c), 360 * ((qq->GetCount()*1.0) / c));

		label1->Text = ("begin: "+ qq->GetStart().ToString() + " end: " + qq->GetEnd().ToString());

	}
};
}
