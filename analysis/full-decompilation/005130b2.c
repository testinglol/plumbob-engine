
int * FUN_005130b2(void)

{
  char *pcVar1;
  size_t sVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x6d] = 0;
  extraout_ECX[0x6e] = 0;
  extraout_ECX[0x6f] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0047343b(0,0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0047343b(0,0);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *extraout_ECX = (int)&PTR_FUN_0066c1a8;
  extraout_ECX[0x65] = 0;
  pcVar1 = (char *)FUN_0046fc7a();
  sVar2 = _strlen(pcVar1);
  pvVar3 = operator_new(sVar2 + 1);
  extraout_ECX[0x6a] = (int)pvVar3;
  uVar4 = FUN_0046fc7a();
  FUN_006358b0(extraout_ECX[0x6a],uVar4);
  FUN_005c11ce();
  pcVar1 = (char *)FUN_0046fc7a();
  sVar2 = _strlen(pcVar1);
  pvVar3 = operator_new(sVar2 + 1);
  extraout_ECX[0x6b] = (int)pvVar3;
  uVar4 = FUN_0046fc7a();
  FUN_006358b0(extraout_ECX[0x6b],uVar4);
  FUN_005c11ce();
  FUN_005d4956(extraout_ECX[0x6a]);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d499c(unaff_EBP + -0x1c);
  (**(code **)(*extraout_ECX + 0x168))();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  extraout_ECX[0x66] = -1;
  iVar5 = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[0x67] = *(int *)(unaff_EBP + 0xc);
  extraout_ECX[0x69] = 0;
  if (iVar5 == 0) {
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
  }
  else {
    uVar4 = FUN_0043acf5(*(undefined4 *)(unaff_EBP + 0x10));
    *(undefined4 *)(unaff_EBP + 0x10) = uVar4;
  }
  if (*(int *)(unaff_EBP + 0x14) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0043acf5(*(undefined4 *)(unaff_EBP + 0x14));
  }
  pvVar3 = operator_new(0x84);
  *(void **)(unaff_EBP + 0x14) = pvVar3;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  if (pvVar3 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_00510166(extraout_ECX[0x6a],extraout_ECX[0x6b],extraout_ECX,
                         *(undefined4 *)(unaff_EBP + 0x10),0,uVar4,0,0,0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 3;
  extraout_ECX[0x68] = iVar5;
  if (iVar5 != 0) {
    FUN_00503993(s_motives_006c4dd8);
    if (*(int *)(unaff_EBP + 0x18) != 0) {
      FUN_005107c9(0,*(undefined4 *)(unaff_EBP + 0x18));
    }
    if (*(int *)(unaff_EBP + 0x1c) != 0) {
      FUN_005107c9(1,*(undefined4 *)(unaff_EBP + 0x1c));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x6c] = 0;
  *(undefined1 *)(extraout_ECX + 0x8a) = 0;
  return extraout_ECX;
}

