
/* WARNING: Removing unreachable block (ram,0x005bdfde) */
/* WARNING: Removing unreachable block (ram,0x005bdfad) */

undefined4 FUN_005bdf5b(void)

{
  uint uVar1;
  int iVar2;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar3;
  char local_2c [16];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  
  local_8 = 0;
  local_2c._0_4_ = s_GenuineIntel_006723a0._0_4_;
  local_2c._4_4_ = s_GenuineIntel_006723a0._4_4_;
  local_2c._8_4_ = s_GenuineIntel_006723a0._8_4_;
  uVar3 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | 0x40
          | (uint)(in_AF & 1) * 0x10 | 4 | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar1 = uVar3 ^ 0x200000;
  if (((uint)((uVar1 & 0x4000) != 0) * 0x4000 | (uint)((uVar1 & 0x200) != 0) * 0x200 |
       (uint)((uVar1 & 0x100) != 0) * 0x100 | (uint)((uVar1 & 0x40) != 0) * 0x40 |
       (uint)((uVar1 & 0x10) != 0) * 0x10 | (uint)((uVar1 & 4) != 0) * 4 |
       (uint)((uVar1 & 0x200000) != 0) * 0x200000 | (uint)((uVar1 & 0x40000) != 0) * 0x40000) !=
      uVar3) {
    iVar2 = cpuid_basic_info(0);
    local_1c = *(undefined4 *)(iVar2 + 4);
    local_18 = *(undefined4 *)(iVar2 + 8);
    local_14 = *(undefined4 *)(iVar2 + 0xc);
    iVar2 = 0;
    do {
      if (*(char *)((int)&local_1c + iVar2) != local_2c[iVar2]) {
        DAT_006fe57c = 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xc);
    if (0 < iVar2) {
      iVar2 = cpuid_Version_info(1);
      local_8 = *(undefined4 *)(iVar2 + 8);
    }
  }
  return local_8;
}

