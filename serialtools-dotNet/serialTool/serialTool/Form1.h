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
	private: C8051IF^  dataIF;
	private: System::Windows::Forms::Button^  buttonLowRef;



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
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::MaskedTextBox^  lowerMinusRefText;
	private: System::Windows::Forms::MaskedTextBox^  upperMinusRefText;
	private: System::Windows::Forms::Button^  takeUpperMinusRefButton;
	private: System::Windows::Forms::Button^  takeMidPointAdcButton;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  twaAdcValText;








	private: System::Windows::Forms::Button^  connectButton;

	public: 


		Form1(void)
		{
			InitializeComponent();
			//
			//  Add the constructor code here
			//
			dataIF = gcnew C8051IF();
			TorqueCalc::initClass();
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
			TorqueCalc::destructClass();
		}
	private: System::Windows::Forms::Button^  buttonUpperRef;
	protected: 

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
		System::Windows::Forms::Button^  takeLowerMinusRefButton;
		this->buttonUpperRef = (gcnew System::Windows::Forms::Button());
		this->buttonLowRef = (gcnew System::Windows::Forms::Button());
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
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->label8 = (gcnew System::Windows::Forms::Label());
		this->lowerMinusRefText = (gcnew System::Windows::Forms::MaskedTextBox());
		this->upperMinusRefText = (gcnew System::Windows::Forms::MaskedTextBox());
		this->takeUpperMinusRefButton = (gcnew System::Windows::Forms::Button());
		this->takeMidPointAdcButton = (gcnew System::Windows::Forms::Button());
		this->label9 = (gcnew System::Windows::Forms::Label());
		this->twaAdcValText = (gcnew System::Windows::Forms::TextBox());
		takeLowerMinusRefButton = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// takeLowerMinusRefButton
		// 
		takeLowerMinusRefButton->Location = System::Drawing::Point(191, 282);
		takeLowerMinusRefButton->Name = L"takeLowerMinusRefButton";
		takeLowerMinusRefButton->Size = System::Drawing::Size(120, 23);
		takeLowerMinusRefButton->TabIndex = 25;
		takeLowerMinusRefButton->Text = L"take lower minus ref";
		takeLowerMinusRefButton->UseVisualStyleBackColor = true;
		takeLowerMinusRefButton->Click += gcnew System::EventHandler(this, &Form1::takeLowerMinusRefButton_Click);
		// 
		// buttonUpperRef
		// 
		this->buttonUpperRef->Location = System::Drawing::Point(472, 281);
		this->buttonUpperRef->Name = L"buttonUpperRef";
		this->buttonUpperRef->Size = System::Drawing::Size(106, 23);
		this->buttonUpperRef->TabIndex = 0;
		this->buttonUpperRef->Text = L"take upper ref";
		this->buttonUpperRef->UseVisualStyleBackColor = true;
		this->buttonUpperRef->Click += gcnew System::EventHandler(this, &Form1::buttonUpperRef_Click);
		// 
		// buttonLowRef
		// 
		this->buttonLowRef->Location = System::Drawing::Point(336, 281);
		this->buttonLowRef->Name = L"buttonLowRef";
		this->buttonLowRef->Size = System::Drawing::Size(112, 23);
		this->buttonLowRef->TabIndex = 1;
		this->buttonLowRef->Text = L"take lower ref";
		this->buttonLowRef->UseVisualStyleBackColor = true;
		this->buttonLowRef->Click += gcnew System::EventHandler(this, &Form1::buttonLowRef_Click);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(473, 235);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(113, 13);
		this->label1->TabIndex = 3;
		this->label1->Text = L"upper ref torque [Ncm]";
		this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(336, 234);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(111, 13);
		this->label2->TabIndex = 5;
		this->label2->Text = L"lower ref torque [Ncm]";
		// 
		// lowerRefText
		// 
		this->lowerRefText->Culture = (gcnew System::Globalization::CultureInfo(L""));
		this->lowerRefText->Location = System::Drawing::Point(336, 255);
		this->lowerRefText->Mask = L"999";
		this->lowerRefText->Name = L"lowerRefText";
		this->lowerRefText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		this->lowerRefText->Size = System::Drawing::Size(100, 20);
		this->lowerRefText->TabIndex = 6;
		this->lowerRefText->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::lowerRefText_MaskInputRejected);
		// 
		// upperRefText
		// 
		this->upperRefText->Culture = (gcnew System::Globalization::CultureInfo(L""));
		this->upperRefText->Location = System::Drawing::Point(472, 255);
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
		this->currentADCText->Location = System::Drawing::Point(94, 32);
		this->currentADCText->Name = L"currentADCText";
		this->currentADCText->ReadOnly = true;
		this->currentADCText->Size = System::Drawing::Size(132, 68);
		this->currentADCText->TabIndex = 8;
		this->currentADCText->Text = L"123";
		this->currentADCText->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
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
		this->label4->Location = System::Drawing::Point(24, 413);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(33, 13);
		this->label4->TabIndex = 10;
		this->label4->Text = L"state:";
		// 
		// stateText
		// 
		this->stateText->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->stateText->Location = System::Drawing::Point(70, 413);
		this->stateText->Name = L"stateText";
		this->stateText->ReadOnly = true;
		this->stateText->Size = System::Drawing::Size(297, 13);
		this->stateText->TabIndex = 11;
		this->stateText->Text = L"not ready";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(23, 376);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(77, 13);
		this->label5->TabIndex = 12;
		this->label5->Text = L"com port name";
		// 
		// commPortText
		// 
		this->commPortText->Location = System::Drawing::Point(106, 376);
		this->commPortText->Name = L"commPortText";
		this->commPortText->Size = System::Drawing::Size(86, 20);
		this->commPortText->TabIndex = 13;
		this->commPortText->Text = L"com10";
		// 
		// connectButton
		// 
		this->connectButton->Location = System::Drawing::Point(198, 374);
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
		this->buttonClearRefs->Location = System::Drawing::Point(472, 311);
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
		this->buttonDisconnect->Location = System::Drawing::Point(198, 348);
		this->buttonDisconnect->Name = L"buttonDisconnect";
		this->buttonDisconnect->Size = System::Drawing::Size(75, 23);
		this->buttonDisconnect->TabIndex = 18;
		this->buttonDisconnect->Text = L"disconnect";
		this->buttonDisconnect->UseVisualStyleBackColor = true;
		this->buttonDisconnect->Click += gcnew System::EventHandler(this, &Form1::buttonDisconnect_Click);
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Location = System::Drawing::Point(185, 235);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(126, 13);
		this->label7->TabIndex = 19;
		this->label7->Text = L"lower minus torque [Ncm]";
		// 
		// label8
		// 
		this->label8->AutoSize = true;
		this->label8->Location = System::Drawing::Point(24, 235);
		this->label8->Name = L"label8";
		this->label8->Size = System::Drawing::Size(133, 13);
		this->label8->TabIndex = 20;
		this->label8->Text = L"higher minus torque  [Ncm]";
		// 
		// lowerMinusRefText
		// 
		this->lowerMinusRefText->Culture = (gcnew System::Globalization::CultureInfo(L""));
		this->lowerMinusRefText->Location = System::Drawing::Point(191, 256);
		this->lowerMinusRefText->Mask = L"999";
		this->lowerMinusRefText->Name = L"lowerMinusRefText";
		this->lowerMinusRefText->Size = System::Drawing::Size(100, 20);
		this->lowerMinusRefText->TabIndex = 23;
		this->lowerMinusRefText->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// upperMinusRefText
		// 
		this->upperMinusRefText->Location = System::Drawing::Point(27, 255);
		this->upperMinusRefText->Mask = L"999";
		this->upperMinusRefText->Name = L"upperMinusRefText";
		this->upperMinusRefText->Size = System::Drawing::Size(100, 20);
		this->upperMinusRefText->TabIndex = 24;
		this->upperMinusRefText->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// takeUpperMinusRefButton
		// 
		this->takeUpperMinusRefButton->Location = System::Drawing::Point(27, 282);
		this->takeUpperMinusRefButton->Name = L"takeUpperMinusRefButton";
		this->takeUpperMinusRefButton->Size = System::Drawing::Size(111, 23);
		this->takeUpperMinusRefButton->TabIndex = 26;
		this->takeUpperMinusRefButton->Text = L"take upper minus ref";
		this->takeUpperMinusRefButton->UseVisualStyleBackColor = true;
		this->takeUpperMinusRefButton->Click += gcnew System::EventHandler(this, &Form1::takeUpperMinusRefButton_Click);
		// 
		// takeMidPointAdcButton
		// 
		this->takeMidPointAdcButton->Location = System::Drawing::Point(279, 311);
		this->takeMidPointAdcButton->Name = L"takeMidPointAdcButton";
		this->takeMidPointAdcButton->Size = System::Drawing::Size(108, 23);
		this->takeMidPointAdcButton->TabIndex = 27;
		this->takeMidPointAdcButton->Text = L"take mid Point ADC";
		this->takeMidPointAdcButton->UseVisualStyleBackColor = true;
		this->takeMidPointAdcButton->Click += gcnew System::EventHandler(this, &Form1::takeMidPointAdcButton_Click);
		// 
		// label9
		// 
		this->label9->AutoSize = true;
		this->label9->Location = System::Drawing::Point(23, 119);
		this->label9->Name = L"label9";
		this->label9->Size = System::Drawing::Size(45, 13);
		this->label9->TabIndex = 28;
		this->label9->Text = L"twa adc";
		// 
		// twaAdcValText
		// 
		this->twaAdcValText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->twaAdcValText->Location = System::Drawing::Point(92, 119);
		this->twaAdcValText->Name = L"twaAdcValText";
		this->twaAdcValText->ReadOnly = true;
		this->twaAdcValText->Size = System::Drawing::Size(134, 68);
		this->twaAdcValText->TabIndex = 29;
		this->twaAdcValText->Text = L"456";
		this->twaAdcValText->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(627, 440);
		this->Controls->Add(this->twaAdcValText);
		this->Controls->Add(this->label9);
		this->Controls->Add(this->takeMidPointAdcButton);
		this->Controls->Add(this->takeUpperMinusRefButton);
		this->Controls->Add(takeLowerMinusRefButton);
		this->Controls->Add(this->upperMinusRefText);
		this->Controls->Add(this->lowerMinusRefText);
		this->Controls->Add(this->label8);
		this->Controls->Add(this->label7);
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
		this->Controls->Add(this->buttonLowRef);
		this->Controls->Add(this->buttonUpperRef);
		this->Name = L"Form1";
		this->Text = L"PinionBearingPreloadTorqueMeter";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void buttonUpperRef_Click(System::Object^  sender, System::EventArgs^  e) {
					 int val;
					 try {
						val = (int) Convert::ToInt16( this->upperRefText->Text);
					 }catch (Exception^ ex1) {
							val = 0;
					 }
					 TorqueCalc::setHighRefNcm(val);

			 }
	private: System::Void buttonLowRef_Click(System::Object^  sender, System::EventArgs^  e) {
					 int val;
					 try {
						val = (int) Convert::ToInt16( this->lowerRefText->Text);
					 }catch (Exception^ ex1) {
							val = 0;
					 }
					 TorqueCalc::setLowRefNcm(val);
					 int v1 = 9;
					 //Debug::WriteLine("\nhello ");
					 //Debug::WriteLine(String::Format("hello world "));
					 //Debug::WriteLine(String::Format("{0} val ",v1));
					 Debug::WriteLine(String::Format("{0} val {1,9:N3}",8,123.456789));
			 }


		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
					 int adcVal;
					 int ncmVal;
					 int twaVal;
					 TorqueCalc::resultTorqueNcm( adcVal,ncmVal, twaVal) ; 
					 // TODO add calculator and call from here
					 twaAdcValText->Text = String::Format("{0}",twaVal);
					 currentADCText->Text = String::Format("{0}",adcVal);
					 textBoxNcm->Text = String::Format("{0}",ncmVal);
					 twaAdcValText->Invalidate();
					 this->currentADCText->Invalidate();
					 textBoxNcm->Invalidate();

					String^ st1 = gcnew String("");
					if (C8051IF::isInterfaceRunning(&st1)) {
						connectButton->Enabled = false;
						buttonDisconnect->Enabled = true;
					} else {
						connectButton->Enabled = true;
						buttonDisconnect->Enabled = false;
					}
					connectButton->Invalidate();
					buttonDisconnect->Invalidate();
					
					st1 += " / calc ";
					TorqueCalc::isCalibValid(&st1);

					this->stateText->Text = st1;
					this->stateText->Invalidate();

					 this->Update();
				 }


		private: System::Void buttonClearRefs_Click(System::Object^  sender, System::EventArgs^  e) 
		{
		   if ((MessageBox::Show(
				 "Are you sure that you want to clear all calibration reference values?", 
				 "Clear all Refs", MessageBoxButtons::YesNo, 
				 MessageBoxIcon::Question,MessageBoxDefaultButton::Button2) == System::Windows::Forms::DialogResult::Yes  )){

					 TorqueCalc::clearRefs();
						
					lowerMinusRefText->Text= L"";
					lowerMinusRefText->Invalidate();
					upperMinusRefText->Text = L"";
					upperMinusRefText->Invalidate();


					 lowerRefText->Text= L"";
					lowerRefText->Invalidate();
					upperRefText->Text = L"";
					upperRefText->Invalidate();
					this->Update();
			  }

		}

		 private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			dataIF->singleton8051IF->start(this->commPortText->Text );
		 }

		private: System::Void buttonDisconnect_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			dataIF->singleton8051IF->stop();		 
		}
private: System::Void lowerRefText_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->timer1->Start();
			 }

public:
	static void logException(Exception^ ex1)
	{
		Debug::WriteLine(String::Format("C8051IF exception {0} source: {1}\nmessage : {2}\nstack: {3}",
											ex1->ToString(),ex1->Source,ex1->Message,ex1->StackTrace));
	}



private: System::Void takeLowerMinusRefButton_Click(System::Object^  sender, System::EventArgs^  e) {
					 int val;
					 try {
						val = (int) Convert::ToInt16( this->lowerMinusRefText->Text);
					 }catch (Exception^ ex1) {
							val = 0;
					 }
					 TorqueCalc::setLowMinusRefNcm(val);



			 }




private: System::Void takeUpperMinusRefButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
			 		int val;
					 try {
						val = (int) Convert::ToInt16( this->upperMinusRefText->Text);
					 }catch (Exception^ ex1) {
							val = 0;
					 }
					 TorqueCalc::setHighMinusRefNcm(val);

			 
			 }


private: System::Void takeMidPointAdcButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 TorqueCalc::setMidPointADC();
}
};  // class
}  // namespace

