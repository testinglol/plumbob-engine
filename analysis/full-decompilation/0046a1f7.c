
undefined4 __fastcall FUN_0046a1f7(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  float local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = param_1[0x14];
  piVar2 = param_1 + 0x14;
  if (iVar3 == param_1[0x13]) {
    while (iVar3 != -1) {
      FUN_0040555d(piVar2);
      piVar1 = (int *)FUN_00469872(*piVar2);
      *piVar2 = piVar1[7];
      if ((param_1[0x15] == -1) && (*piVar1 != -1)) {
        param_1[0x15] = *piVar1;
      }
      iVar3 = *piVar2;
    }
    local_14 = -NAN;
    iVar3 = param_1[2] - param_1[1] >> 2;
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      local_10 = *(int *)(param_1[1] + iVar3 * 4);
      local_c = FUN_00469872(local_10);
      if ((*(int *)(local_c + 4) != -1) && ((float)*(int *)(local_c + 4) != local_14)) {
        FUN_0040555d(&local_10);
        local_14 = *(float *)(local_c + 4);
      }
    }
    uVar4 = 0;
    if (param_1[5] - param_1[4] >> 2 != 0) {
      do {
        iVar3 = FUN_00469872(*(undefined4 *)(param_1[4] + uVar4 * 4));
        FUN_0042eb5f(iVar3 + 0x14);
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(param_1[5] - param_1[4] >> 2));
    }
    if (((param_1[5] - param_1[4] & 0xfffffffcU) != 0) && (*(char *)(*param_1 + 0x14) == '\0')) {
      piVar2 = (int *)FUN_00469872(*(undefined4 *)(param_1[1] + 4));
      piVar2 = (int *)(**(int **)*param_1 + *piVar2 * 0x14);
      local_24 = piVar2[2];
      local_20 = piVar2[3];
      local_1c = (*piVar2 + local_24) / 2;
      local_18 = (piVar2[1] + local_20) / 2;
      FUN_0042eb5f(&local_1c);
    }
  }
  else {
    local_18 = FUN_00469a9d(iVar3);
    local_10 = 0;
    if (0 < local_18) {
      do {
        local_8 = FUN_00469b93(*piVar2,local_10);
        local_c = FUN_00469872(local_8);
        fVar5 = (float10)FUN_00469967(*piVar2,local_8,&local_24);
        local_14 = (float)fVar5;
        iVar3 = FUN_00469872(*piVar2);
        local_14 = local_14 + *(float *)(iVar3 + 0x24);
        for (piVar1 = (int *)param_1[0xf]; piVar1 != (int *)param_1[0x10]; piVar1 = piVar1 + 1) {
          if (local_8 == *piVar1) {
            if (*(float *)(local_c + 0x24) <= local_14) goto LAB_0046a43f;
            piVar1 = (int *)param_1[0xf];
            goto LAB_0046a3c0;
          }
        }
LAB_0046a3d6:
        for (piVar1 = (int *)param_1[0xc]; piVar1 != (int *)param_1[0xd]; piVar1 = piVar1 + 1) {
          if (local_8 == *piVar1) {
            if (local_14 < *(float *)(local_c + 0x24)) goto LAB_0046a409;
            goto LAB_0046a43f;
          }
        }
        FUN_0040555d(&local_8);
LAB_0046a409:
        *(float *)(local_c + 0x24) = local_14;
        *(int *)(local_c + 0x14) = local_24;
        *(int *)(local_c + 0x18) = local_20;
        fVar5 = (float10)FUN_0046989d(local_8);
        local_14 = (float)fVar5;
        *(float *)(local_c + 0x28) = local_14;
        *(float *)(local_c + 0x20) = local_14 + *(float *)(local_c + 0x24);
        *(int *)(local_c + 0x1c) = *piVar2;
LAB_0046a43f:
        local_10 = local_10 + 1;
      } while (local_10 < local_18);
    }
    for (piVar1 = (int *)param_1[0xc]; piVar1 != (int *)param_1[0xd]; piVar1 = piVar1 + 1) {
      if (*piVar2 == *piVar1) {
        FUN_0042ec52(piVar1);
        break;
      }
    }
    FUN_0040555d(piVar2);
    if ((param_1[0xd] - param_1[0xc] & 0xfffffffcU) != 0) {
      iVar3 = FUN_0046aa31();
      *piVar2 = iVar3;
      return 0;
    }
  }
  return 1;
LAB_0046a3c0:
  if (piVar1 == (int *)param_1[0x10]) goto LAB_0046a3d6;
  if (local_8 == *piVar1) {
    FUN_0042ec52(piVar1);
    goto LAB_0046a3d6;
  }
  piVar1 = piVar1 + 1;
  goto LAB_0046a3c0;
}

