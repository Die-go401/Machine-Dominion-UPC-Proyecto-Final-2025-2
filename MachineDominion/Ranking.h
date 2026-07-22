#pragma once
#include <fstream>
#include "RANK.h"
#include <vector>


namespace MachineDominion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Ranking
	/// </summary>
	public ref class Ranking : public System::Windows::Forms::Form
	{
	public:
		Ranking(void)
		{
			InitializeComponent();
			//
			CargarRanking();  // AGREGAR ESTA LÍNEA
			//TODO: agregar código de constructor aquí
			//
		}
		
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Ranking()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ VIDAS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PUNTAJE;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	protected:



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		//void CargarRanking()
		//{
		//	std::ifstream archivo("RANKING.dat", std::ios::binary);

		//	if (!archivo.is_open()) {
		//		MessageBox::Show("No se pudo abrir RANKING.dat");
		//		return;
		//	}

		//	Datos jugador;

		//	// Limpiar el datagrid por si ya tiene datos
		//	dataGridView1->Rows->Clear();

		//	// Leer cada registro del archivo
		//	while (archivo.read((char*)&jugador, sizeof(Datos)))
		//	{
		//		// Convertir char[] a System::String^
		//		System::String^ nombre = gcnew System::String(jugador.NOMBRE);

		//		// Agregar fila al DataGridView
		//		dataGridView1->Rows->Add(nombre, jugador.VIDAS,jugador.PUNTAJE);
		//	}

		//	archivo.close();
		//}
		void CargarRanking()
		{
			std::ifstream archivo("RANKING.dat", std::ios::binary);
			if (!archivo.is_open()) {
				MessageBox::Show("No se pudo abrir RANKING.dat");
				return;
			}

			// Leer todos los registros al vector
			std::vector<Datos> lista;
			Datos d;

			while (archivo.read((char*)&d, sizeof(Datos))) {
				lista.push_back(d);
			}

			archivo.close();

			// ---------------------------------------------------------
			// ORDENAMIENTO BURBUJA (de mayor a menor por PUNTAJE)
			// ---------------------------------------------------------
			for (int i = 0; i < lista.size() - 1; i++)
			{
				for (int j = 0; j < lista.size() - i - 1; j++)
				{
					if (lista[j].PUNTAJE < lista[j + 1].PUNTAJE)
					{
						Datos aux = lista[j];
						lista[j] = lista[j + 1];
						lista[j + 1] = aux;
					}
				}
			}

			// Limpiar el DataGridView
			dataGridView1->Rows->Clear();

			// Rellenar cada registro ya ordenado
			for (int i = 0; i < lista.size(); i++)
			{
				// Convertimos char[ ] a System::String^
				lista[i].NOMBRE[29] = '\0';  // aseguramos fin de cadena
				System::String^ nombre = gcnew System::String(lista[i].NOMBRE);

				dataGridView1->Rows->Add(nombre, lista[i].VIDAS, lista[i].PUNTAJE);
			}
		}
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Ranking::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->VIDAS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PUNTAJE = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Nombre,
					this->VIDAS, this->PUNTAJE
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 123);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(598, 150);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Ranking::dataGridView1_CellContentClick);
			// 
			// Nombre
			// 
			this->Nombre->HeaderText = L"NOMBRE";
			this->Nombre->MinimumWidth = 6;
			this->Nombre->Name = L"Nombre";
			this->Nombre->Width = 125;
			// 
			// VIDAS
			// 
			this->VIDAS->HeaderText = L"VIDAS";
			this->VIDAS->MinimumWidth = 6;
			this->VIDAS->Name = L"VIDAS";
			this->VIDAS->Width = 125;
			// 
			// PUNTAJE
			// 
			this->PUNTAJE->HeaderText = L"PUNTAJE";
			this->PUNTAJE->MinimumWidth = 6;
			this->PUNTAJE->Name = L"PUNTAJE";
			this->PUNTAJE->Width = 125;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(410, 91);
			this->label1->TabIndex = 1;
			this->label1->Text = L"RANKING";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(626, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(394, 286);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// Ranking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 310);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Ranking";
			this->Text = L"Ranking";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	};
}
