
bool FUN_005ed5c3(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  size_t sVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  uVar3 = DAT_006de560;
  *(undefined1 *)(unaff_EBP + -0x10) = DAT_006de560;
  *(undefined2 *)(unaff_EBP + -0xf) = 0;
  *(undefined1 *)(unaff_EBP + -0x11c) = uVar3;
  puVar6 = (undefined4 *)(unaff_EBP + -0x11b);
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  *(undefined1 *)(unaff_EBP + -0x31c) = uVar3;
  puVar6 = (undefined4 *)(unaff_EBP + -0x31b);
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  *(undefined1 *)(unaff_EBP + -0x21c) = uVar3;
  puVar6 = (undefined4 *)(unaff_EBP + -0x21b);
  for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)puVar6 = 0;
  *(undefined1 *)((int)puVar6 + 2) = 0;
  FUN_005d48d9();
  uVar1 = **(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (*(code *)PTR_FUN_006d71dc)
            (uVar1,unaff_EBP + -0x10,unaff_EBP + -0x11c,unaff_EBP + -0x31c,unaff_EBP + -0x21c);
  FUN_005d4bbf(unaff_EBP + -0x10);
  sVar4 = _strlen((char *)(unaff_EBP + -0x11c));
  FUN_00412d8a(unaff_EBP + -0x11c,unaff_EBP + -0x11c + sVar4);
  FUN_005b8775(*(undefined4 *)(unaff_EBP + -0x1c),
               *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c));
  iVar5 = *(int *)(unaff_EBP + -0x18);
  iVar2 = *(int *)(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5 != iVar2;
}

