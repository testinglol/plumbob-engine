
undefined1 __fastcall FUN_004e8aba(int param_1)

{
  int iVar1;
  
  param_1 = param_1 + 0xc;
  iVar1 = 7;
  do {
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_005a5e48(0);
    param_1 = param_1 + 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 1;
}

