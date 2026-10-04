
void FUN_0060fcb0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  float local_150 [14];
  float local_118 [14];
  float local_e0 [14];
  float local_a8 [14];
  undefined1 local_70 [56];
  undefined1 local_38 [56];
  
  iVar1 = *param_2;
  iVar3 = 0;
  local_164 = 0;
  local_160 = 99999;
  if (0 < iVar1) {
    do {
      iVar2 = __ftol();
      if (iVar2 < local_160) {
        local_164 = iVar3;
        local_160 = iVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  local_158 = 0;
  iVar3 = iVar1;
  if (0 < iVar1) {
    do {
      iVar2 = __ftol();
      if (local_158 < iVar2) {
        local_158 = iVar2;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  local_15c = local_164;
  FUN_00610030(param_2,local_164,local_118);
  FUN_00610030(param_2,local_164 + 1,local_150);
  if (local_150[1] <= local_118[1]) {
    do {
      local_164 = FUN_00610010(local_164,iVar1);
      FUN_00610030(param_2,local_164 + 1,local_150);
    } while (local_150[1] <= local_118[1]);
  }
  FUN_00610030(param_2,local_164,local_150);
  pfVar4 = local_118;
  pfVar5 = local_a8;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  do {
    local_15c = FUN_00610020(local_15c,iVar1);
    FUN_00610030(param_2,local_15c,local_a8);
  } while (local_a8[1] <= local_118[1]);
  pfVar4 = local_150;
  pfVar5 = local_e0;
  for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  do {
    local_164 = FUN_00610010(local_164,iVar1);
    FUN_00610030(param_2,local_164,local_e0);
  } while (local_e0[1] <= local_150[1]);
  FUN_0060eeb0(local_118,local_a8,local_70,local_a8[1] - local_118[1]);
  FUN_0060eeb0(local_150,local_e0,local_38,local_e0[1] - local_150[1]);
  for (; local_160 < local_158; local_160 = local_160 + 1) {
    if (local_a8[1] < (float)local_160) {
      pfVar4 = local_a8;
      pfVar5 = local_118;
      for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar5 = pfVar5 + 1;
      }
      do {
        local_15c = FUN_00610020(local_15c,iVar1);
        FUN_00610030(param_2,local_15c,local_a8);
      } while (local_a8[1] <= local_118[1]);
      FUN_0060eeb0(local_118,local_a8,local_70,local_a8[1] - local_118[1]);
    }
    if (local_e0[1] < (float)local_160) {
      pfVar4 = local_e0;
      pfVar5 = local_150;
      for (iVar3 = 0xe; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar5 = pfVar5 + 1;
      }
      do {
        local_164 = FUN_00610010(local_164,iVar1);
        FUN_00610030(param_2,local_164,local_e0);
      } while (local_e0[1] <= local_150[1]);
      FUN_0060eeb0(local_150,local_e0,local_38,local_e0[1] - local_150[1]);
    }
    FUN_0060edb0(param_1,local_118,local_150,local_160,param_2[2]);
    FUN_0060ef70(local_118,local_70);
    FUN_0060ef70(local_150,local_38);
  }
  return;
}

