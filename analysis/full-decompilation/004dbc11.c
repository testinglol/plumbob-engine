
undefined4 FUN_004dbc11(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f847(&PTR_LAB_006c8588,0xffffffff);
  FUN_0046f917(unaff_EBP + 0xc,0xffffffff);
  FUN_0046f847(&DAT_006c8584,0xffffffff);
  FUN_0046f847(&DAT_006c857c,0xffffffff);
  uVar1 = FUN_004102e1();
  puVar2 = (undefined4 *)FUN_004d6554(unaff_EBP + -0x28,uVar1);
  uVar1 = *puVar2;
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f847(uVar1,0xffffffff);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_0046f847(&DAT_006c8578,0xffffffff);
  iVar3 = FUN_004102e1();
  if (0 < iVar3) {
    do {
      FUN_0046f917(unaff_EBP + 0xc,0xffffffff);
      *(int *)(unaff_EBP + -0x10) = iVar4 + 1;
      puVar2 = (undefined4 *)FUN_004d6554(unaff_EBP + -0x1c,iVar4 + 1);
      uVar1 = *puVar2;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_0046f847(uVar1,0xffffffff);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_0046f847(&DAT_006c8574,0xffffffff);
      puVar2 = (undefined4 *)FUN_004102ab(iVar4);
      iVar4 = FUN_0043acf5(*puVar2);
      if (iVar4 != 0) {
        iVar4 = FUN_004580cc(0);
        *(int *)(unaff_EBP + 8) = iVar4;
        if (iVar4 != 0) {
          FUN_0046f824(unaff_EBP + -0x234,0,0x100);
          *(undefined ***)(unaff_EBP + -0x240) = &PTR_FUN_00666524;
          FUN_0046f824(unaff_EBP + -0x128,0,0x100);
          *(undefined ***)(unaff_EBP + -0x134) = &PTR_FUN_00666524;
          FUN_00455edc(*(undefined4 *)(unaff_EBP + 0x118),unaff_EBP + -0x240,unaff_EBP + -0x134,0);
          if (*(char *)(unaff_EBP + 0x120) == '\0') {
            uVar1 = *(undefined4 *)(unaff_EBP + -0x23c);
          }
          else {
            uVar1 = *(undefined4 *)(unaff_EBP + -0x130);
          }
          FUN_0046f847(uVar1,0xffffffff);
          FUN_0046f847(&DAT_006c8570,0xffffffff);
        }
      }
      iVar4 = *(int *)(unaff_EBP + -0x10);
      iVar3 = FUN_004102e1();
    } while (iVar4 < iVar3);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

