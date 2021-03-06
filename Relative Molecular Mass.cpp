// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
char Pdtable[120][4]{ "?","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu" \
,"Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm",\
"Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np",\
"Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og" };
double ct[99], Mr, Ar[120] = { 0,1,4,7,9,11,12,14,16,19,20,23,24,27,28,31,32,35.5,40,39,40,45,48,51,52,55,56,59,63.5,65,70,73,75,79,80,84,85.5,88,89,91\
,93,96,99,101,103,106,108,112,115,119,122,128,127,131,133,137,139,140,141,144,147,150,152,157,159,162.5,165,167,169,173,175,178.5,181,184,186,190,192,195,197,200.5,\
204,207,209,210,210,222,223,226,227,232,231,238,237,244,243,247,247,251,254,257,258,259,260,261,262,263,262,265,266,269,272,277,287,289,288,289,293,294};
int Brh, ename[99], Enum;
using namespace std;
void Mrc(int kEy) {
	cout << "输入一个数字作为元素个数，然后依次输入分子中各元素原子序数和原子数" << endl;
	cin >> Enum;
	for (int i = 0;i < Enum;i++) {
		cin >> ename[i] >> ct[i];
		Mr += (Ar[ename[i]] * ct[i]);
	}
	if (kEy) {
		cout << "Mr(";
		for (int j = 0;j < Enum;j++) {
			cout << Pdtable[ename[j]];
			if (ct[j] != 1)cout << ct[j];
		}
		cout << ")=" << Mr << endl;
	}
}
void Bfc() {
	Mrc(0);
    int exista=0, ziel=-998, pos1;
	double massq,res;
	cout << "输入所求元素的原子序数" << endl;
	while (!exista) {
		if (ziel != -998)cout << "错误\n";
		cin >> ziel;
		for (int i = 0;i < Enum;i++) {
			if (ziel == ename[i]) { exista = 1; pos1 = i; break; }
		}
	}
	massq = ct[pos1] * Ar[ziel];
	res = massq / Mr*100;
	cout << Pdtable[ziel] << "在";
	for (int j = 0;j < Enum;j++) {
		cout << Pdtable[ename[j]];
		if (ct[j] != 1)cout << ct[j];
	}
	cout << "(相对分子质量" << Mr << ")中的质量分数为" << res << "%" << endl;
}
int main() {
	do {
		cout << "计算相对分子质量输入0,计算元素质量分数输入1,输入-1或非数字退出" << endl;
		cin >> Brh;
	} while (Brh != -1 && Brh != 1&&Brh!=0);
	if (Brh == -1)return 0;
	if (Brh == 0)Mrc(1);
	if (Brh == 1)Bfc();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
