
void FUN_004b5090(void)

{
  int iVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  short sVar5;
  char *pcVar6;
  int iVar7;
  undefined4 extraout_ECX;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  pcVar6 = *(char **)(unaff_EBP + 8);
  cVar2 = *pcVar6;
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  if ('\0' < cVar2) {
    iVar7 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if (((cVar2 < iVar7) && (cVar3 = pcVar6[1], '\0' < cVar3)) && (cVar3 < iVar7)) {
      sVar4 = *(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x28 + pcVar6[2] * 4) + 0xc) +
                                 cVar2 * 4) + cVar3 * 2);
      iVar7 = __ftol();
      *(int *)(unaff_EBP + -0x2c) = iVar7;
      iVar8 = -iVar7;
      *(int *)(unaff_EBP + -0x28) = iVar8;
      for (; iVar8 <= iVar7; iVar8 = iVar8 + 1) {
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x28);
        if (*(int *)(unaff_EBP + -0x28) <= iVar7) {
          do {
            *(undefined1 *)(unaff_EBP + -0xe) = 0;
            *(undefined1 *)(unaff_EBP + -0x10) = *(undefined1 *)(unaff_EBP + -0x18);
            *(char *)(unaff_EBP + -0xf) = (char)iVar8;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_0046185f(unaff_EBP + -0x14,unaff_EBP + -0x10);
            *(undefined1 *)(unaff_EBP + -4) = 2;
            iVar7 = DAT_006e53d8;
            if ('\0' < *(char *)(unaff_EBP + -0x14)) {
              iVar1 = *(int *)(DAT_006e54dc + 0x10) + -1;
              if (((*(char *)(unaff_EBP + -0x14) < iVar1) && ('\0' < *(char *)(unaff_EBP + -0x13)))
                 && (*(char *)(unaff_EBP + -0x13) < iVar1)) {
                sVar5 = *(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x28 +
                                                             *(char *)(unaff_EBP + -0x12) * 4) + 0xc
                                                    ) + *(char *)(unaff_EBP + -0x14) * 4) +
                                  *(char *)(unaff_EBP + -0x13) * 2);
                if (sVar5 == sVar4) {
LAB_004b5209:
                  FUN_004b523c(*(undefined4 *)(unaff_EBP + -0x18),iVar8);
                }
                else if (sVar5 == -5) {
                  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                  *(undefined4 *)(unaff_EBP + -0x20) = 0;
                  if (iVar7 != 0) {
                    FUN_004672d0(unaff_EBP + -0x14,unaff_EBP + -0x1c,unaff_EBP + -0x20,
                                 unaff_EBP + -0x34,unaff_EBP + -0x30);
                    if (((*(short **)(unaff_EBP + -0x1c) != (short *)0x0) &&
                        (**(short **)(unaff_EBP + -0x1c) == sVar4)) ||
                       ((*(short **)(unaff_EBP + -0x20) != (short *)0x0 &&
                        (**(short **)(unaff_EBP + -0x20) == sVar4)))) goto LAB_004b5209;
                  }
                }
              }
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
            iVar7 = *(int *)(unaff_EBP + -0x2c);
          } while (*(int *)(unaff_EBP + -0x18) <= iVar7);
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

