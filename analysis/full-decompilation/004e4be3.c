
undefined4 FUN_004e4be3(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int unaff_EBP;
  char *pcVar7;
  
  FUN_00634c24();
  iVar6 = *(int *)(unaff_EBP + 8);
  if ((*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4)) / 0xc != 2) {
    pcVar7 = s_Expected_a_parameter_006c9c90;
    goto LAB_004e4c11;
  }
  iVar3 = FUN_00634d24(*(undefined4 *)(*(int *)(iVar6 + 4) + 0xc),&DAT_006c08e4,unaff_EBP + -0x14);
  if (iVar3 != 1) {
    iVar3 = _strcmp(*(char **)(*(int *)(iVar6 + 4) + 0xc),s_search_006c9c60);
    puVar4 = DAT_006f25a0;
    if (iVar3 == 0) {
      if (DAT_006f25a0 != (undefined4 *)0x0) {
        FUN_004e4174();
        FUN_006321f0(puVar4);
        DAT_006f25a0 = (undefined4 *)0x0;
      }
      puVar4 = operator_new(0xc);
      *(undefined4 **)(unaff_EBP + -0x10) = puVar4;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        FUN_0055e4e2(unaff_EBP + 0xb);
      }
      iVar6 = DAT_006e486c;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      DAT_006f25a0 = puVar4;
      FUN_004e4211(*(undefined4 *)(iVar6 + 0x28));
    }
    else {
      iVar3 = _strcmp(*(char **)(*(int *)(iVar6 + 4) + 0xc),&DAT_006c9c58);
      puVar4 = DAT_006f25a0;
      if (iVar3 != 0) {
        iVar3 = _strcmp(*(char **)(*(int *)(iVar6 + 4) + 0xc),&DAT_006c9c3c);
        if (iVar3 != 0) goto LAB_004e4c19;
        if (DAT_006f25a0 == (undefined4 *)0x0) {
          pcVar7 = s_Nothing_to_dump_006c9c2c;
        }
        else {
          FUN_0046f824(unaff_EBP + -0x228,0,0x104);
          *(undefined ***)(unaff_EBP + -0x234) = &PTR_FUN_006664e8;
          FUN_0046f847(s_ObjectDialogs_txt_006c9c7c,0xffffffff);
          if (2 < (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4)) / 0xc) {
            *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(*(int *)(iVar6 + 4) + 0x18);
            FUN_0046f824(unaff_EBP + -0x448,0,0x104);
            *(undefined ***)(unaff_EBP + -0x454) = &PTR_FUN_006664e8;
            FUN_0046f847(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
            FUN_0046f8e4(unaff_EBP + -0x454);
          }
          cVar1 = FUN_004e495b(unaff_EBP + -0x234);
          if (cVar1 != '\0') goto LAB_004e4d1b;
          pcVar7 = s_Could_not_write_file_006c9c14;
        }
        goto LAB_004e4c11;
      }
      if (DAT_006f25a0 != (undefined4 *)0x0) {
        FUN_004e4174();
        FUN_006321f0(puVar4);
        DAT_006f25a0 = (undefined4 *)0x0;
      }
      FUN_0046f824(unaff_EBP + -0x118,0,0x104);
      *(undefined ***)(unaff_EBP + -0x124) = &PTR_FUN_006664e8;
      FUN_0046f847(s_ObjectDialogs_txt_006c9c7c,0xffffffff);
      if (2 < (*(int *)(iVar6 + 8) - *(int *)(iVar6 + 4)) / 0xc) {
        *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(*(int *)(iVar6 + 4) + 0x18);
        FUN_0046f824(unaff_EBP + -0x338,0,0x104);
        *(undefined ***)(unaff_EBP + -0x344) = &PTR_FUN_006664e8;
        FUN_0046f847(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x344);
      }
      puVar4 = operator_new(0xc);
      *(undefined4 **)(unaff_EBP + -0x10) = puVar4;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        FUN_0055e4e2(unaff_EBP + 0xb);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      DAT_006f25a0 = puVar4;
      cVar1 = FUN_004e4a19(unaff_EBP + -0x124);
      if (cVar1 == '\0') goto LAB_004e4ea7;
    }
LAB_004e4d1b:
    uVar2 = 1;
    goto LAB_004e4c1b;
  }
  if (DAT_006f25a0 == (undefined4 *)0x0) {
    puVar4 = operator_new(0xc);
    *(undefined4 **)(unaff_EBP + -0x10) = puVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      FUN_0055e4e2(unaff_EBP + 0xb);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    DAT_006f25a0 = puVar4;
    FUN_0046f824(unaff_EBP + -0x118,0,0x104);
    *(undefined ***)(unaff_EBP + -0x124) = &PTR_FUN_006664e8;
    FUN_0046f847(s_ObjectDialogs_txt_006c9c7c,0xffffffff);
    cVar1 = FUN_004e4a19(unaff_EBP + -0x124);
    if (cVar1 == '\0') {
LAB_004e4ea7:
      pcVar7 = s_Could_not_read_file_006c9c44;
      goto LAB_004e4c11;
    }
  }
  else {
    for (piVar5 = (int *)*DAT_006f25a0; piVar5 != (int *)DAT_006f25a0[1]; piVar5 = piVar5 + 1) {
      if (*(int *)(unaff_EBP + -0x14) == *(int *)*piVar5) {
        iVar6 = *piVar5;
        goto LAB_004e4cfa;
      }
    }
    iVar6 = 0;
LAB_004e4cfa:
    if (iVar6 != 0) {
      FUN_004e3f34(*(undefined4 *)(DAT_006e486c + 0x28),DAT_006e4f10);
      goto LAB_004e4d1b;
    }
    pcVar7 = s_Dialog_not_found_006c9c68;
LAB_004e4c11:
    FUN_005d4bbf(pcVar7);
  }
LAB_004e4c19:
  uVar2 = 0;
LAB_004e4c1b:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

