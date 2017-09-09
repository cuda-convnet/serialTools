#pragma once

#include "TorqueCalc.h"
#include "8051IF.h"

namespace serialTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		int upperADCgiven;
		int upperADC;
		int lowerADCgiven;
		int lowerADC;

	private: C8051IF^  dataIF;

	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MaskedTextBox^  lowerRefText;
	private: System::Windows::Forms::MaskedTextBox^  upperRefText;
	private: System::Windows::Forms::TextBox^  currentADCText;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  stateText;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  commPortText;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxNcm;
	private: System::Windows::Forms::Button^  buttonClearRefs;
	private: System::Windows::Forms::Button^  buttonDisconnect;

	private: System::Windows::Forms::Button^  connectButton;

	public: 


		Form1(void)
		{
			InitializeComponent();
			//
			//  Add the constructor code here
			//
			upperADCgiven = 0;
			upperADC = 0;
			lowerADCgiven = 0;
			lowerADC = 0;
			dataIF = gcnew C8051IF();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->components = (gcnew System::ComponentModel::Container());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->lowerRefText = (gcnew System::Windows::Forms::MaskedTextBox());
		this->upperRefText = (gcnew System::Windows::Forms::MaskedTextBox());
		this->currentADCText = (gcnew System::Windows::Forms::TextBox());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->stateText = (gcnew System::Windows::Forms::TextBox());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->commPortText = (gcnew System::Windows::Forms::TextBox());
		this->connectButton = (gcnew System::Windows::Forms::Button());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->textBoxNcm = (gcnew System::Windows::Forms::TextBox());
		this->buttonClearRefs = (gcnew System::Windows::Forms::Button());
		this->buttonDisconnect = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(451, 280);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(106, 23);
		this->button1->TabIndex = 0;
		this->button1->Text = L"take upper ref";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(301, 280);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(112, 23);
		this->button2->TabIndex = 1;
		this->button2->Text = L"take lower ref";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(452, 234);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(113, 13);
		this->label1->TabIndex = 3;
		this->label1->Text = L"upper ref torque [Ncm]";
		this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(301, 233);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(111, 13);
		this->label2->TabIndex = 5;
		this->label2->Text = L"lower ref torque [Ncm]";
		// 
		// lowerRefText
		// 
		this->lowerRefText->Culture = (gcnew System::Globalization::CultureInfo(L""));
		this->lowerRefText->Location = System::Drawing::Point(301, 254);
		this->lowerRefText->Mask = L"999";
		this->lowerRefText->Name = L"lowerRefText";
		this->lowerRefText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		this->lowerRefText->Size = System::Drawing::Size(100, 20);
		this->lowerRefText->TabIndex = 6;
		// 
		// upperRefText
		// 
		this->upperRefText->Culture = (gcnew System::Globalization::CultureInfo(L""));
		this->upperRefText->Location = System::Drawing::Point(451, 254);
		this->upperRefText->Mask = L"999";
		this->upperRefText->Name = L"upperRefText";
		this->upperRefText->Size = System::Drawing::Size(100, 20);
		this->upperRefText->TabIndex = 7;
		this->upperRefText->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// currentADCText
		// 
		this->currentADCText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->currentADCText->Location = System::Drawing::Point(94, 47);
		this->currentADCText->Name = L"currentADCText";
		this->currentADCText->ReadOnly = true;
		this->currentADCText->Size = System::Drawing::Size(132, 68);
		this->currentADCText->TabIndex = 8;
		this->currentADCText->Text = L"123";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(21, 32);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(57, 13);
		this->label3->TabIndex = 9;
		this->label3->Text = L"result ADC";
		this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(21, 323);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(33, 13);
		this->label4->TabIndex = 10;
		this->label4->Text = L"state:";
		this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
		// 
		// stateText
		// 
		this->stateText->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->stateText->Location = System::Drawing::Point(67, 323);
		this->stateText->Name = L"stateText";
		this->stateText->ReadOnly = true;
		this->stateText->Size = System::Drawing::Size(297, 13);
		this->stateText->TabIndex = 11;
		this->stateText->Text = L"not ready";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(32, 282);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(77, 13);
		this->label5->TabIndex = 12;
		this->label5->Text = L"com port name";
		// 
		// commPortText
		// 
		this->commPortText->Location = System::Drawing::Point(115, 282);
		this->commPortText->Name = L"commPortText";
		this->commPortText->Size = System::Drawing::Size(86, 20);
		this->commPortText->TabIndex = 13;
		this->commPortText->Text = L"com1";
		// 
		// connectButton
		// 
		this->connectButton->Location = System::Drawing::Point(207, 280);
		this->connectButton->Name = L"connectButton";
		this->connectButton->Size = System::Drawing::Size(75, 23);
		this->connectButton->TabIndex = 14;
		this->connectButton->Text = L"connect";
		this->connectButton->UseVisualStyleBackColor = true;
		this->connectButton->Click += gcnew System::EventHandler(this, &Form1::connectButton_Click);
		// 
		// timer1
		// 
		this->timer1->Interval = 1000;
		this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Location = System::Drawing::Point(276, 32);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(57, 13);
		this->label6->TabIndex = 15;
		this->label6->Text = L"result Ncm";
		// 
		// textBoxNcm
		// 
		this->textBoxNcm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 70, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->textBoxNcm->Location = System::Drawing::Point(336, 47);
		this->textBoxNcm->Name = L"textBoxNcm";
		this->textBoxNcm->ReadOnly = true;
		this->textBoxNcm->Size = System::Drawing::Size(201, 113);
		this->textBoxNcm->TabIndex = 16;
		this->textBoxNcm->Text = L"000";
		this->textBoxNcm->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// buttonClearRefs
		// 
		this->buttonClearRefs->Location = System::Drawing::Point(451, 310);
		this->buttonClearRefs->Name = L"buttonClearRefs";
		this->buttonClearRefs->Size = System::Drawing::Size(114, 23);
		this->buttonClearRefs->TabIndex = 17;
		this->buttonClearRefs->Text = L"cleaar ref values";
		this->buttonClearRefs->UseVisualStyleBackColor = true;
		this->buttonClearRefs->Click += gcnew System::EventHandler(this, &Form1::buttonClearRefs_Click);
		// 
		// buttonDisconnect
		// 
		this->buttonDisconnect->Enabled = false;
		this->buttonDisconnect->Location = System::Drawing::Point(207, 254);
		this->buttonDisconnect->Name = L"buttonDisconnect";
		this->buttonDisconnect->Size = System::Drawing::Size(75, 23);
		this->buttonDisconnect->TabIndex = 18;
		this->buttonDisconnect->Text = L"disconnect";
		this->buttonDisconnect->UseVisualStyleBackColor = true;
		this->buttonDisconnect->Click += gcnew System::EventHandler(this, &Form1::buttonDisconnect_Click);
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(570, 345);
		this->Controls->Add(this->buttonDisconnect);
		this->Controls->Add(this->buttonClearRefs);
		this->Controls->Add(this->textBoxNcm);
		this->Controls->Add(this->label6);
		this->Controls->Add(this->connectButton);
		this->Controls->Add(this->commPortText);
		this->Controls->Add(this->label5);
		this->Controls->Add(this->stateText);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->currentADCText);
		this->Controls->Add(this->upperRefText);
		this->Controls->Add(this->lowerRefText);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->Name = L"Form1";
		this->Text = L"PinionBearingPreloadTorqueMeter";
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (upperADCgiven == 1)  {
					 upperADCgiven = 0;
					 upperADC = 0;
					this->button1->Text = L"take upper ref";
				 } else  {
					 upperADCgiven = 1;
					 upperADC = 1;
					this->button1->Text = L"clear upper ref";
				 }			
					this->button1->Invalidate();
					this->Update();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (lowerADCgiven == 1)  {
					 lowerADCgiven = 0;
					 lowerADC = 0;
					this->button2->Text = L"take lower ref";
				 } else  {
					 lowerADCgiven = 1;
					 lowerADC = 1;
					this->button2->Text = L"clear lower ref";
				 }			
					this->button2->Invalidate();
					this->Update();

			 }


		private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
				 }

		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
					 int adcVal;
					 int ncmVal;
					 TorqueCalc::resultTorqueNcm( adcVal,ncmVal) ; 
					 // TODO add calculator and call from here
					 currentADCText->Text = String::Format("%i",adcVal);
					 textBoxNcm->Text = String::Format("%i",ncmVal);
					 this->currentADCText->Invalidate();

					String^ st1 = gcnew String("");
					if (C8051IF::isInterfaceRunning(st1)) {
						connectButton->Enabled = false;
						buttonDisconnect->Enabled = true;
					} else {
						connectButton->Enabled = true;
						buttonDisconnect->Enabled = false;
					}
					connectButton->Invalidate();
					buttonDisconnect->Invalidate();
					
					st1->Insert(st1->Length," ");
					TorqueCalc::isCalibValid(st1);

					this->stateText->Text = st1;
					this->stateText->Invalidate();

					 this->Update();
				 }


		private: System::Void buttonClearRefs_Click(System::Object^  sender, System::EventArgs^  e) 
		{
				 TorqueCalc::clearRefs();
				 lowerRefText->Text= L"";
				lowerRefText->Invalidate();
				upperRefText->Text = L"";
				upperRefText->Invalidate();
				this->Update();

		}

		 private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			
		 }

		private: System::Void buttonDisconnect_Click(System::Object^  sender, System::EventArgs^  e) 
		{
					 
		}
};  // class
}  // namespace

