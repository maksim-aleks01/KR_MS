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

   //Объявление глобальных перемменных и массивов
AnsiString s1= "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
AnsiString s2 = ";Persist Security Info=False";
AnsiString ConStr;


//----------------------------------[Показать таблицу]--------------------------  
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   if (ADOTable1->Active==true) ADOTable1->Active=false;
        if (ComboBox1->Text!="" && Edit1->Text!="")
        {
         ADOTable1->TableName=ComboBox1->Text;
         ADOTable1->Active=true;

         if (ListBox1->Items != 0) ListBox1->Items->Clear(); ListBox2->Items->Clear();//Что бы не переполнялся ListBox1

         StatusBar1->Panels->Items[1]->Text = "Строк: " + FloatToStr(ADOTable1->RecordCount); //Пишем кол-во стобцев и строк
         StatusBar1->Panels->Items[2]->Text = "Столбцев: " + (FloatToStr(ADOTable1->FieldCount)-1);

         for (int i=1;i<ADOTable1->FieldCount;i++)   //Заполняем марками Список "источник"
              {ListBox1->Items->Append(ADOTable1->FieldList->Strings[i]);}

         ComboBox2->Clear();
         for (int i=1;i<ADOTable1->FieldCount;i++)   //Заполняем марками Список 4-го уровня
             {
              ComboBox2->Items->Append(ADOTable1->FieldList->Strings[i]);
             }
        }
        else
        {
         if (Edit1->Text=="")ShowMessage("БД не открыта!");
         if (ComboBox1->Text=="")ShowMessage("Таблица не выбрана!");
        }
}

//------------------[Кнопка открыть БД]-----------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 OpenDialog1->Execute();
 if (ADOTable1->Active) ADOTable1->Active=false;
 if (ADOConnection1->Connected==true) ADOConnection1->Connected=false;
 if (ListBox1->Items != 0) ListBox1->Items->Clear();
 ComboBox1->Clear();
 
 if (OpenDialog1->FileName!="")
 {
  ComboBox1->Clear();
  Edit1->Text=OpenDialog1->FileName;  // заносим путь БД
  ConStr=s1+Edit1->Text+s2; //полный путь к БД
  ADOConnection1->ConnectionString=ConStr;
  ADOConnection1->Connected=true;
  ADOConnection1->GetTableNames(ComboBox1->Items);
  AnsiString Put="input.bmp";
  Image1->Picture->LoadFromFile(Put);  
  AnsiString Path=OpenDialog1->FileName;
  StatusBar1->Panels->Items[0]->Text="Путь " + Path;
 }
}

//------------------------------[DragOver]--------------------------------------
void __fastcall TForm1::ListBox2DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
 TListBox *mSrc =(TListBox *)Source;//Создаем указатель на класс TListBox источник

 //Если у источника больше 0 элементов и выбран хотя бы 1 - разрешаем перенос
 if (mSrc->Count>0 && mSrc->SelCount>0) Accept = true;
 else Accept = false;
}

//------------------------[DragDrop]--------------------------------------------
void __fastcall TForm1::ListBox2DragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
 TListBox *mSrc =(TListBox *)Source;  //Создаем указатель на класс TListBox источник
 TListBox *mDest=(TListBox *)Sender;  //Создаем указатель на класс получатель (TListBox)
 TPoint p; //Объявляем класс для определения координат мыши
 p = Point(X,Y);//Положение курсора мыши
 int k = mDest ->ItemAtPos(p, true); //Определение индекса элемента списка получателя, на который указывает курсор мыши

 if (mSrc->ItemIndex == mDest->ItemIndex && mSrc->Name == mDest->Name ) return;//Проверка на вложеность итемов друг в друга

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

//------------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
   exit(0);
}

//------------------------[Кнопка МЕНЮ->открыть БД]-----------------------------
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
 StatusBar1->Panels->Items[1]->Text = "Строк: " + FloatToStr(ADOTable1->RecordCount);
 StatusBar1->Panels->Items[2]->Text = "Столбцев: " + FloatToStr(ADOTable1->FieldCount);

 for (int i=1;i<ADOTable1->FieldCount;i++) //Заполнение списка источника (станциями)
  {
    ListBox1->Items->Append(ADOTable1->FieldList->Strings[i]);
  }
}

