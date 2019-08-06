//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

int liczby[151];                            //Maksymalna d³ugosc sekwencji
int ile = 0;                                 //Numer rundy
int licznik = 0;
bool gra_rozpoczeta = false;
bool dzwiek = true;




//-- Dzwieki w grze ---------------------------------------------------------

void dzwieki(char *s)
{
    if(dzwiek==true) sndPlaySound(s,SND_ASYNC);
}




//-- Tworzy sekwencjê do zapamiêtania ---------------------------------------

void utwurzSekwencje()
{
    randomize();
    for(int i=0; i<151; i++)
    {
       liczby[i] = random(7)+1;
    }
}




//-- Za³adowanie rysunków pokemonów -----------------------------------------

void LoadPokemon()
{
  Form1->Pok1->Picture->LoadFromFile("img/p1.bmp");
  Form1->Pok2->Picture->LoadFromFile("img/p2.bmp");
  Form1->Pok3->Picture->LoadFromFile("img/p3.bmp");
  Form1->Pok4->Picture->LoadFromFile("img/p4.bmp");
  Form1->Pok5->Picture->LoadFromFile("img/p5.bmp");
  Form1->Pok6->Picture->LoadFromFile("img/p6.bmp");
  Form1->Pok7->Picture->LoadFromFile("img/p7.bmp");
}




//-- Blokuje pokemony -------------------------------------------------------

void LockPokemon()
{
  Form1->Pok1->Enabled = false;
  Form1->Pok2->Enabled = false;
  Form1->Pok3->Enabled = false;
  Form1->Pok4->Enabled = false;
  Form1->Pok5->Enabled = false;
  Form1->Pok6->Enabled = false;
  Form1->Pok7->Enabled = false;
}




//-- Odblokowuje pokemnony --------------------------------------------------

void UnlockPokemon()
{
  Form1->Pok1->Enabled = true;
  Form1->Pok2->Enabled = true;
  Form1->Pok3->Enabled = true;
  Form1->Pok4->Enabled = true;
  Form1->Pok5->Enabled = true;
  Form1->Pok6->Enabled = true;
  Form1->Pok7->Enabled = true;
}




//-- Sekwencje gry ----------------------------------------------------------

void sekwencja()
{
  Application->ProcessMessages(); Sleep(1000);

  ile++;
  Form1->Label2->Caption = "Runda: "+IntToStr(ile);

  LoadPokemon();
  LockPokemon();

  //Odliczanie do startu rundy; i --> ilosc sekund
  for(int i=3; i>=0; i--)
  {
     String komunikat = "Nastêpna runda za: "+IntToStr(i)+" s.";
     if(i==0) komunikat = "Zapamiêtaj sekwencjê";
     Form1->Label1->Caption = komunikat;
     Application->ProcessMessages(); Sleep(1000);
  }

  //Odgrywanie dzwiêków i wyswietlanie obrazów
  for(int i=0; i<ile; i++)
  {
     switch(liczby[i])
     {
        case 1:
        {
           dzwieki("snd/1.wav");
           Form1->Pok1a->Visible = true;
        } break;

        case 2:
        {
           dzwieki("snd/2.wav");
           Form1->Pok2a->Visible = true;
        } break;

        case 3:
        {
           dzwieki("snd/3.wav");
           Form1->Pok3a->Visible = true;
        } break;

        case 4:
        {
           dzwieki("snd/4.wav");
           Form1->Pok4a->Visible = true;
        } break;
        case 5:
        {
           dzwieki("snd/5.wav");
           Form1->Pok5a->Visible = true;
        } break;

        case 6:
        {
           dzwieki("snd/6.wav");
           Form1->Pok6a->Visible = true;
        } break;

        case 7:
        {
           dzwieki("snd/7.wav");
           Form1->Pok7a->Visible = true;
        } break;
     }//Switch

     Application->ProcessMessages(); Sleep(1200);
     Form1->Pok1a->Visible = false;
     Form1->Pok2a->Visible = false;
     Form1->Pok3a->Visible = false;
     Form1->Pok4a->Visible = false;
     Form1->Pok5a->Visible = false;
     Form1->Pok6a->Visible = false;
     Form1->Pok7a->Visible = false;
     Application->ProcessMessages(); Sleep(100);
  }//For

  UnlockPokemon();

  Form1->Label1->Caption = "Powtórz sekwencjê";
  licznik=0;
}




//-- Sekwencje gracza -------------------------------------------------------

