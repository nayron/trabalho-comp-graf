//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <jpeg.hpp>
#include <math.h>

#include "ReduCores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	//Mudar a cor do Formul�rio
	Form3->Color = clActiveCaption;
	TColor cor;
	ComboBox1->Items->Add("4");
	ComboBox1->Items->Add("8");
	ComboBox1->Items->Add("16");
	SpeedButton2->Enabled = false;
	SpeedButton3->Enabled = false;
	ComboBox1->Enabled = false;
	TrackBar1->Enabled = false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
	//Image1->Picture->LoadFromFile("img1.bmp"); // Carregando imagem
	//Image1->Picture->LoadFromFile("img2.bmp"); // Carregando imagem
	Image1->Picture->LoadFromFile("img3.bmp"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
	SpeedButton2->Enabled = true;
	ComboBox1->Enabled = true;
	TrackBar1->Enabled = true;
	SpeedButton3->Enabled = true;

}
//---------------------------------------------------------------------------



void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{
	//bugou tudo..n�osei fazer :(
	AnsiString recebe;
	recebe = ComboBox1->Text;
	if(recebe == "4"){
             	int R, G, B, L;

	for(int x = 0; x < IntToStr(Image1->Width); x++) {
		for(int y = 0; y < IntToStr(Image1->Height); y++)
		{
			//????????????????????????????????
		}
	}
	}
	else if(recebe == "8"){
	//?????????????????????????w

	}
	else if(recebe == "16"){

	}
}
//---------------------------------------------------------------------------





void __fastcall TForm3::SpeedButton3Click(TObject *Sender)
{

	int R, G, B, L;

	for(int x = 0; x < IntToStr(Image1->Width); x++) {
		for(int y = 0; y < IntToStr(Image1->Height); y++)
		{
			cor = Image1->Canvas->Pixels[x][y];
			R = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			G = GetGValue(cor);  //Retorna Intensidade de cor Verde
			B = GetBValue(cor);  //Retorna Intensidade de cor azul
			if (L < 0) {
				L = 0;
			} else if (L > 255) {
				L = 255;
			}
			L = ((R*0.3) + (G*0.59) + (B *0.11));
			Image1->Canvas->Pixels[x][y] = RGB(L,L,L);
		}
	}
	TrackBar1->Max = 255;
	TrackBar1->Min = 0;
	TrackBar1->Position  = 127;

}
int TForm3::CalcularLuminosidade(RGBTRIPLE* pixel){
	int R = pixel->rgbtRed;
	int G = pixel->rgbtGreen;
	int B = pixel->rgbtBlue;
	return ((R*0.3) + (G*0.59) + (B *0.11));
}

//---------------------------------------------------------------------------
void __fastcall TForm3::TrackBar1Change(TObject *Sender)
{
	/*aqui nesse bloco  de acordo com o movimento da paleta vai alterando
	 tons de cinza da imagem.*/
	 Graphics::TBitmap *escalaCinza = new Graphics::TBitmap;
	 escalaCinza->LoadFromFile("img3.bmp");
	 //escalaCinza->LoadFromFile("img2.bmp");
	 RGBTRIPLE *resultado;
	 int posicao, novaLuminosidade, R, G, B;
	 posicao = TrackBar1->Position;  //captura a posicao da paleta

	 if (posicao < tonalidade) { //altera a tonalidade dos ton de cinza
		  tonalidade = posicao;
		  posicao = posicao-TrackBar1->Max;
	 }else{
		 tonalidade = posicao;
	 }

	 for (int y = 0; y < escalaCinza->Height; y++) {
		resultado = (RGBTRIPLE*)escalaCinza->ScanLine[y];
		for (int x = 0; x < escalaCinza->Width; x++) {
			//aui captura os pixe da imagem
			novaLuminosidade = CalcularLuminosidade(resultado);
			novaLuminosidade = novaLuminosidade + posicao;
			//Verificando se est� entre o intervalo de 0 � 255
			if (novaLuminosidade > 255){
				novaLuminosidade = 255;
			}
			if (novaLuminosidade < 0){
				novaLuminosidade = 0;
			}

			resultado->rgbtRed = novaLuminosidade;
			resultado->rgbtGreen = novaLuminosidade;
			resultado->rgbtBlue = novaLuminosidade;
			resultado++;
		}
	 }
	 Image1->Picture->Assign(escalaCinza);
	 delete escalaCinza;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton6Click(TObject *Sender)
{
	Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::SpeedButton2Click(TObject *Sender)
{
	for (int y = 0; y < Image1->Height; y++) {
		for (int x = 0; x < Image1->Width; x++) {
			cor = Image1->Canvas->Pixels[x][y];
			int R = GetRValue(cor);  //Retorna Intensidade de cor vermelha
			int G = GetGValue(cor);  //Retorna Intensidade de cor Verde
			int B = GetBValue(cor);
			if(R > 100 && R <= 255 && G > 100 && G <= 255 && B > 100 && B <= 255){
			   Image1->Canvas->Pixels[x][y] = RGB(255,255,255);
			}
			else{
				Image1->Canvas->Pixels[x][y] = RGB(0,0,0);
			}
		}
	}
}







