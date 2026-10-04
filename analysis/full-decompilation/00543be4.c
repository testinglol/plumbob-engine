
undefined4 FUN_00543be4(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  void *pvVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  cVar4 = (**(code **)(*extraout_ECX + 200))();
  if (cVar4 == '\0') {
    (**(code **)(*extraout_ECX + 0x174))(1,0);
    (**(code **)(*extraout_ECX + 0x90))(4,0);
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004e1a40(unaff_EBP + -0x28);
    iVar8 = *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2;
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    FUN_0054821c(iVar8,unaff_EBP + -0xd);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar5 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x34),iVar8,unaff_EBP + -0x18,
                         *(undefined4 *)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -0x30) = uVar5;
    piVar1 = extraout_ECX + 0x36;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00544b26(unaff_EBP + -0x34);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0048c4c9();
    iVar8 = *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2;
    if (iVar8 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 700;
      extraout_ECX[0x41] = 0x4b;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      if (iVar8 != 0) {
        do {
          pvVar6 = operator_new(0x1f8);
          *(void **)(unaff_EBP + -0x1c) = pvVar6;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          if (pvVar6 == (void *)0x0) {
            uVar5 = 0;
          }
          else {
            uVar5 = FUN_00542bd8();
          }
          iVar8 = *piVar1;
          *(undefined1 *)(unaff_EBP + -4) = 0;
          iVar7 = *(int *)(unaff_EBP + -0x14) * 4;
          *(undefined4 *)(iVar7 + iVar8) = uVar5;
          if (*(int *)(iVar7 + *piVar1) != 0) {
            *(char *)(*(int *)(iVar7 + *piVar1) + 500) = (char)extraout_ECX[0x35];
            FUN_005434d0(*(undefined4 *)(iVar7 + *(int *)(unaff_EBP + -0x28)));
            (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(iVar7 + *piVar1));
          }
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        } while (*(uint *)(unaff_EBP + -0x14) <
                 (uint)(*(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2));
      }
      FUN_00544228();
      iVar8 = *(int *)*piVar1;
      iVar7 = *(int *)*piVar1;
      iVar3 = *(int *)(iVar7 + 0x88);
      *(int *)(unaff_EBP + -0x14) = *(int *)(iVar8 + 0x84) - *(int *)(iVar8 + 0x7c);
      extraout_ECX[0x41] = iVar3 - *(int *)(iVar7 + 0x80);
    }
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x20;
    pvVar6 = operator_new(0x158);
    *(void **)(unaff_EBP + -0x1c) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (pvVar6 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_005f65e3();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    extraout_ECX[0x39] = iVar8;
    if (iVar8 != 0) {
      FUN_004cb1a2(1,extraout_ECX[0x41] * 6);
      (**(code **)(*(int *)extraout_ECX[0x39] + 0x1b4))(2);
      extraout_ECX[0x3a] = 0;
      piVar2 = extraout_ECX + 0x3a;
      FUN_005a5631(0x139a,piVar2,4);
      if ((int *)*piVar2 != (int *)0x0) {
        (**(code **)(*(int *)*piVar2 + 0x68))(DAT_006f2a64);
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x1b8))(*piVar2,0);
      }
      FUN_004cb21d(*(undefined4 *)(unaff_EBP + -0x14),0);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
      if ((uint)(extraout_ECX[0x37] - *piVar1 >> 2) < 7) {
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x98))();
      }
      else {
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x94))();
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x1ac))(0);
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x1b0))((extraout_ECX[0x37] - *piVar1 >> 2) + -6);
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x1a8))(extraout_ECX[0x40]);
        (**(code **)(*(int *)extraout_ECX[0x39] + 0x1d4))(6);
      }
    }
    FUN_004ec186((*(int *)(extraout_ECX[0x39] + 0x84) - *(int *)(extraout_ECX[0x39] + 0x7c)) +
                 *(int *)(unaff_EBP + -0x14));
    FUN_004ec1a7(extraout_ECX[0x41] * 6);
    if ((int *)extraout_ECX[0x16] != (int *)0x0) {
      cVar4 = (**(code **)(*(int *)extraout_ECX[0x16] + 0x20))(1);
      if (cVar4 != '\0') {
        (**(code **)(*(int *)extraout_ECX[0x16] + 0x38))(DAT_006f2a64,0);
        (**(code **)(*(int *)extraout_ECX[0x16] + 0x68))(DAT_006f2a64);
      }
    }
    extraout_ECX[0x40] = 0;
    FUN_00544228();
    FUN_005a5631(0x139b,extraout_ECX + 0x3e,4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
    uVar5 = 1;
  }
  else {
    uVar5 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

