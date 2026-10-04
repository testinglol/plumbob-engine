
int FUN_00583543(byte *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    iVar1 = iVar1 * 0x100 + (uint)*param_1;
    param_1 = param_1 + 1;
  }
  return iVar1;
}

