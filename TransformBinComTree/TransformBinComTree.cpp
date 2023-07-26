// TransformBinComTree.cpp : Определяет точку входа для приложения.
//

//#include "framework.h"
#include "TransformBinComTree.h"
#include "BinTree.h"
#include "ComTree.h"
#include "commdlg.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
TCHAR filePath[MAX_PATH] = TEXT("");            // путь до файла со структурой дерева
bool pressedOpen = false;                       // нажата кнопка открыть файл (в диалоговом окне)

LPCWSTR s = L"Error, when print big common tree 659 line";

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    
    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TRANSFORMBINCOMTREE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TRANSFORMBINCOMTREE));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TRANSFORMBINCOMTREE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TRANSFORMBINCOMTREE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   HWND ButtonTransfBinTr = CreateWindow(
       L"BUTTON",
       L"Получить бинарное дерево и преобразовать его в дерево общего вида", 
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       40,          // x position 
       60,          // y position 
       500,         // Button width
       50,          // Button height
       hWnd,        // Parent window
       (HMENU)ID_TransfBinTree,
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);

   HWND ButtonTransfComTr = CreateWindow(
       L"BUTTON",
       L"Получить дерево общего вида и преобразовать его в бинарное дерево",
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       700,         // x position 
       60,          // y position 
       500,         // Button width
       50,          // Button height
       hWnd,        // Parent window
       (HMENU)ID_TransfComTree,
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void OpenFileDialog() 
{
    OPENFILENAME OpenFileName = { 0 };
    ZeroMemory(&OpenFileName, sizeof(OpenFileName));
    OpenFileName.lStructSize = sizeof(OpenFileName);
    OpenFileName.lpstrFilter = L"Text Files (*.txt)\0*.txt";
    OpenFileName.lpstrFile = filePath;
    OpenFileName.lpstrFile[0] = L'\0';
    OpenFileName.nMaxFile = sizeof(filePath) / sizeof(TCHAR);
    OpenFileName.lpstrFileTitle = NULL;
    OpenFileName.nMaxFileTitle = 0;
    OpenFileName.lpstrInitialDir = NULL;
    OpenFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    
    if (GetOpenFileName(&OpenFileName)) {
        pressedOpen = true;
    }
    else pressedOpen = false;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    RECT Rect;
    HDC hdc;
    static HDC hCmpDC;
    HBITMAP hBmp;
    static BinTree bt;
    static ComTree ct;
    static BinTree btOfct;
    static ComTree ctOfbt;

    //Флаг отрисовки бинарного дерева и полученного из него общего дерева
    static bool printBinTree = false;
    //Флаг отрисовки общего дерева и полученного из него бинарного дерева
    static bool printComTree = false;
    //Флаг необходимости считывания дерева из файла
    static bool needReadTreeFile = false; 

    static int heightPrintTree = 150; //высота, с которой начинает рисоваться дерево
    POINT aptStar[6] = { 50,2, 2,98, 98,33, 2,33, 98,98, 50,2 };

    switch (message)
    {
    case WM_SIZE:
        //InvalidateRect(hWnd, 0, TRUE);
        //UpdateWindow(hWnd);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case ID_TransfBinTree:
                printBinTree = true;
                printComTree = false;
                needReadTreeFile = true;
                OpenFileDialog();
                InvalidateRect(hWnd, 0, TRUE);
                UpdateWindow(hWnd);
                break;
            case ID_TransfComTree:
                printComTree = true;
                printBinTree = false;
                needReadTreeFile = true;
                OpenFileDialog();
                InvalidateRect(hWnd, 0, TRUE);
                UpdateWindow(hWnd);
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            hdc = BeginPaint(hWnd, &ps);
            GetClientRect(hWnd, &Rect);
            
            SetWindowExtEx(hdc, 2000, 2000, NULL);
            SetViewportExtEx(hdc, Rect.right, Rect.bottom, NULL);

            // Закраска фоновым цветом
            LOGBRUSH br;
            br.lbStyle = BS_SOLID;
            br.lbColor = 0xEECCCC;
            HBRUSH brush;
            brush = CreateBrushIndirect(&br);
            FillRect(hdc, &Rect, brush);
            DeleteObject(brush);
            //TextOut(hdc, 5, 5, filePath, lstrlen(filePath));

            if (printBinTree && pressedOpen)
            {
                heightPrintTree = 150;
                if (needReadTreeFile)
                {
                    const wstring wnameBT = filePath;
                    const string nameBT(wnameBT.begin(), wnameBT.end());
                    bt.ReadBinTreeFromFile(nameBT);
                    needReadTreeFile = false;
                }
                heightPrintTree = bt.PaintBinTree(hdc, heightPrintTree);
                ctOfbt.TransformInComTree(bt);
                ctOfbt.PaintComTree(hdc, heightPrintTree);
            }
            else if (printComTree && pressedOpen)
            {
                heightPrintTree = 150;
                if (needReadTreeFile)
                {
                    const wstring wnameCT = filePath;
                    const string nameCT(wnameCT.begin(), wnameCT.end());
                    ct.ReadComTreeFromFile(nameCT);
                    needReadTreeFile = false;
                }
                heightPrintTree = ct.PaintComTree(hdc, heightPrintTree);
                ct.TransformInBinTree(btOfct);
                btOfct.PaintBinTree(hdc, heightPrintTree);
            }     

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
