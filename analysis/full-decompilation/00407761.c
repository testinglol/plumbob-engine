
void FUN_00407761(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_c;
  uint local_8;
  
  iVar4 = 0;
  do {
    uVar6 = 0;
    local_c = 0x3f;
    do {
      uVar5 = 0;
      local_8 = 0x3f;
      do {
        if (((int)local_c < 0) || ((int)local_8 < 0)) {
          iVar1 = ((iVar4 * 0x40 + uVar6) * 0x40 + uVar5) * 2;
          (&DAT_006de81c)[iVar1] = 0xff;
          (&DAT_006de81d)[iVar1] = 0xff;
        }
        else {
          uVar2 = local_8;
          uVar3 = uVar6;
          if (((iVar4 != 0) && (uVar2 = local_c, uVar3 = local_8, iVar4 != 1)) &&
             (uVar2 = uVar6, uVar3 = uVar5, iVar4 == 2)) {
            uVar2 = uVar5;
            uVar3 = local_c;
          }
          iVar1 = ((iVar4 * 0x40 + uVar6) * 0x40 + uVar5) * 2;
          (&DAT_006de81c)[iVar1] = (char)uVar2;
          (&DAT_006de81d)[iVar1] = (char)uVar3;
        }
        uVar5 = uVar5 + 1;
        local_8 = local_8 - 1;
      } while (local_8 < 0x80000000);
      uVar6 = uVar6 + 1;
      local_c = local_c - 1;
    } while (local_c < 0x80000000);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return;
}

