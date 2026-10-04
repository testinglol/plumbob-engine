
void FUN_004f6f07(void)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006f29f5 == '\0') goto LAB_004f709c;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x38,0,0x20);
  *(undefined ***)(unaff_EBP + -0x44) = &PTR_FUN_006666e4;
  FUN_0046fa40(*(undefined4 *)(unaff_EBP + 0x14));
  sVar2 = _strlen(s_Person___006cb194);
  FUN_00412d8a(s_Person___006cb194,s_Person___006cb194 + sVar2);
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
  sVar2 = _strlen(s_from_the_animations_of_006cb228);
  FUN_00412d8a(s_from_the_animations_of_006cb228,s_from_the_animations_of_006cb228 + sVar2);
  iVar1 = *(int *)(unaff_EBP + 8);
  pcVar3 = *(char **)(*(int *)(iVar1 + 0x11c) + 0x18);
  sVar2 = _strlen(pcVar3);
  FUN_00412d8a(pcVar3,pcVar3 + sVar2);
  sVar2 = _strlen(s___The_entry_for_006cb214);
  FUN_00412d8a(s___The_entry_for_006cb214,s___The_entry_for_006cb214 + sVar2);
  if (*(int *)(iVar1 + 0x11c) != 0) {
    iVar4 = FUN_00457d14();
    iVar1 = *(int *)(unaff_EBP + 0x10);
    if (iVar1 == iVar4) {
      pcVar3 = s_child_to_object__or_child_to_chi_006cb1f0;
    }
    else {
      iVar4 = FUN_00457ccc();
      if (iVar1 == iVar4) {
        pcVar3 = s_adult_to_object__or_adult_to_adu_006cb1cc;
      }
      else {
        iVar4 = FUN_00457d5c();
        if (iVar1 == iVar4) {
          pcVar3 = s_child_to_adult_006cb1bc;
        }
        else {
          iVar4 = FUN_00457d38();
          if (iVar1 != iVar4) goto LAB_004f7076;
          pcVar3 = s_adult_to_child_006cb1ac;
        }
      }
    }
    sVar2 = _strlen(pcVar3);
    FUN_00412d8a(pcVar3,pcVar3 + sVar2);
  }
LAB_004f7076:
  sVar2 = _strlen(s_is_blank__006cb1a0);
  FUN_00412d8a(s_is_blank__006cb1a0,s_is_blank__006cb1a0 + sVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_004f709c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

