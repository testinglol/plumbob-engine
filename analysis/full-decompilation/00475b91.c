
undefined4 FUN_00475b91(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar7;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  if (((piVar2 == (int *)0x0) || (cVar4 = (**(code **)(*piVar2 + 0x28))(), cVar4 == '\0')) ||
     (*(short *)(unaff_EBP + 0xc) == 0)) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar5 = *(int *)(extraout_ECX + 4);
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    if (0 < iVar5) {
      do {
        iVar5 = *(int *)(*(int *)(extraout_ECX + 0x10) + *(int *)(unaff_EBP + -0x10) * 4);
        *(int *)(unaff_EBP + -0x14) = iVar5;
        if (iVar5 != 0) {
          FUN_00476018();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      } while (*(int *)(unaff_EBP + -0x10) < *(int *)(extraout_ECX + 4));
    }
    FUN_006321f0(*(undefined4 *)(extraout_ECX + 0x10));
    *(undefined4 *)(extraout_ECX + 0x10) = 0;
    iVar5 = (**(code **)(*piVar2 + 0x38))(0x54544142,*(undefined4 *)(unaff_EBP + 0xc),0);
    *(int *)(unaff_EBP + -0x10) = iVar5;
    if (iVar5 == 0) {
      uVar6 = 0xffffff9d;
    }
    else {
      uVar1 = *(undefined2 *)(unaff_EBP + 0xc);
      *(int **)(extraout_ECX + 0x14) = piVar2;
      *(undefined2 *)(extraout_ECX + 0x18) = uVar1;
      uVar6 = FUN_00420096(iVar5);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
      uVar6 = FUN_00420048(*(undefined4 *)(unaff_EBP + -0x10));
      FUN_004644dc(uVar6,*(undefined4 *)(unaff_EBP + -0x14),0,0);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00475e2d(unaff_EBP + -0x88,unaff_EBP + 10);
      FUN_0046f824(unaff_EBP + -200,0,0x40);
      iVar5 = *piVar2;
      *(undefined ***)(unaff_EBP + -0xd4) = &PTR_FUN_0066651c;
      (**(code **)(iVar5 + 0x48))(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0xd4);
      FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x10));
      if (*(short *)(unaff_EBP + 10) < 8) {
        cVar4 = (**(code **)(*piVar2 + 0x20))();
        if (cVar4 != '\0') {
          FUN_00475797(unaff_EBP + -0xd4);
        }
      }
      else {
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x140) = &PTR_FUN_0066643c;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0047034e(piVar2,*(undefined4 *)(unaff_EBP + 0xc),0x54544173,0,0xffffffff);
        iVar5 = FUN_0046ffa4(0,1);
        if ((iVar5 == 0) &&
           (iVar5 = *(int *)(extraout_ECX + 4), *(undefined4 *)(unaff_EBP + 0xc) = 0, 0 < iVar5)) {
          do {
            iVar5 = *(int *)(unaff_EBP + 0xc) * 4;
            uVar6 = FUN_004705f2(*(int *)(*(int *)(iVar5 + *(int *)(extraout_ECX + 0x10)) + 0x18) +
                                 1,0xffffffff);
            *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
            FUN_00470631(*(int *)(*(int *)(iVar5 + *(int *)(extraout_ECX + 0x10)) + 0x18) + 1,
                         0xffffffff);
            pcVar7 = *(char **)(unaff_EBP + -0x14);
            if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) {
              iVar3 = *(int *)(iVar5 + *(int *)(extraout_ECX + 0x10));
              uVar6 = (**(code **)(**(int **)(extraout_ECX + 0x14) + 0x38))
                                (0x42484156,
                                 CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 2)),0
                                );
              *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
              FUN_0046f824(unaff_EBP + -0x54,0,0x40);
              *(undefined ***)(unaff_EBP + -0x60) = &PTR_FUN_0066651c;
              if (*(int *)(unaff_EBP + -0x10) != 0) {
                (**(code **)(**(int **)(extraout_ECX + 0x14) + 0x48))
                          (*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x60);
              }
              if (*(short *)(unaff_EBP + -0x58) == 0) {
                FUN_0046f847(&DAT_006c4da4,0xffffffff);
                FUN_0046fa40((int)*(short *)(*(int *)(iVar5 + *(int *)(extraout_ECX + 0x10)) + 2));
              }
              pcVar7 = *(char **)(unaff_EBP + -0x5c);
            }
            FUN_005d4bbf(pcVar7);
            *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
          } while (*(int *)(unaff_EBP + 0xc) < *(int *)(extraout_ECX + 4));
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_00470467();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0046453f();
      uVar6 = 0;
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar6;
}

