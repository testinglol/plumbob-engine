
int FUN_0055118c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 8);
  piVar1 = *(int **)(extraout_ECX + 0x100);
  iVar6 = 0x22;
  piVar1[0x3a] = iVar5;
  if (piVar1 != (int *)0x0) {
    iVar2 = piVar1[0x35];
    iVar3 = *(int *)(extraout_ECX + 0xe0);
    *(int *)(unaff_EBP + 8) = iVar2;
    if (iVar2 == 4) {
      if (*(int *)(iVar3 + 0x24) == -1) {
        iVar6 = 0x1c;
      }
      else {
        uVar4 = FUN_005566cf(*(int *)(iVar3 + 0x24));
        **(undefined4 **)(unaff_EBP + 0x18) = uVar4;
      }
    }
    else if (*(int *)(iVar3 + 0x14) == 0) {
      iVar2 = *(int *)(iVar3 + 0x24);
      if (iVar2 == -1) {
        if (*(int *)(unaff_EBP + 8) == 1) {
          (**(code **)(*piVar1 + 0x1a4))(unaff_EBP + -0x18);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          uVar4 = FUN_004096c2();
          FUN_005d4bbf(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
          iVar5 = FUN_005565f0(*(undefined4 *)(*(int *)(extraout_ECX + 0xe0) + 0x1c),iVar5,
                               *(undefined4 *)(unaff_EBP + 0x18),*(undefined4 *)(unaff_EBP + 0x1c),
                               *(undefined4 *)(unaff_EBP + 0x10));
          if (iVar5 == -3) {
            iVar6 = 0x26;
          }
          else if (iVar5 == -2) {
            iVar6 = 0x24;
          }
          else if (iVar5 == -1) {
            iVar6 = 0x25;
          }
          else if (iVar5 == 1) {
            iVar6 = 0x1f;
          }
        }
        else if (*(int *)(unaff_EBP + 8) == 2) {
          iVar6 = 0xb - (uint)(*(int *)(iVar3 + 0x18) != 0);
        }
        else {
          iVar6 = 0x1d;
        }
      }
      else if (*(int *)(unaff_EBP + 8) == 2) {
        uVar4 = FUN_005566cf(iVar2);
        iVar6 = 0x23;
        **(undefined4 **)(unaff_EBP + 0x18) = uVar4;
      }
      else {
        uVar4 = FUN_005566cf(iVar2);
        iVar6 = 0x22;
        **(undefined4 **)(unaff_EBP + 0x18) = uVar4;
      }
    }
    else if (iVar2 == 1) {
      iVar6 = 8;
    }
    else {
      iVar6 = ((*(int *)(*(int *)(extraout_ECX + 0xf0) + 0xd4) != 2) - 1 & 3) + 6;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar6;
}

