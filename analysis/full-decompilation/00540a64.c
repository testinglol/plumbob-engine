
undefined4 FUN_00540a64(void)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar3 = *(undefined1 **)(extraout_ECX + 0x28);
  puVar4 = *(undefined1 **)(unaff_EBP + 8);
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = *puVar4;
    puVar3[1] = puVar4[1];
    puVar3[2] = puVar4[2];
  }
  iVar5 = *(int *)(extraout_ECX + 0x28);
  cVar2 = puVar4[2];
  *(int *)(unaff_EBP + 8) = iVar5;
  if (iVar5 != 0) {
    *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 1;
  }
  piVar1 = (int *)(extraout_ECX + 4 + cVar2 * 4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar6 = (undefined4 *)*piVar1;
  puVar6 = (undefined4 *)FUN_005417db(*puVar6,puVar6[1],unaff_EBP + 8,&LAB_00540a2f,0);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + 8) != 0) {
    FUN_0053d900();
  }
  if (puVar6 == *(undefined4 **)(*piVar1 + 4)) {
    uVar7 = 0;
  }
  else {
    uVar7 = *puVar6;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

