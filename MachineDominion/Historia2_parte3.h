#pragma once
#include "ControladorHistoria2_parte3.h"
#include "Mundo2_2.h"
#include "Nombre.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Historia2_parte3
	/// </summary>
	public ref class Historia2_parte3 : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ reproductor;
		Nombre^ nom;
	public:
		Historia2_parte3(Nombre^h)
		{
			InitializeComponent();
			//
			nom = h;
			Click = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Click->CreateControl();
			Click->URL = "audio/CLICK.wav";
			Click->Ctlcontrols->stop();

			this->KeyPreview = true;

			controladorhistoria2 = new ControladorHistoria2_parte3();
			jugador = gcnew Bitmap("Imagenes/Principal.png");
			leonardo = Rectangle(pictureBox1->Location, pictureBox1->Size);
			leonardo1 = Rectangle(pictureBox11->Location, pictureBox11->Size);

			Mesa = Rectangle(pictureBox3->Location, pictureBox3->Size);
			Mesa1 = Rectangle(pictureBox12->Location, pictureBox12->Size);

			Cuadro = Rectangle(pictureBox4->Location, pictureBox4->Size);
			Cuadro1 = Rectangle(pictureBox17->Location, pictureBox17->Size);

			Alquimia = Rectangle(pictureBox5->Location, pictureBox5->Size);
			Alquimia1 = Rectangle(pictureBox18->Location, pictureBox18->Size);

			Libros1=Rectangle(pictureBox6->Location, pictureBox6->Size);
			Libros1_1 = Rectangle(pictureBox13->Location, pictureBox13->Size);

			Libros2 = Rectangle(pictureBox7->Location, pictureBox7->Size);
			Libros2_1 = Rectangle(pictureBox14->Location, pictureBox14->Size);

			Libros3 = Rectangle(pictureBox8->Location, pictureBox8->Size);
			Libros3_1 = Rectangle(pictureBox15->Location, pictureBox15->Size);

			GloboTerraqueo = Rectangle(pictureBox9->Location, pictureBox9->Size);
			GloboTerraqueo1 = Rectangle(pictureBox16->Location, pictureBox16->Size);

			Ventana = Rectangle(pictureBox10->Location, pictureBox10->Size);
			String^ ruta = System::IO::Path::Combine(Application::StartupPath, "AUDIOS", "historia2.wav");
			reproductor = gcnew SoundPlayer(ruta);
			reproductor->PlayLooping(); // o Play()

			obj1 = false;
			obj2 = false;
			obj3 = false;
			obj4 = false;
			obj5 = false;
			obj6 = false;
			obj7 = false;
			
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia2_parte3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timerTexto;




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		bool obj1;
		bool obj2;
		bool obj3;
		bool obj4;
		bool obj5;
		bool obj6;
		bool obj7;

		ControladorHistoria2_parte3* controladorhistoria2;
		Bitmap^ jugador;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

		Rectangle leonardo;
		Rectangle leonardo1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
		   Rectangle Mesa;
		   Rectangle Mesa1;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
		   Rectangle Cuadro;
		   Rectangle Cuadro1;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
		   Rectangle Alquimia;
		   Rectangle Alquimia1;

		   Rectangle Libros1;
		   Rectangle Libros1_1;

		   Rectangle Libros2;
		   Rectangle Libros2_1;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
		   Rectangle Libros3;
		   Rectangle Libros3_1;




	private: System::Windows::Forms::PictureBox^ pictureBox10;
		   Rectangle GloboTerraqueo;
		   Rectangle GloboTerraqueo1;
		   Rectangle Ventana;

		   // --PARA EL TEXTO--
		   String^ textoCompleto;

	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::PictureBox^ pictureBox14;
	private: System::Windows::Forms::PictureBox^ pictureBox15;
	private: System::Windows::Forms::PictureBox^ pictureBox16;
private: System::Windows::Forms::PictureBox^ pictureBox17;
private: System::Windows::Forms::PictureBox^ pictureBox18;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::Button^ button2;


	   AxWMPLib::AxWindowsMediaPlayer^ Click;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label3;
	   int indice;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia2_parte3::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTexto = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->pictureBox18);
			this->panel1->Controls->Add(this->pictureBox17);
			this->panel1->Controls->Add(this->pictureBox16);
			this->panel1->Controls->Add(this->pictureBox15);
			this->panel1->Controls->Add(this->pictureBox14);
			this->panel1->Controls->Add(this->pictureBox13);
			this->panel1->Controls->Add(this->pictureBox12);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->pictureBox11);
			this->panel1->Controls->Add(this->pictureBox10);
			this->panel1->Controls->Add(this->pictureBox9);
			this->panel1->Controls->Add(this->pictureBox8);
			this->panel1->Controls->Add(this->pictureBox7);
			this->panel1->Controls->Add(this->pictureBox6);
			this->panel1->Controls->Add(this->pictureBox5);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1247, 847);
			this->panel1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(354, 321);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(557, 317);
			this->panel3->TabIndex = 21;
			this->panel3->Visible = false;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Historia2_parte3::panel3_Paint);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(239, 266);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(98, 39);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Cerrar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Historia2_parte3::button6_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Yellow;
			this->label4->Location = System::Drawing::Point(52, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(473, 160);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Interactua con todos los objetos que\r\nhay en la sala para poder hablar con\r\nLeona"
				L"rdo Da Vinci.\r\n\r\n-Para interactuar presiona R\r\n";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Yellow;
			this->label3->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Location = System::Drawing::Point(161, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 51);
			this->label3->TabIndex = 19;
			this->label3->Text = L"OBJETIVO";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Location = System::Drawing::Point(12, 11);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(899, 205);
			this->panel2->TabIndex = 20;
			this->panel2->Visible = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(803, 163);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 31);
			this->button3->TabIndex = 22;
			this->button3->Text = L"siguiente";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Historia2_parte3::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(812, 167);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"aceptar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Historia2_parte3::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(812, 167);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"cerrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia2_parte3::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Yellow;
			this->label2->Location = System::Drawing::Point(228, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 29);
			this->label2->TabIndex = 19;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Yellow;
			this->label1->Location = System::Drawing::Point(227, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 32);
			this->label1->TabIndex = 18;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(16, 20);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(206, 170);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox18->Location = System::Drawing::Point(442, 249);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(319, 188);
			this->pictureBox18->TabIndex = 19;
			this->pictureBox18->TabStop = false;
			this->pictureBox18->Visible = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox17->Location = System::Drawing::Point(28, 607);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(206, 171);
			this->pictureBox17->TabIndex = 18;
			this->pictureBox17->TabStop = false;
			this->pictureBox17->Visible = false;
			// 
			// pictureBox16
			// 
			this->pictureBox16->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox16->Location = System::Drawing::Point(28, 343);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(134, 122);
			this->pictureBox16->TabIndex = 17;
			this->pictureBox16->TabStop = false;
			this->pictureBox16->Visible = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox15->Location = System::Drawing::Point(168, 222);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(268, 193);
			this->pictureBox15->TabIndex = 16;
			this->pictureBox15->TabStop = false;
			this->pictureBox15->Visible = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox14->Location = System::Drawing::Point(780, 207);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(255, 208);
			this->pictureBox14->TabIndex = 15;
			this->pictureBox14->TabStop = false;
			this->pictureBox14->Visible = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox13->Location = System::Drawing::Point(1102, 240);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(122, 208);
			this->pictureBox13->TabIndex = 14;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Visible = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox12->Location = System::Drawing::Point(425, 505);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(385, 175);
			this->pictureBox12->TabIndex = 13;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(872, 505);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(68, 78);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox11->Location = System::Drawing::Point(870, 500);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(75, 85);
			this->pictureBox11->TabIndex = 11;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Visible = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox10->Location = System::Drawing::Point(1026, 0);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(218, 169);
			this->pictureBox10->TabIndex = 9;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox9->Location = System::Drawing::Point(28, 343);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(115, 105);
			this->pictureBox9->TabIndex = 8;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox8->Location = System::Drawing::Point(1118, 249);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(97, 187);
			this->pictureBox8->TabIndex = 7;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->Location = System::Drawing::Point(780, 156);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(240, 237);
			this->pictureBox7->TabIndex = 6;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Location = System::Drawing::Point(168, 265);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(268, 128);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &Historia2_parte3::pictureBox6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Location = System::Drawing::Point(442, 308);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(319, 128);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Location = System::Drawing::Point(39, 623);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(179, 141);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Location = System::Drawing::Point(437, 518);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(360, 149);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Historia2_parte3::pictureBox3_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Historia2_parte3::timer1_Tick);
			// 
			// timerTexto
			// 
			this->timerTexto->Interval = 20;
			this->timerTexto->Tick += gcnew System::EventHandler(this, &Historia2_parte3::timerTexto_Tick);
			// 
			// Historia2_parte3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1248, 867);
			this->Controls->Add(this->panel1);
			this->Name = L"Historia2_parte3";
			this->Text = L"Historia2_parte3";
			this->Load += gcnew System::EventHandler(this, &Historia2_parte3::Historia2_parte3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Historia2_parte3::Historia2_parte3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Historia2_parte3::Historia2_parte3_KeyUp);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Historia2_parte3::Historia2_parte3_MouseDown);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Historia2_parte3_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		panel3->BackColor = Color::FromArgb(160, 0, 0, 0);
		panel3->Visible = true;
		
		
		panel2->BackColor= Color::FromArgb(160, 0, 0, 0);
		pictureBox1->Parent = panel1;
		pictureBox1->BackColor = Color::Transparent;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		//Borrar
		buffer->Graphics->DrawImage(panel1->BackgroundImage, panel1->ClientRectangle);
		
		controladorhistoria2->controlador(buffer->Graphics, jugador,leonardo,Mesa,Cuadro,Alquimia,Libros1,Libros2,Libros3,GloboTerraqueo,Ventana);
		


		buffer->Render(g);
		delete buffer;
		delete intervalo;
		delete g;
	}
