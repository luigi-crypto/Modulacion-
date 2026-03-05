#pragma once

namespace RegistroUsuarios {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO; // Libreria necesaria para manejar archivos de texto

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

        // Declaración de los controles de la interfaz
    private: System::Windows::Forms::Label^ lblNombre;
    private: System::Windows::Forms::TextBox^ txtNombre;
    private: System::Windows::Forms::Label^ lblPaterno;
    private: System::Windows::Forms::TextBox^ txtPaterno;
    private: System::Windows::Forms::Label^ lblMaterno;
    private: System::Windows::Forms::TextBox^ txtMaterno;
    private: System::Windows::Forms::Label^ lblFechaNacimiento;
    private: System::Windows::Forms::TextBox^ txtFechaNacimiento;
    private: System::Windows::Forms::Label^ lblCURP;
    private: System::Windows::Forms::TextBox^ txtCURP;
    private: System::Windows::Forms::Label^ lblDomicilio;
    private: System::Windows::Forms::TextBox^ txtDomicilio;
    private: System::Windows::Forms::Button^ btnGuardar;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            // Inicialización de los controles
            this->lblNombre = (gcnew System::Windows::Forms::Label());
            this->txtNombre = (gcnew System::Windows::Forms::TextBox());
            this->lblPaterno = (gcnew System::Windows::Forms::Label());
            this->txtPaterno = (gcnew System::Windows::Forms::TextBox());
            this->lblMaterno = (gcnew System::Windows::Forms::Label());
            this->txtMaterno = (gcnew System::Windows::Forms::TextBox());
            this->lblFechaNacimiento = (gcnew System::Windows::Forms::Label());
            this->txtFechaNacimiento = (gcnew System::Windows::Forms::TextBox());
            this->lblCURP = (gcnew System::Windows::Forms::Label());
            this->txtCURP = (gcnew System::Windows::Forms::TextBox());
            this->lblDomicilio = (gcnew System::Windows::Forms::Label());
            this->txtDomicilio = (gcnew System::Windows::Forms::TextBox());
            this->btnGuardar = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // Configuración visual de cada control (Posición y Tamaño)
            // Nombre
            this->lblNombre->Location = System::Drawing::Point(30, 30);
            this->lblNombre->Text = L"Nombre(s):";
            this->txtNombre->Location = System::Drawing::Point(180, 27);
            this->txtNombre->Size = System::Drawing::Size(200, 20);

            // Apellido Paterno
            this->lblPaterno->Location = System::Drawing::Point(30, 70);
            this->lblPaterno->Text = L"Apellido Paterno:";
            this->txtPaterno->Location = System::Drawing::Point(180, 67);
            this->txtPaterno->Size = System::Drawing::Size(200, 20);

            // Apellido Materno
            this->lblMaterno->Location = System::Drawing::Point(30, 110);
            this->lblMaterno->Text = L"Apellido Materno:";
            this->txtMaterno->Location = System::Drawing::Point(180, 107);
            this->txtMaterno->Size = System::Drawing::Size(200, 20);

            // Fecha de Nacimiento
            this->lblFechaNacimiento->Location = System::Drawing::Point(30, 150);
            this->lblFechaNacimiento->Text = L"Fecha de nacimiento:";
            this->txtFechaNacimiento->Location = System::Drawing::Point(180, 147);
            this->txtFechaNacimiento->Size = System::Drawing::Size(200, 20);

            // CURP
            this->lblCURP->Location = System::Drawing::Point(30, 190);
            this->lblCURP->Text = L"CURP:";
            this->txtCURP->Location = System::Drawing::Point(180, 187);
            this->txtCURP->Size = System::Drawing::Size(200, 20);

            // Domicilio
            this->lblDomicilio->Location = System::Drawing::Point(30, 230);
            this->lblDomicilio->Text = L"Domicilio:";
            this->txtDomicilio->Location = System::Drawing::Point(180, 227);
            this->txtDomicilio->Size = System::Drawing::Size(200, 20);

            // Botón Guardar
            this->btnGuardar->Location = System::Drawing::Point(180, 280);
            this->btnGuardar->Size = System::Drawing::Size(120, 40);
            this->btnGuardar->Text = L"Guardar Datos";
            this->btnGuardar->Click += gcnew System::EventHandler(this, &Form1::btnGuardar_Click); // Enlaza el botón al evento

            // Configuración del Formulario Principal
            this->ClientSize = System::Drawing::Size(450, 360);
            this->Controls->Add(this->btnGuardar);
            this->Controls->Add(this->txtDomicilio);
            this->Controls->Add(this->lblDomicilio);
            this->Controls->Add(this->txtCURP);
            this->Controls->Add(this->lblCURP);
            this->Controls->Add(this->txtFechaNacimiento);
            this->Controls->Add(this->lblFechaNacimiento);
            this->Controls->Add(this->txtMaterno);
            this->Controls->Add(this->lblMaterno);
            this->Controls->Add(this->txtPaterno);
            this->Controls->Add(this->lblPaterno);
            this->Controls->Add(this->txtNombre);
            this->Controls->Add(this->lblNombre);
            this->Text = L"Registro de Usuarios";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // Evento que se ejecuta al presionar el botón
    private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
        // 1. Recolectar datos
        String^ nombre = txtNombre->Text;
        String^ paterno = txtPaterno->Text;
        String^ materno = txtMaterno->Text;
        String^ fechaNac = txtFechaNacimiento->Text;
        String^ curp = txtCURP->Text;
        String^ domicilio = txtDomicilio->Text;

        // 2. Validar que no falten datos clave
        if (nombre == "" || curp == "") {
            MessageBox::Show("Por favor ingresa al menos el Nombre y la CURP.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        try {
            // 3. Crear el flujo para escribir el archivo. 'true' permite agregar sin borrar lo anterior.
            StreamWriter^ archivo = gcnew StreamWriter("datos_registrados.txt", true);

            // 4. Escribir en el archivo
            archivo->WriteLine("=== REGISTRO ===");
            archivo->WriteLine("Nombre(s): " + nombre);
            archivo->WriteLine("Apellido Paterno: " + paterno);
            archivo->WriteLine("Apellido Materno: " + materno);
            archivo->WriteLine("Fecha de Nacimiento: " + fechaNac);
            archivo->WriteLine("CURP: " + curp);
            archivo->WriteLine("Domicilio: " + domicilio);
            archivo->WriteLine("================\n");

            // 5. Cerrar el archivo
            archivo->Close();

            MessageBox::Show("Registro guardado con éxito en datos_registrados.txt", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // 6. Limpiar campos
            txtNombre->Clear();
            txtPaterno->Clear();
            txtMaterno->Clear();
            txtFechaNacimiento->Clear();
            txtCURP->Clear();
            txtDomicilio->Clear();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error del sistema", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    };
}