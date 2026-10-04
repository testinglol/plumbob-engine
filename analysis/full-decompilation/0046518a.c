
undefined4 __thiscall FUN_0046518a(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  
  for (piVar1 = (int *)*param_1;
      (piVar1 != (int *)param_1[1] && (*(int *)(*piVar1 + 0xc) != param_2)); piVar1 = piVar1 + 1) {
  }
  return *(undefined4 *)(*(int *)*piVar1 + param_3 * 4);
}

