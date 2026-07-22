#pragma once
#include "RANK.h"
#include "Nombre.h"
#include "Controlador3.h"
#include "Historia3_parte2.h"
#include "Derrota3.h"



namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Mundo3
	/// </summary>
	public ref class Mundo3 : public System::Windows::Forms::Form
	{
	private:
		
		Nombre^ nom;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoBala;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoBalaE;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoRafaga1;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoRafaga2;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoRafaga3;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoFuego;
		AxWMPLib::AxWindowsMediaPlayer^ SonidoHielo;
		AxWMPLib::AxWindowsMediaPlayer^ Musica;
		int contador;
		int contador3;
		controlador3* control3;
		Bitmap^ jugador;
		Bitmap^ Jefe;
		Bitmap^ JefeFuria;
		Bitmap^ soldado;
		Bitmap^ BolaFuego;
		Bitmap^ BalaPrincipal;
		Bitmap^ Balaenemigo;
		Bitmap^ fondo;
		Bitmap^ fondo2;
		Bitmap^ balajefe;
		Bitmap^ BolaHielo;
		Bitmap^ r_derecha;
		Bitmap^ r_izquierda;
		Bitmap^ r_arriba;
		Bitmap^ r_abajo;
		Bitmap^ ultra;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label7;



		   int contador2; //Contador para congelado
	public:
		Mundo3(Nombre^h)
		{
			InitializeComponent();
			nom = h;
			CrearArchivo();

			this->KeyPreview = true;
			control3 = new controlador3();
			jugador = gcnew Bitmap("Imagenes/Principal.png");
			fondo = gcnew Bitmap("Imagenes/Mapa3.png");
			Jefe = gcnew Bitmap("Imagenes/Jefe.png");
			JefeFuria = gcnew Bitmap("Imagenes/Jefe_loco.png");
			soldado = gcnew Bitmap("Imagenes/Robot.png");
			BolaFuego = gcnew Bitmap("Imagenes/Fireball.png");
			BalaPrincipal = gcnew Bitmap("Imagenes/balaPrincipal.png");
			Balaenemigo = gcnew Bitmap("Imagenes/balaEnemigo.png");
			fondo2 = gcnew Bitmap("Imagenes/M3P2.png");
			balajefe = gcnew Bitmap("Imagenes/balaJefe.png");
			BolaHielo = gcnew Bitmap("Imagenes/bolahielo.png");
			r_derecha = gcnew Bitmap("Imagenes/RayoDerecha.png");
			r_izquierda = gcnew Bitmap("Imagenes/RayoIzquierda.png");
			r_abajo = gcnew Bitmap("Imagenes/RayoAbajo.png");
			r_arriba = gcnew Bitmap("Imagenes/RayoArriba.png");
			ultra = gcnew Bitmap("Imagenes/PrincipalUltra.png");
			contador = 0;
			contador2 = 0;
			contador3 = 0;
			Musica = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Musica->CreateControl();
			Musica->URL = "audio/BatallaFinal.mp3";
			Musica->Ctlcontrols->play();

			SonidoBala = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoBala->CreateControl();
			SonidoBala->URL = "audio/SonidoBala.mp3";
			SonidoBala->Ctlcontrols->stop();

			SonidoBalaE = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoBalaE->CreateControl();
			SonidoBalaE->URL = "audio/SonidoBalaE.mp3";
			SonidoBalaE->Ctlcontrols->stop();

			SonidoRafaga1 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoRafaga1->CreateControl();
			SonidoRafaga1->URL = "audio/SonidoRafaga1.mp3";
			SonidoRafaga1->Ctlcontrols->stop();

			SonidoRafaga2 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoRafaga2->CreateControl();
			SonidoRafaga2->URL = "audio/SonidoRafaga2.mp3";
			SonidoRafaga2->Ctlcontrols->stop();

			SonidoRafaga3 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoRafaga3->CreateControl();
			SonidoRafaga3->URL = "audio/SonidoRafaga3.mp3";
			SonidoRafaga3->Ctlcontrols->stop();

			SonidoFuego = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoFuego->CreateControl();
			SonidoFuego->URL = "audio/SonidoFuego.mp3";
			SonidoFuego->Ctlcontrols->stop();

			SonidoHielo = gcnew AxWMPLib::AxWindowsMediaPlayer();
			SonidoHielo->CreateControl();
			SonidoHielo->URL = "audio/SonidoHielo.mp3";
			SonidoHielo->Ctlcontrols->stop();
		}
		
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Mundo3()
		{
			if (components)
			{
				delete components;
			}
			delete control3;
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		string toStdString(String^ texto) {
			using namespace Runtime::InteropServices;
			IntPtr ptr = Marshal::StringToHGlobalAnsi(texto);
			std::string result = static_cast<const char*>(ptr.ToPointer());
			Marshal::FreeHGlobal(ptr);
			return result;
		}
		void CrearArchivo() {
			ifstream archivo("RANKING.dat", ios::binary);
			if (!archivo.good()) {
				ofstream nuevo("RANKING.dat", ios::out | ios::binary);
			}
		}



		void Grabar(string nombre, int vidas) {
			ofstream archivo;
			Datos p;

			archivo.open("RANKING.dat", ios::out | ios::app | ios::binary);

			if (archivo.is_open()) {
				strncpy(p.NOMBRE, nombre.c_str(), sizeof(p.NOMBRE));
				p.NOMBRE[sizeof(p.NOMBRE) - 1] = '\0';

				p.VIDAS = vidas;
				p.PUNTAJE = vidas * 500;

				archivo.write((const char*)&p, sizeof(p));
				archivo.close();
			}
		}

		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Mundo3::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(750, 760);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(104, 231);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(542, 297);
			this->panel2->TabIndex = 23;
			this->panel2->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Yellow;
			this->label9->Location = System::Drawing::Point(310, 102);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(241, 26);
			this->label9->TabIndex = 25;
			this->label9->Text = L"RAYO LASER (1 USO)";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label9->Click += gcnew System::EventHandler(this, &Mundo3::label9_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(321, 183);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(126, 26);
			this->label8->TabIndex = 24;
			this->label8->Text = L"DISPARAR";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(31, 102);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(153, 120);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(231, 167);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(75, 56);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(231, 93);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(75, 56);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(240, 241);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(74, 32);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Cerrar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Mundo3::button6_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Yellow;
			this->label4->Location = System::Drawing::Point(39, 69);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 26);
			this->label4->TabIndex = 18;
			this->label4->Text = L"MOVIMIENTO\r\n";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label7->Location = System::Drawing::Point(150, 15);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(263, 44);
			this->label7->TabIndex = 19;
			this->label7->Text = L"CONTROLES";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Mundo3::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Mundo3::timer2_Tick);
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Location = System::Drawing::Point(749, 2);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(235, 757);
			this->panel4->TabIndex = 3;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel5->Controls->Add(this->label6);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Controls->Add(this->label1);
			this->panel5->Location = System::Drawing::Point(9, 10);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(217, 359);
			this->panel5->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(2, 127);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(151, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"VIDA DEL JEFE: \r\n";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(2, 193);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(157, 60);
			this->label5->TabIndex = 4;
			this->label5->Text = L"OBJETIVO:\r\n\r\nELIMINA AL JEFE\r\n";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(2, 89);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"VIDAS:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(2, 54);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"NOMBRE:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(28, 10);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MUNDO 3";
			// 
			// Mundo3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 761);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Name = L"Mundo3";
			this->Text = L"Mundo3";
			this->Load += gcnew System::EventHandler(this, &Mundo3::Mundo3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo3::Mundo3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Mundo3::Mundo3_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Mundo3_Load(System::Object^ sender, System::EventArgs^ e) {
		
	


		panel5->BackColor = Color::FromArgb(160, 0, 0, 0);
		panel2->BackColor = Color::FromArgb(160, 0, 0, 0);
		panel2->Visible = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		//Borrar
		buffer->Graphics->DrawImage(panel1->BackgroundImage, panel1->ClientRectangle);
		//estadisticas
		label2->Text = "NOMBRE: " + nom->getName();
		label3->Text = "VIDAS: " + control3->getJugador()->getVida();

		label6->Text = "VIDA DEL JEFE: \n"+control3->getJefe()->getVida();
		//SONIDOS X-X ------------------------------------------------------------------------

		//Soldados
		for (int i = 0; i < control3->getJefe()->getSoldados().size(); i++)
		{
			if (control3->getJefe()->getSoldados()[i]->getsonidosBalaEnemigo())
			{
				SonidoBalaE->Ctlcontrols->stop();
				SonidoBalaE->Ctlcontrols->play();

				control3->getJefe()->getSoldados()[i]->setsonidoBalaEnemigo(false);
			}
		}
		if(control3->getJefe()->getRafagaBalas1())
		{
			SonidoRafaga1->Ctlcontrols->stop();
			SonidoRafaga1->Ctlcontrols->play();
			
			control3->getJefe()->setRafagaBalas1(false);
		}
		if (control3->getJefe()->getRafagaBalas2())
		{
			SonidoRafaga2->Ctlcontrols->stop();
			SonidoRafaga2->Ctlcontrols->play();

			control3->getJefe()->setRafagaBalas2(false);
		}
		if (control3->getJefe()->getRafagaBalas3())
		{
			SonidoRafaga3->Ctlcontrols->stop();
			SonidoRafaga3->Ctlcontrols->play();

			control3->getJefe()->setRafagaBalas3(false);
		}
		if(control3->getJefe()->getNormal())
		{
			SonidoBalaE->Ctlcontrols->stop();
			SonidoBalaE->Ctlcontrols->play();

			control3->getJefe()->setNormal(false);
		}
		if (control3->getJefe()->getFuego())
		{
			SonidoFuego->Ctlcontrols->stop();
			SonidoFuego->Ctlcontrols->play();

			control3->getJefe()->setFuego(false);
		}

		//Mover y dibujar
		if (control3->getRayoDisparado() == false)
			control3->ControlGeneral(buffer->Graphics, jugador, Jefe, JefeFuria, soldado, BalaPrincipal, Balaenemigo, balajefe, BolaFuego, BolaHielo, r_derecha, r_izquierda, r_abajo, r_arriba);
		if (control3->getRayoDisparado() == true)
			control3->ControlGeneral(buffer->Graphics, ultra, Jefe, JefeFuria, soldado, BalaPrincipal, Balaenemigo, balajefe, BolaFuego, BolaHielo, r_derecha, r_izquierda, r_abajo, r_arriba);
		contador3 += timer1->Interval;
		if (contador3 >= 3000) {
			contador3 = 0;
			control3->getJefe()->RafagaBalas1();
		}
		buffer->Render(g);
		//Condicion de derrota
		if (control3->getJugador()->getVida() <= 0) {
			timer1->Stop();
			Musica->Ctlcontrols->stop();
			Derrota3^ c2 = gcnew Derrota3();
			this->Hide();
			c2->ShowDialog();
			this->Close();
		}
		if (control3->getJefe()->getFuria() == true) {
			timer2->Enabled = true;
			timer1->Enabled = false;
		}
		delete buffer;
		delete g;
		delete intervalo;





	}
	private: System::Void Mundo3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up: {
			control3->getJugador()->setDireccion(Arriba);
			break;

		}
		case Keys::Down: {
			control3->getJugador()->setDireccion(Abajo);
			break;

		}
		case Keys::Left: {
			control3->getJugador()->setDireccion(Izquierda);
			break;

		}
		case Keys::Right: {
			control3->getJugador()->setDireccion(Derecha);
			break;

		}
		case Keys::Q: {
			SonidoBala->Ctlcontrols->stop();
			SonidoBala->Ctlcontrols->play();
			control3->getJugador()->disparar();
			break;
		}
		case Keys::R: {
			//CREAMOS UN RAYO Y LO ASIGNAMOS AL JUGADOR 
			if (control3->getRayoDisparado() == false) { //Solo se dispara un rayo una sola vez
				rayo* r = new rayo(control3->getJugador()->getX(), control3->getJugador()->getY(), control3->getJugador()->getUltimaDireccion());
				control3->getJugador()->setRayo(r);
				control3->getJugador()->setDisparandoRayo(true);
				control3->setRayoDisparado(true);
			}
		}


		}



	}
	private: System::Void Mundo3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		control3->getJugador()->setDireccion(Ninguna);



	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		int alto = buffer->Graphics->VisibleClipBounds.Height;
		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		buffer->Graphics->DrawImage(fondo2, 0, 0, ancho, alto);
		//Estadisticas
		label2->Text = "NOMBRE: " + nom->getName();
		label3->Text = "VIDAS: " + control3->getJugador()->getVida();

		label6->Text = "VIDA DEL JEFE: \n" + control3->getJefe()->getVida();
		//SONIDOS X-X ------------------------------------------------------------------------

		//Soldados
		for (int i = 0; i < control3->getJefe()->getSoldados().size(); i++)
		{
			if (control3->getJefe()->getSoldados()[i]->getsonidosBalaEnemigo())
			{
				SonidoBalaE->Ctlcontrols->stop();
				SonidoBalaE->Ctlcontrols->play();

				control3->getJefe()->getSoldados()[i]->setsonidoBalaEnemigo(false);
			}
		}
		if (control3->getJefe()->getRafagaBalas1())
		{
			SonidoRafaga1->Ctlcontrols->stop();
			SonidoRafaga1->Ctlcontrols->play();

			control3->getJefe()->setRafagaBalas1(false);
		}
		if (control3->getJefe()->getRafagaBalas2())
		{
			SonidoRafaga2->Ctlcontrols->stop();
			SonidoRafaga2->Ctlcontrols->play();

			control3->getJefe()->setRafagaBalas2(false);
		}
		if (control3->getJefe()->getRafagaBalas3())
		{
			SonidoRafaga3->Ctlcontrols->stop();
			SonidoRafaga3->Ctlcontrols->play();

			control3->getJefe()->setRafagaBalas3(false);
		}
		if (control3->getJefe()->getNormal())
		{
			SonidoBalaE->Ctlcontrols->stop();
			SonidoBalaE->Ctlcontrols->play();

			control3->getJefe()->setNormal(false);
		}
		if (control3->getJefe()->getFuego())
		{
			SonidoFuego->Ctlcontrols->stop();
			SonidoFuego->Ctlcontrols->play();

			control3->getJefe()->setFuego(false);
		}
		if (control3->getJefe()->getHielo())
		{
			SonidoHielo->Ctlcontrols->stop();
			SonidoHielo->Ctlcontrols->play();

			control3->getJefe()->setHielo(false);
		}

		//Mover y dibujar
		if (control3->getRayoDisparado() == false)
			control3->ControlGeneral(buffer->Graphics, jugador, Jefe, JefeFuria, soldado, BalaPrincipal, Balaenemigo, balajefe, BolaFuego, BolaHielo, r_derecha, r_izquierda, r_abajo, r_arriba);
		if (control3->getRayoDisparado() == true)
			control3->ControlGeneral(buffer->Graphics, ultra, Jefe, JefeFuria, soldado, BalaPrincipal, Balaenemigo, balajefe, BolaFuego, BolaHielo, r_derecha, r_izquierda, r_abajo, r_arriba);
		control3->ControlRafagaBalasJefe();
		if (control3->getCongelado() == true) {
			contador2 += timer2->Interval;
			if (contador2 >= 1500) { //Congelado dura un segundo y medio
				contador2 = 0; //Reiniciamos
				control3->setCongelado(false);
			}
		}
		buffer->Render(g);
		if (control3->getJefe()->getVida() <= 0) {
			Grabar(toStdString(nom->getName()), control3->getJugador()->getVida());
			timer2->Enabled = false;
			Musica->Ctlcontrols->stop();
			Historia3_parte2^ c2 = gcnew Historia3_parte2();
			this->Hide();
			c2->ShowDialog();
			this->Close();
		}
		if (control3->getJugador()->getVida() <= 0) {
			timer2->Stop();
			Musica->Ctlcontrols->stop();
			Derrota3^ c2 = gcnew Derrota3();
			this->Hide();
			c2->ShowDialog();
			this->Close();
		}
		delete buffer;
		delete g;
		delete intervalo;
	
	}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	panel2->Visible = false;
}

};
}
