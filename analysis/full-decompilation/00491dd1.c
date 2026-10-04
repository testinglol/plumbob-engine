
void FUN_00491dd1(void)

{
  char cVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x2c) == '\0') && (*(uint *)(extraout_ECX + 0x58) <= DAT_006e5490))
  {
    cVar1 = FUN_00484ba0(unaff_EBP + 8);
    if (cVar1 == '\0') {
      DAT_006e57d8 = *(undefined4 *)(unaff_EBP + 8);
      DAT_006e57dc = *(undefined4 *)(unaff_EBP + 0xc);
      FUN_00491e92();
      FUN_00490d54(*(undefined4 *)(extraout_ECX + 0x4c),unaff_EBP + 8);
      *(char *)(unaff_EBP + -0x10) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
      *(char *)(unaff_EBP + -0xf) = (char)(*(int *)(unaff_EBP + 8) >> 4);
      *(undefined1 *)(unaff_EBP + -0xe) = 1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00491f06(unaff_EBP + -0x10);
      *(uint *)(extraout_ECX + 0x58) = DAT_006e5490 + 100;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

