
void FUN_00665000(void)

{
  ushort in_FPUControlWord;
  
  DAT_006f7780 = in_FPUControlWord;
  DAT_006f7782 = in_FPUControlWord & 0xfcff | 0x3f;
  return;
}

