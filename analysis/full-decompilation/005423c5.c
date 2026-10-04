
void __fastcall FUN_005423c5(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  param_1 = param_1 + 0x24;
  do {
    FUN_005a5631(iVar1 + 0x1645,param_1,4);
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 4;
  } while (iVar1 < 0x10);
  return;
}

