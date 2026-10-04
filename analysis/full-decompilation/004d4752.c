
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d4752(int *param_1,int param_2,uint param_3,uint param_4)

{
  SHORT SVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  int iVar5;
  float10 fVar6;
  undefined4 *puVar7;
  uint uVar8;
  float *pfVar9;
  float fVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined1 local_24 [12];
  undefined2 local_18;
  undefined2 local_16;
  ushort local_14;
  int local_10;
  float local_c;
  char local_5;
  
  iVar5 = param_2;
  if ((char)param_1[0x24] == '\0') {
    return;
  }
  if (param_1[0xe] == 0) {
    param_1[0xf] = param_1[10];
    param_1[0x10] = param_1[0xb];
  }
  param_1[0xe] = param_1[0xe] + 1;
  param_1[0xc] = param_1[10];
  param_1[10] = param_2;
  param_1[0xd] = param_1[0xb];
  param_1[0xb] = param_3;
  local_5 = FUN_004d3d3d(param_2,param_3);
  SVar1 = GetKeyState(1);
  param_2 = CONCAT13(SVar1 < 0,(undefined3)param_2);
  if ((char)param_1[9] != '\0') {
    return;
  }
  *(undefined1 *)((int)param_1 + 0x93) = 0;
  if ((*(char *)((int)param_1 + 0x45) != '\0') &&
     ((iVar2 = FUN_00636bef(param_1[10] - param_1[0x13]), param_1[0x12] < iVar2 ||
      (iVar2 = FUN_00636bef(param_1[0xb] - param_1[0x14]), param_1[0x12] < iVar2)))) {
    local_10 = param_1[0x13];
    local_c = (float)param_1[0x14];
    *(undefined1 *)((int)param_1 + 0x45) = 0;
    *(undefined1 *)(param_1 + 0x11) = 1;
    FUN_004d279d(&local_10);
    FUN_004d4d42(0x19);
  }
  if ((char)param_1[0x11] != '\0') {
    param_3 = param_1[0x14] - param_1[0xb];
    local_c = (float)(int)param_3 * (float)param_1[0x17];
    param_1[2] = (int)((float)(param_1[0x13] - param_1[10]) * (float)param_1[0x17]);
    param_1[3] = (int)local_c;
    uVar3 = FUN_004d5363(param_1 + 2);
    FUN_004d4d42(uVar3);
    goto LAB_004d4c3d;
  }
  if (((*(char *)((int)param_1 + 0x55) == '\0') && (local_5 != '\0')) ||
     (*(char *)((int)param_1 + 0x91) == '\0')) goto LAB_004d4c77;
  iVar2 = param_1[0x16];
  if ((int)param_3 < iVar2) {
    if (iVar5 < iVar2) {
      if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
        if (param_1[0x22] != 1) {
          param_1[0x22] = 1;
          DVar4 = timeGetTime();
          param_1[0x23] = DVar4;
          FUN_004d4d42(0x16);
        }
        local_c = -(float)param_1[0x18];
        param_1[2] = (int)((float)param_1[0x18] * _DAT_00668fe4);
LAB_004d4a5f:
        param_1[3] = (int)local_c;
LAB_004d4b73:
        pfVar9 = (float *)(param_1 + 2);
        if ((*(char *)((int)param_1 + 0x91) == '\0') && ((char)param_1[0x11] == '\0')) {
          uVar11 = 0;
          uVar3 = 0;
          *pfVar9 = 0.0;
          param_1[3] = 0;
          param_1[0x22] = 0;
          (**(code **)(*DAT_006fe8bc + 0x18))(0,0);
          FUN_005dadbc(uVar3,uVar11);
          puVar13 = &param_3;
          puVar7 = &param_4;
          (**(code **)(*DAT_006fe8bc + 0x18))(puVar7,puVar13);
          FUN_005d9928(puVar7,puVar13);
          uVar8 = param_4;
          uVar12 = param_3;
          (**(code **)(*DAT_006fe8bc + 0x18))(param_4,param_3);
          iVar5 = FUN_005da3e9(uVar8,uVar12);
          if (iVar5 != 0) {
            FUN_005ddddb();
          }
        }
        else {
          DVar4 = timeGetTime();
          param_3 = DVar4 - param_1[0x23];
          if (param_3 < 0x5dc) {
            fVar10 = (float)(int)param_3 * _DAT_00668fe0;
            *pfVar9 = fVar10 * *pfVar9;
            param_1[3] = (int)(fVar10 * (float)param_1[3]);
          }
          fVar6 = (float10)FUN_004d4d2c();
          if ((float10)(float)param_1[0x19] < fVar6) {
            local_c = (float)(((float10)(float)param_1[0x19] / fVar6) * (float10)(float)param_1[3]);
            *pfVar9 = (float)(((float10)(float)param_1[0x19] / fVar6) * (float10)*pfVar9);
            param_1[3] = (int)local_c;
          }
        }
LAB_004d4c3d:
        if (param_1[1] != 0) {
          return;
        }
        if ((*(char *)((int)param_1 + 0x91) == '\0') && ((char)param_1[0x11] == '\0')) {
          return;
        }
        if (*(char *)((int)param_1 + 0x92) != '\0') {
          return;
        }
        FUN_004d555c();
        param_1[4] = DAT_006e5490;
        return;
      }
      (**(code **)(*param_1 + 0x38))();
      uVar3 = 0x16;
    }
    else if (iVar5 < param_1[7] - iVar2) {
      if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
        if (param_1[0x22] != 2) {
          param_1[0x22] = 2;
          DVar4 = timeGetTime();
          param_1[0x23] = DVar4;
          FUN_004d4d42(0x13);
        }
        fVar10 = -(float)param_1[0x18];
LAB_004d4aa8:
        param_1[2] = 0;
LAB_004d4b70:
        param_1[3] = (int)fVar10;
        goto LAB_004d4b73;
      }
      (**(code **)(*param_1 + 0x38))();
      uVar3 = 0x13;
    }
    else {
      if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
        if (param_1[0x22] != 3) {
          param_1[0x22] = 3;
          DVar4 = timeGetTime();
          param_1[0x23] = DVar4;
          FUN_004d4d42(0x15);
        }
        local_c = -(float)param_1[0x18];
        param_1[2] = (int)((float)param_1[0x18] + (float)param_1[0x18]);
        goto LAB_004d4a5f;
      }
      (**(code **)(*param_1 + 0x38))();
      uVar3 = 0x15;
    }
