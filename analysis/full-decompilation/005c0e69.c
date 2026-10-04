
void FUN_005c0e69(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_14 = *param_2;
  uStack_10 = param_2[1];
  uStack_c = param_2[2];
  local_8 = param_2[3];
  if (local_8 < (uint)param_1[3]) {
    puVar2 = param_2 + 4;
    iVar1 = (int)param_2 - (int)param_1 >> 4;
    if (0 < iVar1) {
      do {
        puVar2[-4] = param_2[-4];
        puVar2[-3] = param_2[-3];
        puVar2[-2] = param_2[-2];
        iVar1 = iVar1 + -1;
        puVar2[-1] = param_2[-1];
        puVar2 = puVar2 + -4;
        param_2 = param_2 + -4;
      } while (iVar1 != 0);
    }
  }
  else {
    local_14 = *param_2;
    uStack_10 = param_2[1];
    uStack_c = param_2[2];
    local_8 = param_2[3];
    param_1 = param_2;
    while (local_8 < (uint)param_1[-1]) {
      *param_1 = param_1[-4];
      param_1[1] = param_1[-3];
      param_1[2] = param_1[-2];
      param_1[3] = param_1[-1];
      param_1 = param_1 + -4;
    }
  }
  *param_1 = local_14;
  param_1[1] = uStack_10;
  param_1[2] = uStack_c;
  param_1[3] = local_8;
  return;
}

