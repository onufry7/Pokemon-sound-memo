//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Pomoc1;
        TMenuItem *Instrukcja;
        TMenuItem *Info;
        TMenuItem *Gra1;
        TImage *Tlo;
        TImage *Pok1;
        TImage *Pok2;
        TImage *Pok6;
        TImage *Pok3;
        TImage *Pok4;
        TImage *Pok7;
        TImage *Pok5;
        TMenuItem *Zamknijgr1;
        TLabel *Label1;
        TImage *Pok1a;
        TImage *Pok2a;
        TImage *Pok3a;
        TImage *Pok4a;
        TImage *Pok5a;
        TImage *Pok6a;
        TImage *Pok7a;
        TMenuItem *Opcje1;
        TMenuItem *Dzwiek1;
        TLabel *Label2;
        TMenuItem *Changelog;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Label1Click(TObject *Sender);
        void __fastcall Pok1Click(TObject *Sender);
        void __fastcall Pok2Click(TObject *Sender);
        void __fastcall Pok3Click(TObject *Sender);
        void __fastcall Pok4Click(TObject *Sender);
        void __fastcall Pok5Click(TObject *Sender);
        void __fastcall Pok6Click(TObject *Sender);
        void __fastcall Pok7Click(TObject *Sender);
        void __fastcall Pok1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok3MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok4MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok4MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok5MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok5MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok6MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok6MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok7MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Pok7MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Zamknijgr1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Dzwiek1Click(TObject *Sender);
        void __fastcall InfoClick(TObject *Sender);
        void __fastcall InstrukcjaClick(TObject *Sender);
        void __fastcall ChangelogClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
