#pragma once
#include "Mundo2.h"
#include "Nombre.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia2_parte1
	/// </summary>
	public ref class Historia2_parte1 : public System::Windows::Forms::Form
	{
	public:
		Historia2_parte1(Nombre^h)
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
			Narrador->URL = "audio/NarradorMundo2.mp3";
			Narrador->Ctlcontrols->play();

			imagenesIntro = gcnew cli::array<Image^>(4);
			imagenesIntro[0] = Image::FromFile("Imagenes/Gif12.gif");
			imagenesIntro[1] = Image::FromFile("Imagenes/Gif13.gif");
			imagenesIntro[2] = Image::FromFile("Imagenes/Gif14.gif");
			imagenesIntro[3] = Image::FromFile("Imagenes/Gif15.gif");

			// al inicio usamos las imágenes de la intro
			imagenesActuales = imagenesIntro;

			indiceImagen = 0;
			pictureBox1->Image = imagenesActuales[indiceImagen];

			timerImagenes->Start();
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia2_parte1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private:
		/// <summary>
		Nombre^ nom;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador;
		AxWMPLib::AxWindowsMediaPlayer^ Click;

		// --PARA EL TEXTO--
		String^ textoCompleto;
		int indice;

		// --PARA LAS IMAGENES--
		cli::array<Image^>^ imagenesIntro;
		cli::array<Image^>^ imagenesCap1;
		cli::array<Image^>^ imagenesActuales;
		int indiceImagen;
	private: System::Windows::Forms::Timer^ timerTexto;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timerImagenes;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia2_parte1::typeid));
			this->timerTexto = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerImagenes = (gcnew System::Windows::Forms::Timer(this->components));
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// timerTexto
			// 
			this->timerTexto->Interval = 20;
			this->timerTexto->Tick += gcnew System::EventHandler(this, &Historia2_parte1::timerTexto_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(685, 566);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 27);
			this->button2->TabIndex = 15;
			this->button2->Text = L"siguiente";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Historia2_parte1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(685, 566);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 27);
			this->button1->TabIndex = 14;
			this->button1->Text = L"siguiente";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia2_parte1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 471);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 13;
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
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(814, 618);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// timerImagenes
			// 
			this->timerImagenes->Interval = 8000;
			this->timerImagenes->Tick += gcnew System::EventHandler(this, &Historia2_parte1::timerImagenes_Tick);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(774, 113);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(75, 23);
			this->axWindowsMediaPlayer1->TabIndex = 16;
			// 
			// Historia2_parte1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 618);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Historia2_parte1";
			this->Text = L"Historia2_parte1";
			this->Load += gcnew System::EventHandler(this, &Historia2_parte1::Historia2_parte1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Historia2_parte1_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		pictureBox2->Visible = false;
		label1->Visible = false;

		pictureBox2->Parent = pictureBox1;
		pictureBox2->BackColor = Color::Transparent;
		imprimir_lento("Tras ser teletransportado a lo que parecía otra época, el protagonista corrió sin rumbo hasta llegar a las afueras de\n la ciudad. Allí se encontró con Miguel Ángel, quien aseguró saber dónde estaba Leonardo da Vinci, la única\n persona capaz de ayudarlo. Sin embargo, antes de revelarle su ubicación, Miguel Ángel le dio una misión : debía\n ayudar al bosque cercano, que estaba en peligro.Solo entonces le diría dónde encontrar a Da Vinci.");
	}
private: System::Void timerImagenes_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	indiceImagen++;

	// Si ya llegamos al final del array, detener el timer
	if (indiceImagen >= imagenesActuales->Length) {
		timerImagenes->Stop();  // Detiene la rotación
		indiceImagen = imagenesActuales->Length - 1; // Mantener la última imagen
		return;
	}

	pictureBox1->Image = imagenesActuales[indiceImagen];
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
	// Paramos el timer de nuevo
	timerImagenes->Stop();
	// Cambiamos el backgroundimage del form y desactivamos el picturebox de los gif para la transparencia del panel
	pictureBox1->Image = Image::FromFile("Imagenes/Gif17.gif");

	pictureBox2->Visible = false;
	label1->Visible = false;
	button1->Visible = false;
	button2->Visible = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
    Mundo2^ c2 = gcnew Mundo2(nom);
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
};
}
