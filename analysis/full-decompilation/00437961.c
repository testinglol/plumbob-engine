
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00437961(int param_1,int *param_2,float *param_3)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 uVar3;
  float fVar4;
  float *pfVar5;
  char cVar6;
  int iVar7;
  LONG *pLVar8;
  undefined4 *puVar9;
  float10 fVar10;
  undefined1 local_12c [116];
  undefined1 local_b8 [16];
  undefined1 local_a8 [16];
  undefined1 local_98 [8];
  undefined1 local_90 [4];
  short local_8c;
  undefined **local_88;
  undefined4 local_84;
  undefined1 local_7c [32];
  undefined1 local_5c [16];
  float local_4c;
  float local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  tagRECT local_28;
  int *local_18;
  int *local_14;
  undefined1 local_e;
  undefined1 local_d;
  int local_c;
  int local_8;
  
  pfVar5 = param_3;
  local_8 = param_1;
  FUN_00438fc0(&local_3c,1);
  if ((*(int *)(param_1 + 0x15c) == 1) && (DAT_006d6184 != 0)) {
    *(undefined4 *)(param_1 + 0x154) = DAT_006e5490;
  }
  if ((*(short *)(param_1 + 0x8e) == 0) && (*(short *)(*(int *)(param_1 + 0x118) + 6) != 0)) {
    iVar7 = FUN_004577bb((int)*(short *)(param_1 + 0x4a));
    if ((iVar7 == 0) ||
       (local_14 = (int *)FUN_004078a4((int)param_3[7] + (uint)*(ushort *)(param_1 + 0x4c) & 7,
                                       param_3[8]), local_14 == (int *)0x0)) {
      sVar2 = *(short *)(*(int *)(param_1 + 0x118) + 0x12);
      if (((sVar2 != 2) && (sVar2 != 0xb)) && (sVar2 != 8)) {
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x11c) + 0x18);
        pLVar8 = (LONG *)FUN_004373ae(local_98,param_3[4],param_3[5],
                                      CONCAT31((int3)((uint)uVar3 >> 8),*(undefined1 *)(param_3 + 8)
                                              ),uVar3,0);
        local_28.left = *pLVar8;
        local_28.top = pLVar8[1];
        local_28.right = pLVar8[2];
        local_28.bottom = pLVar8[3];
        FUN_004b46b5(&local_3c,&local_28);
        param_1 = local_8;
      }
    }
    else {
      local_c = 0;
      if (0 < (int)(local_14[1] - *local_14 & 0xffffffe0U)) {
        do {
          puVar9 = (undefined4 *)FUN_00407ade(local_c);
          local_2c = puVar9[1];
          uVar3 = *puVar9;
          cVar6 = FUN_0043803e(uVar3);
          if (cVar6 != '\0') {
            local_44 = *(undefined4 *)(*(int *)(param_1 + 0x11c) + 8);
            param_3._0_2_ = (short)uVar3;
            local_40 = (int)(short)param_3;
            iVar7 = FUN_004c8f58(local_40);
            if (local_2c < iVar7) {
              FUN_004c8ec9(local_90,local_40,local_2c);
              uVar1 = *(undefined1 *)((int)pfVar5 + 0x35);
              local_e = *(undefined1 *)((int)pfVar5 + 0x36);
              local_d = *(undefined1 *)(pfVar5 + 0xe);
              *(byte *)((int)pfVar5 + 0x35) = (byte)*(undefined4 *)(param_1 + 0x114) & 1;
              if ((*(byte *)(param_1 + 0x114) & 8) == 0) {
                *(undefined1 *)((int)pfVar5 + 0x36) = 0;
              }
              if ((*(byte *)(param_1 + 0x114) & 0x10) != 0) {
                *(undefined1 *)(pfVar5 + 0xe) = 1;
              }
              fVar10 = (float10)FUN_004b46a4();
              local_18 = (int *)(float)fVar10;
              cVar6 = FUN_00438022();
              if (cVar6 != '\0') {
                FUN_004b475c();
              }
              iVar7 = FUN_004573f9();
              if (*(short *)(*(int *)(iVar7 + 0x60) + 0x8a) == 7) {
                FUN_004b4722(0x3f800000);
              }
              if ((((float)puVar9[4] == _DAT_0066657c) && ((float)puVar9[5] == _DAT_0066657c)) &&
                 ((float)puVar9[6] == _DAT_0066657c)) {
                pLVar8 = (LONG *)FUN_004c7387(local_a8,local_40,local_2c,puVar9[2] + (int)pfVar5[4],
                                              (puVar9[3] + (int)pfVar5[5]) - (int)local_8c,
                                              CONCAT22((short)(local_8c >> 0xf),
                                                       (ushort)*(byte *)(puVar9 + 7)),pfVar5,0);
                local_28.left = *pLVar8;
                local_28.top = pLVar8[1];
                local_28.right = pLVar8[2];
                local_28.bottom = pLVar8[3];
                FUN_004b46b5(&local_3c,&local_28);
              }
              else {
                FUN_004b45e2(pfVar5);
                local_48 = (float)puVar9[5];
                local_4c = (float)puVar9[6];
                FUN_00439195((int)*(short *)(param_1 + 0x4c),&local_48,&local_4c);
                fVar4 = (float)puVar9[4];
                *pfVar5 = local_48 + *pfVar5;
                pfVar5[1] = local_4c + pfVar5[1];
                pfVar5[2] = fVar4 + pfVar5[2];
                FUN_004b9b69(pfVar5);
                pLVar8 = (LONG *)FUN_004c7387(local_5c,local_40,local_2c,puVar9[2] + (int)pfVar5[4],
                                              (puVar9[3] + (int)pfVar5[5]) - (int)local_8c,
                                              CONCAT22((short)(local_8c >> 0xf),
                                                       (ushort)*(byte *)(puVar9 + 7)),pfVar5,0);
                local_28.left = *pLVar8;
                local_28.top = pLVar8[1];
                local_28.right = pLVar8[2];
                local_28.bottom = pLVar8[3];
                FUN_004b46b5(&local_3c,&local_28);
                FUN_004b45fe(local_12c);
              }
              FUN_004b4722(local_18);
              *(undefined1 *)((int)pfVar5 + 0x35) = uVar1;
              *(undefined1 *)((int)pfVar5 + 0x36) = local_e;
              *(undefined1 *)(pfVar5 + 0xe) = local_d;
              param_1 = local_8;
            }
            else {
              FUN_00635858(local_7c,&DAT_006c08e4,uVar3);
              pLVar8 = (LONG *)FUN_004373ae(local_b8,pfVar5[4],pfVar5[5],
                                            CONCAT31((int3)((uint)local_7c >> 8),
                                                     *(undefined1 *)(pfVar5 + 8)),local_7c,1);
              local_28.left = *pLVar8;
              local_28.top = pLVar8[1];
              local_28.right = pLVar8[2];
              local_28.bottom = pLVar8[3];
              FUN_004b46b5(&local_3c,&local_28);
              param_1 = local_8;
            }
          }
          local_c = local_c + 1;
        } while (local_c < local_14[1] - *local_14 >> 5);
      }
    }
  }
  if (*(short *)(*(int *)(param_1 + 0x118) + 0x12) != 2) {
    local_c = 0;
    local_18 = (int *)((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1);
    if (0 < (int)local_18) {
      param_3 = (float *)0x24;
      do {
        if (((int)param_3 < 0x24) ||
           ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= local_c)) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(param_1 + 0x130) + (int)param_3;
        }
        pLVar8 = (LONG *)FUN_00438082(local_5c,pfVar5,iVar7);
        local_28.left = *pLVar8;
        local_28.top = pLVar8[1];
        local_28.right = pLVar8[2];
        local_28.bottom = pLVar8[3];
        FUN_00422698();
        local_c = local_c + 1;
        param_3 = (float *)((int)param_3 + 0x24);
        param_1 = local_8;
      } while (local_c < (int)local_18);
    }
    for (iVar7 = *(int *)(param_1 + 0x148); iVar7 != *(int *)(param_1 + 0x14c); iVar7 = iVar7 + 0x3c
        ) {
      if (*(int *)(iVar7 + 0x10) != 0) {
        pLVar8 = (LONG *)FUN_00438198(local_5c,pfVar5,iVar7);
        local_28.left = *pLVar8;
        local_28.top = pLVar8[1];
        local_28.right = pLVar8[2];
        local_28.bottom = pLVar8[3];
        FUN_00422698();
        param_1 = local_8;
      }
    }
  }
  pLVar8 = (LONG *)(**(code **)(*(int *)pfVar5[6] + 8))(local_5c,param_1,pfVar5[4],pfVar5[5]);
  local_28.left = *pLVar8;
  local_28.top = pLVar8[1];
  local_28.right = pLVar8[2];
  local_28.bottom = pLVar8[3];
  FUN_004b46b5(&local_3c,&local_28);
  iVar7 = local_8;
  if ((local_38 < local_30) && (local_3c < local_34)) {
    FUN_00439016(&local_3c,1);
  }
  if (*(char *)(iVar7 + 0x188) != '\0') {
    FUN_0046f824(local_7c,0,0x20);
    local_88 = &PTR_FUN_006666e4;
    FUN_0046fa40((int)*(short *)(iVar7 + 0xf0));
    pLVar8 = (LONG *)FUN_004373ae(local_5c,pfVar5[4],pfVar5[5],*(undefined1 *)(pfVar5 + 8),local_84,
                                  3);
    local_28.left = *pLVar8;
    local_28.top = pLVar8[1];
    local_28.right = pLVar8[2];
    local_28.bottom = pLVar8[3];
    FUN_004b46b5(&local_3c,&local_28);
    iVar7 = local_8;
  }
  if (*(short *)(iVar7 + 0x70) == 2) {
    FUN_0046f824(local_7c,0,0x20);
    local_88 = &PTR_FUN_006666e4;
    if (*(int *)(iVar7 + 0x15c) == 1) {
      FUN_0046fa40((int)*(short *)(iVar7 + 0x4a));
      pLVar8 = (LONG *)FUN_004373ae(local_5c,pfVar5[4],pfVar5[5],*(undefined1 *)(pfVar5 + 8),
                                    local_84,3);
      local_28.left = *pLVar8;
      local_28.top = pLVar8[1];
      local_28.right = pLVar8[2];
      local_28.bottom = pLVar8[3];
      FUN_004b46b5(&local_3c,&local_28);
      iVar7 = local_8;
    }
    else {
      *(undefined2 *)(iVar7 + 0x70) = 0;
    }
  }
  if ((*(short *)(*(int *)(iVar7 + 0x118) + 0x12) == 2) &&
     (puVar9 = (undefined4 *)FUN_005a58fe(iVar7), puVar9 != (undefined4 *)0x0)) {
    if ((uint)(*(int *)(*(int *)(DAT_006e486c + 0x1c) + 0x98) - puVar9[5]) < 100) {
      local_14 = (int *)pfVar5[4];
      fVar4 = pfVar5[5];
      cVar6 = FUN_00492d2c();
      param_3 = (float *)((int)fVar4 - (0xaf >> (3U - cVar6 & 0x1f)));
      iVar7 = FUN_00492d2c();
      if (iVar7 == 1) {
        param_3 = (float *)((int)param_3 + -4);
      }
      local_18 = puVar9 + 1;
      FUN_0049bafe((int)local_14 - (puVar9[3] - *local_18) / 2,
                   (int)param_3 - (int)(puVar9[4] - puVar9[2]) / 2,*puVar9,pfVar5,local_18);
      pLVar8 = (LONG *)FUN_004b469d();
      local_28.left = *pLVar8;
      local_28.top = pLVar8[1];
      local_28.right = pLVar8[2];
      local_28.bottom = pLVar8[3];
      OffsetRect(&local_28,(int)local_14 - (local_18[2] - *local_18) / 2,
                 (int)param_3 - (local_18[3] - local_18[1]) / 2);
      FUN_004b46b5(&local_3c,&local_28);
    }
    else {
      FUN_005a5947(iVar7);
    }
  }
  *param_2 = local_3c;
  param_2[1] = local_38;
  param_2[2] = local_34;
  param_2[3] = local_30;
  return;
}

