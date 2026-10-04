
void FUN_00576b0a(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  while (param_1 != param_2) {
    param_1 = (undefined4 *)*param_1;
    *param_3 = *param_3 + 1;
  }
  return;
}

