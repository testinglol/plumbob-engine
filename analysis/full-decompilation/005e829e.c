
undefined4 * __thiscall FUN_005e829e(int *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *local_c;
  int *piStack_8;
  
  iVar1 = *param_1;
  iVar3 = param_3;
  local_c = param_1;
  piStack_8 = param_1;
  if (param_3 == *(int *)(iVar1 + 8)) {
    if ((param_1[1] == 0) || (*(int *)(param_3 + 0x10) <= *param_4)) goto LAB_005e8320;
LAB_005e82c4:
    FUN_006031c1(param_2,param_3,iVar3,param_4);
  }
  else {
    if (param_3 == iVar1) {
      iVar3 = *(int *)(iVar1 + 0xc);
      if (*(int *)(iVar3 + 0x10) < *param_4) {
LAB_005e8318:
        param_3 = 0;
        goto LAB_005e82c4;
      }
    }
    else {
      FUN_0042a392();
      if ((*(int *)(param_3 + 0x10) < *param_4) && (*param_4 < *(int *)(param_3 + 0x10))) {
        if (*(int *)(param_3 + 0xc) != 0) goto LAB_005e82c4;
        goto LAB_005e8318;
      }
    }
LAB_005e8320:
    puVar2 = (undefined4 *)FUN_004c662a(&local_c,param_4);
    *param_2 = *puVar2;
  }
  return param_2;
}