//----------------------[Кнопка МЕНЮ->закрыт БД]--------------------------------
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

   for (int i = 0; i < StringGrid2->ColCount; i++) //Очистка таблицы 2-го уровня
   { for (int j = 0; j < StringGrid2->RowCount; j++)
       { StringGrid2->Cells[i][j] = "";}
   }
   Button7->Enabled = True;//Видима кнопка "Построить таблицу"

   for (int i = 0; i < StringGrid3->ColCount; i++) //Очистка таблицы Расчетов 2-го уровня
   { for (int j = 0; j < StringGrid3->RowCount; j++)
       { StringGrid3->Cells[i][j] = "";}
   }

   Edit2->Text = 0.005; //Дефолтное ззначение Эпсилон
}

//-----------------------[Построить график]-----------------------------//---------------------[Построить таблицу]--------------------------------------
  int iSchetchik = 0;//Счетчик нажатия на кнопку [Построить таблицу]
void __fastcall TForm1::Button7Click(TObject *Sender)
{
 if (ComboBox1->Text!="" && ADOTable1->Active==true)//Проверка открытия БД
 {
  iSchetchik++;
  if ( iSchetchik == 1)
  {Button7->Enabled = False;}//Скрываем кнопку после нажатия

                             //Строим структуру, столбцы и строки
  StringGrid2->RowCount = ADOTable1->RecordCount+1; //Получаем колличество строк  в созд. таблице
  StringGrid2->ColCount = ListBox2->Items->Count+1; //Получаем колличество столбцев в принимаемом списке

  //////////////////Заполняем столбец с Эпохами/////////////////////////////////
   int g=1;
     ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid2->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
       ADOTable1->Next();
       g++;
     };
  //////////////////////////////////////////////////////////////////////////////

   /////////////////////Заполнение таблицы данными///////////////////////////////
 StringGrid2->Cells[0][0] = ADOTable1->FieldList->Strings[0];//Имя нулевой ячейки
 for (int j=0; j<ListBox2->Items->Count; j++)
  {  ADOTable1->First();
   for (int i=0; i<ADOTable1->RecordCount; i++)
      {
        StringGrid2->Cells[j+1][0] = ListBox2->Items->Strings[j];     // заполнение марок в шапке
        StringGrid2->Cells[j+1][i+1] = ADOTable1->FieldByName(ListBox2->Items->Strings[j])->AsString; //заполнение отметок высот
        ADOTable1->Next();
      }
  }
 }
  else
  {
    if (ADOTable1->Active==false && ComboBox1->Text=="") ShowMessage("БД не открыта, не выбрана таблица!");
    if (ADOTable1->Active==true && ComboBox1->Text!="") ShowMessage("Не выбрана таблица!");
    if (ADOTable1->Active==false && ComboBox1->Text!="") ShowMessage("БД не открыта!");
  }
}

//---------------------------------[Очистка таблицы]------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
   for (int i = 0; i < StringGrid2->ColCount; i++)    //Очистка талицы конструктора
   {
    for (int j = 0; j < StringGrid2->RowCount; j++)
       {
        StringGrid2->Cells[i][j] = "";
        iSchetchik = 0;
        Button7->Enabled = True;  //активная кнопка Построить таблицу
       }
   }

   for (int i = 0; i < StringGrid3->ColCount; i++) // Очитска таблицы расчетов
   {
    for (int j = 0; j < StringGrid3->RowCount; j++)
       {
        StringGrid3->Cells[i][j] = "";
       }
   }
   Edit2->Text = 0.005; //Дефолтное ззначение Эпсилон
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
 if((Key!=VK_BACK)&&(Key<'0'||Key>'9')&&(Key!=','))Key=0;// Обработчик ввода эпсилон
}

//-----------------[Переместить все элменты в список источник]----------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   for(int i=0; i<ListBox2->Items->Count; i++)
 {
  ListBox1->Items->Add(ListBox2->Items->Strings[i]);
 }
  ListBox2->Items->Clear();
}

//---------------[Переместить все элменты в список приемник]--------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
 for(int i=0; i<ListBox1->Items->Count; i++)
 {
  ListBox2->Items->Add(ListBox1->Items->Strings[i]);
 }
 ListBox1->Items->Clear();
}

