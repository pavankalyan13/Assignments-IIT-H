#include<iostream>

using namespace std;

bool strcmp(string numberPlate1,string numberPlate2 )
{
     // As we already know the length of the input string is 6
      int len = 6;

      // Looping variable
      int i = 0;

      /************  LOGIC *******************************************************************************************

       loop through all characters using k, if it mets any of the two conditions

      i) character at k of A < character at k of B
          that means A < B. return 1

      we can't do else as there might be chances that both char are equal so,

      ii) character at k of A > character at k of B
           that means A > B. return 0

      ****************************************************************************************************************/
      while(i < len)
      {
        if( (numberPlate1.at(i) < numberPlate2.at(i)) || (numberPlate1.at(i) < numberPlate2.at(i) ) )
        {
            cout << 1 << endl;
            break;
        }
        else if( (numberPlate1.at(i) > numberPlate2.at(i)) || (numberPlate1.at(i) > numberPlate2.at(i) ))
        {
            cout << 0 << endl;
            break;
        }

        i++;
      }

}


int main(){
  string numberPlate[2];
  bool act=0;
  while (cin >> numberPlate[act]){
    act=1-act;
    if(act==0){
      // Call your string compare function here on numberPlate[0] and numberPlate[1].
        strcmp(numberPlate[0], numberPlate[1] );

    }
  }
  return 0;
}
