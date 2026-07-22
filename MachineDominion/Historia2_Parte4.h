#pragma once
#include "Historia3_parte1.h"
#include "Nombre.h"
#include "Derrota2.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia2_Parte4
	/// </summary>
	public ref class Historia2_Parte4 : public System::Windows::Forms::Form
	{
	public:
		Historia2_Parte4(Nombre^h)
		{
			InitializeComponent();
			//
			nom = h;
			Click = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Click->CreateControl();
			Click->URL = "audio/CLICK.wav";
			Click->Ctlcontrols->stop();

			Narrador = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador->CreateControl();
			Narrador->URL = "audio/NarradorMundo2_2.mp3";
			Narrador->Ctlcontrols->play();
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia2_Parte4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		Nombre^ nom;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador;
		AxWMPLib::AxWindowsMediaPlayer^ Click;

		// --PARA EL TEXTO--
		String^ textoCompleto;
		int indice;
	private: System::Windows::Forms::Timer^ timerTexto;
	private: AxWMPLib::AxWindowsMediaPlayer^ axWindowsMediaPlayer1;
	private: System::ComponentModel::IContainer^ components;
		   /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		void imprimir_lento(String^ texto)
		{
			textoCompleto = texto;
			indice = 0;
			label1->Text = "";   // limpiar el texto
			timerTexto->Start();     // usar el timer del diseñador
		}
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia2_Parte4::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerTexto = (gcnew System::Windows::Forms::Timer(this->components));
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(73, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(684, 376);
			this->panel1->TabIndex = 22;
			this->panel1->Visible = false;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(17, 292);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(646, 60);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Es un ideal romántico, porque tarde o temprano siempre dependeremos de otros.";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Historia2_Parte4::button4_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(17, 211);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(646, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Nos condena a cometer errores inútiles que podrían evitarse con ayuda.";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Historia2_Parte4::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(17, 130);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(646, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Nos permite despertar nuestra creatividad y descubrir soluciones propias.\r\n\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Historia2_Parte4::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(13, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(562, 36);
			this->label2->TabIndex = 0;
			this->label2->Text = L"¿Que valor tiene para nosotros dejar de depender de que todo lo resuelva\r\n una ma"
				L"quina y aprender  a ser independientes\?";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(685, 566);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 27);
			this->button1->TabIndex = 21;
			this->button1->Text = L"siguiente";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia2_Parte4::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 471);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 20;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1, 445);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(814, 173);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 19;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(814, 618);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			// 
			// timerTexto
			// 
			this->timerTexto->Interval = 20;
			this->timerTexto->Tick += gcnew System::EventHandler(this, &Historia2_Parte4::timerTexto_Tick);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(661, 40);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(75, 23);
			this->axWindowsMediaPlayer1->TabIndex = 23;
			// 
			// Historia2_Parte4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 618);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Historia2_Parte4";
			this->Text = L"Historia2_Parte4";
			this->Load += gcnew System::EventHandler(this, &Historia2_Parte4::Historia2_Parte4_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Historia2_Parte4_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		pictureBox2->Visible = false;
		label1->Visible = false;

		// Cambiamos el backgroundimage del form y desactivamos el picturebox de los gif para la transparencia del panel
		pictureBox1->Image = Image::FromFile("Imagenes/Gif18.gif");

		pictureBox2->Parent = pictureBox1;
		pictureBox2->BackColor = Color::Transparent;
		imprimir_lento("Leonardo agradeció al viajero por haberlo ayudado a librarse de la plaga de arañas, y mientras ambos conversaban\n sobre la posibilidad de encontrar una forma de devolverlo a su tiempo, el reloj del protagonista comenzó a emitir un\n brillo extraño. Antes de que Leonardo pudiera advertirle algo, una luz intensa envolvió al viajero y lo arrancó del\n taller. En un instante, el mundo renacentista desapareció, y el protagonista fue arrojado a una época completamente\n distinta, sin poder controlar su destino.");
	}
private: System::Void timerTexto_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	if (indice < textoCompleto->Length)
	{
		label1->Text += textoCompleto[indice];
		indice++;
	}
	else
	{
		timerTexto->Stop();
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Narrador->Ctlcontrols->stop();
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	// Cambiamos el backgroundimage del form y desactivamos el picturebox de los gif para la transparencia del panel
	this->BackgroundImage = Image::FromFile("Imagenes/PreguntaMundo2.png");
	//Activamos el panel
	panel1->Visible = true;
	panel1->BackColor = Color::FromArgb(160, 255, 255, 255);

	pictureBox2->Visible = false;
	label1->Visible = false;
	button1->Visible = false;
	pictureBox1->Visible = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Historia3_parte1^ c2 = gcnew Historia3_parte1(nom);
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Derrota2^ c2 = gcnew Derrota2();
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Derrota2^ c2 = gcnew Derrota2();
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
};
}
