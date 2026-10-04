
void __thiscall FUN_005805ba(int param_1,int param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    if ((param_2 < iVar1) || (*(int *)(param_1 + 4) + -1 + iVar1 < param_2)) {
      iVar1 = FUN_005805ba(param_2);
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0xc) + (param_2 - iVar1) * 4);
    }
    if (iVar1 != -0x80000000) break;
    param_1 = *(int *)(param_1 + 0x14);
  }
  return;
}

