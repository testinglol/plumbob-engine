
undefined4 * FUN_004c8ec9(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  iVar1 = FUN_004c8f7a(param_2);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x20) < 999) {
      puVar2 = (undefined4 *)FUN_004c1ba2(param_3);
      *param_1 = *puVar2;
      param_1[1] = puVar2[1];
      return param_1;
    }
    if (999 < *(int *)(iVar1 + 0x20)) {
      puVar3 = (undefined2 *)
               (*(int *)(*(int *)(iVar1 + 0xc) + 0xc + param_3 * 4) + *(int *)(iVar1 + 0xc));
      local_8 = CONCAT22(*puVar3,puVar3[1]);
      *param_1 = 0;
      goto LAB_004c8f51;
    }
  }
  _memset(&local_14,0,8);
  *param_1 = local_14;
  local_8 = local_10;
LAB_004c8f51:
  param_1[1] = local_8;
  return param_1;
}

