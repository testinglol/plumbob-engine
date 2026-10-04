
void FUN_004aac36(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int local_8;
  
  uVar3 = FUN_004aabcd();
  iVar6 = DAT_006f0bbc >> 1;
  local_8 = param_1[3] - param_1[1];
  iVar1 = param_1[2];
  iVar5 = DAT_006f0bcc + param_1[1] * iVar6 * 2;
  if (0 < local_8) {
    iVar2 = *param_1;
    do {
      if (iVar2 < iVar1 + -1) {
        puVar7 = (uint *)(iVar5 + iVar2 * 2);
        for (uVar4 = ((iVar1 + -1) - iVar2) + 1U >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = uVar3 << 0x10 | uVar3 & 0xffff;
          puVar7 = puVar7 + 1;
        }
      }
      iVar5 = iVar5 + iVar6 * 2;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return;
}

