
undefined4 * FUN_00473c1d(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = *puVar1;
  extraout_ECX[1] = puVar1[1];
  extraout_ECX[2] = puVar1[2];
  *(undefined1 *)(extraout_ECX + 3) = *(undefined1 *)(puVar1 + 3);
  *(undefined2 *)((int)extraout_ECX + 0xe) = *(undefined2 *)((int)puVar1 + 0xe);
  *(undefined1 *)(extraout_ECX + 4) = *(undefined1 *)(puVar1 + 4);
  *(undefined2 *)((int)extraout_ECX + 0x12) = *(undefined2 *)((int)puVar1 + 0x12);
  *(undefined2 *)(extraout_ECX + 5) = *(undefined2 *)(puVar1 + 5);
  *(undefined2 *)((int)extraout_ECX + 0x16) = *(undefined2 *)((int)puVar1 + 0x16);
  FUN_005b86bd(puVar1 + 6);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(puVar1 + 9);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

