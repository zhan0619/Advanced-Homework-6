#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(void){
    
    string num;
    int id_change[26] = {10,11,12,13,14,15,16,17,34,18,19,20,
    21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    int all[8] = {0,0,0,0,0,0,0,0};
    int end_all = 0;
    int first = 0;
    
    cout << "請輸入身分證號碼" << endl;
    cin >> num;
    
    if((int)num[0] >= 97 && (int)num[0] <= 122){
          (int)num[0]-32;               
    }
    
    first = ((id_change[(int)(num[0]-65)] % 10) * 9) + 
    (((id_change[(int)(num[0]-65)]) - (id_change[(int)(num[0]-65)] % 10)) / 10);
    
    all[7] = ((int)num[8] - 48);
    all[6] = ((int)num[7] - 48)* 2;
    all[5] = ((int)num[6] - 48)* 3;
    all[4] = ((int)num[5] - 48)* 4;
    all[3] = ((int)num[4] - 48)* 5;
    all[2] = ((int)num[3] - 48)* 6;
    all[1] = ((int)num[2] - 48)* 7;
    all[0] = ((int)num[1] - 48)* 8;
    
    end_all = (first + all[7] + all[6] + all[5] + all[4] + 
    all[3] + all[2] + all[1] + all[0]) % 10;
    
    if(end_all == 0){
               end_all = 0;
    }else{
               end_all = 10 - ((first + all[7] + all[6] + all[5] + all[4] + 
               all[3] + all[2] + all[1] + all[0]) % 10);
    }
    
    if(end_all == (int)num[9] - 48){
               cout << "這是合法的身分證號碼" << endl;
    }else{
               cout << "這不是合法的身分證號碼" << endl;
    }

    system("pause");
    return 0;
}
