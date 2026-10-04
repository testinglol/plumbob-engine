
int FUN_00638af3(int param_1)

{
  bool bVar1;
  
  if (DAT_00703bec == 0) {
    if ((0x60 < param_1) && (param_1 < 0x7b)) {
      return param_1 + -0x20;
    }
  }
  else {
    InterlockedIncrement(&DAT_00705360);
    bVar1 = DAT_0070535c != 0;
    if (bVar1) {
      InterlockedDecrement(&DAT_00705360);
      FUN_0063d88b(0x13);
    }
    param_1 = FUN_00638b62(param_1);
    if (bVar1) {
      FUN_0063d8ec(0x13);
    }
    else {
      InterlockedDecrement(&DAT_00705360);
    }
  }
  return param_1;
}

