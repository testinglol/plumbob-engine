
undefined4 FUN_0044cc47(void)

{
  undefined2 *puVar1;
  char cVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066643c;
  puVar1 = *(undefined2 **)(unaff_EBP + 0xc);
  iVar5 = *(int *)(unaff_EBP + 8);
  uVar4 = CONCAT22(extraout_var,*puVar1);
  uVar6 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_00401f6f(uVar4,0);
  FUN_00470383(uVar3,uVar4,uVar6);
  uVar4 = FUN_004705f2(*(undefined1 *)(puVar1 + 2),0xffffffff);
  FUN_005b870f(uVar4);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined2 *)(unaff_EBP + -0x14) = 0;
  *(undefined2 *)(unaff_EBP + -0x12) = 0;
  *(undefined2 *)(unaff_EBP + -0x10) = 0;
  *(undefined2 *)(unaff_EBP + -0xe) = 0;
  FUN_0044bf5a(unaff_EBP + -0x24,iVar5,unaff_EBP + -0x14,unaff_EBP + -0x28);
  cVar2 = FUN_004588d7();
  if (cVar2 == '\0') {
    if (DAT_006c4d5c != '\0') {
      iVar5 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0x18),0,&cXObject::RTTI_Type_Descriptor,
                           &cXPerson::RTTI_Type_Descriptor,0);
      if (iVar5 != 0) {
        FUN_0041f1b0(unaff_EBP + -0x24);
      }
    }
  }
  else {
    if (*(short *)(unaff_EBP + -0x14) == 0) {
      if (iVar5 == 0) {
        *(undefined2 *)(unaff_EBP + -0x14) = 0;
      }
      else {
        *(undefined2 *)(unaff_EBP + -0x14) = *(undefined2 *)(iVar5 + 4);
      }
    }
    FUN_004588f5(*(undefined4 *)(unaff_EBP + -0x24),unaff_EBP + -0x14);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

