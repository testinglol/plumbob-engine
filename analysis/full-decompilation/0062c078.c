
/* WARNING: Removing unreachable block (ram,0x0062c0b5) */

int FUN_0062c078(void)

{
  undefined4 *puVar1;
  uint3 uVar3;
  int iVar2;
  
  puVar1 = (undefined4 *)cpuid_Version_info(1);
  uVar3 = (uint3)((uint)*puVar1 >> 8);
  if ((puVar1[2] & 0x800000) == 0) {
    iVar2 = (uint)uVar3 << 8;
  }
  else {
    iVar2 = CONCAT31(uVar3,1);
  }
  return iVar2;
}

