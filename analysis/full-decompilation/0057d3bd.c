
undefined4 FUN_0057d3bd(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = FUN_00635845(**(undefined4 **)(unaff_EBP + 8),&DAT_006cf464);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    while (iVar2 = FUN_006380d8(unaff_EBP + -0x218,0x100,iVar1), iVar2 != 0) {
      FUN_00634d24(unaff_EBP + -0x218,s__s__ld___006cf4d8,unaff_EBP + -0x118,unaff_EBP + 8);
      if (*(char *)(unaff_EBP + -0x118) != '\0') {
        uVar3 = FUN_005d4956(unaff_EBP + -0x118);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        puVar4 = (undefined4 *)FUN_0058089f(uVar3);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *puVar4 = *(undefined4 *)(unaff_EBP + 8);
        FUN_005b8770();
      }
    }
    uVar3 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

