
void FUN_004a64cc(int *param_1,undefined4 *param_2,int param_3,undefined4 param_4,int param_5,
                 int *param_6)

{
  ushort *puVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined2 uVar10;
  int *piVar11;
  bool bVar12;
  uint local_2c;
  uint local_28;
  ushort *local_24;
  undefined2 *local_20;
  undefined2 *local_18;
  uint local_14;
  uint local_10;
  ushort *local_c;
  ushort *local_8;
  
  local_10 = 0xffffffff;
  local_20 = (undefined2 *)*param_1;
  local_24 = (ushort *)*param_2;
  puVar5 = local_20;
  piVar11 = param_1;
  local_8 = (ushort *)(param_3 + 0x10);
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          puVar9 = puVar5;
          puVar1 = local_8 + 1;
          uVar2 = *local_8;
          local_2c = uVar2 & 0x1fff;
          uVar7 = uVar2 & 0xe000;
          local_8 = puVar1;
          if ((uVar2 & 0xe000) != 0) break;
          local_c = local_24;
          local_20 = puVar9 + param_1[1];
          local_24 = local_24 + param_2[1];
          piVar11 = (int *)(*param_6 + param_5);
          local_10 = local_10 + 1;
          local_14 = 0;
          puVar5 = local_20;
          param_6 = param_6 + 1;
          local_18 = puVar9;
        }
        puVar5 = puVar9;
        if (uVar7 != 0x6000) break;
        local_c = local_c + local_2c;
        local_14 = local_14 + local_2c;
        local_18 = local_18 + local_2c;
      }
      if (uVar7 != 0x8000) break;
      if ((uVar2 & 0x1fff) != 0) {
        uVar7 = local_2c;
        do {
          local_18 = puVar9;
          puVar9 = local_20 + param_1[1];
          puVar1 = local_24 + param_2[1];
          local_c = local_24;
          uVar7 = uVar7 - 1;
          local_24 = puVar1;
          local_20 = puVar9;
        } while (uVar7 != 0);
      }
      local_10 = local_10 + local_2c;
      puVar5 = puVar9;
    }
    if (uVar7 != 0xc000) {
      return;
    }
    if ((uVar2 & 0x1fff) != 0) {
      local_8 = (ushort *)((int)puVar1 + local_2c);
      local_28 = local_14;
      do {
        local_28 = local_28 + 1;
        if ((int)piVar11 <= (int)(uint)*local_c) {
          if ((((local_14 & 3) == 0) && ((local_10 & 3) == 0)) ||
             (((local_14 & 3) == 2 && (((byte)local_10 & 3) == 2)))) {
            bVar4 = true;
          }
          else {
            bVar4 = false;
          }
          uVar10 = 0;
          iVar6 = ((int)local_28 >> 1) + local_10;
          iVar8 = local_10 - ((int)local_14 >> 1);
          sVar3 = *(short *)(param_3 + 2);
          if (sVar3 == 0x10) {
            if ((iVar6 != 8) && (iVar8 != -7)) {
              if (iVar6 != 0x17) {
                bVar12 = iVar8 == 8;
LAB_004a65e8:
                if (!bVar12) goto LAB_004a65fa;
              }
              goto LAB_004a65ea;
            }
LAB_004a65ee:
            bVar4 = true;
            uVar10 = 0xffff;
LAB_004a65fa:
            if (!bVar4) goto LAB_004a660c;
          }
          else {
            if (sVar3 == 0x20) {
              if ((iVar6 == 0x10) || (iVar8 == -0xf)) goto LAB_004a65ee;
              if (iVar6 != 0x2f) {
                bVar12 = iVar8 == 0x10;
                goto LAB_004a65e8;
              }
            }
            else {
              if (sVar3 != 0x40) goto LAB_004a65fa;
              if ((iVar6 == 0x20) || (iVar8 == -0x1f)) goto LAB_004a65ee;
              if (iVar6 != 0x5f) {
                bVar12 = iVar8 == 0x20;
                goto LAB_004a65e8;
              }
            }
LAB_004a65ea:
            uVar10 = 0;
          }
          *local_18 = uVar10;
          *local_c = (ushort)piVar11;
        }
LAB_004a660c:
        local_18 = local_18 + 1;
        local_c = local_c + 1;
        local_14 = local_14 + 1;
        local_2c = local_2c - 1;
      } while (local_2c != 0);
    }
    local_8 = (ushort *)((int)local_8 + ((uint)local_8 & 1));
  } while( true );
}

