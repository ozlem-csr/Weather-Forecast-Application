#include<graphics.h>
#include<string.h>
FILE *dosya,*yedekle;

struct hava_durumu {
	char gun[30];
	char hava[30];
} van[30];

void bulut(int x, int y, int renk) {
	setfillstyle(SOLID_FILL,renk);
	setcolor(renk);
	fillellipse(x+25,y,32,32);
	fillellipse(x+75,y,32,32);
	fillellipse(x,y+40,35,35);
	fillellipse(x+50,y+40,33,33);
	fillellipse(x+100,y+40,35,35);
}

void gunes(int x, int y) {
	setfillstyle(SOLID_FILL,YELLOW);
	setcolor(YELLOW);
	fillellipse(x,y,50,50);   
}

void damla(int x,int y) {
	int i;
	setcolor(LIGHTBLUE);
	for(i=0; i<10; i++) {
		line(x-i,y+i,x+i,y+i);
	}
	sector(x+1,y+10,180,0,10,10 );
}

void kar(int x,int y) {
	setcolor(WHITE);
	line(x-10,y,x+10,y);
	line(x,y-10,x,y+10);
	line(x-10,y-7,x+10,y+7);
	line (x-10,y+7,x+10,y-7);
}

void metin(int x, int y, int yaziBoyutu, int renk, char *yazi) {
	setcolor(renk);

	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,yaziBoyutu);
	outtextxy(x,y,yazi);

}

void degis();
void yedekleme();
void degistir(char durum[30]);

int j=0,a,b;
char durum[30];

