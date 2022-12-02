#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

//1. Read the companies’ information from a given file :
struct Company
{
	string name;
	string tax_code;
	string address;
};

Company readOneLine(string line_info)
{
	Company Comp;
	stringstream ss(line_info);
	getline(ss, Comp.name, '|');
	getline(ss, Comp.tax_code, '|');
	getline(ss, Comp.address);
	return Comp;
}

vector<Company> ReadCompanyList(string file_name)
{
	vector<Company> Comp_s;
	ifstream fin(file_name, ios::in);
	if (!fin)
	{
		cout << "Mo file khong thanh cong" << endl;
		return Comp_s;
	}
	cout << "Mo file thanh cong" << endl;

	string line_info;
	// Doc dong dau
	getline(fin, line_info);

	while (!fin.eof())
	{
		getline(fin, line_info);
		Comp_s.push_back(readOneLine(line_info));
	}

	fin.close();
	return Comp_s;
}

void printOneCompany(Company Comp)
{
	cout << Comp.name << "|" << Comp.tax_code << "|" << Comp.address;
}

void printListCompany(vector<Company> Comp_s)
{
	for (int i = 0; i < Comp_s.size(); i++)
	{
		printOneCompany(Comp_s[i]);
		cout << endl;
	}
}

//2. Hash a string (company name) function:
long long HashString(string company_name)
{
	int p = 31;
	long long m = pow(10, 9) + 9;
	int len = company_name.length();
	string s;
	if (len <= 20)
		s = company_name;
	else
		s = company_name.substr(len - 20, 20);

	long long sum = 0;
	for (int i = 0; i < s.length() - 1; i++)
	{
		int j = 0;
		if (i > 10) j = i - 10;
		long long a = (int)s[i] % m;
		int b = (pow(p, i)) % m
		sum = sum +
	}
}

//3. Kiem tra mang day chua, key cuoi cung


int main()
{
	vector<Company> Comp_s = ReadCompanyList("data.txt");
	printListCompany(Comp_s);
}