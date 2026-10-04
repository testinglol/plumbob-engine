
undefined4 FUN_005fe2e5(void)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int extraout_ECX;
  undefined *puVar4;
  int unaff_EBP;
  char *pcVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  FUN_00634c24();
  FUN_005d48d9();
  iVar1 = *(int *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 0x13)) {
    puVar2 = *(undefined **)(unaff_EBP + 0xc);
    if (*(char *)(unaff_EBP + 0x14) == '\0') {
      if ((int)puVar2 < 0xc) {
        puVar4 = &DAT_006d848c;
      }
      else {
        puVar4 = &DAT_006d8488;
      }
    }
    else {
      puVar4 = &DAT_006d8484;
      if (0xb < (int)puVar2) {
        puVar4 = &DAT_006d8480;
      }
    }
    if (puVar2 == (undefined *)0x0) {
      puVar2 = (undefined *)0xc;
    }
    else if (0xc < (int)puVar2) {
      puVar2 = puVar2 + -0xc;
    }
    if (*(char *)(unaff_EBP + 0x18) == '\0') {
      puVar7 = *(undefined **)(unaff_EBP + 0x10);
      pcVar5 = s__2u___2u__s_006d8468;
      puVar6 = puVar2;
    }
    else {
      pcVar5 = s__s__2u___2u_006d8474;
      puVar6 = puVar4;
      puVar7 = puVar2;
      puVar4 = *(undefined **)(unaff_EBP + 0x10);
    }
    FUN_005d5156(unaff_EBP + -0x18,pcVar5,puVar6,puVar7,puVar4);
  }
  else {
    FUN_005d5156(unaff_EBP + -0x18,s__2u___2u_006d8490,*(undefined4 *)(unaff_EBP + 0xc),
                 *(undefined4 *)(unaff_EBP + 0x10));
  }
  uVar3 = FUN_004096c2();
  FUN_005d49b7(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

