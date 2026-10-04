
/* WARNING: Removing unreachable block (ram,0x004f5a71) */

ulonglong FUN_004f5a68(void)

{
  int *piVar1;
  
  piVar1 = (int *)cpuid_Version_info(1);
  return CONCAT44(piVar1[2],*piVar1 >> 8) & 0xffffffff0000000f;
}

