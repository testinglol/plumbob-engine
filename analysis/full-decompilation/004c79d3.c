
void FUN_004c79d3(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_24 [16];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0x7fffffff;
  local_10 = 0x7fffffff;
  local_c = 0x80000000;
  local_8 = 0x80000000;
  iVar1 = FUN_004c8f7a(param_2);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_004c1bfd(local_24,param_3,param_4,param_5,param_6,param_7,1,0);
    local_14 = *puVar2;
    local_10 = puVar2[1];
    local_c = puVar2[2];
    local_8 = puVar2[3];
  }
  *param_1 = local_14;
  param_1[1] = local_10;
  param_1[2] = local_c;
  param_1[3] = local_8;
  return;
}

