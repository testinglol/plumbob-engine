
/* WARNING: Removing unreachable block (ram,0x005be057) */
/* WARNING: Removing unreachable block (ram,0x005be022) */

undefined8 FUN_005bdfee(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  char local_2c [16];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  uint local_c;
  
  local_2c._0_4_ = s_GenuineIntel_006723a0._0_4_;
  local_2c._4_4_ = s_GenuineIntel_006723a0._4_4_;
  local_2c._8_4_ = s_GenuineIntel_006723a0._8_4_;
  local_c = 0xffff;
  iVar1 = cpuid_basic_info(0);
  local_18 = *(uint *)(iVar1 + 8);
  local_1c = *(undefined4 *)(iVar1 + 4);
  local_14 = *(undefined4 *)(iVar1 + 0xc);
  uVar3 = 0;
  do {
    if (*(char *)((int)&local_1c + uVar3) != local_2c[uVar3]) {
      DAT_006fe57c = 1;
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0xc);
  if (0 < (int)uVar3) {
    puVar2 = (uint *)cpuid_Version_info(1);
    local_18 = puVar2[2];
    uVar3 = *puVar2 >> 8 & 0xf;
    local_c = uVar3;
  }
  return CONCAT44(local_18,CONCAT22((short)(uVar3 >> 0x10),(undefined2)local_c));
}

