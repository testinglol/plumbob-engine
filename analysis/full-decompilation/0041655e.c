
void __thiscall FUN_0041655e(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (0x12 < param_3) {
    FUN_00464c84(param_1 + 0x28);
  }
  if (param_3 < 0x26) {
    if (*(int *)(param_2 + 0xc) == 0) {
      FUN_004165e9();
    }
  }
  else {
    iVar1 = param_1 + 0x38;
    param_3 = 5;
    do {
      FUN_00464a5e(iVar1 + 4,1);
      FUN_00464a5e(iVar1,1);
      iVar1 = iVar1 + 8;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    FUN_00464a5e(param_1 + 100,1);
    FUN_00464a5e(param_1 + 0x60,1);
  }
  return;
}

