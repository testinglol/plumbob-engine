
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x005bde48) */

uint FUN_005bddff(void)

{
  int iVar1;
  uint uVar2;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  bool bVar3;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  bool bVar4;
  byte in_IF;
  bool bVar5;
  byte in_OF;
  byte in_NT;
  bool bVar6;
  byte in_AC;
  bool bVar7;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  bool bVar8;
  uint uVar9;
  uint local_8;
  
  uVar9 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
          (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
          (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1) |
          (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 |
          (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  uVar2 = uVar9 ^ 0x200000;
  bVar6 = (uVar2 & 0x4000) != 0;
  bVar5 = (uVar2 & 0x200) != 0;
  bVar4 = (uVar2 & 0x100) != 0;
  bVar3 = (uVar2 & 0x10) != 0;
  bVar8 = (uVar2 & 0x200000) != 0;
  bVar7 = (uVar2 & 0x40000) != 0;
  if (((uint)bVar6 * 0x4000 | (uint)((uVar2 & 0x800) != 0) * 0x800 | (uint)bVar5 * 0x200 |
       (uint)bVar4 * 0x100 | (uint)((uVar2 & 0x80) != 0) * 0x80 | (uint)((uVar2 & 0x40) != 0) * 0x40
       | (uint)bVar3 * 0x10 | (uint)((uVar2 & 4) != 0) * 4 | (uint)((uVar2 & 1) != 0) |
       (uint)bVar8 * 0x200000 | (uint)bVar7 * 0x40000) == uVar9) {
    DAT_006fe57c = 1;
    uVar9 = (uint)bVar6 * 0x4000 | (uint)bVar5 * 0x200 | (uint)bVar4 * 0x100 |
            (uint)((short)(ushort)&stack0xfffffff4 < 0) * 0x80 |
            (uint)(((uint)&stack0xfffffff4 & 0xfffc) == 0) * 0x40 | (uint)bVar3 * 0x10 |
            (uint)((POPCOUNT((ushort)&stack0xfffffff4 & 0xfc) & 1U) == 0) * 4 |
            (uint)bVar8 * 0x200000 | (uint)bVar7 * 0x40000;
    uVar2 = uVar9 ^ 0x40000;
    local_8 = 3;
    if (((uint)((uVar2 & 0x4000) != 0) * 0x4000 | (uint)((uVar2 & 0x200) != 0) * 0x200 |
         (uint)((uVar2 & 0x100) != 0) * 0x100 | (uint)((uVar2 & 0x80) != 0) * 0x80 |
         (uint)((uVar2 & 0x40) != 0) * 0x40 | (uint)((uVar2 & 0x10) != 0) * 0x10 |
         (uint)((uVar2 & 4) != 0) * 4 | (uint)((uVar2 & 0x200000) != 0) * 0x200000 |
        (uint)((uVar2 & 0x40000) != 0) * 0x40000) != uVar9) {
      local_8 = 0xffff;
    }
    iVar1 = CONCAT22((short)((uint)&stack0xfffffff4 >> 0x10),(short)&stack0xfffffff4);
    if ((short)local_8 != 3) {
      *(undefined4 *)(iVar1 + -4) = 4;
      local_8 = *(uint *)(iVar1 + -4);
    }
  }
  else {
    local_8 = FUN_005bdfee();
  }
  if (DAT_006fe57c != 0) {
    local_8 = local_8 | 0x8000;
  }
  return local_8;
}

