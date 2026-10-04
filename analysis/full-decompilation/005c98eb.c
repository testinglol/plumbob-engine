
int FUN_005c98eb(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined *puVar5;
  undefined4 uVar6;
  
  FUN_00634c24();
  FUN_005c22bb();
  FUN_005c32ce();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047354f(1);
  iVar3 = FUN_005c1b28(unaff_EBP + -0x2c,extraout_ECX + 0x440,&DAT_006fe814,
                       *(undefined4 *)(unaff_EBP + 8),1);
  if (iVar3 == 0) {
    puVar5 = &DAT_006fe80c;
    FUN_005c3383(&DAT_006fe80c);
    cVar2 = FUN_005c17a6(puVar5);
    if (cVar2 == '\0') {
      puVar5 = &DAT_006fe808;
      FUN_005c3383(&DAT_006fe808);
      cVar2 = FUN_005c17a6(puVar5);
      if (cVar2 == '\0') {
        iVar3 = -0x64f4ffe3;
      }
      else {
        iVar3 = FUN_005cb022(unaff_EBP + -0x2c,extraout_ECX + 200,*(undefined4 *)(unaff_EBP + 0x10))
        ;
      }
    }
    else {
      uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
      iVar3 = extraout_ECX + 0xa8;
      uVar4 = FUN_00401f73(iVar3,uVar6);
      iVar3 = FUN_005c99e4(uVar4,iVar3,uVar6);
      if (((iVar3 == 0) && (iVar1 = *(int *)(unaff_EBP + 0xc), iVar1 != 0)) &&
         (*(int *)(iVar1 + 4) != 0)) {
        iVar3 = FUN_005ca5a7(*(undefined4 *)(unaff_EBP + 0x10),iVar1);
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c3314();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

