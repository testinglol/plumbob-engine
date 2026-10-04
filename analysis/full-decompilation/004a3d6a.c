
void FUN_004a3d6a(void)

{
  int iVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006686d4;
  iVar1 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = *(int *)(iVar1 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != iVar1) {
    do {
      FUN_00634ecc(*(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14));
      FUN_0041674f();
    } while (*(int *)(unaff_EBP + -0x10) != extraout_ECX[1]);
  }
  FUN_004a42fd();
  FUN_00634ecc(extraout_ECX[0x10]);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004a4291();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

