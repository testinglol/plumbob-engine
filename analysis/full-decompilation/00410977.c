
undefined4 FUN_00410977(void)

{
  void *pvVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x148) == 0) {
    pvVar1 = operator_new(0x240);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004ed703(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x148) = iVar2;
    if (iVar2 != 0) {
      FUN_0046f824(unaff_EBP + -0x114,0,0x104);
      *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
      FUN_00425531(unaff_EBP + -0x120);
      FUN_0046f847(s_PhotoAlbum__006c1120,0xffffffff);
      FUN_004edae7(unaff_EBP + -0x120,unaff_EBP + -0x120);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(extraout_ECX + 0x148);
}

