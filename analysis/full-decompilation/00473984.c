
void __thiscall FUN_00473984(int param_1,undefined4 param_2,int param_3)

{
  FUN_00464a4e(param_1 + 4,1);
  FUN_00464a4e(param_1 + 8,1);
  FUN_00464c84(param_1 + 0x18);
  FUN_00464c84(param_1 + 0x24);
  if (param_3 < 1) {
    *(undefined1 *)(param_1 + 0x10) = 0;
    *(undefined2 *)(param_1 + 0x12) = 0;
    *(undefined2 *)(param_1 + 0x14) = 100;
  }
  else {
    FUN_0046494e(param_1 + 0x10);
    FUN_00464973(param_1 + 0x12,1);
    FUN_00464973(param_1 + 0x14,1);
  }
  return;
}

