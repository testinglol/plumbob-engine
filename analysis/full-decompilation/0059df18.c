
int FUN_0059df18(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005a1c75();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005a1d32();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005a1def();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined4 *)(extraout_ECX + 0x3c) = uVar2;
  pvVar1 = operator_new(0x14);
  *(void **)(unaff_EBP + 8) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005d23b8(uVar2);
  }
  *(undefined4 *)(extraout_ECX + 0x40) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  DAT_006f75e4 = FUN_0059e028;
  DAT_006f75e8 = FUN_0059e041;
  DAT_006f75ec = FUN_0059e0c7;
  FUN_005c22bb();
  FUN_005c1871(&DAT_006f7668);
  FUN_005c18db(&DAT_006f7668,&DAT_006f7664);
  FUN_005c18db(&DAT_006f7668,&DAT_006f7660);
  FUN_005c1871(&DAT_006f765c);
  FUN_005c18db(&DAT_006f765c,&DAT_006f7658);
  FUN_005c18db(&DAT_006f765c,&DAT_006f7654);
  FUN_005c1871(&DAT_006f7650);
  FUN_005c18db(&DAT_006f7650,&DAT_006f764c);
  DAT_006f75dc = DAT_006e5490;
  DAT_006f7670 = extraout_ECX;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

