
undefined1 FUN_00497140(void)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined1 *puVar3;
  int *piVar4;
  int *piVar5;
  short sVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar3 = *(undefined1 **)(unaff_EBP + 8);
  piVar4 = *(int **)(unaff_EBP + 0x10);
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *piVar4 = 0;
  *(undefined1 *)(unaff_EBP + 0x10) = *puVar3;
  uVar1 = puVar3[2];
  *(undefined1 *)(unaff_EBP + 0x11) = puVar3[1];
  *(undefined1 *)(unaff_EBP + 0x12) = uVar1;
  iVar7 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434ffd(-*(int *)(iVar7 + 0x84) & 3);
  FUN_0043f371(*DAT_006e486c,unaff_EBP + 0x10,0);
  piVar5 = *(int **)(unaff_EBP + -0x18);
  do {
    if (piVar5 == (int *)0x0) {
LAB_004972b7:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return *(undefined1 *)(unaff_EBP + -0xd);
    }
    if (*(short *)(piVar5[0x46] + 0x12) == 8) {
      uVar2 = *(ushort *)(piVar5 + 0x19);
      iVar7 = *(int *)(&DAT_006f4620 +
                      ((((int)(-(int)(short)piVar5[0x13] & 7U) >> 1) - *(int *)(DAT_006e54d8 + 0x84)
                       & 3U) * 0x40 + *(int *)(unaff_EBP + 0xc)) * 4);
      if (((((iVar7 == 1) && ((uVar2 & 8) != 0)) || ((iVar7 == 8 && ((uVar2 & 4) != 0)))) ||
          ((iVar7 == 2 && ((uVar2 & 1) != 0)))) || ((iVar7 == 4 && ((uVar2 & 2) != 0)))) {
        if (piVar5 != (int *)0x0) {
          sVar6 = FUN_00432249();
          *(int *)(unaff_EBP + 8) = (int)sVar6;
          iVar7 = __ftol();
          *piVar4 = *piVar4 + iVar7;
          pvVar8 = operator_new(0x88);
          *(void **)(unaff_EBP + 8) = pvVar8;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          if (pvVar8 == (void *)0x0) {
            uVar9 = 0;
          }
          else {
            uVar9 = FUN_0048bb59((short)piVar5[0x3c],3,0,extraout_ECX[0x3811]);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          if (extraout_ECX[0x3810] == 1) {
            (**(code **)(*extraout_ECX + 0x14))();
          }
          else {
            (**(code **)(*extraout_ECX + 0x10))(uVar9);
          }
          (**(code **)(*piVar5 + 0x50))(1);
          extraout_ECX[0x3814] = extraout_ECX[0x3814] + 1;
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
        goto LAB_004972b7;
      }
    }
    FUN_0043f3b9();
    piVar5 = *(int **)(unaff_EBP + -0x18);
  } while( true );
}

