
void FUN_00429f5e(void)

{
  bool bVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  byte bVar9;
  int *piVar10;
  undefined1 local_c4 [44];
  int local_98 [4];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  int local_74;
  int local_70;
  undefined2 local_6c;
  short local_6a;
  short local_68;
  short local_66;
  short local_64;
  short local_62;
  short local_60;
  undefined2 local_5e;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  undefined2 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  iVar8 = *DAT_006e486c;
  local_14 = *(int *)(iVar8 + 0x10);
  local_10 = *(uint *)(iVar8 + 0x14);
  iVar8 = *(int *)(iVar8 + 0x20);
  if (*(int *)(local_14 + 0x10c) != 0) {
    local_6c = *(undefined2 *)(local_14 + 0x110);
    local_6a = 0;
    local_68 = 0;
    local_66 = 0;
    local_64 = 0;
    local_62 = 0;
    local_60 = 0;
    local_c = FUN_004102e1();
    local_8 = 0;
    if (0 < local_c) {
      do {
        puVar3 = (undefined4 *)FUN_004102ab(local_8);
        iVar4 = FUN_0044097d(*puVar3);
        if (iVar4 != 0) {
          local_6a = local_6a + 1;
          if (*(short *)(iVar4 + 0x600) < 0x12) {
            bVar9 = 2;
          }
          else {
            bVar9 = 0;
          }
          bVar7 = *(byte *)(iVar4 + 0x60e) & 1 | bVar9;
          if (bVar7 == 0) {
            local_68 = local_68 + 1;
          }
          else if (bVar7 == 1) {
            local_66 = local_66 + 1;
          }
          else if (bVar7 == 2) {
            local_64 = local_64 + 1;
          }
          else if (bVar7 == 3) {
            local_62 = local_62 + 1;
          }
          if ((bVar9 == 0) && (*(short *)(iVar4 + 0x5fc) != 0)) {
            local_60 = local_60 + 1;
          }
        }
        local_8 = local_8 + 1;
      } while (local_8 < local_c);
    }
    FUN_00416780();
    FUN_00416618(local_c4);
    local_5e = FUN_005f94bd();
    local_5c = *(undefined4 *)(iVar8 + 0xa0);
    local_58 = *(undefined4 *)(iVar8 + 0xa4);
    local_54 = FUN_004096c2();
    local_52 = FUN_0060b848();
    local_50 = FUN_00416847();
    local_4e = FUN_004167a5();
    local_4c = FUN_00416890();
    local_4a = FUN_004168ca();
    local_48 = FUN_0060b844();
    piVar10 = local_98;
    for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar10 = 0;
      piVar10 = piVar10 + 1;
    }
    FUN_0046dbf4(local_98);
    local_44 = local_98[1];
    local_40 = local_88;
    local_3c = local_98[3];
    local_38 = local_84;
    local_34 = local_80;
    local_30 = local_98[2] + local_98[0];
    local_2c = local_7c;
    local_28 = FUN_0046d9e5();
    local_1c = FUN_004102f3();
    local_70 = DAT_006c4388;
    local_24 = 0;
    local_22 = 0;
    piVar10 = *(int **)(local_18 + 0x148);
    local_20 = 0;
    local_1e = 0;
    iVar8 = local_18;
    for (; piVar10 != *(int **)(iVar8 + 0x14c); piVar10 = piVar10 + 1) {
      if (*piVar10 != 0) {
        uVar5 = FUN_00401f73();
        cVar2 = FUN_00410285(uVar5);
        local_10 = (uint)(cVar2 != '\0');
        local_78 = FUN_004652f7();
        local_8 = 0;
        iVar8 = local_18;
        if (0 < local_78) {
          do {
            local_c = FUN_00465300(local_8);
            iVar8 = FUN_0042573e(local_c);
            if (iVar8 != 0) {
              uVar5 = FUN_00401f73();
              uVar6 = FUN_00410285(uVar5);
              if ((uVar6 & 0xff) != local_10) {
                local_74 = FUN_0046518a(local_c,0);
                iVar8 = FUN_00465062(local_c);
                if ((iVar8 < 2) || (iVar8 = FUN_0046518a(local_c,1), iVar8 == 0)) {
                  bVar1 = false;
                }
                else {
                  bVar1 = true;
                }
                if (local_70 <= local_74) {
                  if (local_10 == 0) {
                    local_1e = local_1e + 1;
                  }
                  else {
                    local_20 = local_20 + 1;
                  }
                }
                if (bVar1) {
                  if (local_10 == 0) {
                    local_22 = local_22 + 1;
                  }
                  else {
                    local_24 = local_24 + 1;
                  }
                }
              }
            }
            local_8 = local_8 + 1;
            iVar8 = local_18;
          } while (local_8 < local_78);
        }
      }
    }
    iVar8 = FUN_00410a3c();
    if (iVar8 != 0) {
      FUN_00410ffa(&local_6c);
    }
  }
  return;
}

