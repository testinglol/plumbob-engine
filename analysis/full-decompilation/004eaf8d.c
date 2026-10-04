
void FUN_004eaf8d(void)

{
  short sVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar5 = DAT_006f2a54;
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_004e950a(*(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0x10);
  if (cVar2 != '\0') {
    uVar5 = *(uint *)(unaff_EBP + 0x14);
    uVar8 = uVar5 >> 8;
    uVar4 = uVar5 >> 0x10;
    FUN_004096c2(uVar4,uVar8,uVar5);
    uVar5 = FUN_005dfe3b(uVar4,uVar8,uVar5);
    uVar5 = uVar5 & 0xffff;
    iVar6 = FUN_004096c2();
    uVar7 = FUN_004096c2();
    FUN_004b818c(*(undefined4 *)(unaff_EBP + 8),uVar7,iVar6 + 0x14,100,0,0);
  }
  *(undefined1 *)(unaff_EBP + 0x17) = 0;
  iVar6 = FUN_004e9744(*(undefined4 *)(unaff_EBP + 0x10));
  if (iVar6 == 0) {
    FUN_004e978e(*(undefined4 *)(unaff_EBP + 0x10));
    iVar6 = FUN_004e9744(*(undefined4 *)(unaff_EBP + 0x10));
    if (iVar6 == 0) goto LAB_004eb13c;
    *(undefined1 *)(unaff_EBP + 0x17) = 1;
  }
  FUN_005c1719();
  sVar1 = *(short *)(iVar6 + 0x60e);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (((uint)(int)sVar1 >> 1 & 1) == 0) {
    if (((uint)(int)sVar1 >> 2 & 1) == 0) {
      FUN_005b870f(s_a2o_idle_transition_handships_ar_006c9e30);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar3 = FUN_004e81eb(iVar6,uVar5,0,unaff_EBP + -0x1c,0,unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + 0x13) = uVar3;
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
    else {
      FUN_005b870f(s_k2o_sit_howl_start_006c9e5c);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar3 = FUN_004e81eb(iVar6,uVar5,0,unaff_EBP + -0x1c,1,unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + 0x13) = uVar3;
      *(undefined1 *)(unaff_EBP + -4) = 1;
    }
  }
  else {
    FUN_005b870f(s_d2o_napfloor_sit_loop_006c9e70);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar3 = FUN_004e81eb(iVar6,uVar5,0,unaff_EBP + -0x1c,1,unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + 0x13) = uVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
  }
  FUN_005b8770();
  if (*(char *)(unaff_EBP + 0x13) != '\0') {
    uVar7 = FUN_004096c2();
    FUN_004b818c(*(undefined4 *)(unaff_EBP + 0xc),uVar7,0,100,0,0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005a5e09();
  if (*(char *)(unaff_EBP + 0x17) != '\0') {
    FUN_0044127f(*(undefined2 *)(iVar6 + 0xf0));
  }
LAB_004eb13c:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005a5e09();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

