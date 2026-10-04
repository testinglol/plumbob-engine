
undefined4 __thiscall FUN_005ed80b(int param_1,int param_2,int param_3)

{
  void *pvVar1;
  
  *(int *)(param_1 + 8) = param_2;
  FUN_006321f0(*(undefined4 *)(param_1 + 0x10));
  pvVar1 = operator_new((int)(((param_2 - 1U | 1) + 1) * param_3) / 8);
  *(int *)(param_1 + 0xc) = param_3;
  *(void **)(param_1 + 0x10) = pvVar1;
  return 1;
}

