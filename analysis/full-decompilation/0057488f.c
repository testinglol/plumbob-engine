
uint FUN_0057488f(undefined4 param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_34 [2];
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_18 [2];
  int local_10;
  int local_c;
  int local_8;
  
  FUN_005763bc(local_34,&param_1);
  local_1c = local_2c;
  local_18[0] = local_28;
  if (local_34[0] == local_2c) {
    *param_2 = 0;
    *param_3 = 0x200;
    piVar2 = param_3;
  }
  else {
    local_10 = FUN_00573466(param_1);
    iVar3 = local_1c;
    piVar1 = param_3;
    piVar2 = (int *)0x0;
    if (local_10 != 0) {
      local_c = 0;
      *param_3 = 0;
      local_8 = 0;
      param_3 = (int *)0x0;
      local_24 = local_34[0];
      while (local_24 != iVar3) {
        FUN_0057320a(*(undefined4 *)(local_24 + 8),local_18,piVar1,local_10);
        if (local_c < local_18[0]) {
          local_c = local_18[0];
        }
        param_3 = (int *)((int)param_3 + local_18[0]);
        local_8 = local_8 + (*piVar1 + -0x200) * local_18[0];
        FUN_00576e56();
      }
      iVar3 = 0;
      if (param_3 != (int *)0x0) {
        iVar3 = local_8 / (int)param_3;
      }
      *param_2 = local_c;
      *piVar1 = iVar3 + 0x200;
      return CONCAT31((int3)((uint)(iVar3 + 0x200) >> 8),1);
    }
  }
  return (uint)piVar2 & 0xffffff00;
}

