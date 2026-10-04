
void FUN_0049f015(void)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(DAT_006e486c + 0x34) == 2) {
    DAT_006c66ec = 2;
  }
  local_10 = 0;
  do {
    iVar9 = local_10;
    iVar7 = local_10 * 0x20;
    iVar5 = local_10 * 0x40;
    local_8 = 0;
    do {
      iVar2 = local_8;
      local_c = 0;
      uVar3 = __ftol();
      local_c = 0;
      (&DAT_006eeaf8)[iVar2 + iVar7] = uVar3;
      uVar3 = __ftol();
      (&DAT_006ee2f8)[iVar2 + iVar5] = uVar3;
      local_c = 1;
      piVar6 = &local_10;
      if (iVar9 < 2) {
        piVar6 = &local_c;
      }
      local_c = *piVar6 + -1;
      uVar3 = __ftol();
      (&DAT_006edef8)[iVar2 + iVar7] = uVar3;
      local_8 = iVar2 + 1;
    } while (local_8 < 0x20);
    local_10 = iVar9 + 1;
  } while (local_10 < 0x20);
  if (*(int *)(DAT_006e486c + 0x34) == 2) {
    puVar8 = &DAT_006ee2f8;
    local_10 = 0;
    do {
      local_8 = 0;
      do {
        uVar3 = __ftol();
        iVar9 = local_8 + 1;
        puVar8[local_8] = uVar3;
        local_8 = iVar9;
      } while (iVar9 < 0x40);
      puVar8 = puVar8 + 0x40;
    } while ((int)puVar8 < 0x6eeaf8);
  }
  if (*(int *)(DAT_006e486c + 0x34) == 1) {
    iVar9 = 0;
    do {
      uVar4 = FUN_0049f1f4(iVar9 << 0x13);
      bVar1 = DAT_006c66ec;
      (&DAT_006eef98)[iVar9] = uVar4;
      uVar4 = FUN_0049f1f4((iVar9 << (bVar1 & 0x1f)) << 8);
      (&DAT_006eef18)[iVar9] = uVar4;
      uVar3 = FUN_0049f1f4(iVar9 << 3);
      (&DAT_006eeef8)[iVar9] = uVar3;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x20);
  }
  else {
    iVar9 = 0;
    do {
      uVar4 = FUN_0049f21b((iVar9 << (DAT_006c66ec & 0x1f)) << 8);
      (&DAT_006eef18)[iVar9] = uVar4;
      if (iVar9 < 0x20) {
        uVar4 = FUN_0049f21b(iVar9 << 0x13);
        (&DAT_006eef98)[iVar9] = uVar4;
        uVar3 = FUN_0049f21b(iVar9 << 3);
        (&DAT_006eeef8)[iVar9] = uVar3;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x40);
  }
  FUN_0049f242();
  return;
}

