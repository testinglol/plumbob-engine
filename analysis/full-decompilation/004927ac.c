
void FUN_004927ac(void)

{
  char *pcVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_EBP;
  int iVar9;
  
  FUN_00634c24();
  if (((byte)*(int *)(extraout_ECX + 0x2c) & 0xf) == 1) {
    FUN_00492702(unaff_EBP + 8,*(int *)(extraout_ECX + 0x2c) >> 4);
  }
  else if ((*(int *)(extraout_ECX + 0x38) == 2) || (*(int *)(extraout_ECX + 0x38) == 3)) {
    cVar3 = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    *(char *)(unaff_EBP + -0x1c) = cVar3;
    cVar5 = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(char *)(unaff_EBP + -0x1b) = cVar5;
    *(undefined1 *)(unaff_EBP + -0x1a) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pcVar1 = (char *)(extraout_ECX + 0x33);
    if ((((*(char *)(extraout_ECX + 0x33) != cVar3) ||
         ((*(char *)(extraout_ECX + 0x34) != cVar5 || (*(char *)(extraout_ECX + 0x35) != '\x01'))))
        && (*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar3)) &&
       ((((int)cVar3 <= *(int *)(DAT_006e54d8 + 0x74) + -1 &&
         (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)cVar5)) &&
        ((int)cVar5 <= *(int *)(DAT_006e54d8 + 0x7c) + -1)))) {
      *pcVar1 = cVar3;
      *(char *)(extraout_ECX + 0x34) = cVar5;
      *(undefined1 *)(extraout_ECX + 0x35) = 1;
      if (*(int *)(extraout_ECX + 0x38) == 3) {
        FUN_004929ee();
        iVar4 = (int)*(char *)(extraout_ECX + 0x30);
        iVar9 = (int)*pcVar1;
        iVar7 = (int)*(char *)(extraout_ECX + 0x31);
        iVar6 = (int)*(char *)(extraout_ECX + 0x34);
        *(int *)(unaff_EBP + -0x20) = iVar7;
        *(int *)(unaff_EBP + -0x18) = iVar6;
        iVar8 = iVar4;
        if (iVar9 < iVar4) {
          iVar8 = iVar9;
          iVar9 = iVar4;
        }
        if (iVar6 < iVar7) {
          *(int *)(unaff_EBP + -0x20) = iVar6;
          *(int *)(unaff_EBP + -0x18) = iVar7;
        }
        *(undefined1 *)(unaff_EBP + -0x10) = 0;
        *(undefined1 *)(unaff_EBP + -0xf) = 0;
        *(undefined1 *)(unaff_EBP + -0xe) = 1;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        *(int *)(unaff_EBP + -0x14) = iVar8;
        while (iVar8 <= iVar9) {
          for (iVar8 = *(int *)(unaff_EBP + -0x20); iVar8 <= *(int *)(unaff_EBP + -0x18);
              iVar8 = iVar8 + 1) {
            uVar2 = *(undefined4 *)(extraout_ECX + 0x40);
            *(undefined1 *)(unaff_EBP + -0x10) = *(undefined1 *)(unaff_EBP + -0x14);
            *(char *)(unaff_EBP + -0xf) = (char)iVar8;
            FUN_004924fd(unaff_EBP + -0x10,uVar2);
          }
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
          iVar8 = *(int *)(unaff_EBP + -0x14);
        }
      }
      else {
        FUN_004924fd(pcVar1,*(undefined4 *)(extraout_ECX + 0x40));
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

