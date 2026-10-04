
void __fastcall FUN_005f53ae(int *param_1)

{
  param_1[0x3e] = -1;
  while ((param_1[0x36] - param_1[0x35] & 0xfffffffcU) != 0) {
    FUN_005f53e2(0);
  }
  (**(code **)(*param_1 + 0x168))();
  return;
}

