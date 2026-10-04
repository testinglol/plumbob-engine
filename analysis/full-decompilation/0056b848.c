
int __thiscall FUN_0056b848(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0056bb88(param_2 + -0x27);
  if ((iVar1 < 0) || (8 < iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x154 + iVar1 * 4) + 0x194;
  }
  return iVar1;
}

