
int __thiscall FUN_00632fb8(int param_1,int param_2,int param_3)

{
  if ((*(int *)(param_1 + 0x4c) == -1) || (*(int *)(param_1 + 0x14) == 0)) {
    if ((param_2 == 0) || (param_3 < 1)) {
      *(undefined4 *)(param_1 + 8) = 1;
    }
    else {
      if (*(int *)(param_1 + 0x30) < 0) {
        FUN_00633e5e(param_1 + 0x34);
      }
      FUN_006345ae(param_2,param_2 + param_3,0);
      if (*(int *)(param_1 + 0x30) < 0) {
        FUN_00633e69(param_1 + 0x34);
      }
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

