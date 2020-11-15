#include<iostream>
#include<string>
#include<fstream>    // contains file stream processing types
#include<cstdlib>   // exit function prototype
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>

using namespace std;

class R
{
   public:
       R(vector<string> strs)
       {
           if(strs.size() == 4)
           {
                funct = strs[0];
                rd = strs[1];
                rs = strs[2];
                rt = strs[3];
           }
           else if(strs.size() == 2)
           {
                rt = "00000";
                rd = "00000";
                rs = strs[1];
                funct = strs[0];

           }

       }


       void toString()
       {
           string add;
           add = (opcode + rs + rt + rd + shamt + funct );

           cout << add << endl;
       }

       void setop()
       {
           opcode = "000000";
       }


        ~R()
       {

       }
    private:
        string opcode;
        string rs;
        string rt;
        string rd;
        string shamt;
        string funct;

};

class I
{

};

class J
{

};


bool containsStr(string w, vector<string> instr );

int main()
{

map<string, string> regAddress;
regAddress["$at"] = "00001";
regAddress["$zero"] = "00000";
regAddress["$v0"] = "00010";
regAddress["$v1"] = "00011";
regAddress["$a0"] = "00100";
regAddress["$a1"] = "00101";
regAddress["$a2"] = "00110";
regAddress["$a3"] = "00111";
regAddress["$t0"] = "01000";
regAddress["$t1"] = "01001";
regAddress["$t2"] = "01010";
regAddress["$t3"] = "01011";
regAddress["$t4"] = "01100";
regAddress["$t5"] = "01101";
regAddress["$t6"] = "01110";
regAddress["$t7"] = "01111";
regAddress["$s0"] = "10000";
regAddress["$s1"] = "10001";
regAddress["$s2"] = "10010";
regAddress["$s3"] = "10011";
regAddress["$s4"] = "10100";
regAddress["$s5"] = "10101";
regAddress["$s6"] = "10110";
regAddress["$s7"] = "10111";
regAddress["$t8"] = "11000";
regAddress["$t9"] = "11001";
regAddress["$k0"] = "11010";
regAddress["$k1"] = "11011";
regAddress["$gp"] = "11100";
regAddress["$sp"] = "11101";
regAddress["$fp"] = "11110";
regAddress["$ra"] = "11111";

map<string,vector<string> > formatTable;
formatTable["add"]  = {"R", "0", "100000"};
formatTable["addu"] = {"R", "0", "100001"};
formatTable["sub"] = {"R", "0", "100010"};
formatTable["subu"] = {"R", "0", "100011"};
formatTable["and"] = {"R", "0", "100100"};
formatTable["or"] = {"R", "0", "100101"};
formatTable["nor"] = {"R", "0", "100111"};
formatTable["slt"] = {"R", "0", "101010"};
formatTable["sltu"] = {"R", "0", "101011"};
formatTable["sll"] = {"R", "0", "0000000"};
formatTable["srl"] = {"R", "0", "000010"};
formatTable["jr"] = {"R", "0", "001000"};

formatTable["beq"] = {"I", "4", ""};
formatTable["bne"] = {"I", "5", ""};
formatTable["addi"] = {"I", "8", ""};
formatTable["addiu"] = {"I", "9", ""};
formatTable["andi"] = {"I", "12", ""};
formatTable["ori"] = {"I", "13", ""};
formatTable["slti"] = {"I", "10", ""};
formatTable["sltiu"] = {"I", "11", ""};
formatTable["lui"] = {"I", "15", ""};
formatTable["lw"] = {"I", "35", ""};
formatTable["sw"] = {"I", "45", ""};

formatTable["j"] = {"J", "2", ""};
formatTable["jal"] = {"J", "3", ""};

    fstream newfile1, newfile2;
    newfile1.open("prog2bin.txt", ios::out);
    newfile1.open("test.txt", ios::in);

    if( newfile1.is_open())
    {
        string line;
        string word;
        vector<string> inst;
        while(getline(newfile1,line))
        {

            int i = 0;
            while( line.at(i) != '\n')
            {
                char c = line.at(i);

                if( (c == ' ') || (c == ',') )
                {
                    if( c == '#' || c == '.' || c == ':')
                        continue;

                    if(! word.empty() & !containsStr(word,inst))
                    {
                        inst.push_back(word);
                    }
                    word = "";
                }

                 word.push_back(c);

                i++;
            }

            vector<string> format = formatTable.at(inst[0]);

            string  f;
            string des;
            string s1;
            string s2;

            vector<string> Rinst;

            if(format[0] == "R")
            {
                f = format[2];
                des = regAddress[inst[1]];
                s1  = regAddress[inst[2]];
                s2  = regAddress[inst[3]];

                Rinst.push_back(f);
                Rinst.push_back(des);
                Rinst.push_back(s1);
                Rinst.push_back(s2);

                R objR(Rinst);

                objR.toString();
            }

        }

    }
    else
    {
        cout << "Can't open file " << endl;
    }

    newfile1.close();
    newfile2.close();

    return 0;
}

bool containsStr(string w, vector<string> instr )
{
    vector<string>::iterator it  = instr.begin();

    while(it != instr.end() )
    {
        if( (*it).compare(w) == 0)
        {
            return true;
        }
    }

    return false;
}


int binarytodecimal(string n)
{
    string num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

string decimaltobinary()
{

}

string binarytoHexa(string n)
{

}

string HexatoBinary(string in)
{

}

