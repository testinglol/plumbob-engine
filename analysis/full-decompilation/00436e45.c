
undefined1 FUN_00436e45(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = (**(code **)(*DAT_006fe8bc + 0x18))();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  puVar2 = operator_new(0x14c);
  *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00523434();
    puVar2[0x52] = extraout_ECX;
    *puVar2 = &PTR_FUN_00666ddc;
    puVar2[0x35] = &PTR_LAB_00666dcc;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(extraout_ECX + 0x70) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(bool *)((int)puVar2 + 0x129) = *(char *)(extraout_ECX + 0x69) == '\0';
  }
  if (*(int *)(extraout_ECX + 0x70) != 0) {
    FUN_00436af7();
    *(undefined4 *)(extraout_ECX + 0x74) = 1;
    FUN_004f6c41(*(undefined4 *)(extraout_ECX + 0x70),*(undefined1 *)(extraout_ECX + 0x69),2);
    if (*(char *)(extraout_ECX + 0x69) != '\0') {
      FUN_005da4c7(*(undefined4 *)(extraout_ECX + 0x70));
      *(undefined4 *)(extraout_ECX + 0x70) = 0;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(extraout_ECX + 0x69);
}

