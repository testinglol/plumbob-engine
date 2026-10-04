
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005122a9(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  uint uVar11;
  CHAR *pCVar12;
  undefined4 uVar13;
  CHAR local_540 [1024];
  undefined1 local_140 [256];
  undefined1 local_40 [8];
  int local_38;
  int iStack_34;
  int local_30;
  int local_2c;
  int local_28;
  float local_24;
  int local_20;
  int local_1c;
  undefined2 *local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (((int *)param_1[0x17] != (int *)0x0) && ((char)param_1[0x46] != '\0')) {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x40))();
    }
    local_24 = 1.0 / (float)param_1[0x35];
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(4);
    if (cVar1 != '\0') {
      local_14 = 0;
      if ((param_1[0x51] - param_1[0x50]) / 0xc != 0) {
        local_28 = 0;
        do {
          uVar11 = param_1[0x49];
          puVar10 = (undefined2 *)0x0;
          local_1c = 0;
          local_c = 0;
          if ((uVar11 & 1) == 0) {
            if ((uVar11 & 2) == 0) {
              local_10 = ((int)(char)uVar11 & 4U) >> 1;
            }
            else {
              local_10 = 1;
            }
          }
          else {
            local_10 = 0;
          }
          while( true ) {
            uVar11 = param_1[0x49];
            if ((uVar11 & 4) == 0) {
              if ((uVar11 & 2) == 0) {
                uVar11 = (int)(char)uVar11 & 1;
              }
              else {
                uVar11 = 2;
              }
            }
            else {
              uVar11 = 3;
            }
            if ((int)uVar11 <= (int)local_10) break;
            local_1c = local_1c + (int)puVar10;
            if (local_10 == 0) {
              local_c = *(int *)(param_1[0x50] + local_28);
              local_8 = 1;
            }
            else if (local_10 == 1) {
              local_8 = 2;
              local_c = *(int *)(param_1[0x50] + 4 + local_28);
            }
            else if (local_10 == 2) {
              local_8 = 3;
              local_c = *(int *)(param_1[0x50] + 8 + local_28);
            }
            else {
              local_8 = 0;
            }
            if (param_1[0x47] == 1) {
              iVar2 = local_14 - 1;
              if (iVar2 < 0) {
                iVar2 = (param_1[0x51] - param_1[0x50]) / 0xc + -1;
              }
              if (local_10 == 0) {
                iVar2 = *(int *)(param_1[0x50] + iVar2 * 0xc);
              }
              else {
                iVar2 = *(int *)(param_1[0x50] + 4 + iVar2 * 0xc);
              }
              local_c = local_c - iVar2;
            }
            local_18 = (undefined2 *)__ftol();
            local_38 = param_1[0x3c] + param_1[7] + local_14;
            local_30 = local_38;
            iVar2 = ((param_1[0x3f] - param_1[0x3d]) - (int)local_18) + param_1[0x3d] + param_1[8] +
                    param_1[0x45] * 10;
            local_2c = iVar2 - local_1c;
            iStack_34 = (int)local_18 + (iVar2 - local_1c);
            if (local_2c < param_1[0x3f]) {
              local_20 = param_1[0x3d] + param_1[8];
              piVar3 = &local_20;
              if (local_20 <= local_2c) {
                piVar3 = &local_2c;
              }
              local_2c = *piVar3;
              local_20 = param_1[8] + -1 + param_1[0x3f];
              piVar4 = &local_20;
              if (iStack_34 <= local_20) {
                piVar4 = &iStack_34;
              }
              (**(code **)(*(int *)param_1[0x17] + 0x7c))
                        (local_38,*piVar3,local_38,*piVar4,param_1[local_8 + 0x4a],1);
            }
            local_10 = local_10 + 1;
            puVar10 = local_18;
            if ((local_10 == 1) && ((*(byte *)(param_1 + 0x49) & 2) == 0)) {
              local_10 = 2;
            }
          }
          local_14 = local_14 + 1;
          local_28 = local_28 + 0xc;
        } while (local_14 < (uint)((param_1[0x51] - param_1[0x50]) / 0xc));
      }
      (**(code **)(*(int *)param_1[0x17] + 0x24))(4);
    }
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x40);
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(*(int *)param_1[0x17] + 0xcc))();
      uVar11 = (**(code **)(*(int *)param_1[0x17] + 0xd0))();
      local_8 = 10;
      uVar11 = uVar11 >> 1;
      puVar10 = (undefined2 *)
                (iVar2 + ((param_1[0x3d] + param_1[8]) * uVar11 + param_1[7] + param_1[0x3c]) * 2);
      if (10 < param_1[0x3e] - param_1[0x3c]) {
        do {
          puVar10 = puVar10 + 10;
          local_18 = puVar10 + (param_1[0x3f] - param_1[0x3d]) * uVar11;
          for (puVar8 = puVar10; puVar8 < local_18; puVar8 = puVar8 + uVar11 * 10) {
            *puVar8 = (short)param_1[0x4e];
          }
          local_8 = local_8 + 10;
        } while (local_8 < param_1[0x3e] - param_1[0x3c]);
      }
      (**(code **)(*(int *)param_1[0x17] + 0x24))();
    }
    if ((param_1[0x40] < param_1[0x42]) && (param_1[0x41] < param_1[0x43])) {
      local_38 = param_1[0x56];
      iStack_34 = 0;
      iVar2 = param_1[0x44];
      iVar5 = __ftol();
      iVar2 = param_1[7] + param_1[0x3c] + iVar2;
      iVar5 = ((param_1[0x3f] - iVar5) - param_1[0x3d]) + param_1[0x45] * 10 +
              param_1[8] + param_1[0x3d];
      if ((((param_1[7] <= iVar2) &&
           ((((param_1[8] <= iVar5 && (iVar2 < param_1[9])) && (iVar5 < param_1[10])) &&
            ((piVar3 = (int *)param_1[0x17], piVar3[5] <= iVar2 && (piVar3[6] <= iVar5)))))) &&
          (iVar2 < piVar3[7])) &&
         ((iVar5 < piVar3[8] && (cVar1 = (**(code **)(*piVar3 + 0x20))(), cVar1 != '\0')))) {
        *(undefined2 *)
         (*(int *)(param_1[0x17] + 0x34) + (*(int *)(param_1[0x17] + 0x38) * iVar5 + iVar2) * 2) =
             0xffff;
        (**(code **)(*(int *)param_1[0x17] + 0x24))();
      }
    }
    uVar6 = FUN_00635858(local_140,s_Kb_Tick____3_2f_006cca4c,
                         (double)((float)param_1[0x35] * _DAT_0066c1a0));
    (**(code **)(*(int *)param_1[0x36] + 0x78))
              (param_1[0x17],param_1[0x38] + param_1[7],param_1[0x39] + param_1[8],local_140,uVar6,0
               ,0);
    iVar2 = param_1[0x44];
    if (iVar2 == 0) {
      iVar2 = (param_1[0x51] - param_1[0x50]) / 0xc;
    }
    iVar5 = iVar2 + -1;
    if (iVar5 == 0) {
      iVar2 = (param_1[0x51] - param_1[0x50]) / 0xc + -1;
    }
    else {
      iVar2 = iVar2 + -2;
    }
    iVar9 = 0;
    local_8 = 0;
    if ((*(byte *)(param_1 + 0x49) & 1) != 0) {
      local_8 = *(int *)(param_1[0x50] + 4 + iVar5 * 0xc);
      iVar9 = *(int *)(param_1[0x50] + 4 + iVar2 * 0xc);
    }
    if ((*(byte *)(param_1 + 0x49) & 2) != 0) {
      local_8 = local_8 + *(int *)(param_1[0x50] + 4 + iVar5 * 0xc);
      iVar9 = *(int *)(param_1[0x50] + 4 + iVar2 * 0xc);
    }
    if ((*(byte *)(param_1 + 0x49) & 4) != 0) {
      local_8 = local_8 + *(int *)(param_1[0x50] + 8 + iVar5 * 0xc);
      iVar9 = *(int *)(param_1[0x50] + 8 + iVar2 * 0xc);
    }
    local_18 = (undefined2 *)(local_8 - iVar9);
    uVar6 = FUN_00635858(local_140,s_Total____3_2f_kb__Delta____3_2f_k_006cca28,
                         (double)((float)local_8 * _DAT_0066c19c),
                         (double)((float)(int)local_18 * _DAT_0066c19c));
    iVar2 = *(int *)param_1[0x36];
    iVar5 = (**(code **)(iVar2 + 0x58))(local_140,uVar6,0,0,0);
    (**(code **)(iVar2 + 0x78))
              (param_1[0x17],param_1[0x38] + param_1[7],iVar5 + param_1[0x39] + param_1[8]);
  }
  if ((param_1[0x40] < param_1[0x42]) && (param_1[0x41] < param_1[0x43])) {
    wsprintfA(local_540,s_PageFaultCount____12d_PeakWorkin_006cc9c4,param_1[0x54],param_1[0x55],
              param_1[0x56]);
    iVar2 = *(int *)param_1[0x36];
    uVar13 = 0;
    sVar7 = _strlen(local_540);
    pCVar12 = local_540;
    uVar6 = FUN_004df599(local_40,param_1 + 7);
    (**(code **)(iVar2 + 0x80))(param_1[0x17],uVar6,pCVar12,sVar7,uVar13);
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

