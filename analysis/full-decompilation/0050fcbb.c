
void FUN_0050fcbb(void)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar10;
  undefined1 auStack_8c [4];
  undefined4 uStack_88;
  uint uStack_84;
  int iStack_80;
  
  FUN_00634c24();
  iVar4 = *(int *)(extraout_ECX + 0x10c);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x21c;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x7f;
  *(undefined4 *)(unaff_EBP + -0x78) = 0;
  *(undefined4 *)(unaff_EBP + -0x74) = 0;
  *(undefined4 *)(unaff_EBP + -0x70) = 0xa8;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0x7f;
  *(undefined4 *)(unaff_EBP + -0x68) = 0x174;
  *(undefined4 *)(unaff_EBP + -0x60) = 0x21c;
  *(undefined4 *)(unaff_EBP + -100) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0x7f;
  if (iVar4 != 0) {
    iStack_80 = 0x50fd14;
    cVar1 = FUN_00510725();
    if (cVar1 == '\0') {
      *(undefined4 *)(unaff_EBP + -0x28) = 5;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x70);
    }
    iStack_80 = 0x50fd34;
    cVar1 = FUN_00510725();
    iVar4 = DAT_006e486c;
    if (cVar1 == '\0') {
      *(undefined4 *)(unaff_EBP + -0x20) = 0x217;
      if (*(char *)(iVar4 + 100) == '\x13') {
        *(undefined4 *)(unaff_EBP + -0x20) = 0x212;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x68);
    }
    uVar2 = (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x58))();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
    uVar10 = *(uint *)(*(int *)(extraout_ECX + 0x10c) + 0xc);
    uVar3 = *(int *)(*(int *)(extraout_ECX + 0x10c) + 0x10) + uVar10;
    *(uint *)(unaff_EBP + -0x14) = uVar3;
    if (uVar10 < uVar3) {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28);
      do {
        iVar4 = (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x58))();
        piVar8 = *(int **)(extraout_ECX + 0xdc);
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar4;
        iStack_80 = *(int *)(unaff_EBP + -0x14) - uVar10;
        uStack_88 = 0x50fda8;
        uStack_84 = uVar10;
        iVar4 = (**(code **)(*piVar8 + 0x60))();
        uVar10 = uVar10 + iVar4;
      } while (uVar10 < *(uint *)(unaff_EBP + -0x14));
    }
    if (*(int *)(unaff_EBP + -0x10) + 0x18 < 0x7f) {
      *(undefined4 *)(unaff_EBP + -0x10) = 0x67;
    }
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  iVar4 = *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80);
  *(int *)(unaff_EBP + -0x18) = *(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c);
  iVar5 = *(int *)(unaff_EBP + -0x1c) + 0x18;
  if (iVar4 != iVar5) {
    iVar4 = iVar5;
  }
  cVar1 = FUN_004cff80();
  if (cVar1 != '\0') {
    iVar4 = iVar4 + 0x32;
  }
  if (*(int *)(extraout_ECX + 0x108) == 0) {
    iStack_80 = 0x50fe0d;
    pvVar6 = operator_new(100);
    *(void **)(unaff_EBP + -0x14) = pvVar6;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar6 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_005dfb13();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x108) = uVar2;
  }
  cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x18))();
  if (cVar1 != '\0') {
    iStack_80 = 0;
    uStack_84 = 0;
    uVar2 = **(undefined4 **)(extraout_ECX + 0x108);
    *(undefined1 **)(unaff_EBP + -0x14) = auStack_8c;
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    FUN_00436a50(4);
    cVar1 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0xc))
                      (*(undefined4 *)(unaff_EBP + -0x18),iVar4);
    if (cVar1 != '\0') {
      FUN_004cff80();
      cVar1 = FUN_005df69e();
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x20))(0x10);
        if (cVar1 != '\0') {
          iVar4 = *(int *)(extraout_ECX + 0x104);
          *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(iVar4 + 0x14);
          *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar4 + 0x18);
          iVar5 = *(int *)(iVar4 + 0x1c);
          *(int *)(unaff_EBP + -0x50) = iVar5;
          iVar7 = *(int *)(iVar4 + 0x20);
          *(int *)(unaff_EBP + -0x50) = iVar5 / 3;
          piVar8 = *(int **)(extraout_ECX + 0x108);
          *(int *)(unaff_EBP + -0x4c) = iVar7 / 3;
          (**(code **)(*piVar8 + 0xc0))(iVar4,unaff_EBP + -0x58,piVar8 + 5,1);
          (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x24))(0x10);
        }
        FUN_004ec186(*(int *)(*(int *)(extraout_ECX + 0x108) + 0x1c) -
                     *(int *)(*(int *)(extraout_ECX + 0x108) + 0x14));
        FUN_004ec1a7(*(int *)(*(int *)(extraout_ECX + 0x108) + 0x20) -
                     *(int *)(*(int *)(extraout_ECX + 0x108) + 0x18));
        if (*(int *)(extraout_ECX + 0x10c) != 0) {
          piVar8 = *(int **)(extraout_ECX + 0xd8);
          *(undefined4 *)(unaff_EBP + -0x44) = 0xc;
          iVar4 = *(int *)(unaff_EBP + -0x28) + 10;
          *(int *)(unaff_EBP + -0x48) = iVar4;
          iVar5 = *(int *)(unaff_EBP + -0x20) + 10;
          iVar7 = *(int *)(unaff_EBP + -0x1c) + 0xc;
          *(int *)(unaff_EBP + -0x40) = iVar5;
          *(int *)(unaff_EBP + -0x18) = iVar7;
          *(int *)(unaff_EBP + -0x3c) = iVar7;
          iVar7 = (**(code **)(*piVar8 + 0x58))();
          iVar7 = iVar7 + *(int *)(unaff_EBP + -0x44);
          *(int *)(unaff_EBP + -0x28) = iVar4;
          *(int *)(unaff_EBP + -0x20) = iVar5;
          *(int *)(unaff_EBP + -0x3c) = iVar7;
          *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x18);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          *(int *)(unaff_EBP + -0x24) = (iVar7 - *(int *)(unaff_EBP + -0x44)) + 0xc;
          do {
            iVar4 = *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80);
            if (*(int *)(unaff_EBP + -0x10) == 1) {
              cVar1 = FUN_004cff80();
              if (cVar1 != '\0') {
LAB_0050ffbe:
                iVar4 = iVar4 + -0x32;
              }
            }
            else if ((*(int *)(unaff_EBP + -0x10) == 0) &&
                    (piVar8 = (int *)FUN_005caed9(), *piVar8 == 0x400)) goto LAB_0050ffbe;
            iVar7 = *(int *)(unaff_EBP + -0x10) * 0x10;
            iVar5 = unaff_EBP + -0x78 + iVar7;
            if (*(int *)(unaff_EBP + -0x6c + iVar7) - *(int *)(iVar5 + 4) < iVar4) {
              iVar9 = ((*(int *)(iVar5 + 4) - *(int *)(iVar5 + 0xc)) + iVar4) / 2 -
                      *(int *)(unaff_EBP + -0x74 + iVar7);
              *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + iVar9;
              *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + iVar9;
              iVar7 = *(int *)(unaff_EBP + -0x6c + iVar7);
              iVar9 = *(int *)(*(int *)(extraout_ECX + 0x108) + 0x20);
              if (iVar9 < iVar7) {
                iVar9 = iVar9 - iVar7;
                *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + iVar9;
                *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + iVar9;
              }
              iVar4 = ((*(int *)(iVar5 + 4) - *(int *)(iVar5 + 0xc)) + iVar4) / 2 + -5;
              *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) - iVar4;
              *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + iVar4;
            }
            cVar1 = FUN_00510725(*(undefined4 *)(unaff_EBP + -0x10));
            if (cVar1 != '\0') {
              cVar1 = (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x108) + 0x5c) + 0x20))(1);
              if (cVar1 != '\0') {
                (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x108) + 0x5c) + 0x40))
                          (0xffff,iVar5,0);
                (**(code **)(**(int **)(*(int *)(extraout_ECX + 0x108) + 0x5c) + 0x24))(1);
              }
              FUN_005105d2(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(extraout_ECX + 0x108),
                           iVar5);
            }
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          } while (*(int *)(unaff_EBP + -0x10) < 2);
          (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x80))
                    (*(undefined4 *)(extraout_ECX + 0x108),unaff_EBP + -0x48,
                     *(undefined4 *)(*(int *)(extraout_ECX + 0x10c) + 4),
                     *(undefined4 *)(*(int *)(extraout_ECX + 0x10c) + 8),0);
          (**(code **)(**(int **)(extraout_ECX + 0xdc) + 0x80))
                    (*(undefined4 *)(extraout_ECX + 0x108),unaff_EBP + -0x28,
                     *(undefined4 *)(*(int *)(extraout_ECX + 0x10c) + 0xc),
                     *(undefined4 *)(*(int *)(extraout_ECX + 0x10c) + 0x10),0);
        }
        piVar8 = *(int **)(extraout_ECX + 0x114);
        *(int *)(unaff_EBP + -0x38) = piVar8[0x1f];
        *(int *)(unaff_EBP + -0x34) = piVar8[0x20];
        *(int *)(unaff_EBP + -0x30) = piVar8[0x21];
        *(int *)(unaff_EBP + -0x2c) = piVar8[0x22];
        iVar4 = (**(code **)(*piVar8 + 0x18))();
        if (iVar4 != 0) {
          FUN_00436feb(unaff_EBP + -0x38,unaff_EBP + -0x34);
          FUN_00436feb(unaff_EBP + -0x30,unaff_EBP + -0x2c);
        }
        iVar4 = *(int *)(extraout_ECX + 0x80);
        iVar5 = *(int *)(extraout_ECX + 0x88);
        if (*(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x34) == 0x96) {
          *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) + 0x32;
        }
        FUN_004cb21d((*(int *)(extraout_ECX + 0x7c) - *(int *)(extraout_ECX + 0x84)) +
                     *(int *)(unaff_EBP + -0x30),(iVar4 - iVar5) + *(int *)(unaff_EBP + -0x34));
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