//-------------------------[Кнопка Расчет]--------------------------------------//-------------------------2-ой уровень [Расчет]-----------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
                  if (ComboBox1->Text!="" && StringGrid2->RowCount > 2 && StringGrid2->ColCount >= 2)//Проверка открытия БД
 {
 StringGrid3->RowCount = StringGrid2->RowCount+1; //Строим структуру, строки
 StringGrid3->Cells[0][0] = StringGrid2->Cells[0][0]; //Имя нулевой ячейки

///////////////////Заполнение эпох таблицы расчетов 2-го уровня/////////////////
 int g=1; ADOTable1->First();
     while (!ADOTable1->Eof)
     {
      for (int j = 0; j < ADOTable1->FieldCount; j++)
         StringGrid3->Cells[0][g] = ADOTable1->Fields->Fields[0]->AsFloat;
         ADOTable1->Next();
         g++;
     }
////////////////////////////////////////////////////////////////////////////////
                                           
  StringGrid3->Cells[1][0] = "Mu";
  StringGrid3->Cells[2][0] = "Alpha";
  StringGrid3->Cells[3][0] = "Mu+";
  StringGrid3->Cells[4][0] = "Mu-";
  StringGrid3->Cells[5][0] = "Alpha+";
  StringGrid3->Cells[6][0] = "Alpha-";
  StringGrid3->Cells[7][0] = "Прогноз Мю";
  StringGrid3->Cells[8][0] = "Прогноз Alpha";
  StringGrid3->Cells[9][0] = "Устойчивость";
      //////////////////////Epsilon///////////////////////////////////////////////
 double E=0.005;
 if(Edit2->Text!="")
 E=StrToFloat(Edit2->Text);
 else E=0,005;

    //////////////////////Коэффицент А///////////////////////////////////////////////
 double A=0.1;
 if(Edit3->Text!="" && Edit3->Text <=1 )
 A=StrToFloat(Edit3->Text);
 else A=0,1;
             ////////Расчет Мю, MuMax, MuMin////////
  double Mu(0), MuMax(0), MuMin(0), SumMu(0);
  //double *MuArray = new double [ADOTable1->RecordCount]; //массив значений Мю
  double MuArray [100]; double MaxMuArray [100]; double MinMuArray [100];

  for (int i=0; i<100; i++)//Обнуление массивов
   {
     MuArray[i] = 0;
     MaxMuArray[i] = 0;
     MinMuArray[i] = 0;
   }


  for (int i=1; i<ADOTable1->RecordCount+1; i++)
  {
        Mu =0; MuMax =0; MuMin =0;
        for (int j = 1; j < StringGrid2->ColCount; j++)
        {
          Mu += pow(StrToFloat(StringGrid2->Cells[j][i]),2);//Сумма квадратов строки
          MuMax += pow((StrToFloat(StringGrid2->Cells[j][i]))+E,2);
          MuMin += pow((StrToFloat(StringGrid2->Cells[j][i]))-E,2);
        }
         Mu = sqrt(Mu);//Извлекаем мю из под знака корня
         MuMax = sqrt(MuMax);
         MuMin = sqrt(MuMin);

         SumMu += Mu; //Сумма Мю

         StringGrid3->Cells[1][i] = Mu; //Вывод Мю в таблицу
         StringGrid3->Cells[3][i] = MuMax; //"Mu+"
         StringGrid3->Cells[4][i] = MuMin; //"Mu-"

         MuArray[i-1] = Mu;//Заносим значения в массив
         MaxMuArray[i-1] = MuMax;
         MinMuArray[i-1] = MuMin;
  }
   ////////////////END МЮ/////////////////

               //Расчет Алфьа, MaxAlpha+, MinAlpha-
  //Альфа=arccos(k/Q); k = (h0)*(hi), Q = (MuArray[0]*MuArray[f])
  //////Одномерный динамический массив, содержит 1-ю строку StringGrid2///////////
  //double *Str0Array = new double [StringGrid2->ColCount-1]; //массив нулевой строки
   double Str0Array [100];
   float MaxStr0Array [100];
   float MinStr0Array [100];
  double SumAl=0;

  for (int i=0; i<100; i++) //Обнуление массивов
  {
   Str0Array[i] = 0;
   MaxStr0Array[i] = 0;
   MinStr0Array[i] = 0;
  }

  for (int i=1; i<StringGrid2->ColCount; i++)  //Нулевы
    {
       Str0Array[i-1] = StrToFloat(StringGrid2->Cells[i][1]); //значенния нулевой строки
       MaxStr0Array[i-1] = (StrToFloat(StringGrid2->Cells[i][1]))+E;
       MinStr0Array[i-1] = (StrToFloat(StringGrid2->Cells[i][1]))-E;
    }
////////////////////////////////////////////////////////////////////////////////

     ////k = (h0)*(hi); Умножаем 1строчный массив на ячейки ADOTable1////
  double k=0; double kMax=0; double kMin=0;

  //double *AlArray = new double [StringGrid2->ColCount-1]; //массив значений альфа
  float AlArray [100]; double MaxAlArray [100]; double MinAlArray [100];

  //for (int i=0; i<StringGrid2->ColCount-1; i++) AlArray[i] = 0; // обнуляем массив
  for (int i=0; i<100; i++)
  {
   AlArray[i] = 0;
   MaxAlArray[i] = 0;
   MinAlArray[i] = 0;// обнуляем массив
  }

  for(int f=0; f<StringGrid2->RowCount-1; f++)
  {
    k=0.0; kMax=0; kMin=0;
       for (int j=1; j<StringGrid2->ColCount; j++)
       {
          double dbTemp1 = Str0Array[j-1];
          double dbTemp2 = StrToFloat(StringGrid2->Cells[j][f+1]);

          k += dbTemp1 * dbTemp2; // перемножение элементов 1ой строки на элементы таблицы
          double temp3 = k;
          kMax += MaxStr0Array[j-1] * ((StrToFloat(StringGrid2->Cells[j][f+1]))+E);
          kMin += MinStr0Array[j-1] * ((StrToFloat(StringGrid2->Cells[j][f+1]))-E);
       }


      //double dProverka = k/(MuArray[0]*MuArray[f]);
      double dProverka = k/(MuArray[0]*MuArray[f]);
      double MaXdProverka = kMax/(MaxMuArray[0]*MaxMuArray[f]);
      double MiNdProverka = kMin/(MinMuArray[0]*MinMuArray[f]);

      if (dProverka > 1 ) dProverka = 1;
      if (MaXdProverka > 1 ) MaXdProverka = 1;
      if (MiNdProverka > 1 ) MiNdProverka = 1;


         //AlArray[f] = acos(dProverka) * 180.0 / M_PI;   //acos
         AlArray[f] = acos(dProverka);
         MaxAlArray[f] = acos(MaXdProverka);
         MinAlArray[f] = acos(MiNdProverka);


      SumAl += AlArray[f];
      StringGrid3->Cells[2][f+1] = FloatToStrF(AlArray[f],ffFixed,9,7);//Вывод ALpha в таблицу
      StringGrid3->Cells[5][f+1] = FloatToStr(MaxAlArray[f]);//Вывод ALpha+ в таблицу
      StringGrid3->Cells[6][f+1] = FloatToStr(MinAlArray[f]);//Вывод ALpha- в таблицу

  }
    ///END Альфа///

    //////Расчет прогнрзного значения Мю //////
     double MuPr0 = MuArray[0] * A +(1-A) * (SumMu/StrToFloat(ADOTable1->RecordCount)); //Расчет 0-го прогнрзного значения Мю, среднее значение
     StringGrid3->Cells[7][1] = MuPr0;

     double MuPrArray[100];
     for (int i=0; i<ADOTable1->RecordCount; i++)
        {
          MuPrArray[i] = MuArray[i+1] * A +(1-A) * MuPr0;
          StringGrid3->Cells[7][i+2] = MuPrArray[i];//Вывод Прогнозного Мю в таблицу
        }
     double MuPrB = (SumMu/StrToFloat(ADOTable1->RecordCount)) * A +(1-A) * MuPrArray[ADOTable1->RecordCount]; //Мю последнее
     StringGrid3->Cells[7][ADOTable1->RecordCount+1] = MuPrB;
     //////END Mu-pr//////

     //////Расчет прогнрзного значения Альфа-pr//////
     double AlPr0 = AlArray[0] * A +(1-A) * (SumAl/StrToFloat(ADOTable1->RecordCount)); //Расчет 0-го прогнрзного значения Мю
     StringGrid3->Cells[8][1] = AlPr0;

     double AlPrArray[100];
     for (int i=0; i<ADOTable1->RecordCount; i++)
        {
          AlPrArray[i] = AlArray[i+1] * A +(1-A) * AlPr0;
          StringGrid3->Cells[8][i+2] = AlPrArray[i];//Вывод Прогнозного Альфа в таблицу
        }
     double AlPrB = SumAl-AlArray[0]/(StrToFloat(ADOTable1->RecordCount-1))*A+(1-A)*AlPrArray[ADOTable1->RecordCount-1];


     StringGrid3->Cells[0][ADOTable1->RecordCount+1] = "Прогноз: ";
     StringGrid3->Cells[8][ADOTable1->RecordCount+1] = AlPrB;
     //////END Альфа-pr//////

   //Проверка устойчивости системы
  for(int i=0; i<ADOTable1->RecordCount; i++)
     {
      if(fabs(MinMuArray[i] - MaxMuArray[i])>=fabs(MuArray[i]-MuArray[0]))
        { StringGrid3->Cells[9][i+1]=("+"); }
      else
 	{ StringGrid3->Cells[9][i+1]=("-"); }
     }
 }
   else {
    if (StringGrid2->RowCount <= 2 || StringGrid2->ColCount <= 2){ShowMessage("Таблица не собрана!");}
    if (ComboBox1->Text==""){ShowMessage("БД не открыта!");}
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
 if((Key!=VK_BACK)&&(Key<'0'||Key>'9')&&(Key!=','))Key=0;// Обработчик ввода A
}

