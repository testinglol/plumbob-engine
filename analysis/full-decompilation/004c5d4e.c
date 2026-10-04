
undefined4 __thiscall FUN_004c5d4e(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 8);
  while( true ) {
    if (iVar2 == iVar1) {
      return 0xffff;
    }
    if ((**(int **)(iVar2 + 0x14) == param_2) && ((*(int **)(iVar2 + 0x14))[1] == param_3)) break;
    FUN_0041674f();
  }
  return *(undefined4 *)(iVar2 + 0x10);
}

