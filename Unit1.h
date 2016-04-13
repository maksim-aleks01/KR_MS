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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TLabel *Label1;
        TImage *Image1;
        TButton *Button1;
        TEdit *Edit1;
        TComboBox *ComboBox1;
        TButton *Button2;
        TStatusBar *StatusBar1;
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
        TMemo *Memo1;
        TListBox *ListBox2;
        TStaticText *StaticText2;
        TListBox *ListBox1;
        TStaticText *StaticText1;
        TButton *Button3;
        TLabel *Label2;
        TLabel *Label3;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall ListBox2DragOver(TObject *Sender, TObject *Source,
          int X, int Y, TDragState State, bool &Accept);
        void __fastcall ListBox2DragDrop(TObject *Sender, TObject *Source,
          int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
