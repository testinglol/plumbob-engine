
void FUN_0047f9d2(void)

{
  short sVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int unaff_EBP;
  int *piVar5;
  bool bVar6;
  
  FUN_00634c24();
  piVar5 = *(int **)(unaff_EBP + 8);
  if ((*piVar5 == -1) && (piVar5[1] == -1)) {
    *(undefined1 *)(unaff_EBP + 0xb) = 1;
  }
  else {
    *(undefined1 *)(unaff_EBP + 0xb) = 0;
  }
  if (*(short *)(unaff_EBP + 0x14) < 0x100) {
    if (*(char *)(unaff_EBP + 0xb) == '\0') {
      FUN_0046fb9b(unaff_EBP + -0x118,0x100);
      sVar1 = *(short *)((int)piVar5 + 6);
      *(undefined ***)(unaff_EBP + -0x124) = &PTR_LAB_0066655c;
      FUN_00635858(*(undefined4 *)(unaff_EBP + -0x120),s__params__d___d___d___d__006c55a0,
                   (int)(short)*piVar5,(int)*(short *)((int)piVar5 + 2),(int)(short)piVar5[1],
                   (int)sVar1);
      FUN_0046f917(unaff_EBP + -0x124,0xffffffff);
    }
  }
  else {
    FUN_0047408c(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0xc),*(undefined4 *)(unaff_EBP + 0x14))
    ;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0047417a();
    if (*(char *)(unaff_EBP + -0x429) == '\0') {
      iVar4 = FUN_004742a0(0);
      *(int *)(unaff_EBP + -0x18) = iVar4;
      if (0 < iVar4) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        uVar2 = *(undefined4 *)(unaff_EBP + 0x10);
        do {
          cVar3 = FUN_00474276(*(undefined4 *)(unaff_EBP + -0x10));
          if (cVar3 != '\0') {
            iVar4 = *(int *)(unaff_EBP + -0x14);
            bVar6 = false;
            if (iVar4 == 0) {
              FUN_0046f847(s__with_006c5580,0xffffffff);
              iVar4 = *(int *)(unaff_EBP + -0x14);
              bVar6 = iVar4 == 0;
            }
            if (!bVar6 && -1 < iVar4) {
              FUN_0046f847(&DAT_006c25a8,0xffffffff);
            }
            FUN_0046f824(unaff_EBP + -0x224,0,0x100);
            *(undefined ***)(unaff_EBP + -0x230) = &PTR_FUN_00666524;
            FUN_0047422f(0,*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x230);
            FUN_0046f917(unaff_EBP + -0x230,0xffffffff);
            FUN_0046f847(&DAT_006c42ec,0xffffffff);
            if (*(char *)(unaff_EBP + 0xb) == '\0') {
              FUN_0046fa40((int)(short)*piVar5);
              if (*(int *)(unaff_EBP + -0x10) == 3) break;
            }
            else {
              FUN_0047e457(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0xc),8,
                           *(undefined4 *)(unaff_EBP + -0x10),uVar2,
                           *(undefined4 *)(unaff_EBP + 0x14));
            }
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
          piVar5 = (int *)((int)piVar5 + 2);
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
        if (0 < *(int *)(unaff_EBP + -0x14)) {
          FUN_0046f847(&DAT_006c3cd4,0xffffffff);
        }
      }
    }
    else if (*(char *)(unaff_EBP + 0xb) == '\0') {
      FUN_0046fb9b(unaff_EBP + -0x118,0x100);
      sVar1 = *(short *)((int)piVar5 + 6);
      *(undefined ***)(unaff_EBP + -0x124) = &PTR_LAB_0066655c;
      FUN_00635858(*(undefined4 *)(unaff_EBP + -0x120),s__stack__d___d___d___d__006c5588,
                   (int)(short)*piVar5,(int)*(short *)((int)piVar5 + 2),(int)(short)piVar5[1],
                   (int)sVar1);
      FUN_0046f917(unaff_EBP + -0x124,0xffffffff);
    }
    else {
      FUN_0046fa24(0x28);
      FUN_0047fc4a(4,*(undefined4 *)(unaff_EBP + 0x10));
      FUN_0046fa24(0x29);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00474121();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

