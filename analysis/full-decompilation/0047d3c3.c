
undefined4 FUN_0047d3c3(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  FUN_00634c24();
  iVar3 = *(int *)(extraout_ECX + 8);
  *(int *)(unaff_EBP + -0x18) = iVar3;
  pvVar1 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
  }
  else {
    uVar2 = FUN_0047ccd7(iVar3);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  }
  if ((*(int *)(unaff_EBP + -0x14) != 0) && (*(undefined4 *)(unaff_EBP + -0x10) = 0, 0 < iVar3)) {
    do {
      iVar3 = 0;
      iVar5 = *(char *)(unaff_EBP + -0x10) * 0xe;
      do {
        iVar4 = (char)iVar3 * 4;
        puVar6 = (undefined4 *)(*(int *)(*(int *)(extraout_ECX + 0xc) + iVar4) + iVar5);
        puVar7 = (undefined4 *)
                 (*(int *)(iVar4 + *(int *)(*(int *)(unaff_EBP + -0x14) + 0xc)) + iVar5);
        *puVar7 = *puVar6;
        puVar7[1] = puVar6[1];
        puVar7[2] = puVar6[2];
        iVar3 = iVar3 + 1;
        iVar4 = *(int *)(unaff_EBP + -0x18);
        *(undefined2 *)(puVar7 + 3) = *(undefined2 *)(puVar6 + 3);
      } while (iVar3 < iVar4);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

