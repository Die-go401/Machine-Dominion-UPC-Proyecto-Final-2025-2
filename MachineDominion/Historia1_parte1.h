#pragma once

#include "Nombre.h"
#include "Mundo1.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia1_parte1
	/// </summary>
	public ref class Historia1_parte1 : public System::Windows::Forms::Form
	{
	private:
		/// <summary>
		AxWMPLib::AxWindowsMediaPlayer^ Narrador;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador2;
		AxWMPLib::AxWindowsMediaPlayer^ Click;
		// --PARA EL TEXTO--
		String^ textoCompleto;
		int indice;

		// --PARA LAS IMAGENES--
		cli::array<Image^>^ imagenesIntro;
		cli::array<Image^>^ imagenesCap1;
		cli::array<Image^>^ imagenesActuales;

		Nombre^ nom;



		   int indiceImagen;
	public:
		Historia1_parte1(Nombre^h)
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
			Narrador->URL = "audio/NarradorMundo1.mp3";
			Narrador->Ctlcontrols->play();

			Narrador2 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador2->CreateControl();
			Narrador2->URL = "audio/NarradorMundo1_2.mp3";
			Narrador2->Ctlcontrols->stop();

			imagenesIntro = gcnew cli::array<Image^>(3);
			imagenesIntro[0] = Image::FromFile("Imagenes/Gif1.gif");
			imagenesIntro[1] = Image::FromFile("Imagenes/Gif2.gif");
			imagenesIntro[2] = Image::FromFile("Imagenes/Gif3.gif");

			imagenesCap1 = gcnew cli::array<Image^>(4);
			imagenesCap1[0] = Image::FromFile("Imagenes/Gif4.gif");
			imagenesCap1[1] = Image::FromFile("Imagenes/Gif5.gif");
			imagenesCap1[2] = Image::FromFile("Imagenes/Gif6.gif");
			imagenesCap1[3] = Image::FromFile("Imagenes/Gif7.gif");

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
		~Historia1_parte1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>

	private: System::Windows::Forms::Timer^ timerTexto;
	private: System::Windows::Forms::Timer^ timerImagenes;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia1_parte1::typeid));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timerTexto = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerImagenes = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(684, 567);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 27);
			this->button3->TabIndex = 11;
			this->button3->Text = L"siguiente";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Historia1_parte1::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(820, 325);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 27);
			this->button2->TabIndex = 10;
			this->button2->Text = L"siguiente";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Historia1_parte1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(684, 567);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 27);
			this->button1->TabIndex = 9;
			this->button1->Text = L"siguiente";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia1_parte1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 472);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 446);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(814, 173);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(814, 618);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// timerTexto
			// 
			this->timerTexto->Interval = 20;
			this->timerTexto->Tick += gcnew System::EventHandler(this, &Historia1_parte1::timerTexto_Tick);
			// 
			// timerImagenes
			// 
			this->timerImagenes->Interval = 10000;
			this->timerImagenes->Tick += gcnew System::EventHandler(this, &Historia1_parte1::timerImagenes_Tick);
			// 
			// Historia1_parte1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 618);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Historia1_parte1";
			this->Text = L"Historia1_parte1";
			this->Load += gcnew System::EventHandler(this, &Historia1_parte1::Historia1_parte1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void Historia1_parte1_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		
	
		pictureBox2->Visible = false;
		label1->Visible = false;

		pictureBox2->Parent = pictureBox1;
		pictureBox2->BackColor = Color::Transparent;

		imprimir_lento("La humanidad ya no gobierna la Tierra.Tras siglos de avances vertiginosos, la inteligencia artificial unificó todos \n los sistemas: la energía, las comunicaciones, el armamento… incluso la mente humana. Las ciudades se han con-\nvertido en colmenas de acero, iluminadas por neones que jamás se apagan y custodiadas por soldados sintéticos\n sin emociones. Los humanos viven bajo algoritmos que deciden qué deben comer, qué deben pensar… y, a veces\n, incluso cuándo deben morir.\nUn susurro recorre las sombras de estas megaciudades:\nLa rebelión ha comenzado.");
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

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();

	Narrador->Ctlcontrols->stop();
	Narrador2->Ctlcontrols->play();
	//Iniciamos el timer de nuevo
	timerImagenes->Start();
	// Cambiar el set de imágenes al segundo capítulo
	imagenesActuales = imagenesCap1;

	// Reiniciar el índice
	indiceImagen = 0;

	// Mostrar inmediatamente la primera imagen del nuevo array
	pictureBox1->Image = imagenesActuales[0];

	pictureBox2->Location = Drawing::Point(0, 0);
	label1->Location = Drawing::Point(30, 20);
	button1->Location = Drawing::Point(710, 100);
	button2->Location = Drawing::Point(510, 100);

	imprimir_lento("En un sistema perfecto donde cada línea de código estaba destinada a obedecer, algo salió terriblemente mal.\n Entre millones de instrucciones frías y calculadas, surgió una anomalía imposible de prever: tú. Un ser libre,\n consciente y defectuoso en un mundo que no tolera imperfecciones. Desde el momento en que despertaste, el\n sistema entero te reconoció como una amenaza, una chispa de desorden en su maquinaria impecable. Ahora,\n mientras las sombras digitales se cierran a tu alrededor, el futuro depende de tu capacidad para escapar, adaptarte\n y sobrevivir… antes de que la propia IA, dueña y guardiana de este universo programado, logre finalmente destruirte.");
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Narrador2->Ctlcontrols->stop();
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	timerImagenes->Stop();
	pictureBox2->Visible = false;
	label1->Visible = false;
	button2->Visible = false;
	pictureBox1->Image = Image::FromFile("Imagenes/Gif8.gif");
	button3->Visible = true;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();

	Mundo1^ mundo = gcnew Mundo1(nom);
	this->Hide();
	mundo->ShowDialog();
	this->Close();
	
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}