//---------------------[График ПРОГНОЗА]------------------------------------------------------
void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
 if (StringGrid3->RowCount > 2)
 {
          if (CheckBox4->Checked == true)
           {
            Series4->Clear(); Series8->Clear();
            for( int i = 0; i < ADOTable1->RecordCount-1; i++)
                   {
                    //Отчерчиваем график Мю-Прогнозное(Альфа-Прогнозное)
                        double MuPrX = StrToFloat(StringGrid3->Cells[7][i+1]);
                        double AlPrY = StrToFloat(StringGrid3->Cells[8][i+1]);
                        double MuPrX1 = StrToFloat(StringGrid3->Cells[7][i+2]);
                        double AlPrY1 = StrToFloat(StringGrid3->Cells[8][i+2]);
                        Series4->AddArrow(MuPrX, AlPrY, MuPrX1, AlPrY1, "", clBlack);
                        Series8->AddXY(MuPrX, AlPrY, "" , clBlack);
                   }
           }
          else {Series4->Clear(); Series8->Clear();}
       }
 else
 {
  if (StringGrid3->RowCount <= 2)
    {
     CheckBox4->Checked = false;
    }
  ShowMessage("Нет необходимых расчетов!");
 }
}

//-------------------[График 4-го уровня]---------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
if (ComboBox1->Text!="" && Edit1->Text!="")//Проверка
 {
   if (ComboBox2->Text!="")
     {
       Series9->Clear(); Series10->Clear();
       ADOTable1->First();
       int i=1;
        while (!ADOTable1->Eof)
             {
              double X = ADOTable1->Fields->Fields[0]->AsFloat;
              double Y = ADOTable1->FieldByName(ComboBox2->Text)->AsFloat;

              ADOTable1->Next();

              double X1 = ADOTable1->Fields->Fields[0]->AsFloat;
              double Y1 = ADOTable1->FieldByName(ComboBox2->Text)->AsFloat;

              Series9->AddArrow(X, Y, X1, Y1, "", clRed);   // StringGrid2->Cells[0][3]   StringGrid2->Cells[0][i]
              Series10->AddXY(X1, Y1, "", clRed);
              i++;
             }




           //double X = ADOTable1->Fields->Fields[0]->AsFloat;
           //double Y = ADOTable1->FieldByName(ComboBox2->Text)->AsFloat;

          // double X1 = ADOTable1->FieldByName(ComboBox2->Text)->AsFloat+1;
          // double Y1 = ADOTable1->Fields->Fields[1]->AsFloat+1;

           //Series11->AddXY(X, Y, "", clRed);

          
     }
 }//END проверка
 else {if (ComboBox1->Text=="" || Edit1->Text=="")ShowMessage("Не открыта БД или таблица!");}
}

