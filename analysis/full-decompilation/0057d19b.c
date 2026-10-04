
bool FUN_0057d19b(void)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  void *pvVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005ed03e(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_005ed121(1,2,1);
  if (cVar2 != '\0') {
    uVar3 = FUN_005ed1e6();
    pvVar4 = operator_new(uVar3);
    puVar1 = (undefined4 *)(extraout_ECX + 0xa4);
    *puVar1 = pvVar4;
    FUN_00601324(puVar1);
    FUN_005ed28f(*puVar1,uVar3);
    FUN_005ed1ac();
    *(uint *)(extraout_ECX + 0x50) = uVar3;
    *(undefined4 *)(extraout_ECX + 0x4c) = *puVar1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005ed0c3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar2 != '\0';
}

