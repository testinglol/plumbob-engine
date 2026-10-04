
void __thiscall FUN_005f36c3(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x130);
  iVar2 = *(int *)(param_1 + 300) + iVar1 * param_2;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  else if ((*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) - iVar1 < iVar2) {
    iVar2 = (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) - iVar1;
  }
  FUN_005f358e(iVar1 * param_2,param_3);
  FUN_005f398c(iVar2);
  return;
}

