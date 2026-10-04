
void __thiscall FUN_005e40ac(int param_1,int param_2)

{
  void *pvVar1;
  
  FUN_006321f0(*(undefined4 *)(param_1 + 0x178));
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x178) = 0;
  }
  else {
    pvVar1 = operator_new(*(int *)(param_1 + 0xf0) << 2);
    *(void **)(param_1 + 0x178) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      FUN_00636510(pvVar1,param_2,*(int *)(param_1 + 0xf0) << 2);
    }
  }
  return;
}

