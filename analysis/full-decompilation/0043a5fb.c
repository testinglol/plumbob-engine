
void FUN_0043a5fb(void)

{
  short sVar1;
  undefined4 uVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar9;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x30) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(*(int *)(unaff_EBP + 8) + 0xc) == 0) {
    FUN_00464a5e(unaff_EBP + -0x10,1);
    iVar8 = *(int *)(unaff_EBP + -0x10);
    piVar9 = extraout_ECX;
    while (iVar8 != 0) {
      iVar8 = *(int *)(unaff_EBP + 0xc);
      if (0 < iVar8) {
        FUN_00464a5e(unaff_EBP + -0x20,1);
        FUN_00464a5e(unaff_EBP + -0x24,1);
      }
      FUN_00464973(unaff_EBP + -0x1c,1);
      if (iVar8 < 2) {
        *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
      }
      else {
        FUN_00464973(unaff_EBP + -0x18,1);
      }
      FUN_00464c84(unaff_EBP + -0x50);
      if (iVar8 < 3) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        FUN_00464a5e(unaff_EBP + -0x14,1);
      }
      uVar5 = FUN_00415747(*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
      iVar6 = FUN_0043acf5(uVar5);
      if (iVar6 == 0) {
        if (piVar9[1] != 0) {
          pvVar7 = operator_new(0x1c);
          *(void **)(unaff_EBP + -0x38) = pvVar7;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          if (pvVar7 == (void *)0x0) {
            pvVar7 = (void *)0x0;
          }
          else {
            uVar5 = *(undefined4 *)(unaff_EBP + -0x1c);
            sVar1 = *(short *)(unaff_EBP + -0x18);
            *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
            *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x10);
            FUN_005b86bd(unaff_EBP + -0x50);
            uVar2 = *(undefined4 *)(unaff_EBP + -0x28);
            *(short *)((int)pvVar7 + 0x18) = (short)uVar5;
            piVar9 = *(int **)(unaff_EBP + -0x30);
            *(undefined4 *)((int)pvVar7 + 0xc) = uVar2;
            uVar5 = *(undefined4 *)(unaff_EBP + -0x2c);
            *(int *)((int)pvVar7 + 0x14) = (int)sVar1;
            *(undefined4 *)((int)pvVar7 + 0x10) = uVar5;
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          *(void **)(unaff_EBP + -0x34) = pvVar7;
          FUN_0043e394(unaff_EBP + -0x34);
        }
      }
      else {
        *(undefined2 *)(iVar6 + 0xa4) = *(undefined2 *)(unaff_EBP + -0x1c);
        if (iVar8 < 1) {
          cVar4 = FUN_0045773e();
          *(uint *)(iVar6 + 0xb4) = *(uint *)(iVar6 + 0xb4) & 0xfffffffd;
          if (cVar4 != '\0') {
            *(uint *)(iVar6 + 0xb4) = *(uint *)(iVar6 + 0xb4) | 2;
          }
        }
        else {
          iVar8 = FUN_00457759();
          if ((iVar8 == *(int *)(unaff_EBP + -0x20)) &&
             (iVar8 = FUN_0045778a(), iVar8 == *(int *)(unaff_EBP + -0x24))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          *(uint *)(iVar6 + 0xb4) = *(uint *)(iVar6 + 0xb4) & 0xfffffffd;
          if (bVar3) {
            *(uint *)(iVar6 + 0xb4) = *(uint *)(iVar6 + 0xb4) | 2;
          }
        }
      }
      FUN_00464a5e(unaff_EBP + -0x10,1);
      iVar8 = *(int *)(unaff_EBP + -0x10);
    }
  }
  else {
    FUN_005b8680();
    iVar8 = *extraout_ECX;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    for (piVar9 = *(int **)(iVar8 + 0x20); piVar9 != *(int **)(iVar8 + 0x24); piVar9 = piVar9 + 1) {
      sVar1 = *(short *)(*piVar9 + 0xa4);
      if (sVar1 != 0) {
        *(uint *)(unaff_EBP + -0x1c) = CONCAT22((short)((uint)*piVar9 >> 0x10),sVar1);
        uVar5 = FUN_0045741b();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(*piVar9 + 0x60) + 0x8c);
        uVar5 = FUN_00457759();
        *(undefined4 *)(unaff_EBP + -0x20) = uVar5;
        uVar5 = FUN_0045778a();
        *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
        *(uint *)(unaff_EBP + -0x18) =
             CONCAT22((short)((uint)*(int *)(*piVar9 + 0x60) >> 0x10),
                      *(undefined2 *)(*(int *)(*piVar9 + 0x60) + 0x12));
        if ((*(short *)(*(int *)(*piVar9 + 0x60) + 0x14) == 0) ||
           (*(short *)(*(int *)(*piVar9 + 0x60) + 0x16) == -1)) {
          uVar5 = FUN_00457ea7();
          FUN_005d499c(uVar5);
        }
        else {
          FUN_005d4bbf(&DAT_006de560);
        }
        FUN_00464a5e(unaff_EBP + -0x10,1);
        FUN_00464a5e(unaff_EBP + -0x20,1);
        FUN_00464a5e(unaff_EBP + -0x24,1);
        FUN_00464973(unaff_EBP + -0x1c,1);
        FUN_00464973(unaff_EBP + -0x18,1);
        FUN_00464c84(unaff_EBP + -0x44);
        if (*(int *)(unaff_EBP + 0xc) < 3) {
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
        }
        else {
          FUN_00464a5e(unaff_EBP + -0x14,1);
        }
      }
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_00464a5e(unaff_EBP + -0x10,1);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

