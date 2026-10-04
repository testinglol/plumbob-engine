
void FUN_0058574d(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(char *)(unaff_EBP + 8) == '\0') &&
     (extraout_ECX[0x27] == (int)*(short *)(extraout_ECX[1] + 0xd2))) goto LAB_005859ce;
  FUN_0046f824(unaff_EBP + -0x208,0,0x100);
  *(undefined ***)(unaff_EBP + -0x214) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x360,0,0x100);
  *(undefined ***)(unaff_EBP + -0x36c) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x46c,0,0x100);
  iVar3 = extraout_ECX[1];
  piVar1 = (int *)extraout_ECX[0x37];
  *(undefined ***)(unaff_EBP + -0x478) = &PTR_FUN_00666524;
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
  extraout_ECX[0x27] = (int)*(short *)(iVar3 + 0xd2);
  (**(code **)(*piVar1 + 0xc))(2,unaff_EBP + -0x214,unaff_EBP + -0x36c,0);
  iVar3 = (**(code **)(*extraout_ECX + 0xac))();
  if (iVar3 == 0) goto LAB_005859ce;
  iVar3 = (**(code **)(*extraout_ECX + 0xac))();
  uVar2 = *(undefined4 *)(iVar3 + 4);
  uVar4 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x368));
  *(undefined4 *)(unaff_EBP + 8) = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x210));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0058372c(DAT_006f6b64,uVar2,uVar4,*(undefined4 *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_0046f824(unaff_EBP + -100,0,0x40);
  *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_0066651c;
  FUN_0046f847(s_head_arrow_006d05cc,0xffffffff);
  FUN_0040f445(unaff_EBP + -0x214);
  iVar3 = FUN_0046f93d(unaff_EBP + -0x70);
  if (iVar3 == 0) {
    *(undefined1 *)(extraout_ECX + 0x3e) = 1;
    extraout_ECX[0x3f] = 1;
LAB_005859a1:
    *(undefined1 *)((int)extraout_ECX + 0xf7) = 0;
  }
  else {
    FUN_0046f824(unaff_EBP + -100,0,0x40);
    *(undefined ***)(unaff_EBP + -0x70) = &PTR_FUN_0066651c;
    FUN_0046f847(s_head_arrow_date_006d05bc,0xffffffff);
    FUN_0040f445(unaff_EBP + -0x214);
    iVar3 = FUN_0046f93d(unaff_EBP + -0x70);
    if (iVar3 == 0) {
      *(undefined1 *)(extraout_ECX + 0x3e) = 1;
      extraout_ECX[0x3f] = 2;
      goto LAB_005859a1;
    }
    FUN_0046f824(unaff_EBP + -0xb0,0,0x40);
    *(undefined ***)(unaff_EBP + -0xbc) = &PTR_FUN_0066651c;
    FUN_0046f847(s_head_star_006d05b0,0xffffffff);
    FUN_0040f445(unaff_EBP + -0x214);
    iVar3 = FUN_0046f93d(unaff_EBP + -0xbc);
    if (iVar3 == 0) {
      *(undefined1 *)(extraout_ECX + 0x3e) = 1;
      extraout_ECX[0x3f] = 3;
      goto LAB_005859a1;
    }
  }
  uVar5 = (uint)*(byte *)((int)extraout_ECX + 0xf6);
  uVar6 = (uint)*(byte *)((int)extraout_ECX + 0xf5);
  uVar7 = (uint)*(byte *)(extraout_ECX + 0x3d);
  (**(code **)(*extraout_ECX + 0xac))(uVar7,uVar6,uVar5);
  FUN_005a1917(uVar7,uVar6,uVar5);
LAB_005859ce:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

