
int FUN_00439631(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    FUN_00439520(param_3,param_1);
    param_3 = param_3 + 0x10;
  }
  return param_3;
}

