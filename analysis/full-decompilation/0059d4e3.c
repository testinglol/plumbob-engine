
void FUN_0059d4e3(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = param_1 + 5;
    do {
      *param_1 = *param_3;
      puVar1[-4] = param_3[1];
      puVar1[-3] = param_3[2];
      puVar1[-2] = param_3[3];
      puVar1[-1] = param_3[4];
      *puVar1 = param_3[5];
      param_1 = param_1 + 6;
      puVar1 = puVar1 + 6;
    } while (param_1 != param_2);
  }
  return;
}

