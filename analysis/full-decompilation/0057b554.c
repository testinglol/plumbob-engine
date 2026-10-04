
undefined4 FUN_0057b554(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar3 = *(undefined4 **)(unaff_EBP + 8);
  pcVar1 = (char *)*puVar3;
  if (*pcVar1 == '@') {
    iVar2 = FUN_005d49d6();
    FUN_005d4c15(unaff_EBP + -0x18,iVar2 + -1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0057d4ab(unaff_EBP + -0x18,unaff_EBP + 8);
    uVar4 = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    iVar2 = FUN_006368c3((int)*pcVar1);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)FUN_005758af(puVar3);
      uVar4 = *puVar3;
    }
    else {
      uVar4 = FUN_004096c2();
      uVar4 = FUN_005d81cf(uVar4);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

