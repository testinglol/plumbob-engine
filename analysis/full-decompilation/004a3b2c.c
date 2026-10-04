
char __thiscall FUN_004a3b2c(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  if (param_2 == 0) {
    bVar2 = *param_1;
    cVar3 = (bVar2 >> 4 & 1) * '\x02' - ((char)bVar2 >> 7);
  }
  else if (param_2 == 1) {
    bVar1 = *param_1;
    bVar2 = bVar1 >> 1;
    cVar3 = (bVar1 >> 5 & 1) + (bVar1 >> 4 & 1) * '\x02';
  }
  else if (param_2 == 2) {
    bVar1 = *param_1;
    bVar2 = bVar1 >> 2;
    cVar3 = (bVar1 >> 6 & 1) + (bVar1 >> 5 & 1) * '\x02';
  }
  else {
    if (param_2 != 3) {
      return '\0';
    }
    bVar1 = *param_1;
    bVar2 = bVar1 >> 3;
    cVar3 = (bVar1 >> 6 & 1) + ((char)bVar1 >> 7) * -2;
  }
  return (bVar2 & 1) + cVar3 * '\x02';
}

