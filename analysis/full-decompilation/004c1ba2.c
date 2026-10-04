
int __thiscall FUN_004c1ba2(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) == 0) ||
     (iVar1 = *(int *)(*(int *)(param_1 + 0xc) + param_2 * 4), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

