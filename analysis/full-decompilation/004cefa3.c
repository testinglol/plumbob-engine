
void __thiscall FUN_004cefa3(int param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    param_2 = 1;
  }
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 1;
  *(int *)(param_1 + 0x3c) = param_2;
  if (param_3 == 0) {
    FUN_004a82db(param_2,0);
  }
  FUN_004cefd8();
  return;
}

