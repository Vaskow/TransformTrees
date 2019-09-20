#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;
 
[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
 
    TreesBC::Form1 form; 
    Application::Run(%form);
}