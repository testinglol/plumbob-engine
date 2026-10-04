
void __thiscall FUN_005e4817(int param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  size_t sVar1;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0x180) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x180));
    *(undefined4 *)(param_1 + 0x180) = 0;
  }
  if (*(int *)(param_1 + 0x184) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x184));
    *(undefined4 *)(param_1 + 0x184) = 0;
  }
  if (*(int *)(param_1 + 0x188) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x188));
    *(undefined4 *)(param_1 + 0x188) = 0;
  }
  if (*(int *)(param_1 + 0x18c) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x18c));
    *(undefined4 *)(param_1 + 0x18c) = 0;
  }
  if (param_2 != (char *)0x0) {
    sVar1 = _strlen(param_2);
    pvVar2 = operator_new(sVar1 + 1);
    *(void **)(param_1 + 0x180) = pvVar2;
    FUN_006358b0(pvVar2,param_2);
  }
  if (param_3 != (char *)0x0) {
    sVar1 = _strlen(param_3);
    pvVar2 = operator_new(sVar1 + 1);
    *(void **)(param_1 + 0x184) = pvVar2;
    FUN_006358b0(pvVar2,param_3);
  }
  if (param_4 != (char *)0x0) {
    sVar1 = _strlen(param_4);
    pvVar2 = operator_new(sVar1 + 1);
    *(void **)(param_1 + 0x188) = pvVar2;
    FUN_006358b0(pvVar2,param_4);
  }
  if (param_5 != (char *)0x0) {
    sVar1 = _strlen(param_5);
    pvVar2 = operator_new(sVar1 + 1);
    *(void **)(param_1 + 0x18c) = pvVar2;
    FUN_006358b0(pvVar2,param_5);
  }
  return;
}

