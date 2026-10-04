
int FUN_004e988f(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_006f2648;
  while( true ) {
    if (piVar1 == DAT_006f264c) {
      return -1;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 0x11;
  }
  return ((int)piVar1 - (int)DAT_006f2648) / 0x44;
}

