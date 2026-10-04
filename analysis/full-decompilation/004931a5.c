
undefined4 __fastcall FUN_004931a5(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  while( true ) {
    if (iVar2 == *(int *)(param_1 + 0x1c)) {
      return 0;
    }
    iVar1 = FUN_00493210();
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 4;
  }
  return 1;
}

