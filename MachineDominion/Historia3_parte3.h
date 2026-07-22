#pragma once
#include "ControladorHistoria3_parte3.h"
#include "Victoria.h"
namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Historia3_parte3
	/// </summary>
	public ref class Historia3_parte3 : public System::Windows::Forms::Form
	{
	private:
		bool a;
		bool b;
		bool c;
		// --PARA EL TEXTO--
		AxWMPLib::AxWindowsMediaPlayer^ Click;
		AxWMPLib::AxWindowsMediaPlayer^ Pascua;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador2;
		AxWMPLib::AxWindowsMediaPlayer^ Narrador3;
		String^ textoCompleto;
		int indice;

		Bitmap^ jugador;

		Rectangle hospital;
		Rectangle noticias;
		Rectangle huevodepascua;
		Rectangle robot;
		Rectangle noticias1;
		Rectangle huevodepascua1;
		Rectangle Puerta;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Timer^ timerTexto;
	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;


		ControladorHistoria3_parte3* control;
	public:
		Historia3_parte3(void)
		{
			InitializeComponent();
			//
			a = false;
			b = false;
			c = false;

			Click = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Click->CreateControl();
			Click->URL = "audio/CLICK.wav";
			Click->Ctlcontrols->stop();

			Pascua = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Pascua->CreateControl();
			Pascua->URL = "audio/SONIDOPascua.mp3";
			Pascua->Ctlcontrols->stop();

			Narrador = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador->CreateControl();
			Narrador->URL = "audio/Chatgpt64.mp3";
			Narrador->Ctlcontrols->stop();

			Narrador2 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador2->CreateControl();
			Narrador2->URL = "audio/Otrasnoticias.mp3";
			Narrador2->Ctlcontrols->stop();

			Narrador3 = gcnew AxWMPLib::AxWindowsMediaPlayer();
			Narrador3->CreateControl();
			Narrador3->URL = "audio/Noticiasfinal.mp3";
			Narrador3->Ctlcontrols->stop();

			this->KeyPreview = true;

			jugador = gcnew Bitmap("Imagenes/Principal.png");
			control = new ControladorHistoria3_parte3();

			hospital= Rectangle(pictureBox1->Location, pictureBox1->Size);
			noticias = Rectangle(pictureBox2->Location, pictureBox2->Size);
			huevodepascua = Rectangle(pictureBox3->Location, pictureBox3->Size);

			robot = Rectangle(pictureBox4->Location, pictureBox4->Size);
			noticias1 = Rectangle(pictureBox6->Location, pictureBox6->Size);
			huevodepascua1 = Rectangle(pictureBox5->Location, pictureBox5->Size);

			Puerta = Rectangle(pictureBox9->Location, pictureBox9->Size);
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historia3_parte3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		void imprimir_lento(String^ texto)
		{
			textoCompleto = texto;
			indice = 0;
			label1->Text = "";   // limpiar el texto
			timerTexto->Start();     // usar el timer del diseñador
		}
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Historia3_parte3::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTexto = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->pictureBox9);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->pictureBox6);
			this->panel1->Controls->Add(this->pictureBox5);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1248, 864);
			this->panel1->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::Control;
			this->panel4->Controls->Add(this->button6);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Location = System::Drawing::Point(405, 274);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(498, 317);
			this->panel4->TabIndex = 24;
			this->panel4->Visible = false;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(192, 271);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(98, 39);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Cerrar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Historia3_parte3::button6_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Yellow;
			this->label4->Location = System::Drawing::Point(43, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(411, 160);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Interactua con el robot IA y mira\r\nlas noticias para poder abrir la \r\npuerta y ga"
				L"nar :D\r\n\r\n-Para interactuar presiona R\r\n";
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
			this->label3->Location = System::Drawing::Point(120, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 51);
			this->label3->TabIndex = 19;
			this->label3->Text = L"OBJETIVO";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox9->Location = System::Drawing::Point(1153, 508);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(95, 146);
			this->pictureBox9->TabIndex = 23;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Visible = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->pictureBox8);
			this->panel3->Location = System::Drawing::Point(228, 135);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(782, 505);
			this->panel3->TabIndex = 22;
			this->panel3->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(675, 464);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(84, 33);
			this->button4->TabIndex = 25;
			this->button4->Text = L"siguiente";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Historia3_parte3::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(675, 464);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 33);
			this->button3->TabIndex = 24;
			this->button3->Text = L"siguiente";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Historia3_parte3::button3_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 464);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 33);
			this->button2->TabIndex = 23;
			this->button2->Text = L"cerrar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Historia3_parte3::button2_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox8->Location = System::Drawing::Point(22, 21);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(737, 428);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 0;
			this->pictureBox8->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->pictureBox7);
			this->panel2->Location = System::Drawing::Point(11, 11);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(899, 205);
			this->panel2->TabIndex = 21;
			this->panel2->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(812, 167);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"cerrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Historia3_parte3::button1_Click);
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
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(16, 20);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(206, 170);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 0;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Location = System::Drawing::Point(644, 590);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(330, 64);
			this->pictureBox6->TabIndex = 5;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Visible = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Location = System::Drawing::Point(1150, 203);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(95, 64);
			this->pictureBox5->TabIndex = 4;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Location = System::Drawing::Point(428, 135);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(95, 64);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Location = System::Drawing::Point(1173, 220);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(62, 47);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Location = System::Drawing::Point(495, 297);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(753, 335);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(312, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(936, 180);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Historia3_parte3::timer1_Tick);
			// 
			// timerTexto
			// 
			this->timerTexto->Interval = 20;
			this->timerTexto->Tick += gcnew System::EventHandler(this, &Historia3_parte3::timerTexto_Tick);
			// 
			// Historia3_parte3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1248, 867);
			this->Controls->Add(this->panel1);
			this->Name = L"Historia3_parte3";
			this->Text = L"Historia3_parte3";
			this->Load += gcnew System::EventHandler(this, &Historia3_parte3::Historia3_parte3_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Historia3_parte3::Historia3_parte3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Historia3_parte3::Historia3_parte3_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Graphics^ g = panel1->CreateGraphics();
		BufferedGraphicsContext^ intervalo = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = intervalo->Allocate(g, panel1->ClientRectangle);
		//Borrar
		buffer->Graphics->DrawImage(panel1->BackgroundImage, panel1->ClientRectangle);

		control->controlador(buffer->Graphics,jugador,hospital,noticias,huevodepascua);



		buffer->Render(g);
		delete buffer;
		delete intervalo;
		delete g;
	}
	private: System::Void Historia3_parte3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {

		case Keys::Up:
			control->getJugador()->setDireccion(Arriba);
			break;

		case Keys::Down:
			control->getJugador()->setDireccion(Abajo);
			break;

		case Keys::Left:
			control->getJugador()->setDireccion(Izquierda);
			break;

		case Keys::Right:
			control->getJugador()->setDireccion(Derecha);
			break;

		case Keys::R: {
			if (control->getJugador()->getRectanglePrincipal().IntersectsWith(robot))
			{
				a = true;
				panel2->Visible = true;
				label2->Text = "KAREN";
				imprimir_lento("Paciente detectado, iniciando escaneo; vitales\n estables, leve fatiga muscular, recomendación:\n hidratarse y continuar con precaución.");
				pictureBox7->Image = Image::FromFile("Imagenes/Doctora.png");
			}
			else if(control->getJugador()->getRectanglePrincipal().IntersectsWith(noticias1))
			{
				b = true;
				button3->Visible = true;
				button4->Visible = false;

				panel3->Visible = true;

				Narrador->Ctlcontrols->play();
				pictureBox8->Image = Image::FromFile("Imagenes/Gif26.gif");
			}
			else if (control->getJugador()->getRectanglePrincipal().IntersectsWith(huevodepascua1))
			{
				button3->Visible = false;
				button4->Visible = false;
				panel3->Visible = true;
				Pascua->Ctlcontrols->play();
				pictureBox8->Image = Image::FromFile("Imagenes/Huevodepascua.gif");
			}
			else if (control->getJugador()->getRectanglePrincipal().IntersectsWith(Puerta) && a && b)
			{
				Victoria^ c2 = gcnew Victoria();
				this->Hide();
				c2->ShowDialog();
				this->Close();
			}
			break;
		}
		}
	}
