
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0060e160(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int local_18;
  
  puVar5 = (undefined4 *)FUN_005a9320(0x18);
  if (puVar5 == (undefined4 *)0x0) {
    *param_1 = 0;
    return 0;
  }
  puVar10 = puVar5;
  for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *puVar5 = 1;
  puVar5[2] = param_2;
  puVar5[3] = param_3;
  *param_1 = puVar5;
  piVar6 = (int *)FUN_005a9320(0x40);
  puVar5[1] = piVar6;
  if (piVar6 == (int *)0x0) {
    FUN_005a9340(puVar5);
    *param_1 = 0;
    return 0;
  }
  iVar9 = FUN_005a9320(0x2000);
  *piVar6 = iVar9;
  if (iVar9 == 0) {
    FUN_005a9340(piVar6);
    FUN_005a9340(puVar5);
    *param_1 = 0;
    return 0;
  }
  local_18 = *(int *)(*param_3 + 0x14);
  iVar7 = *(int *)(*param_3 + 0x10);
  piVar1 = piVar6 + 4;
  if (param_5 == (int *)0x0) {
    *piVar1 = iVar7 / 2;
    piVar6[6] = local_18 / 2;
    piVar6[0xc] = 0;
    piVar6[0xe] = 0;
    piVar6[8] = 1;
    *(undefined1 *)((int)piVar6 + 0x2b) = 0;
    *(undefined1 *)((int)piVar6 + 0x2a) = 0;
    *(undefined1 *)((int)piVar6 + 0x29) = 0;
    *(undefined1 *)(piVar6 + 10) = 0;
    piVar6[0xd] = 0x3ff00000;
    piVar6[0xf] = 0;
  }
  else {
    dVar2 = *(double *)(param_5 + 8);
    *piVar1 = *param_5;
    *(double *)(piVar6 + 0xc) = dVar2;
    dVar3 = *(double *)(param_5 + 10);
    piVar6[6] = param_5[2];
    iVar4 = param_5[4];
    *(double *)(piVar6 + 0xe) = dVar3;
    piVar6[8] = iVar4;
    if ((iVar4 < 1) || (2 < iVar4)) {
      piVar6[8] = 1;
    }
    if (dVar2 < _DAT_00667270) {
      piVar6[0xc] = 0;
      piVar6[0xd] = 0x3fe00000;
    }
    if (_DAT_00668308 < *(double *)(piVar6 + 0xc)) {
      piVar6[0xc] = 0;
      piVar6[0xd] = 0x40000000;
    }
    if (dVar3 < _DAT_006669e8) {
      piVar6[0xe] = 0;
      piVar6[0xf] = 0;
    }
    if (_DAT_00668308 < *(double *)(piVar6 + 0xe)) {
      piVar6[0xe] = 0;
      piVar6[0xf] = 0x40000000;
    }
  }
  puVar5[5] = piVar1;
  if (iVar7 < *piVar1) {
    iVar7 = *piVar1;
  }
  if (local_18 < piVar6[6]) {
    local_18 = piVar6[6];
  }
  puVar5[4] = 6;
  iVar7 = FUN_0060d590(param_3,iVar7,local_18);
  piVar6[2] = iVar7;
  if (iVar7 == 0) {
    FUN_005a9340(iVar9);
    FUN_005a9340(piVar6);
    FUN_005a9340(puVar5);
    *param_1 = 0;
    return 0;
  }
  uVar8 = __ftol();
  iVar9 = FUN_0060db30(*piVar6,0x1000,uVar8);
  iVar7 = __ftol();
  piVar6[1] = (int)(iVar7 * iVar9 + (iVar7 * iVar9 >> 0x1f & 0x3ffU)) >> 10;
  return 1;
}

