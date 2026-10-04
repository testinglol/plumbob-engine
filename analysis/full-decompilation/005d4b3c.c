
undefined4 FUN_005d4b3c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d4956(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((uint)(*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18)) < *(uint *)(unaff_EBP + 0xc)
     ) {
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14));
  }
  else {
    puVar3 = (undefined4 *)FUN_005d4be4(unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 0xc));
    uVar1 = puVar3[1];
    uVar2 = *puVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00412d8a(uVar2,uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00401729();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00401729();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

