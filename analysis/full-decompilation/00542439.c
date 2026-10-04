
void __fastcall FUN_00542439(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  param_1 = param_1 + 100;
  do {
    FUN_005a5631(iVar1 + 0x1658,param_1,4);
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 4;
  } while (iVar1 < 6);
  return;
}

