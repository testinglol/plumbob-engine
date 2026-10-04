
void __thiscall FUN_00436a50(int *param_1,int param_2)

{
  int iStack_4;
  
  *param_1 = param_2;
  if (param_2 == 2) {
    iStack_4 = 4;
  }
  else if (param_2 == 3) {
    iStack_4 = 8;
  }
  else if ((param_2 < 4) || ((8 < param_2 && (param_2 != 10)))) {
    iStack_4 = 0;
  }
  else {
    iStack_4 = 0x10;
  }
  param_1[1] = iStack_4;
  return;
}

