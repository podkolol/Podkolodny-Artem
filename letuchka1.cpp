#include <iostream>
using namespace std;
int getIntLen(int num) {
  int length = 0;
  while (num > 0) {
    num = num / 16;
    length = length + 1;
  }
  return length;
}

char *intTohex(int num) {
  bool is_negative = (num < 0) ? true : false;
  int total_length;

  if (is_negative) {
    total_length = getIntLen(num) + 3;
  } else {
    total_length = getIntLen(num) + 2;
  }

  char *result = new char[total_length + 1];
  result[total_length + 1] = 0;

  int i;
  if (is_negative) {
    num = num * (-1);
    result[0] = '-';
    result[1] = '0';
    result[2] = 'x';
    i = getIntLen(num) + 2;
  } else {
    result[0] = '0';
    result[1] = 'x';
    i = getIntLen(num) + 1;
  }

  while (num > 0) {
    int ost = num % 16;
    char res;

    if (ost > 9) {
      res = char(64 + (ost - 9));
    } else {
      res = char(48 + ost);
    }

    result[i] = res;
    num = num / 16;
    i = i - 1;
  }

  return result;
}

int main(){
    int n;
    cin >>n;
    cout << intTohex(n)<< endl;
}