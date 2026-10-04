
undefined4 FUN_004757ba(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar6;
  undefined4 *unaff_FS_OFFSET;
  undefined1 *puVar7;
  
  FUN_00634c24();
  FUN_00636080();
  uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
  if ((((short)uVar5 < 1) || (piVar6 = *(int **)(unaff_EBP + 8), piVar6 == (int *)0x0)) ||
     (cVar2 = (**(code **)(*piVar6 + 0x28))(), cVar2 == '\0')) {
    uVar5 = 0xffffffff;
  }
  else {
    FUN_00464515();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00475e2d(unaff_EBP + -0xac,unaff_EBP + -0x16);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0xa4);
    uVar3 = FUN_0041ffd9(*(undefined4 *)(unaff_EBP + -0xa4));
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    uVar3 = FUN_00420048(uVar3);
    *(int **)(extraout_ECX + 0x14) = piVar6;
    *(short *)(extraout_ECX + 0x18) = (short)uVar5;
    FUN_004644dc(uVar3,*(undefined4 *)(unaff_EBP + -0x14),1,0);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00475e2d(unaff_EBP + -0xd4,unaff_EBP + -0x16);
    FUN_0042004f(*(undefined4 *)(unaff_EBP + -0x10));
    (**(code **)(*piVar6 + 0x74))
              (*(undefined4 *)(unaff_EBP + -0x10),0x54544142,uVar5,*(undefined4 *)(unaff_EBP + 0x10)
               ,1);
    iVar4 = FUN_00401f6f();
    if (iVar4 == 0) {
      FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x10));
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x84) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0047034e(piVar6,uVar5,0x54544173,0,0xffffffff);
      FUN_0046ffa4(0,1);
      *(undefined4 *)(unaff_EBP + 0x10) = 0;
      if (0 < *(int *)(extraout_ECX + 4)) {
        do {
          *(undefined4 *)(unaff_EBP + -0x10) =
               *(undefined4 *)
                (*(int *)(*(int *)(extraout_ECX + 0x10) + *(int *)(unaff_EBP + 0x10) * 4) + 0x18);
          while (iVar4 = FUN_0046fbe5(0xffffffff), iVar4 < *(int *)(unaff_EBP + -0x10)) {
            uVar5 = 0xffffffff;
            puVar7 = &DAT_006de560;
            iVar4 = FUN_0046fbe5(0xffffffff);
            FUN_004704a5(iVar4 + 1,puVar7,uVar5);
          }
          iVar4 = *(int *)(unaff_EBP + -0x10) + 1;
          iVar1 = *(int *)(extraout_ECX + 0x10);
          *(int *)(unaff_EBP + -0x10) = iVar4;
          FUN_004704a5(iVar4,*(undefined4 *)
                              (*(int *)(iVar1 + *(int *)(unaff_EBP + 0x10) * 4) + 0x24),0xffffffff);
          uVar5 = FUN_00470631(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
          FUN_0046f824(unaff_EBP + -0x4d4,0,0x400);
          *(undefined ***)(unaff_EBP + -0x4e0) = &PTR_FUN_0066773c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
          FUN_004765ab(unaff_EBP + -0x4e0);
          if ((*(short *)(unaff_EBP + -0x4d8) == 0) || (**(char **)(unaff_EBP + -0x4dc) != '!')) {
            if ((*(uint *)(*(int *)(*(int *)(extraout_ECX + 0x10) + *(int *)(unaff_EBP + 0x10) * 4)
                          + 0x14) >> 7 & 1) != 0) {
              FUN_0046f824(unaff_EBP + -0x1504,0,0x400);
              *(undefined ***)(unaff_EBP + -0x1510) = &PTR_FUN_0066773c;
              FUN_0046f847(&DAT_006c4da0,0xffffffff);
              FUN_0046f8e4(unaff_EBP + -0x1510);
              FUN_0046f917(unaff_EBP + -0x4e0,0xffffffff);
            }
          }
          else if ((*(uint *)(*(int *)(*(int *)(extraout_ECX + 0x10) +
                                      *(int *)(unaff_EBP + 0x10) * 4) + 0x14) >> 7 & 1) == 0) {
            *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x4dc);
            FUN_0046f824(unaff_EBP + -0x10f8,0,0x400);
            *(undefined ***)(unaff_EBP + -0x1104) = &PTR_FUN_0066773c;
            FUN_0046f847(*(int *)(unaff_EBP + -0x14) + 1,0xffffffff);
            FUN_0046f8e4(unaff_EBP + -0x1104);
            if (*(short *)(unaff_EBP + -0x8e4) == 0) {
              FUN_0046f824(unaff_EBP + -0xcec,0,0x400);
              *(undefined ***)(unaff_EBP + -0xcf8) = &PTR_FUN_0066773c;
              FUN_0046f847(&DAT_006c3d7c,0xffffffff);
              FUN_0046f8e4(unaff_EBP + -0xcf8);
            }
          }
          iVar4 = FUN_0046f93d(unaff_EBP + -0x4e0);
          if (iVar4 != 0) {
            FUN_004d5038(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x8e8),
                         0xffffffff);
          }
          *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
        } while (*(int *)(unaff_EBP + 0x10) < *(int *)(extraout_ECX + 4));
        piVar6 = *(int **)(unaff_EBP + 8);
        uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
      }
      FUN_0047034e(piVar6,uVar5,0x54544173,0,0xffffffff);
      FUN_0046fd72();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00470467();
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00401f6f();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0046453f();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046453f();
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}

