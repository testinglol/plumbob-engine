
undefined4 __thiscall
FUN_005e24c1(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  int iVar9;
  undefined2 uVar10;
  int iVar11;
  undefined4 *puVar12;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar6 = (param_3 - param_2) + param_4;
  if ((((((param_2 < 0x1001) && (-0x1001 < param_2)) && (param_3 < 0x1001)) &&
       ((-0x1001 < param_3 && (param_4 < 0x1001)))) &&
      ((-0x1001 < param_4 && ((iVar6 < 0x1001 && (-0x1001 < iVar6)))))) && (param_2 <= param_4)) {
    if ((((param_2 < 0) || (param_1[7] <= param_2)) || (param_4 < 0)) ||
       (((param_1[7] <= param_4 || (param_3 < 0)) ||
        ((param_1[8] <= param_3 || ((iVar6 < 0 || (param_1[8] <= iVar6)))))))) {
      uVar5 = (**(code **)(*param_1 + 0x8c))(param_2,param_3,param_4,iVar6,param_6);
    }
    else {
      uVar3 = (**(code **)(*param_1 + 0xd0))();
      uVar3 = uVar3 >> 1;
      iVar4 = (param_4 - param_2) / 2;
      param_3 = iVar4 + param_3;
      iVar11 = (param_4 + param_2) / 2;
      local_10 = iVar11;
      local_8 = uVar3;
      iVar6 = (**(code **)(*param_1 + 0xcc))();
      local_1c = 0;
      local_18 = 0;
      local_28 = 3;
      iVar6 = iVar6 + (param_3 * uVar3 + iVar11) * 2;
      local_2c = 1 - iVar4;
      iVar11 = iVar4 * uVar3;
      local_24 = iVar4 * -2 + 5;
      uVar10 = (undefined2)param_6;
      *(undefined2 *)(iVar11 * 2 + iVar6) = uVar10;
      *(undefined2 *)(iVar6 + iVar11 * -2) = uVar10;
      *(undefined2 *)(iVar6 + iVar4 * -2) = uVar10;
      *(undefined2 *)(iVar4 * 2 + iVar6) = uVar10;
      local_20 = iVar4;
      if (1 < iVar4) {
        do {
          iVar4 = local_1c + 1;
          local_18 = local_18 + local_8;
          if (local_2c < 0) {
            iVar2 = local_24 + 2;
            iVar9 = local_28;
          }
          else {
            iVar11 = iVar11 - local_8;
            local_20 = local_20 + -1;
            puVar12 = (undefined4 *)(iVar6 + (iVar4 + iVar11) * -2);
            puVar1 = (undefined4 *)(iVar6 + (iVar4 - iVar11) * 2);
            if (puVar12 < puVar1) {
              uVar3 = (int)puVar1 + (1 - (int)puVar12);
              for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *puVar12 = CONCAT22(uVar10,uVar10);
                puVar12 = puVar12 + 1;
              }
              for (uVar3 = (uint)((uVar3 >> 1 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
                *(undefined2 *)puVar12 = uVar10;
                puVar12 = (undefined4 *)((int)puVar12 + 2);
              }
            }
            for (puVar8 = (undefined2 *)((iVar4 + iVar11) * 2 + iVar6);
                (undefined2 *)(iVar6 + (iVar11 - iVar4) * 2) < puVar8; puVar8 = puVar8 + -1) {
              *puVar8 = uVar10;
            }
            local_c = (local_20 + local_18) * 2;
            for (puVar8 = (undefined2 *)(iVar6 + (local_18 - local_20) * 2);
                (undefined2 *)(iVar6 + (local_20 + local_18) * -2) < puVar8;
                puVar8 = puVar8 + -local_8) {
              *puVar8 = uVar10;
            }
            for (puVar8 = (undefined2 *)(iVar6 + (local_20 - local_18) * 2); iVar2 = local_24 + 4,
                local_14 = iVar11, iVar9 = local_24, puVar8 < (undefined2 *)(local_c + iVar6);
                puVar8 = puVar8 + local_8) {
              *puVar8 = uVar10;
            }
          }
          local_24 = iVar2;
          local_2c = local_2c + iVar9;
          local_28 = local_28 + 2;
          iVar9 = local_1c + 2;
          local_1c = iVar4;
        } while (iVar9 < local_20);
      }
      (**(code **)(*param_1 + 0x24))(0x200);
      (**(code **)(*param_1 + 0x20))(1);
      local_20 = local_10 - local_1c;
      local_18 = local_1c + 1 + local_10;
      local_14 = local_1c + 1 + param_3;
      local_1c = param_3 - local_1c;
      (**(code **)(*param_1 + 0x4c))(param_6,&local_20);
      (**(code **)(*param_1 + 0x24))(1);
      (**(code **)(*param_1 + 0x20))(0x200);
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

