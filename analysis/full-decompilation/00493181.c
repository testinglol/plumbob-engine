
undefined4 __fastcall FUN_00493181(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  while( true ) {
    if (iVar2 == *(int *)(param_1 + 0x10)) {
      return 0;
    }
    iVar1 = FUN_00493210();
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 4;
  }
  return 1;
}

