
uint FUN_00476f33(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_EBP;
  int iVar9;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  iVar9 = piVar2[1];
  iVar3 = *piVar2;
  iVar7 = piVar2[3] >> 4;
  uVar5 = piVar2[2] >> 4;
  *(int *)(unaff_EBP + -0x1c) = iVar7;
  iVar9 = iVar9 + -1 >> 4;
  *(uint *)(unaff_EBP + -0x18) = uVar5;
  uVar4 = uVar5;
  do {
    if (iVar3 + -1 >> 4 < (int)uVar4) {
      uVar5 = uVar5 & 0xffff0000;
LAB_004770bc:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar5;
    }
    *(int *)(unaff_EBP + -0x14) = iVar7;
    if (iVar7 <= iVar9) {
      do {
        *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(unaff_EBP + -0x14);
        *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + 0xc);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        uVar5 = FUN_00479737(unaff_EBP + -0x48,unaff_EBP + 8);
        if (*(int *)(unaff_EBP + -0x48) == 0) {
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
        }
        else {
          uVar5 = 1;
          if (((byte)*(undefined4 *)(unaff_EBP + -0x48) & 1) != 1) {
            do {
              uVar5 = uVar5 * 2;
            } while ((uVar5 & *(uint *)(unaff_EBP + -0x48)) != uVar5);
          }
          *(uint *)(unaff_EBP + -0x10) = uVar5;
        }
        uVar4 = *(uint *)(unaff_EBP + -0x10);
        while (uVar4 != 0) {
          iVar7 = FUN_00435221(*(undefined4 *)(unaff_EBP + -0x10),0);
          sVar1 = *(short *)(unaff_EBP + -0x40 + iVar7 * 2);
          if ((((sVar1 != 3) && (sVar1 != 5)) && (sVar1 != 6)) &&
             ((sVar1 != 0xf && (sVar1 != 0x17)))) {
            iVar7 = *(int *)(unaff_EBP + -0x10);
            if (iVar7 == 1) {
              iVar7 = piVar2[3];
              iVar8 = piVar2[1];
              iVar6 = (int)*(char *)(unaff_EBP + 8) << 4;
            }
            else if (iVar7 == 2) {
              iVar7 = piVar2[2];
              iVar8 = *piVar2;
              iVar6 = (int)*(char *)(unaff_EBP + 9) << 4;
            }
            else if (iVar7 == 0x10) {
              iVar7 = *piVar2 + piVar2[1];
              iVar6 = (*(char *)(unaff_EBP + 9) + 1 + (int)*(char *)(unaff_EBP + 8)) * 0x10;
              iVar8 = piVar2[3] + piVar2[2];
            }
            else {
              if (iVar7 != 0x20) goto LAB_00477077;
              iVar7 = piVar2[2] - piVar2[1];
              iVar6 = ((int)*(char *)(unaff_EBP + 9) - (int)*(char *)(unaff_EBP + 8)) * 0x10;
              iVar8 = *piVar2 - piVar2[3];
            }
            if (((iVar7 < iVar6) && (iVar6 < iVar8)) || ((iVar6 < iVar7 && (iVar8 < iVar6)))) {
              uVar5 = CONCAT22((short)((uint)iVar6 >> 0x10),1);
              goto LAB_004770bc;
            }
          }
LAB_00477077:
          uVar5 = *(uint *)(unaff_EBP + -0x10);
          do {
            uVar5 = uVar5 * 2;
            if ((uVar5 & *(uint *)(unaff_EBP + -0x48)) == uVar5) break;
          } while ((int)uVar5 < 0x20);
          if (0x1f < (int)uVar5) break;
          *(uint *)(unaff_EBP + -0x10) = uVar5;
          uVar4 = uVar5;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(int *)(unaff_EBP + -0x14) <= iVar9);
      iVar7 = *(int *)(unaff_EBP + -0x1c);
    }
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
    uVar4 = *(uint *)(unaff_EBP + -0x18);
  } while( true );
}

