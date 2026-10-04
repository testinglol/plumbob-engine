
undefined4 FUN_00465c3c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  void *pvVar6;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x118,0,0x104);
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  puVar2 = (undefined4 *)*puVar1;
  *(undefined ***)(unaff_EBP + -0x124) = &PTR_FUN_006664e8;
  iVar5 = (*(code *)*puVar2)();
  if (0 < iVar5) {
    do {
      cVar4 = *(char *)(puVar1[1] + *(int *)(unaff_EBP + -0x10));
      *(char *)(unaff_EBP + 8) = cVar4;
      if (cVar4 == '\\') {
        uVar7 = 0x2f;
      }
      else {
        uVar7 = *(undefined4 *)(unaff_EBP + 8);
      }
      FUN_0046fa24(uVar7);
      puVar2 = (undefined4 *)*puVar1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      iVar5 = (*(code *)*puVar2)();
    } while (*(int *)(unaff_EBP + -0x10) < iVar5);
  }
  while (((1 < *(ushort *)(unaff_EBP + -0x11c) && (**(char **)(unaff_EBP + -0x120) == '.')) &&
         ((*(char **)(unaff_EBP + -0x120))[1] == '/'))) {
    FUN_0046f824(unaff_EBP + -0x228,0,0x104);
    *(undefined ***)(unaff_EBP + -0x234) = &PTR_FUN_006664e8;
    FUN_0046f8e4(unaff_EBP + -0x124);
    *(undefined2 *)(unaff_EBP + -0x11c) = 0;
    **(undefined1 **)(unaff_EBP + -0x120) = 0;
    FUN_0046f8cb(*(int *)(unaff_EBP + -0x230) + 2);
  }
  pvVar6 = operator_new(0xc);
  *(void **)(unaff_EBP + 8) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar6 == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x120));
  }
  iVar5 = *(int *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar5 + 0xc) = uVar7;
  cVar4 = FUN_005c2f17();
  if (cVar4 == '\0') {
    iVar3 = *(int *)(iVar5 + 0xc);
    if (iVar3 != 0) {
      FUN_005c2ee6();
      FUN_006321f0(iVar3);
    }
    *(undefined4 *)(iVar5 + 0xc) = 0;
    uVar7 = 0xffffffd1;
  }
  else {
    uVar7 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

