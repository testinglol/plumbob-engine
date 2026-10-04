
int __thiscall FUN_00416e82(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 0x50;
  if (iVar2 != *(int *)(param_1 + 4)) {
    do {
      iVar1 = FUN_0046f973(param_2 + 4);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 0x50;
    } while (iVar2 != *(int *)(param_1 + 4));
  }
  return 0;
}