private: System::Void Historia3_parte3_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	control->getJugador()->setDireccion(Ninguna);
}
private: System::Void timerTexto_Tick(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	panel2->Visible = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Click->Ctlcontrols->stop();
	Click->Ctlcontrols->play();
	Pascua->Ctlcontrols->stop();
	Narrador->Ctlcontrols->stop();
	Narrador2->Ctlcontrols->stop();
	Narrador3->Ctlcontrols->stop();
	panel3->Visible = false;
}
private: System::Void Historia3_parte3_Load(System::Object^ sender, System::EventArgs^ e) 
{
	panel4->BackColor = Color::FromArgb(160, 0, 0, 0);
	panel4->Visible = true;
	panel3->BackColor= Color::FromArgb(160, 0, 0, 0);
	panel2->BackColor = Color::FromArgb(160, 0, 0, 0);
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
	// Cambia a la siguiente parte de la narración
	Narrador->Ctlcontrols->stop();
	Narrador2->Ctlcontrols->play();
	pictureBox8->Image = Image::FromFile("Imagenes/Gif27.gif");

	// Cambiar botones
	button3->Visible = false;
	button4->Visible = true;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Narrador2->Ctlcontrols->stop();
	Narrador3->Ctlcontrols->play();
	pictureBox8->Image = Image::FromFile("Imagenes/Gif28.gif");

	button4->Visible = false;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	panel4->Visible = false;
}
};
}
