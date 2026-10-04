
undefined4 * FUN_00551513(void)

{
  char cVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *extraout_ECX = &PTR_FUN_00670714;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  extraout_ECX[0x3a] = 0;
  *(undefined1 *)(extraout_ECX + 0x3b) = 1;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x4e] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6b] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004733c6();
  extraout_ECX[0x51] = 0;
  *extraout_ECX = &PTR_FUN_00670564;
  extraout_ECX[0x52] = 0;
  _memset(extraout_ECX + 0x53,0,0x24);
  _memset(extraout_ECX + 0x5c,0,0x18);
  _memset(extraout_ECX + 0x3e,0,0x1c);
  cVar1 = *(char *)(unaff_EBP + 8);
  extraout_ECX[0x72] = 0x41d00000;
  extraout_ECX[0x73] = 0;
  extraout_ECX[0x35] = (-(uint)(cVar1 != '\0') & 0xfffffffc) + 4;
  extraout_ECX[0x75] = DAT_006fea20;
  DAT_006fea20 = DAT_006f2a98;
  extraout_ECX[0x6c] = 0xffffffff;
  *(char *)((int)extraout_ECX + 0x12a) = cVar1;
  *(undefined1 *)(extraout_ECX + 0x67) = 0;
  extraout_ECX[0x68] = 0;
  *(undefined1 *)(extraout_ECX + 0x76) = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  *(undefined1 *)(extraout_ECX + 0x4a) = 0;
  extraout_ECX[0x49] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x129) = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x7b] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

