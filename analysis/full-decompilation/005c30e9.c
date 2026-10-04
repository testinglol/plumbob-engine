
undefined4 FUN_005c30e9(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  HANDLE pvVar6;
  BOOL BVar7;
  int *extraout_ECX;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b8680();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar8 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x14) = piVar1[1] - *piVar1 >> 2;
  if (iVar8 != extraout_ECX[1]) {
    do {
      uVar5 = FUN_005c2efd(unaff_EBP + -0x50,iVar8);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar5 = FUN_00412a04(unaff_EBP + -0x44,uVar5,&DAT_006cf084);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b86bd(uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005d499c(unaff_EBP + -0x38);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00401729();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      pvVar6 = FindFirstFileA(*(LPCSTR *)(unaff_EBP + -0x2c),(LPWIN32_FIND_DATAA)(unaff_EBP + -400))
      ;
      *(HANDLE *)(unaff_EBP + -0x18) = pvVar6;
      if (pvVar6 != (HANDLE)0xffffffff) {
        do {
          if ((*(byte *)(unaff_EBP + -400) & 0x10) == 0) {
            FUN_005c3270(unaff_EBP + -0x20,unaff_EBP + -0x164);
            FUN_005c174f(unaff_EBP + -0x20);
            iVar2 = piVar1[1];
            iVar3 = *piVar1;
            *(undefined1 *)(unaff_EBP + -4) = 4;
            *(int *)(unaff_EBP + -0x1c) = iVar2;
            *(int *)(unaff_EBP + 8) = iVar3;
            if (iVar3 != iVar2) {
              do {
                cVar4 = FUN_005c17a6(unaff_EBP + -0x10);
                if (cVar4 != '\0') break;
                *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 4;
              } while (*(int *)(unaff_EBP + 8) != *(int *)(unaff_EBP + -0x1c));
            }
            if (*(int *)(unaff_EBP + 8) == piVar1[1]) {
              FUN_005c244d(unaff_EBP + -0x10);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_0042004f();
          }
          BVar7 = FindNextFileA(*(HANDLE *)(unaff_EBP + -0x18),
                                (LPWIN32_FIND_DATAA)(unaff_EBP + -400));
        } while (BVar7 != 0);
      }
      iVar8 = iVar8 + 0xc;
    } while (iVar8 != extraout_ECX[1]);
  }
  if (*(int *)(unaff_EBP + -0x14) == piVar1[1] - *piVar1 >> 2) {
    uVar5 = 5;
  }
  else {
    uVar5 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

