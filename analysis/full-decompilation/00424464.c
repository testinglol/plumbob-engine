
undefined4 * FUN_00424464(void)

{
  undefined4 *extraout_ECX;
  int iVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0046f824(extraout_ECX + 3,0,0x104);
  *extraout_ECX = &PTR_FUN_006664e8;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x49] = 0;
  extraout_ECX[0x52] = 0;
  extraout_ECX[0x53] = 0;
  extraout_ECX[0x54] = 0;
  extraout_ECX[0x55] = 0;
  extraout_ECX[0x56] = 0;
  extraout_ECX[0x57] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8680();
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x5e] = 0;
  extraout_ECX[0x5f] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0042ee36(unaff_EBP + -0xe,unaff_EBP + -0xd);
  extraout_ECX[0x65] = 0;
  extraout_ECX[0x66] = 0;
  extraout_ECX[0x67] = 0;
  puVar2 = extraout_ECX + 0x4a;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x58] = 0;
  extraout_ECX[0x59] = 0;
  *(undefined1 *)(extraout_ECX + 0x68) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1a1) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1a2) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1a3) = 0;
  *(undefined1 *)(extraout_ECX + 0x69) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1a5) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1aa) = 0;
  return extraout_ECX;
}

