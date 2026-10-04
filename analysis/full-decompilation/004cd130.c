
undefined4 * FUN_004cd130(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_00668d2c;
  extraout_ECX[4] = uVar1;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  cVar2 = FUN_005a5e72();
  if (cVar2 == '\0') {
    cVar2 = FUN_005a5631(0x256,unaff_EBP + -0x10,4);
    *(char *)(unaff_EBP + 0xb) = cVar2;
    if (cVar2 != '\0') {
      FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
  }
  cVar2 = FUN_005a5e72();
  if (cVar2 == '\0') {
    FUN_005a5631(0x10cc,unaff_EBP + -0x10,4);
    if (*(char *)(unaff_EBP + 0xb) != '\0') {
      FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x10));
      piVar3 = (int *)FUN_004096c2();
      (**(code **)(*piVar3 + 0x68))(DAT_006f2a64);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
  }
  cVar2 = FUN_005a5e72();
  if (cVar2 == '\0') {
    FUN_005a5631(0x10cd,unaff_EBP + -0x10,4);
    if (*(char *)(unaff_EBP + 0xb) != '\0') {
      FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x10));
      piVar3 = (int *)FUN_004096c2();
      (**(code **)(*piVar3 + 0x68))(DAT_006f2a64);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

