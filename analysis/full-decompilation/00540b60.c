
void FUN_00540b60(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  int iVar3;
  int iVar4;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = iVar3;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = unaff_EBP + -0x10;
  puVar1 = *(undefined4 **)(extraout_ECX + 0xc + *(int *)(unaff_EBP + 0xc) * 4);
  iVar4 = extraout_ECX;
  uVar2 = FUN_00541822(*puVar1,puVar1[1],unaff_EBP + 8,&LAB_00540a42,0,iVar3);
  FUN_0054105c(uVar2,iVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    FUN_0053c286(iVar4);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

