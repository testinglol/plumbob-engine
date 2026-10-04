
undefined4 * FUN_00466964(void)

{
  byte bVar1;
  void *pvVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  undefined4 uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar5 = 0;
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_00468c1e(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00468b61();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00468b61();
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = 0;
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0xd] = 0;
  *extraout_ECX = uVar4;
  *(undefined1 *)(extraout_ECX + 0xe) = 0;
  extraout_ECX[0xf] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  extraout_ECX[0x10] = 0;
  DAT_006e53d8 = extraout_ECX;
  pvVar2 = operator_new(0x20);
  *(void **)(unaff_EBP + 8) = pvVar2;
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    sVar3 = _strlen(s_room_ambient_1_006c49a0);
    FUN_00401a3c(s_room_ambient_1_006c49a0,s_room_ambient_1_006c49a0 + sVar3);
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004311b4(1,0x40,0x40,unaff_EBP + -0x24);
    uVar4 = *(undefined4 *)(unaff_EBP + 8);
  }
  bVar1 = *(byte *)(unaff_EBP + -0x14);
  extraout_ECX[0x11] = uVar4;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if ((bVar1 & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_00401729();
  }
  pvVar2 = operator_new(0x20);
  *(void **)(unaff_EBP + 8) = pvVar2;
  if (pvVar2 != (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 9;
    sVar3 = _strlen(s_room_ambient_2_006c4990);
    FUN_00401a3c(s_room_ambient_2_006c4990,s_room_ambient_2_006c4990 + sVar3);
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 2;
    uVar5 = *(undefined4 *)(unaff_EBP + 8);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_004311b4(1,0x40,0x40,unaff_EBP + -0x24);
  }
  bVar1 = *(byte *)(unaff_EBP + -0x14);
  extraout_ECX[0x12] = uVar5;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if ((bVar1 & 2) != 0) {
    FUN_00401729();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

