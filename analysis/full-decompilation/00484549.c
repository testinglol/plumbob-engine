
undefined4 FUN_00484549(void)

{
  int iVar1;
  size_t sVar2;
  int unaff_EBP;
  short sVar3;
  short sVar4;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_0048423e();
  sVar4 = 1;
  sVar3 = (short)*(undefined4 *)(unaff_EBP + 0xc);
  if ((0 < sVar3) && (sVar4 = sVar3, 0xc < sVar3)) {
    sVar4 = 0xc;
  }
  FUN_005b86bd(&DAT_006e5610);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  iVar1 = *(int *)(sVar4 * 8 + 0x6c5d30);
  FUN_00412d8a(*(undefined4 *)(&DAT_006e5624 + iVar1 * 0xc),*(undefined4 *)(iVar1 * 0xc + 0x6e5628))
  ;
  sVar2 = _strlen(&DAT_006c25a8);
  FUN_00412d8a(&DAT_006c25a8,&DAT_006c25a8 + sVar2);
  iVar1 = *(int *)(sVar4 * 8 + 0x6c5d34);
  FUN_00412d8a(*(undefined4 *)(&DAT_006e5624 + iVar1 * 0xc),*(undefined4 *)(iVar1 * 0xc + 0x6e5628))
  ;
  FUN_005b86bd(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