private: System::Void Historia2_parte3_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
{
}
private: System::Void Historia2_parte3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode) {

	case Keys::Up:
		controladorhistoria2->getJugador()->setDireccion(Arriba);
		break;

	case Keys::Down:
		controladorhistoria2->getJugador()->setDireccion(Abajo);
		break;

	case Keys::Left:
		controladorhistoria2->getJugador()->setDireccion(Izquierda);
		break;

	case Keys::Right:
		controladorhistoria2->getJugador()->setDireccion(Derecha);
		break;

	case Keys::R: {
		if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(leonardo1) && obj1 && obj2 && obj3 && obj4 && obj5 && obj6 && obj7)
		{
			button1->Visible = false;
			button2->Visible = false;
			button3->Visible = true;
			panel2->Visible = true;
			label2->Text = "Leonardo Da Vinci";
			pictureBox2->Image = Image::FromFile("Imagenes/LeonardoDaVinci.png");
			imprimir_lento("Has llegado justo a tiempo. Un grupo de arañas\n está invadiendo mi hogar. ¿Puedes ayudarme\n a ahuyentarlas?");
		
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(Mesa1))
		{
			obj1 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("Si Leonardo pudo crear tanto desde esta mesa…\n ¿qué puedo lograr yo?");
			pictureBox2->Image= Image::FromFile("Imagenes/Fotocara.png");
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(Libros1_1))
		{
			obj2 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("Cuántos pensamientos, dudas y sueños habrán\n sido escritos en estas páginas… ojalá pudiera\n escucharlos.");
			pictureBox2->Image = Image::FromFile("Imagenes/Fotocara.png");
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(Libros2_1))
		{
			obj3 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("A veces basta abrir un libro para sentirse\n acompañado, aunque no haya nadie cerca.");
			pictureBox2->Image = Image::FromFile("Imagenes/Fotocara.png");
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(Libros3_1))
		{
			obj4 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("Siempre pensé que los libros eran puertas…\n y cada estantería es como un pasillo lleno de\n mundos posibles.");
			pictureBox2->Image = Image::FromFile("Imagenes/Fotocara.png");
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(GloboTerraqueo1))
		{
			obj5 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("Qué irónico… cuanto más observo el mundo,\n más pequeño me siento.Pero también más curioso.");
			pictureBox2->Image = Image::FromFile("Imagenes/Fotocara.png");
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(Cuadro1))
		{
			obj6 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("Es increíble cómo una simple pincelada\n puede decir más que mil palabras… Leonardo\n entendía algo que yo todavía no.");
			pictureBox2->Image = Image::FromFile("Imagenes/Fotocara.png");
		}
		else if (controladorhistoria2->getJugador()->getRectanglePrincipal().IntersectsWith(Alquimia1))
		{
			obj7 = true;
			panel2->Visible = true;
			label2->Text = nom->getName();
			imprimir_lento("Da miedo lo que esta mesa esconde…\n intentos, errores, descubrimientos.Todo\n mezclado como en la vida misma.");
			pictureBox2->Image = Image::FromFile("Imagenes/Fotocara.png");
		}
		break;
	}
	}
}
private: System::Void Historia2_parte3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
{
	controladorhistoria2->getJugador()->setDireccion(Ninguna);

}
private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void pictureBox12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	panel2->Visible = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	reproductor->Stop();
	timer1->Stop();
	Mundo2_2^ c2 = gcnew Mundo2_2(nom);
	this->Hide();
	c2->ShowDialog();
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	button1->Visible = false;
	button2->Visible = true;
	button3->Visible = false;
	panel2->Visible = true;
	label2->Text = "Leonardo Da Vinci";
	pictureBox2->Image = Image::FromFile("Imagenes/LeonardoDaVinci.png");
	imprimir_lento("Si me ofreces tu ayuda, puedo otorgar a tu arma\n una mejora especial.Pero recuerda : solo podrás\n usarla una vez. ¿Aceptas ? ");
}
private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	panel3->Visible = false;
}
};
}
