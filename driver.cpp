#include "DAG.h"

int main()
{
	//creating main graph along with test vertices and edges
	DAG g;
	Vertex v0(0, 3.5, "COEN212: Digital System Design I");
	Vertex v1(1, 3, "COEN231: Introduction to Discrete Mathematics");
	Vertex v2(2, 3, "COEN243: Programming Methodology I");
	Vertex v3(3, 3, "COEN244: Programming Methodology II");
	Vertex v4(4, 3.5, "COEN311: Computer Organization and Software");
	Vertex v5(5, 3.5, "COEN313: Digital System Design II");
	Vertex v6(6, 3.5, "COEN315: Digital Electronics");
	Vertex v7(7, 3.5, "COEN316: Computer Architecture and Design");
	Vertex v8(8, 3.5, "COEN317: Microprocessor Systems");
	Vertex v9(9, 3, "COEN320: Introduction to Real-Time Systems");
	Vertex v10(10, 3.5, "COEN345: Software Testing and Validation");
	Vertex v11(11, 3.5, "COEN346: Operating Systems");
	Vertex v12(12, 3, "COEN352: Data Structures and Algorithms");
	Vertex v13(13, 3, "COEN390: Computer Engineering Product Design Project");
	Vertex v14(14, 3, "COEN413: Hardware Functional Verification");
	Vertex v15(15, 4, "COEN421: Embedded Systems Design");
	Vertex v16(16, 3, "COEN422: Cyber-Physical Systems");
	Vertex v17(17, 3, "COEN424: Programming on the Cloud");
	Vertex v18(18, 3, "COEN432: Applied Evolutionary and Learning Algorithms");
	Vertex v19(19, 3, "COEN433: Biological Computing and Synthetic Biology");
	Vertex v20(20, 3, "COEN434: Microfluidic Devices for Synthetic Biology");
	Vertex v21(21, 3.5, "COEN445: Communication Networks and Protocols");
	Vertex v22(22, 3, "COEN446: Internet of Things");
	Vertex v23(23, 3, "COEN447: Software-Defined Networking");
	Vertex v24(24, 4, "COEN451: VLSI Circuit Design");
	Vertex v25(25, 4, "COEN490: Capstone Computer Engineering Design Project");
	Vertex v26(26, 3, "COEN498: Topics in Computer Engineering");
	Vertex* temp = new Vertex[27];
	temp[0] = v0;
	temp[1] = v1;
	temp[2] = v2;
	temp[3] = v3;
	temp[4] = v4;
	temp[5] = v5;
	temp[6] = v6;
	temp[7] = v7;
	temp[8] = v8;
	temp[9] = v9;
	temp[10] = v10;
	temp[11] = v11;
	temp[12] = v12;
	temp[13] = v13;
	temp[14] = v14;
	temp[15] = v15;
	temp[16] = v16;
	temp[17] = v17;
	temp[18] = v18;
	temp[19] = v19;
	temp[20] = v20;
	temp[21] = v21;
	temp[22] = v22;
	temp[23] = v23;
	temp[24] = v24;
	temp[25] = v25;
	temp[26] = v26;
	Edge e0(0, 2, 3, 1.0);
	Edge e1(1, 0, 4, 0.5);
	Edge e2(2, 2, 4, 0.5);
	Edge e3(3, 4, 7, 0.5);
	Edge e4(4, 5, 7, 0.5);
	Edge e5(5, 4, 8, 0.25);
	Edge e6(6, 5, 8, 0.75);
	Edge e7(7, 11, 9, 1.0);
	Edge e8(8, 4, 11, 0.67);
	Edge e9(9, 12, 11, 0.33);
	Edge e10(10, 1, 12, 0.5);
	Edge e11(11, 3, 12, 0.5);
	Edge e12(12, 3, 13, 0.2);
	Edge e13(13, 4, 13, 0.2);
	Edge e14(14, 5, 14, 1.0);
	Edge e15(15, 8, 15, 0.34);
	Edge e16(16, 9, 15, 0.34);
	Edge e17(17, 9, 16, 0.5);
	Edge e18(18, 11, 17, 1.0);
	Edge e19(19, 12, 18, 1.0);
	Edge e20(20, 0, 19, 0.5);
	Edge e21(21, 3, 19, 0.5);
	Edge e22(22, 11, 21, 1);
	Edge e23(23, 21, 22, 1);
	Edge e24(24, 8, 23, 0.67);
	Edge e25(25, 21, 23, 0.33);
	Edge e26(26, 0, 24, 0.5);
	Edge e27(27, 12, 25, 0.2);
	Edge e28(28, 13, 25, 0.2);
	Edge* temp2 = new Edge[29];
	temp2[0] = e0;
	temp2[1] = e1;
	temp2[2] = e2;
	temp2[3] = e3;
	temp2[4] = e4;
	temp2[5] = e5;
	temp2[6] = e6;
	temp2[7] = e7;
	temp2[8] = e8;
	temp2[9] = e9;
	temp2[10] = e10;
	temp2[11] = e11;
	temp2[12] = e12;
	temp2[13] = e13;
	temp2[14] = e14;
	temp2[15] = e15;
	temp2[16] = e16;
	temp2[17] = e17;
	temp2[18] = e18;
	temp2[19] = e19;
	temp2[20] = e20;
	temp2[21] = e21;
	temp2[22] = e22;
	temp2[23] = e23;
	temp2[24] = e24;
	temp2[25] = e25;
	temp2[26] = e26;
	temp2[27] = e27;
	temp2[28] = e28;

	return 0;
}