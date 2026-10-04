
int FUN_004783f6(void)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int extraout_ECX;
  int unaff_EBP;
  int iVar7;
  undefined1 *puVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = 2;
  if (*(int *)(unaff_EBP + 0xc) < 0x17) {
    *(undefined4 *)(unaff_EBP + -0x28) = 1;
  }
  iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,0,1);
  if ((iVar2 == 0) &&
     (iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,4,1), iVar2 == 0)) {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    if (0 < *(int *)(unaff_EBP + -0x28)) {
      iVar7 = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(int *)(unaff_EBP + -0x10) = extraout_ECX + 0x44;
      do {
        iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,iVar7 + 0xb,1);
        if (iVar2 != 0) goto LAB_004786fa;
        pvVar3 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x20) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar3 == (void *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        }
        else {
          uVar4 = FUN_0047c8fb(0x40);
          *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
        }
        iVar2 = *(int *)(extraout_ECX + 0x10);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        if (0 < iVar2) {
          do {
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            if (0 < iVar2) {
              do {
                uVar4 = FUN_0047c7b7(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x14));
                *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
                *(undefined4 *)(unaff_EBP + -4) = 1;
                piVar5 = (int *)FUN_0047c7b7(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + -0x14));
                iVar2 = *piVar5;
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                iVar1 = **(int **)(unaff_EBP + -0x20);
                *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                *(undefined1 *)(*(int *)(unaff_EBP + -0x18) + iVar2) =
                     *(undefined1 *)(iVar1 + *(int *)(unaff_EBP + -0x18) * 2);
              } while (*(int *)(unaff_EBP + -0x14) < *(int *)(extraout_ECX + 0x10));
            }
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
            iVar2 = *(int *)(extraout_ECX + 0x10);
          } while (*(int *)(unaff_EBP + -0x18) < iVar2);
        }
        iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,iVar7 + 1,1);
        if (iVar2 != 0) goto LAB_004786fa;
        if (*(int *)(unaff_EBP + -0x1c) != 0) {
          FUN_00431242();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x1c));
        }
        FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,iVar7 + 0xc,1);
        pvVar3 = operator_new(0x20);
        *(void **)(unaff_EBP + -0x20) = pvVar3;
        *(undefined4 *)(unaff_EBP + -4) = 2;
        if (pvVar3 == (void *)0x0) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
        }
        else {
          uVar4 = FUN_0047d01e(0x40);
          *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
        }
        iVar2 = *(int *)(extraout_ECX + 0x10);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        if (0 < iVar2) {
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          do {
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            if (0 < iVar2) {
              do {
                piVar5 = (int *)FUN_0047c7b7(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x1c));
                puVar8 = (undefined1 *)(*(int *)(unaff_EBP + -0x14) * 8 + *piVar5);
                piVar5 = (int *)FUN_0047c7b7(unaff_EBP + -0x3c,*(undefined4 *)(unaff_EBP + -0x1c));
                puVar6 = (undefined1 *)(*piVar5 + *(int *)(unaff_EBP + -0x20));
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
                *puVar8 = *puVar6;
                puVar8[1] = puVar6[1];
                puVar8[2] = puVar6[2];
                puVar8[3] = puVar6[4];
                puVar8[4] = puVar6[6];
                puVar8[5] = puVar6[8];
                puVar8[6] = puVar6[10];
                puVar8[7] = puVar6[0xc];
              } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(extraout_ECX + 0x10));
              iVar7 = *(int *)(unaff_EBP + -0x2c);
            }
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            iVar2 = *(int *)(extraout_ECX + 0x10);
            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0xe;
          } while (*(int *)(unaff_EBP + -0x14) < iVar2);
        }
        iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,iVar7 + 2,1);
        if (iVar2 != 0) goto LAB_004786fa;
        if (*(int *)(unaff_EBP + -0x18) != 0) {
          FUN_00431242();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x18));
        }
        iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,iVar7 + 3,1);
        if ((iVar2 != 0) ||
           (iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,iVar7 + 8,1), iVar2 != 0)
           ) goto LAB_004786fa;
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
        iVar7 = iVar7 + 100;
        *(int *)(unaff_EBP + -0x2c) = iVar7;
      } while (*(int *)(unaff_EBP + -0x24) <= *(int *)(unaff_EBP + -0x28));
    }
    if ((*(int *)(unaff_EBP + 0xc) < 0x11) ||
       ((iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,6,1), iVar2 == 0 &&
        (iVar2 = FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,7,1), iVar2 == 0)))) {
      if (0x25 < *(int *)(unaff_EBP + 0xc)) {
        FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,9,1);
      }
      if (0x34 < *(int *)(unaff_EBP + 0xc)) {
        FUN_00431289(*(undefined4 *)(unaff_EBP + 8),0x41727279,10,1);
      }
      iVar2 = 0;
    }
  }
LAB_004786fa:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