LAB_004d48a5:
    FUN_004d4d42(uVar3);
    *(undefined1 *)((int)param_1 + 0x93) = 1;
  }
  else {
    if (param_1[8] - iVar2 <= (int)param_3) {
      if (iVar5 < iVar2) {
        if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
          if (param_1[0x22] != 5) {
            param_1[0x22] = 5;
            DVar4 = timeGetTime();
            param_1[0x23] = DVar4;
            FUN_004d4d42(0x18);
          }
          local_c = (float)param_1[0x18];
          param_1[2] = (int)((float)param_1[0x18] * _DAT_00668fe4);
          goto LAB_004d4a5f;
        }
        (**(code **)(*param_1 + 0x38))();
        uVar3 = 0x18;
      }
      else if (iVar5 < param_1[7] - iVar2) {
        if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
          if (param_1[0x22] != 6) {
            param_1[0x22] = 6;
            DVar4 = timeGetTime();
            param_1[0x23] = DVar4;
            FUN_004d4d42(0x14);
          }
          fVar10 = (float)param_1[0x18];
          goto LAB_004d4aa8;
        }
        (**(code **)(*param_1 + 0x38))();
        uVar3 = 0x14;
      }
      else {
        if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
          if (param_1[0x22] != 7) {
            param_1[0x22] = 7;
            DVar4 = timeGetTime();
            param_1[0x23] = DVar4;
            FUN_004d4d42(0x17);
          }
          local_c = (float)param_1[0x18];
          param_1[2] = (int)((float)param_1[0x18] + (float)param_1[0x18]);
          goto LAB_004d4a5f;
        }
        (**(code **)(*param_1 + 0x38))();
        uVar3 = 0x17;
      }
      goto LAB_004d48a5;
    }
    if (iVar2 <= iVar5) {
      if ((iVar5 < param_1[7] - iVar2) || (local_5 != '\0')) goto LAB_004d4c77;
      if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
        if (param_1[0x22] != 8) {
          param_1[0x22] = 8;
          DVar4 = timeGetTime();
          param_1[0x23] = DVar4;
          FUN_004d4d42(0x12);
        }
        fVar10 = (float)param_1[0x18];
        goto LAB_004d4b68;
      }
      (**(code **)(*param_1 + 0x38))();
      uVar3 = 0x12;
LAB_004d4b2c:
      FUN_004d4d42(uVar3);
      *(undefined1 *)((int)param_1 + 0x93) = 1;
      goto LAB_004d4cda;
    }
    if (local_5 == '\0') {
      if (((char)param_1[0x15] == '\0') || (param_2._3_1_ != '\0')) {
        if (param_1[0x22] != 4) {
          param_1[0x22] = 4;
          DVar4 = timeGetTime();
          param_1[0x23] = DVar4;
          FUN_004d4d42(0x11);
        }
        fVar10 = -(float)param_1[0x18];
LAB_004d4b68:
        param_1[2] = (int)fVar10;
        fVar10 = 0.0;
        goto LAB_004d4b70;
      }
      (**(code **)(*param_1 + 0x38))();
      uVar3 = 0x11;
      goto LAB_004d4b2c;
    }
LAB_004d4c77:
    param_1[0x22] = 0;
    uVar11 = 0;
    uVar3 = 0;
    (**(code **)(*DAT_006fe8bc + 0x18))(0,0);
    FUN_005dadbc(uVar3,uVar11);
    puVar13 = &param_2;
    pfVar9 = &local_c;
    (**(code **)(*DAT_006fe8bc + 0x18))(pfVar9,puVar13);
    FUN_005d9928(pfVar9,puVar13);
    fVar10 = local_c;
    uVar3 = param_2;
    (**(code **)(*DAT_006fe8bc + 0x18))(local_c,param_2);
    iVar2 = FUN_005da3e9(fVar10,uVar3);
    if (iVar2 != 0) {
      FUN_005ddddb();
    }
    (**(code **)(*param_1 + 0x38))();
  }
  if (local_5 != '\0') {
    return;
  }
LAB_004d4cda:
  if (*(char *)((int)param_1 + 0x93) == '\0') {
    local_16 = (undefined2)iVar5;
    local_18 = (undefined2)param_3;
    local_14 = 0;
    if ((param_4 & 1) != 0) {
      local_14 = 0x200;
    }
    if ((param_4 & 2) != 0) {
      local_14 = local_14 | 0x100;
    }
    SVar1 = GetKeyState(1);
    FUN_004ab995(local_24,SVar1 < 0);
  }
  return;
}

