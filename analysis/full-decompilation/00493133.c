
undefined4 __fastcall FUN_00493133(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  do {
    if (iVar2 == *(int *)(param_1 + 0xc)) {
      return 0;
    }
    iVar2 = iVar2 + -4;
    iVar1 = FUN_004931e7();
  } while (iVar1 == 0);
  return 1;
}

