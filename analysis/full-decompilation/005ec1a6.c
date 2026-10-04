
undefined4 FUN_005ec1a6(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)((int)extraout_ECX + 0x75) = 1;
  puVar3 = operator_new(400);
  *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_005ec224();
    *puVar3 = &PTR_FUN_00674f18;
  }
  iVar1 = *extraout_ECX;
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x12] = (int)puVar3;
  cVar2 = (**(code **)(iVar1 + 0x120))(uVar4);
  if (cVar2 == '\0') {
    *(undefined1 *)((int)extraout_ECX + 0x75) = 0;
    if ((undefined4 *)extraout_ECX[0x12] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[0x12])(1);
    }
    extraout_ECX[0x12] = 0;
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

