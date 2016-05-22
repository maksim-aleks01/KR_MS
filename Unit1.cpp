//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

AnsiString s1= "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
AnsiString s2 = ";Persist Security Info=False";
AnsiString ConStr;
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
   if (ADOTable1->Active==true) ADOTable1->Active=false;
        if (ComboBox1->Text!="")
        {
         ADOTable1->TableName=ComboBox1->Text;
         ADOTable1->Active=true;
        }
  // ADOTable1->TableName=ComboBox1->Text;
  // ADOTable1->Active=true;

}
//------------------[Кнопка открыть БД]---------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  OpenDialog1->Execute();
if (ADOTable1->Active) ADOTable1->Active=false;
if (ADOConnection1->Connected==true) ADOConnection1->Connected=false;
ComboBox1->Clear();

if (OpenDialog1->FileName!="")
  {
  Edit1->Text=OpenDialog1->FileName;
  ConStr=s1+Edit1->Text+s2;
  ADOConnection1->ConnectionString=ConStr;
  ADOConnection1->Connected=true;
  ADOConnection1->GetTableNames(ComboBox1->Items);
  AnsiString Put="input.bmp";
  Image1->Picture->LoadFromFile(Put);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  int n(0), m(0);//n-колличество строк, m- коллонок
  n = ADOTable1->RecordCount;
  m = ADOTable1->FieldCount;
  Label2->Caption = n;
  Label3->Caption = m;
  StatusBar1->Panels->Items[1]->Text = n;
  StatusBar1->Panels->Items[2]->Text = m -1;
  ADOTable1->First();//Устанавливааем на 1 строку перед циклом считывания


  //Объявлеение массива и проход по нему
 int **array = new int* [n];
  for (int i=0; i<n; i++)
  {     array[i] = new int [m];
        for (int j = 0; j < m; j++)
        {
        
        }
        ADOTable1->Next();
  }

 // for (int i=0; i<n; i++) //Освобождаем память
 // delete [] array [m];

  //job for ListBox
  for (int i=1;i<m;i++){
  ListBox1->Items->Append(ADOTable1->FieldList->Strings[i]);
  };
}

void __fastcall TForm1::ListBox2DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
 TListBox *mSrc =(TListBox *)Source;//Создаем указатель на класс TListBox источник
 TListBox *mDest=(TListBox *)Sender;

 //Если у источника больше 0 элементов и выбран хотя бы 1 - разрешаем перенос
 if (mSrc->Count>0 && mSrc->SelCount>0) Accept = true;
 else Accept = false;

 if (mSrc->Items == mDest->Items && mSrc->Name == mDest->Name ) return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox2DragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
 TListBox *mSrc =(TListBox *)Source;  //Создаем указатель на класс TListBox источник
 TListBox *mDest=(TListBox *)Sender;  //Создаем указатель на класс получатель (TListBox)
 TPoint p; //Объявляем класс для определения координат мыши
 p = Point(X,Y);//Положение курсора мыши
 int k = mDest ->ItemAtPos(p, true); //Определение индекса элемента списка получателя, на который указывает курсор мыши

 //Вставляем перемещенные элементы в список получатель
 //Положение перемещенного элемента будет определенно положением екрсора мыши
 for (int i=0; i<mSrc->Count; i++)//Проход по всем элементам списка источника
   {
     if (mSrc->Selected[i] == true)//Если текущий элемент выделен
     mDest->Items->Insert(k, mSrc->Items->Strings[i]);//Добавляем элемент всписок получатель на место с индесом k
    }

    //Удаляем выделенные элементы из списка источника
 for (int i=0; i<mSrc->Count; i++)//Проход по всем элементам списка источника
   {
    if (mSrc->Selected[i] == true)//Если текущий элемент выделен
     {
       mSrc->Items->Delete(i);// Удаляем элемент из списка источника
       i--; //Уменьшаем индекс т.к. элемент перемещен
     }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
        exit(0);
}
//------------------------[Кнопка МЕНЮ->открыть БД]--------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
AnsiString ConStr,Path;
ConStr="Provider=Microsoft.Jet.OLEDB.4.0; User ID=Admin; Data Source=";
if (!OpenDialog1->Execute()) return;
Path=OpenDialog1->FileName;
ConStr=ConStr+Path;
StatusBar1->Panels->Items[0]->Text=Path;
ADOConnection1->ConnectionString=ConStr;
ADOConnection1->Connected=true;
ADOConnection1->GetTableNames(ComboBox1->Items);
ADOTable1->Active=true;
Edit1->Text=Path;
AnsiString Put="input.bmp";
Image1->Picture->LoadFromFile(Put);
}
//----------------------[Кнопка МЕНЮ->закрыт БД]------------------------------------

