
undefined4 * __thiscall
FUN_004c173f(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            int param_5,undefined1 *param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  void *pvVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  
  uVar3 = FUN_00420096(param_3);
  param_1[10] = uVar3;
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = 1;
  }
  if (param_5 == 0) {
    puVar4 = (undefined4 *)FUN_00420048(param_3);
    param_1[8] = *puVar4;
    param_1[1] = puVar4[1];
    param_1[9] = 0;
    *param_1 = param_4;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    if (((int)param_1[8] < 0x1f6) || ((int)puVar4[2] < 0)) {
      iVar5 = *(int *)(DAT_006e486c + 0x14);
      param_1[2] = iVar5;
      piVar1 = (int *)(iVar5 + 0x14);
      *piVar1 = *piVar1 + 1;
    }
    else {
      iVar5 = FUN_004b8e26(puVar4[2]);
      param_1[2] = iVar5;
      if (iVar5 == 0) {
        return param_1;
      }
    }
    pvVar6 = operator_new(param_1[1] << 2);
    if (pvVar6 != (void *)0x0) {
      pvVar7 = pvVar6;
      uVar3 = FUN_00420096(param_3,pvVar6);
      FUN_004c1ad4(puVar4,uVar3,pvVar7);
      iVar5 = param_1[8];
      if ((iVar5 == 0x1f5) || (iVar5 == 0x1f7)) {
        iVar5 = param_1[1];
        param_1[1] = iVar5 / 2;
        pvVar7 = operator_new(iVar5 / 2 << 2);
        param_1[3] = pvVar7;
        pvVar7 = operator_new(param_1[1] << 2);
        param_1[4] = pvVar7;
        iVar5 = 0;
        if (0 < (int)param_1[1]) {
          do {
            *(undefined4 *)(param_1[3] + iVar5 * 4) = *(undefined4 *)((int)pvVar6 + iVar5 * 4);
            *(undefined4 *)(param_1[4] + iVar5 * 4) =
                 *(undefined4 *)((int)pvVar6 + (param_1[1] + iVar5) * 4);
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)param_1[1]);
        }
      }
      else if (iVar5 == 0x1fa) {
        iVar5 = (int)param_1[1] / 5;
        param_1[1] = iVar5;
        pvVar7 = operator_new(iVar5 << 2);
        param_1[3] = pvVar7;
        pvVar7 = operator_new(param_1[1] << 2);
        param_1[4] = pvVar7;
        pvVar7 = operator_new(param_1[1] << 2);
        param_1[5] = pvVar7;
        pvVar7 = operator_new(param_1[1] << 2);
        param_1[6] = pvVar7;
        pvVar7 = operator_new(param_1[1] << 2);
        iVar5 = 0;
        param_1[7] = pvVar7;
        if (0 < (int)param_1[1]) {
          do {
            iVar8 = iVar5 * 4;
            *(undefined4 *)(iVar8 + param_1[3]) = *(undefined4 *)(iVar8 + (int)pvVar6);
            *(undefined4 *)(param_1[4] + iVar8) =
                 *(undefined4 *)((int)pvVar6 + (param_1[1] + iVar5) * 4);
            *(undefined4 *)(iVar8 + param_1[5]) =
                 *(undefined4 *)((int)pvVar6 + (iVar5 + param_1[1] * 2) * 4);
            *(undefined4 *)(param_1[6] + iVar8) =
                 *(undefined4 *)((int)pvVar6 + (iVar5 + param_1[1] * 3) * 4);
            iVar2 = iVar5 + param_1[1] * 4;
            iVar5 = iVar5 + 1;
            *(undefined4 *)(iVar8 + param_1[7]) = *(undefined4 *)((int)pvVar6 + iVar2 * 4);
          } while (iVar5 < (int)param_1[1]);
        }
      }
      else {
        pvVar7 = operator_new(param_1[1] << 2);
        param_1[3] = pvVar7;
        iVar5 = 0;
        if (0 < (int)param_1[1]) {
          do {
            *(undefined4 *)(param_1[3] + iVar5 * 4) = *(undefined4 *)((int)pvVar6 + iVar5 * 4);
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)param_1[1]);
        }
      }
      FUN_006321f0(pvVar6);
    }
  }
  else if (param_5 == 1) {
    puVar4 = (undefined4 *)FUN_00420048(param_3);
    param_1[8] = *puVar4;
    param_1[1] = puVar4[1];
    *param_1 = param_4;
    param_1[9] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    uVar9 = FUN_00420096(param_3);
    pvVar6 = operator_new(uVar9);
    param_1[3] = pvVar6;
    FUN_005a92b0(pvVar6,puVar4,uVar9);
    FUN_0042004f(param_3);
    if ((int)puVar4[2] < 0) {
      iVar5 = *(int *)(DAT_006e486c + 0x14);
      param_1[2] = iVar5;
      piVar1 = (int *)(iVar5 + 0x14);
      *piVar1 = *piVar1 + 1;
    }
    else {
      uVar3 = FUN_004b8e26(puVar4[2]);
      param_1[2] = uVar3;
    }
  }
  return param_1;
}

