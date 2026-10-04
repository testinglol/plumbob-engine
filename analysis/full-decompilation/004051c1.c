
int FUN_004051c1(int param_1)

{
  int iVar1;
  
  if (param_1 == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004ea79e(param_1);
    iVar1 = (int)*(short *)(iVar1 + 0xa2);
  }
  return iVar1;
}

