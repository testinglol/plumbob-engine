
int FUN_00551013(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(extraout_ECX + 0xf0);
  if (piVar1 != (int *)0x0) {
    iVar4 = piVar1[0x35];
    if (iVar4 == 4) {
      iVar4 = FUN_0042ba25(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x44));
      if (iVar4 == 2) {
        iVar4 = 0x15;
        goto LAB_0055117c;
      }
      if (*(int *)(*(int *)(extraout_ECX + 0xe0) + 0x24) == -1) {
        iVar4 = 0x14;
        goto LAB_0055117c;
      }
    }
    else {
      iVar2 = *(int *)(extraout_ECX + 0xe0);
      if (*(int *)(iVar2 + 0x14) != 0) {
        if (iVar4 == 1) {
          iVar4 = 8;
        }
        else {
          iVar4 = ((piVar1[0x35] != 2) - 1 & 3) + 6;
        }
        goto LAB_0055117c;
      }
      if (*(int *)(iVar2 + 0x24) == -1) {
        if (iVar4 == 1) {
          iVar4 = FUN_0042ba25(*(undefined4 *)(iVar2 + 0x44));
          if (iVar4 == 2) {
            iVar4 = 0x12;
          }
          else {
            (**(code **)(*piVar1 + 0x1a4))(unaff_EBP + -0x18);
            *(undefined4 *)(unaff_EBP + -4) = 0;
            uVar5 = FUN_004096c2();
            FUN_005d4bbf(uVar5);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
            if (*(int *)(*(int *)(extraout_ECX + 0xe0) + 0x18) == 0) {
              cVar3 = (**(code **)(*piVar1 + 0x1a8))
                                (*(int *)(extraout_ECX + 0xe0),*(undefined4 *)(unaff_EBP + 0x10),
                                 *(undefined4 *)(unaff_EBP + 0x14));
              iVar4 = (cVar3 != '\0') + 4;
            }
            else {
              cVar3 = (**(code **)(*piVar1 + 0x1a8))();
              iVar4 = (cVar3 != '\0') + 2;
            }
          }
        }
        else if (iVar4 == 2) {
          iVar4 = 0xb - (uint)(*(int *)(iVar2 + 0x18) != 0);
        }
        else if (iVar4 == 3) {
          iVar4 = 0x13;
        }
        else {
          iVar4 = FUN_0042ba25(*(undefined4 *)(iVar2 + 0x44));
          iVar4 = (-(uint)(iVar4 != 1) & 0x10) + 1;
        }
        goto LAB_0055117c;
      }
      if ((iVar4 == 2) || (iVar4 == 3)) {
        iVar4 = 9;
        goto LAB_0055117c;
      }
    }
  }
  iVar4 = 0;
LAB_0055117c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

