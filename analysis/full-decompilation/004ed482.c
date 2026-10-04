
undefined1 FUN_004ed482(void)

{
  undefined4 uVar1;
  int iVar2;
  int *extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = 1;
  if ((undefined4 *)extraout_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[1])(1);
  }
  extraout_ECX[1] = 0;
  FUN_005d4bbf(&DAT_006de560);
  if (*extraout_ECX != 2) {
    uVar3 = 0;
    goto LAB_004ed546;
  }
  FUN_0063344c(1);
  uVar1 = DAT_00689070;
  iVar2 = extraout_ECX[0x8f];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00633510(iVar2,1,uVar1);
  if (*(int *)(*(int *)(unaff_EBP + -0x68 + *(int *)(*(int *)(unaff_EBP + -0x6c) + 4)) + 0x4c) == -1
     ) {
LAB_004ed52a:
    uVar3 = 0;
  }
  else {
    while( true ) {
      FUN_00633175(unaff_EBP + -0x10);
      if ((*(byte *)(unaff_EBP + -100 + *(int *)(*(int *)(unaff_EBP + -0x6c) + 4)) & 1) != 0) break;
      FUN_004015e4(*(undefined4 *)(unaff_EBP + -0x10));
    }
    iVar2 = FUN_004b845d(extraout_ECX[7]);
    extraout_ECX[1] = iVar2;
    if (iVar2 == 0) goto LAB_004ed52a;
    *extraout_ECX = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006334fd();
  FUN_00632b08();
LAB_004ed546:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

