#include "Story.h"

Story::Story(int type){
	nama = "";
	current = type;
	isDone = false;
	progress = 0;
	story = selectStory(type);
}

string Story::selectStory(int type){
	switch (type){
		case 0	: return "Pada suatu hari di negeri yang tercinta ini ...";
		case 1	: return "Terdapat segerombolan teroris yang diduga bernama YUDI";
		case 2	: return "Sebagai geng brandal anda harus melawan teroris ini!";
		case 3	: return "TIMOTH4Y mendanai anda untuk membeli sebuah kapal laut";
		case 4	: return "Kapal laut ini dapat menghancurkan matahari dalam 1x tembak!";
		case 5	: return "Anda harus berhati-hati dalam misi ini ...";
		case 6	: return "Teroris memiliki helikopter yang cukup canggih";
		case 7	: return "Helikopter ini diawaki oleh Capt. Calvin Sadewo";
		case 8	: return "Pertama, kami harus cek identitas anda!";
		case 9	: return "Oke ...";
		case 10	: return string("Selamat datang ") + nama;
		case 11	: return "Kami harus memvalidasi bahwa anda bukan mata-mata sadewo";
		case 12	: return "Silahkan pilih warna favorit anda!";
		case 13	: return "Sebentar gan ...";
		case 14	: return "Oke, kami baru saja melakukan pengujian di ITB dan IPB";
		case 15	: return "Anda dinyatakan bebas flu burung ...";
		case 16	: return "eh, maksudnya anda dinyatakan bebas mata-mata ...";
		case 17	: return "Sekarang, silahkan amati kondisi wilayah kita ...";
		case 18	: return "Seperti yang sudah anda amati ...";
		case 19	: return "Capt. Sadewo sudah masuk ke wilayah kita";
		case 20	: return "Sekarang anda kami tugaskan untuk menyerang langsung";
		case 21	: return "Kami sudah siapkan kapal laut anda.";
		case 22	: return "Selamat berperang!";
		case 23	: return  string("Selamat datang kembali ") + nama;
		case 24	: return "Sebelumnya selamat atas keberhasilan anda ...";
		case 25	: return "Capt. Sadewo telah mampus dibom oleh anda!";
		case 26	: return "Saat ini misi anda adalah memburu gembong utamanya";
		case 27	: return "Yup! Anda benar!";
		case 28	: return "Kita akan memburu YUDI!";
		case 29	: return "Kami sudah menyiapkan kendaraan dan senjata anda";
		case 30	: return "Selamat bertempur gan!";

		//case 17	: return "Anda dinyatakan bebas flu burung ...";

		//case 15	: return "Sebentar gan ...";

		default	: return "Anjing anjing anjing asu asu"; 
	}
}

void Story::next(){
	gotoxy(30,30);
	printf("                               ");
	gotoxy(13,25);
	printf("                                                                                                               ");
	gotoxy(199,99);

	isDone = false;

	progress = 0;
	
	story = selectStory(++current);
}

void Story::gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}

void Story::printStory(){
	progress += 0.0003f;
	int pjg = (int)progress;
	if (pjg > story.length()){
		isDone = true;
		gotoxy(30,30);
		printf("Tekan S untuk melanjutkan ...");
		gotoxy(199,99);
		
		return;
	}
	gotoxy(13,25);
	printf(story.substr(0, pjg).c_str());
	gotoxy(199,99);
	
}
