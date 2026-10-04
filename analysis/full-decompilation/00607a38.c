
undefined4 __thiscall FUN_00607a38(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0) {
    iVar1 = (**(code **)*param_2)(param_2,&DAT_00677228,param_1);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1,&DAT_006d9328,0,&param_2);
      if (iVar1 == 0) {
        if (((byte)param_2 & 2 | 1) == 3) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        iVar1 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1,&DAT_006d9348,1,&param_2);
        if ((iVar1 == 0) && (((byte)param_2 & 2 | 1) == 3)) {
          *(undefined1 *)((int)param_1 + 5) = 1;
          goto LAB_00607ab2;
        }
      }
      (**(code **)(*(int *)*param_1 + 8))((int *)*param_1);
    }
    *param_1 = 0;
    uVar2 = 0;
  }
  else {
LAB_00607ab2:
    uVar2 = 1;
  }
  return uVar2;
}

