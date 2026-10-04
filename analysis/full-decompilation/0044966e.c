
undefined4 * __thiscall FUN_0044966e(int *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  undefined4 *puVar1;
  undefined1 local_30 [16];
  undefined1 local_20 [12];
  undefined1 local_14 [12];
  int local_8;
  
  if (param_3 == *(int *)(*param_1 + 8)) {
    if ((param_1[1] == 0) || (*(int *)(param_3 + 0x10) <= *param_4)) {
      puVar1 = (undefined4 *)FUN_00449f7d(local_14,param_4);
      *param_2 = *puVar1;
    }
    else {
      FUN_00449e79(param_2,param_3,param_3,param_4);
    }
  }
  else if (param_3 == *param_1) {
    if (*(int *)(*(int *)(*param_1 + 0xc) + 0x10) < *param_4) {
      FUN_00449e79(param_2,0,*(undefined4 *)(*param_1 + 0xc),param_4);
    }
    else {
      puVar1 = (undefined4 *)FUN_00449f7d(local_20,param_4);
      *param_2 = *puVar1;
    }
  }
  else {
    local_8 = param_3;
    FUN_0042a392();
    if ((*(int *)(local_8 + 0x10) < *param_4) && (*param_4 < *(int *)(param_3 + 0x10))) {
      if (*(int *)(local_8 + 0xc) == 0) {
        FUN_00449e79(param_2,0,local_8,param_4);
      }
      else {
        FUN_00449e79(param_2,param_3,param_3,param_4);
      }
    }
    else {
      puVar1 = (undefined4 *)FUN_00449f7d(local_30,param_4);
      *param_2 = *puVar1;
    }
  }
  return param_2;
}

