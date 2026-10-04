
undefined4 * __thiscall FUN_004e89a7(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    *param_1 = *param_2;
    FUN_005a5e72();
    FUN_005a5e1c(param_2 + 1);
    uVar1 = param_2[3];
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_2 + 2);
    *(undefined1 *)((int)param_1 + 9) = *(undefined1 *)((int)param_2 + 9);
    param_1[3] = uVar1;
    uVar1 = FUN_0041f169();
    FUN_005d499c(uVar1);
  }
  return param_1;
}

