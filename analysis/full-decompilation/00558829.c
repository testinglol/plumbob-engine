
void FUN_00558829(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar4;
  undefined4 uVar5;
  
  FUN_00634c24();
  iVar2 = FUN_0055c216(*(undefined4 *)(unaff_EBP + 8));
  if (iVar2 == 0) goto LAB_00558a18;
  uVar4 = DAT_006f5984;
  uVar5 = DAT_006f5980;
  if ((*(int *)(iVar2 + 0x14) != 0) ||
     (iVar3 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + 8)), uVar4 = DAT_006f5974,
     uVar5 = DAT_006f5970, iVar3 != 1)) {
    FUN_004f6994(uVar4,uVar5,0,0);
    goto LAB_00558a18;
  }
  FUN_00429c21();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = FUN_004e1c79(*(undefined4 *)(extraout_ECX + 0x1ac),unaff_EBP + -0x2c);
  if (cVar1 == '\0') {
    FUN_0055b4e6(0);
    goto LAB_00558a0c;
  }
  uVar4 = DAT_006f594c;
  uVar5 = DAT_006f5948;
  if (*(int *)(iVar2 + 0x10) == 0) {
LAB_005589f7:
    FUN_004f6994(uVar4,uVar5,0,0);
  }
  else {
    uVar4 = DAT_006f597c;
    uVar5 = DAT_006f5978;
    if (*(int *)(iVar2 + 0x18) == 0) {
      if ((*(int *)(iVar2 + 0x24) != -1) ||
         (uVar4 = DAT_006f594c, uVar5 = DAT_006f5948,
         *(int *)(unaff_EBP + -0x20) < *(int *)(iVar2 + 0x1c))) goto LAB_005589f7;
      iVar2 = FUN_004f6994(DAT_006f595c,DAT_006f5958,2,0);
      if (iVar2 == 4) {
        FUN_0055b4e6(0);
        goto LAB_0055898a;
      }
    }
    else {
      if ((*(int *)(iVar2 + 0x24) != -1) ||
         (uVar4 = DAT_006f594c, uVar5 = DAT_006f5948,
         *(int *)(unaff_EBP + -0x20) < *(int *)(iVar2 + 0x1c))) goto LAB_005589f7;
      iVar2 = FUN_004f6994(DAT_006f5944,DAT_006f5940,2,0);
      if (iVar2 == 4) {
        FUN_0055b4e6(0);
        iVar2 = *(int *)(extraout_ECX + 0x148);
        iVar3 = *(int *)(iVar2 + 8);
        *(int *)(unaff_EBP + -0x10) = iVar3;
        if (iVar3 != iVar2) {
          do {
            (**(code **)(**(int **)(*(int *)(unaff_EBP + -0x10) + 0x14) + 0x160))(0);
            FUN_0041674f();
          } while (*(int *)(unaff_EBP + -0x10) != *(int *)(extraout_ECX + 0x148));
        }
LAB_0055898a:
        FUN_0042b033();
        FUN_0042a9d1(0x1e);
        FUN_0042b902();
        FUN_0042b13f(10);
        FUN_004f1b96(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(extraout_ECX + 0x1ac));
        FUN_005dac30(0x10,extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
      }
    }
  }
LAB_00558a0c:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00558a18:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

