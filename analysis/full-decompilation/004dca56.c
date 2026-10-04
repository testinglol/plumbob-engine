
undefined4 FUN_004dca56(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar5 = 0;
  FUN_0046f824(unaff_EBP + -0x24c,0,0x104);
  *(undefined ***)(unaff_EBP + -600) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x35c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x368) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x13c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x148) = &PTR_FUN_006664e8;
  iVar1 = FUN_004102e1();
  if (0 < iVar1) {
    do {
      FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 0xc));
      *(int *)(unaff_EBP + -0x10) = iVar5 + 1;
      (*(code *)PTR_FUN_006d7008)(iVar5 + 1,unaff_EBP + -0x468,10);
      puVar2 = (undefined4 *)FUN_004102ab(iVar5);
      uVar3 = FUN_004e988f(*puVar2);
      FUN_0046f847(s_family_006c83a8,0xffffffff);
      FUN_0046f847(unaff_EBP + -0x468,0xffffffff);
      FUN_0046f847(s__face_jpg_006c8a0c,0xffffffff);
      FUN_0046f847(s_family_006c83a8,0xffffffff);
      FUN_0046f847(unaff_EBP + -0x468,0xffffffff);
      FUN_0046f847(s__full_jpg_006c8a00,0xffffffff);
      FUN_0046f847(s_faminfo__006c89f4,0xffffffff);
      FUN_0046f847(unaff_EBP + -0x468,0xffffffff);
      FUN_0046f847(&DAT_006c111c,0xffffffff);
      uVar4 = FUN_004e8d71(uVar3);
      puVar2 = (undefined4 *)FUN_004d6554(unaff_EBP + -0x1c,uVar4);
      uVar4 = *puVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046f847(uVar4,0xffffffff);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      FUN_005ed06b(*(undefined4 *)(unaff_EBP + -0x144));
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_005ed121(2,1,1);
      FUN_004d6581(*(undefined4 *)(unaff_EBP + -0x254));
      FUN_004d6581(*(undefined4 *)(unaff_EBP + -0x364));
      FUN_004eaf8d(*(undefined4 *)(unaff_EBP + -0x254),*(undefined4 *)(unaff_EBP + -0x364),uVar3,
                   0xffffff);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005ed0c3();
      iVar5 = *(int *)(unaff_EBP + -0x10);
      iVar1 = FUN_004102e1();
    } while (iVar5 < iVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

