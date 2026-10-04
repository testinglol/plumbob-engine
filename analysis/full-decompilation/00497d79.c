
void FUN_00497d79(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  char cVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x4c) == '\0') || (*(char *)(extraout_ECX + 0x30) != '\0'))
  goto LAB_00497fc9;
  *(undefined4 *)(extraout_ECX + 0x38) = 0;
  iVar3 = FUN_00492b26();
  if (iVar3 < 2) {
    iVar3 = DAT_006e57e0 >> 4;
    cVar2 = (char)(DAT_006e57e4 >> 4);
    *(char *)(unaff_EBP + -0x1c) = cVar2;
    cVar5 = (char)iVar3;
    *(char *)(unaff_EBP + -0x1b) = cVar5;
    *(undefined1 *)(unaff_EBP + -0x1a) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(char *)(unaff_EBP + -0x18) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
    *(char *)(unaff_EBP + -0x17) = (char)(*(int *)(unaff_EBP + 8) >> 4);
    *(undefined1 *)(unaff_EBP + -0x16) = 1;
    iVar6 = DAT_006e54d8;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar3 = *(int *)(iVar6 + 0x70) + 1;
    *(int *)(unaff_EBP + -0x14) = iVar3;
    if ((cVar2 < iVar3) ||
       (iVar3 = *(int *)(iVar6 + 0x74) + -1, *(int *)(unaff_EBP + -0x10) = iVar3, iVar3 < cVar2)) {
LAB_00497f9a:
      *(undefined4 *)(extraout_ECX + 0x38) = 1;
    }
    else {
      iVar3 = *(int *)(iVar6 + 0x78) + 1;
      if ((cVar5 < iVar3) ||
         ((((iVar6 = *(int *)(iVar6 + 0x7c) + -1, *(int *)(unaff_EBP + -0x24) = iVar6, iVar6 < cVar5
            || ((int)*(char *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x14))) ||
           (*(int *)(unaff_EBP + -0x10) < (int)*(char *)(unaff_EBP + -0x18))) ||
          ((*(char *)(unaff_EBP + -0x17) < iVar3 ||
           (*(int *)(unaff_EBP + -0x24) < (int)*(char *)(unaff_EBP + -0x17))))))) goto LAB_00497f9a;
      if (*(char *)(unaff_EBP + -0x18) < cVar2) {
        *(char *)(unaff_EBP + -0x1c) = *(char *)(unaff_EBP + -0x18);
        *(char *)(unaff_EBP + -0x18) = cVar2;
      }
      if (*(char *)(unaff_EBP + -0x17) < cVar5) {
        *(char *)(unaff_EBP + -0x1b) = *(char *)(unaff_EBP + -0x17);
        *(char *)(unaff_EBP + -0x17) = cVar5;
      }
      iVar3 = *(int *)(extraout_ECX + 0x48);
      if ((iVar3 != 0) && (0 < iVar3)) {
        FUN_00492bba(iVar3 * DAT_006c618c);
      }
      *(undefined4 *)(extraout_ECX + 0x48) = 0;
      FUN_0047736d(*(undefined4 *)(extraout_ECX + 0x40));
      uVar1 = DAT_006e482b;
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      *(undefined1 *)(unaff_EBP + -0x10) = uVar1;
      *(undefined1 *)(unaff_EBP + -0xf) = DAT_006e482c;
      uVar4 = FUN_0046185f(unaff_EBP + -0x14,unaff_EBP + -0x10);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar4 = FUN_0048f8f5(unaff_EBP + -0x1c,uVar4);
      iVar3 = extraout_ECX + 0x31;
      FUN_0048ec44(uVar4);
      iVar6 = DAT_006e54d8;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0048f0d1(-*(int *)(iVar6 + 0x84) & 3);
      if (*(int *)(extraout_ECX + 0x2c) == 0) {
        cVar2 = FUN_0049847a(iVar3);
        if (cVar2 == '\0') {
LAB_00497f1a:
          uVar4 = FUN_00461e56(0,0,0,0,1);
          FUN_0048ec44(uVar4);
          *(undefined4 *)(extraout_ECX + 0x48) = 0;
        }
        else {
          DAT_006e57d8 = *(undefined4 *)(unaff_EBP + 8);
          DAT_006e57dc = *(undefined4 *)(unaff_EBP + 0xc);
          if (*(int *)(extraout_ECX + 0x48) == 0) {
            *(undefined4 *)(extraout_ECX + 0x38) = 0x1b;
          }
          else {
            FUN_004774ed(iVar3);
            FUN_00492bb0(DAT_006c618c * *(int *)(extraout_ECX + 0x48));
          }
        }
      }
      else {
        cVar2 = FUN_00498291(iVar3);
        if (cVar2 == '\0') goto LAB_00497f1a;
        if (*(int *)(extraout_ECX + 0x48) == 0) {
          *(undefined4 *)(extraout_ECX + 0x38) = 0x1c;
        }
        else {
          FUN_00477655(iVar3);
          FUN_00492cca();
        }
      }
    }
    iVar3 = *(int *)(extraout_ECX + 0x38);
    if (iVar3 != 0) goto LAB_00497fab;
    if (*(int *)(extraout_ECX + 0x2c) != 0) goto LAB_00497fc9;
    iVar6 = *(int *)(extraout_ECX + 0x48) * DAT_006c618c;
    iVar3 = 0x1a;
  }
  else {
    iVar3 = 0x1f;
    *(undefined4 *)(extraout_ECX + 0x38) = 0x1f;
LAB_00497fab:
    iVar6 = -1;
  }
  FUN_004864ed(iVar3,iVar6);
LAB_00497fc9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

