
void FUN_00562616(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *lpFile;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(DAT_006e486c + 0x24);
  FUN_0046f824(unaff_EBP + -0x160,0,0x104);
  *(undefined ***)(unaff_EBP + -0x16c) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(0x55,s_neighborhood_html_006ce01c,unaff_EBP + -0x16c);
  FUN_004eea6b(uVar1);
  if (*(char *)(extraout_ECX + 0x164) == '\0') {
    uVar1 = *(undefined4 *)(extraout_ECX + 0x170);
    piVar6 = (int *)(extraout_ECX + 0x16c);
    *(int **)(unaff_EBP + -0x10) = piVar6;
    FUN_004071be(*piVar6,uVar1);
    FUN_004e2f00(piVar6);
    if ((*(int *)(extraout_ECX + 0x170) - *piVar6 & 0xfffffffcU) != 0) {
      FUN_0057a7f7(s_bkground_fade_006c3bcc,0xffffffff);
      uVar8 = 0;
      uVar7 = 2;
      uVar1 = FUN_004705f2(1,0xffffffff);
      uVar2 = FUN_004705f2(2,0xffffffff);
      iVar3 = FUN_004f6994(uVar2,uVar1,uVar7,uVar8);
      if (iVar3 != 4) {
        FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
        FUN_004071be(**(undefined4 **)(unaff_EBP + -0x10),(*(undefined4 **)(unaff_EBP + -0x10))[1]);
        goto LAB_00562b1f;
      }
    }
    *(undefined1 *)(extraout_ECX + 0x164) = 1;
    FUN_004d3f37(1);
    FUN_005dae65(extraout_ECX);
    FUN_005dadff(extraout_ECX,100,0);
    FUN_005d9dba();
    piVar6 = (int *)**(int **)(extraout_ECX + 0x38);
    if (piVar6 != *(int **)(extraout_ECX + 0x38)) {
      do {
        (**(code **)(*(int *)piVar6[2] + 0x90))(0x400,0);
        (**(code **)(*(int *)piVar6[2] + 0x90))(2,0);
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)*(int *)(extraout_ECX + 0x38));
    }
    goto LAB_00562b1f;
  }
  iVar3 = *(int *)(extraout_ECX + 0x178);
  *(int *)(unaff_EBP + -0x14) = iVar3;
  if (iVar3 == -1) {
    if (*(int *)(extraout_ECX + 0x168) != 0) {
      FUN_005da4c7(*(int *)(extraout_ECX + 0x168));
      *(undefined4 *)(extraout_ECX + 0x168) = 0;
    }
    if ((*(int *)(extraout_ECX + 0x170) - *(int *)(extraout_ECX + 0x16c) & 0xfffffffcU) != 0) {
      piVar6 = *(int **)(extraout_ECX + 0x16c);
      iVar3 = *piVar6;
      *(int *)(unaff_EBP + -0x14) = iVar3;
      FUN_005db2f2(piVar6);
      if (iVar3 != -1) {
        iVar3 = *(int *)(unaff_EBP + -0x14);
        goto LAB_005628b8;
      }
    }
    *(undefined1 *)(extraout_ECX + 0x164) = 0;
    iVar3 = FUN_00428886();
    if (iVar3 != 0) {
      FUN_0042888d();
    }
    FUN_004e325a();
    lpFile = *(char **)(unaff_EBP + -0x168);
    if ((*lpFile == '.') && (lpFile[1] == '/')) {
      lpFile = lpFile + 2;
    }
    ShellExecuteA((HWND)0x0,&DAT_006cd9cc,lpFile,(LPCSTR)0x0,(LPCSTR)0x0,1);
    piVar6 = (int *)**(int **)(extraout_ECX + 0x38);
    if (piVar6 != *(int **)(extraout_ECX + 0x38)) {
      do {
        (**(code **)(*(int *)piVar6[2] + 0x90))(0x400,1);
        (**(code **)(*(int *)piVar6[2] + 0x90))(2,1);
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)*(int *)(extraout_ECX + 0x38));
    }
    (**(code **)(**(int **)(extraout_ECX + 0x154) + 0x90))(0x400,0);
    FUN_004d3f37(0);
    FUN_0057a7f7(s_bkground_nhood1_006cde14,0xffffffff);
    FUN_005dadff(extraout_ECX,1000,0);
    goto LAB_00562b1f;
  }
LAB_005628b8:
  FUN_00429c21();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004e1c79(iVar3,unaff_EBP + -0x5c);
  iVar4 = FUN_00425db3(iVar3);
  iVar4 = *(int *)(iVar4 + 0x10c);
  if ((((iVar4 == 2000) || (iVar4 == 4000)) || (iVar4 == 5000)) ||
     (((iVar4 == 0x157c || (iVar4 == 6000)) || ((2999 < iVar4 && (iVar4 < 0xbc2)))))) {
    iVar3 = *(int *)(extraout_ECX + 0x168);
    if (iVar3 != 0) {
LAB_00562aee:
      FUN_005dac30(0x10,iVar3,0);
    }
    *(undefined4 *)(extraout_ECX + 0x178) = 0xffffffff;
LAB_00562b04:
    FUN_005dadff(extraout_ECX,100,0);
  }
  else {
    if (*(int *)(extraout_ECX + 0x168) != 0) {
      FUN_004d3125();
      FUN_004e2fc2(iVar3);
      iVar3 = *(int *)(extraout_ECX + 0x168);
      if (iVar3 != 0) goto LAB_00562aee;
      goto LAB_00562b04;
    }
    pvVar5 = operator_new(0x148);
    *(void **)(unaff_EBP + -0x10) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar5 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_00523434();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(extraout_ECX + 0x168) = uVar1;
    uVar1 = FUN_004705f2(1,0xffffffff);
    FUN_005d4956(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_00523771(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    FUN_005b870f(s__family_006c28b4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar1 = FUN_004705f2(3,0xffffffff);
    FUN_005d4956(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    uVar1 = FUN_004096c2();
    piVar6 = (int *)FUN_005d4956(uVar1);
    iVar3 = *piVar6;
    iVar4 = piVar6[1];
    *(undefined1 *)(unaff_EBP + -4) = 5;
    iVar3 = FUN_004558e0(iVar3,0,iVar4 - iVar3);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005b8770();
    if (iVar3 != -1) {
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x40);
      uVar1 = FUN_004096c2();
      FUN_00455800(iVar3,*(undefined4 *)(unaff_EBP + -0x10),uVar1);
    }
    FUN_00523be3(unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    FUN_005a5631(0x14e6,unaff_EBP + -0x18,4);
    uVar1 = DAT_006f2a64;
    piVar6 = *(int **)(unaff_EBP + -0x18);
    if (piVar6 != (int *)0x0) {
      *(int *)(unaff_EBP + -0x28) = piVar6[5];
      *(int *)(unaff_EBP + -0x24) = piVar6[6];
      *(int *)(unaff_EBP + -0x20) = piVar6[7];
      *(int *)(unaff_EBP + -0x1c) = piVar6[8];
      (**(code **)(*piVar6 + 0x68))(uVar1);
      FUN_00523b65(*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x28,0);
    }
    FUN_005dadff(extraout_ECX,100,0);
    *(undefined4 *)(extraout_ECX + 0x178) = *(undefined4 *)(unaff_EBP + -0x14);
    FUN_004f6c41(*(undefined4 *)(extraout_ECX + 0x168),1,0);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00562b1f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

