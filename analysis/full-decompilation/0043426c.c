
void __thiscall FUN_0043426c(int param_1,undefined4 param_2,int param_3)

{
  FUN_00464a5e(param_1 + 0x108,1);
  FUN_00464a5e(param_1 + 0x10c,1);
  FUN_00464a5e(param_1 + 0x100,1);
  FUN_00464a5e(param_1 + 0x104,1);
  FUN_00464a5e(param_1 + 0xf8,1);
  FUN_00464a5e(param_1 + 0xf4,1);
  *(char *)(param_1 + 0xfc) = (char)(*(int *)(param_1 + 0xf8) >> 4);
  *(char *)(param_1 + 0xfd) = (char)(*(int *)(param_1 + 0xf4) >> 4);
  if (0x18 < param_3) {
    FUN_00464a4e(param_1 + 0x110,1);
    *(char *)(param_1 + 0xfe) = (char)*(undefined4 *)(param_1 + 0x110);
  }
  if (param_3 < 0x2f) {
    FUN_00464973(param_1 + 0xf0,1);
  }
  param_2 = 1;
  FUN_00464973(&param_2,1);
  if (param_3 == 0x37) {
    FUN_00464a4e(param_1 + 0x114,1);
  }
  return;
}

