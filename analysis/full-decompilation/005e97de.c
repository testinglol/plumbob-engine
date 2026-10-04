
void __fastcall FUN_005e97de(int *param_1)

{
  if ((char)param_1[0x3a] != '\0') {
    FUN_005dae65(param_1);
    *(undefined1 *)(param_1 + 0x3a) = 0;
  }
  if (param_1[0x38] < 1) {
    if ((param_1[0x38] < 0) && (param_1[0x39] == 0)) {
      param_1[0x38] = 1;
    }
  }
  else if (param_1[0x39] == param_1[0x36] + -1) {
    param_1[0x38] = -1;
  }
  param_1[0x39] = param_1[0x39] + param_1[0x38];
  (**(code **)(*param_1 + 0x168))();
  FUN_005e98c3();
  return;
}

