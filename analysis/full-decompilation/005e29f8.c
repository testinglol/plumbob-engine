
undefined4 __thiscall
FUN_005e29f8(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            uint param_7)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar9 = *(int *)(param_1 + 0x1c);
  iVar1 = *(int *)(param_1 + 0x20);
  cVar3 = FUN_005e2e1b(&param_2,&param_3,&param_4,&param_5,0,0,iVar9 + -1,iVar1 + -1);
  if (cVar3 != '\0') {
    uVar4 = (undefined2)param_6;
    if (param_3 == param_5) {
      iVar9 = param_4;
      if (param_4 < param_2) {
        iVar9 = param_2;
        param_2 = param_4;
      }
      puVar12 = (undefined4 *)
                (*(int *)(param_1 + 0x34) + (*(int *)(param_1 + 0x38) * param_3 + param_2) * 2);
      iVar9 = (int)(short)(((short)iVar9 - (short)param_2) + 1);
      puVar13 = (undefined4 *)((int)puVar12 + iVar9 * 2);
      for (; param_7 != 0; param_7 = param_7 - 1) {
        if (puVar12 < puVar13) {
          uVar5 = (int)puVar13 + (1 - (int)puVar12);
          uVar6 = uVar5 >> 1;
          puVar13 = puVar12;
          for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar13 = CONCAT22(uVar4,uVar4);
            puVar13 = puVar13 + 1;
          }
          for (uVar5 = (uint)((uVar6 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined2 *)puVar13 = uVar4;
            puVar13 = (undefined4 *)((int)puVar13 + 2);
          }
          puVar12 = (undefined4 *)((int)puVar12 + uVar6 * 2);
        }
        puVar12 = (undefined4 *)((int)puVar12 + (*(int *)(param_1 + 0x38) - iVar9) * 2);
        puVar13 = (undefined4 *)((int)puVar12 + iVar9 * 2);
      }
    }
    else if (param_2 == param_4) {
      iVar9 = param_5;
      if (param_5 < param_3) {
        iVar9 = param_3;
        param_3 = param_5;
      }
      puVar12 = (undefined4 *)
                (*(int *)(param_1 + 0x34) + (*(int *)(param_1 + 0x38) * param_3 + param_2) * 2);
      puVar13 = (undefined4 *)((int)puVar12 + param_7 * 2);
      for (iVar9 = iVar9 + (1 - param_3); iVar9 != 0; iVar9 = iVar9 + -1) {
        if (puVar12 < puVar13) {
          uVar5 = (int)puVar13 + (1 - (int)puVar12);
          uVar6 = uVar5 >> 1;
          puVar13 = puVar12;
          for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar13 = CONCAT22(uVar4,uVar4);
            puVar13 = puVar13 + 1;
          }
          for (uVar5 = (uint)((uVar6 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined2 *)puVar13 = uVar4;
            puVar13 = (undefined4 *)((int)puVar13 + 2);
          }
          puVar12 = (undefined4 *)((int)puVar12 + uVar6 * 2);
        }
        puVar12 = (undefined4 *)((int)puVar12 + (*(int *)(param_1 + 0x38) - param_7) * 2);
        puVar13 = (undefined4 *)((int)puVar12 + param_7 * 2);
      }
    }
    else {
      iVar7 = FUN_00636bef(param_4 - param_2);
      local_18 = FUN_00636bef(param_5 - param_3);
      bVar2 = iVar7 < local_18;
      if (bVar2) {
        local_10 = iVar7 * 2 - local_18;
        local_2c = iVar7 - local_18;
        local_28 = iVar7;
      }
      else {
        local_2c = local_18 - iVar7;
        local_10 = local_18 * 2 - iVar7;
        local_28 = local_18;
        local_18 = iVar7;
      }
      local_18 = local_18 + 1;
      local_28 = local_28 * 2;
      local_2c = local_2c * 2;
      local_1c = (uint)!bVar2;
      local_20 = (uint)bVar2;
      if (param_4 < param_2) {
        local_1c = -local_1c;
        local_14 = 0xffffffff;
      }
      else {
        local_14 = 1;
      }
      if (param_5 < param_3) {
        local_20 = -local_20;
        local_24 = 0xffffffff;
      }
      else {
        local_24 = 1;
      }
      local_8 = param_2;
      local_c = param_3;
      if (param_7 == 1) {
        if (0 < local_18) {
          param_7 = local_18;
          do {
            *(undefined2 *)
             (*(int *)(param_1 + 0x34) + (*(int *)(param_1 + 0x38) * param_3 + local_8) * 2) =
                 (undefined2)param_6;
            uVar5 = local_24;
            iVar9 = local_2c;
            uVar6 = local_14;
            if (local_10 < 0) {
              uVar5 = local_20;
              iVar9 = local_28;
              uVar6 = local_1c;
            }
            local_8 = local_8 + uVar6;
            local_10 = local_10 + iVar9;
            param_3 = param_3 + uVar5;
            param_7 = param_7 + -1;
          } while (param_7 != 0);
        }
      }
      else if (local_18 != 0) {
        do {
          if ((((local_8 < (int)(param_7 - 1)) || ((int)(iVar9 - param_7) < local_8)) ||
              (local_c < (int)(param_7 - 1))) || ((int)(iVar1 - param_7) < local_c)) break;
          if (local_14 == 0xffffffff) {
            puVar13 = (undefined4 *)
                      (*(int *)(param_1 + 0x34) + 2 +
                      ((*(int *)(param_1 + 0x38) * local_c - param_7) + local_8) * 2);
          }
          else {
            puVar13 = (undefined4 *)
                      (*(int *)(param_1 + 0x34) + (*(int *)(param_1 + 0x38) * local_c + local_8) * 2
                      );
          }
          for (uVar5 = param_7 & 0xffff; uVar5 != 0; uVar5 = uVar5 - 1) {
            if (param_7 != 0) {
              puVar12 = puVar13;
              for (uVar6 = param_7 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
                *puVar12 = CONCAT22((undefined2)param_6,(undefined2)param_6);
                puVar12 = puVar12 + 1;
              }
              for (uVar6 = (uint)((param_7 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
                *(undefined2 *)puVar12 = (undefined2)param_6;
                puVar12 = (undefined4 *)((int)puVar12 + 2);
              }
            }
            iVar7 = *(int *)(param_1 + 0x38);
            if (local_24 == 0xffffffff) {
              iVar7 = -iVar7;
            }
            puVar13 = (undefined4 *)((int)puVar13 + iVar7 * 2);
          }
          uVar6 = local_24;
          iVar7 = local_2c;
          uVar5 = local_14;
          if (local_10 < 0) {
            uVar6 = local_20;
            iVar7 = local_28;
            uVar5 = local_1c;
          }
          local_8 = local_8 + uVar5;
          local_10 = local_10 + iVar7;
          local_c = local_c + uVar6;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
        for (; local_18 != 0; local_18 = local_18 + -1) {
          if (local_14 == 0xffffffff) {
            iVar10 = *(int *)(param_1 + 0x34);
            uVar5 = (local_8 - param_7) + 1;
            iVar8 = *(int *)(param_1 + 0x38);
            uVar5 = -(uint)(uVar5 != 0) & uVar5;
            iVar7 = iVar8 * local_c;
          }
          else {
            iVar7 = local_8;
            if (iVar9 + -1 <= local_8) {
              iVar7 = iVar9 + -1;
            }
            iVar8 = *(int *)(param_1 + 0x38);
            iVar10 = *(int *)(param_1 + 0x34);
            uVar5 = iVar8 * local_c;
          }
          puVar13 = (undefined4 *)(iVar10 + (uVar5 + iVar7) * 2);
          for (uVar5 = param_7 & 0xffff; uVar5 != 0; uVar5 = uVar5 - 1) {
            if ((*(undefined4 **)(param_1 + 0x34) <= puVar13) &&
               (puVar13 < (undefined4 *)(iVar10 + iVar8 * iVar1 * 2))) {
              uVar6 = param_7;
              if (local_14 == 0xffffffff) {
                if (local_8 < (int)(param_7 - 1)) {
                  uVar6 = local_8 + 1;
                }
              }
              else if ((int)(iVar9 - param_7) < local_8) {
                uVar6 = iVar9 - local_8;
              }
              if (uVar6 != 0) {
                puVar12 = puVar13;
                for (uVar11 = uVar6 >> 1; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar12 = CONCAT22((undefined2)param_6,(undefined2)param_6);
                  puVar12 = puVar12 + 1;
                }
                for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
                  *(undefined2 *)puVar12 = (undefined2)param_6;
                  puVar12 = (undefined4 *)((int)puVar12 + 2);
                }
              }
            }
            iVar7 = *(int *)(param_1 + 0x38);
            if (local_24 == 0xffffffff) {
              iVar7 = -iVar7;
            }
            puVar13 = (undefined4 *)((int)puVar13 + iVar7 * 2);
          }
          uVar6 = local_24;
          iVar7 = local_2c;
          uVar5 = local_14;
          if (local_10 < 0) {
            uVar6 = local_20;
            iVar7 = local_28;
            uVar5 = local_1c;
          }
          local_8 = local_8 + uVar5;
          local_10 = local_10 + iVar7;
          local_c = local_c + uVar6;
        }
      }
    }
  }
  return 1;
}

