
int FUN_005cbd7d(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x2f0) {
    if (param_3 != 0) {
      FUN_005cb7ff(param_1);
    }
    param_3 = param_3 + 0x2f0;
  }
  return param_3;
}

