
undefined4 * FUN_005d6303(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  undefined4 *puVar9;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0055e4e2(unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = extraout_ECX + 4;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_006697ec;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 8));
  while ((extraout_ECX[5] != *piVar1 &&
         (*(char *)((extraout_ECX[5] - *piVar1) + -1 + *piVar1) == ' '))) {
    FUN_00406466((extraout_ECX[5] - *piVar1) + -1,1);
  }
  while ((extraout_ECX[5] != *piVar1 && (*(char *)*piVar1 == ' '))) {
    FUN_00406466(0,1);
  }
  if (extraout_ECX[5] == *piVar1) {
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    puVar9 = extraout_ECX;
  }
  else {
    iVar3 = extraout_ECX[5];
    iVar4 = *piVar1;
    iVar5 = 0;
    iVar8 = 0;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < iVar3 - iVar4) {
      do {
        cVar2 = *(char *)(*piVar1 + iVar8);
        if (((cVar2 == '\n') || (cVar2 == '\t')) || (cVar2 == ' ')) {
          if ((*(byte *)(unaff_EBP + 8) & 1) == 0) {
            iVar7 = *piVar1 + iVar5;
            *(undefined4 *)(unaff_EBP + 8) = 0;
            FUN_00431779(iVar7,(iVar7 - iVar5) + iVar8);
            if ((**(char **)(unaff_EBP + -0x20) == '\"') &&
               (*(char *)(*(int *)(unaff_EBP + -0x1c) + -1) == '\"')) {
              FUN_00406466((*(int *)(unaff_EBP + -0x1c) - (int)*(char **)(unaff_EBP + -0x20)) + -1,1
                          );
              if (*(int *)(unaff_EBP + -0x1c) != *(int *)(unaff_EBP + -0x20)) {
                FUN_00406466(0,1);
              }
            }
            FUN_004054fa(unaff_EBP + -0x20);
            for (pcVar6 = (char *)(*piVar1 + 1 + iVar8); *pcVar6 == ' '; pcVar6 = pcVar6 + 1) {
              iVar8 = iVar8 + 1;
            }
            iVar5 = iVar8 + 1;
          }
        }
        else if (cVar2 == '\"') {
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar3 - iVar4);
    }
    FUN_00431779(*piVar1 + iVar5,((*piVar1 + iVar5) - iVar5) + iVar8);
    if ((**(char **)(unaff_EBP + -0x20) == '\"') &&
       (*(char *)(*(int *)(unaff_EBP + -0x1c) + -1) == '\"')) {
      FUN_00406466((*(int *)(unaff_EBP + -0x1c) - (int)*(char **)(unaff_EBP + -0x20)) + -1,1);
      if (*(int *)(unaff_EBP + -0x1c) != *(int *)(unaff_EBP + -0x20)) {
        FUN_00406466(0,1);
      }
    }
    FUN_004054fa(unaff_EBP + -0x20);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    puVar9 = *(undefined4 **)(unaff_EBP + -0x14);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar9;
}

