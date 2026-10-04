
/* WARNING: Removing unreachable block (ram,0x005bdf39) */
/* WARNING: Removing unreachable block (ram,0x005bdf08) */

short FUN_005bdeb6(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  byte in_AF;
  bool bVar4;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar5;
  char local_2c [12];
  char cStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  char cStack_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  local_1c = s______________006d25b0._0_4_;
  local_18 = s______________006d25b0._4_4_;
  local_14 = s______________006d25b0._8_4_;
  cStack_10 = s______________006d25b0[0xc];
  local_2c._0_4_ = s_GenuineIntel_006723a0._0_4_;
  local_2c._4_4_ = s_GenuineIntel_006723a0._4_4_;
  local_2c._8_4_ = s_GenuineIntel_006723a0._8_4_;
  cStack_20 = s_GenuineIntel_006723a0[0xc];
  uVar5 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | 0x40
          | (uint)(in_AF & 1) * 0x10 | 4 | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar2 = uVar5 ^ 0x200000;
  bVar4 = ((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x200) != 0) * 0x200 |
           (uint)((uVar2 & 0x100) != 0) * 0x100 | (uint)((uVar2 & 0x40) != 0) * 0x40 |
           (uint)((uVar2 & 0x10) != 0) * 0x10 | (uint)((uVar2 & 4) != 0) * 4 |
           (uint)((uVar2 & 0x200000) != 0) * 0x200000 | (uint)((uVar2 & 0x40000) != 0) * 0x40000) !=
          uVar5;
  local_c = (uint)bVar4;
  if (bVar4) {
    iVar3 = cpuid_basic_info(0);
    local_1c = *(undefined4 *)(iVar3 + 4);
    local_18 = *(undefined4 *)(iVar3 + 8);
    local_14 = *(undefined4 *)(iVar3 + 0xc);
    iVar3 = 0;
    do {
      if (*(char *)((int)&local_1c + iVar3) != local_2c[iVar3]) {
        DAT_006fe57c = 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xc);
    if (0 < iVar3) {
      puVar1 = (uint *)cpuid_Version_info(1);
      local_8 = *puVar1 & 0xffff;
    }
  }
  else {
    local_8._0_2_ = FUN_005bddff();
    local_8._0_2_ = (short)local_8 << 8;
  }
  return (short)local_8;
}