void sekwencjaGracza(int i)
{
  if(gra_rozpoczeta == true)
  {
     licznik++;
     if(liczby[licznik-1]!=i)
     {
        Form1->Label1->Caption = "B³¹d! Twój wynik to: "+IntToStr(ile-1)+"\n Zagraj jeszcze raz.";
        dzwieki("snd/koniec.wav");
        gra_rozpoczeta = false;
        LockPokemon();
        Form1->Label1->Cursor = crHandPoint;
        ile=0;
     }
     if(licznik == ile)
     {
        Form1->Label1->Caption = "Doskonale!";
        sekwencja();
     }
  }
}




//-- G³ówne okno aplikacji --------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}




//-- Tworzy sekwencjê w momencie wczytania okna -----------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
     utwurzSekwencje();
}



//-- Klikniêcie na nowa gra -------------------------------------------------

void __fastcall TForm1::Label1Click(TObject *Sender)
{
    if(gra_rozpoczeta == false)
    {
       utwurzSekwencje();
       gra_rozpoczeta = true;
       Label1->Cursor = crArrow;
       dzwieki("snd/start.wav");
       sekwencja();
    }
}




//-- Sekwencje --------------------------------------------------------------

void __fastcall TForm1::Pok1Click(TObject *Sender)
{
    sekwencjaGracza(1);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok2Click(TObject *Sender)
{
    sekwencjaGracza(2);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok3Click(TObject *Sender)
{
    sekwencjaGracza(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pok4Click(TObject *Sender)
{
    sekwencjaGracza(4);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok5Click(TObject *Sender)
{
    sekwencjaGracza(5);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok6Click(TObject *Sender)
{
    sekwencjaGracza(6);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok7Click(TObject *Sender)
{
    sekwencjaGracza(7);
}




//-- Klikniêcia pokemonów --------------------------------------------------

void __fastcall TForm1::Pok1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok1->Picture->LoadFromFile("img/pz1.bmp");
    dzwieki("snd/1.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok1->Picture->LoadFromFile("img/p1.bmp");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok2->Picture->LoadFromFile("img/pz2.bmp");
    dzwieki("snd/2.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok2->Picture->LoadFromFile("img/p2.bmp");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok3MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok3->Picture->LoadFromFile("img/pz3.bmp");
    dzwieki("snd/3.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok3->Picture->LoadFromFile("img/p3.bmp");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok4MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok4->Picture->LoadFromFile("img/pz4.bmp");
    dzwieki("snd/4.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok4->Picture->LoadFromFile("img/p4.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pok5MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok5->Picture->LoadFromFile("img/pz5.bmp");
    dzwieki("snd/5.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok5->Picture->LoadFromFile("img/p5.bmp");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok6MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok6->Picture->LoadFromFile("img/pz6.bmp");
    dzwieki("snd/6.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok6MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok6->Picture->LoadFromFile("img/p6.bmp");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok7MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok7->Picture->LoadFromFile("img/pz7.bmp");
    dzwieki("snd/7.wav");
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Pok7MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    Pok7->Picture->LoadFromFile("img/p7.bmp");
}

//-- Obs³uga zamkniêcia gry -------------------------------------------------

void __fastcall TForm1::Zamknijgr1Click(TObject *Sender)
{
    if(Application->MessageBox("Czy na pewno zamkn¹æ grê?","PotwierdŸ",MB_YESNO | MB_ICONQUESTION)==IDYES) Application->Terminate();
}



//-- Obs³uga w przypadku zamkniêcia okna-------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(Application->MessageBox("Czy na pewno zamkn¹æ grê?","PotwierdŸ",MB_YESNO | MB_ICONQUESTION)==IDNO) Action=caNone;
}



//-- Obs³uga dzwiêków w grze ------------------------------------------------

void __fastcall TForm1::Dzwiek1Click(TObject *Sender)
{
    if(Dzwiek1->Checked == true)
    {
       Dzwiek1->Checked = false;
       Dzwiek1->Caption = "&Wycisz grê";
       dzwiek = true;
    }
    else
    {
       Dzwiek1->Checked = true;
       Dzwiek1->Caption = "Gra &wyciszona";
       dzwiek = false;
    }
}



//-- Wywo³anie okna z informacjami ------------------------------------------

void __fastcall TForm1::InfoClick(TObject *Sender)
{
   Form2->ShowModal();
}



//-- Wywo³anie okna z instrukcj¹ --------------------------------------------

void __fastcall TForm1::InstrukcjaClick(TObject *Sender)
{
   Form3->Visible = True;
}




//---------------------------------------------------------------------------


void __fastcall TForm1::ChangelogClick(TObject *Sender)
{
    Form4->ShowModal();
}
//---------------------------------------------------------------------------

