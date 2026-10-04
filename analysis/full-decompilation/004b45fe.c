
void __thiscall FUN_004b45fe(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != param_2) {
    for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}