int main() {

	initwindow(1340,740,"Hava Durumu");
	char durum[30]="";
	int arkaplan;
	dosya=fopen("havadurumu.txt","w");
		fprintf(dosya,"pazartesi parcali_bulutlu\n");
		fprintf(dosya,"sali yagmurlu\n");
		fprintf(dosya,"carsamba karli\n");
		fprintf(dosya,"persembe gunesli\n");
		fprintf(dosya,"cuma gunesli\n");
		fprintf(dosya,"cumartesi bulutlu\n");
		fprintf(dosya,"pazar parcali_bulutlu\n");
		fclose(dosya);

	while(1) {

		setcolor(YELLOW);
		settextstyle(3,0,1);
		outtextxy(20,715,"o gunun animasyonunu gormek istiyorsanız butona basin");
		setfillstyle(SOLID_FILL,YELLOW);
		rectangle(10,80,1330,700);
		line(190,80,190,700);
		line(380,80,380,700);
		line(570,80,570,700);
		line(760,80,760,700);
		line(950,80,950,700);
		line(1140,80,1140,700);
		line(10,140,1330,140);

		settextstyle(10,HORIZ_DIR,5);
		outtextxy(310,25,"VAN HAFTALIK HAVA DURUMU");

		settextstyle(8,HORIZ_DIR,3);
		outtextxy(20,95,"Pazartesi");
		gunes(80,250);
		bulut(50,270,WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(60,450,"20 C"); //derece(°) sembolünü yazınca random verdiği için eklemedim.
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(36,520,"Parcali bulutlu");

		rectangle(45,590,145,620);
		outtextxy(50,595,"DEGIS");

		getmouseclick(WM_LBUTTONDOWN,a,b);
		if(a<145&&a>45&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"pazartesi");
			yedekleme();
			degistir(durum);
			exit(0);
		}

		if(a<330&&a>230&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"sali");
			yedekleme();
			degistir(durum);
			exit(0);
		}

		if(a<520&&a>420&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"carsamba");
			yedekleme();
			degistir(durum);
			exit(0);
		}
		if(a<710&&a>610&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"persembe");
			yedekleme();
			degistir(durum);
			exit(0);
		}
		if(a<900&&a>800&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"cuma");
			yedekleme();
			degistir(durum);
			exit(0);
		}
		if(a<1095&&a>995&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"cumartesi");
			yedekleme();
			degistir(durum);
			exit(0);
		}
		if(a<1280&&a>1180&&b<620&&b>590)
		{
			cleardevice();
			strcpy(durum,"pazar");
			yedekleme();
			degistir(durum);
			exit(0);
		}
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		rectangle(45,640,145,670);
		outtextxy(60,645,"BAS");
		
		if(a<145&&a>45&&b<670&&b>640) {
			cleardevice();
			int i=0;
			while(1) {
				getmouseclick(WM_LBUTTONDOWN,a,b);
				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					line(675,60,675,60+i);
					line(675,220,675,220-i);
					line(595,140,595+i,140);
					line(755,140,755-i,140);
					line(610,70,610+i,70+i);
					line(736,192,736+i,192+i);
					line(736,70,736-i,70+i);
					line(610,192,610-i,192+i);
					setfillstyle(SOLID_FILL,YELLOW);
					fillellipse(675,140,60,60);
					bulut(getmaxx()-30*i,150,WHITE);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				setfillstyle(SOLID_FILL,YELLOW);
				fillellipse(675,140,60,60);
				bulut(690,150,WHITE);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(690,100,"Pazartesi");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(690,450,"20 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(680,580,"Parcali bulutlu");
				delay(100);
			}

		}
		setcolor(WHITE);
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(245,95,"Sali");
		bulut(235,270,DARKGRAY);
		setcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(240,450,"12 C");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(240,520,"Yagmurlu");
		setcolor(LIGHTBLUE);
		damla(240,350);
		damla(280,350);
		damla(320,350);
		damla(260,380);
		damla(300,380);

		setcolor(WHITE);
		rectangle(230,590,330,620);
		outtextxy(235,595,"DEGIS");

		
		rectangle(230,640,330,670);
		outtextxy(245,645,"BAS");
		if(a<330&&a>230&&b<670&&b>640) {
			cleardevice();
			int i=0,j=0;
			
			while(1) {
				
				getmouseclick(WM_LBUTTONDOWN,a,b);
				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					bulut(getmaxx()-30*i,140,DARKGRAY);
					delay(100);
				}
				for(j; j<26; j+=5) {
					cleardevice();
					bulut(670,150,DARKGRAY);
					damla(680,230+j);
					damla(720,230+j);
					damla(760,230+j);
					damla(700,260+j);
					damla(740,260+j);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				bulut(670,150,DARKGRAY);
				damla(680,230);
				damla(720,230);
				damla(760,230);
				damla(700,260);
				damla(740,260);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(690,110,"Sali");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(685,450,"12 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(680,580,"Yagmurlu");
				delay(100);
			}
		}
		setcolor(WHITE);
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(410,95,"Carsamba");
		bulut(425,270,DARKGRAY);
		setcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(425,450,"0 C");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(450,520,"Karli");
		setcolor(WHITE);
		kar(430,360);
		kar(470,360);
		kar(510,360);
		kar(450,390);
		kar(490,390);
		
		rectangle(420,590,520,620);
		outtextxy(425,595,"DEGIS");
		
		rectangle(420,640,520,670);
		outtextxy(435,645,"BAS");
		if(a<520&&a>420&&b<670&&b>640) {
			cleardevice();
			int i=0,j=0;
			while(1) {
				getmouseclick(WM_LBUTTONDOWN,a,b);
				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					bulut(getmaxx()-30*i,140,DARKGRAY);
					delay(100);
				}
				for(j; j<26; j+=5) {
					cleardevice();
					bulut(670,150,DARKGRAY);
					kar(680,230+j);
					kar(720,230+j);
					kar(760,230+j);
					kar(700,260+j);
					kar(740,260+j);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				bulut(670,150,DARKGRAY);
				kar(680,240);
				kar(720,240);
				kar(760,240);
				kar(700,270);
				kar(740,270);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(690,110,"Carsamba");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(690,450,"0 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(690,580,"Karli");
				delay(100);
			}
		}
		setcolor(WHITE);
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(600,95,"Persembe");
		gunes(660,280);
		setcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(630,450,"14 C");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(625,520,"Gunesli");

		rectangle(610,590,710,620);
		outtextxy(615,595,"DEGIS");
		
		rectangle(610,640,710,670);
		outtextxy(625,645,"BAS");
		if(a<710&&a>610&&b<670&&b>640) {
			cleardevice();
			int i=0;
			while(1) {
				getmouseclick(WM_LBUTTONDOWN,a,b);
				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					line(675,60,675,60+i);
					line(675,220,675,220-i);
					line(595,140,595+i,140);
					line(755,140,755-i,140);
					line(610,70,610+i,70+i);
					line(736,192,736+i,192+i);
					line(736,70,736-i,70+i);
					line(610,192,610-i,192+i);
					setfillstyle(SOLID_FILL,YELLOW);
					fillellipse(675,140,60,60);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				fillellipse(675,140,60,60);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(690,100,"Persembe");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(670,450,"14 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(670,580,"Gunesli");
				delay(100);
			}
		}
		setcolor(WHITE);
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(810,95,"Cuma");
		gunes(850,280);
		setcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(820,450,"15 C");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(815,520,"Gunesli");

		rectangle(800,590,900,620);
		outtextxy(805,595,"DEGIS");
		
		rectangle(800,640,900,670);
		outtextxy(815,645,"BAS");
		if(a<900&&a>800&&b<670&&b>640) {
			cleardevice();
			int i=0;
			while(1) {
				getmouseclick(WM_LBUTTONDOWN,a,b);
				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					line(675,60,675,60+i);
					line(675,220,675,220-i);
					line(595,140,595+i,140);
					line(755,140,755-i,140);
					line(610,70,610+i,70+i);
					line(736,192,736+i,192+i);
					line(736,70,736-i,70+i);
					line(610,192,610-i,192+i);
					setfillstyle(SOLID_FILL,YELLOW);
					fillellipse(675,140,60,60);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				setfillstyle(SOLID_FILL,YELLOW);
				fillellipse(675,140,60,60);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(690,100,"Cuma");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(665,450,"15 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(665,580,"Gunesli");
				delay(100);
			}
		}
		setcolor(WHITE);
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(970,95,"Cumartesi");
		bulut(990,270,WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(1000,450,"16 C");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(1015,520,"Bulutlu");

		rectangle(995,590,1095,620);
		outtextxy(1000,595,"DEGIS");
		
		rectangle(995,640,1095,670);
		outtextxy(1010,645,"BAS");
		if(a<1095&&a>995&&b<670&&b>640) {
			cleardevice();
			int i=0;
			while(1) {
				getmouseclick(WM_LBUTTONDOWN,a,b);

				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					bulut(getmaxx()-30*i,150,WHITE);
					bulut(30*i,150,WHITE);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				bulut(690,150,WHITE);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(700,110,"Cumartesi");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(700,450,"16 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(710,580,"Bulutlu");
				delay(100);
			}
		}
		setcolor(WHITE);
		settextstyle(8,HORIZ_DIR,3);
		outtextxy(1190,95,"Pazar");
		gunes(1210,250);
		bulut(1190,270,WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(1195,450,"19 C");
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		outtextxy(1170,520,"Parcali bulutlu");
	
		rectangle(1180,590,1280,620);
		outtextxy(1185,595,"DEGIS");
		
		rectangle(1180,640,1280,670);
		outtextxy(1195,645,"BAS");
		if(a<1280&&a>1180&&b<670&&b>640) {
			cleardevice();
			int i=0;
			while(1) {
				getmouseclick(WM_LBUTTONDOWN,a,b);
				setcolor(YELLOW);
				for(i; i<16; i+=5) {
					cleardevice();
					setlinestyle(0,0,4);
					line(675,60,675,60+i);
					line(675,220,675,220-i);
					line(595,140,595+i,140);
					line(755,140,755-i,140);
					line(610,70,610+i,70+i);
					line(736,192,736+i,192+i);
					line(736,70,736-i,70+i);
					line(610,192,610-i,192+i);
					setfillstyle(SOLID_FILL,YELLOW);
					fillellipse(675,140,60,60);
					bulut(getmaxx()-30*i,150,WHITE);
					delay(100);
				}
				cleardevice();
				setcolor(YELLOW);
				circle(30,30,20);
				line(20,30,40,30);
				line(20,30,30,20);
				line(20,30,30,40);
				setcolor(WHITE);
				if(a<50&&a>10&&b<50&&b>10) {
					cleardevice();
					break;
				}
				setfillstyle(SOLID_FILL,YELLOW);
				fillellipse(675,140,60,60);
				bulut(690,150,WHITE);
				setcolor(YELLOW);
				settextstyle(8,HORIZ_DIR,3);
				outtextxy(695,100,"Pazar");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
				outtextxy(690,450,"19 C");
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
				outtextxy(680,580,"Parcali bulutlu");
				delay(100);
			}
		}
		delay(10);
	}
	getch();
	closegraph();
	return 0;
}

void yedekleme() {
	if((yedekle=fopen("yedekozlem.txt","w"))!=NULL) {

		if((dosya=fopen("havadurumu.txt","r"))!=NULL) {

			while(!feof(dosya)) {

				fscanf(dosya,"%s %s\n",van[j].gun,van[j].hava);

				fprintf(yedekle,"%s %s\n",van[j].gun,van[j].hava);

				j=j+1;
			}
		}
	}
	remove("havadurumu.txt");

	fclose(dosya);
	fclose(yedekle);
}

void degistir(char durum[30]) {//silme komutu: eskisini silip yenisini yazıyor.
	if((dosya=fopen("havadurumu.txt","w"))!=NULL) {

		if((yedekle=fopen("yedekozlem.txt","r"))!=NULL) {

			while(!feof(yedekle)) {
				
				fscanf(yedekle,"%s %s\n",van[j].gun,van[j].hava);

				if(strcmpi(durum,van[j].gun)==0 ) {
					degis();
				}
				fprintf(dosya,"%s %s\n",van[j].gun,van[j].hava);
				j=j+1;
			}
		}
	}
	remove("yedekozlem.txt");//yedek dosyasını silme.
	fclose(dosya);
	fclose(yedekle);
}

void degis() {
	int kontrol=1;
	int a,b;
	cleardevice();
	while(kontrol) {
			 
		settextstyle(10,HORIZ_DIR,4);
		outtextxy(105,40,"HANGI HAVA DURUMUNU ILE DEGISTIRMEK ISTIYORSUNUZ?");

		gunes(170,350);
		bulut(140,370,WHITE);
		rectangle(100,290,290,450);
		setcolor(WHITE);

		gunes(390,370);
		rectangle(300,290,490,450);
		setcolor(WHITE);

		bulut(540,350,WHITE);
		rectangle(500,290,690,450);
		setcolor(WHITE);

		bulut(740,325,DARKGRAY);
		damla(745,400);
		damla(785,400);
		damla(825,400);
		damla(765,425);
		damla(805,425);
		rectangle(700,290,890,450);
		setcolor(WHITE);


		bulut(940,325,DARKGRAY);
		kar(945,410);
		kar(985,410);
		kar(1025,410);
		kar(965,435);
		kar(1005,435);
		rectangle(900,290,1090,450);
		setcolor(WHITE);
		getmouseclick(WM_LBUTTONDOWN,a,b);

		if(a<290&&a>100&&b<450&&b>290) {
			strcpy(van[j].hava,"parcali_bulutlu");
			kontrol=0;
		}
		if(a<490&&a>300&&b<450&&b>290) {
			strcpy(van[j].hava,"gunesli");
			kontrol=0;
		}
		if(a<690&&a>500&&b<450&&b>290) {
			strcpy(van[j].hava,"bulutlu");
			kontrol=0;
		}
		if(a<890&&a>700&&b<450&&b>290) {
			strcpy(van[j].hava,"yagmurlu");
			kontrol=0;
		}
		if(a<1090&&a>900&&b<450&&b>290) {
			strcpy(van[j].hava,"karli");
			kontrol=0;
		}
		delay(100);
	}
}