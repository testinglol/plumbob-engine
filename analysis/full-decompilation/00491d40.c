
void FUN_00491d40(void)

{
  int iVar1;
  char cVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00490c0d(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  if (*(char *)(extraout_ECX + 0x2c) == '\0') {
    cVar2 = FUN_00484ba0(unaff_EBP + 8);
    if (cVar2 == '\0') {
      FUN_00491e92();
      FUN_00490d54(*(undefined4 *)(extraout_ECX + 0x4c),unaff_EBP + 8);
      iVar1 = *(int *)(unaff_EBP + 0xc);
      *(undefined4 *)(extraout_ECX + 0x30) = 0;
      *(char *)(unaff_EBP + 0x14) = (char)(iVar1 >> 4);
      *(undefined1 *)(unaff_EBP + 0x16) = 1;
      *(char *)(unaff_EBP + 0x15) = (char)(*(int *)(unaff_EBP + 8) >> 4);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00491f06(unaff_EBP + 0x14);
      *(int *)(extraout_ECX + 0x58) = DAT_006e5490 + 400;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

