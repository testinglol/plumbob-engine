
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062b390(double *param_1)

{
  byte *pbVar1;
  longlong lVar2;
  byte bVar3;
  char cVar4;
  double dVar5;
  double dVar6;
  bool bVar7;
  uint uVar8;
  double *pdVar9;
  ulonglong uVar10;
  char *pcVar11;
  byte *pbVar12;
  int iVar13;
  bool bVar14;
  undefined4 uVar15;
  float10 fVar16;
  float10 fVar17;
  byte local_238;
  byte local_237 [511];
  undefined8 local_38;
  int iStack_2c;
  undefined4 local_28;
  undefined8 local_24;
  double local_1c;
  double local_14;
  undefined8 local_c;
  
  pdVar9 = param_1;
  pcVar11 = *(char **)((int)param_1 + 0x3c);
  local_28 = 0;
  if (*pcVar11 == '\0') goto LAB_0062b8df;
  pcVar11 = (char *)FUN_0062b8f0(&local_238,pcVar11);
  if (local_238 == 0) {
    fVar16 = (float10)_DAT_006669e8;
    uVar15 = 0;
    local_14 = _DAT_006669e8;
    local_38 = local_38 & 0xffffffff;
  }
  else {
    fVar16 = (float10)_DAT_006669e8;
    uVar15 = 1;
    bVar14 = false;
    local_38 = CONCAT44(1,(undefined4)local_38);
    pbVar12 = &local_238;
    if (local_238 == 0x2b) {
      pbVar12 = local_237;
    }
    else if (local_238 == 0x2d) {
      pbVar12 = local_237;
      bVar14 = true;
    }
    bVar3 = *pbVar12;
    while (bVar3 - 0x30 < 10) {
      iVar13 = bVar3 - 0x30;
      local_24 = CONCAT44(iVar13,(uint)local_24);
      pbVar1 = pbVar12 + 1;
      pbVar12 = pbVar12 + 1;
      fVar16 = fVar16 * (float10)_DAT_00667410 + (float10)iVar13;
      bVar3 = *pbVar1;
    }
    if (*pbVar12 == 0x2e) {
      fVar17 = (float10)_DAT_00668348;
      bVar3 = pbVar12[1];
      pbVar1 = pbVar12;
      while( true ) {
        pbVar12 = pbVar1 + 1;
        if (9 < bVar3 - 0x30) break;
        iVar13 = bVar3 - 0x30;
        local_24 = CONCAT44(iVar13,(uint)local_24);
        bVar3 = pbVar1[2];
        fVar16 = (float10)iVar13 * fVar17 + fVar16;
        fVar17 = fVar17 * (float10)_DAT_00668348;
        pbVar1 = pbVar12;
      }
    }
    if (bVar14) {
      fVar16 = -fVar16;
    }
    if (*pbVar12 != 0) {
      if (*(int *)(param_1 + 7) != 0) {
        fVar16 = (float10)FUN_00628440(*(int *)(param_1 + 7),&local_238);
        local_14 = (double)fVar16;
        goto LAB_0062b4c3;
      }
      fVar16 = (float10)FUN_0063b213();
    }
    local_14 = (double)fVar16;
  }
LAB_0062b4c3:
  uVar10 = local_24;
  cVar4 = *pcVar11;
  if ((cVar4 == ',') || (cVar4 == '\0')) {
    param_1[3] = (double)fVar16;
    param_1[2] = (double)fVar16;
    *(undefined4 *)(param_1 + 1) = 0;
    *(undefined4 *)(param_1 + 6) = 1;
    *param_1 = (double)fVar16;
    *(undefined4 *)((int)param_1 + 0xc) = 0x3ff00000;
    *(undefined4 *)((int)param_1 + 0x34) = 0;
    local_28 = uVar15;
    if (cVar4 == ',') {
      pcVar11 = pcVar11 + 1;
    }
LAB_0062b8df:
    *(char **)((int)param_1 + 0x3c) = pcVar11;
    return local_28;
  }
  local_24 = local_24 & 0xffffffff;
  if ((cVar4 == '.') && (pcVar11[1] == '.')) {
    pcVar11 = pcVar11 + 2;
    local_24._0_4_ = (uint)uVar10;
    local_24 = CONCAT44(1,(uint)local_24);
  }
  pcVar11 = (char *)FUN_0062b8f0(&local_238,pcVar11);
  if (local_238 == 0) {
    iStack_2c = 0;
    local_1c = 0.0;
  }
  else {
    fVar16 = (float10)_DAT_006669e8;
    bVar14 = false;
    iStack_2c = 1;
    pbVar12 = &local_238;
    if (local_238 == 0x2b) {
      pbVar12 = local_237;
    }
    else if (local_238 == 0x2d) {
      pbVar12 = local_237;
      bVar14 = true;
    }
    bVar3 = *pbVar12;
    while (bVar3 - 0x30 < 10) {
      pbVar1 = pbVar12 + 1;
      pbVar12 = pbVar12 + 1;
      fVar16 = fVar16 * (float10)_DAT_00667410 + (float10)(int)(bVar3 - 0x30);
      bVar3 = *pbVar1;
    }
    if (*pbVar12 == 0x2e) {
      fVar17 = (float10)_DAT_00668348;
      bVar3 = pbVar12[1];
      pbVar1 = pbVar12;
      while( true ) {
        uVar8 = (uint)bVar3;
        pbVar12 = pbVar1 + 1;
        if (9 < uVar8 - 0x30) break;
        bVar3 = pbVar1[2];
        fVar16 = (float10)(int)(uVar8 - 0x30) * fVar17 + fVar16;
        fVar17 = fVar17 * (float10)_DAT_00668348;
        pbVar1 = pbVar12;
      }
    }
    if (bVar14) {
      fVar16 = -fVar16;
    }
    if (*pbVar12 != 0) {
      if (*(int *)(param_1 + 7) != 0) {
        fVar16 = (float10)FUN_00628440(*(int *)(param_1 + 7),&local_238);
        local_1c = (double)fVar16;
        goto LAB_0062b5f7;
      }
      fVar16 = (float10)FUN_0063b213();
    }
    local_1c = (double)fVar16;
  }
LAB_0062b5f7:
  iVar13 = iStack_2c;
  if ((*pcVar11 == '+') && (pcVar11[1] == '=')) {
    pcVar11 = pcVar11 + 2;
  }
  if ((*pcVar11 == '-') && (pcVar11[1] == '=')) {
    pcVar11 = pcVar11 + 2;
  }
  pcVar11 = (char *)FUN_0062b8f0(&local_238,pcVar11);
  if (local_238 == 0) {
    bVar14 = false;
    local_c = 0.0;
  }
  else {
    fVar16 = (float10)_DAT_006669e8;
    bVar7 = false;
    bVar14 = true;
    pbVar12 = &local_238;
    if (local_238 == 0x2b) {
      pbVar12 = local_237;
    }
    else if (local_238 == 0x2d) {
      pbVar12 = local_237;
      bVar7 = true;
    }
    bVar3 = *pbVar12;
    while (bVar3 - 0x30 < 10) {
      iVar13 = bVar3 - 0x30;
      local_c = (double)CONCAT44(iVar13,(undefined4)local_c);
      pbVar1 = pbVar12 + 1;
      pbVar12 = pbVar12 + 1;
      fVar16 = fVar16 * (float10)_DAT_00667410 + (float10)iVar13;
      bVar3 = *pbVar1;
    }
    if (*pbVar12 == 0x2e) {
      fVar17 = (float10)_DAT_00668348;
      bVar3 = pbVar12[1];
      pbVar1 = pbVar12;
      while( true ) {
        pbVar12 = pbVar1 + 1;
        if (9 < bVar3 - 0x30) break;
        iVar13 = bVar3 - 0x30;
        local_c = (double)CONCAT44(iVar13,(undefined4)local_c);
        bVar3 = pbVar1[2];
        fVar16 = (float10)iVar13 * fVar17 + fVar16;
        fVar17 = fVar17 * (float10)_DAT_00668348;
        pbVar1 = pbVar12;
      }
    }
    if (bVar7) {
      fVar16 = -fVar16;
    }
    if (*pbVar12 != 0) {
      if (*(int *)(param_1 + 7) != 0) {
        fVar16 = (float10)FUN_00628440(*(int *)(param_1 + 7),&local_238);
        local_c = (double)fVar16;
        iVar13 = iStack_2c;
        goto LAB_0062b720;
      }
      fVar16 = (float10)FUN_0063b213();
    }
    local_c = (double)fVar16;
    iVar13 = iStack_2c;
  }
LAB_0062b720:
  cVar4 = *pcVar11;
  if (((cVar4 != '\0') && (cVar4 != ',')) || ((local_38._4_4_ == 0 && ((iVar13 == 0 && (!bVar14)))))
     ) {
    *(undefined4 *)((int)param_1 + 0x44) = 1;
    *(char **)((int)param_1 + 0x3c) = pcVar11;
    return local_28;
  }
  local_28 = 1;
  param_1 = (double *)pcVar11;
  if (cVar4 == ',') {
    param_1 = (double *)(pcVar11 + 1);
  }
  if (bVar14) {
    if (_DAT_006669e8 <= local_c) {
      if (local_c == _DAT_006669e8) {
        local_c = 1.0;
        *(undefined4 *)((int)pdVar9 + 0x44) = 1;
      }
    }
    else {
      local_c = -local_c;
    }
  }
  else {
    local_c = 1.0;
  }
  if (local_38._4_4_ == 0) {
    local_14 = pdVar9[4];
    if (iVar13 != 0) {
      fVar16 = (float10)FUN_006369f9(-((pdVar9[4] - local_1c) / local_c));
      local_14 = (double)((float10)local_1c - fVar16 * (float10)local_c);
      goto LAB_0062b7de;
    }
  }
  else {
LAB_0062b7de:
    if (iVar13 != 0) goto LAB_0062b819;
  }
  local_1c = local_14;
  if ((local_24._4_4_ != 0) || (bVar14)) {
    fVar16 = (float10)FUN_006369f9((pdVar9[5] - local_14) / local_c);
    local_1c = (double)(fVar16 * (float10)local_c + (float10)local_14);
  }
LAB_0062b819:
  lVar2 = (longlong)
          ROUND(((local_c * _DAT_006782d0 + (local_1c - local_14)) / local_c + _DAT_00667280) -
                _DAT_00667270);
  local_24._0_4_ = (uint)lVar2;
  local_24._4_4_ = (int)((ulonglong)lVar2 >> 0x20);
  dVar5 = local_1c;
  dVar6 = local_14;
  if (local_1c < local_14) {
    lVar2 = CONCAT44(-(uint)(2 < (uint)local_24) - local_24._4_4_,2 - (uint)local_24);
    local_c = -local_c;
    dVar5 = local_14;
    dVar6 = local_1c;
  }
  *pdVar9 = local_14;
  *(int *)(pdVar9 + 6) = (int)lVar2;
  pdVar9[2] = dVar6;
  *(int *)((int)pdVar9 + 0x34) = (int)((ulonglong)lVar2 >> 0x20);
  pdVar9[3] = dVar5;
  *(undefined4 *)(pdVar9 + 1) = (undefined4)local_c;
  *(undefined4 *)((int)pdVar9 + 0xc) = local_c._4_4_;
  *(double **)((int)pdVar9 + 0x3c) = param_1;
  return local_28;
}

