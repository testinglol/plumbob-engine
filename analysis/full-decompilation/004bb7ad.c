
undefined4 __fastcall FUN_004bb7ad(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004bb6c5();
  cVar3 = FUN_004bb700();
  if (cVar3 == '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 0xc);
    iVar2 = *(int *)(*(int *)(param_1 + 0x1c) + 0x10);
    bVar7 = (byte)*(undefined4 *)(param_1 + 0xc);
    iVar8 = 0x40 >> (3 - bVar7 & 0x1f);
    iVar9 = (0x3a << (bVar7 - 1 & 0x1f)) + (8 << (bVar7 & 0x1f));
    iVar11 = 0x10 << (bVar7 - 1 & 0x1f);
    if (*(int *)(param_1 + 0x14) == 0) {
      local_20 = (4 << (bVar7 & 0x1f)) + -1;
    }
    else {
      local_20 = 0;
    }
    local_10 = 0;
    if (-1 < *(int *)(param_1 + 4)) {
      local_1c = 0;
      do {
        iVar5 = FUN_0049bf45();
        local_18 = FUN_004bb786(local_10);
        local_c = 0;
        if (0 < iVar9) {
          do {
            local_8 = 0;
            if (0 < iVar8) {
              do {
                bVar7 = 3 - (char)*(undefined4 *)(param_1 + 0xc);
                iVar10 = local_8 << (bVar7 & 0x1f);
                if (*(int *)(param_1 + 0x14) == 1) {
                  iVar6 = -((iVar10 + 1) / 2);
                }
                else {
                  iVar6 = (*(int *)(param_1 + 0x14) + iVar10) / 2;
                }
                iVar6 = (local_c - local_20 << (bVar7 & 0x1f)) + iVar6;
                if ((-1 < iVar6) && (iVar6 < iVar2)) {
                  *(undefined1 *)(local_18 + local_8) =
                       *(undefined1 *)(iVar6 * iVar1 + iVar10 + iVar5 + local_1c);
                }
                local_8 = local_8 + 1;
              } while (local_8 < iVar8);
            }
            local_c = local_c + 1;
            local_18 = local_18 + iVar11;
          } while (local_c < iVar9);
        }
        local_10 = local_10 + 1;
        local_1c = local_1c + 0x40;
      } while (local_10 <= *(int *)(param_1 + 4));
    }
    local_10 = -1;
    if (*(int *)(param_1 + 4) == 1 || -*(int *)(param_1 + 4) < -1) {
      local_18 = -0x40;
      do {
        iVar5 = FUN_0049bf45();
        local_1c = FUN_004bb786(local_10);
        local_c = 0;
        if (0 < iVar9) {
          do {
            local_8 = 0;
            if (0 < iVar8) {
              do {
                bVar7 = 3 - (char)*(undefined4 *)(param_1 + 0xc);
                iVar10 = local_8 << (bVar7 & 0x1f);
                if (*(int *)(param_1 + 0x14) == 1) {
                  iVar6 = -((iVar10 + 1) / 2);
                }
                else {
                  iVar6 = (iVar10 + *(int *)(param_1 + 0x14)) / 2;
                }
                iVar6 = (local_c - local_20 << (bVar7 & 0x1f)) + iVar6;
                if ((-1 < iVar6) && (iVar6 < iVar2)) {
                  *(undefined1 *)(local_1c + local_8) =
                       *(undefined1 *)(iVar6 * iVar1 + (iVar5 - local_18) + (0x3f - iVar10));
                }
                local_8 = local_8 + 1;
              } while (local_8 < iVar8);
            }
            local_c = local_c + 1;
            local_1c = local_1c + iVar11;
          } while (local_c < iVar9);
        }
        local_10 = local_10 + -1;
        local_18 = local_18 + -0x40;
      } while (-*(int *)(param_1 + 4) <= local_10);
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}

