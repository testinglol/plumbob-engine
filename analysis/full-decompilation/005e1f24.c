
undefined4 __thiscall
FUN_005e1f24(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  param_5 = (param_3 - param_2) + param_4;
  if ((((((param_2 < 0x1001) && (-0x1001 < param_2)) && (param_3 < 0x1001)) &&
       ((-0x1001 < param_3 && (param_4 < 0x1001)))) && (-0x1001 < param_4)) &&
     ((((int)param_5 < 0x1001 && (-0x1001 < (int)param_5)) && (param_2 <= param_4)))) {
    local_c = (param_2 + param_4) / 2;
    iVar3 = param_1[8];
    iVar12 = (param_4 - param_2) / 2;
    local_8 = param_3 + iVar12;
    iVar4 = param_1[7];
    local_10 = param_1;
    if (((((param_2 < 0) || (iVar4 <= param_2)) || (param_4 < 0)) ||
        ((iVar4 <= param_4 || (param_3 < 0)))) ||
       ((iVar3 <= param_3 || (((int)param_5 < 0 || (iVar3 <= (int)param_5)))))) {
      uVar7 = (**(code **)(*param_1 + 0xd0))();
      uVar7 = uVar7 >> 1;
      param_5 = uVar7;
      local_20 = (**(code **)(*param_1 + 0xcc))();
      local_24 = local_20 + (iVar3 + -1) * uVar7 * 2;
      local_30 = 0;
      local_2c = 0;
      local_3c = 3;
      iVar1 = local_20 + (uVar7 * local_8 + local_c) * 2;
      local_40 = 1 - iVar12;
      local_38 = iVar12 * -2 + 5;
      local_28 = iVar12 * param_5;
      if ((-1 < iVar12 + local_c) &&
         (((iVar12 + local_c < iVar4 && (-1 < local_8)) && (local_8 < iVar3)))) {
        *(undefined2 *)(iVar12 * 2 + iVar1) = (undefined2)param_6;
      }
      if (((-1 < local_c - iVar12) && (local_c - iVar12 < iVar4)) &&
         ((-1 < local_8 && (local_8 < iVar3)))) {
        *(undefined2 *)(iVar1 + iVar12 * -2) = (undefined2)param_6;
      }
      if ((-1 < local_c) && (local_c < iVar4)) {
        if ((-1 < local_8 - iVar12) && (local_8 - iVar12 < iVar3)) {
          *(undefined2 *)(iVar1 + local_28 * -2) = (undefined2)param_6;
        }
        if (((local_c < iVar4) && (-1 < local_8 + iVar12)) && (local_8 + iVar12 < iVar3)) {
          *(undefined2 *)(iVar1 + local_28 * 2) = (undefined2)param_6;
        }
      }
      if (1 < iVar12) {
        do {
          local_2c = local_2c + param_5;
          iVar8 = local_30 + 1;
          if (local_40 < 0) {
            local_40 = local_40 + local_3c;
            local_38 = local_38 + 2;
          }
          else {
            local_40 = local_40 + local_38;
            local_28 = local_28 - param_5;
            local_38 = local_38 + 4;
            local_14 = -iVar8;
            local_1c = local_14 + local_c;
            iVar12 = iVar12 + -1;
            if (((local_1c < 0) || (iVar4 <= local_1c)) ||
               ((iVar9 = local_8 - iVar12, iVar9 < 0 || (iVar3 <= iVar9)))) {
              if (((-1 < local_c + iVar8) && (local_c + iVar8 < iVar4)) &&
                 ((-1 < local_8 - iVar12 && (iVar5 = local_c, local_8 - iVar12 < iVar3))))
              goto LAB_005e221a;
            }
            else {
              iVar5 = iVar8;
              if ((((local_c + iVar8 < 0) || (iVar4 <= local_c + iVar8)) || (iVar9 < 0)) ||
                 (iVar3 <= iVar9)) {
                iVar9 = (iVar4 - local_28) - local_c;
              }
              else {
LAB_005e221a:
                iVar9 = iVar8 - local_28;
              }
              puVar13 = (undefined4 *)(iVar1 + (local_28 + iVar5) * -2);
              puVar2 = (undefined4 *)(iVar1 + iVar9 * 2);
              if (puVar13 <= puVar2) {
                uVar7 = (int)puVar2 + (2 - (int)puVar13);
                for (uVar11 = uVar7 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                  *puVar13 = CONCAT22((undefined2)param_6,(undefined2)param_6);
                  puVar13 = puVar13 + 1;
                }
                for (uVar7 = (uint)((uVar7 >> 1 & 1) != 0); param_1 = local_10, uVar7 != 0;
                    uVar7 = uVar7 - 1) {
                  *(undefined2 *)puVar13 = (undefined2)param_6;
                  puVar13 = (undefined4 *)((int)puVar13 + 2);
                }
              }
            }
            local_18 = local_c + iVar8;
            iVar9 = iVar12 + local_c;
            if (-1 < iVar9) {
              if (((iVar9 < iVar4) && (-1 < local_14 + local_8)) && (local_14 + local_8 < iVar3)) {
                if ((iVar8 + local_8 < 0) || (iVar3 <= iVar8 + local_8)) {
                  for (puVar10 = (undefined2 *)(iVar1 + (iVar12 - local_2c) * 2);
                      puVar10 <= (undefined2 *)(local_24 + iVar9 * 2); puVar10 = puVar10 + param_5)
                  {
                    *puVar10 = (undefined2)param_6;
                  }
                }
                else {
                  for (puVar10 = (undefined2 *)(iVar1 + (iVar12 - local_2c) * 2);
                      puVar10 <= (undefined2 *)(iVar1 + (local_2c + iVar12) * 2);
                      puVar10 = puVar10 + param_5) {
                    *puVar10 = (undefined2)param_6;
                  }
                }
              }
              else if (((-1 < iVar9) && (iVar9 < iVar4)) &&
                      ((-1 < iVar8 + local_8 && (iVar8 + local_8 < iVar3)))) {
                for (puVar10 = (undefined2 *)(local_20 + iVar9 * 2);
                    puVar10 <= (undefined2 *)(iVar1 + (local_2c + iVar12) * 2);
                    puVar10 = puVar10 + param_5) {
                  *puVar10 = (undefined2)param_6;
                }
              }
            }
            if ((((local_18 < 0) || (iVar4 <= local_18)) || (local_8 + iVar12 < 0)) ||
               (iVar3 <= local_8 + iVar12)) {
              if (((-1 < local_1c) && (local_1c < iVar4)) &&
                 ((-1 < local_8 + iVar12 && (local_8 + iVar12 < iVar3)))) {
                for (puVar10 = (undefined2 *)(iVar1 + ((local_28 - local_c) + iVar4) * 2);
                    (undefined2 *)(iVar1 + (local_28 - iVar8) * 2) <= puVar10;
                    puVar10 = puVar10 + -1) {
                  *puVar10 = (undefined2)param_6;
                }
              }
            }
            else if ((local_1c < 0) || (iVar4 <= local_1c)) {
              for (puVar10 = (undefined2 *)(iVar1 + (iVar8 + local_28) * 2);
                  (undefined2 *)(iVar1 + (local_28 - local_c) * 2) <= puVar10;
                  puVar10 = puVar10 + -1) {
                *puVar10 = (undefined2)param_6;
              }
            }
            else {
              for (puVar10 = (undefined2 *)(iVar1 + (local_28 + iVar8) * 2);
                  (undefined2 *)(iVar1 + (local_28 - iVar8) * 2) <= puVar10; puVar10 = puVar10 + -1)
              {
                *puVar10 = (undefined2)param_6;
              }
            }
            iVar9 = local_c - iVar12;
            if ((((iVar9 < 0) || (iVar4 <= iVar9)) || (iVar8 + local_8 < 0)) ||
               (iVar3 <= iVar8 + local_8)) {
              if (((-1 < iVar9) && (iVar9 < iVar4)) &&
                 ((-1 < local_14 + local_8 && (local_14 + local_8 < iVar3)))) {
                for (puVar10 = (undefined2 *)(local_24 + iVar9 * 2);
                    (undefined2 *)(iVar1 + (local_2c + iVar12) * -2) <= puVar10;
                    puVar10 = puVar10 + -param_5) {
                  *puVar10 = (undefined2)param_6;
                }
              }
            }
            else if (((iVar9 < 0) || (iVar4 <= iVar9)) ||
                    ((local_14 + local_8 < 0 || (iVar3 <= local_14 + local_8)))) {
              for (puVar10 = (undefined2 *)(iVar1 + (local_2c - iVar12) * 2);
                  (undefined2 *)(local_20 + iVar9 * 2) <= puVar10; puVar10 = puVar10 + -param_5) {
                *puVar10 = (undefined2)param_6;
              }
            }
            else {
              for (puVar10 = (undefined2 *)(iVar1 + (local_2c - iVar12) * 2);
                  (undefined2 *)(iVar1 + (local_2c + iVar12) * -2) <= puVar10;
                  puVar10 = puVar10 + -param_5) {
                *puVar10 = (undefined2)param_6;
              }
            }
          }
          local_3c = local_3c + 2;
          iVar9 = local_30 + 2;
          local_30 = iVar8;
        } while (iVar9 < iVar12);
      }
      (**(code **)(*param_1 + 0x24))(0x200);
      (**(code **)(*param_1 + 0x20))(1);
      local_34 = local_c - local_30;
      local_2c = local_30 + 1 + local_c;
      local_28 = local_30 + 1 + local_8;
      local_30 = local_8 - local_30;
      (**(code **)(*param_1 + 0x40))(param_6,&local_34,0);
      (**(code **)(*param_1 + 0x24))(1);
      (**(code **)(*param_1 + 0x20))(0x200);
      uVar6 = 1;
    }
    else {
      uVar6 = (**(code **)(*param_1 + 0x90))(param_2,param_3,param_4,param_5,param_6);
    }
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

