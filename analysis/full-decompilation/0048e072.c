
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048e072(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_ECX;
  uint uVar6;
  int unaff_EBP;
  float10 fVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_00492b05();
  FUN_00445724();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar3 = (**(code **)(*piVar1 + 0x1b0))();
  uVar6 = iVar3 + *(int *)(extraout_ECX + 100);
  if ((-1 < (int)uVar6) &&
     (uVar6 < (uint)(((*(int **)(extraout_ECX + 0x58))[1] - **(int **)(extraout_ECX + 0x58)) / 0x28)
     )) {
    if ((*(char *)(uVar6 * 0x28 + 0x14 + **(int **)(extraout_ECX + 0x58)) == '\0') &&
       (iVar3 = *(int *)(uVar6 * 0x28 + 0x24 + **(int **)(extraout_ECX + 0x58)), iVar3 != 0)) {
      iVar5 = *(int *)(iVar3 + 4);
      *(int *)(unaff_EBP + 8) = iVar5;
      if (iVar5 != 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        FUN_004583ff(iVar5,1);
        uVar4 = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_0045846c(uVar4);
        FUN_00458485(iVar3,unaff_EBP + -0x14);
        if ((*(uint *)(iVar3 + 0x40) >> 3 & 1) == 0) {
          *(undefined4 *)(unaff_EBP + -0x10) = 0xbf800000;
        }
        else {
          fVar7 = (float10)FUN_004214d4(*(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8));
          *(float *)(unaff_EBP + -0x10) =
               (float)(fVar7 * (float10)_DAT_006c5fc0 * (float10)_DAT_00666a4c);
        }
        if ((0 < *(int *)(extraout_ECX + 0x5c)) && (*(short *)(iVar3 + 0x16) != 0)) {
          iVar3 = FUN_0042573e((int)*(short *)(iVar3 + 0x14));
          if (iVar3 != 0) {
            uVar4 = FUN_0045741b();
            uVar4 = FUN_004e988f(uVar4);
            FUN_005c1719();
            *(undefined1 *)(unaff_EBP + -4) = 1;
            cVar2 = FUN_004e93e4(uVar4,unaff_EBP + 8);
            if (cVar2 != '\0') {
              uVar4 = FUN_004096c2(1,extraout_ECX + 0xe8);
              FUN_004cad42(uVar4);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_005a5e09();
          }
          cVar2 = FUN_005a5e72();
          if (cVar2 != '\0') {
            iVar3 = *piVar1;
            uVar4 = FUN_004096c2(0);
            (**(code **)(iVar3 + 0x228))(uVar4);
            uVar4 = FUN_005d4956(&DAT_006de560);
            iVar3 = *piVar1;
            *(undefined1 *)(unaff_EBP + -4) = 2;
            (**(code **)(iVar3 + 0x220))(uVar4);
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_005b8770();
            (**(code **)(*piVar1 + 0x1b8))();
            (**(code **)(*piVar1 + 0x168))();
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00458449();
        goto LAB_0048e2cb;
      }
    }
  }
  if (0 < *(int *)(extraout_ECX + 0x5c)) {
    uVar4 = FUN_0051cedd();
    (**(code **)(*piVar1 + 0x228))(uVar4,0);
    FUN_005d48d9();
    iVar3 = *(int *)(extraout_ECX + 0x4c);
    iVar5 = *(int *)(extraout_ECX + 0x60);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    iVar5 = iVar5 * 0x28;
    if (*(int *)(iVar5 + 4 + iVar3) != *(int *)(iVar5 + iVar3)) {
      FUN_00431779(*(int *)(iVar5 + iVar3),
                   (*(int *)(iVar5 + 4 + iVar3) - *(int *)(iVar5 + iVar3)) + *(int *)(iVar5 + iVar3)
                  );
    }
    (**(code **)(*piVar1 + 0x220))(unaff_EBP + -0x20);
    (**(code **)(*piVar1 + 0x1b8))();
    (**(code **)(*piVar1 + 0x168))();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
LAB_0048e2cb:
  FUN_00587d3f(*(undefined4 *)(unaff_EBP + -0x10));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

