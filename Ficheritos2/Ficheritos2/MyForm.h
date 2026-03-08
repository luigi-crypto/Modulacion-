#pragma once
using namespace System::IO;
using namespace System::Collections;
namespace Ficheritos2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvEstudiantes;
	private: System::Windows::Forms::Button^ Cargar;

	private: System::Windows::Forms::Button^ Ordenar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ApellidoPaterno;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ApellidoMaterno;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Matricula;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CURP;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgvEstudiantes = (gcnew System::Windows::Forms::DataGridView());
			this->Cargar = (gcnew System::Windows::Forms::Button());
			this->Ordenar = (gcnew System::Windows::Forms::Button());
			this->Nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ApellidoPaterno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ApellidoMaterno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Matricula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CURP = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEstudiantes))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvEstudiantes
			// 
			this->dgvEstudiantes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEstudiantes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Nombre,
					this->ApellidoPaterno, this->ApellidoMaterno, this->Matricula, this->CURP
			});
			this->dgvEstudiantes->Location = System::Drawing::Point(-1, -5);
			this->dgvEstudiantes->Name = L"dgvEstudiantes";
			this->dgvEstudiantes->RowHeadersWidth = 51;
			this->dgvEstudiantes->RowTemplate->Height = 24;
			this->dgvEstudiantes->Size = System::Drawing::Size(1607, 827);
			this->dgvEstudiantes->TabIndex = 0;
			// 
			// Cargar
			// 
			this->Cargar->Location = System::Drawing::Point(746, 12);
			this->Cargar->Name = L"Cargar";
			this->Cargar->Size = System::Drawing::Size(75, 23);
			this->Cargar->TabIndex = 1;
			this->Cargar->Text = L"Cargar Datos";
			this->Cargar->UseVisualStyleBackColor = true;
			this->Cargar->Click += gcnew System::EventHandler(this, &MyForm::Cargar_Click);
			// 
			// Ordenar
			// 
			this->Ordenar->Location = System::Drawing::Point(1507, 12);
			this->Ordenar->Name = L"Ordenar";
			this->Ordenar->Size = System::Drawing::Size(75, 23);
			this->Ordenar->TabIndex = 2;
			this->Ordenar->Text = L"Ordenar";
			this->Ordenar->UseVisualStyleBackColor = true;
			this->Ordenar->Click += gcnew System::EventHandler(this, &MyForm::Ordenar_Click);
			// 
			// Nombre
			// 
			this->Nombre->HeaderText = L"Nombre";
			this->Nombre->MinimumWidth = 6;
			this->Nombre->Name = L"Nombre";
			this->Nombre->Width = 125;
			// 
			// ApellidoPaterno
			// 
			this->ApellidoPaterno->HeaderText = L"Apellido Paterno";
			this->ApellidoPaterno->MinimumWidth = 6;
			this->ApellidoPaterno->Name = L"ApellidoPaterno";
			this->ApellidoPaterno->Width = 125;
			// 
			// ApellidoMaterno
			// 
			this->ApellidoMaterno->HeaderText = L"Apellido Materno";
			this->ApellidoMaterno->MinimumWidth = 6;
			this->ApellidoMaterno->Name = L"ApellidoMaterno";
			this->ApellidoMaterno->Width = 125;
			// 
			// Matricula
			// 
			this->Matricula->HeaderText = L"Matricula";
			this->Matricula->MinimumWidth = 6;
			this->Matricula->Name = L"Matricula";
			this->Matricula->Width = 125;
			// 
			// CURP
			// 
			this->CURP->HeaderText = L"CURP";
			this->CURP->MinimumWidth = 6;
			this->CURP->Name = L"CURP";
			this->CURP->Width = 125;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1608, 817);
			this->Controls->Add(this->Ordenar);
			this->Controls->Add(this->Cargar);
			this->Controls->Add(this->dgvEstudiantes);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEstudiantes))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Cargar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ archivo = "estudiantes.csv";

		if (File::Exists(archivo)) {
			// 2. Leer todas las líneas del archivo
			array<String^>^ lineas = File::ReadAllLines(archivo);

			// 3. Limpiar la tabla por si ya tenía algo
			dgvEstudiantes->Rows->Clear();

			// 4. Recorrer las líneas (empezamos en 1 para saltar el encabezado)
			for (int i = 1; i < lineas->Length; i++) {
				// Separar cada línea por las comas
				array<String^>^ datos = lineas[i]->Split(',');

				// Agregar la fila a la tabla
				dgvEstudiantes->Rows->Add(datos);
			}
		}
		else {
			MessageBox::Show("No encontré el archivo estudiantes.csv en la carpeta Debug");
		}
	}
	private: System::Void Ordenar_Click(System::Object^ sender, System::EventArgs^ e) {
		dgvEstudiantes->Sort(dgvEstudiantes->Columns[0], System::ComponentModel::ListSortDirection::Ascending);
	}
};
}
