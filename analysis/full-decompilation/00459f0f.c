
void __thiscall FUN_00459f0f(int param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_58 [6];
  undefined4 local_40 [2];
  undefined1 local_38 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  FUN_00438fc0(&local_18,1);
  if (*(short *)(param_1 + 0x8e) == 0) {
    iVar2 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24;
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x130) + 0x24;
    }
    if (iVar2 == 0) {
      local_8 = (int *)0x0;
    }
    else {
      local_8 = (int *)FUN_00407498((int)*(short *)(iVar2 + 0x10));
    }
    piVar3 = local_8;
    if (local_8 != (int *)0x0) {
      puVar4 = param_3;
      puVar5 = local_40;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      cVar1 = FUN_0059181d(param_3,0,piVar3);
      piVar3 = local_8;
      if (cVar1 != '\0') {
        FUN_0043908c(1);
        (**(code **)(*piVar3 + 0x30))(&local_28,param_3);
        if ((local_28 < local_20) && (local_24 < local_1c)) {
          FUN_00422698();
        }
      }
      puVar4 = local_40;
      puVar5 = param_3;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    if ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 < 3) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x130) + 0x6c;
    }
    if (iVar2 == 0) {
      local_8 = (int *)0x0;
    }
    else {
      local_8 = (int *)FUN_00407498((int)*(short *)(iVar2 + 0x10));
    }
    piVar3 = local_8;
    if (local_8 != (int *)0x0) {
      puVar4 = param_3;
      puVar5 = local_40;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      cVar1 = FUN_0059181d(param_3,3,piVar3);
      piVar3 = local_8;
      if (cVar1 != '\0') {
        FUN_0043908c(1);
        (**(code **)(*piVar3 + 0x30))(&local_28,param_3);
        if ((local_28 < local_20) && (local_24 < local_1c)) {
          FUN_00422698();
        }
      }
      puVar4 = local_40;
      puVar5 = param_3;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    if ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 < 4) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x130) + 0x90;
    }
    if (iVar2 == 0) {
      local_8 = (int *)0x0;
    }
    else {
      local_8 = (int *)FUN_00407498((int)*(short *)(iVar2 + 0x10));
    }
    piVar3 = local_8;
    if (local_8 != (int *)0x0) {
      puVar4 = param_3;
      puVar5 = local_40;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      cVar1 = FUN_0059181d(param_3,1,piVar3);
      piVar3 = local_8;
      if (cVar1 != '\0') {
        FUN_0043908c(1);
        (**(code **)(*piVar3 + 0x30))(&local_28,param_3);
        if ((local_28 < local_20) && (local_24 < local_1c)) {
          FUN_00422698();
        }
      }
      puVar4 = local_40;
      puVar5 = param_3;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    if ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 < 5) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x130) + 0xb4;
    }
    if (iVar2 == 0) {
      local_8 = (int *)0x0;
    }
    else {
      local_8 = (int *)FUN_00407498((int)*(short *)(iVar2 + 0x10));
    }
    piVar3 = local_8;
    if (local_8 != (int *)0x0) {
      puVar4 = param_3;
      puVar5 = local_40;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      cVar1 = FUN_0059181d(param_3,0,piVar3);
      piVar3 = local_8;
      if (cVar1 != '\0') {
        FUN_0043908c(1);
        (**(code **)(*piVar3 + 0x30))(&local_28,param_3);
        if ((local_28 < local_20) && (local_24 < local_1c)) {
          FUN_00422698();
        }
      }
      puVar4 = local_40;
      puVar5 = param_3;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    puVar4 = param_3;
    puVar5 = local_58;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (piVar3 = *(int **)(param_1 + 0x148); local_8 = piVar3,
        piVar3 != (int *)*(int *)(param_1 + 0x14c); piVar3 = (int *)((int)piVar3 + 0x3c)) {
      if ((*(int *)((int)piVar3 + 0x10) != 0) &&
         (((*(char *)((int)piVar3 + 0x38) != '\0' || ((*(byte *)(param_1 + 0x114) & 2) != 0)) &&
          (cVar1 = FUN_0059181d(param_3,2,0), cVar1 != '\0')))) {
        FUN_004b4718(DAT_006c438c);
        piVar3 = (int *)FUN_00438198(local_38,param_3,piVar3);
        local_28 = *piVar3;
        local_24 = piVar3[1];
        local_20 = piVar3[2];
        local_1c = piVar3[3];
        FUN_004b4718(-DAT_006c438c);
        FUN_00422698();
        piVar3 = local_8;
      }
    }
    puVar4 = local_58;
    puVar5 = param_3;
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    if ((local_18 < local_10) && (local_14 < local_c)) {
      FUN_00439016(&local_18,1);
    }
    piVar3 = (int *)FUN_00437961(local_38,param_3);
    local_18 = *piVar3;
    local_14 = piVar3[1];
    local_10 = piVar3[2];
    local_c = piVar3[3];
    if ((local_18 < local_10) && (local_14 < local_c)) {
      FUN_00439016(&local_18,1);
    }
  }
  *param_2 = local_18;
  param_2[1] = local_14;
  param_2[2] = local_10;
  param_2[3] = local_c;
  return;
}