//-------------------------[График МЮ(Альфа)]-----------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
 if (StringGrid3->RowCount > 2)
 { 
  if (CheckBox1->Checked == true)
           {
            Series1->Clear(); Series5->Clear();
            for( int i = 0; i < ADOTable1->RecordCount-1; i++)
                   {
                    //Отчерчиваем график Мю(Альфа)
                     double MuX = StrToFloat(StringGrid3->Cells[1][i+1]);
                     double AlY = StrToFloat(StringGrid3->Cells[2][i+1]);
                     double MuX1 = StrToFloat(StringGrid3->Cells[1][i+2]);
                     double AlY1 = StrToFloat(StringGrid3->Cells[2][i+2]);
                     Series1->AddArrow(MuX, AlY, MuX1, AlY1, StringGrid3->Cells[1][i+1], clRed); //Mu(Al)
                     Series5->AddXY(MuX, AlY, "" , clRed);
                   }
           }
   else {Series1->Clear(); Series5->Clear();}
 }
 else
 {
  if (StringGrid3->RowCount <= 2)
    {
     CheckBox1->Checked = false;                         
    }
  ShowMessage("Нет необходимых расчетов!");
 }
}

//-------------------------[График МЮ+(Альфа+)]-----------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
if (StringGrid3->RowCount > 2)
 {
 if (CheckBox2->Checked == true)
           {
            Series3->Clear(); Series7->Clear();
            for( int i = 0; i < ADOTable1->RecordCount-1; i++)
                   {
                         double MuMaxX = StrToFloat(StringGrid3->Cells[3][i+1]);
                         double AlMaxY = StrToFloat(StringGrid3->Cells[5][i+1]);
                         double MuMaxX1 = StrToFloat(StringGrid3->Cells[3][i+2]);
                         double AlMaxY1 = StrToFloat(StringGrid3->Cells[5][i+2]);
                         Series3->AddArrow(MuMaxX, AlMaxY, MuMaxX1, AlMaxY1, StringGrid3->Cells[3][i+1], clGreen);
                         Series7->AddXY(MuMaxX, AlMaxY, "" , clGreen);
                   }
           }
          else {Series3->Clear(); Series7->Clear();}
        }
 else
 {
  if (StringGrid3->RowCount <= 2)
    {
     CheckBox2->Checked = false;
    }
  ShowMessage("Нет необходимых расчетов!");
 }
}

