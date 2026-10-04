
void __thiscall FUN_00448887(int *param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < (uint)(param_1[1] - *param_1 >> 2)) {
    FUN_00448aa5(*param_1 + param_2 * 4,param_1[1]);
  }
  else {
    FUN_00448eb2(param_1[1],param_2 - (param_1[1] - *param_1 >> 2),param_3);
  }
  return;
}

