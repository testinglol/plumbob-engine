
undefined4 * __thiscall FUN_00602a7d(int *param_1,undefined4 *param_2,int param_3,uint *param_4)

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
    if ((param_1[1] == 0) || (*(uint *)(param_3 + 0x10) <= *param_4)) goto LAB_00602aff;
LAB_00602aa3:
    FUN_00602c94(param_2,param_3,iVar3,param_4);
  }
  else {
    if (param_3 == iVar1) {
      iVar3 = *(int *)(iVar1 + 0xc);
      if (*(uint *)(iVar3 + 0x10) < *param_4) {
LAB_00602af7:
        param_3 = 0;
        goto LAB_00602aa3;
      }
    }
    else {
      FUN_0042a392();
      if ((*(uint *)(param_3 + 0x10) < *param_4) && (*param_4 < *(uint *)(param_3 + 0x10))) {
        if (*(int *)(param_3 + 0xc) != 0) goto LAB_00602aa3;
        goto LAB_00602af7;
      }
    }
LAB_00602aff:
    puVar2 = (undefined4 *)FUN_00602b14(&local_c,param_4);
    *param_2 = *puVar2;
  }
  return param_2;
}

