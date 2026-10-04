
void __thiscall FUN_0062e08d(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint local_20 [4];
  byte *local_10;
  undefined *local_c;
  int local_8;
  
  iVar6 = param_2;
  cVar1 = *(char *)(param_1 + 0x4a17);
  iVar8 = 0;
  iVar10 = param_3 * 0x48;
  iVar2 = param_2 * 0xa0 + iVar10;
  uVar4 = *(uint *)(iVar2 + 0x34f0 + param_1);
  if (*(int *)(iVar2 + 0x34f8 + param_1) == 2) {
    iVar2 = *(int *)(iVar2 + param_1 + 0x34fc);
    if (iVar2 == 0) {
      param_2 = 1;
    }
    else {
      param_2 = (-(uint)(iVar2 != 1) & 0xfffffffe) + 2;
    }
  }
  else {
    param_2 = 0;
  }
  if (((cVar1 != '\x01') && (cVar1 != '\x03')) || (iVar6 != 1)) {
    if (uVar4 < 400) {
      local_20[0] = (uVar4 >> 4) / 5;
      local_20[1] = (uVar4 >> 4) % 5;
      local_20[2] = uVar4 >> 2 & 3;
      local_20[3] = uVar4 & 3;
      iVar8 = 0;
      *(undefined4 *)((iVar6 * 5 + 0x1a9) * 0x20 + iVar10 + param_1) = 0;
    }
    else if (uVar4 < 500) {
      uVar3 = uVar4 - 400 >> 2;
      local_20[3] = 0;
      local_20[0] = uVar3 / 5;
      local_20[1] = uVar3 % 5;
      local_20[2] = uVar4 & 3;
      *(undefined4 *)((iVar6 * 5 + 0x1a9) * 0x20 + iVar10 + param_1) = 0;
      iVar8 = 1;
    }
    else if (uVar4 < 0x200) {
      local_20[2] = 0;
      local_20[3] = 0;
      local_20[0] = (uVar4 - 500) / 3;
      *(undefined4 *)((iVar6 * 5 + 0x1a9) * 0x20 + iVar10 + param_1) = 1;
      local_20[1] = (uVar4 - 500) % 3;
      iVar8 = 2;
    }
  }
  if (((cVar1 == '\x01') || (cVar1 == '\x03')) && (iVar6 == 1)) {
    uVar4 = uVar4 >> 1;
    if (uVar4 < 0xb4) {
      local_20[3] = 0;
      local_20[0] = uVar4 / 0x24;
      local_20[1] = (uint)(((ulonglong)uVar4 % 0x24) / 6);
      *(undefined4 *)(iVar10 + 0x35c0 + param_1) = 0;
      iVar8 = 3;
      local_20[2] = (uint)(((ulonglong)uVar4 % 0x24) % 6);
    }
    else if (uVar4 < 0xf4) {
      local_20[3] = 0;
      iVar8 = 4;
      local_20[0] = uVar4 + 0xc >> 4 & 3;
      *(undefined4 *)(iVar10 + 0x35c0 + param_1) = 0;
      local_20[1] = uVar4 - 4 >> 2 & 3;
      local_20[2] = uVar4 & 3;
    }
    else {
      if (0xfe < uVar4) goto LAB_0062e2b5;
      local_20[0] = (uVar4 - 0xf4) / 3;
      iVar8 = 5;
      local_20[2] = 0;
      local_20[3] = 0;
      *(undefined4 *)(iVar10 + 0x35c0 + param_1) = 0;
      local_20[1] = (uVar4 - 0xf4) % 3;
    }
    local_20[3] = 0;
  }
LAB_0062e2b5:
  local_8 = 0;
  param_3 = 0;
  puVar11 = &DAT_006ff870;
  for (iVar6 = 0x2d; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  puVar9 = local_20;
  local_c = &UNK_00687d74 + (param_2 + iVar8 * 3) * 4;
  do {
    param_2 = 0;
    pbVar7 = local_c + param_3;
    local_10 = pbVar7;
    if (*pbVar7 != 0) {
      puVar11 = &DAT_006ff870 + local_8;
      do {
        uVar5 = 0;
        if (*puVar9 != 0) {
          uVar5 = FUN_0062cc47(*puVar9);
          pbVar7 = local_10;
        }
        local_8 = local_8 + 1;
        *puVar11 = uVar5;
        puVar11 = puVar11 + 1;
        param_2 = param_2 + 1;
      } while (param_2 < *pbVar7);
    }
    param_3 = param_3 + 1;
    puVar9 = puVar9 + 1;
  } while (param_3 < 4);
  return;
}

