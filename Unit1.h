//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ActnCtrls.hpp>
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include <ActnMenus.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <Chart.hpp>
#include <DbChart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *Label1;
        TButton *Button1;
        TEdit *Edit1;
        TComboBox *ComboBox1;
        TButton *Button2;
        TDBGrid *DBGrid1;
        TADOConnection *ADOConnection1;
        TDataSource *DataSource1;
        TADOTable *ADOTable1;
        TMainMenu *MainMenu1;
        TMenuItem *Menu1;
        TMenuItem *Open1;
        TMenuItem *CloseDB1;
        TMenuItem *Exit1;
        TMenuItem *About1;
        TMenuItem *N1;
        TActionList *ActionList1;
        TImageList *ImageList1;
        TOpenDialog *OpenDialog1;
        TListBox *ListBox2;
        TStaticText *StaticText2;
        TListBox *ListBox1;
        TStaticText *StaticText1;
        TStatusBar *StatusBar1;
        TTabSheet *TabSheet3;
        TDBChart *DBChart1;
        TLineSeries *Series1;
        TButton *Button6;
        TStringGrid *StringGrid2;
        TButton *Button7;
        TButton *Button8;
        TImage *Image1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label2;
        TStringGrid *StringGrid1;
        TStringGrid *StringGrid3;
        TButton *Button4;
        TLabel *Label3;
        TEdit *Edit2;
        TLabel *Label4;
        TButton *Button3;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ListBox2DragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
        void __fastcall ListBox2DragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall CloseDB1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
