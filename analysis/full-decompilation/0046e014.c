
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046e014(int param_1,int param_2)

{
  *(int *)(param_1 + 0x14) = param_2;
  if (param_2 == 0) {
    if (*(float *)(param_1 + 8) == _DAT_0066657c) {
      *(undefined4 *)(param_1 + 0x14) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x14) = 5;
    }
  }
  else if (param_2 == 1) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(param_1 + 8) = 0x40200000;
  }
  else {
    if (param_2 != 3) {
      if (param_2 == 4) {
        *(undefined4 *)(param_1 + 8) = 0x4081999a;
        return;
      }
      if (param_2 != 8) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 8) = 0x40800000;
  }
  return;
}

