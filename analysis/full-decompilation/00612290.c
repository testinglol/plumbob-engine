
void FUN_00612290(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  if (-1 < param_2) {
    if (((param_2 < *(int *)(*param_1 + 0x10)) && (-1 < param_3)) &&
       (param_3 < *(int *)(*param_1 + 0x14))) {
      *(undefined4 *)(param_1[2] * param_3 + param_1[1] + param_2 * 4) = param_4;
    }
  }
  return;
}

