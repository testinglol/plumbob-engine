
void __thiscall FUN_005e4104(int param_1,int param_2)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0x17c) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x17c));
    *(undefined4 *)(param_1 + 0x17c) = 0;
  }
  if (param_2 != 0) {
    pvVar1 = operator_new(*(int *)(param_1 + 0xf0) << 3);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    *(void **)(param_1 + 0x17c) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      FUN_00636510(pvVar1,param_2,*(int *)(param_1 + 0xf0) << 3);
    }
  }
  return;
}