void __fastcall TForm1::CloseDB1Click(TObject *Sender)
{
  //Main_menu->Close
ADOConnection1->Connected=false;
ADOTable1->Active=false;
ComboBox1->Clear();
Edit1->Clear();

Image1->Picture->Bitmap = NULL;  //Очищяем Image1

for (int i=0; i < StatusBar1->Panels->Count; i++)//Чистка StatusBar
    {
      StatusBar1->Panels->Items[i]->Text = "";
    }

ListBox1->Items->Clear();//Чистка 2го уровня drag&drop
ListBox2->Items->Clear();
}
//-----------------------[Кнопка обработать массив]----------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{        
/////////////////////////Заполнение шапки таблицы///////////////////////////////
      StringGrid1->Cells[1][0] = "Mu";
      StringGrid1->Cells[2][0] = "Alpha";
////////////////////////////////////////////////////////////////////////////////
     int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid1->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       g++;
       ADOTable1->Next();
     };
////////////////////////////////////////////////////////////////////////////////

  float Mu=0;    //Альфа=arccos(k/Q); k = вектор(h0)*вектор(hi), Q = Mu0*Mi.
  int i=1;
  ADOTable1->First();
  while (!ADOTable1->Eof)
  {
        Mu =0;
        for (int j = 1; j < ADOTable1->FieldCount; j++)
        {              ////////Расчет Мю  ////////
          Mu += pow((ADOTable1->Fields->Fields[j]->AsFloat),2);//Сумма квадратов строки
        }
         Mu = sqrt(Mu);//Извлекаем мю из под знака корня
         StringGrid1->Cells[1][i] = Mu; //Вывод Мю в таблицу
         ADOTable1->Next();
         i++;
  };
}

//---------------------Алфьа------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
 float Al=0, k=0, Q=0;//Альфа=arccos(k/Q); k = вектор(h0)*вектор(hi), Q = Mu0*Mi.

////////Одномерный динамический массив, содержит 1-ю строку ADOTable1///////////
  float *farray = new float [ADOTable1->RecordCount];
  ADOTable1->First();
  for (int i=0; i<ADOTable1->FieldCount; i++)
    {
       farray[i] = ADOTable1->Fields->Fields[i]->AsFloat;
    }
////////////////////////////////////////////////////////////////////////////////

////k = вектор(h0)*вектор(hi); Умножаем 1строчный массив на ячейки ADOTable1////
  float *karray = new float [ADOTable1->RecordCount];
   int i=0;
  ADOTable1->First();
  while (!ADOTable1->Eof)
  {
    k=0;
       for (int j=1; j<ADOTable1->FieldCount; j++)
       {
          k += farray[j] * ADOTable1->Fields->Fields[j]->AsFloat;
       }
      karray[i] = k;
      //StringGrid1->Cells[2][i+1] = k;
      i++;
      ADOTable1->Next();
  };
////////////////////////////////////////////////////////////////////////////////

///////////////////Q = Mu0*Mi.//////////////////////////////////////////////////
    float *Qarray = new float [ADOTable1->RecordCount];
    int z=0;
    ADOTable1->First();
    while (!ADOTable1->Eof)
    {
        Q = 0;
         for (int j=1; j<ADOTable1->FieldCount; j++)
         {
          Q += pow((ADOTable1->Fields->Fields[j]->AsFloat),2);
         }
          Qarray[z] = Q;
     // StringGrid1->Cells[3][z+1] = Qarray[z];
      z++;
      ADOTable1->Next();
    }
////////////////////////////////////////////////////////////////////////////////

///////////////////Получаем Альфа///////////////////////////////////////////////
           for (int i=0; i<ADOTable1->RecordCount; i++)
           {
                Al = Qarray[i]/karray[i];
                if ( Al > 1 ) Al =1;
             StringGrid1->Cells[2][i+1] = acos(Al);
           }
////////////////////////////////////////////////////////////////////////////////


  /////////////////////////Освобождаем память///////////////////////////////////
   delete [] farray;
   delete [] karray;
   delete [] Qarray;
}
//---------------------------------------------------------------------------

