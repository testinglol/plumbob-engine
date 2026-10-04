
int FUN_00435221(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (param_1 & 1) == 0; param_1 = (int)param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  if (param_2 != 1) {
    if (param_2 == 3) {
      return iVar1 + 2;
    }
    if (param_2 != 4) {
      return iVar1;
    }
  }
  return iVar1 + 1;
}

