
void __fastcall FUN_005d0fb5(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint extraout_ECX;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined1 local_64 [32];
  undefined4 local_44 [9];
  uint local_20;
  uint *local_1c;
  undefined4 local_18;
  uint *local_14;
  int local_10;
  uint *local_c;
  uint local_8;
  
  if ((*(int *)(param_1 + 0x7c) != *(int *)(param_1 + 0x80)) &&
     (*(int *)(param_1 + 0x94) != *(int *)(param_1 + 0x98))) {
    FUN_0040812f(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc));
    piVar1 = (int *)(param_1 + 0xd4);
    if (*(int *)(param_1 + 0xd4) == *(int *)(param_1 + 0xd8)) {
      FUN_005d157f(*(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xec) >> 2);
    }
    else {
      uVar6 = 0;
      if ((*(int *)(param_1 + 0xd8) - *piVar1) / 0xc != 0) {
        local_8 = 0;
        do {
          FUN_005bd82a(*(undefined4 *)(local_8 + *piVar1),((undefined4 *)(local_8 + *piVar1))[1]);
          local_8 = local_8 + 0xc;
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)((*(int *)(param_1 + 0xd8) - *piVar1) / 0xc));
      }
    }
    piVar1 = (int *)(param_1 + 0xe0);
    if (*(int *)(param_1 + 0xe0) == *(int *)(param_1 + 0xe4)) {
      local_14 = *(uint **)(param_1 + 0xf0);
      local_10 = *(int *)(param_1 + 0xec);
      uVar2 = FUN_005d124f();
      FUN_005d1682((int)local_14 - local_10 >> 2,uVar2);
      uVar6 = extraout_ECX;
    }
    else {
      uVar6 = 0;
      if (*(int *)(param_1 + 0xe4) - *piVar1 >> 3 != 0) {
        do {
          iVar7 = *piVar1;
          *(undefined4 *)(iVar7 + uVar6 * 8) = 0xffffffff;
          *(undefined4 *)(iVar7 + 4 + uVar6 * 8) = 0;
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)(*(int *)(param_1 + 0xe4) - *piVar1 >> 3));
      }
    }
    local_8 = 0;
    if (*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) >> 4 != 0) {
      local_10 = 0;
      do {
        puVar8 = (uint *)(local_10 + *(int *)(param_1 + 0x7c));
        local_20 = puVar8[3];
        local_14 = (uint *)CONCAT22((short)(uVar6 >> 0x10),(short)*puVar8);
        local_c = (uint *)(local_20 * 0xc);
        FUN_005d15e7(&local_14);
        local_1c = puVar8 + 1;
        local_14 = (uint *)CONCAT22((short)((uint)local_1c >> 0x10),(short)*local_1c);
        FUN_005d15e7(&local_14);
        local_14 = puVar8 + 2;
        local_18 = CONCAT22((short)((uint)local_14 >> 0x10),(short)*local_14);
        FUN_005d15e7(&local_18);
        local_c = local_14;
        if (*local_1c <= *local_14) {
          local_c = local_1c;
        }
        if (*puVar8 <= *local_c) {
          local_c = puVar8;
        }
        local_20 = local_20 * 8;
        puVar3 = (uint *)(local_20 + *(int *)(param_1 + 0xe0));
        puVar4 = local_c;
        if (*puVar3 <= *local_c) {
          puVar4 = puVar3;
        }
        *puVar3 = *puVar4;
        puVar4 = local_14;
        if (*local_14 <= *local_1c) {
          puVar4 = local_1c;
        }
        if (*puVar8 < *puVar4) {
          puVar8 = puVar4;
        }
        puVar4 = (uint *)(local_20 + 4 + *(int *)(param_1 + 0xe0));
        if (*puVar8 <= *puVar4) {
          puVar8 = puVar4;
        }
        uVar6 = *puVar8;
        local_8 = local_8 + 1;
        local_10 = local_10 + 0x10;
        *puVar4 = uVar6;
      } while (local_8 < (uint)(*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) >> 4));
    }
    local_8 = 0;
    if ((*(int *)(param_1 + 0x98) - *(int *)(param_1 + 0x94)) / 0x18 != 0) {
      local_10 = 0;
      do {
        iVar7 = *(int *)(param_1 + 0x94);
        puVar5 = (undefined4 *)
                 FUN_005d0e65(local_64,*(int *)(param_1 + 100) + *(int *)(local_10 + iVar7) * 0xc,
                              *(int *)(param_1 + 0x70) + *(int *)(local_10 + 4 + iVar7) * 8,
                              local_10 + 8 + iVar7);
        puVar9 = local_44;
        for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar9 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar9 = puVar9 + 1;
        }
        FUN_005d1507(local_44);
        local_8 = local_8 + 1;
        local_10 = local_10 + 0x18;
      } while (local_8 < (uint)((*(int *)(param_1 + 0x98) - *(int *)(param_1 + 0x94)) / 0x18));
    }
  }
  *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) & 0xfffffffb;
  return;
}

