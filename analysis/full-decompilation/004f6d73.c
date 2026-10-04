
void FUN_004f6d73(void)

{
  short sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006f29f5 == '\0') goto LAB_004f6efb;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x38,0,0x20);
  *(undefined ***)(unaff_EBP + -0x44) = &PTR_FUN_006666e4;
  FUN_0046fa40(*(undefined4 *)(unaff_EBP + 0x10));
  sVar2 = _strlen(s_Person___006cb194);
  FUN_00412d8a(s_Person___006cb194,s_Person___006cb194 + sVar2);
  iVar5 = *(int *)(unaff_EBP + 8);
  thunk_FUN_00457ea7();
  pcVar3 = (char *)FUN_004096c2();
  sVar2 = _strlen(pcVar3);
  FUN_00412d8a(pcVar3,pcVar3 + sVar2);
  sVar2 = _strlen(s___is_attempting_to_run_the_anima_006cb160);
  FUN_00412d8a(s___is_attempting_to_run_the_anima_006cb160,
               s___is_attempting_to_run_the_anima_006cb160 + sVar2);
  pcVar3 = *(char **)(unaff_EBP + -0x40);
  sVar2 = _strlen(pcVar3);
  FUN_00412d8a(pcVar3,pcVar3 + sVar2);
  sVar2 = _strlen(s_from_the_006cb154);
  FUN_00412d8a(s_from_the_006cb154,s_from_the_006cb154 + sVar2);
  iVar4 = _strcmp(*(char **)(unaff_EBP + 0xc),&DAT_006c5288);
  if (iVar4 == 0) {
    sVar2 = _strlen(s_global_miscellaneous_006cb13c);
    FUN_00412d8a(s_global_miscellaneous_006cb13c,s_global_miscellaneous_006cb13c + sVar2);
    sVar1 = *(short *)(iVar5 + 0x600);
    if ((sVar1 == 0) || (0x11 < sVar1)) {
      pcVar3 = s_adult_006c1028;
    }
    else {
      pcVar3 = s_child_006c1030;
    }
LAB_004f6ec2:
    sVar2 = _strlen(pcVar3);
    FUN_00412d8a(pcVar3,pcVar3 + sVar2);
  }
  else {
    iVar5 = _strcmp(*(char **)(unaff_EBP + 0xc),&DAT_006cb134);
    if (iVar5 == 0) {
      pcVar3 = s_legacy_global_006cb124;
      goto LAB_004f6ec2;
    }
    iVar5 = _strcmp(*(char **)(unaff_EBP + 0xc),&DAT_006cb11c);
    if (iVar5 == 0) {
      pcVar3 = s_legacy_person_stock_006cb108;
      goto LAB_004f6ec2;
    }
  }
  sVar2 = _strlen(s_table__and_the_entry_is_blank__006cb0e4);
  FUN_00412d8a(s_table__and_the_entry_is_blank__006cb0e4,
               s_table__and_the_entry_is_blank__006cb0e4 + sVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_004f6efb:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

