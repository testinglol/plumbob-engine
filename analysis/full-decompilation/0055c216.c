
int __thiscall FUN_0055c216(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x148);
  iVar2 = *(int *)(iVar1 + 8);
  while( true ) {
    if (iVar2 == iVar1) {
      return 0;
    }
    if (*(int *)(*(int *)(iVar2 + 0x14) + 0x1d8) == param_2) break;
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 0x148);
  }
  if (*(int *)(iVar2 + 0x14) == 0) {
    return 0;
  }
  return *(int *)(iVar2 + 0x14) + 0x194;
}

