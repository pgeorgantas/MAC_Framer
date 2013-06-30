/*
Εργαστηριακή Άσκηση 1
Γεωργαντάς Φίλιππος
40266
*/
#include <stdio.h>
#include <string.h>

//Definitions
	typedef unsigned char byte;
	byte ICMP_Data[]="abcde";
//Variables
	byte pkt[100];

//Code
void main()
{
	int i,protocol;
	printf("MAC Frame Constructor.\n");
	printf("Choose protocol:\n  1 for ICMP\n  2 for TCP\n");
	do
		scanf("%d", &protocol);
	while((protocol!=1) && (protocol!=2));
	pkt[0]=1;		//Source MAC
	pkt[1]=1;
	pkt[2]=1;
	pkt[3]=1;
	pkt[4]=1;
	pkt[5]=1;
	pkt[6]=2;		//Destination MAC
	pkt[7]=2;
	pkt[8]=2;
	pkt[9]=2;
	pkt[10]=2;
	pkt[11]=2;
	pkt[12]=8;		//Type
	pkt[13]=0;
	pkt[14]=0x45;		//Version and IHL
	pkt[15]=0;		//Type of Service
	pkt[16]=0;		//Total Length
					//Total Length of IP Header + Data
	pkt[18]=0;		//Identification
	pkt[19]=0;
	pkt[20]=0;		//Flags and Fragment Offset
	pkt[21]=0;
	pkt[22]=255;	//Time to Live
					//Protocol
	pkt[24]=0;		//Header Checksum
	pkt[25]=0;
	pkt[26]=3;		//IP Source Address
	pkt[27]=3;
	pkt[28]=3;
	pkt[29]=3;
	pkt[30]=4;		//IP Destination Address
	pkt[31]=4;
	pkt[32]=4;
	pkt[33]=4;
	if (protocol==1) //ICMP
	{
		pkt[23]=1;		//Protocol is ICMP
		pkt[34]=8;		//Type
		pkt[35]=0;		//Code
		pkt[36]=0;		//Checksum
		pkt[37]=0;
		pkt[38]=0;		//Identifier
		pkt[39]=0;
		pkt[40]=0;		//Sequence Number
		pkt[41]=1;
		for (i=0;i<strlen(ICMP_Data);i++)
			pkt[42+i]=ICMP_Data[i];
		pkt[43+i]=0;		//FCS
		pkt[44+i]=0;
		pkt[45+i]=0;
		pkt[46+i]=0;
		int j=46+i;
		for(i=0;i<=j;i++)
			if (i%16==0)
				printf("\n%0x",pkt[i]);
			else
				printf("%0x",pkt[i]);
	}
	else if (protocol==2)
	{
		pkt[13]=6;		//Type is 0x0806h for TCP
		pkt[23]=6;		//Protocol is TCP

		pkt[34]=1;		//Identification
		pkt[35]=1;		//Source Port
		pkt[36]=0;
		pkt[37]=0;		//Destination Port
		pkt[38]=80;
		pkt[39]=0;		//Sequence Number
		pkt[40]=0;
		pkt[41]=0;		
		pkt[42]=0;
		pkt[43]=0;		//Acknowledgement Number
		pkt[44]=0;
		pkt[45]=0;
		pkt[46]=1;
		pkt[47]=0;		//Data Offset + Reserved
		pkt[48]=0;
		pkt[49]=2;		//Flags
		pkt[50]=255;	//Window
		pkt[51]=255;
		pkt[52]=0;		//Checksum
		pkt[53]=0;
		pkt[54]=0;		//Urgent Pointer
		pkt[55]=0;
		pkt[56]=0;		//FCS
		pkt[57]=0;
		pkt[58]=0;
		pkt[59]=0;
		for(i=0;i<59;i++)
			if (i%16==0)
				printf("\n%0x",pkt[i]);
			else
				printf("%0x",pkt[i]);
	}
}
void Handle_MAC_Frm(byte pkt[])
{
	if(pkt[12]==8 && pkt[13]==0)			//Type
		if(pkt[23]==6)						//Protocol
			if(pkt[34]==0 && pkt[35]==80)	//Port
				return;
}