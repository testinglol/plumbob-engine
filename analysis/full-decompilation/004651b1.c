
void __thiscall FUN_004651b1(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  
  for (piVar1 = (int *)*param_1;
      (piVar1 != (int *)param_1[1] && (*(int *)(*piVar1 + 0xc) != param_2)); piVar1 = piVar1 + 1) {
  }
  *(undefined4 *)(*(int *)*piVar1 + param_3 * 4) = param_4;
  return;
}