//-----------------------------[График Мю-(Альфа-)]-----------------------------
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
 if (StringGrid3->RowCount > 2)
 {
   if (CheckBox3->Checked == true)
           {
            Series2->Clear(); Series6->Clear();
            for( int i = 0; i < ADOTable1->RecordCount-1; i++)
                   {
                        double MuMinX = StrToFloat(StringGrid3->Cells[4][i+1]);
                        double AlMinY = StrToFloat(StringGrid3->Cells[6][i+1]);
                        double MuMinX1 = StrToFloat(StringGrid3->Cells[4][i+2]);
                        double AlMinY1 = StrToFloat(StringGrid3->Cells[6][i+2]);
                        Series2->AddArrow(MuMinX, AlMinY, MuMinX1, AlMinY1, StringGrid3->Cells[4][i+1], clBlue); //StringGrid3->Cells[4][i+1]
                        Series6->AddXY(MuMinX, AlMinY, "" , clBlue);
                   }
           }
          else {Series2->Clear(); Series6->Clear();}
        }
 else
 {
  if (StringGrid3->RowCount <= 2)
    {
     CheckBox3->Checked = false;
    }
  ShowMessage("Нет необходимых расчетов!");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2KeyPress(TObject *Sender, char &Key)
{
 if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;// Обработчик ввода марки
}

//---------------------[Добавить запись]----------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
if (ADOTable1->Active==true)
{
 double h, h0, h1;
 double n=(ADOTable1->FieldCount-1); //Колличество столбцев
 double *ptrarray = new double [n];
 srand(time(NULL));  //Псевдослучайные числа с привязкой к текущему времени

 ADOTable1 -> First();
 while (!ADOTable1->Eof) //Модуль суммы разностей
{
  h0 = ADOTable1->Fields->Fields[1]->AsFloat;
  if (ADOTable1->Eof) break;
  ADOTable1 -> Next();
  h1 = ADOTable1->Fields->Fields[1]->AsFloat;
  h += fabs(h1-h0); //fabs модуль
 }

 double dD = h/(Form1->ADOTable1->RecordCount-1);
 double dD_t=dD;

 int t=1;
 while (dD_t<1)
 {
  dD_t = dD_t*10;
  t++;
 }

 double dG=0;
 ADOTable1->First();
 for (int i=1;i<=ADOTable1->FieldCount-1;i++)
 {
  dG=(rand()%(int(dD*pow(10,t))*2+1)-int(dD*pow(10,t)))/pow(10,t);
  ptrarray[i-1]=ADOTable1->Fields->Fields[i]->AsFloat+dG;
 }

 ADOTable1 -> Last();
 ADOTable1 -> Insert();
 ADOTable1->Fields->Fields[0]->AsFloat = ADOTable1->RecordCount+1; //Добавление сроки

 for (int i=0; i<ADOTable1->FieldCount-1; i++)
 {
  ADOTable1->Fields->Fields[i+1]->AsFloat=(ptrarray[i]);
 }
 ADOTable1->Post();
 delete [] ptrarray;
}
else
{
 ShowMessage("Таблица не открыта!");
}
}
//------------------------------------------------------------------------------






