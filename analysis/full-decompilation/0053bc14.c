
void FUN_0053bc14(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  int *local_1c;
  int *local_18;
  int local_14;
  uint *local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0;
  local_14 = 0;
  local_18 = &DAT_006f45d4;
  local_10 = &DAT_006f4624;
  local_1c = &DAT_006f4660;
  do {
    _memset(local_10 + -1,0,0x100);
    local_c = 0;
    do {
      uVar1 = 1 << ((byte)local_c & 0x1f);
      if (uVar1 == 0x20) {
        if ((local_8 & 1) == 0) {
          local_1c[0x10] = 0x20;
        }
        else {
          local_1c[0x10] = 0x10;
        }
      }
      else if (uVar1 == 0x10) {
        *local_1c = (-(uint)((local_8 & 1) != 0) & 0x10) + 0x10;
      }
      else {
        uVar2 = uVar1;
        uVar7 = local_8;
        if (0x6f4660 < (int)local_1c) {
          do {
            uVar2 = uVar2 * 2;
            if (8 < uVar2) {
              uVar2 = 1;
            }
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        *(uint *)(&DAT_006f4620 + (local_14 + uVar1) * 4) = uVar2;
      }
      local_c = local_c + 1;
    } while (local_c < 6);
    uVar1 = 1;
    puVar5 = local_10;
    do {
      iVar4 = 0;
      if (*puVar5 == 0) {
        do {
          uVar2 = 1 << ((byte)iVar4 & 0x1f);
          if ((uVar2 & uVar1) != 0) {
            *puVar5 = *puVar5 | *(uint *)(&DAT_006f4620 + (local_14 + uVar2) * 4);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 6);
      }
      uVar1 = uVar1 + 1;
      puVar5 = puVar5 + 1;
    } while ((int)uVar1 < 0x40);
    _memset(local_18 + -1,0,0x14);
    iVar4 = 1;
    piVar6 = local_18;
    do {
      iVar3 = local_8 + iVar4;
      if (4 < iVar3) {
        iVar3 = iVar4 + -4 + local_8;
      }
      *piVar6 = iVar3;
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 < 5);
    local_8 = local_8 + 1;
    local_10 = local_10 + 0x40;
    local_14 = local_14 + 0x40;
    local_18 = local_18 + 5;
    local_1c = local_1c + 0x40;
  } while ((int)local_1c < 0x6f4a60);
  return;
}

