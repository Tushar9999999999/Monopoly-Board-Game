#include "head.h"

//Initializing the board
void initialize_board()
{
	//0
	strcpy(property[0].name, "START");
	property[0].price = 0;
	strcpy(property[0].owner, "Prohibited");

	//1
	strcpy(property[1].name, "GUWAHATI");	
	strcpy(property[1].color, "Brown");
	property[1].price = 60;
	property[1].rent[0] = 2;
	property[1].rent[1] = 10;
	property[1].rent[2] = 30;
	property[1].rent[3] = 90;
	property[1].rent[4] = 160;
	property[1].rent[5] = 250;
	property[1].nhouses = 0;
	property[1].mortgage = false;
	strcpy(property[1].owner, "no owner");

	//2
	strcpy(property[2].name, "COMMUNITY CHEST");
	property[2].price = 0;
	strcpy(property[2].owner, "Prohibited");

	//3
	strcpy(property[3].name, "BHUBHANESHWAR");	
	strcpy(property[3].color, "Brown");
	property[3].price = 60;
	property[3].rent[0] = 4;
	property[3].rent[1] = 20;
	property[3].rent[2] = 60;
	property[3].rent[3] = 180;
	property[3].rent[4] = 320;
	property[3].rent[5] = 450;
	property[3].nhouses = 0;
	property[3].mortgage = false;
	strcpy(property[3].owner, "no owner");

	//4
	strcpy(property[4].name, "INCOME TAX");
	property[4].price = 0;
	strcpy(property[4].owner, "Prohibited");

	//5
	strcpy(property[5].name, "CHENNAI RAILWAY STATION");
	strcpy(property[5].color, "Station");
	property[5].price = 200;
	property[5].mortgage = false;
	strcpy(property[5].owner, "no owner");

	//6
	strcpy(property[6].name, "PANHAJI(GOA)");	
	strcpy(property[6].color, "Light Blue");
	property[6].price = 100;
	property[6].rent[0] = 6;
	property[6].rent[1] = 30;
	property[6].rent[2] = 90;
	property[6].rent[3] = 270;
	property[6].rent[4] = 400;
	property[6].rent[5] = 550;
	property[6].nhouses = 0;
	property[6].mortgage = false;
	strcpy(property[6].owner, "no owner");

	//7
	strcpy(property[7].name, "CHANCE");
	property[7].price = 0;
	strcpy(property[7].owner, "Prohibited");
	//8
	strcpy(property[8].name, "AGRA");	
	strcpy(property[8].color, "Blue");
	property[8].price = 100;
	property[8].rent[0] = 6;
	property[8].rent[1] = 30;
	property[8].rent[2] = 90;
	property[8].rent[3] = 270;
	property[8].rent[4] = 400;
	property[8].rent[5] = 550;
	property[8].nhouses = 0;
	property[8].mortgage = false;
	strcpy(property[8].owner, "no owner");

	//9
	strcpy(property[9].name, "VADODARA");	
	strcpy(property[9].color, "Blue");
	property[9].price = 120;
	property[9].rent[0] = 8;
	property[9].rent[1] = 40;
	property[9].rent[2] = 100;
	property[9].rent[3] = 300;
	property[9].rent[4] = 450;
	property[9].rent[5] = 600;
	property[9].nhouses = 0;
	property[9].mortgage = false;
	strcpy(property[9].owner, "no owner");

	//10
	strcpy(property[10].name, "JUST VISITING");
	property[10].price = 0;
	strcpy(property[10].owner, "Prohibited");

	//11
	strcpy(property[11].name, "LUDHIANA");	
	strcpy(property[11].color, "Pink");
	property[11].price = 140;
	property[11].rent[0] = 10;
	property[11].rent[1] = 50;
	property[11].rent[2] = 150;
	property[11].rent[3] = 450;
	property[11].rent[4] = 625;
	property[11].rent[5] = 750;
	property[11].nhouses = 0;
	property[11].mortgage = false;
	strcpy(property[11].owner, "no owner");

	//12
	strcpy(property[12].name, "ELECTRIC COMPANY");
	property[12].price = 150;
	strcpy(property[12].owner, "no owner");

	//13
	strcpy(property[13].name, "PATNA");	
	strcpy(property[13].color, "Pink");
	property[13].price = 140;
	property[13].rent[0] = 10;
	property[13].rent[1] = 50;
	property[13].rent[2] = 150;
	property[13].rent[3] = 450;
	property[13].rent[4] = 625;
	property[13].rent[5] = 750;
	property[13].nhouses = 0;
	property[13].mortgage = false;
	strcpy(property[13].owner, "no owner");

	//14
	strcpy(property[14].name, "BHOPAL");	
	strcpy(property[14].color, "Pink");
	property[14].price = 160;
	property[14].rent[0] = 12;
	property[14].rent[1] = 60;
	property[14].rent[2] = 180;
	property[14].rent[3] = 500;
	property[14].rent[4] = 700;
	property[14].rent[5] = 900;
	property[14].nhouses = 0;
	property[14].mortgage = false;
	strcpy(property[14].owner, "no owner");

	//15
	strcpy(property[15].name, "HOWRAH RAILWAY STATION");
	strcpy(property[15].color, "Station");
	property[15].price = 200;
	property[15].mortgage = false;
	strcpy(property[15].owner, "no owner");

	//16
	strcpy(property[16].name, "INDORE");	
	strcpy(property[16].color, "Orange");
	property[16].price = 180;
	property[16].rent[0] = 14;
	property[16].rent[1] = 70;
	property[16].rent[2] = 200;
	property[16].rent[3] = 550;
	property[16].rent[4] = 750;
	property[16].rent[5] = 950;
	property[16].nhouses = 0;
	property[16].mortgage = false;
	strcpy(property[16].owner, "no owner");

	//17
	strcpy(property[17].name, "COMMUNITY CHEST");
	property[17].price = 0;
	strcpy(property[17].owner, "Prohibited");

	//18
	strcpy(property[18].name, "NAGPUR");	
	strcpy(property[18].color, "Orange");
	property[18].price = 180;
	property[18].rent[0] = 14;
	property[18].rent[1] = 70;
	property[18].rent[2] = 200;
	property[18].rent[3] = 550;
	property[18].rent[4] = 750;
	property[18].rent[5] = 950;
	property[18].nhouses = 0;
	property[18].mortgage = false;
	strcpy(property[18].owner, "no owner");

	//19
	strcpy(property[19].name, "KOCHI");	
	strcpy(property[19].color, "Orange");
	property[19].price = 200;
	property[19].rent[0] = 16;
	property[19].rent[1] = 80;
	property[19].rent[2] = 220;
	property[19].rent[3] = 600;
	property[19].rent[4] = 800;
	property[19].rent[5] = 1000;
	property[19].nhouses = 0;
	property[19].mortgage = false;
	strcpy(property[19].owner, "no owner");

	//20
	strcpy(property[20].name, "FREE PARKING");
	property[20].price = 0;
	strcpy(property[20].owner, "Prohibited");

	//21
	strcpy(property[21].name, "LUCKNOW");	
	strcpy(property[21].color, "Red");
	property[21].price = 220;
	property[21].rent[0] = 18;
	property[21].rent[1] = 90;
	property[21].rent[2] = 250;
	property[21].rent[3] = 700;
	property[21].rent[4] = 875;
	property[21].rent[5] = 1050;
	property[21].nhouses = 0;
	property[21].mortgage = false;
	strcpy(property[21].owner, "no owner");

	//22
	strcpy(property[22].name, "CHANCE");
	property[22].price = 0;
	strcpy(property[22].owner, "Prohibited");

	//23
	strcpy(property[23].name, "CHANDIGARH");	
	strcpy(property[23].color, "Red");
	property[23].price = 220;
	property[23].rent[0] = 18;
	property[23].rent[1] = 90;
	property[23].rent[2] = 250;
	property[23].rent[3] = 700;
	property[23].rent[4] = 875;
	property[23].rent[5] = 1050;
	property[23].nhouses = 0;
	property[23].mortgage = false;
	strcpy(property[23].owner, "no owner");

	//24
	strcpy(property[24].name, "JAIPUR");	
	strcpy(property[24].color, "Red");
	property[24].price = 240;
	property[24].rent[0] = 20;
	property[24].rent[1] = 100;
	property[24].rent[2] = 300;
	property[24].rent[3] = 750;
	property[24].rent[4] = 925;
	property[24].rent[5] = 1100;
	property[24].nhouses = 0;
	property[24].mortgage = false;
	strcpy(property[24].owner, "no owner");

	//25
	strcpy(property[25].name, "NEW DELHI RAILWAY STATION");
	strcpy(property[25].color, "Station");
	property[25].price = 200;
	property[25].mortgage = false;
	strcpy(property[25].owner, "no owner");

	//26
	strcpy(property[26].name, "PUNE");	
	strcpy(property[26].color, "Yellow");
	property[26].price = 260;
	property[26].rent[0] = 22;
	property[26].rent[1] = 110;
	property[26].rent[2] = 330;
	property[26].rent[3] = 800;
	property[26].rent[4] = 975;
	property[26].rent[5] = 1150;
	property[26].nhouses = 0;
	property[26].mortgage = false;
	strcpy(property[26].owner, "no owner");

	//27
	strcpy(property[27].name, "HYDERABAD");	
	strcpy(property[27].color, "Yellow");
	property[27].price = 260;
	property[27].rent[0] = 22;
	property[27].rent[1] = 110;
	property[27].rent[2] = 330;
	property[27].rent[3] = 800;
	property[27].rent[4] = 975;
	property[27].rent[5] = 1150;
	property[27].nhouses = 0;
	property[27].mortgage = false;
	strcpy(property[27].owner, "no owner");

	//28
	strcpy(property[28].name, "WATER WORKS");
	property[28].price = 150;
	strcpy(property[28].owner, "no owner");

	//29
	strcpy(property[29].name, "AHMEDABAD");	
	strcpy(property[29].color, "Yellow");
	property[29].price = 280;
	property[29].rent[0] = 24;
	property[29].rent[1] = 120;
	property[29].rent[2] = 360;
	property[29].rent[3] = 850;
	property[29].rent[4] = 1025;
	property[29].rent[5] = 1200;
	property[29].nhouses = 0;
	property[29].mortgage = false;
	strcpy(property[29].owner, "no owner");

	//30
	strcpy(property[30].name, "GO TO JAIL");
	property[30].price = 0;
	strcpy(property[30].owner, "Prohibited");

	//31
	strcpy(property[31].name, "KOLKATA");	
	strcpy(property[31].color, "Green");
	property[31].price = 300;
	property[31].rent[0] = 26;
	property[31].rent[1] = 130;
	property[31].rent[2] = 390;
	property[31].rent[3] = 900;
	property[31].rent[4] = 1100;
	property[31].rent[5] = 1275;
	property[31].nhouses = 0;
	property[31].mortgage = false;
	strcpy(property[31].owner, "no owner");

	//32
	strcpy(property[32].name, "CHENNAI");	
	strcpy(property[32].color, "Green");
	property[32].price = 300;
	property[32].rent[0] = 26;
	property[32].rent[1] = 130;
	property[32].rent[2] = 390;
	property[32].rent[3] = 900;
	property[32].rent[4] = 1100;
	property[32].rent[5] = 1275;
	property[32].nhouses = 0;
	property[32].mortgage = false;
	strcpy(property[32].owner, "no owner");

	//33
	strcpy(property[33].name, "COMMUNITY CHEST");
	property[33].price = 0;
	strcpy(property[33].owner, "Prohibited");

	//34
	strcpy(property[34].name, "BENGALURU");	
	strcpy(property[34].color, "Green");
	property[34].price = 320;
	property[34].rent[0] = 28;
	property[34].rent[1] = 150;
	property[34].rent[2] = 390;
	property[34].rent[3] = 900;
	property[34].rent[4] = 1200;
	property[34].rent[5] = 1400;
	property[34].nhouses = 0;
	property[34].mortgage = false;
	strcpy(property[34].owner, "no owner");

	//35
	strcpy(property[35].name, "CHHATRAPATI SHIVAJI TERMINUS");
	strcpy(property[35].color, "Station");
	property[35].price = 200;
	property[35].mortgage = false;
	strcpy(property[35].owner, "no owner");
	//36
	strcpy(property[36].name, "CHANCE");
	property[36].price = 0;
	strcpy(property[36].owner, "Prohibited");

	//37
	strcpy(property[37].name, "DELHI");	
	strcpy(property[37].color, "Dark blue");
	property[37].price = 350;
	property[37].rent[0] = 35;
	property[37].rent[1] = 175;
	property[37].rent[2] = 500;
	property[37].rent[3] = 1100;
	property[37].rent[4] = 1300;
	property[37].rent[5] = 1500;
	property[37].nhouses = 0;
	property[37].mortgage = false;
	strcpy(property[37].owner, "no owner");

	//38
	strcpy(property[38].name, "SUPER TAX");
	property[38].price = 0;
	strcpy(property[38].owner, "Prohibited");

	//39
	strcpy(property[39].name, "MUMBAI");	
	strcpy(property[39].color, "Dark blue");
	property[39].price = 400;
	property[39].rent[0] = 50;
	property[39].rent[1] = 175;
	property[39].rent[2] = 500;
	property[39].rent[3] = 110;
	property[39].rent[4] = 1700;
	property[39].rent[5] = 2000;
	property[39].nhouses = 0;
	property[39].mortgage = false;
	strcpy(property[39].owner, "no owner");
}