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
  AnsiString Path=OpenDialog1->FileName;
  StatusBar1->Panels->Items[0]->Text="Путь" + Path;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if (ADOTable1->Active==false) {return; ShowMessage("БД не открыта!"); Button3->Visible = false;}
  int n(0), m(0);//n-колличество строк, m- коллонок
  n = ADOTable1->RecordCount;
  m = ADOTable1->FieldCount;
  Label2->Caption = "Строк: " + FloatToStr(n);
  Label3->Caption = "Столбцев: " + FloatToStr(m - 1);
  StatusBar1->Panels->Items[1]->Text = "Строк: " + FloatToStr(n);
  StatusBar1->Panels->Items[2]->Text = "Столбцев: " + FloatToStr(m - 1);
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

 //Если у источника больше 0 элементов и выбран хотя бы 1 - разрешаем перенос
 if (mSrc->Count>0 && mSrc->SelCount>0) Accept = true;
 else Accept = false;


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
   if (mSrc->ItemIndex == mDest->ItemIndex && mSrc->Name == mDest->Name ) return;
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
StatusBar1->Panels->Items[0]->Text="Путь" + Path;
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

  float Mu=0;    //Альфа=arccos(k/Q); k = вектор(h0)*вектор(hi), Q = sqrt(Mu0*Mi).
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
 float Al=0, k=0, Q=0;//Альфа=arccos(k/Q); k = (h0)*(hi), Q = (Mu0*Mi)^2.

////////Одномерный динамический массив, содержит 1-ю строку ADOTable1///////////
  float *farray = new float [ADOTable1->FieldCount];
  ADOTable1->First();
  for (int i=0; i<ADOTable1->FieldCount; i++)
    {
       farray[i] = ADOTable1->Fields->Fields[i]->AsFloat;
    }
////////////////////////////////////////////////////////////////////////////////

////k = (h0)*(hi); Умножаем 1строчный массив на ячейки ADOTable1////
  float *karray = new float [ADOTable1->FieldCount];
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
      //StringGrid1->Cells[2][i+1] = karray[i];
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
         for (int j=0; j<ADOTable1->FieldCount; j++)
         {
          Q += pow((ADOTable1->Fields->Fields[j]->AsFloat),2);
         }
         float Q1;
         if (z == 0)  {Q1 = Q;}
         Qarray[z] = sqrt(Q)*sqrt(Q1);
      //StringGrid1->Cells[3][z+1] = Qarray[z];
      z++;
      ADOTable1->Next();
    }
////////////////////////////////////////////////////////////////////////////////

///////////////////Получаем Альфа///////////////////////////////////////////////
           for (int i=0; i<ADOTable1->RecordCount; i++)
           {
            StringGrid1->Cells[2][i+1] = acos(karray[i]/Qarray[i]);
           }
////////////////////////////////////////////////////////////////////////////////


   /////////////////////////Освобождаем память///////////////////////////////////
   delete [] farray;
   delete [] karray;
   delete [] Qarray;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
   Series1->LinePen->Width = 5; Series1->SeriesColor = clRed;
   Series1->Clear();

        for( int i = 0; i < ADOTable1->RecordCount; i++)
          {
            Series1->AddXY(StrToFloat(StringGrid1->Cells[1][i]), StrToFloat(StringGrid1->Cells[2][i]));
          }

}
//---------------------------------------------------------------------------




  int iSchetchik = 0;//Счетчик нажатия на кнопку [Построить таблицу]
void __fastcall TForm1::Button7Click(TObject *Sender)
{
  iSchetchik++;
                           //Строим структуру, столбцы и строки
  int iKolRecord = ListBox2->Items->Count;//Получаем колличество строк в принимаемом списке
  int iKolField =  ADOTable1->FieldCount;//Получаем колличество столбцев в созд. таблице
  StringGrid2->RowCount=StringGrid2->RowCount+(iKolRecord-1);
  StringGrid2->ColCount = StringGrid2->ColCount+(iKolField-2);

  if ( iSchetchik == 1)
  {
    Button7->Enabled = False;
  }
    int iAR = ADOTable1->RecordCount; //Колличество строк в ADOTable1


    for (int i=0; i<iAR; i++)
    {   int j=0;
       // while (ListBox2->Items[i] == ADOTable1->Fields->Fields[i])
        {
         //   StringGrid1->Cells[i][j] = ADOTable1->Fields[0][iAR]
        }
        j++;
    }
  //
   //for (int j=0; j<iKolRecord; j++)
   {
   // if (ListBox2->Items[i] == ADOTable1->Fields[0][iAR])
     {
    //StringGrid1->Cells[i][j] = ADOTable1->Fields[0][iAR];
     }

   }




}
//---------------------------------[Очистка таблицы]------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
   for (int i = 0; i < StringGrid2->ColCount; i++)
   {
    for (int j = 0; j < StringGrid2->RowCount; j++)
    {
      StringGrid2->Cells[i][j] = "";
      iSchetchik = 0;
      Button7->Enabled = True;
    }
   }
   StringGrid2->RowCount= 0;
   StringGrid2->ColCount = 0;
}
//---------------------------------------------------------------------------


