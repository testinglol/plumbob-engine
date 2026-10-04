
int __thiscall FUN_0054c9d3(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0054cd13(param_2 + -0x14);
  if ((iVar1 < 0) || (9 < iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14c + iVar1 * 4) + 0x194;
  }
  return iVar1;
}

