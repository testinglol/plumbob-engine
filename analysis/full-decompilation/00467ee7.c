
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00467ee7(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  ushort *extraout_ECX;
  undefined1 uVar6;
  int unaff_EBP;
  int iVar7;
  float10 fVar8;
  
  FUN_00634c24();
  iVar7 = *(int *)(unaff_EBP + 0xc);
  do {
    if (iVar7 == 0) {
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if ((*(short *)(iVar7 + 0x8e) == 0) && (-1 < *(short *)(iVar7 + 0x84))) {
      *(int *)(extraout_ECX + 0x20) = *(int *)(extraout_ECX + 0x20) + 1;
      sVar1 = *(short *)(iVar7 + 0xc0);
      if (sVar1 == 4) {
        *(int *)(extraout_ECX + 0x2c) = *(int *)(extraout_ECX + 0x2c) + 1;
      }
      else if (4 < sVar1) {
        if (sVar1 < 8) {
          *(int *)(extraout_ECX + 0x2e) = *(int *)(extraout_ECX + 0x2e) + 1;
        }
        else if (sVar1 == 8) {
          *(bool *)(extraout_ECX + 0x3a) = (*extraout_ECX & 0x3ff) != 0;
        }
      }
      if (*(short *)(*(int *)(iVar7 + 0x118) + 0x12) == 2) {
        *(int *)(extraout_ECX + 0x142) = *(int *)(extraout_ECX + 0x142) + 1;
      }
      if (((*(ushort *)(iVar7 + 0x9a) & 0x400) != 0) && (cVar4 = FUN_00432644(), cVar4 != '\0')) {
        if (*(short *)(*(int *)(iVar7 + 0x118) + 0x12) != 8) {
          *(int *)(extraout_ECX + 0x140) = *(int *)(extraout_ECX + 0x140) + 1;
        }
        iVar5 = (int)*(short *)(iVar7 + 0xb0);
        if (iVar5 == 0) {
          iVar5 = *(int *)(iVar7 + 0xf4);
          uVar3 = *(undefined4 *)(iVar7 + 0x110);
          *(char *)(unaff_EBP + -0x18) = (char)(*(int *)(iVar7 + 0xf8) >> 4);
          *(char *)(unaff_EBP + -0x17) = (char)(iVar5 >> 4);
          *(char *)(unaff_EBP + -0x16) = (char)uVar3;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_004b52ba(unaff_EBP + -0x18,(int)*(short *)(iVar7 + 0x6a));
        }
        else {
          if (*(short *)(*(int *)(iVar7 + 0x118) + 0x12) == 8) {
            *(int *)(extraout_ECX + 0x22) = *(int *)(extraout_ECX + 0x22) + iVar5;
          }
          else {
            *(int *)(extraout_ECX + 0x24) = *(int *)(extraout_ECX + 0x24) + iVar5;
          }
          if (*(short *)(iVar7 + 0x6a) != 1) goto LAB_0046810f;
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar7 + 0xf4);
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar7 + 0xf8);
          if ((uint)(*(int *)(extraout_ECX + 10) - *(int *)(extraout_ECX + 8) >> 2) < 6) {
            piVar2 = *(int **)(*(int *)(*(int *)(extraout_ECX + 0x3c) + 0x28) +
                              (*(int *)(extraout_ECX + 10) - *(int *)(extraout_ECX + 8) >> 2) * 4);
            *(int **)(unaff_EBP + -0x1c) = piVar2;
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 8))();
            }
            FUN_00468a79(unaff_EBP + -0x1c);
            fVar8 = (float10)FUN_00478f70(unaff_EBP + -0x2c);
            *(float *)(unaff_EBP + -0x20) = (float)fVar8;
            FUN_00454f9c(unaff_EBP + -0x38,unaff_EBP + -0x2c,unaff_EBP + -0x20);
            *(float *)(unaff_EBP + -0x34) = *(float *)(unaff_EBP + -0x34) + _DAT_00667678;
            FUN_00468aa0(unaff_EBP + -0x38);
          }
          iVar5 = *(int *)(iVar7 + 0x110);
          *(char *)(unaff_EBP + -0x10) = (char)(*(int *)(unaff_EBP + -0x28) >> 4);
          *(char *)(unaff_EBP + -0xf) = (char)(*(int *)(unaff_EBP + -0x2c) >> 4);
          uVar6 = (undefined1)iVar5;
          *(undefined1 *)(unaff_EBP + -0xe) = uVar6;
          *(int *)(unaff_EBP + -0x24) = iVar5 * 4 + 100;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_004b52ba(unaff_EBP + -0x10,(int)*(short *)(iVar7 + 0x6a));
          *(undefined1 *)(unaff_EBP + -0x12) = uVar6;
          *(char *)(unaff_EBP + -0x14) = (char)(*(int *)(unaff_EBP + -0x28) >> 4);
          *(char *)(unaff_EBP + -0x13) = (char)(*(int *)(unaff_EBP + -0x2c) >> 4);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          FUN_004b5090(unaff_EBP + -0x14,(int)*(short *)(iVar7 + 0x6a));
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
LAB_0046810f:
      *(int *)(extraout_ECX + 0x26) = *(int *)(extraout_ECX + 0x26) + (int)*(short *)(iVar7 + 0x98);
      iVar7 = (int)*(short *)(iVar7 + 0x58);
      cVar4 = FUN_00468851();
      if (((cVar4 != '\0') && (-1 < iVar7)) ||
         (*(int *)(extraout_ECX + 0x28) = *(int *)(extraout_ECX + 0x28) + iVar7, -1 < iVar7)) {
        *(int *)(extraout_ECX + 0x2a) = *(int *)(extraout_ECX + 0x2a) + 1;
      }
    }
    FUN_0043f3b9();
    iVar7 = *(int *)(unaff_EBP + 0xc);
  } while( true );
}

