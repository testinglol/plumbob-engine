
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062f56b(undefined1 *param_1)

{
  short sVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  float *pfVar7;
  float *pfVar8;
  short *psVar9;
  int extraout_ECX;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined1 local_5a28 [4608];
  undefined1 local_4828 [4608];
  undefined1 local_3628 [4608];
  undefined1 local_2428 [4608];
  undefined1 local_1228 [2304];
  float local_928 [19];
  float local_8dc [557];
  float local_28;
  float *local_24;
  undefined1 *local_20;
  undefined4 uStack_1c;
  undefined1 *local_18;
  float *local_14;
  undefined1 *puVar14;
  
  FUN_00636080();
  if (*(char *)(extraout_ECX + 0x4a12) == '\0') {
    *(int *)(extraout_ECX + 0x24a8) = *(int *)(extraout_ECX + 0x24a8) + 0x10;
  }
  local_14 = (float *)0x62f5b0;
  FUN_0062cd77();
  if (*(char *)(extraout_ECX + 0x4a0e) == '\0') {
    iVar3 = ((*(char *)(extraout_ECX + 0x4a16) != '\x03') - 1 & 0xfffffff1) + 0x20;
  }
  else {
    iVar3 = ((*(char *)(extraout_ECX + 0x4a16) != '\x03') - 1 & 0xfffffff8) + 0x11;
  }
  iVar3 = (*(int *)(extraout_ECX + 0x2498) - iVar3) -
          ((-(uint)(*(char *)(extraout_ECX + 0x4a12) != '\0') & 0xfffffffe) + 2);
  if (0 < iVar3) {
    do {
      uVar4 = *(uint *)((*(int *)(extraout_ECX + 0x24a8) >> 3) + *(int *)(extraout_ECX + 0x24a4));
      local_14 = (float *)((uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 |
                           uVar4 << 0x18) >>
                           (-((byte)*(int *)(extraout_ECX + 0x24a8) & 7) - 8 & 0x1f) & _DAT_0067bb74
                          );
      *(int *)(extraout_ECX + 0x24a8) = *(int *)(extraout_ECX + 0x24a8) + 8;
      local_18 = (undefined1 *)0x62f645;
      FUN_0062ccf9();
    } while (local_14 != (float *)0x1);
  }
  local_14 = (float *)0x62f655;
  uVar4 = FUN_0062cc3d();
  uVar4 = uVar4 >> 3;
  local_14 = (float *)0x62f668;
  uVar5 = FUN_0062cc3d();
  if ((uVar5 & 7) != 0) {
    local_14 = (float *)(8 - (uVar5 & 7));
    local_18 = (undefined1 *)0x62f67e;
    FUN_0062cc47();
    uVar4 = uVar4 + 1;
  }
  iVar12 = *(int *)(extraout_ECX + 0x4a08);
  iVar3 = iVar12 + iVar3;
  *(int *)(extraout_ECX + 0x4a08) = iVar3;
  iVar12 = (iVar12 - *(int *)(extraout_ECX + 0x34cc)) - uVar4;
  if (iVar12 < 0) {
    uVar6 = 0xffffffff;
  }
  else {
    if (0x1000 < uVar4) {
      local_14 = (float *)0x1000;
      *(int *)(extraout_ECX + 0x4a08) = iVar3 + -0x1000;
      local_18 = (undefined1 *)0x62f6c8;
      FUN_0062cd49();
    }
    if (0 < iVar12) {
      do {
        local_14 = (float *)0x8;
        local_18 = (undefined1 *)0x62f6d9;
        FUN_0062cc47();
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    puVar14 = (undefined1 *)0x0;
    if (*(char *)(extraout_ECX + 0x4a10) != '\0') {
      do {
        uVar4 = 0;
        if (*(int *)(extraout_ECX + 0x4a40) != 0) {
          puVar13 = local_3628;
          do {
            local_14 = (float *)0x62f708;
            uVar6 = FUN_0062cc3d();
            local_18 = (undefined1 *)uVar4;
            local_14 = (float *)puVar14;
            if (*(char *)(extraout_ECX + 0x4a11) == '\x01') {
              uStack_1c = (undefined1 *)0x62f71f;
              FUN_0062dafd();
            }
            else {
              uStack_1c = (undefined1 *)0x62f726;
              FUN_0062e335();
            }
            local_18 = local_1228;
            local_24 = (float *)0x62f73b;
            local_20 = (undefined1 *)uVar4;
            uStack_1c = puVar14;
            local_14 = (float *)uVar6;
            FUN_0062e473();
            local_14 = (float *)local_1228;
            local_24 = (float *)0x62f74e;
            local_20 = puVar13;
            uStack_1c = (undefined1 *)uVar4;
            local_18 = puVar14;
            FUN_0062e67b();
            uVar4 = uVar4 + 1;
            puVar13 = puVar13 + 0x900;
          } while (uVar4 < *(uint *)(extraout_ECX + 0x4a40));
        }
        local_14 = (float *)local_5a28;
        local_18 = local_3628;
        uStack_1c = local_2428;
        local_24 = (float *)0x62f77c;
        local_20 = puVar14;
        FUN_0062eae1();
        uVar4 = 0;
        if (*(int *)(extraout_ECX + 0x4a40) != 0) {
          local_20 = local_2428;
          do {
            local_14 = local_928;
            local_24 = (float *)0x62f7bf;
            uStack_1c = (undefined1 *)uVar4;
            local_18 = puVar14;
            FUN_0062e939();
            local_14 = local_928;
            local_20 = (undefined1 *)0x62f7d3;
            uStack_1c = (undefined1 *)uVar4;
            local_18 = puVar14;
            FUN_0062f317();
            local_14 = local_928;
            local_20 = (undefined1 *)0x62f7e7;
            uStack_1c = (undefined1 *)uVar4;
            local_18 = puVar14;
            FUN_0062f3c5();
            pfVar10 = local_8dc;
            iVar3 = 0x10;
            do {
              local_14 = (float *)&DAT_00000009;
              iVar12 = 9;
              pfVar7 = pfVar10;
              do {
                *pfVar7 = -*pfVar7;
                pfVar7 = pfVar7 + 2;
                iVar12 = iVar12 + -1;
              } while (iVar12 != 0);
              pfVar10 = pfVar10 + 0x24;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            pfVar10 = local_928;
            if (DAT_006ff868 == 0) {
              iVar3 = 0x12;
              pfVar7 = local_24;
              do {
                local_18 = (undefined1 *)0x20;
                pfVar8 = pfVar7;
                pfVar11 = pfVar10;
                do {
                  fVar2 = *pfVar11;
                  pfVar11 = pfVar11 + 0x12;
                  *pfVar8 = fVar2;
                  pfVar8 = pfVar8 + 1;
                  local_18 = (undefined1 *)((int)local_18 + -1);
                } while (local_18 != (undefined1 *)0x0);
                pfVar7 = pfVar7 + 0x40;
                pfVar10 = pfVar10 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            else {
              local_18 = (undefined1 *)0x12;
              do {
                iVar3 = 0x20;
                psVar9 = (short *)local_14;
                pfVar7 = pfVar10;
                do {
                  local_28 = *pfVar7 * _DAT_00687e40;
                  sVar1 = (short)ROUND(*pfVar7 * _DAT_00687e40);
                  uStack_1c = (undefined1 *)CONCAT22(sVar1,(undefined2)uStack_1c);
                  pfVar7 = pfVar7 + 0x12;
                  *psVar9 = sVar1;
                  psVar9 = psVar9 + 1;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
                local_14 = (float *)((int)local_14 + 0x80);
                pfVar10 = pfVar10 + 1;
                local_18 = (undefined1 *)((int)local_18 + -1);
              } while (local_18 != (undefined1 *)0x0);
            }
            uVar4 = uVar4 + 1;
            local_20 = (undefined1 *)((int)local_20 + 0x900);
            local_24 = local_24 + 0x20;
          } while (uVar4 < *(uint *)(extraout_ECX + 0x4a40));
        }
        puVar13 = local_4828;
        if (DAT_006ff868 == 0) {
          iVar3 = 0x12;
          do {
            local_18 = param_1;
            uStack_1c = (undefined1 *)0x62f8d8;
            local_14 = (float *)puVar13;
            FUN_00630fee();
            puVar13 = puVar13 + 0x100;
            iVar3 = iVar3 + -1;
            param_1 = param_1 + *(int *)(extraout_ECX + 0x4a1c) * 2;
          } while (iVar3 != 0);
        }
        else {
          iVar3 = 0x12;
          do {
            local_18 = param_1;
            uStack_1c = (undefined1 *)0x62f8ff;
            local_14 = (float *)puVar13;
            FUN_0062f99c();
            puVar13 = puVar13 + 0x80;
            iVar3 = iVar3 + -1;
            param_1 = param_1 + *(int *)(extraout_ECX + 0x4a1c) * 2;
          } while (iVar3 != 0);
        }
        puVar14 = puVar14 + 1;
      } while (puVar14 < (undefined1 *)(uint)*(byte *)(extraout_ECX + 0x4a10));
    }
    uVar6 = 0;
  }
  return uVar6;
}

