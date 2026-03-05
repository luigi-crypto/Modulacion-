#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Si tu namespace en el .h arriba es diferente, cámbialo aquí
    RegistroUsuarios::Form1 form;
    Application::Run(% form);

    return 0;
}