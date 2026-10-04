
undefined4 FUN_005c841c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  puVar1 = *(undefined4 **)(*(int *)(unaff_EBP + 0xc) + 4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_005cb60e(0);
  }
  else {
    iVar2 = (**(code **)*puVar1)(puVar1,&DAT_00677308,unaff_EBP + 0xc);
    if (-1 < iVar2) {
      FUN_005cb60e(*(undefined4 *)(unaff_EBP + 0xc));
      iVar2 = **(int **)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      (**(code **)(iVar2 + 8))(*(int **)(unaff_EBP + 0xc));
      FUN_005cb5eb(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      FUN_005cb62e();
      uVar3 = *(undefined4 *)(unaff_EBP + 8);
      goto LAB_005c849d;
    }
    FUN_005cb60e(0);
  }
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
LAB_005c849d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

