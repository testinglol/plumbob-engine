
void FUN_00492219(void)

{
  char cVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + 0x10);
  iVar2 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(*(undefined4 *)(iVar2 + 0x84));
  FUN_004a6a27(unaff_EBP + 8);
  cVar1 = DAT_006e481d;
  *(char *)(unaff_EBP + 8) = *(char *)(unaff_EBP + 8) + DAT_006e481c;
  *(char *)(unaff_EBP + 9) = *(char *)(unaff_EBP + 9) + cVar1;
  FUN_004a6a27(unaff_EBP + 8);
  cVar1 = DAT_006e4823;
  *(char *)(unaff_EBP + 8) = *(char *)(unaff_EBP + 8) + DAT_006e4822;
  *(char *)(unaff_EBP + 9) = *(char *)(unaff_EBP + 9) + cVar1;
  FUN_004a6a27(unaff_EBP + 8);
  cVar1 = DAT_006e4820;
  *(char *)(unaff_EBP + 8) = *(char *)(unaff_EBP + 8) + DAT_006e481f;
  *(char *)(unaff_EBP + 9) = *(char *)(unaff_EBP + 9) + cVar1;
  FUN_004a6a27(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

